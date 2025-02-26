/* (c) Copyright, Real-Time Innovations, Inc. 2003-2009. All rights reserved. */
/*
 * @(#)commend_writerService.h    generated by: makeheader    Sat Nov 23 02:38:40 2013
 *
 *		built from:	writerService.ifc
 */

#ifndef commend_writerService_h
#define commend_writerService_h


  #ifndef reda_table_h
    #include "reda/reda_table.h"
  #endif
  #ifndef reda_weakReference_h
    #include "reda/reda_weakReference.h"
  #endif
  #ifndef reda_inlineList_h
    #include "reda/reda_inlineList.h"
  #endif
  #ifndef osapi_ntptime_h
    #include "osapi/osapi_ntptime.h"
  #endif
  #ifndef event_jobDispatcher_h
    #include "event/event_jobDispatcher.h"
  #endif
  #ifndef mig_rtps_h
    #include "mig/mig_rtps.h"
  #endif
  #ifndef mig_generator_h
    #include "mig/mig_generator.h"
  #endif
  #ifndef commend_dll_h
    #include "commend/commend_dll.h"
  #endif
  #ifndef commend_common_h
    #include "commend/commend_common.h"
  #endif
  #ifndef commend_writerStatistics_h
    #include "commend/commend_writerStatistics.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif

struct COMMENDWriterService;

struct COMMENDWriterServiceWriterSampleListener;

struct COMMENDWriterServiceWriterActivityListener;

struct COMMENDFilterStatus;

struct COMMENDWriterServiceTransportPlugins {
    int length; /* array's length */
    NDDS_Transport_Plugin **plugins; /* array of plugin ptrs */
};


  #define COMMEND_WRITER_SERVICE_TRANSPORT_PLUGINS_DEFAULT { \
      0, /* length */ \
      NULL, /* plugins */ \
  }


#define COMMEND_WRITER_SERVICE_WRITER_LISTENER_STORAGE_LENGTH (5)


#define COMMEND_WRITER_LOCATOR_MAX_REMOTE_READER              (4)


#define COMMEND_WRITER_MAX_RTPS_OVERHEAD                      (512)

struct COMMENDWriterServiceWriterListenerStorage {
    void *field[COMMEND_WRITER_SERVICE_WRITER_LISTENER_STORAGE_LENGTH];
};

typedef RTIBool
(*COMMENDWriterServiceWriterSampleListenerOnDataRequestCallback)(
    const struct COMMENDWriterServiceWriterSampleListener *listener,
    struct MIGGeneratorSample **sample, RTIBool *dataValid,
    struct REDASequenceNumber *firstRelevantSn,
    struct REDASequenceNumber *nextRelevantSn,
    struct REDASequenceNumber *firstRelevantVirtualSn,
    struct REDASequenceNumber *nextRelevantVirtualSn,
    struct RTINtpTime *ackDelay,
    const struct COMMENDWriterServiceWriterListenerStorage *storage,
    const struct REDASequenceNumber *requestSn,
    int filterIndex,
    struct COMMENDFilterStatus *filterStatus,
    const struct RTINtpTime *now_in,
    const struct MIGRtpsGuid *remoteReaderVirtualGuid,
    struct REDAWorker *worker);

typedef void
(*COMMENDWriterServiceWriterSampleListenerOnDataLoanFinishCallback)(
    const struct COMMENDWriterServiceWriterSampleListener *listener,
    struct MIGGeneratorSample *sample,
    const struct COMMENDWriterServiceWriterListenerStorage *storage,
    struct REDAWorker *worker);

typedef RTIBool
(*COMMENDWriterServiceWriterActivityListenerOnRemoteReaderInactiveCallback)(
    const struct COMMENDWriterServiceWriterActivityListener *listener,
    const struct COMMENDWriterServiceWriterListenerStorage *storage,
    struct REDAWorker *worker);

typedef RTIBool
(*COMMENDWriterServiceWriterActivityListenerOnRemoteReaderActiveCallback)(
    const struct COMMENDWriterServiceWriterActivityListener *listener,
    const struct COMMENDWriterServiceWriterListenerStorage *storage,
    struct REDAWorker *worker);

typedef RTIBool
(*COMMENDWriterServiceWriterSampleListenerOnFirstUnackedSnChangeCallback)(
    const struct COMMENDWriterServiceWriterSampleListener *listener,
    struct REDASequenceNumber *firstUnackedVirtualSn, /* output parameter */
    const struct COMMENDWriterServiceWriterListenerStorage *storage,
    const struct MIGRtpsGuid *readerVirtualGuid,
    const RTIBool durSubOnly,
    const struct REDASequenceNumber *firstUnackedSn,
    struct REDAWorker *worker);

typedef RTIBool
(*COMMENDWriterServiceWriterSampleListenerOnFirstNonElapsedSnUpdateCallback)(
    const struct COMMENDWriterServiceWriterSampleListener *listener,
    const struct COMMENDWriterServiceWriterListenerStorage *storage,
    struct REDASequenceNumber *firstNonElapsedSn,
    struct RTINtpTime *firstNonElapsedTs,
    struct RTINtpTime *ackDelay,
    const struct RTINtpTime *now,
    struct REDAWorker *worker);

typedef RTIBool
(*COMMENDWriterServiceWriterSampleListenerOnWriterInfoListRequestCallback)(
    const struct COMMENDWriterServiceWriterSampleListener *listener,
    const struct COMMENDWriterServiceWriterListenerStorage *storage,
    struct MIGRtpsWriterInfoList **list, RTI_INT32 sessionId,
    struct REDAWorker *worker);

typedef RTIBool
(*COMMENDWriterServiceWriterSampleListenerOnKeepDurationChangeCallback)(
    const struct COMMENDWriterServiceWriterSampleListener *listener,
    const struct COMMENDWriterServiceWriterListenerStorage *storage,
    struct RTINtpTime *ackDelay,
    const struct RTINtpTime *now,
    struct REDAWorker *worker);

typedef RTIBool
(*COMMENDWriterServiceWriterSampleListenerOnSerializeSampleCallback)(
    const struct COMMENDWriterServiceWriterSampleListener *listener,
    const struct COMMENDWriterServiceWriterListenerStorage *storage,
    struct MIGGeneratorSample *sample,
    RTIEncapsulationId encapsulationId,
    struct REDAWorker *worker);

typedef RTIBool
(*COMMENDWriterServiceWriterSampleListenerOnReturnSerializationBufferCallback)(
    const struct COMMENDWriterServiceWriterSampleListener *listener,
    const struct COMMENDWriterServiceWriterListenerStorage *storage,
    struct MIGGeneratorSample *sample,
    RTIEncapsulationId encapsulationId,
    struct REDAWorker *worker);

typedef RTIBool
(*COMMENDWriterServiceWriterSampleListenerOnDestinationUnreachableCallback)(
    const struct COMMENDWriterServiceWriterSampleListener *listener,
    const struct COMMENDWriterServiceWriterListenerStorage *storage,
    const struct MIGRtpsGuid *readerGuid,
    const struct RTINetioLocator *destination,
    struct REDAWorker *worker);

typedef RTIBool
(*COMMENDWriterServiceWriterSampleListenerOnSendWindowChangeCallback)(
    const struct COMMENDWriterServiceWriterSampleListener *listener,
    const struct COMMENDWriterServiceWriterListenerStorage *storage,
    RTI_INT32 *samplesPerHb,
    RTI_INT32 sendWindow,
    struct REDAWorker *worker);

typedef RTIBool
(*COMMENDWriterServiceWriterSampleListenerOnAppAckCallback)(
    const struct COMMENDWriterServiceWriterSampleListener *listener,
    const struct COMMENDWriterServiceWriterListenerStorage *storage,
    struct MIGRtpsAppAck * appAckIn,
    const struct MIGRtpsGuid *remoteReaderGuid,
    const struct MIGRtpsGuid *remoteReaderVirtualGuid,
    const struct RTINtpTime *now,
    struct REDAWorker *worker);

typedef RTIBool
(*COMMENDWriterServiceWriterSampleListenerOnBeAsynchPubCompletedCallback)(
    const struct COMMENDWriterServiceWriterSampleListener *listener,
    const struct COMMENDWriterServiceWriterListenerStorage *storage,
    const struct REDASequenceNumber *completedSn, RTIBool includingPrevious,
    struct REDAWorker *worker);

typedef RTIBool
(*COMMENDWriterServiceWriterActivityListenerOnStateRequestCallback)(
    const struct COMMENDWriterServiceWriterActivityListener *listener,
    struct RTINtpTime *nextResponseTime, struct RTINtpTime *snooze,
    const struct RTINtpTime *now,
    const struct COMMENDWriterServiceWriterListenerStorage *storage,
    struct REDAWorker *worker);

typedef RTIBool
(*COMMENDWriterServiceWriterActivityListenerOnRemoteReaderAckModeChangedCallback)(
    const struct COMMENDWriterServiceWriterActivityListener *listener,
    const struct COMMENDWriterServiceWriterListenerStorage *storage,
    RTIBool ackEnabledReaderPresent,
    RTIBool ackDisabledReaderPresent,
    struct REDAWorker *worker);

typedef RTIBool
(*COMMENDWriterServiceWriterSampleListenerOnQueueUpdateCallback)(
    const struct COMMENDWriterServiceWriterSampleListener *listener,
    struct REDASequenceNumber *firstSn, struct REDASequenceNumber *firstVirtualSn,
    const struct COMMENDWriterServiceWriterListenerStorage *storage,
    struct REDAWorker *worker);

struct COMMENDWriterServiceWriterSampleListener {
    COMMENDWriterServiceWriterSampleListenerOnDataRequestCallback
        onDataRequest;
    COMMENDWriterServiceWriterSampleListenerOnDataLoanFinishCallback
        onDataLoanFinish;
    COMMENDWriterServiceWriterSampleListenerOnFirstUnackedSnChangeCallback
        onFirstUnackedSnChange;
    COMMENDWriterServiceWriterSampleListenerOnBeAsynchPubCompletedCallback
        onBeAsynchPubCompleted;
    COMMENDWriterServiceWriterSampleListenerOnFirstNonElapsedSnUpdateCallback
        onFirstNonElapsedSnUpdate;
    COMMENDWriterServiceWriterSampleListenerOnKeepDurationChangeCallback
        onKeepDurationChange;
    COMMENDWriterServiceWriterSampleListenerOnSerializeSampleCallback
        onSerializeSample;
    COMMENDWriterServiceWriterSampleListenerOnReturnSerializationBufferCallback
        onReturnSerializationBuffer;
    COMMENDWriterServiceWriterSampleListenerOnDestinationUnreachableCallback
        onDestinationUnreachable;
    COMMENDWriterServiceWriterSampleListenerOnSendWindowChangeCallback
        onSendWindowChange;
    COMMENDWriterServiceWriterSampleListenerOnQueueUpdateCallback
        onQueueUpdate;

    COMMENDWriterServiceWriterSampleListenerOnAppAckCallback onAppAck;

    COMMENDWriterServiceWriterSampleListenerOnWriterInfoListRequestCallback
    	onWriterInfoListRequest;
};

struct COMMENDWriterServiceWriterActivityListener {
    COMMENDWriterServiceWriterActivityListenerOnRemoteReaderInactiveCallback
        onRemoteReaderInactive;
    COMMENDWriterServiceWriterActivityListenerOnRemoteReaderActiveCallback
        onRemoteReaderActive;
    COMMENDWriterServiceWriterActivityListenerOnStateRequestCallback
        onStateRequest;
    COMMENDWriterServiceWriterActivityListenerOnRemoteReaderAckModeChangedCallback
        onRemoteReaderAckModeChanged;
};

struct COMMENDWriterServiceWriterStatusListener;

typedef RTIBool
(*COMMENDWriterServiceWriterStatusListenerOnNewWriterLocatorPairCallback)(
    const struct COMMENDWriterServiceWriterStatusListener *listener,
    const struct COMMENDWriterServiceWriterListenerStorage *storage,
    const MIGRtpsObjectId localWriterOid,
    const struct RTINetioLocator *locator,
    struct REDAWorker *worker);

typedef RTIBool
(*COMMENDWriterServiceWriterStatusListenerOnDeletedWriterLocatorPairCallback)(
    const struct COMMENDWriterServiceWriterStatusListener *listener,
    const struct COMMENDWriterServiceWriterListenerStorage *storage,
    const MIGRtpsObjectId localWriterOid,
    const struct RTINetioLocator *locator,
    struct REDAWorker *worker);

struct COMMENDWriterServiceWriterStatusListener {
    COMMENDWriterServiceWriterStatusListenerOnNewWriterLocatorPairCallback
    	onNewWriterLocatorPair;
    COMMENDWriterServiceWriterStatusListenerOnDeletedWriterLocatorPairCallback
    	onDeletedWriterLocatorPair;
};



struct COMMENDFilterStatusEx {
    /*e Filter index status: 0=passed 1=nopass */
    RTI_UINT32 status;

    /*e Filter index state: 1=invalid, 0=valid */
    RTI_UINT32 state;
};

struct COMMENDFilterStatus {
    /*e Filter index status: 0=passed 1=nopass */
    RTI_UINT32 status;

    /*e Filter index state: 1=invalid, 0=valid */
    RTI_UINT32 state;

    /*e Extended filter status for more then 32 readers.
     * Note that the first entry has special meaning:
     *
     * extended[0].status is the msx number of elements in the array
     *
     * extended[0].state is the highest index currenty in use. This is
     * to avoid having to iterate over the entire array when only some of the
     * entries are used.
     */
    struct COMMENDFilterStatusEx *_extended;

    /* Reader lists to support optimized writer side filtering */
    /*e List of readers whose filters pass the sample */
    struct REDAInlineList * _passedReaders;

    /*e List of readers for which writer side filtering is not being performed.
     */
    struct REDAInlineList * _notFilteredReaders;

};

#define COMMEND_FILTER_INDEX_MAX            32
#define COMMEND_FILTER_STATUS_NEW           {0,0,NULL}
#define COMMEND_FILTER_STATUS_NO_FILTER_NEW {0,0,NULL}
#define COMMEND_FILTER_INDEX_REUSE          0x7ffffffe
#define COMMEND_FILTER_INDEX_INVALID        0x7fffffff
#define COMMEND_FILTER_MAX_FILTERS          ((COMMEND_FILTER_INDEX_INVALID)-2)
#define COMMEND_FILTER_ALL_INDEX_INVALID   0xffffffff

#define COMMENDFilterStatus_clear(__me) \
{RTI_UINT32 i; (__me)->status = 0; (__me)->state = COMMEND_FILTER_ALL_INDEX_INVALID; \
  if ((__me)->_extended) {(__me)->_extended[0].state = 0; for (i = 1; i < (__me)->_extended[0].status; ++i) {(__me)->_extended[i].status=0; (__me)->_extended[i].state=COMMEND_FILTER_ALL_INDEX_INVALID;}}}

#define COMMENDFilterStatus_clearExtension(__me,__start_index) \
{RTI_UINT32 i; \
 for (i = __start_index; i < (__me)->_extended[0].status; ++i) {\
    (__me)->_extended[i].status=0; \
    (__me)->_extended[i].state=COMMEND_FILTER_ALL_INDEX_INVALID;\
    }\
}

#define COMMENDFilterStatus_clearSampleStatus(__me) \
{RTI_UINT32 i; (__me)->status = 0; \
  if ((__me)->_extended) {for (i = 1; i < (__me)->_extended[0].status; ++i) {(__me)->_extended[i].status=0;}}}

#define COMMENDFilterStatus_droppedSampleStatus(__me) \
{RTI_UINT32 i; (__me)->status = 0xffffffff; \
  if ((__me)->_extended) {for (i = 1; i < (__me)->_extended[0].status; ++i) {(__me)->_extended[i].status=0xffffffff;}}}

#define COMMENDFilterStatus_arraySize(__max_index) (((__max_index) / COMMEND_FILTER_INDEX_MAX)+1)

extern COMMENDDllExport
RTIBool COMMENDFilterStatus_init(struct COMMENDFilterStatus * me, RTI_UINT32 maxIndex);

extern COMMENDDllExport
RTIBool COMMENDFilterStatus_extend(struct COMMENDFilterStatus * me, RTI_UINT32 maxIndex);


#define COMMENDFilterStatus_finalize(__me) \
    { if ((__me)->_extended) { RTIOsapiHeap_freeArray((__me)->_extended); (__me)->_extended = NULL; } }

#define COMMENDFilterStatus_dropSample(__me,__bitnum) \
((__bitnum < COMMEND_FILTER_INDEX_MAX) ? ((__me)->status |= (1<<(__bitnum))) : \
    ((__me)->_extended[(__bitnum)/COMMEND_FILTER_INDEX_MAX].status |= (1<<(__bitnum % COMMEND_FILTER_INDEX_MAX))))

#define COMMENDFilterStatus_passSample(__me,__bitnum) \
((__bitnum < COMMEND_FILTER_INDEX_MAX) ? ((__me)->status &= ~(1<<(__bitnum))) : ((__me)->_extended[(__bitnum)/COMMEND_FILTER_INDEX_MAX].status &= ~(1<<(__bitnum % COMMEND_FILTER_INDEX_MAX))))

#define COMMENDFilterStatus_invalidateIndex(__me,__bitnum) \
((__bitnum < COMMEND_FILTER_INDEX_MAX) ? ((__me)->state |= (1<<(__bitnum))) : ((__me)->_extended[(__bitnum)/COMMEND_FILTER_INDEX_MAX].state |= (1<<(__bitnum % COMMEND_FILTER_INDEX_MAX))));\
{\
  RTI_UINT32 _i;\
  if (((__me)->_extended != NULL) && ((__me)->_extended[0].state == (__bitnum)/COMMEND_FILTER_INDEX_MAX)) {\
      for (_i = (__me)->_extended[0].status-1; ((_i > 0) && ((__me)->_extended[_i].state == COMMEND_FILTER_ALL_INDEX_INVALID)); --_i);\
      (__me)->_extended[0].state = _i;\
  }\
}

#define COMMENDFilterStatus_validateIndex(__me,__bitnum) \
if (((__me)->_extended != NULL) && ((__me)->_extended[0].state < (__bitnum)/COMMEND_FILTER_INDEX_MAX)) (__me)->_extended[0].state = (__bitnum)/COMMEND_FILTER_INDEX_MAX; \
((__bitnum < COMMEND_FILTER_INDEX_MAX) ? ((__me)->state &= ~(1<<(__bitnum))) : ((__me)->_extended[(__bitnum)/COMMEND_FILTER_INDEX_MAX].state &= ~(1<<(__bitnum % COMMEND_FILTER_INDEX_MAX))));

extern COMMENDDllExport
RTIBool COMMENDFilterStatus_samplesAreDropped(struct COMMENDFilterStatus * me);

extern COMMENDDllExport
RTIBool COMMENDFilterStatus_allIndicesAreInvalid(struct COMMENDFilterStatus * me);

extern COMMENDDllExport
RTIBool COMMENDFilterStatus_allIndicesAreValid(struct COMMENDFilterStatus * me);


#define COMMENDFilterStatus_sampleIsDropped(__me,__index) \
((__index < COMMEND_FILTER_INDEX_MAX) ? ((__me)->status & (1<<(__index))) : \
    ((__me)->_extended[(__index)/COMMEND_FILTER_INDEX_MAX].status & (1<<(__index % COMMEND_FILTER_INDEX_MAX))))

#define COMMENDFilterStatus_indexIsValid(__me,__index) \
((__index == COMMEND_FILTER_INDEX_INVALID) ? RTI_FALSE : \
    (((__index < COMMEND_FILTER_INDEX_MAX) ? (((__index)>=0) && !((__me)->state & (1<<(__index)))) : \
    (((__index)>=0) && !((__me)->_extended[(__index)/COMMEND_FILTER_INDEX_MAX].state & (1<<(__index % COMMEND_FILTER_INDEX_MAX)))))))

#define COMMENDFilterStatus_indexInRange(__index) \
    (__index != COMMEND_FILTER_INDEX_INVALID)

extern COMMENDDllExport
RTIBool COMMENDFilterStatus_copy(struct COMMENDFilterStatus * out, const struct COMMENDFilterStatus * in);

extern COMMENDDllExport
RTIBool COMMENDFilterStatus_equal(const struct COMMENDFilterStatus * left, const struct COMMENDFilterStatus * right);

extern COMMENDDllExport
RTI_UINT32 COMMENDFilterStatus_allocateIndex(struct COMMENDFilterStatus * me, RTI_UINT32 limit);


#define COMMENDFilterStatus_freeIndex(__me,__bitnum) \
  ((__bitnum < COMMEND_FILTER_INDEX_MAX) ? ((__me)->state |= (1<<(__bitnum))) : ((__me)->_extended[(__bitnum)/COMMEND_FILTER_INDEX_MAX].state |= (1<<(__bitnum % COMMEND_FILTER_INDEX_MAX))))


struct COMMENDWriterServiceProperty {
    /* local writer table property */
    struct REDATableProperty localTable;

    /* remote reader table property */
    struct REDATableProperty remoteTable;

    /* writer group table property */
    struct REDATableProperty groupTable;

    /*e Max number of destinations per send. Should >=
      COMMEND_COMMON_APP_IPADDRESS_COUNT_MAX */
    int destinationFanoutMax;

    int statsRemoteReaderFanoutMax;
};


  #define COMMEND_WRITER_SERVICE_PROPERTY_DEFAULT {  \
    /* localTable */              \
    {{16, REDA_FAST_BUFFER_POOL_UNLIMITED, REDA_FAST_BUFFER_POOL_UNLIMITED}, \
     1}, \
    /* remoteTable */ \
    {{16, REDA_FAST_BUFFER_POOL_UNLIMITED, REDA_FAST_BUFFER_POOL_UNLIMITED}, \
     1}, \
    /* groupTable */ \
    {{16, REDA_FAST_BUFFER_POOL_UNLIMITED, REDA_FAST_BUFFER_POOL_UNLIMITED}, \
     1}, \
    COMMEND_COMMON_APP_IPADDRESS_COUNT_MAX, /* destinationFanoutMax */ \
    16 /* statsRemoteReaderFanoutMax */ \
    }

struct COMMENDTransportEncapsulationInfo {
    NDDS_Transport_Plugin *plugin;
    int encapsulationCount;
    RTIEncapsulationId encapsulations[NETIO_LOCATOR_ENCAPSULATION_COUNT_MAX];
};


#define COMMEND_TRANSPORT_ENCAPSULATION_INFO_DEFAULT { \
   NULL, /* plugin */ \
   1, /* encapsulationCount */ \
   {RTI_CDR_ENCAPSULATION_ID_CDR_NATIVE,0,0,0,0,0,0,0}, /* encapsulations */ \
}

struct COMMENDWriterServiceWriterProperty {
    /*e The type of the writer. CSTWriter is true, PSWriter otherwise */
    RTIBool isCstWriter;
    /*e The rate to send periodic liviness heartbeat if necessary. */
    struct RTINtpTime livelinessRate;
    /*e transport priority */
    int transportPriority;
    /*e What transports to use for local writer */
    struct RTINetioAliasList transportAliasList;
    /*e Array of entryport for communication back from the reader.
      Max COMMEND_COMMON_APP_IPADDRESS_COUNT_MAX. */
    struct RTINetioLocator entryport[COMMEND_COMMON_APP_IPADDRESS_COUNT_MAX];
    /*e Number of entryports. Could be 0 if using default. Writers that do
      not receive anything from the reader may ignore this.
    */
    int entryportCount;
    /*e Indicate whether or not to replace dropped samples with a HB
     * if needed to maintain liveliness
     */
    RTIBool forceFilteredLiveliness;
    /*e Indicates whether the writer must be able to fragment large data
        if the data size exceeds the max message size of its transports. */
    RTIBool supportsFragments;
    /*e Denotes the token bucket to use. NULL if writing synchronously.
     */
    struct RTIEventJobDispatcherTokenBucket *tokenBucket;
    /*e Denotes the publishing thread to use. NULL is asynch publishing is disabled.
    */
    struct RTIEventJobDispatcherThread *asynchPubThread;
    /*e For asynch publishing flow controlling, how many bytes a single token is allowed to send.
    */
    int bytesPerToken;
    /*e Max asynch samples.
    */
    int maxAsynchSamples;
    /*e Indicates if batching is enabled or disabled
    */
    RTIBool batch;
    /*e Session ID of this writer
    */
    RTI_INT32 sessionId;
    /*e Indicates if this writer is one of multiple session-writers
    */
    RTIBool multiSession;
    /*e Indicates the publication priority of this writer, if one is assigned
    */
    RTI_INT32 publicationPriority;
    /*e Indicates if dataFrag messages should be compatible with RTI DDS 43
        In 43 the format of the DataFrag message was not compliant with the RTPS spec
    */
    RTIBool use43DataFragFormat;
    /*e
    */
    int transportEncapsulationInfoCount;
    /*e
    */
    struct COMMENDTransportEncapsulationInfo *transportEncapsulationInfo; /* array */
    /*e
    */
    int encapsulationInfoCount;
    /*e
    */
    struct RTIEncapsulationInfo *encapsulationInfo; /* array */
    /*e RTPS protocol overhead
    */
    int maxRtpsOverhead;
};


  #define COMMEND_WRITER_SERVICE_WRITER_PROPERTY_DEFAULT {  \
    RTI_FALSE, /* isCstWriter */                            \
    RTI_NTP_TIME_MAX, /* livelinessRate */                  \
    NDDS_TRANSPORT_PRIORITY_DEFAULT, /* transportPriority */\
    RTI_NETIO_ALIAS_LIST_DEFAULT, /* aliasList */           \
    {RTI_NETIO_LOCATOR_INVALID, /* transportAliasList */    \
     RTI_NETIO_LOCATOR_INVALID,                             \
     RTI_NETIO_LOCATOR_INVALID,                             \
     RTI_NETIO_LOCATOR_INVALID},                            \
    0,        /* entryportCount */   	         	    \
    RTI_TRUE, /* forceFilteredLiveliness  */                \
    RTI_FALSE,  /* supportsFragments */                      \
    NULL, /* tokenBucket */ \
    NULL, /* asynchPubThread */ \
    REDA_FAST_BUFFER_POOL_UNLIMITED /* maxAsynchSamples */, \
    RTI_FALSE, /* gatherStatistics */ \
    RTI_FALSE, /* batch */ \
    0, /* sessionId */ \
    RTI_FALSE, /* multiSession */ \
    COMMEND_PUBLICATION_PRIORITY_UNDEFINED, /*publicationPriority */ \
    RTI_FALSE,  /* use43DataFragFormat */ \
    0, /* encapsulationInfoCount */ \
    NULL, /* encapsulationInfo (array) */ \
    0, /* encapsulationCount */ \
    NULL, /* encapsulations (array) */ \
    COMMEND_WRITER_MAX_RTPS_OVERHEAD /* RTP protocol overhead */ \
  }

struct REDAInlineList;

struct COMMENDFilterSignature {
    int signature[4];
};


#define COMMEND_FILTER_SIGNATURE_DEFAULT {{0,0,0,0}}

struct COMMENDWriterServiceRemoteReaderProperty {
    /*e Locators that can be used to reach the remote reader.
      Nodes are of type COMMENDLocatorInlineNode, containing the real locator.
      If used as unicast locators, should be < RTPS_IP_ADDRESS_MAX.
      But anonymous writer may use it as unlimited number of locators.
      That is, if you don't treat multicast or unicast locators differently,
      you can mix them here.
    */
    struct REDAInlineList* locators;

    /*e Some implementations make a distinction between unicast
      locators and the multicast locators.  So when you need to make a
      distinction, use this list to indicate MULTICAST locators.
    */
    struct REDAInlineList* multicastLocators;
    /*e Some implementations make a distinction between unicast
      locators and the multicast locators.  So when you need to make a
      distinction, use this list to indicate MULTICAST locators.
    */
    struct REDAInlineList* sessionLocators;
    /*e Flag indicating whether reader is requiring inline QoS to be
    sent with every sample.
    */
    RTIBool expectsInlineQos;
    /*e Filtering index assigned by the PRES layer. The index maps into the
	filter status in a sample
     */
     int filterIndex;

    /*e Filter signature that is used by the user of the service
     * to filter samples.
     */
     struct COMMENDFilterSignature filterSignature;
};


  #define COMMEND_WRITER_SERVICE_REMOTE_READER_PROPERTY_DEFAULT { \
         NULL, /* locators */ \
         NULL, /* multicastLocators */ \
         NULL, /* sessionLocators */ \
         RTI_FALSE, /* expectsInlineQos */ \
         COMMEND_FILTER_INDEX_INVALID, /* filterIndex */ \
         COMMEND_FILTER_SIGNATURE_DEFAULT /* filterSignature */ \
  }

typedef RTIBool (*COMMENDWriterServiceWriteFunction)(
    struct COMMENDWriterService *me,
    struct REDASequenceNumber *firstUnackedSnOut,
    const struct REDAWeakReference *writer,
    const struct REDASequenceNumber *firstSn,
    const struct REDASequenceNumber *firstVirtualSn,
    const struct MIGGeneratorSample *sample,
    const struct RTINtpTime* nowIn,
    const struct RTINtpTime* blockTime,
    struct COMMENDFilterStatus *filterStatus,
    struct REDAWorker *worker);

typedef RTIBool (*COMMENDWriterServiceLivelinessAssertFunction)(
    struct COMMENDWriterService *me, const struct REDAWeakReference *writer,
    struct REDAWorker *worker);

typedef RTIBool (*COMMENDWriterServiceWriterCreateFunction)(
    struct COMMENDWriterService *me,
    struct REDAWeakReference *recordWROut,
    MIGRtpsObjectId oid,
    const struct COMMENDWriterServiceWriterSampleListener *sListener,
    const struct COMMENDWriterServiceWriterActivityListener *aListener,
    const struct COMMENDWriterServiceWriterStatusListener *statusListener,
    const struct COMMENDWriterServiceWriterListenerStorage *storage,
    const struct COMMENDWriterServiceWriterProperty *property,
    const struct REDASequenceNumber * firstSn,
    const struct REDASequenceNumber * lastSn,
    const struct REDASequenceNumber * firstVirtualSn,
    const struct REDASequenceNumber * lastVirtualSn,
    const struct REDASequenceNumber * lowestUnackSn,
    struct REDAExclusiveArea *ea, struct REDAWorker *worker);

typedef RTIBool (*COMMENDWriterServiceWriterPropertySetFunction)(
    struct COMMENDWriterService *me, struct REDAWeakReference *writerWR,
    const struct COMMENDWriterServiceWriterProperty *property,
    struct REDAWorker *worker);

typedef RTIBool (*COMMENDWriterServiceGroupAssertFunction)(
    struct COMMENDWriterService *me, struct REDAWeakReference *recordWR,
    struct REDAWeakReference *writer,
    const struct RTINetioLocator* multicastLocator,
    struct REDAWorker *worker);

typedef RTIBool (*COMMENDWriterServiceRemoteReaderAssertFunction)(
    struct COMMENDWriterService *me,
    struct REDAWeakReference *reader,
    RTIBool * readerAlreadyExisted,
    const struct REDAWeakReference *writer,
    const struct REDAWeakReference *group,
    const struct MIGRtpsGuid *guid,
    const struct MIGRtpsGuid *virtualGuid,
    const RTIBool isDurSubReader,
    const struct COMMENDWriterServiceWriterListenerStorage *storage,
    const struct COMMENDWriterServiceRemoteReaderProperty *property,
    struct REDAWorker *worker);

typedef RTIBool (*COMMENDWriterServiceWriterDestroyFunction)(
    struct COMMENDWriterService *w, MIGRtpsObjectId oid,
    struct REDAWorker *worker);

typedef RTIBool (*COMMENDWriterServiceGroupRemoveFunction)(
    struct COMMENDWriterService *me, struct REDAWeakReference *group,
    struct REDAWorker *worker);

typedef RTIBool (*COMMENDWriterServiceRemoteReaderRemoveFunction)(
    struct COMMENDWriterService *w, MIGRtpsObjectId oid,
    const struct MIGRtpsGuid *guid, struct REDAWorker *worker);

typedef RTIBool (*COMMENDWriterServiceStateChangedFunction)(
    struct COMMENDWriterService *w, const struct REDAWeakReference *writer,
    const struct REDASequenceNumber *firstSn,
    const struct REDASequenceNumber *lastSn,
    const struct REDASequenceNumber *firstVirtualSn,
    const struct REDASequenceNumber *lastVirtualSn,
    struct REDAWorker *worker);

typedef void (*COMMENDWriterServiceShutdownFunction)
    (struct COMMENDWriterService *w, struct REDAWorker *worker);

typedef void (*COMMENDWriterServiceDeletionFunction)
    (struct COMMENDWriterService *w, struct REDAWorker *worker);

typedef RTIBool (*COMMENDWriterServiceGetLocalWriterStatisticsFunction)
    (struct COMMENDWriterService *w,
     struct COMMENDWriterServiceLocalWriterStatistics *stats,
     const struct REDAWeakReference *writer,
     RTIBool clearChange,
     struct REDAWorker *worker);

typedef RTIBool (*COMMENDWriterServiceGetMatchedSubscriptionStatisticsFunction)
    (struct COMMENDWriterService *w,
     struct COMMENDWriterServiceMatchedReaderStatistics *status,
     const struct MIGRtpsGuid *guid,
     const struct REDAWeakReference *writer,
     RTIBool clearChange,
     struct REDAWorker *worker);

typedef RTIBool (*COMMENDWriterServiceGetMatchedSubscriptionStatisticsByLocatorFunction)
    (struct COMMENDWriterService *w,
     struct COMMENDWriterServiceMatchedDestinationStatistics *status,
     const struct RTINetioLocator *locator,
     const struct REDAWeakReference *writer,
     RTIBool clearChange,
     struct REDAWorker *worker);

typedef RTIBool (*COMMENDWriterServiceSetLocalWriterStatisticsFunction)
    (struct COMMENDWriterService *w,
     const struct COMMENDWriterServiceLocalWriterStatistics *stats,
     const struct REDAWeakReference *writer,
     struct REDAWorker *worker);

typedef RTIBool (*COMMENDWriterServiceSetMatchedSubscriptionStatisticsFunction)
    (struct COMMENDWriterService *w,
     const struct COMMENDWriterServiceMatchedReaderStatistics *status,
     const struct MIGRtpsGuid *guid,
     const struct REDAWeakReference *writer,
     struct REDAWorker *worker);

typedef RTIBool (*COMMENDWriterServiceSetMatchedSubscriptionStatisticsByLocatorFunction)
    (struct COMMENDWriterService *w,
     const struct COMMENDWriterServiceMatchedDestinationStatistics *status,
     const struct RTINetioLocator *locator,
     const struct REDAWeakReference *writer,
     struct REDAWorker *worker);

typedef RTIBool (*COMMENDWriterServiceGetMatchedDestinations)
    (struct COMMENDWriterService *w,
     RTI_INT32 *matchedLocatorCount,
     struct RTINetioLocator *matchedLocators,
     const struct REDAWeakReference *writer,
     struct REDAWorker *worker);

typedef RTIBool (*COMMENDWriterServiceInvalidateRemoteReaderFilterFunction)(struct COMMENDWriterService *w,
										   MIGRtpsObjectId oid,
										   const struct MIGRtpsGuid *guid,
										   struct REDAWorker *worker);

struct COMMENDWriterService {
    /*e */
    COMMENDWriterServiceWriterCreateFunction       createWriter;
    /*e */
    COMMENDWriterServiceWriterPropertySetFunction  setWriterProperty;
    /*e */
    COMMENDWriterServiceWriterDestroyFunction      destroyWriter;
    /*e */
    COMMENDWriterServiceGroupAssertFunction        assertGroup;
    /*e */
    COMMENDWriterServiceGroupRemoveFunction        removeGroup;
    /*e */
    COMMENDWriterServiceRemoteReaderAssertFunction assertRemoteReader;
    /*e */
    COMMENDWriterServiceRemoteReaderRemoveFunction removeRemoteReader;
    /*e */
    COMMENDWriterServiceInvalidateRemoteReaderFilterFunction invalidateRemoteReaderFilter;
    /*e */
    COMMENDWriterServiceWriteFunction              write;
    /*e */
    COMMENDWriterServiceStateChangedFunction       stateChanged;
    COMMENDWriterServiceLivelinessAssertFunction   assertLiveliness;
    COMMENDWriterServiceShutdownFunction           shutdown;
    COMMENDWriterServiceDeletionFunction           deleteService;

    COMMENDWriterServiceGetMatchedDestinations getMatchedDestinations;

    COMMENDWriterServiceGetLocalWriterStatisticsFunction    getLocalWriterStatistics;
    COMMENDWriterServiceGetMatchedSubscriptionStatisticsFunction    getMatchedSubscriptionStatistics;
    COMMENDWriterServiceGetMatchedSubscriptionStatisticsByLocatorFunction   getMatchedSubscriptionStatisticsByLocator;

    COMMENDWriterServiceSetLocalWriterStatisticsFunction    setLocalWriterStatistics;
    COMMENDWriterServiceSetMatchedSubscriptionStatisticsFunction    setMatchedSubscriptionStatistics;
    COMMENDWriterServiceSetMatchedSubscriptionStatisticsByLocatorFunction   setMatchedSubscriptionStatisticsByLocator;
};


#ifdef __cplusplus
    }	/* extern "C" */
#endif

  #include "commend/commend_writerService_impl.h"

#endif /* commend_writerService_h */
