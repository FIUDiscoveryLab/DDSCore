/* (c) Copyright, Real-Time Innovations, Inc. 2003-2009. All rights reserved. */
/*
 * @(#)commend_common_impl.h    generated by: makeheader    Sat Nov 23 02:38:38 2013
 *
 *		built from:	common_impl.ifc
 */

#ifndef commend_common_impl_h
#define commend_common_impl_h



  #ifndef osapi_alignment_h
    #include "osapi/osapi_alignment.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif



#define COMMEND_calculateAppendedSize(testType, suffixSize, suffixAlignment) \
  (((suffixSize) <= 0) ? sizeof(testType) : \
    (RTIOsapiAlignment_alignSizeUp(sizeof(testType), (suffixAlignment)) + (suffixSize)))

#define COMMEND_calculateAppendedAlignment(testType, suffixSize, suffixAlignment) \
  (((suffixSize) <= 0) ? RTIOsapiAlignment_getAlignmentOf(testType) : \
   ((RTIOsapiAlignment_getAlignmentOf(testType) < (suffixAlignment)) ? \
     (suffixAlignment) : RTIOsapiAlignment_getAlignmentOf(testType)))

#define COMMEND_calculateAppendedPtr(entityPtr, testType, suffixSize, suffixAlignment) \
  (((suffixSize) <= 0) ? (void *)NULL : \
   (void *)((char *)(entityPtr) + RTIOsapiAlignment_alignSizeUp(sizeof(testType), (suffixAlignment))))



#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* commend_common_impl_h */
