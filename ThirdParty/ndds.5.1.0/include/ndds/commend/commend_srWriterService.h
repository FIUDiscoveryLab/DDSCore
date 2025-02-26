/* (c) Copyright, Real-Time Innovations, Inc. 2003-2009. All rights reserved. */
/*
 * @(#)commend_srWriterService.h    generated by: makeheader    Sat Nov 23 02:38:40 2013
 *
 *		built from:	srWriterService.ifc
 */

#ifndef commend_srWriterService_h
#define commend_srWriterService_h


  #ifndef reda_worker_h
    #include "reda/reda_worker.h"
  #endif
  #ifndef reda_weakReference_h
    #include "reda/reda_weakReference.h"
  #endif
  #ifndef reda_database_h
    #include "reda/reda_database.h"
  #endif
  #ifndef mig_rtps_h
    #include "mig/mig_rtps.h"
  #endif
  #ifndef commend_dll_h
    #include "commend/commend_dll.h"
  #endif
  #ifndef commend_common_h
    #include "commend/commend_common.h"
  #endif
  #ifndef commend_writerService_h
    #include "commend/commend_writerService.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif

struct RTIClock;

struct REDADatabase;

struct COMMENDSrWriterService;


  /* NON_VOLATILE includes both TRANSIENT, TRANSIENT_LOCAL and PERSISTENT */
  #define COMMEND_WRITER_SERVICE_REMOTE_READER_NON_VOLATILE (1)
  #define COMMEND_WRITER_SERVICE_REMOTE_READER_VOLATILE  (2)

  #define COMMEND_SR_WRITER_SERVICE_SAMPLE_PTR_ARRAY_MAX (32)

struct COMMENDSrWriterServiceWriterProperty {
    /*e Parent property */
    struct COMMENDWriterServiceWriterProperty parent;
    /*e <<Immutable>>. Push data when write, or wait until NACK. */
    RTIBool pushMode;
    /*e The rate to send periodic heartbeat. Cannot be RTI_NTP_TIME_ZERO */
    struct RTINtpTime heartbeatRate;
    /*e The rate to send fast periodic heartbeat. Cannot be RTI_NTP_TIME_ZERO */
    struct RTINtpTime heartbeatRateFast;
    /*e The rate to send periodic heartbeat to late-joiners.  
    Cannot be RTI_NTP_TIME_ZERO */
    struct RTINtpTime heartbeatRateLateJoiner;
    /*e The rate to send periodic heartbeat containing the virtual writer infos
    Cannot be RTI_NTP_TIME_ZERO */
    struct RTINtpTime heartbeatVirtualRate;
    /*e Number of samples between two piggyback virtual heartbeats */
    int samplesPerVirtualHeartbeat;
    /*e Whether late-joiner is serviced by heartbeatRateLateJoiner until 
    all available samples or until reaching the level of an existing reader */
    RTIBool lateJoinerAckAll; 
    /*e Whether to send HB at the fast rate or the normal rate */
    RTIBool useHeartbeatRateFast;
    /*e Max number of heartbeat to timeout a remote reader */
    int heartbeatRetriesMax;
    /*e Max output user data size for one repair packet (in bytes).
        If < 0, we will count the negative of the maximum number of samples
        that can be sent in 1 repair packet.  There are times (e.g. multicast
        repair packet) when this is a more meaningful bound.
    */
    int outputLoadMax;
    /*e Number of samples between two piggyback heartbeats */
    int samplesPerHeartbeat;
    /*e Duration to ignore NACKs that trigger redundant repairs */
    struct RTINtpTime nackSuppressionDuration;
    /*e Whether readers ACKs are enabled */
    RTIBool disableAcks;
    /*e Minimum duration for which a sample is retained for an ACK-suppressed reader */
    struct RTINtpTime minAckDelay;
    /*e Maximum duration for which a sample is retained for an ACK-suppressed reader */
    struct RTINtpTime maxAckDelay;
    struct RTINtpTime ackDelayMinSeparation;
    RTIBool enableAdaptiveAckDelay;
    RTI_INT32 decreaseAckDelayScaler;
    RTI_INT32 increaseAckDelayScaler;
    /*e The rate to check ACK and timeout state of samples */
    struct RTINtpTime ackStateUpdateRate;

    struct REDAFastBufferPoolGrowthProperty sampleCount;

    /*e Indicates whether a non-progressing NACK is counted towards 
        the heartbeat-retries (remote-reader activity) count 
    */
    RTIBool nonProgressingNackIsInactive;

    /*e This member must be set to RTI_TRUE to disable the preemptive HB */
    RTIBool disablePreemptiveHB;

    int minWindowSize;
    int maxWindowSize;
    RTINtpTime sendWindowUpdatePeriod;
    int sendWindowIncreaseFactor;
    int sendWindowDecreaseFactor;

    RTIBool sendMulticastPeriodicHB;
    int multicastRepairThreshold;

    int changeSendWindowRatioThreshold;

    int maxOutstandingNackBitmap;

    COMMENDAppAckMode appAckMode;
    /* Is set by presentation. It tells if there are durSub or not*/
    RTIBool durSubEnabled;
    
    COMMENDSendWindowResizeMode sendWindowResizeMode;
};


  #define COMMEND_SR_WRITER_SERVICE_WRITER_PROPERTY_DEFAULT { \
    COMMEND_WRITER_SERVICE_WRITER_PROPERTY_DEFAULT,           \
    RTI_TRUE,                                                 \
    {30, 0}, /* heartbeatRate 30 sec*/                        \
    {30, 0}, /* heartbeatRateFast 30 sec*/                    \
    {30, 0}, /* heartbeatRateLateJoiner 30 sec */             \
    RTI_NTP_TIME_MAX, /* heartbeatVirtualRate */              \
    -1, /* samplesPerVirtualHeartbeat */                 \
    RTI_FALSE, /* lateJoinerAckAll No */                      \
    RTI_FALSE, /* useHeartbeatRateFast No */                  \
    10, /* heartbeatRetriesMax */                             \
    5000, /* outputLoadMax */                                 \
    1, /* samplesPerHeartbeat */                              \
    {0, 0}, /* nackSuppressionDuration */                     \
    RTI_FALSE, /* disableAcks */                              \
    {0, 4294967}, /* minAckDelay */                            \
    {1, 0}, /* maxAckDelay */                                 \
    {0, 429496}, /* min separation (100us) */                 \
    RTI_TRUE, /* enableAdaptiveAckDelay */                    \
    95, /* ackDelayDownScaler*/                             \
    150, /* ackDelayUpScaler */                               \
    {1, 0}, /* ackStateUpdateRate */                          \
    REDA_FAST_BUFFER_POOL_GROWTH_PROPERTY_DEFAULT, /* sampleCount */ \
    RTI_FALSE, /* nonProgressingNackIsInactive */ \
    RTI_FALSE, /* disablePreemptiveHB */  \
    256, /* minWindowSize */ \
    256, /* maxWindowSize */ \
    {30,0}, /* sendWindowUpdatePeriod */ \
    105, /* sendWindowIncreaseFactor */ \
    50, /* sendWindowDecreaseFactor */ \
    RTI_FALSE, /* sendMulticastPeriodicHB */ \
    2, /* multicastRepairThreshold */ \
    2, /* changeSendWindowRatioThreshold */ \
    8, /* maxOutstandingNackBitmap */ \
    COMMEND_PROTOCOL_ACK_MODE, /* appAckMode */ \
    RTI_FALSE, /*durSubEnabled*/ \
	COMMEND_SEND_WINDOW_RESIZE_PUSH_PULL_RATIO_MODE /*sendWindowResizeMode*/ \
}

struct COMMENDSrWriterServiceRemoteReaderProperty {
    /*e parent property */
    struct COMMENDWriterServiceRemoteReaderProperty parent;
    /*e persistence type */
    int persistenceType;
    /*e disable ACKs */
    RTIBool disableAcks;
    /*e Flag determining fragmentBitmap's starting SN */
    RTIBool startFragmentBitmapFromZero;

    /* alex TODO: rename/move type?*/
    COMMENDAppAckMode appAckMode;

    /*i Indicates if the reader expects virtual HB */	
    RTIBool expectsHBVirtual;
};


  #define COMMEND_SR_WRITER_SERVICE_REMOTE_READER_PROPERTY_DEFAULT {     \
    COMMEND_WRITER_SERVICE_REMOTE_READER_PROPERTY_DEFAULT, /* parent */  \
    COMMEND_WRITER_SERVICE_REMOTE_READER_NON_VOLATILE, /* persistenceType */ \
    RTI_FALSE, /* disableAcks */ \
    RTI_FALSE, /* startFragmentBitmapFromZero */ \
    COMMEND_PROTOCOL_ACK_MODE, /* appAckMode */ \
    RTI_FALSE /* disable HeartbeatVirtuals */ \
}

extern COMMENDDllExport struct COMMENDSrWriterService *
COMMENDSrWriterService_new(
    struct REDADatabase *db, struct COMMENDFacade *facade,
    struct COMMENDWriterServiceProperty *property,
    struct REDAExclusiveArea *ea, struct REDAWorker *worker);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

  #include "commend/commend_srWriterService_impl.h"

#endif /* commend_srWriterService_h */
