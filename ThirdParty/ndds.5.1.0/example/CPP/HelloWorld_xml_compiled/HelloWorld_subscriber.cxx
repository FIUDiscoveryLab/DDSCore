/* HelloWorld_subscriber.cxx

   A subscription example
              
       
modification history
------------ -------       
*/

#include <stdio.h>
#include <stdlib.h>
#include "ndds/ndds_cpp.h"
#include "HelloWorldSupport.h"

class HelloWorldListener : public DDSDataReaderListener {
  public:
    virtual void on_requested_deadline_missed(
        DDSDataReader* /*reader*/,
        const DDS_RequestedDeadlineMissedStatus& /*status*/) {}
    
    virtual void on_requested_incompatible_qos(
        DDSDataReader* /*reader*/,
        const DDS_RequestedIncompatibleQosStatus& /*status*/) {}
    
    virtual void on_sample_rejected(
        DDSDataReader* /*reader*/,
        const DDS_SampleRejectedStatus& /*status*/) {}

    virtual void on_liveliness_changed(
        DDSDataReader* /*reader*/,
        const DDS_LivelinessChangedStatus& /*status*/) {}

    virtual void on_sample_lost(
        DDSDataReader* /*reader*/,
        const DDS_SampleLostStatus& /*status*/) {}

    virtual void on_subscription_matched(
        DDSDataReader* /*reader*/,
        const DDS_SubscriptionMatchedStatus& /*status*/) {}

    virtual void on_data_available(DDSDataReader * reader);
};

void HelloWorldListener::on_data_available(DDSDataReader * reader) {
    HelloWorldDataReader * helloWorldReader = NULL;
    HelloWorldSeq dataSeq;
    DDS_SampleInfoSeq infoSeq;
    DDS_ReturnCode_t retCode = DDS_RETCODE_ERROR;        
    DDS_Long i = 0;
    
    helloWorldReader = HelloWorldDataReader::narrow(reader);
    if (helloWorldReader == NULL) {
        printf("HelloWorldDataReader::narrow error\n");
        return;
    }

    retCode = helloWorldReader->take(
        dataSeq, infoSeq, DDS_LENGTH_UNLIMITED,
        DDS_ANY_SAMPLE_STATE, DDS_ANY_VIEW_STATE, DDS_ANY_INSTANCE_STATE);

    if (retCode != DDS_RETCODE_OK) {
        
        printf("take error %d\n", retCode);
        return;
    }

    printf("\non_data_available: %s", reader->get_topicdescription()->get_name());
    for (i = 0; i < dataSeq.length(); ++i) {
        if (infoSeq[i].valid_data) {                       
            HelloWorldTypeSupport::print_data(&dataSeq[i]);
        } else {
            if ( infoSeq[i].instance_state == DDS_NOT_ALIVE_DISPOSED_INSTANCE_STATE ) {
                printf("\nData instance was disposed.\n");
            } else if ( infoSeq[i].instance_state == DDS_NOT_ALIVE_NO_WRITERS_INSTANCE_STATE ) {
               printf("\nData instance no longer has any DataWriter writing it.\n");
            } 
        }

    }
    
    retCode = helloWorldReader->return_loan(dataSeq, infoSeq);
    if (retCode != DDS_RETCODE_OK) {
       printf("return_loan error %d\n", retCode);
    }
}

/* Delete all entities */
static int subscriberShutdown(
    DDSDomainParticipant * participant) {
    
    DDS_ReturnCode_t retCode;
    int status = 0;

    if (participant != NULL) {
        retCode = participant->delete_contained_entities();
        if (retCode != DDS_RETCODE_OK) {
            printf("delete_contained_entities error %d\n", retCode);
            status = -1;
        }

        retCode = DDSTheParticipantFactory->delete_participant(participant);
        if (retCode != DDS_RETCODE_OK) {
            printf("delete_participant error %d\n", retCode);
            status = -1;
        }
    }

    /* RTI Connext provides the finalize_instance() method on
       domain participant factory and the finalize() method on type support for
       users who want to release memory used by the participant factory and
       type support singletons. Uncomment the following block of code for
       clean destruction of the singletons. */
/*
    HelloWorldTypeSupport::finalize();

    retcode = DDSDomainParticipantFactory::finalize_instance();
    if (retcode != DDS_RETCODE_OK) {
        printf("finalize_instance error %d\n", retcode);
        status = -1;
    }
*/
    return status;
}

int subscriberMain(int sampleCount) {
    
    DDS_ReturnCode_t retCode;
    int count = 0;  
    DDS_Duration_t receivePeriod = {4,0};
    int status = 0;
    
    /* type registration */
    retCode = DDSTheParticipantFactory->register_type_support(
                                        HelloWorldTypeSupport::register_type, 
                                        "HelloWorldType");
    if (retCode != DDS_RETCODE_OK) {
        printf("register_type_support %d\n", retCode);
        subscriberShutdown(NULL);
        return -1;
    }

    /* To customize the participant QoS, use 
       the configuration file USER_QOS_PROFILES.xml */    
    DDSDomainParticipant * participant = DDSTheParticipantFactory->
            create_participant_from_config("MyParticipantLibrary::SubscriptionParticipant");
    if (participant == NULL) {
        printf("create_participant_from_config error\n");
        subscriberShutdown(participant);
        return -1;
    }
    
    HelloWorldDataReader * helloWorldReader = HelloWorldDataReader::narrow(
            participant-> lookup_datareader_by_name(
                                      "MySubscriber::HelloWorldReader"));    
    if (helloWorldReader == NULL) {
        printf("lookup_datareader_by_name error\n");
        subscriberShutdown(participant);
        return -1;
    }

    /* Create a data reader listener */
    HelloWorldListener * readerListener = new HelloWorldListener();

    /* set listener */
    retCode = helloWorldReader->set_listener(
            readerListener, DDS_DATA_AVAILABLE_STATUS);
    if (retCode != DDS_RETCODE_OK) {
        printf("set_listener error\n");
        subscriberShutdown(participant);
        delete readerListener;
        return -1;
    }

    /* Main loop */
    for (count=0; (sampleCount == 0) || (count < sampleCount); ++count) {
        printf("HelloWorld subscriber sleeping for %d sec...\n",
               receivePeriod.sec);
        NDDSUtility::sleep(receivePeriod);
    }

    /* Delete all entities */
    status = subscriberShutdown(participant);
    delete readerListener;

    return status;
}

int main(int argc, char *argv[]) {
    
    int sampleCount = 0; /* infinite loop */   
    
    if (argc >= 2) {
        sampleCount = atoi(argv[1]);
    }

    /* Uncomment this to turn on additional logging
    NDDSConfigLogger::get_instance()->
        set_verbosity_by_category(NDDS_CONFIG_LOG_CATEGORY_API, 
                                  NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL);
    */
    
    return subscriberMain(sampleCount);
}


