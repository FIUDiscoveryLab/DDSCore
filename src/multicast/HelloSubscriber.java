package multicast;
// ****************************************************************************
//         (c) Copyright, Real-Time Innovations, All rights reserved.       
//                                                                          
//         Permission to modify and use for internal purposes granted.      
// This software is provided "as is", without warranty, express or implied. 
//                                                                          
// ****************************************************************************


import java.util.ArrayList;
import java.util.List;

import com.rti.dds.domain.DomainParticipant;
import com.rti.dds.domain.DomainParticipantFactory;
import com.rti.dds.domain.DomainParticipantFactoryQos;
import com.rti.dds.infrastructure.RETCODE_ERROR;
import com.rti.dds.infrastructure.RETCODE_NO_DATA;
import com.rti.dds.infrastructure.StatusKind;
import com.rti.dds.subscription.DataReader;
import com.rti.dds.subscription.DataReaderAdapter;
import com.rti.dds.subscription.SampleInfo;
import com.rti.dds.subscription.Subscriber;
import com.rti.dds.topic.Topic;
import com.rti.dds.type.builtin.StringDataReader;
import com.rti.dds.type.builtin.StringTypeSupport;

//****************************************************************************
public class HelloSubscriber extends DataReaderAdapter {

    // For clean shutdown sequence
    private static boolean shutdown_flag = false;

    public static final void main(String[] args) {
    	List<String> fileNames = new ArrayList<String>();
        //BufferedReader reader = new BufferedReader(new FileReader(Config.QOS_FILE_PATH));
        //filenames.add("base_profile_multicast.xml");
        //filenames.add("MaxMulticast.xml");
    	fileNames.add("MaxMulticast.xml");
    	
        // Create the DDS Domain participant on domain ID 0
		DomainParticipantFactoryQos factoryQos = 
				new DomainParticipantFactoryQos();
		DomainParticipantFactory.get_instance().get_qos(factoryQos);
		factoryQos.profile.url_profile.setMaximum(fileNames.size());
		for (int i = 0; i < fileNames.size(); i++) {
			
			factoryQos.profile.url_profile.add(fileNames.get(i));
		}

		DomainParticipantFactory.get_instance().set_qos(factoryQos);
		
		DomainParticipant participant = 
				DomainParticipantFactory.get_instance()
				.create_participant_with_profile(
									0,
									"BasicAEONProfile", 
									 "MaxThroughputMulticast", 
									null, 
									StatusKind.STATUS_MASK_NONE);
    	/*
        DomainParticipant participant = DomainParticipantFactory.get_instance().create_participant(
                0, // Domain ID = 0
                DomainParticipantFactory.PARTICIPANT_QOS_DEFAULT, 
                null, // listener
                StatusKind.STATUS_MASK_NONE);
        */
        
        if (participant == null) {
            System.err.println("Unable to create domain participant");
            return;
        }

        // Create the topic "Hello World" for the String type
        Topic topic = participant.create_topic(
                "Hello, World", 
                StringTypeSupport.get_type_name(), 
                DomainParticipant.TOPIC_QOS_DEFAULT, 
                null, // listener
                StatusKind.STATUS_MASK_NONE);
        if (topic == null) {
            System.err.println("Unable to create topic.");
            return;
        }

        // Create the data reader using the default publisher
        StringDataReader dataReader =
            (StringDataReader) participant.create_datareader(
                topic, 
                Subscriber.DATAREADER_QOS_DEFAULT,
                new HelloSubscriber(),         // Listener
                StatusKind.DATA_AVAILABLE_STATUS);
        if (dataReader == null) {
            System.err.println("Unable to create DDS Data Reader");
            return;
        }

        System.out.println("Ready to read data.");
        System.out.println("Press CTRL+C to terminate.");
        for (;;) {
            try {
                Thread.sleep(2000);
                if(shutdown_flag) break;
            } catch (InterruptedException e) {
                // Nothing to do...
            }
        }
	
        System.out.println("Shutting down...");
        participant.delete_contained_entities();
        DomainParticipantFactory.get_instance().delete_participant(participant);
    }

    /*
     * This method gets called back by DDS when one or more data samples have
     * been received.
     */
    public void on_data_available(DataReader reader) {
        StringDataReader stringReader = (StringDataReader) reader;
        SampleInfo info = new SampleInfo();
        for (;;) {
            try {
                String sample = stringReader.take_next_sample(info);
                if (info.valid_data) {
                    System.out.println(sample);
                    if (sample.equals("")) {
                        shutdown_flag = true;
                    }
                }
            } catch (RETCODE_NO_DATA noData) {
                // No more data to read
                break;
            } catch (RETCODE_ERROR e) {
                // An error occurred
                e.printStackTrace();
            }
        }
    }
}
