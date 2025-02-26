/* (c) Copyright, Real-Time Innovations, Inc. 2003-2009. All rights reserved. */
/*
 * @(#)disc_builtin.h    generated by: makeheader    Sat Nov 23 02:39:02 2013
 *
 *		built from:	builtin.ifc
 */

#ifndef disc_builtin_h
#define disc_builtin_h



#ifndef pres_participant_h
    #include "pres/pres_participant.h"
#endif

#ifndef cdr_encapsulation_h
    #include "cdr/cdr_encapsulation.h"
#endif

#ifndef cdr_stream_h
    #include "cdr/cdr_stream.h"
#endif

#ifndef cdr_typeObject_h
    #include "cdr/cdr_typeObject.h"
#endif


#ifndef rti_makeheader_h
    #include "log/log_makeheader.h"
#endif

#ifndef disc_dll_h
    #include "disc/disc_dll.h"
#endif

#ifndef osapi_heap_h
    #include "osapi/osapi_heap.h"
#endif

#ifndef reda_buffer_h
    #include "reda/reda_buffer.h"
#endif

#ifndef reda_fastBuffer_h
    #include "reda/reda_fastBuffer.h"
#endif

#ifndef pres_typePlugin_h
    #include "pres/pres_typePlugin.h"
#endif

#ifndef pres_participant_h
    #include "pres/pres_common.h"
#endif

#ifndef pres_participant_h
    #include "pres/pres_participant.h"
#endif

#ifndef pres_psService_h
    #include "pres/pres_psService.h"
#endif

#ifdef __cplusplus
    extern "C" {
#endif



/* Protocol defined built-in endpoint bits */ 
#define DISC_BUILTIN_ENDPOINT_PARTICIPANT_ANNOUNCER                     0x00000001 << 0
#define DISC_BUILTIN_ENDPOINT_PARTICIPANT_DETECTOR                      0x00000001 << 1
#define DISC_BUILTIN_ENDPOINT_PUBLICATION_ANNOUNCER                     0x00000001 << 2
#define DISC_BUILTIN_ENDPOINT_PUBLICATION_DETECTOR                      0x00000001 << 3
#define DISC_BUILTIN_ENDPOINT_SUBSCRIPTION_ANNOUNCER                    0x00000001 << 4
#define DISC_BUILTIN_ENDPOINT_SUBSCRIPTION_DETECTOR                     0x00000001 << 5
#define DISC_BUILTIN_ENDPOINT_PARTICIPANT_PROXY_ANNOUNCER               0x00000001 << 6
#define DISC_BUILTIN_ENDPOINT_PARTICIPANT_PROXY_DETECTOR                0x00000001 << 7
#define DISC_BUILTIN_ENDPOINT_PARTICIPANT_STATE_ANNOUNCER               0x00000001 << 8
#define DISC_BUILTIN_ENDPOINT_PARTICIPANT_STATE_DETECTOR                0x00000001 << 9

/* Builtin topic names */
#define DISC_BUILTIN_TOPIC_PARTICIPANT_SELF             "DISCParticipant"
#define DISC_BUILTIN_TOPIC_PARTICIPANT_PROXY            "DISCParticipantProxy"
#define DISC_BUILTIN_TOPIC_PARTICIPANT_STATE            "DISCParticipantState"
#define DISC_BUILTIN_TOPIC_PUBLICATION                  "DISCPublication"
#define DISC_BUILTIN_TOPIC_SUBSCRIPTION                 "DISCSubscription"

/* Property names for settable properties */
#define DISC_BUILTIN_PROPERTY_VALUE_SIZE (32)

#define DISC_BUILTIN_PROPERTY_LIST_MAX_LENGTH_NAME "DiscBuiltinPropertyListMaxLength"
#define DISC_BUILTIN_PROPERTY_STRING_MAX_LENGTH_NAME "DiscBuiltinPropertyStringMaxLength"
#define DISC_BUILTIN_USER_DATA_MAX_LENGTH_NAME "DiscBuiltinUserDataMaxLength"
#define DISC_BUILTIN_TRANSPORT_INFO_LIST_MAX_LENGTH_NAME "DiscTransportInfoListMaxLength"
#define DISC_BUILTIN_TOPIC_DATA_MAX_LENGTH_NAME "DiscBuiltinTopicDataMaxLength"
#define DISC_BUILTIN_GROUP_DATA_MAX_LENGTH_NAME "DiscBuiltinTopicGroupDataMaxLength"
#define DISC_BUILTIN_PARTITION_MAX_LENGTH_NAME "DiscBuiltinPartitionMaxLength"
#define DISC_BUILTIN_MAX_PARTITIONS_NAME "DiscBuiltinMaxPartitions"
#define DISC_BUILTIN_TYPE_CODE_MAX_LENGTH_NAME "DiscBuiltinTypeCodeMaxLength"
#define DISC_BUILTIN_TYPE_OBJECT_MAX_SERIALIZED_LENGTH_NAME "DiscBTOMSL"
#define DISC_BUILTIN_SERIALIZED_TYPE_OBJECT_DYNAMIC_ALLOCATION_THRESHOLD_NAME "DiscBSTODAT"
#define DISC_BUILTIN_TYPE_OBJECT_MAX_DESERIALIZED_LENGTH_NAME "DiscBTOMDL"
#define DISC_BUILTIN_DESERIALIZED_TYPE_OBJECT_DYNAMIC_ALLOCATION_THRESHOLD_NAME "DiscBDTODAT"
#define DISC_BUILTIN_CFT_PROPERTY_MAX_LENGTH_NAME "DiscBuiltinCFTPropertyMaxLength"
#define DISC_BUILTIN_LOCATOR_FILTER_SEQ_MAX_LENGTH_NAME "DiscBuiltinLocatorFilterSeqMaxLength"
#define DISC_BUILTIN_LOCATOR_FILTER_EXP_MAX_LENGTH_NAME "DiscBuiltinLocatorFilterExpMaxLength"

/* Participant properties */
#define DISC_BUILTIN_PARTICIPANT_PROPERTY_LENGTH (4)

#define DISC_BUILTIN_PARTICIPANT_PROPERTY_SIZE                                      \
strlen(DISC_BUILTIN_PROPERTY_LIST_MAX_LENGTH_NAME) +                                \
strlen(DISC_BUILTIN_PROPERTY_STRING_MAX_LENGTH_NAME) +                              \
strlen(DISC_BUILTIN_USER_DATA_MAX_LENGTH_NAME) +                                    \
strlen(DISC_BUILTIN_TRANSPORT_INFO_LIST_MAX_LENGTH_NAME) +                           \
DISC_BUILTIN_PARTICIPANT_PROPERTY_LENGTH * DISC_BUILTIN_PROPERTY_VALUE_SIZE +       \
DISC_BUILTIN_PARTICIPANT_PROPERTY_LENGTH

/* Publication properties */
#define DISC_BUILTIN_PUBLICATION_PROPERTY_LENGTH (14)

#define DISC_BUILTIN_PUBLICATION_PROPERTY_SIZE                                    \
strlen(DISC_BUILTIN_USER_DATA_MAX_LENGTH_NAME) +                                  \
strlen(DISC_BUILTIN_TOPIC_DATA_MAX_LENGTH_NAME) +                                 \
strlen(DISC_BUILTIN_GROUP_DATA_MAX_LENGTH_NAME) +                                 \
strlen(DISC_BUILTIN_PARTITION_MAX_LENGTH_NAME) +                                  \
strlen(DISC_BUILTIN_TYPE_CODE_MAX_LENGTH_NAME) +                                  \
strlen(DISC_BUILTIN_TYPE_OBJECT_MAX_SERIALIZED_LENGTH_NAME) +                     \
strlen(DISC_BUILTIN_SERIALIZED_TYPE_OBJECT_DYNAMIC_ALLOCATION_THRESHOLD_NAME) +   \
strlen(DISC_BUILTIN_TYPE_OBJECT_MAX_DESERIALIZED_LENGTH_NAME) +                   \
strlen(DISC_BUILTIN_DESERIALIZED_TYPE_OBJECT_DYNAMIC_ALLOCATION_THRESHOLD_NAME) + \
strlen(DISC_BUILTIN_PROPERTY_LIST_MAX_LENGTH_NAME) +                              \
strlen(DISC_BUILTIN_PROPERTY_STRING_MAX_LENGTH_NAME) +                            \
strlen(DISC_BUILTIN_MAX_PARTITIONS_NAME) +                                        \
strlen(DISC_BUILTIN_LOCATOR_FILTER_SEQ_MAX_LENGTH_NAME) +                         \
strlen(DISC_BUILTIN_LOCATOR_FILTER_EXP_MAX_LENGTH_NAME) +                         \
DISC_BUILTIN_PUBLICATION_PROPERTY_LENGTH * DISC_BUILTIN_PROPERTY_VALUE_SIZE +     \
DISC_BUILTIN_PUBLICATION_PROPERTY_LENGTH

/* Subscription properties */
#define DISC_BUILTIN_SUBSCRIPTION_PROPERTY_LENGTH (13)

#define DISC_BUILTIN_SUBSCRIPTION_PROPERTY_SIZE                                   \
strlen(DISC_BUILTIN_USER_DATA_MAX_LENGTH_NAME) +                                  \
strlen(DISC_BUILTIN_TOPIC_DATA_MAX_LENGTH_NAME) +                                 \
strlen(DISC_BUILTIN_GROUP_DATA_MAX_LENGTH_NAME) +                                 \
strlen(DISC_BUILTIN_PARTITION_MAX_LENGTH_NAME) +                                  \
strlen(DISC_BUILTIN_TYPE_CODE_MAX_LENGTH_NAME) +                                  \
strlen(DISC_BUILTIN_TYPE_OBJECT_MAX_SERIALIZED_LENGTH_NAME) +                     \
strlen(DISC_BUILTIN_SERIALIZED_TYPE_OBJECT_DYNAMIC_ALLOCATION_THRESHOLD_NAME) +   \
strlen(DISC_BUILTIN_TYPE_OBJECT_MAX_DESERIALIZED_LENGTH_NAME) +                   \
strlen(DISC_BUILTIN_DESERIALIZED_TYPE_OBJECT_DYNAMIC_ALLOCATION_THRESHOLD_NAME) + \
strlen(DISC_BUILTIN_PROPERTY_LIST_MAX_LENGTH_NAME) +                              \
strlen(DISC_BUILTIN_PROPERTY_STRING_MAX_LENGTH_NAME) +                            \
strlen(DISC_BUILTIN_CFT_PROPERTY_MAX_LENGTH_NAME) +                               \
strlen(DISC_BUILTIN_MAX_PARTITIONS_NAME) +                                        \
DISC_BUILTIN_SUBSCRIPTION_PROPERTY_LENGTH * DISC_BUILTIN_PROPERTY_VALUE_SIZE +    \
DISC_BUILTIN_SUBSCRIPTION_PROPERTY_LENGTH

/* Topic properties */
#define DISC_BUILTIN_TOPIC_PROPERTY_LENGTH (1)

#define DISC_BUILTIN_TOPIC_PROPERTY_SIZE                                        \
strlen(DISC_BUILTIN_TOPIC_DATA_MAX_LENGTH_NAME) +                               \
DISC_BUILTIN_TOPIC_PROPERTY_LENGTH * DISC_BUILTIN_PROPERTY_VALUE_SIZE +         \
DISC_BUILTIN_TOPIC_PROPERTY_LENGTH

extern DISCDllExport RTIBool
DISCBuiltin_createParticipantProperties(
    struct PRESPropertyQosPolicy *propertyQos,
    int userDataMaximumLength,
    int propertyListMaximumLength,
    int propertyStringMaximumLength,
    int transportInfoListMaxLength);


enum DISCBuiltinEndpointType {
    DISC_BUILTIN_ENDPOINT_TYPE_SUBSCRIPTION = 1,
    DISC_BUILTIN_ENDPOINT_TYPE_PUBLICATION
};

extern DISCDllExport RTIBool
DISCBuiltin_createEndpointProperties(
    struct PRESPropertyQosPolicy *propertyQos,
    int userDataMaximumLength,
    int groupDataMaximumLength,
    int topicDataMaximumLength,
    int partitionMaximumNameCount,
    int partitionMaximumCumulativeLength,
    int contentFilterPropertyMaxLength,
    int typeCodeMaximumSerializedLength,
    int typeObjectMaximumSerializedLength,
    int serializedTypeObjectDynamicAllocationThreshold,
    int typeObjectMaximumDeserializedLength,
    int deserializedTypeObjectDynamicAllocationThreshold,
    int propertyListMaximumLength,
    int propertyStringMaximumLength,
    int maxPartitions,
    int locatorFilterSeqMaxLength,
    int locatorFilterExpMaxLength,
    enum DISCBuiltinEndpointType topicType);

extern DISCDllExport void
DISCBuiltin_deleteProperties(
    struct PRESPropertyQosPolicy *propertyQos);


struct DISCPluginInfo {
    /*e Identifies vendor/implementer of the plugin. Meaningful only if (classId&0x8000)==1.
    */
    long vendorId;
    /*e Identifies the plugin. (classId&0x8000)==0 is reserved for standardized (interoperable) discovery protocols.
    */
    long classId;
    /*e Version info of the plugin.
    */
    long version;
    /*e Additional config parameters of the plugin.
    */
    struct PRESSequenceOctet parameters;
};


/*e \ingroup DISCPluggableModule
  \brief Used to initialize DISCPluginInfo.
*/
#define DISC_PLUGIN_INFO_INITIALIZE {   \
0, /* vendorId */                       \
0, /* classId */                        \
0, /* version */                        \
{0, 0, NULL} /* parameters */           \
}

extern DISCDllExport RTIBool
DISCPluginInfo_isSamePlugin(const struct DISCPluginInfo *left,
                            const struct DISCPluginInfo *right);

extern DISCDllExport void
DISCPluginInfo_copyShallow(struct DISCPluginInfo *to,
                           const struct DISCPluginInfo *from);


/*e \ingroup DISCPluggableModule
  \brief Maximum number of installable participant discovery plugins.
*/
  #define DISC_MAX_PDP_PLUGINS 8
/*e \ingroup DISCPluggableModule
  \brief Maximum number of installable endpoint discovery plugins.
*/
  #define DISC_MAX_EDP_PLUGINS 8

typedef enum {
    /*e Participant builtin topic.
    */
    DISC_BUILTIN_TOPIC_KIND_PARTICIPANT = 0,
    /*e Publication builtin topic.
    */
    DISC_BUILTIN_TOPIC_KIND_PUBLICATION,
    /*e Subscription builtin topic.
    */
    DISC_BUILTIN_TOPIC_KIND_SUBSCRIPTION,
    /*e Topic builtin topic.
    */
    DISC_BUILTIN_TOPIC_KIND_TOPIC,
    /* do not remove this; used to size internal array */
    _DISC_BUILTIN_TOPIC_KIND
} DISCBuiltinTopicKind;

struct
DISCBuiltinTopicParticipantData {
    /*e Guid of the participant
    */
    struct MIGRtpsGuid guid;
    /*e Parameters of the participant.
    */
    struct PRESParticipantParameter *parameter;
};


/*e \ingroup DISCPluggableModule
  \brief Initialize participant builtin topic data.
*/
#define DISC_BUILTIN_TOPIC_PARTICIPANT_DATA_INITIALIZE {        \
    MIG_RTPS_GUID_UNKNOWN, /* guid */                           \
    NULL /* parameter */                                        \
}

struct
DISCBuiltinTopicPublicationData {
    /*e GUID of the participant of the data writer.
    */
    struct MIGRtpsGuid participantGuid;
    /*e GUID of the data writer itself.
    */
    struct MIGRtpsGuid guid;
    /*e Parameters of the data writer.
    */
    struct PRESPsPublicationParameter *parameter;
};


/*e \ingroup DISCPluggableModule
  \brief Initialize publication builtin topic data.
*/
#define DISC_BUILTIN_TOPIC_PUBLICATION_DATA_INITIALIZE { \
    MIG_RTPS_GUID_UNKNOWN, /* participantGuid */ \
    MIG_RTPS_GUID_UNKNOWN, /* guid */ \
    NULL /* parameter */ \
}

struct
DISCBuiltinTopicSubscriptionData {
    /*e GUID of the participant of the data reader.
    */
    struct MIGRtpsGuid participantGuid;
    /*e GUID of the data reader itself.
    */
    struct MIGRtpsGuid guid;
    /*e Parameters of the data reader.
    */
    struct PRESPsSubscriptionParameter *parameter;
};


/*e \ingroup DISCPluggableModule
  \brief Initialize subscription builtin topic data.
*/
#define DISC_BUILTIN_TOPIC_SUBSCRIPTION_DATA_INITIALIZE { \
    MIG_RTPS_GUID_UNKNOWN, /* participantGuid */ \
    MIG_RTPS_GUID_UNKNOWN, /* guid */ \
    NULL /* parameter */ \
}

struct
DISCBuiltinTopicTopicData {
    /*e GUID.
    */
    struct MIGRtpsGuid guid;
};


/*e \ingroup DISCPluggableModule
  \brief Initialize topic builtin topic data.
*/
#define DISC_BUILTIN_TOPIC_TOPIC_DATA_INITIALIZE { \
    MIG_RTPS_GUID_UNKNOWN /* guid */ \
}

extern DISCDllExport RTIBool
DISCBuiltin_isBuiltinTopicName(const char* topicName);

struct DISCBuiltinTopicParticipantDataPool {
    struct PRESTypePluginPool *parent;

    struct REDAFastBufferPool *_participantParameterDataPool;

    struct REDAFastBufferPool *_userDataPool;

    struct REDAFastBufferPool *_propertyListPool;

    struct REDAFastBufferPool *_participantNamePool;

    struct REDAFastBufferPool *_transportInfoSeqPool;

    /* The property list is made up of to parts;
     * the sequence elements and the strings. When we
     * de-serialize we need to know how many elements
     * it was created with
     */
    int _propertyListMaximumLength;
    int _propertyStringMaximumLength;
    int _userDataMaximumLength;
    int _propertyMaximumSerializationLength;
    int _transportInfoSeqMaxLength;
};

extern DISCDllExport void 
DISCBuiltinTopicParticipantDataPlugin_setDefaultParameterValues(
    struct DISCBuiltinTopicParticipantData *topic_data);

struct DISCBuiltinTopicSubscriptionDataPool {
    struct PRESTypePluginPool *parent;

    struct REDAFastBufferPool *_subscriptionParameterPool;

    struct REDAFastBufferPool *_topicNamePool;
    struct REDAFastBufferPool *_typeNamePool;

    struct REDAFastBufferPool *_userDataPool;
    struct REDAFastBufferPool *_groupDataPool;
    struct REDAFastBufferPool *_topicDataPool;

    struct REDAFastBufferPool *_partitionPool;

    struct REDAFastBufferPool *_filterPropertyPool;
    
    struct REDAFastBufferPool *_typeCodePool;    

    RTICdrTypeObjectFactory *_typeObjectFactory;

    struct REDAFastBufferPool *_propertyPool;

    struct REDAFastBufferPool *_subscriptionNamePool;
    
    int _propertyListMaximumLength;
    int _propertyStringMaximumLength;
    int _propertyMaximumSerializedLength;
    int _typeCodeMaximumSerializedLength;
    int _typeObjectMaximumSerializedLength;
    int _serializedTypeObjectDynamicAllocationThreshold;
    int _typeObjectMaximumDeserializedLength;
    int _deserializedTypeObjectDynamicAllocationThreshold;
    int _userDataMaximumLength;
    int _groupDataMaximumLength;
    int _topicDataMaximumLength;
    int _partitionMaximumNameCount;
    int _partitionMaximumCumulativeLength;
    int _contentFilterPropertyMaxSerializedLength;
};

extern DISCDllExport void 
DISCBuiltinTopicSubscriptionDataPluginSupport_print(
    const struct DISCBuiltinTopicSubscriptionData *topic_data,
    const char *desc,
    unsigned int indent);

extern DISCDllExport void 
DISCBuiltinTopicSubscriptionDataPluginSupport_setDefaultParameterValues(
    struct DISCBuiltinTopicSubscriptionData *topic_data);

extern DISCDllExport RTIBool 
DISCBuiltinTopicSubscriptionDataPluginSupport_initializeData_ex(
    struct DISCBuiltinTopicSubscriptionData *sample,
    RTIBool allocatePointers);

extern DISCDllExport RTIBool 
DISCBuiltinTopicSubscriptionDataPluginSupport_initializeData(
    struct DISCBuiltinTopicSubscriptionData *sample);

extern DISCDllExport void
DISCBuiltinTopicSubscriptionDataPluginSupport_finalizeData_ex(
    struct DISCBuiltinTopicSubscriptionData *sample,
    RTIBool deletePointers);

extern DISCDllExport void 
DISCBuiltinTopicSubscriptionDataPluginSupport_finalizeData(
    struct DISCBuiltinTopicSubscriptionData *sample);

extern DISCDllExport struct DISCBuiltinTopicSubscriptionData *
DISCBuiltinTopicSubscriptionDataPluginSupport_createData();

extern DISCDllExport void 
DISCBuiltinTopicSubscriptionDataPluginSupport_destroyData(
    struct DISCBuiltinTopicSubscriptionData *topic_data);

extern DISCDllExport PRESTypePluginParticipantData 
DISCBuiltinTopicSubscriptionDataPlugin_onParticipantAttached(
    void *registrationData, 
    const struct PRESTypePluginParticipantInfo *participantInfo,
    RTIBool topLevelRegistration, 
    void *containerPluginContext,
    RTICdrTypeCode *typeCode);

extern DISCDllExport void 
DISCBuiltinTopicSubscriptionDataPlugin_onParticipantDetached(
    PRESTypePluginParticipantData participantData);

extern DISCDllExport void 
DISCBuiltinTopicSubscriptionDataPlugin_onEndpointDetached(
    PRESTypePluginEndpointData endpointData);

extern DISCDllExport PRESTypePluginEndpointData 
DISCBuiltinTopicSubscriptionDataPlugin_onEndpointAttached(
    PRESTypePluginParticipantData participantData,
    const struct PRESTypePluginEndpointInfo *endpointInfo,
    RTIBool topLevelRegistration, 
    void *containerPluginContext);

extern DISCDllExport RTIBool 
DISCBuiltinTopicSubscriptionDataPlugin_serializeParameters(
    PRESTypePluginEndpointData endpointData,
    const struct DISCBuiltinTopicSubscriptionData *topic_data,
    struct RTICdrStream *stream,
    RTIBool serializeEncapsulation, 
    RTIBool serializeData,
    void *endpointPluginQos);

extern DISCDllExport RTIBool 
DISCBuiltinTopicSubscriptionDataPlugin_serialize(
    PRESTypePluginEndpointData endpointData,
    const struct DISCBuiltinTopicSubscriptionData *topic_data,
    struct RTICdrStream *stream,
    RTIBool serializeEncapsulation,
    RTIEncapsulationId encapsulationId,
    RTIBool serializeData,
    void *endpointPluginQos);

extern DISCDllExport RTIBool 
DISCBuiltinTopicSubscriptionDataPlugin_deserializeParameterValue(
    PRESTypePluginEndpointData endpointData,
    RTIBool *ok, struct DISCBuiltinTopicSubscriptionData *topic_data,
    struct RTICdrStream *stream,
    RTICdrUnsignedLong parameterId, RTICdrUnsignedLong parameterLength,
    RTIBool deserializeEncapsulation, RTIBool deserializeSample,
    void *endpointPluginQos);

extern DISCDllExport RTIBool 
DISCBuiltinTopicSubscriptionDataPlugin_deserialize(
    PRESTypePluginEndpointData endpointData, 
    struct DISCBuiltinTopicSubscriptionData **topic_data,
    RTIBool * dropSample,
    struct RTICdrStream *stream,
    RTIBool deserializeEncapsulation,
    RTIBool deserializeSample,
    void *endpointPluginQos);

extern DISCDllExport struct DISCBuiltinTopicSubscriptionData *
DISCBuiltinTopicSubscriptionDataPlugin_getSample(
    PRESTypePluginEndpointData endpointData,
    void** handle /* out */);

extern DISCDllExport void 
DISCBuiltinTopicSubscriptionDataPlugin_returnSample(
    PRESTypePluginEndpointData endpointData,
    struct DISCBuiltinTopicSubscriptionData *sample,
    void *handle /* in */);

extern DISCDllExport unsigned int 
DISCBuiltinTopicSubscriptionDataPlugin_getParametersMaxSizeSerialized(
    unsigned int size, int userDataMaximumLength, int groupDataMaximumLength,
    int topicDataMaximumLength,
    int partitionMaximumNameCount,
    int partitionMaximumCumulativeLength,
    int contentFilterPropertyMaximumSerializedLength,
    int typeCodeMaximumSerializedLength,
    int typeObjectMaximumSerializedLength,
    int propertyListMaximumLength,int propertyStringMaximumLength);

extern DISCDllExport unsigned int 
DISCBuiltinTopicSubscriptionDataPlugin_getSerializedSampleMaxSizeI(
    unsigned int size, RTIBool includeEncapsulation,
    int userDataMaximumLength, int groupDataMaximumLength,
    int topicDataMaximumLength,
    int partitionMaximumNameCount,
    int partitionMaximumCumulativeLength,
    int contentFilterPropertyMaximumSerializedLength,
    int typeCodeMaximumSerializedLength,
    int typeObjectMaximumSerializedLength,
    int propertyListMaximumLength,int propertyStringMaximumLength);

extern DISCDllExport unsigned int
DISCBuiltinTopicSubscriptionDataPlugin_getSerializedSampleMaxSize(
    PRESTypePluginEndpointData endpointData,
    RTIBool includeEncapsulation,
    RTIEncapsulationId encapsulationId,
    unsigned int size);

extern DISCDllExport RTIBool 
DISCBuiltinTopicSubscriptionDataPlugin_copy(
    PRESTypePluginEndpointData endpointData,
    struct DISCBuiltinTopicSubscriptionData *out,
    const struct DISCBuiltinTopicSubscriptionData *in);

extern DISCDllExport struct DISCBuiltinTopicSubscriptionData *
DISCBuiltinTopicSubscriptionDataPlugin_createSample(
    PRESTypePluginEndpointData endpointData);

extern DISCDllExport void
DISCBuiltinTopicSubscriptionDataPlugin_destroySample(
    PRESTypePluginEndpointData endpointData,
    struct DISCBuiltinTopicSubscriptionData *sample);

extern DISCDllExport PRESTypePluginKeyKind 
DISCBuiltinTopicSubscriptionDataPlugin_getKeyKind();

extern DISCDllExport struct PRESTypePlugin **
DISCBuiltinTopicSubscriptionDataPlugin_assert();

extern DISCDllExport void
DISCBuiltinTopicSubscriptionDataPlugin_delete(
    struct PRESTypePlugin *plugin);

extern DISCDllExport int
DISCBuiltinTopicSubscriptionDataPluginSupport_compare(
    const struct DISCBuiltinTopicSubscriptionData *left,
    const struct DISCBuiltinTopicSubscriptionData *right);

struct DISCBuiltinTopicPublicationDataPool {
    struct PRESTypePluginPool *parent;
     
    struct REDAFastBufferPool *_publicationParameterPool;

    struct REDAFastBufferPool *_topicNamePool;
    struct REDAFastBufferPool *_typeNamePool;

    struct REDAFastBufferPool *_userDataPool;
    struct REDAFastBufferPool *_groupDataPool;
    struct REDAFastBufferPool *_topicDataPool;
    struct REDAFastBufferPool *_partitionPool;
    
    struct REDAFastBufferPool *_typeCodePool;

    RTICdrTypeObjectFactory * _typeObjectFactory;

    struct REDAFastBufferPool *_typeObjectPool;

    struct REDAFastBufferPool *_propertyPool;

    struct REDAFastBufferPool *_locatorFilterPool;
    struct REDAFastBufferPool *_locatorFilterLocatorsPool;

    struct REDAFastBufferPool *_publicationNamePool;
    
    int _propertyListMaximumLength;
    int _propertyStringMaximumLength;
    int _userDataMaximumLength;
    int _groupDataMaximumLength;
    int _topicDataMaximumLength;
    int _partitionMaximumNameCount;
    int _partitionMaximumCumulativeLength;
    int _propertyMaximumSerializedLength;
    int _typeCodeMaximumSerializedLength;
    int _typeObjectMaximumSerializedLength;
    int _serializedTypeObjectDynamicAllocationThreshold;
    int _typeObjectMaximumDeserializedLength;
    int _deserializedTypeObjectDynamicAllocationThreshold;
    int _locatorFilterSeqMaximumLength;
    int _locatorFilterExpMaximumLength;
};

extern DISCDllExport void 
DISCBuiltinTopicPublicationDataPluginSupport_print(
    const struct DISCBuiltinTopicPublicationData *topic_data,
    const char *desc,
    unsigned int indent);

extern DISCDllExport void 
DISCBuiltinTopicPublicationDataPluginSupport_setDefaultParameterValues(
    struct DISCBuiltinTopicPublicationData *topic_data);

extern DISCDllExport RTIBool 
DISCBuiltinTopicPublicationDataPluginSupport_initializeData_ex(
    struct DISCBuiltinTopicPublicationData *sample,
    RTIBool allocatePointers);

extern DISCDllExport void 
DISCBuiltinTopicPublicationDataPluginSupport_initializeData(
    struct DISCBuiltinTopicPublicationData *sample);

extern DISCDllExport void
DISCBuiltinTopicPublicationDataPluginSupport_finalizeData_ex(
    struct DISCBuiltinTopicPublicationData *sample,
    RTIBool deletePointers);

extern DISCDllExport void 
DISCBuiltinTopicPublicationDataPluginSupport_finalizeData(
    struct DISCBuiltinTopicPublicationData *sample);

extern DISCDllExport void 
DISCBuiltinTopicPublicationDataPluginSupport_destroyData(
    struct DISCBuiltinTopicPublicationData *topic_data);

extern DISCDllExport PRESTypePluginParticipantData 
DISCBuiltinTopicPublicationDataPlugin_onParticipantAttached(
    void *registrationData, 
    const struct PRESTypePluginParticipantInfo *participantInfo,
    RTIBool topLevelRegistration, 
    void *containerPluginContext,
    RTICdrTypeCode *typeCode);

extern DISCDllExport void 
DISCBuiltinTopicPublicationDataPlugin_onParticipantDetached(
    PRESTypePluginParticipantData participantData);

extern DISCDllExport void 
DISCBuiltinTopicPublicationDataPlugin_onEndpointDetached(
    PRESTypePluginEndpointData endpointData);

extern DISCDllExport PRESTypePluginEndpointData 
DISCBuiltinTopicPublicationDataPlugin_onEndpointAttached(
    PRESTypePluginParticipantData participantData,
    const struct PRESTypePluginEndpointInfo *endpointInfo,
    RTIBool topLevelRegistration, 
    void *containerPluginContext);

extern DISCDllExport RTIBool
DISCBuiltinTopicPublicationDataPlugin_serializeParameters(
    PRESTypePluginEndpointData endpointData,
    const struct DISCBuiltinTopicPublicationData *topic_data,
    struct RTICdrStream *stream,
    RTIBool serializeEncapsulation, 
    RTIBool serializeData,
    void *endpointPluginQos);

extern DISCDllExport RTIBool 
DISCBuiltinTopicPublicationDataPlugin_serialize(
    PRESTypePluginEndpointData endpointData,
    const struct DISCBuiltinTopicPublicationData *topic_data,
    struct RTICdrStream *stream,
    RTIBool serializeEncapsulation,
    RTIEncapsulationId encapsulationId,
    RTIBool serializeData,
    void *endpointPluginQos);

extern DISCDllExport RTIBool 
DISCBuiltinTopicPublicationDataPlugin_deserializeParameterValue(
    PRESTypePluginEndpointData endpointData,
    RTIBool *ok, struct DISCBuiltinTopicPublicationData *topic_data,
    struct RTICdrStream *stream,
    RTICdrUnsignedLong parameterId, RTICdrUnsignedLong parameterLength,
    RTIBool deserializeEncapsulation, RTIBool deserializeSample,
    void *endpointPluginQos);

extern DISCDllExport RTIBool 
DISCBuiltinTopicPublicationDataPlugin_deserialize(
    PRESTypePluginEndpointData endpointData, 
    struct DISCBuiltinTopicPublicationData **topic_data,
    RTIBool * dropSample,
    struct RTICdrStream *stream,
    RTIBool deserializeEncapsulation,
    RTIBool deserializeSample,
    void *endpointPluginQos);

extern DISCDllExport unsigned int 
DISCBuiltinTopicPublicationDataPlugin_getParametersMaxSizeSerialized(
    unsigned int size, int userDataMaximumLength, int groupDataMaximumLength,
    int topicDataMaximumLength, int partitionMaximumNameCount,
    int partitionMaximumCumulativeLength, int typeCodeMaximumSerializedLength,
    int typeObjectMaximumSerializedLength,
    int propertyListMaximumLength,int propertyStringMaximumLength,
    int locatorFilterSeqMaxLength, int locatorFilterExpressionMaxLength);

extern DISCDllExport unsigned int 
DISCBuiltinTopicPublicationDataPlugin_getSerializedSampleMaxSizeI(
    unsigned int size, RTIBool includeEncapsulation,
    int userDataMaximumLength, int groupDataMaximumLength,
    int topicDataMaximumLength, int partitionMaximumNameCount,
    int partitionMaximumCumulativeLength, int typeCodeMaximumSerializedLength,
    int typeObjectMaximumSerializedLength,
    int propertyListMaximumLength,int propertyStringMaximumLength,
    int locatorFilterSeqMaxLength, int locatorFilterExpressionMaxLength);

extern DISCDllExport unsigned int
DISCBuiltinTopicPublicationDataPlugin_getSerializedSampleMaxSize(
    PRESTypePluginEndpointData endpointData,
    RTIBool includeEncapsulation,
    RTIEncapsulationId encapsulationId,
    unsigned int size);

extern DISCDllExport PRESTypePluginKeyKind 
DISCBuiltinTopicPublicationDataPlugin_getKeyKind(
    const struct PRESTypePlugin* me);

extern DISCDllExport RTIBool 
DISCBuiltinTopicPublicationDataPlugin_copy(
    PRESTypePluginEndpointData endpointData,
    struct DISCBuiltinTopicPublicationData *out,
    const struct DISCBuiltinTopicPublicationData *in);

extern DISCDllExport struct DISCBuiltinTopicPublicationData *
DISCBuiltinTopicPublicationDataPlugin_getSample(
    PRESTypePluginEndpointData endpointData,
    void** handle /* out */);

extern DISCDllExport void 
DISCBuiltinTopicPublicationDataPlugin_returnSample(
    PRESTypePluginEndpointData endpointData,
    struct DISCBuiltinTopicPublicationData *sample,
    void *handle /* in */);

extern DISCDllExport struct DISCBuiltinTopicPublicationData *
DISCBuiltinTopicPublicationDataPlugin_createSample(
    PRESTypePluginEndpointData endpointData);

extern DISCDllExport void
DISCBuiltinTopicPublicationDataPlugin_destroySample(
    PRESTypePluginEndpointData endpointData,
    struct DISCBuiltinTopicPublicationData *sample);

extern DISCDllExport struct PRESTypePlugin**
DISCBuiltinTopicPublicationDataPlugin_assert();

extern DISCDllExport void
DISCBuiltinTopicPublicationDataPlugin_delete(
    struct PRESTypePlugin *plugin);

extern DISCDllExport int 
DISCBuiltinTopicPublicationDataPluginSupport_compare(
    const struct DISCBuiltinTopicPublicationData *left,
    const struct DISCBuiltinTopicPublicationData *right);

extern DISCDllExport void 
DISCBuiltinTopicParticipantDataPluginSupport_print(
    const struct DISCBuiltinTopicParticipantData *topic_data,
    const char *desc,
    unsigned int indent);

extern DISCDllExport void 
DISCBuiltinTopicParticipantDataPluginSupport_setDefaultParameterValues(
    struct DISCBuiltinTopicParticipantData *topic_data);

extern DISCDllExport RTIBool 
DISCBuiltinTopicParticipantDataPluginSupport_initializeData_ex(
    struct DISCBuiltinTopicParticipantData *sample,
    RTIBool allocatePointers);

extern DISCDllExport RTIBool 
DISCBuiltinTopicParticipantDataPluginSupport_initializeData(
    struct DISCBuiltinTopicParticipantData *sample);

extern DISCDllExport void
DISCBuiltinTopicParticipantDataPluginSupport_finalizeData_ex(
    struct DISCBuiltinTopicParticipantData *sample,
    RTIBool deletePointers);

extern DISCDllExport void 
DISCBuiltinTopicParticipantDataPluginSupport_finalizeData(
    struct DISCBuiltinTopicParticipantData *sample);

extern DISCDllExport struct DISCBuiltinTopicParticipantData*
DISCBuiltinTopicParticipantDataPluginSupport_createData();

extern DISCDllExport void 
DISCBuiltinTopicParticipantDataPluginSupport_destroyData(
    struct DISCBuiltinTopicParticipantData *sample);

extern DISCDllExport PRESTypePluginParticipantData 
DISCBuiltinTopicParticipantDataPlugin_onParticipantAttached(
    void *registrationData, 
    const struct PRESTypePluginParticipantInfo *participantInfo,
    RTIBool topLevelRegistration, 
    void *containerPluginContext,
    RTICdrTypeCode *typeCode);

extern DISCDllExport void 
DISCBuiltinTopicParticipantDataPlugin_onParticipantDetached(
    PRESTypePluginParticipantData participantData);

extern DISCDllExport PRESTypePluginEndpointData 
DISCBuiltinTopicParticipantDataPlugin_onEndpointAttached(
    PRESTypePluginParticipantData participantData,
    const struct PRESTypePluginEndpointInfo *endpointInfo,
    RTIBool topLevelRegistration, 
    void *containerPluginContext);

extern DISCDllExport void 
DISCBuiltinTopicParticipantDataPlugin_onEndpointDetached(
    PRESTypePluginEndpointData endpointData);

extern DISCDllExport struct DISCBuiltinTopicParticipantData *
DISCBuiltinTopicParticipantDataPlugin_getSample(
    PRESTypePluginEndpointData endpointData,
    void** handle /* out */);

extern DISCDllExport void 
DISCBuiltinTopicParticipantDataPlugin_returnSample(
    PRESTypePluginEndpointData endpointData,
    struct DISCBuiltinTopicParticipantData *sample,
    void *handle /* in */);

extern DISCDllExport struct DISCBuiltinTopicParticipantData *
DISCBuiltinTopicParticipantDataPlugin_createSample(
    PRESTypePluginEndpointData endpointData);

extern DISCDllExport void
DISCBuiltinTopicParticipantDataPlugin_destroySample(
    PRESTypePluginEndpointData endpointData,
    struct DISCBuiltinTopicParticipantData *sample);

extern DISCDllExport RTIBool 
DISCBuiltinTopicParticipantDataPlugin_serializeParameters(
    PRESTypePluginEndpointData endpointData,
    const struct DISCBuiltinTopicParticipantData *topic_data,
    struct RTICdrStream *stream,
    RTIBool serializeEncapsulation, 
    RTIBool serializeData,
    void *endpointPluginQos);

extern DISCDllExport RTIBool 
DISCBuiltinTopicParticipantDataPlugin_serialize(
    PRESTypePluginEndpointData endpointData,
    const struct DISCBuiltinTopicParticipantData *topic_data,
    struct RTICdrStream *stream,
    RTIBool serializeEncapsulation,
    RTIEncapsulationId encapsulationId,
    RTIBool serializeData,
    void *endpointPluginQos);

extern DISCDllExport RTIBool 
DISCBuiltinTopicParticipantDataPlugin_deserializeParameterValue(
    PRESTypePluginEndpointData endpointData,
    RTIBool *ok, struct DISCBuiltinTopicParticipantData *topic_data,
    struct RTICdrStream *stream,
    RTICdrUnsignedLong parameterId, RTICdrUnsignedLong parameterLength,
    RTIBool deserializeEncapsulation, RTIBool deserializeSample,
    void *endpointPluginQos);

extern DISCDllExport RTIBool 
DISCBuiltinTopicParticipantDataPlugin_deserialize(
    PRESTypePluginEndpointData endpointData,
    struct DISCBuiltinTopicParticipantData **topic_data,
    RTIBool * dropSample,
    struct RTICdrStream *stream,
    RTIBool deserializeEncapsulation,
    RTIBool deserializeSample,
    void *endpointPluginQos);

extern DISCDllExport unsigned int
DISCBuiltinTopicParticipantDataPlugin_getParametersMaxSizeSerialized(
    unsigned int size,
    int transportInfoMaximumLength,
    int userDataMaximumLength,
    int propertyListMaximumLength,
    int propertyStringMaximumLength);

extern DISCDllExport unsigned int
DISCBuiltinTopicParticipantDataPlugin_getSerializedSampleMaxSizeI(
    unsigned int size,
    RTIBool includeEncapsulation,
    int transportInfoMaxLength,
    int userDataMaxSize,
    int propertyListMaxSize,
    int propertyStringMaxSize);

extern DISCDllExport unsigned int
DISCBuiltinTopicParticipantDataPlugin_getSerializedSampleMaxSize(
    PRESTypePluginEndpointData endpointData,
    RTIBool includeEncapsulation,
    RTIEncapsulationId encapsulationId,
    unsigned int size);

extern DISCDllExport RTIBool 
DISCBuiltinTopicParticipantDataPlugin_copy(
    PRESTypePluginEndpointData endpointData,
    struct DISCBuiltinTopicParticipantData *out,
    const struct DISCBuiltinTopicParticipantData *in);

extern DISCDllExport PRESTypePluginKeyKind 
DISCBuiltinTopicParticipantDataPlugin_getKeyKind();

extern DISCDllExport struct PRESTypePlugin **
DISCBuiltinTopicParticipantDataPlugin_assert();

extern DISCDllExport void
DISCBuiltinTopicParticipantDataPlugin_delete(
    struct PRESTypePlugin *plugin);

extern DISCDllExport int 
DISCBuiltinTopicParticipantDataPluginSupport_compare(
    const struct DISCBuiltinTopicParticipantData *left,
    const struct DISCBuiltinTopicParticipantData *right);

extern DISCDllExport void
DISCBuiltin_printDurabilityQosPolicy(const struct PRESDurabilityQosPolicy* p,
				     const char *desc, unsigned int indent);

extern DISCDllExport void
DISCBuiltin_printOwnershipQosPolicy(const struct PRESOwnershipQosPolicy *p,
				    const char *desc, unsigned int indent);

extern DISCDllExport void DISCBuiltin_printPresentationQosPolicy(
    const struct PRESPresentationQosPolicy *p,
    const char *desc, unsigned int indent);

extern DISCDllExport void DISCBuiltin_printDestinationOrderQosPolicy(
    const struct PRESDestinationOrderQosPolicy *p,
    const char *desc, unsigned int indent);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* disc_builtin_h */
