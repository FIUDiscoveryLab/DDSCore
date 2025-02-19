/* (c) Copyright, Real-Time Innovations, Inc. 2003-2009. All rights reserved. */
/*
 * @(#)transport_common_stat_impl.h    generated by: makeheader    Sat Nov 23 02:38:25 2013
 *
 *		built from:	common_stat_impl.ifc
 */

#ifndef transport_common_stat_impl_h
#define transport_common_stat_impl_h



#ifndef osapi_bufferUtils_h
  #include "osapi/osapi_bufferUtils.h"
#endif
#ifndef reda_log_h
  #include "reda/reda_log.h"
#endif
#ifndef reda_worker_h
  #include "reda/reda_worker.h"
#endif

#ifdef __cplusplus
    extern "C" {
#endif


NDDS_Transport_DllVariable 
struct REDAObjectPerWorker *NDDS_TRANSPORT_STAT_PER_WORKER;

#define NDDS_Transport_WorkerStat_getStorageLazy(statPtr, worker) \
    ( *(statPtr) = (struct NDDS_Transport_WorkerStat *) \
        REDAWorker_assertObject(worker, NDDS_TRANSPORT_STAT_PER_WORKER) )


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* transport_common_stat_impl_h */
