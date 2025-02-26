/* (c) Copyright, Real-Time Innovations, Inc. 2003-2009. All rights reserved. */
/*
 * @(#)log_common.h    generated by: makeheader    Sat Nov 23 02:37:42 2013
 *
 *		built from:	common.ifc
 */

#ifndef log_common_h
#define log_common_h



#ifndef log_makeheader_h
  #include "log/log_makeheader.h"
#endif
#ifndef log_dll_h
  #include "log/log_dll.h"
#endif

#ifdef __cplusplus
    extern "C" {
#endif


typedef unsigned int RTILogBitmap;


/*e \ingroup RTILogBitmapClass
  \brief Log nothing, remain completely silent; 
  		 good for production code running in the field.
*/
#define RTI_LOG_BIT_SILENCE       (0x00000000)

/*e \ingroup RTILogBitmapClass
  \brief Log all exceptions; these should be fixed completely before shipping!
*/
#define RTI_LOG_BIT_EXCEPTION     (0x00000001)

/*e \ingroup RTILogBitmapClass
  \brief Log all warnings; should check the source before shipping.
*/
#define RTI_LOG_BIT_WARN          (0x00000002)

/*e \ingroup RTILogBitmapClass
  \brief Log what is happening due to local object creation and destruction.
*/
#define RTI_LOG_BIT_LOCAL         (0x00000004)

/*e \ingroup RTILogBitmapClass
  \brief Log what is happening due to what other applications 
  (not necessarily on another host, but in different address space) 
  are creating and destroying.
*/
#define RTI_LOG_BIT_REMOTE        (0x00000008)

/*e \ingroup RTILogBitmapClass
  \brief Log periodic activities.  
  Different than \ref RTI_LOG_BIT_LOCAL or \ref RTI_LOG_BIT_REMOTE 
  in that this is NOT related to creation or destruction. 
  
  This bit is used for periodic activities, such as sending a packet.
  Disabling this type of log message can significantly reduce logging
  output.
*/
#define RTI_LOG_BIT_PERIODIC      (0x00000010)

/*e \ingroup RTILogBitmapClass
  \brief For logging activity context enter/exit information.
*/
#define RTI_LOG_BIT_ACTIVITY      (0x00000020)

/*e \ingroup RTILogBitmapClass
  \brief Dump data content, to see what is being sent or received.
*/
#define RTI_LOG_BIT_CONTENT       (0x00000040)

/*e \ingroup RTILogBitmapClass
  \brief For logging those things that do not really belong in any of 
  the other logging categories.
*/
#define RTI_LOG_BIT_OTHER         (0x00000080)

/*e \ingroup RTILogBitmapClass
  \brief Worker specific data.
*/
#define RTI_LOG_BIT_WORKER_STAT   (0x00000100)

/*e \ingroup RTILogBitmapClass
  \brief This will be the log level stored in the thread specific structrue
         for the log message if the Log macro had not specified the log level.
         This is set to 0x04000000 as this has to be mapped to verbosity in
         Java and Java expects signed integer. So we cannot use the msb.
*/
#define RTI_LOG_BIT_UNINITIALIZED   (0x04000000)

/*e \ingroup RTILogBitmapClass 
	\brief Default bitmap.
	
	When using this default bitmap, only exceptions will be logged.
*/
#define RTI_LOG_BITMAP_DEFAULT RTI_LOG_BIT_EXCEPTION

/*e \ingroup RTILogBitmapClass
  \brief Enables setting the logging verbosity using a single number.
  
  @note This macro assumes the log message bitmaps are such that 
  a more significant bit corresponds to a more verbose message.
  That is, nothing will be enabled for verbosity = -1,
  \ref RTI_LOG_BIT_EXCEPTION will be enabled for verbosity = 0,
  whereas enabling \ref RTI_LOG_BIT_WARN requires at least verbosity = 1.
  A given verbosity value automatically enables all log messages 
  corresponding to lower verbosity values.
*/
#define RTILogBitmap_setFromVerbosity(verbosity) \
  (((verbosity) < 0)? 0 : (~(~0 << ((verbosity) + 1))))

/****************************************************************************/
/*e \defgroup RTILogNumberBitmapClass RTILogNumberBitmap
  \ingroup RTILogModule
  \brief Each specific log message can also be represented by a unique 
  matching log message number. This page defines how to compose and 
  interpret log message numbers.
  
  For each standard log message, NDDS defines a corresponding
  log message number. This makes it possible to reduce the
  footprint of the NDDS libraries by not linking the error
  message strings. Instead, all log messages are represented by numbers. 
  To report problems, production code in the field can make use of log 
  message numbers only, while development code can use the 
  actual log message.
  
  A log message number contains a variety of information, such as 
  what product generated the message (e.g. NDDS), what module
  (e.g. netio, commend), submodule and so on. This information is encoded
  in separate parts of the 32 bit log message number, as described on
  this page.
  
  When building an NDDS module, link with \c Log_silent.msg.c instead of
  \c Log_normal.msg.c to use log numbers instead of log messages and
  thereby reduce the footprint of that module.
  
  Example (from \c Log_normal.msg.c in Netio):
  
  \code
  const struct RTILogMessage RTI_NETIO_LOG_BLOCK_s = {
    PRODUCT_WAVEWORKS|MODULE_NETIO|0, 
    "%s blocking\n"
	};
  \endcode
  
  uniquely identifies the Netio blocking log message by the bitmap
  
  \code
  PRODUCT_WAVEWORKS|MODULE_NETIO|0
  \endcode
  
  which corresponds to 0x02070000 (message 0 in module Netio of the Waveworks
  product). See also \ref PRODUCT_WAVEWORKS and \ref MODULE_NETIO.
  
  The counterpart in \c Log_silent.msg.c of the code snippet above is
  
  \code
  const struct RTILogMessage RTI_NETIO_LOG_BLOCK_s = {
    PRODUCT_WAVEWORKS|MODULE_NETIO|0, 
    NULL
	};
  \endcode
  
  which indeed does not contain the string and only the log message number. 
  
  @see RTILogMessageClass
  
*/
/****************************************************************************/

/*e \ingroup RTILogNumberBitmapClass
  \brief Product portion of log message number => up to 256 products allowed.
  
  @see PRODUCT_WAVEWORKS 
*/
#define RTI_LOG_PRODUCT_MASK   (0xff000000)

/*e \ingroup RTILogNumberBitmapClass
  \brief Module portion of log message number => up to 256 modules 
  per product allowed.
*/
#define RTI_LOG_MODULE_MASK    (0x00ff0000)

/*e \ingroup RTILogNumberBitmapClass
  \brief Submodule portion of log message number => up to 64 submodules 
  per module allowed.
*/
#define RTI_LOG_SUBMODULE_MASK (0x0000fc00)

/*e \ingroup RTILogNumberBitmapClass
  \brief Message specific to a submodule => up to 1024 messages 
  per submodule allowed.
*/
#define RTI_LOG_ERROR_MASK     (0x000003ff)

/*e \ingroup RTILogNumberBitmapClass 
  \brief Macro to extract the product ID from the log message number.
	
	@see RTI_LOG_PRODUCT_MASK
*/
#define RTI_LOG_getProductId(mask) (((mask)&RTI_LOG_PRODUCT_MASK) >> 24)

/*e \ingroup RTILogNumberBitmapClass 
   \brief Macro to extract the module ID from the log message number.
	
	@see RTI_LOG_MODULE_MASK
*/
#define RTI_LOG_getModuleId(mask) (((mask)&RTI_LOG_MODULE_MASK) >> 16)

/*e \ingroup RTILogNumberBitmapClass 
	\brief Macro to extract the submodule ID from the log message number.
	
	@see RTI_LOG_SUBMODULE_MASK
*/
#define RTI_LOG_getSubmoduleId(mask) (((mask)&RTI_LOG_SUBMODULE_MASK) >> 10)

/*e \ingroup RTILogNumberBitmapClass 
	\brief Macro to extract the error ID from the log message number.
	
	@see RTI_LOG_ERROR_MASK
*/
#define RTI_LOG_getErrorId(mask) ((mask)&RTI_LOG_ERROR_MASK)

#define RTI_LOG_FORMAT_X_LENGTH (11)
#define RTI_LOG_FORMAT_XX_LENGTH (22)

/*e \ingroup RTILogNumberBitmapClass
  \brief The most significant byte of a 
  log message number defines the product that generated the log message. 
  Use this bitmask to specify Waveworks.
  
  @see RTI_LOG_PRODUCT_MASK
*/
#define PRODUCT_WAVEWORKS (0x02000000)

/*e \ingroup RTILogNumberBitmapClass 
	\brief Bitmap to specify LOG module in log message number.
	
	@see RTI_LOG_MODULE_MASK
*/
#define MODULE_LOG          (0x000000)

/*e \ingroup RTILogNumberBitmapClass 
	\brief Bitmap to specify TEST module in log message number.
	
	@see RTI_LOG_MODULE_MASK
 */
#define MODULE_TEST         (0x010000)

/*e \ingroup RTILogNumberBitmapClass 
	\brief Bitmap to specify OSAPI module in log message number.
	
	@see RTI_LOG_MODULE_MASK
 */
#define MODULE_OSAPI        (0x020000)

/*e \ingroup RTILogNumberBitmapClass 
	\brief Bitmap to specify CLOCK module in log message number.
	
	@see RTI_LOG_MODULE_MASK
 */
#define MODULE_CLOCK        (0x030000)

/*e \ingroup RTILogNumberBitmapClass 
	\brief Bitmap to specify REDA module in log message number.
	
	@see RTI_LOG_MODULE_MASK
 */
#define MODULE_REDA         (0x040000)

/*e \ingroup RTILogNumberBitmapClass 
 \brief Bitmap to specify ADVLOG module in log message number.
       
 @see RTI_LOG_MODULE_MASK
 */
#define MODULE_ADVLOG       (0x050000)

/*e \ingroup RTILogNumberBitmapClass 
	\brief Bitmap to specify EVENT module in log message number.
	
	@see RTI_LOG_MODULE_MASK
 */
#define MODULE_EVENT        (0x060000)

/*e \ingroup RTILogNumberBitmapClass 
	\brief Bitmap to specify CDR module in log message number.
	
	@see RTI_LOG_MODULE_MASK
 */
#define MODULE_CDR          (0x070000)

/*e \ingroup RTILogNumberBitmapClass 
	\brief Bitmap to specify TRANSPORT module in log message number.
	
	@see RTI_LOG_MODULE_MASK
 */
#define MODULE_TRANSPORT    (0x080000)

/*e \ingroup RTILogNumberBitmapClass 
	\brief Bitmap to specify NETIO module in log message number.
	
	@see RTI_LOG_MODULE_MASK
 */
#define MODULE_NETIO        (0x090000)

/*e \ingroup RTILogNumberBitmapClass 
	\brief Bitmap to specify MIG module in log message number.
	
	@see RTI_LOG_MODULE_MASK
 */
#define MODULE_MIG          (0x0A0000)

/*e \ingroup RTILogNumberBitmapClass 
	\brief Bitmap to specify COMMEND module in log message number.
	
	@see RTI_LOG_MODULE_MASK
 */
#define MODULE_COMMEND      (0x0B0000)

/*e \ingroup RTILogNumberBitmapClass 
	\brief Bitmap to specify DISC module in log message number.
	
	@see RTI_LOG_MODULE_MASK
 */
#define MODULE_DISC         (0x0C0000)

/*e \ingroup RTILogNumberBitmapClass 
	\brief Bitmap to specify PRES module in log message number.
	
	@see RTI_LOG_MODULE_MASK
 */
#define MODULE_PRES         (0x0D0000)

/*e \ingroup RTILogNumberBitmapClass 
        \brief Bitmap to specify CPPLIB module in log message number.
        
        @see RTI_LOG_MODULE_MASK
 */
#define MODULE_CPPLIB       (0x0E0000)

/*e \ingroup RTILogNumberBitmapClass 
	\brief Bitmap to specify DDS moduleS in log message number.
	
	@see RTI_LOG_MODULE_MASK
 */
#define MODULE_DDS          (0x0F0000)

/*e \ingroup RTILogNumberBitmapClass 
	\brief Bitmap to specify TESTSUITE module in log message number.
	
	@see RTI_LOG_MODULE_MASK
 */
#define MODULE_TESTSUITE    (0x100000)

/*e \ingroup RTILogNumberBitmapClass 
	\brief Bitmap to specify STARFABRIC module in log message number.
	
	@see RTI_LOG_MODULE_MASK
 */
#define MODULE_TRANSPORT_STARFABRIC  (0x110000)

/*e \ingroup RTILogNumberBitmapClass 
	\brief Bitmap to specify RTISHELL module in log message number.
	
	@see RTI_LOG_MODULE_MASK
 */
#define MODULE_RSHELL       (0x120000)

/*e \ingroup RTILogNumberBitmapClass 
	\brief Bitmap to specify DISCSTATIC module in log message number.
	
	@see RTI_LOG_MODULE_MASK
 */
#define MODULE_DISCSTATIC       (0x130000)

/*e \ingroup RTILogNumberBitmapClass 
 \brief Bitmap to specify DISCOVERY_PARTICIPANT_ADOPTER module in log message number.
       
 @see RTI_LOG_MODULE_MASK
 */
#define MODULE_DISCOVERY_PARTICIPANT_ADOPTER       (0x140000)

/*e \ingroup RTILogNumberBitmapClass 
	\brief Bitmap to specify DL_DRIVER module in log message number.
	
	@see RTI_LOG_MODULE_MASK
*/
#define MODULE_DLDRIVER  (0x150000)

/*e \ingroup RTILogNumberBitmapClass 
	\brief Bitmap to specify WRITERHISTORY module in log message number.
	
	@see RTI_LOG_MODULE_MASK
*/
#define MODULE_WRITERHISTORY  (0x160000)

/*e \ingroup RTILogNumberBitmapClass 
	\brief Bitmap to specify PERSISTENCE module in log message number.
	
	@see RTI_LOG_MODULE_MASK
*/
#define MODULE_PERSISTENCE  (0x170000)

/*e \ingroup RTILogNumberBitmapClass 
	\brief Bitmap to specify TRANSPORT_WAN module in log message number.
	
	@see RTI_LOG_MODULE_MASK
 */
#define MODULE_TRANSPORT_WAN  (0x180000)

/*e \ingroup RTILogNumberBitmapClass 
	\brief Bitmap to specify TRANSPORT_TLS module in log message number.
	
	@see RTI_LOG_MODULE_MASK
 */
#define MODULE_TRANSPORT_TLS  (0x190000)

/*e \ingroup RTILogNumberBitmapClass 
        \brief Bitmap to specify JMS modules in log message number.
        
        @see RTI_LOG_MODULE_MASK
 */
#define MODULE_JMS            (0x1A0000)

/*e \ingroup RTILogNumberBitmapClass 
        \brief Bitmap to specify RTIXML module in log message number.
        
        @see RTI_LOG_MODULE_MASK
 */
#define MODULE_RTIXML         (0x1B0000)

/*e \ingroup RTILogNumberBitmapClass 
	\brief Bitmap to specify ROUTER module in log message number.
	
	@see RTI_LOG_MODULE_MASK
*/
#define MODULE_ROUTER  (0x1C0000)

/*e \ingroup RTILogNumberBitmapClass 
	\brief Bitmap to specify METP module in log message number.
	
	@see RTI_LOG_MODULE_MASK
*/
#define MODULE_METP  (0x1d0000)

/*e \ingroup RTILogNumberBitmapClass 
	\brief Bitmap to specify TRANSPORT_TCP module in log message number.
	
	@see RTI_LOG_MODULE_MASK
 */
#define MODULE_TRANSPORT_TCP  (0x1e0000)


/*e \ingroup RTILogNumberBitmapClass 
      \brief Bitmap to specify TRANSPORT_PCIE module in log message number.
      
      @see RTI_LOG_MODULE_MASK
*/
#define MODULE_TRANSPORT_PCIE (0x1F0000)

/*e \ingroup RTILogNumberBitmapClass
      \brief Bitmap to specify RECORDING_SERVICE module in log message number.

      @see RTI_LOG_MODULE_MASK
*/
#define MODULE_RECORDING_SERVICE (0x210000)

/*e \ingroup RTILogNumberBitmapClass
      \brief Bitmap to specify LAUNCHER module in log message number.

      @see RTI_LOG_MODULE_MASK
*/
#define MODULE_LAUNCHER (0x220000)

/*e \ingroup RTILogNumberBitmapClass
      \brief Bitmap to specify VALIDATION module in log message number.

      @see RTI_LOG_MODULE_MASK
*/
#define MODULE_VALIDATION (0x230000)

/*e \ingroup RTILogNumberBitmapClass
      \brief Bitmap to specify TRANSPORT_ITP module in log message number.

      @see RTI_LOG_MODULE_MASK
*/
#define MODULE_TRANSPORT_ITP (0x240000)

/*e \ingroup RTILogNumberBitmapClass
      \brief Bitmap to specify CONNECTOR module in log message number.

      @see RTI_LOG_MODULE_MASK
*/
#define MODULE_CONNECTOR (0x250000)

/*e \ingroup RTILogNumberBitmapClass
      \brief Bitmap to specify XMQ module in log message number.

      @see RTI_LOG_MODULE_MASK
*/
#define MODULE_XMQ (0x260000)

/*e \ingroup RTILogNumberBitmapClass
      \brief Bitmap to specify LUA_BINDING module in log message number.

      @see RTI_LOG_MODULE_MASK
*/
#define MODULE_LUABINDING (0x270000)
/*=================================================================== */
/*e \ingroup RTILogNumberBitmapClass 
  \brief Macro to for a number that is specific to the module and submodule.
  Useful for creating an error code that won't collide with error code
  from another module/submodule
*/
#define RTI_LOG_formSubmoduleSpecificNumber(module, submodule, num) \
    (PRODUCT_WAVEWORKS | (module) | (submodule) | (num))

#define RTI_LOG_FAIL_REASON_PRECONDITION \
    RTI_LOG_formSubmoduleSpecificNumber(MODULE_LOG, 0, 0xFF)

extern RTILogDllVariable const char *RTI_LOG_FORMAT_X;

extern RTILogDllVariable const char *RTI_LOG_FORMAT_XX;

struct RTILogMessage {
    /* specifies a number for the log message */
    unsigned int logNumber;
    /* specifies the format of the log message */
    const char *format;
};


#  define RTI_LOG_MSG_SIZE_MAX 1024
#  define RTI_LOG_CONTEXT_LENGTH_MAX 256
     /* will be truncated if too long: */
#    define RTI_LOG_CONTEXT_FILENAME_LENGTH_MAX 120
#    define RTI_LOG_CONTEXT_METHOD_LENGTH_MAX    80

typedef int (*RTILogOnMessageMethod)(const char *msg);

extern RTILogDllVariable RTILogOnMessageMethod RTILog_onMessage;

typedef int (*RTILogSetLogLevelMethod)(RTILogBitmap level);

extern RTILogDllVariable RTILogSetLogLevelMethod RTILog_setLogLevel;


/* \ingroup RTILogPrintBitmapClass
   @brief Print the log number; good for minimal logging
*/
#define RTI_LOG_PRINT_BIT_NUMBER    0x1
/* \ingroup RTILogPrintBitmapClass
   @brief Print the log message (enabled by default)
*/
#define RTI_LOG_PRINT_BIT_MSG       0x2

/* -- Location context bits */
/* \ingroup RTILogPrintBitmapClass
   @brief Print the calling module (can augment the msg number)
*/
#define RTI_LOG_PRINT_BIT_AT_MODULE	0x04
/* \ingroup RTILogPrintBitmapClass
   @brief Print filename location
*/
#define RTI_LOG_PRINT_BIT_AT_FILE	0x08
/* \ingroup RTILogPrintBitmapClass
   @brief Print method location context
*/
#define RTI_LOG_PRINT_BIT_AT_METHOD     0x10
/* \ingroup RTILogPrintBitmapClass
   @brief Print line number location
*/
#define RTI_LOG_PRINT_BIT_AT_LINE	0x20

/* \ingroup RTILogPrintBitmapClass
   @brief Collection of location bits
*/
#define RTI_LOG_PRINT_LOCATION_MASK \
	(RTI_LOG_PRINT_BIT_AT_MODULE | RTI_LOG_PRINT_BIT_AT_FILE | \
	 RTI_LOG_PRINT_BIT_AT_METHOD | RTI_LOG_PRINT_BIT_AT_LINE)

extern RTILogDllVariable unsigned int RTILog_printMask;

extern RTILogDllExport int RTILog_debug(const char *errMsg, ...);

extern RTILogDllExport int RTILog_print(const struct RTILogMessage *errMsg, ...);

extern RTILogDllExport
int RTILog_printContextAndMsg(const char *context,
			      const struct RTILogMessage *errMsg, ...);

extern RTILogDllExport			      
int RTILog_printContextAndFatalMsg(
        const char *context,
        const struct RTILogMessage *errMsg, ...);
        
/*i \ingroup RTILogModule
  @brief Parameterized log output mechanism with detailed location context

  Composes a context string based on four fields, which is then passed
  to RTILog_printContextAndMsg.  Output is controlled by the print bits:
  - RTI_LOG_PRINT_BIT_AT_MODULE: module location
  - RTI_LOG_PRINT_BIT_AT_FILE:   file location
  - RTI_LOG_PRINT_BIT_AT_METHOD: method location
  - RTI_LOG_PRINT_BIT_AT_LINE:   line number
*/
extern RTILogDllExport
int RTILog_printLocationContextAndMsg(unsigned int module, const char *filename,
                                const char *method, unsigned int lineno,
			        const struct RTILogMessage *errMsg, ...);


#define RTI_LOG_AT(module, method)	module, __FILE__, method, __LINE__

extern RTILogDllExport void RTILog_flush();

extern RTILogDllExport void
RTILog_registerOnMessageMethod(RTILogOnMessageMethod onMsgMethod);

extern RTILogDllExport void
RTILog_registerSetLogLevelMethod(RTILogSetLogLevelMethod setLogLevelMethod);

extern RTILogDllExport void
RTILog_registerOnDebugMessageMethod(RTILogOnMessageMethod onMsgMethod);

extern RTILogDllExport
RTILogOnMessageMethod RTILog_getDefaultOnMessageMethod();

extern RTILogDllExport int RTILog_onAssert();

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_NULL_OBJECT;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_ADD_FAILURE_s;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_ALREADY_CREATED_s;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_ALREADY_DESTROYED_s;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_ALREADY_INITIALIZED_s;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_ANY_s;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_ANY_ss;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_ANY_FAILURE_s;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_ANY_FAILURE_ss;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_ASSERT_FAILURE_s;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_CREATE_s;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_CREATION_FAILURE_s;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_ENABLE_FAILURE_s;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_DELETE_s;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_DELETE_REQUESTED_s;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_DESTRUCTION_FAILURE_s;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_FINALIZE_s;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_GET_FAILURE_s;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_GET_FAILURE_ss;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_INIT_FAILURE_s;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_INSUFFICIENT_SPACE_FAILURE_dd;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_INVALID_s;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_UNEXPECTED_PROPERTY_ssss;

extern RTILogDllVariable
const struct RTILogMessage RTI_LOG_INVARIANCE_VIOLATION;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_MALLOC_FAILURE_d;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_GETRLIMIT_FAILURE;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_EXCEED_HEAP_FAILURE_lulu;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_MUTEX_GIVE_FAILURE;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_MUTEX_TAKE_FAILURE;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_OS_FAILURE_sXs;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_PRECONDITION_FAILURE;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_PRECONDITION_FAILURE_s;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_REFERENCE_COUNT_sd;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_REMOVE_FAILURE_s;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_SEMAPHORE_GIVE_FAILURE;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_SEMAPHORE_TAKE_FAILURE;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_SINGLETON_VIOLATION_s;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_SKIP_s;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_SLEEP_FAILURE_s;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_STOP_s;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_FATAL_EXCEPTION;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_UNEXPECTED_EXCEPTION;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_SYSTEM_FAILURE_d;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_TIMESTAMP_xX;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_BAD_STRING_FORMAT_ss;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_CONTEXT_ENTER_s;

extern RTILogDllVariable const struct RTILogMessage RTI_LOG_CONTEXT_LEAVE_s;


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* log_common_h */
