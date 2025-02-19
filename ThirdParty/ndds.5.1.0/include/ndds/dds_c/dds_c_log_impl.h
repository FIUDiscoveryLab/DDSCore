/* (c) Copyright, Real-Time Innovations, Inc. 2003-2009. All rights reserved. */
/*
 * @(#)dds_c_log_impl.h    generated by: makeheader    Sat Nov 23 02:39:21 2013
 *
 *		built from:	log_impl.ifc
 */

#ifndef dds_c_log_impl_h
#define dds_c_log_impl_h


  /* For context support (used by macros below) */
  #ifndef advlog_context_h
    #include "advlog/advlog_context.h"
  #endif

  #ifndef dds_c_log_h
    #include "dds_c/dds_c_log.h"
  #endif
  #ifndef dds_c_dll_h
    #include "dds_c/dds_c_dll.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif




/* ================================================================= */
/*                Storage for logging masks                          */
/* ================================================================= */
/*i @ingroup DDSLogModule
  @brief Stores the current setting for the submodule mask.

  Use DDSLog_getBitmaps() to set the submodule mask, and
  DDSLog_setBitmaps() to retrieve the current value.
 */
extern DDSCDllVariable RTILogBitmap DDSLog_g_submoduleMask;


/* ----------------------------------------------------------------- */
/*i @ingroup DDSLogModule
  @brief Stores the current setting for the instrumentation mask

  Use DDSLog_getBitmaps() to set the instrumentation mask, and
  DDSLog_setBitmaps() to retrieve the current value.
 */
extern DDSCDllVariable RTILogBitmap DDSLog_g_instrumentationMask;

/* ================================================================= */
/*                       Logging macros                              */
/* ================================================================= */
/*i @ingroup DDSLogModule 
  @brief See \ref RTI_LOG_BIT_EXCEPTION 
*/
  #define DDSLog_exception \
      if ((RTILog_setLogLevel != NULL) &&                           \
          (DDSLog_g_instrumentationMask & RTI_LOG_BIT_EXCEPTION) &&      \
          (DDSLog_g_submoduleMask & DDS_CURRENT_SUBMODULE)){        \
          RTILog_setLogLevel(RTI_LOG_BIT_EXCEPTION);                \
      }                                                             \
      if ((DDSLog_g_instrumentationMask & RTI_LOG_BIT_EXCEPTION) && \
          (DDSLog_g_submoduleMask & DDS_CURRENT_SUBMODULE)) \
          RTILog_printContextAndMsg

/* ----------------------------------------------------------------- */
/*i @ingroup DDSLogModule 
  @brief See \ref RTI_LOG_BIT_WARN
*/
  #define DDSLog_warn \
      if ((RTILog_setLogLevel != NULL) &&                           \
          (DDSLog_g_instrumentationMask & RTI_LOG_BIT_WARN) &&      \
          (DDSLog_g_submoduleMask & DDS_CURRENT_SUBMODULE)){        \
          RTILog_setLogLevel(RTI_LOG_BIT_WARN);                \
      }                                                             \
      if ((DDSLog_g_instrumentationMask & RTI_LOG_BIT_WARN) && \
          (DDSLog_g_submoduleMask & DDS_CURRENT_SUBMODULE)) \
          RTILog_printContextAndMsg

/* ----------------------------------------------------------------- */
/*i @ingroup DDSLogModule 
  @brief See \ref RTI_LOG_BIT_LOCAL
 */
  #define DDSLog_local \
      if ((RTILog_setLogLevel != NULL) &&                           \
          (DDSLog_g_instrumentationMask & RTI_LOG_BIT_LOCAL) &&      \
          (DDSLog_g_submoduleMask & DDS_CURRENT_SUBMODULE)){        \
          RTILog_setLogLevel(RTI_LOG_BIT_LOCAL);                \
      }                                                             \
      if ((DDSLog_g_instrumentationMask & RTI_LOG_BIT_LOCAL) && \
          (DDSLog_g_submoduleMask & DDS_CURRENT_SUBMODULE)) \
          RTILog_printContextAndMsg

/* ----------------------------------------------------------------- */
/*i @ingroup DDSLogModule 
  @brief See \ref RTI_LOG_BIT_LOCAL
  
   Allows creation of a codeblock just for loggin purposes.
 */
  #define DDSLog_local_codeblock(codeblock) \
      if ((DDSLog_g_instrumentationMask & RTI_LOG_BIT_LOCAL) && \
          (DDSLog_g_submoduleMask & DDS_CURRENT_SUBMODULE)) {\
          codeblock \
      }          
/* ----------------------------------------------------------------- */
/*i @ingroup DDSLogModule 
  @brief See \ref RTI_LOG_BIT_REMOTE
*/
  #define DDSLog_remote \
      if ((RTILog_setLogLevel != NULL) &&                           \
          (DDSLog_g_instrumentationMask & RTI_LOG_BIT_REMOTE) &&      \
          (DDSLog_g_submoduleMask & DDS_CURRENT_SUBMODULE)){        \
          RTILog_setLogLevel(RTI_LOG_BIT_REMOTE);                \
      }                                                           \
      if ((DDSLog_g_instrumentationMask & RTI_LOG_BIT_REMOTE) && \
          (DDSLog_g_submoduleMask & DDS_CURRENT_SUBMODULE)) \
          RTILog_printContextAndMsg

/* ----------------------------------------------------------------- */
/*i @ingroup DDSLogModule 
  @brief See \ref RTI_LOG_BIT_PERIODIC
 */
  #define DDSLog_periodic \
      if ((RTILog_setLogLevel != NULL) &&                           \
          (DDSLog_g_instrumentationMask & RTI_LOG_BIT_PERIODIC) &&      \
          (DDSLog_g_submoduleMask & DDS_CURRENT_SUBMODULE)){        \
          RTILog_setLogLevel(RTI_LOG_BIT_PERIODIC);                \
      }                                                           \
      if ((DDSLog_g_instrumentationMask & RTI_LOG_BIT_PERIODIC) && \
          (DDSLog_g_submoduleMask & DDS_CURRENT_SUBMODULE)) \
          RTILog_printContextAndMsg

/* ----------------------------------------------------------------- */
/*i @ingroup DDSLogModule 
  @brief See \ref RTI_LOG_BIT_CONTENT
 */
  #define DDSLog_content \
      if ((RTILog_setLogLevel != NULL) &&                           \
          (DDSLog_g_instrumentationMask & RTI_LOG_BIT_CONTENT) &&      \
          (DDSLog_g_submoduleMask & DDS_CURRENT_SUBMODULE)){        \
          RTILog_setLogLevel(RTI_LOG_BIT_CONTENT);                \
      }                                                           \
      if ((DDSLog_g_instrumentationMask & RTI_LOG_BIT_CONTENT) && \
          (DDSLog_g_submoduleMask & DDS_CURRENT_SUBMODULE)) \
          RTILog_printContextAndMsg

/* ----------------------------------------------------------------- */
/*i @ingroup DDSLogModule 
  @brief Indicate via log message that the precondition of a function failed
*/
  #define DDSLog_logPreconditionFailed(preconditionExpression) \
     DDSLog_exception(METHOD_NAME,                             \
                      &RTI_LOG_PRECONDITION_FAILURE_s,         \
                      #preconditionExpression);   

/* ----------------------------------------------------------------- */
/*i @ingroup DDSLogModule
  @brief Indicate via log message that an accessor (get method) into
  an object failed
*/
  #define DDSLog_logGetFailed(memberName)                               \
                                                                        \
	DDSLog_exception(METHOD_NAME, &RTI_LOG_GET_FAILURE_s, memberName);

/* ----------------------------------------------------------------- */
/*i @ingroup DDSLogModule
  @brief Generate a free form log message.

  @param instrumentBit A bit map as define by RTILogBitmap

  The message is free form, using the "printf" format, as illustrated
  in the example below.

  @see RTILogBitmap

  \code
	DDSLog_freeForm(RTI_LOG_BIT_EXCEPTION)("%s: error in", METHOD_NAME);
  \endcode
*/
#define DDSLog_freeForm(instrumentBit)                                \
                                                                      \
      if (DDSLog_g_instrumentationMask & (instrumentBit)) RTILog_debug

/* ================================================================= */
/*                       Context macros                              */
/* ================================================================= */
/*i @ingroup DDSLogModule
  @brief See \ref ADVLOGContext 
*/
  #define DDSLog_enterContext \
    { \
      ADVLOGContext_enter

/*i @ingroup DDSLogModule
  @brief See \ref ADVLOGContext 
*/
  #define DDSLog_leaveContext(worker, context) \
      ADVLOGContext_leave((worker), (context)); \
    }

/*i @ingroup DDSLogModule
  @brief See \ref ADVLOGContext 
*/
  #define DDSLog_leaveContextAndReturn(worker, context, eval) \
    { \
        DDS_ReturnCode_t _LOGretcode = (eval); \
        ADVLOGContext_leave((worker), (context)); \
        return _LOGretcode; \
    } \
  }


/*i @ingroup DDSLogModule
  @brief Enter domain + top-level activity context.  Must be matched with
     DDSLog_leaveDomainContext.

  See \ref ADVLOGContext
*/
  #define DDSLog_enterDomainContext(self, worker, context, iparam, pparam) \
    { \
      struct REDAWorker *_DDS_LOG_DC_worker = DDS_DomainParticipant_enterContextI(self, worker); \
      DDSLog_enterContext(_DDS_LOG_DC_worker, context, iparam, pparam)

/*i @ingroup DDSLogModule
  @brief Leave domain + top-level activity context.  Must be matched with
     DDSLog_enterDomainContext.

  See \ref ADVLOGContext
*/
  #define DDSLog_leaveDomainContext(context) \
      DDSLog_leaveContext(_DDS_LOG_DC_worker, context); \
      DDS_DomainParticipant_leaveContextI(_DDS_LOG_DC_worker); \
    }

/*i @ingroup DDSLogModule
  @brief Compute return value inside domain + top-level activity context.

  Equivalent to surrounding with DDSLog_enterDomainContext and
  DDSLog_leaveDomainContext.

  See \ref ADVLOGContext
*/
  #define DDSLog_evaluateInDomainContext(self, worker, context, iparam, pparam, type, eval) \
    { \
      type _DDS_LOG_DC_retcode; \
      struct REDAWorker *_DDS_LOG_DC_worker = DDS_DomainParticipant_enterContextI(self, worker); \
      DDSLog_enterContext(_DDS_LOG_DC_worker, context, iparam, pparam); \
      _DDS_LOG_DC_retcode = (eval); \
      DDSLog_leaveContext(_DDS_LOG_DC_worker, (context)); \
      DDS_DomainParticipant_leaveContextI(_DDS_LOG_DC_worker); \
      return _DDS_LOG_DC_retcode; \
    }


/*i @ingroup DDSLogModule
  @brief Enter domain/entity + top-level activity context.  Must be matched with
     DDSLog_leaveEntityContext.

  See \ref ADVLOGContext
*/
  #define DDSLog_enterEntityContext(self, worker, context, iparam, pparam) \
    { \
      struct REDAWorker *_DDS_LOG_EC_worker = DDS_DomainEntity_enterContextI(self, worker); \
      DDSLog_enterContext(_DDS_LOG_EC_worker, context, iparam, pparam)

/*i @ingroup DDSLogModule
  @brief Leave domain/entity + top-level activity context.  Must be matched with
     DDSLog_enterEntityContext.

  See \ref ADVLOGContext
*/
  #define DDSLog_leaveEntityContext(context) \
      DDSLog_leaveContext(_DDS_LOG_EC_worker, context); \
      DDS_DomainEntity_leaveContextI(_DDS_LOG_EC_worker); \
    }

/*i @ingroup DDSLogModule
  @brief Compute return value inside domain/entity + top-level activity context.

  Equivalent to surrounding with DDSLog_enterEntityContext and
  DDSLog_leaveEntityContext.

  See \ref ADVLOGContext
*/
  #define DDSLog_evaluateInEntityContext(self, worker, context, iparam, pparam, type, eval) \
    { \
      type _DDS_LOG_EC_retcode; \
      struct REDAWorker *_DDS_LOG_EC_worker = DDS_DomainEntity_enterContextI(self, worker); \
      DDSLog_enterContext(_DDS_LOG_EC_worker, context, iparam, pparam); \
      _DDS_LOG_EC_retcode = (eval); \
      DDSLog_leaveContext(_DDS_LOG_EC_worker, (context)); \
      DDS_DomainEntity_leaveContextI(_DDS_LOG_EC_worker); \
      return _DDS_LOG_EC_retcode; \
    }


/*i @ingroup DDSLogModule
  @brief Enter domain/topic + top-level activity context.  Must be matched with
     DDSLog_leaveTopicContext.

  See \ref ADVLOGContext
*/
  #define DDSLog_enterTopicContext(topic, worker, context, iparam, pparam) \
    { \
      struct REDAWorker *_DDS_LOG_TC_worker = DDS_DomainParticipant_enterContextI( \
          DDS_TopicDescription_get_participant(topic), worker); \
      DDS_TopicDescription_enterContextI(topic, _DDS_LOG_TC_worker); \
      DDSLog_enterContext(_DDS_LOG_TC_worker, context, iparam, pparam)

/*i @ingroup DDSLogModule
  @brief Leave domain/topic + top-level activity context.  Must be matched with
     DDSLog_enterTopicContext.

  See \ref ADVLOGContext
*/
  #define DDSLog_leaveTopicContext(context) \
      DDSLog_leaveContext(_DDS_LOG_TC_worker, context); \
      DDS_TopicDescription_leaveContextI(_DDS_LOG_TC_worker); \
      DDS_DomainParticipant_leaveContextI(_DDS_LOG_TC_worker); \
    }

/*i @ingroup DDSLogModule
  @brief Compute return value inside domain/topic + top-level activity context.

  Equivalent to surrounding with DDSLog_enterTopicContext and
  DDSLog_leaveTopicContext.

  See \ref ADVLOGContext
*/
  #define DDSLog_evaluateInTopicContext(topic, worker, context, iparam, pparam, type, eval) \
    { \
      type _DDS_LOG_TC_retcode; \
      struct REDAWorker *_DDS_LOG_TC_worker = DDS_DomainParticipant_enterContextI( \
          DDS_TopicDescription_get_participant(topic), worker); \
      DDS_TopicDescription_enterContextI(topic, _DDS_LOG_TC_worker); \
      DDSLog_enterContext(_DDS_LOG_TC_worker, context, iparam, pparam); \
      _DDS_LOG_TC_retcode = (eval); \
      DDSLog_leaveContext(_DDS_LOG_TC_worker, (context)); \
      DDS_TopicDescription_leaveContextI(_DDS_LOG_TC_worker); \
      DDS_DomainParticipant_leaveContextI(_DDS_LOG_TC_worker); \
      return _DDS_LOG_TC_retcode; \
    }


/*i @ingroup DDSLogModule
  @brief Enter domain/entity/topic + top-level activity context.  Must be matched with
     DDSLog_leaveEntityTopicContext.

  See \ref ADVLOGContext
*/
  #define DDSLog_enterEntityTopicContext(self, topic, worker, context, iparam, pparam) \
    { \
      struct REDAWorker *_DDS_LOG_ETC_worker = DDS_DomainEntity_enterContextI(self, worker); \
      DDS_TopicDescription_enterContextI(topic, _DDS_LOG_ETC_worker); \
      DDSLog_enterContext(_DDS_LOG_ETC_worker, context, iparam, pparam)

/*i @ingroup DDSLogModule
  @brief Leave domain/entity/topic + top-level activity context.  Must be matched with
     DDSLog_enterEntityTopicContext.

  See \ref ADVLOGContext
*/
  #define DDSLog_leaveEntityTopicContext(context) \
      DDSLog_leaveContext(_DDS_LOG_ETC_worker, context); \
      DDS_TopicDescription_leaveContextI(_DDS_LOG_ETC_worker); \
      DDS_DomainEntity_leaveContextI(_DDS_LOG_ETC_worker); \
    }

/*i @ingroup DDSLogModule
  @brief Compute return value inside domain/entity/topic + top-level activity context.

  Equivalent to surrounding with DDSLog_enterTopicContext and
  DDSLog_leaveTopicContext.

  See \ref ADVLOGContext
*/
  #define DDSLog_evaluateInEntityTopicContext(self, topic, worker, context, iparam, pparam, type, eval) \
    { \
      type _DDS_LOG_ETC_retcode; \
      struct REDAWorker *_DDS_LOG_ETC_worker = DDS_DomainEntity_enterContextI(self, worker); \
      DDS_TopicDescription_enterContextI(topic, _DDS_LOG_ETC_worker); \
      DDSLog_enterContext(_DDS_LOG_ETC_worker, context, iparam, pparam); \
      _DDS_LOG_ETC_retcode = (eval); \
      DDSLog_leaveContext(_DDS_LOG_ETC_worker, (context)); \
      DDS_TopicDescription_leaveContextI(_DDS_LOG_ETC_worker); \
      DDS_DomainEntity_leaveContextI(_DDS_LOG_ETC_worker); \
      return _DDS_LOG_ETC_retcode; \
    }


/* ================================================================= */
/*            When RTI_PRECONDITION_TEST is #defined                 */
/* ================================================================= */
/*i @def DDSLog_preconditionOnly
  @ingroup DDSLogModule 

  @brief  Conditionally expands to the expression below, or nothing
  depending on whether RTI_PRECONDITION_TEST is defined

  \hideinitializer

  @param declaration the code to be injected if RTI_PRECONDITION_TEST 
  is defined
*/
#ifdef RTI_PRECONDITION_TEST 
  #define  DDSLog_preconditionOnly( declaration )  declaration
#else /* nothing */
  #define DDSLog_preconditionOnly( declaration ) 
#endif /* RTI_PRECONDITION_TEST */

/* ----------------------------------------------------------------- */

/*i @def DDSLog_testPreconditionAlways
 *  @ingroup DDSLogModule 
 *  @brief Expands to the expression below.
 *
 * \hideinitializer
 *
 * @param preconditionExpression The expression to check
 * @param failAction The action to take if the expression evaluates to true
 */
#define DDSLog_testPreconditionAlways(preconditionExpression, failAction) \
  if (preconditionExpression) {                           \
    DDSLog_logPreconditionFailed(preconditionExpression); \
    failAction;                                           \
  }

/*i @def DDSLog_testPrecondition
  @ingroup DDSLogModule 
  @brief Conditionally expands to the expression below, or nothing depending
  on whether RTI_PRECONDITION_TEST is defined 
  
  \hideinitializer

  @param preconditionExpression the expression to check
  @param failAction the action to take if the expression evaluates to true
*/
#ifdef RTI_PRECONDITION_TEST 
  #define DDSLog_testPrecondition(preconditionExpression, failAction) \
    if (preconditionExpression) {                          \
	DDSLog_logPreconditionFailed(preconditionExpression);  \
	failAction;                                        \
    }
#else /* do nothing */
  #define  DDSLog_testPrecondition(preconditionExpression, failAction)   
#endif /* RTI_PRECONDITION_TEST */


extern DDSCDllVariable const struct RTILogMessage
DDS_LOG_BAD_PARAMETER_s;

extern DDSCDllVariable const struct RTILogMessage
DDS_LOG_IMMUTABLE_POLICY_s;

extern DDSCDllVariable const struct RTILogMessage
DDS_LOG_OUT_OF_RESOURCES_s;

extern DDSCDllVariable const struct RTILogMessage
DDS_LOG_MEMORY_ALLOCATED_dd;

extern DDSCDllVariable const struct RTILogMessage
DDS_LOG_SEQUENCE_UNINITIALIZED;

extern DDSCDllVariable const struct RTILogMessage
DDS_LOG_SEQUENCE_NOT_OWNER;

extern DDSCDllVariable const struct RTILogMessage
DDS_LOG_AUTO_ENABLE_FAILURE;

extern DDSCDllVariable const struct RTILogMessage
DDS_LOG_GET_FAILURE_s;

extern DDSCDllVariable const struct RTILogMessage
DDS_LOG_CREATE_FAILURE_s;

extern DDSCDllVariable const struct RTILogMessage
DDS_LOG_INITIALIZE_FAILURE_s;

extern DDSCDllVariable const struct RTILogMessage
DDS_LOG_SET_FAILURE_s;

extern DDSCDllVariable const struct RTILogMessage
DDS_LOG_COMPARE_UNEQUAL_s;

extern DDSCDllVariable const struct RTILogMessage
DDS_LOG_STARTED_NDDS_VERSION_s;

extern DDSCDllVariable const struct RTILogMessage
DDS_LOG_NOT_ENABLED;


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* dds_c_log_impl_h */
