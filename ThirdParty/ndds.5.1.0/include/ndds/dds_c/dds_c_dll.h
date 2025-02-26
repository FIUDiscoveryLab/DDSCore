/* (c) Copyright, Real-Time Innovations, Inc. 2003-2009. All rights reserved. */
/*
 * @(#)dds_c_dll.h    generated by: makeheader    Sat Nov 23 02:39:22 2013
 *
 *		built from:	dll.ifc
 */

#ifndef dds_c_dll_h
#define dds_c_dll_h



#if defined(RTI_WIN32) || defined(RTI_WINCE)
  #if defined(RTI_dds_c_DLL_EXPORT)
    #define DDSCDllExport __declspec( dllexport )
  #else
    #define DDSCDllExport
  #endif /* RTI_dds_c_DLL_EXPORT */

  #if defined(RTI_dds_c_DLL_VARIABLE) 
    #if defined(RTI_dds_c_DLL_EXPORT)
      #define DDSCDllVariable __declspec( dllexport )
    #else
      #define DDSCDllVariable __declspec( dllimport )
    #endif /* RTI_dds_c_DLL_EXPORT */
  #else 
    #define DDSCDllVariable
  #endif /* RTI_dds_c_DLL_VARIABLE */
#else
  #define DDSCDllExport
  #define DDSCDllVariable
#endif /* RTI_WIN32 || RTI_WINCE */




#if defined(__cplusplus) && defined(RTI_USE_CPP_API)
  #define RTI_CPP
#endif


#endif /* dds_c_dll_h */
