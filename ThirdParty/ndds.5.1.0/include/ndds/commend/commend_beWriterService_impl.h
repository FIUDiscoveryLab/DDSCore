/* (c) Copyright, Real-Time Innovations, Inc. 2003-2009. All rights reserved. */
/*
 * @(#)commend_beWriterService_impl.h    generated by: makeheader    Sat Nov 23 02:38:39 2013
 *
 *		built from:	beWriterService_impl.ifc
 */

#ifndef commend_beWriterService_impl_h
#define commend_beWriterService_impl_h


#ifndef osapi_bufferUtils_h
  #include "osapi/osapi_bufferUtils.h"
#endif
#ifndef reda_orderedDataType_h
  #include "reda/reda_orderedDataType.h"
#endif
#ifndef mig_rtps_h
  #include "mig/mig_rtps.h"
#endif

#ifdef __cplusplus
    extern "C" {
#endif


/* ---------------------------------------------------------------- */
#define COMMENDBeWriterServiceProperty_copy(to, from) \
   RTIOsapiMemory_copy(to, from, sizeof(struct COMMENDBeWriterServiceProperty))

/* ---------------------------------------------------------------- */
#define COMMENDBeWriterServiceRemoteReaderProperty_copy(to, from) \
   RTIOsapiMemory_copy(to, from,                                  \
              sizeof(struct COMMENDBeWriterServiceRemoteReaderProperty))


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* commend_beWriterService_impl_h */
