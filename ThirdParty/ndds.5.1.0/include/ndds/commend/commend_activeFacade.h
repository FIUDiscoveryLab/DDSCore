/* (c) Copyright, Real-Time Innovations, Inc. 2003-2009. All rights reserved. */
/*
 * @(#)commend_activeFacade.h    generated by: makeheader    Sat Nov 23 02:38:39 2013
 *
 *		built from:	activeFacade.ifc
 */

#ifndef commend_activeFacade_h
#define commend_activeFacade_h



  #ifndef event_activeGenerator_h
    #include "event/event_activeGenerator.h"
  #endif
  #ifndef mig_rtps_h
    #include "mig/mig_rtps.h"
  #endif
  #ifndef commend_dll_h
    #include "commend/commend_dll.h"
  #endif
  #ifndef commend_facade_h
    #include "commend/commend_facade.h"
  #endif
  #ifndef osapi_threadFactory_h
    #include "osapi/osapi_threadFactory.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif

struct COMMENDActiveFacade;

struct RTIEventActiveDatabase;

struct RTINetioConfigurator;

extern COMMENDDllExport RTIBool
COMMENDActiveFacade_preShutdownWakeup(struct COMMENDActiveFacade *me,
				      struct REDAWorker *worker);

extern COMMENDDllExport RTIBool
COMMENDActiveFacade_shutdown(struct COMMENDActiveFacade *me,
			     struct REDAWorker *worker);

extern COMMENDDllExport void
COMMENDActiveFacade_delete(struct COMMENDFacade *me,
			   struct REDAWorker *worker);

typedef void (*COMMENDActiveFacadeThreadListenerOnStartedCallback)(
    struct COMMENDActiveFacade *me, void *onStartedParam,
    struct REDAWorker *worker);

typedef void (*COMMENDActiveFacadeThreadListenerOnStoppedCallback)(
    struct COMMENDActiveFacade *me, void *onStoppedParam,
    struct REDAWorker *worker);

struct COMMENDActiveFacadeThreadListener {
    /*e Called when a new thread is just started.
    */
    COMMENDActiveFacadeThreadListenerOnStartedCallback onStarted;
    /*e Associated with the onStarted() method */
    void *onStartedParam;
    /*e Called when the thread is about to stop.
    */
    COMMENDActiveFacadeThreadListenerOnStoppedCallback onStopped;
    /*e Associated with the onStopped() method */
    void *onStoppedParam;
};

struct COMMENDActiveFacadeProperty {
    struct COMMENDFacadeProperty parent;

    /*e There will only be 1 event thread 
      @see RTIEventActiveGeneratorProperty
     */
    struct RTIEventActiveGeneratorProperty activeEventGenerator;

    /*e there will be as many receiver threads are there are entryports */
    struct RTIEventActiveObjectProperty activeReceiver;

    /*e Unless all transports will loan the buffer on reception (IP transport
     does not, for example.) the receiver needs some buffer space to hold
     the received messages.  This should be the largest size message you
     expect to receive on over ALL transports that do NOT loan the buffer.
     For example, if you are using 4 separate transports, with the following
     capability:
     <verbatim>
     TP     max message size  loans buffer?  alignment req'd
     -----  ----------------  -------------  ---------------
     TP1    1K                never          32 bytes
     TP2    5K                always         8  bytes
     TP3    9K                sometimes      16 bytes
     TP4    10M               always         4  bytes
     </verbatim>
     Then the required buffer size is 9K.
    */
    int receiveBufferSize;

    /*e
      To parse RTPS messages, you need the minimum alignment of
      MIG_RTPS_SUBMESSAGE_ALIGNMENT.  But some user supplied transports
      (like VME) require greater alignment.  The alignment required for
      receiver thread pool is the maximum alignment required among
      transports that does NOT always loan its buffer.
      In the example for COMMENDActiveFacadeProperty#receiveBufferSize,
      the alignment required is 32 bytes, belonging to TP1.
     */
    int receiveBufferAlignment;
    /*e Control growth of thread table */
    struct REDAFastBufferPoolGrowthProperty receiveThreadGrowth;
    /*e
      The wakeup period during cleanup to check if cleanup has finished.
     */
    struct RTINtpTime wakeupPeriodDuringCleanup;
};


#define COMMEND_ACTIVE_FACADE_PROPERTY_DEFAULT {                      \
    COMMEND_FACADE_PROPERTY_DEFAULT,                                  \
    RTI_EVENT_ACTIVE_GENERATOR_PROPERTY_DEFAULT, /* activeEventGenerator */ \
    RTI_EVENT_ACTIVE_OBJECT_PROPERTY_DEFAULT, /* activeReceiver */    \
    COMMEND_LENGTH_AUTO,                      /* receiveBufferSize */ \
    MIG_RTPS_SUBMESSAGE_ALIGNMENT,            /* receiveBufferAlignment */ \
    /* receiveThreadGrowth */  \
    {8, REDA_FAST_BUFFER_POOL_UNLIMITED, REDA_FAST_BUFFER_POOL_UNLIMITED}, \
    {3, 0}                         /* wakeupPeriodDuringCleanup */         \
}

extern COMMENDDllExport struct COMMENDFacade *
COMMENDActiveFacade_new(
    struct REDAWorkerFactory *workerFactory,
    struct RTIEventActiveDatabase *activeDb,
    struct REDAExclusiveArea *tableEa,
    struct RTIClock *clock,
    struct RTIClock *timestampClock,
    const struct COMMENDActiveFacadeThreadListener *threadListener,
    const struct COMMENDActiveFacadeProperty *property,
    struct RTINetioConfigurator* configuratorIn,
    struct RTIOsapiThreadFactory *recvThreadFactory,
    struct RTIOsapiThreadFactory *eventThreadFactory, 
    struct RTIOsapiThreadFactory *asynchPubThreadFactory, 
    struct REDAWorker *worker);

extern COMMENDDllExport RTIBool
COMMENDActiveFacade_getProperty(
    struct COMMENDFacade *me,
    struct COMMENDActiveFacadeProperty *property);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* commend_activeFacade_h */
