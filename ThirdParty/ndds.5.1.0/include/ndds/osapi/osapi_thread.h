/* (c) Copyright, Real-Time Innovations, Inc. 2003-2009. All rights reserved. */
/*
 * @(#)osapi_thread.h    generated by: makeheader    Sat Nov 23 02:37:48 2013
 *
 *		built from:	thread.ifc
 */

#ifndef osapi_thread_h
#define osapi_thread_h


  #ifndef osapi_ntptime_h
    #include "osapi/osapi_ntptime.h"
  #endif
  #ifndef osapi_dll_h
    #include "osapi/osapi_dll.h"
  #endif
  #ifndef osapi_cpu_h
    #include "osapi/osapi_cpu.h"
  #endif
  
#ifdef __cplusplus
    extern "C" {
#endif

struct RTIOsapiThread;



/*e \ingroup RTIOsapiThreadClass 
  Use only the default options the OS gives you. 
*/
#define RTI_OSAPI_THREAD_OPTION_DEFAULT     0x00
/*e \ingroup RTIOsapiThreadClass 
  Support floating point. 
*/
#define RTI_OSAPI_THREAD_OPTION_FLOATING_POINT      0x01
/*e \ingroup RTIOsapiThreadClass 
  This thread can do standard io. 
*/
#define RTI_OSAPI_THREAD_OPTION_STDIO               0x02
/*e \ingroup RTIOsapiThreadClass 
  This thread will run in real-time priority mode. 
*/
#define RTI_OSAPI_THREAD_OPTION_REALTIME_PRIORITY   0x08
/*e \ingroup RTIOsapiThreadClass 
  Insist on the specified priority and fail if OS doesn't like it. 
*/
#define RTI_OSAPI_THREAD_OPTION_PRIORITY_ENFORCE    0x10
/*e \ingroup RTIOsapiThreadClass 
  Set the flag to be able to asynchronously cancel thread. 
*/
#define RTI_OSAPI_THREAD_OPTION_CANCEL_ASYNCHRONOUS 0x20


#if defined(RTI_VXWORKS)

  typedef enum {
      RTI_OSAPI_THREAD_PRIORITY_HIGH         = 68,
      RTI_OSAPI_THREAD_PRIORITY_ABOVE_NORMAL = 71,
      RTI_OSAPI_THREAD_PRIORITY_NORMAL       = 100,
      RTI_OSAPI_THREAD_PRIORITY_BELOW_NORMAL = 110,
      RTI_OSAPI_THREAD_PRIORITY_LOW          = 120
  } RTIOsapiThreadPriority;

  #define RTI_OSAPI_THREAD_PRIORITY_DEFAULT RTI_OSAPI_THREAD_PRIORITY_NORMAL
  #define RTI_OSAPI_THREAD_STACK_SIZE_DEFAULT (30*1024)

#elif defined(RTI_PSOS)

  typedef enum {
      RTI_OSAPI_THREAD_PRIORITY_HIGH         = 150,
      RTI_OSAPI_THREAD_PRIORITY_ABOVE_NORMAL = 130,
      RTI_OSAPI_THREAD_PRIORITY_NORMAL       = 100,
      RTI_OSAPI_THREAD_PRIORITY_BELOW_NORMAL = 90,
      RTI_OSAPI_THREAD_PRIORITY_LOW          = 80
  } RTIOsapiThreadPriority;

  #define RTI_OSAPI_THREAD_PRIORITY_DEFAULT RTI_OSAPI_THREAD_PRIORITY_NORMAL
  #define RTI_OSAPI_THREAD_STACK_SIZE_DEFAULT (16*1024)

#elif defined(RTI_LYNX)

  typedef enum {
      RTI_OSAPI_THREAD_PRIORITY_HIGH         = 32,
      RTI_OSAPI_THREAD_PRIORITY_ABOVE_NORMAL = 29,
      RTI_OSAPI_THREAD_PRIORITY_NORMAL       = 17,
      RTI_OSAPI_THREAD_PRIORITY_BELOW_NORMAL = 13,
      RTI_OSAPI_THREAD_PRIORITY_LOW          = 10
  } RTIOsapiThreadPriority;

  #define RTI_OSAPI_THREAD_PRIORITY_DEFAULT RTI_OSAPI_THREAD_PRIORITY_NORMAL
  #define RTI_OSAPI_THREAD_STACK_SIZE_DEFAULT (16*1024)

#elif defined(RTI_NETOS)

  typedef enum {
      RTI_OSAPI_THREAD_PRIORITY_HIGH         = 6,
      RTI_OSAPI_THREAD_PRIORITY_ABOVE_NORMAL = 9,
      RTI_OSAPI_THREAD_PRIORITY_NORMAL       = 15,
      RTI_OSAPI_THREAD_PRIORITY_BELOW_NORMAL = 20,
      RTI_OSAPI_THREAD_PRIORITY_LOW          = 22
  } RTIOsapiThreadPriority;

  #define RTI_OSAPI_THREAD_PRIORITY_DEFAULT RTI_OSAPI_THREAD_PRIORITY_NORMAL
  #define RTI_OSAPI_THREAD_STACK_SIZE_DEFAULT (16*1024)

#elif defined(RTI_WIN32)

  typedef enum {
      RTI_OSAPI_THREAD_PRIORITY_HIGH         = 3,
      RTI_OSAPI_THREAD_PRIORITY_ABOVE_NORMAL = 2,
      RTI_OSAPI_THREAD_PRIORITY_NORMAL       = 0,
      RTI_OSAPI_THREAD_PRIORITY_BELOW_NORMAL = -2,
      RTI_OSAPI_THREAD_PRIORITY_LOW          = -3
  } RTIOsapiThreadPriority;

  #define RTI_OSAPI_THREAD_PRIORITY_DEFAULT RTI_OSAPI_THREAD_PRIORITY_NORMAL
  #define RTI_OSAPI_THREAD_STACK_SIZE_DEFAULT (0)

#elif defined(RTI_WINCE)

  typedef enum {
      RTI_OSAPI_THREAD_PRIORITY_HIGH         = 249,
      RTI_OSAPI_THREAD_PRIORITY_ABOVE_NORMAL = 250,
      RTI_OSAPI_THREAD_PRIORITY_NORMAL       = 251,
      RTI_OSAPI_THREAD_PRIORITY_BELOW_NORMAL = 252,
      RTI_OSAPI_THREAD_PRIORITY_LOW          = 253
  } RTIOsapiThreadPriority;

  #define RTI_OSAPI_THREAD_PRIORITY_DEFAULT RTI_OSAPI_THREAD_PRIORITY_NORMAL
  #define RTI_OSAPI_THREAD_STACK_SIZE_DEFAULT (0)

#elif defined(RTI_QNX)

  typedef enum {
      RTI_OSAPI_THREAD_PRIORITY_HIGH         = 60,
      RTI_OSAPI_THREAD_PRIORITY_ABOVE_NORMAL = 40,
      RTI_OSAPI_THREAD_PRIORITY_NORMAL       = 10,
      RTI_OSAPI_THREAD_PRIORITY_BELOW_NORMAL = 9,
      RTI_OSAPI_THREAD_PRIORITY_LOW          = 8
  } RTIOsapiThreadPriority;

  #define RTI_OSAPI_THREAD_PRIORITY_DEFAULT RTI_OSAPI_THREAD_PRIORITY_NORMAL
  #define RTI_OSAPI_THREAD_STACK_SIZE_DEFAULT (20*1024)

#elif defined(RTI_INTY)
  #if defined(RTI_INTY_VERSION_10)
  typedef enum {
      RTI_OSAPI_THREAD_PRIORITY_HIGH         = 127,
      RTI_OSAPI_THREAD_PRIORITY_ABOVE_NORMAL = 100,
      RTI_OSAPI_THREAD_PRIORITY_NORMAL       = 90,
      RTI_OSAPI_THREAD_PRIORITY_BELOW_NORMAL = 80,
      RTI_OSAPI_THREAD_PRIORITY_LOW          = 1
  } RTIOsapiThreadPriority;


  #define RTI_OSAPI_THREAD_PRIORITY_DEFAULT RTI_OSAPI_THREAD_PRIORITY_HIGH
  #define RTI_OSAPI_THREAD_STACK_SIZE_DEFAULT (30*1024)
  #else
  typedef enum {
      RTI_OSAPI_THREAD_PRIORITY_HIGH         = 120,
      RTI_OSAPI_THREAD_PRIORITY_ABOVE_NORMAL = 100,
      RTI_OSAPI_THREAD_PRIORITY_NORMAL       = 90,
      RTI_OSAPI_THREAD_PRIORITY_BELOW_NORMAL = 80,
      RTI_OSAPI_THREAD_PRIORITY_LOW          = 60
  } RTIOsapiThreadPriority;


  #define RTI_OSAPI_THREAD_PRIORITY_DEFAULT 16 
  #define RTI_OSAPI_THREAD_STACK_SIZE_DEFAULT (20*1024)
  #endif

#elif defined(RTI_OPENVMS)

  typedef enum {
      RTI_OSAPI_THREAD_PRIORITY_HIGH         = 15,
      RTI_OSAPI_THREAD_PRIORITY_ABOVE_NORMAL = 12,
      RTI_OSAPI_THREAD_PRIORITY_NORMAL       = 11,
      RTI_OSAPI_THREAD_PRIORITY_BELOW_NORMAL = 9,
      RTI_OSAPI_THREAD_PRIORITY_LOW          = 8
  } RTIOsapiThreadPriority;

  #define RTI_OSAPI_THREAD_PRIORITY_DEFAULT RTI_OSAPI_THREAD_PRIORITY_NORMAL
  #define RTI_OSAPI_THREAD_STACK_SIZE_DEFAULT (-1)

#elif defined(RTI_AIX)

  typedef enum {
      RTI_OSAPI_THREAD_PRIORITY_HIGH         = -9999999,
      RTI_OSAPI_THREAD_PRIORITY_ABOVE_NORMAL = -9999999,
      RTI_OSAPI_THREAD_PRIORITY_NORMAL       = -9999999,
      RTI_OSAPI_THREAD_PRIORITY_BELOW_NORMAL = -9999999,
      RTI_OSAPI_THREAD_PRIORITY_LOW          = -9999999
  } RTIOsapiThreadPriority;

  #define RTI_OSAPI_THREAD_PRIORITY_DEFAULT RTI_OSAPI_THREAD_PRIORITY_NORMAL

  /* The default stack size on 32 bit AIX is too small, the default for 64 bit
   * is 192KB, which is enough. Set the default high enough
   */
  #define RTI_OSAPI_THREAD_STACK_SIZE_DEFAULT (192*1024)
#else

  typedef enum {
      RTI_OSAPI_THREAD_PRIORITY_HIGH         = -9999999,
      RTI_OSAPI_THREAD_PRIORITY_ABOVE_NORMAL = -9999999,
      RTI_OSAPI_THREAD_PRIORITY_NORMAL       = -9999999,
      RTI_OSAPI_THREAD_PRIORITY_BELOW_NORMAL = -9999999,
      RTI_OSAPI_THREAD_PRIORITY_LOW          = -9999999
  } RTIOsapiThreadPriority;

  #define RTI_OSAPI_THREAD_PRIORITY_DEFAULT RTI_OSAPI_THREAD_PRIORITY_NORMAL
  #define RTI_OSAPI_THREAD_STACK_SIZE_DEFAULT (-1)

#endif/* setting of default thread property */


typedef void RTIOsapiThreadTssFactory;

extern RTIOsapiDllExport 
RTIOsapiThreadTssFactory * RTIOsapiThread_createTssFactory();

extern RTIOsapiDllExport 
void RTIOsapiThread_deleteTssFactory(RTIOsapiThreadTssFactory * factory);

extern RTIOsapiDllExport 
RTIBool RTIOsapiThread_createKey(RTI_UINT32 *key,
                                 RTIOsapiThreadTssFactory * tssFactory);

extern RTIOsapiDllExport RTIBool RTIOsapiThread_setTss(RTI_UINT32 key, 
						       const void *value);

extern RTIOsapiDllExport void *RTIOsapiThread_getTss(RTI_UINT32 key);

extern RTIOsapiDllExport 
RTIBool RTIOsapiThread_deleteKey(RTIOsapiThreadTssFactory * tssFactory,
                                 RTI_UINT32 key);

extern RTIOsapiDllExport RTIBool
RTIOsapiThread_sleep(const struct RTINtpTime* timeIn);

extern RTIOsapiDllExport void
RTIOsapiThread_spin(RTI_UINT64 spinCount);

extern RTIOsapiDllExport int
RTIOsapiThread_getPriority(struct RTIOsapiThread* me);

extern RTIOsapiDllExport void
RTIOsapiThread_logCpuAffinity(const char *threadName);

typedef void *(*RTIOsapiThreadOnSpawnedMethod)(void* threadParam);

extern RTIOsapiDllExport struct RTIOsapiThread*
RTIOsapiThread_new(const char *name, int priority,
                   int options, size_t stackSize, 
                   struct RTIOsapiCpuBitmap *cpuBitmap,
                   RTIOsapiThreadOnSpawnedMethod thread_rtn,
                   void *threadParam);

extern RTIOsapiDllExport void RTIOsapiThread_delete(struct RTIOsapiThread* me);

extern RTIOsapiDllExport void
RTIOsapiThread_terminateThread(struct RTIOsapiThread* me);

extern RTIOsapiDllExport struct RTIOsapiThread*
RTIOsapiThread_getCurrentThread(void);

extern RTIOsapiDllExport RTI_UINT32
RTIOsapiThread_getCurrentThreadID(void);

extern RTIOsapiDllExport RTIBool
RTIOsapiThread_getNativePriorityFromNormal(int *nativePriority,
    int normalPriority, int normalMin, int normalMax, int options);

extern RTIOsapiDllExport RTIBool
RTIOsapiThread_getNormalPriorityFromNative(
    int *normalPriority,
    int nativePriority, int normalMin, int normalMax, int options);


#ifdef __cplusplus
    }	/* extern "C" */
#endif
    
#include "osapi/osapi_thread_impl.h"
    

#endif /* osapi_thread_h */
