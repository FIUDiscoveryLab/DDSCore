/* (c) Copyright, Real-Time Innovations, Inc. 2003-2009. All rights reserved. */
/*
 * @(#)commend_anonWriterService.h    generated by: makeheader    Sat Nov 23 02:38:40 2013
 *
 *		built from:	anonWriterService.ifc
 */

#ifndef commend_anonWriterService_h
#define commend_anonWriterService_h


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
  #ifndef commend_writerService_h
    #include "commend/commend_writerService.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif

struct RTIClock;

struct REDADatabase;

struct COMMENDAnonWriterServiceWriterProperty {
    /*e Parent property */
    struct COMMENDWriterServiceWriterProperty parent;
    /*e Type of writer: BROADCASTER or TRANSPONDER */
    RTIBool isBroadcaster;
    /*e The rate to send periodic heartbeat. If ZERO, the writer is
     RESPONDER */
    struct RTINtpTime heartbeatRate;
    /*e The delay between receiving nack and sending response */
    struct RTINtpTime nackResponseDelay;
    /*e Max output user data size for one repair packet (in bytes) */
    int outputLoadMax;
    
    /* The following parameters configure the behavior of the feature used
     * to announce a participant to the default domain 0.
     * 
     * See CORE-5634 for additional details
     */
    
    /* The rate at which a participant is announced to the default domain. 
     * If ZERO, the participant is not announced periodically
     */
    struct RTINtpTime domainBroadcastRate;
    /* Locator in which a participant is announced to the default domain */
    struct RTINetioLocator domainBroadcastLocator;
};


  #define COMMEND_ANON_WRITER_SERVICE_WRITER_PROPERTY_DEFAULT {    \
      COMMEND_WRITER_SERVICE_WRITER_PROPERTY_DEFAULT, /* parent */ \
    RTI_TRUE, /* isBroadcaster */                                  \
    {30, 0}, /* heartbeatRate 30 sec*/                             \
    {0, 0}, /* nackResponseDelay */                                \
    5000,                                                          \
    {0,0}, /* domainBroadcastRate */                               \
    RTI_NETIO_LOCATOR_INVALID}

extern COMMENDDllExport struct COMMENDAnonWriterService *
COMMENDAnonWriterService_new(
    struct REDADatabase *db, struct COMMENDFacade *facade,
    struct COMMENDWriterServiceProperty *property,
    struct REDAExclusiveArea *ea, struct REDAWorker *worker);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* commend_anonWriterService_h */
