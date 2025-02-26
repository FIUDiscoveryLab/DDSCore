/* (c) Copyright, Real-Time Innovations, Inc. 2003-2009. All rights reserved. */
/*
 * @(#)connext_cpp_dll.h    generated by: makeheader    Sat Nov 23 02:41:09 2013
 *
 *		built from:	dll.ifcxx
 */

#ifndef connext_cpp_dll_h
#define connext_cpp_dll_h



#if defined(RTI_WIN32) || defined(RTI_WINCE)
  #if defined(RTI_connext_cpp_DLL_EXPORT)
    #define XMQCPPDllExport __declspec( dllexport )
  #else
    #define XMQCPPDllExport
  #endif /* RTI_connext_cpp_DLL_EXPORT */

  #if defined(RTI_connext_cpp_DLL_VARIABLE) 
    #if defined(RTI_connext_cpp_DLL_EXPORT)
      #define XMQCPPDllVariable __declspec( dllexport )
    #else
      #define XMQCPPDllVariable __declspec( dllimport )
    #endif /* RTI_connext_cpp_DLL_EXPORT */
  #else 
    #define XMQCPPDllVariable
  #endif /* RTI_connext_cpp_DLL_VARIABLE */
#else
  #define XMQCPPDllExport
  #define XMQCPPDllVariable
#endif /* RTI_WIN32 || RTI_WINCE */

/* Use the C++ constructs that are included in the DDS/C interfaces. */
#ifndef RTI_USE_CPP_API
#define RTI_USE_CPP_API
#endif


#endif /* connext_cpp_dll_h */
