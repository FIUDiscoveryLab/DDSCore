/*****************************************************************************/
/*         (c) Copyright, Real-Time Innovations, All rights reserved.        */
/*                                                                           */
/*         Permission to modify and use for internal purposes granted.       */
/* This software is provided "as is", without warranty, express or implied.  */
/*                                                                           */
/*****************************************************************************/

#ifndef __HELLO_H_INCLUDED__
#define __HELLO_H_INCLUDED__


/*****************************************************************************/
/* Unify some common functions and types between Unix and Windows            */
/*****************************************************************************/
#ifdef RTI_WIN32
#define RTI_SNPRINTF        _snprintf
#define RTI_STRCASECMP      _stricmp
#define RTI_STRNCASECMP     _strnicmp
#define RTI_STRTOULL        _strtoui64
#define RTI_STRTOUL         strtoul
#define RTI_STRNCMP         strncmp
#else
#define RTI_SNPRINTF        snprintf
#define RTI_STRCASECMP      strcasecmp
#define RTI_STRNCASECMP     strncasecmp
#define RTI_STRTOULL        strtoull
#define RTI_STRTOUL         strtoul
#define RTI_STRNCMP         strncmp
#endif


/* Defines the TCP transport library name */
#if defined(RTI_LINUX) || defined(RTI_UNIX)
  #define TRANSPORT_LIB_NAME        "libnddstransporttcp.so"
  #define TRANSPORT_LIB_NAME_DBG    "libnddstransporttcpd.so"
#elif defined(RTI_DARWIN) 
  #define TRANSPORT_LIB_NAME        "libnddstransporttcp.dylib"
  #define TRANSPORT_LIB_NAME_DBG    "libnddstransporttcpd.dylib"
#elif defined(RTI_WIN32)
  #define TRANSPORT_LIB_NAME        "NDDSTRANSPORTTCP.DLL"
  #define TRANSPORT_LIB_NAME_DBG    "NDDSTRANSPORTTCPD.DLL"
#else
#error unknown architecture
#endif



#endif            /* !defined(__HELLO_H_INCLUDED__) */
