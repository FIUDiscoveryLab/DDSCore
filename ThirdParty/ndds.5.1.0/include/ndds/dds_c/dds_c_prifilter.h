/* (c) Copyright, Real-Time Innovations, Inc. 2003-2009. All rights reserved. */
/*
 * @(#)dds_c_prifilter.h    generated by: makeheader    Sat Nov 23 02:39:24 2013
 *
 *		built from:	prifilter.ifc
 */

#ifndef dds_c_prifilter_h
#define dds_c_prifilter_h


  #ifndef dds_c_sequence_h
     #include "dds_c/dds_c_sequence.h"
  #endif
  #ifndef dds_c_infrastructure_h
    #include "dds_c/dds_c_infrastructure.h"
  #endif
  #ifndef dds_c_dll_h
#include "dds_c/dds_c_dll.h"
  #endif
  #ifndef dds_c_topic_h
    #include "dds_c/dds_c_topic.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif


#define DDS_PRIFILTER_RETCODE_OK                     0
#define DDS_PRIFILTER_RETCODE_SYNTAX_ERROR          -1
#define DDS_PRIFILTER_RETCODE_EMPTY_EXPRESSION      -2
#define DDS_PRIFILTER_RETCODE_INVALID_EXPRESSION    -3
#define DDS_PRIFILTER_RETCODE_UNMATCHED_NESTING     -4
#define DDS_PRIFILTER_RETCODE_ALLOCATION_ERROR      -5

extern DDSCDllVariable const char *const DDS_PRIFILTER_NAME;

struct DDS_TypeCode;

extern DDSCDllExport DDS_ReturnCode_t
DDS_PriFilter_compile(void *filter_data,
                      void **newHandle,
                      const char *expression,
                      const struct DDS_StringSeq *parameters,
                      const struct DDS_TypeCode *typeCode,
                      const char *typeClassName,
                      void *oldhandle);

extern DDSCDllExport DDS_Boolean
DDS_PriFilter_evaluate(void *filterData, void *handle,
                       const void *sample, const struct DDS_FilterSampleInfo * meta_data);

extern DDSCDllExport void
DDS_PriFilter_finalize(void* filterData, void *handle);

extern DDSCDllExport DDS_Long
DDS_PriFilter_query(void* filterData, void *handle);

 extern DDSCDllVariable const struct DDS_ContentFilter DDS_PRI_FILTER;


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* dds_c_prifilter_h */
