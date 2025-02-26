/* (c) Copyright, Real-Time Innovations, Inc. 2003-2009. All rights reserved. */
/*
 * @(#)reda_log.h    generated by: makeheader    Sat Nov 23 02:38:01 2013
 *
 *		built from:	log.ifc
 */

#ifndef reda_log_h
#define reda_log_h


  #ifndef reda_dll_h
    #include "reda/reda_dll.h"
  #endif
  #ifndef log_common_h
    #include "log/log_common.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif


  #define SUBMODULE_REDA_BUFFER                 (0x0000)
  #define SUBMODULE_REDA_FAST_BUFFER            (0x1000)
  #define SUBMODULE_REDA_EPOCH                  (0x2000)
  #define SUBMODULE_REDA_SEQUENCE_NUMBER        (0x3000)
  #define SUBMODULE_REDA_INLINE_LIST            (0x4000)
  #define SUBMODULE_REDA_CONCURRENT_QUEUE       (0x5000)
  #define SUBMODULE_REDA_HASH                   (0x6000)
  #define SUBMODULE_REDA_ORDERED_DATA_TYPE      (0x7000)
  #define SUBMODULE_REDA_WORKER                 (0x8000)
  #define SUBMODULE_REDA_SKIPLIST               (0x9000)
  #define SUBMODULE_REDA_HASHED_SKIPLIST        (0xA000)
  #define SUBMODULE_REDA_TABLE                  (0xB000)
  #define SUBMODULE_REDA_DATABASE               (0xC000)
  #define SUBMODULE_REDA_STRING                 (0xD000)
  #define SUBMODULE_REDA_DBSHELL                (0xE000)


  #define REDA_SUBMODULE_MASK_BUFFER            (0x0001)


  #define REDA_SUBMODULE_MASK_FAST_BUFFER       (0x0002)


  #define REDA_SUBMODULE_MASK_EPOCH             (0x0004)


  #define REDA_SUBMODULE_MASK_SEQUENCE_NUMBER   (0x0008)


  #define REDA_SUBMODULE_MASK_INLINE_LIST       (0x0010)


  #define REDA_SUBMODULE_MASK_CONCURRENT_QUEUE  (0x0020)


  #define REDA_SUBMODULE_MASK_HASH              (0x0040)


  #define REDA_SUBMODULE_MASK_ORDERED_DATA_TYPE (0x0080)


  #define REDA_SUBMODULE_MASK_WORKER            (0x0100)


  #define REDA_SUBMODULE_MASK_SKIPLIST          (0x0200)


  #define REDA_SUBMODULE_MASK_HASHED_SKIPLIST   (0x0400)


  #define REDA_SUBMODULE_MASK_TABLE             (0x0800)


  #define REDA_SUBMODULE_MASK_DATABASE          (0x1000)


  #define REDA_SUBMODULE_MASK_STRING            (0x2000)


  #define REDA_SUBMODULE_MASK_DBSHELL           (0x4000)


  #define REDA_SUBMODULE_MASK_ALL               (0xFFFF)

extern REDADllExport
void REDALog_setVerbosity(RTILogBitmap submoduleMask, int verbosity);

extern REDADllExport void
REDALog_setBitmaps(RTILogBitmap submoduleMask,
		   RTILogBitmap instrumentationMask);

extern REDADllExport void
REDALog_getBitmaps(RTILogBitmap *submoduleMask,
		   RTILogBitmap *instrumentationMask);

extern REDADllVariable const struct RTILogMessage
REDA_LOG_CONCURRENT_QUEUE_START_WRITE_FAILURE;

extern REDADllVariable const struct RTILogMessage
REDA_LOG_WORKER_EXCLUSIVE_AREA_FAILURE_s;

extern REDADllVariable const struct RTILogMessage
REDA_LOG_WORKER_GET_OBJECT_FAILURE;

extern REDADllVariable const struct RTILogMessage
REDA_LOG_WORKER_CREATE_OBJECT_FAILURE;

extern REDADllVariable const struct RTILogMessage REDA_LOG_CURSOR_COPY_FAILURE_s;

extern REDADllVariable const struct RTILogMessage REDA_LOG_CURSOR_CREATE_WR_FAILURE_s;

extern REDADllVariable const struct RTILogMessage REDA_LOG_CURSOR_GOTO_KEY_FAILURE_s;

extern REDADllVariable const struct RTILogMessage REDA_LOG_CURSOR_GOTO_WR_FAILURE_s;

extern REDADllVariable const struct RTILogMessage
REDA_LOG_CURSOR_LOCK_TABLE_FAILURE_s;

extern REDADllVariable const struct RTILogMessage REDA_LOG_CURSOR_MODIFY_FAILURE_s;

extern REDADllVariable const struct RTILogMessage
REDA_LOG_CURSOR_REMOVE_RECORD_FAILURE_s;

extern REDADllVariable const struct RTILogMessage
REDA_LOG_CURSOR_REMOVE_TABLE_FAILURE_s;

extern REDADllVariable const struct RTILogMessage REDA_LOG_CURSOR_START_FAILURE_s;

extern REDADllVariable const struct RTILogMessage REDA_LOG_CURSOR_GET_KEY_FAILURE_s;

extern REDADllVariable const struct RTILogMessage
REDA_LOG_CURSOR_GET_READ_ONLY_AREA_FAILURE_s;

extern REDADllVariable const struct RTILogMessage REDA_LOG_CURSOR_GET_WR_FAILURE_s;

extern REDADllVariable const struct RTILogMessage REDA_LOG_CURSOR_UNFREEZE_FAILURE_s;

extern REDADllVariable const struct RTILogMessage
REDA_LOG_DATABASE_CREATE_TABLE_FAILURE_s;


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* reda_log_h */
