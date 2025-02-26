/* (c) Copyright, Real-Time Innovations, Inc. 2003-2009. All rights reserved. */
/*
 * @(#)event_timer.h    generated by: makeheader    Sat Nov 23 02:38:16 2013
 *
 *		built from:	timer.ifc
 */

#ifndef event_timer_h
#define event_timer_h


  #ifndef osapi_type_h
    #include "osapi/osapi_type.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif

struct RTINtpTime; /* forward declare to appease the compiler */

struct REDAWorker;

struct RTIEventTimer;

typedef RTIBool
(*RTIEventTimerWakeupFunction)(struct RTIEventTimer *me);

typedef RTIBool
(*RTIEventTimerStartFunction)(struct RTIEventTimer *me);

typedef RTIBool
(*RTIEventTimerSleepFunction)(struct RTIEventTimer *me,
			      const struct RTINtpTime *sleepTime);

struct RTIEventTimer {
    /*e Only the event thread may call this */
    RTIEventTimerStartFunction start;
    /*e Only the event thread may call this */
    RTIEventTimerSleepFunction sleep;
    /*e Any thread except the event thread may call this */
    RTIEventTimerWakeupFunction wakeup;
};


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* event_timer_h */
