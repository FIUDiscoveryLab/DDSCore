/* ****************************************************************************
 *         (c) Copyright, Real-Time Innovations, All rights reserved.       
 *                                                                          
 *         Permission to modify and use for internal purposes granted.      
 * This software is provided "as is", without warranty, express or implied. 
 *                                                                          
 * ****************************************************************************
 */

using System;
using System.Collections.Generic;
using System.Text;

namespace Hello {
    /**
     * Manage the data publication for the Hello example 
     */
    class HelloPublisher {
        /* Maximum consecutive write error after stopping the write process */
        private const int MAX_CONSECUTIVE_WRITE_ERROR = 5;

        private HelloWorldDataWriter _theDataWriter;
        private int _theDataSize;
        private int _theVerbose;
        private int _theSampleCount;


        // ************************************************************************

        /**
         * Builds a new HelloPublisher object and initialize the inner DDS 
         * entities.
         * This method only creates the entities, but it does not actually write
         * the data.
         * To write the data, use the method writeSamples().
         *  
         * @param participant the DDS Domain participant
         * @param topic       the DDS topic 
         * @param verbose     an integer to control the output verbosity
         * @param dataSize    the size of the payload data
         */

        public HelloPublisher(DDS.DomainParticipant participant,
                              DDS.Topic topic,
                              int verbose,
                              int dataSize,
                              int sampleCount) {
            _theDataSize = dataSize;
            _theVerbose = verbose;
             _theSampleCount = sampleCount;

            /** Create the publisher. 
             * Just like the participant, if you want to customize the publisher QoS,
             * use DDS.DomainParticipant.get_default_publisher_qos() to 
             * initialize a local copy of the default QoS, modify them, then
             * use them in the creation call below instead of 
             *     DDS.DomainParticipant.PUBLISHER_QOS_DEFAULT.
             * For more info on publisher API, see:
             *     $NDDSHOME/doc/html/api_dotnet/group__DDSPublisherModule.html
             */
            if (verbose > 0) {
                Console.WriteLine("Creating publisher...");
            }
            DDS.Publisher publisher = participant.create_publisher(
                            DDS.DomainParticipant.PUBLISHER_QOS_DEFAULT,
                            null, /* Listener */
                            DDS.StatusMask.STATUS_MASK_NONE);
            if (publisher == null) {
                Console.Error.WriteLine("! Unable to create DDS Publisher");
                return;
            }

            /* Creates the DDS Data writer. 
             * Just like before, if you want to customize the writer QoS,
             * use DDS.Publisher.get_default_datawriter_qos() to 
             * initialize a local copy of the default QoS, modify them, then
             * use them in the creation call below instead of 
             * DDS_DATAWRITER_QOS_DEFAULT.
             * For more data writer API info, see:
             *     $NDDSHOME/doc/html/api_dotnet/group__DDSWriterModule.html
             */
            if (verbose > 0) {
                Console.WriteLine("Creating the data writer...");
            }
            _theDataWriter = (HelloWorldDataWriter)
                publisher.create_datawriter(topic,
                                DDS.Publisher.DATAWRITER_QOS_DEFAULT,
                                null, /* Listener */
                                DDS.StatusMask.STATUS_MASK_NONE);
            if (_theDataWriter == null) {
                Console.Error.WriteLine("! Unable to create DDS data writer");
                return;
            }
        }

        // ************************************************************************

        /**
         * Writes samples to DDS. This method never returns.
         */
        public void writeSamples() {
            HelloWorld instance = new HelloWorld();

            /* Initialize the data */
            instance.prefix = "Hello world";
            instance.payload.ensure_length(_theDataSize, _theDataSize);
            byte[] arr = instance.payload.buffer;
            for (int i = 0; i < _theDataSize; ++i) {
                arr[i] = (byte)(i % 0xff);
            }
            Console.WriteLine("Sending data...");
            int consecutiveErrors = 0;
            for (instance.sampleId = 0; ;
                ++(instance.sampleId)) {
                try {
                    _theDataWriter.write(instance, ref DDS.InstanceHandle_t.HANDLE_NIL);
                }
                catch (DDS.Retcode_Error e) {
                    Console.Error.WriteLine("! Write error " +
                            e.GetType() + ": " + e.Message);
                    if (++consecutiveErrors > MAX_CONSECUTIVE_WRITE_ERROR) {
                        Console.WriteLine("! Reached maximum number of failure, stopping writer...");
                        return;
                    }
                }
                /* Always clear the error count in case of successful write */
                consecutiveErrors = 0;
                if (_theVerbose > 0 && (instance.sampleId % 10000) == 0) {
                    Console.WriteLine("Sent " +
                        instance.sampleId + " samples...");
                }
                 if (_theSampleCount != 0 && (instance.sampleId >= _theSampleCount)) {
                    Console.WriteLine("Sent " + instance.sampleId + " samples.");
                    break;
                }
            }
        }
    }
}
