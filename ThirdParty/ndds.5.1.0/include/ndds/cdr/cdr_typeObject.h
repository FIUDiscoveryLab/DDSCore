/* (c) Copyright, Real-Time Innovations, Inc. 2003-2009. All rights reserved. */
/*
 * @(#)cdr_typeObject.h    generated by: makeheader    Sat Nov 23 02:38:22 2013
 *
 *		built from:	typeObject.ifc
 */

#ifndef cdr_typeObject_h
#define cdr_typeObject_h


 #ifndef osapi_type_h
    #include "osapi/osapi_type.h"
 #endif
 #ifndef cdr_dll_h
    #include "cdr/cdr_dll.h"
 #endif
 #ifndef cdr_type_h
    #include "cdr/cdr_type.h"
 #endif
#ifndef cdr_stream_h
    #include "cdr/cdr_stream.h"
#endif
#ifndef reda_fastBuffer_h
    #include "reda/reda_fastBuffer.h"
#endif
#ifndef cdr_typecode_h
    #include "cdr/cdr_typeCode.h"
#endif


#ifdef __cplusplus
    extern "C" {
#endif


struct RTICdrTypeObject;

typedef struct RTICdrTypeObjectFactory {

    /*i @brief (private) Fast buffer pool to allocate TypeObjects in buffer
       form when size is below deserializedAllocThreshold
      */
    struct REDAFastBufferPool * _allocator;
    
    /*i @brief (private) Fast buffer pool to allocate serialize buffer 
      this is used only to convert from type code into type object
      buffer representation. There should be only one buffer out
      at a time (unless the factory is used by different threads)
     */
    struct REDAFastBufferPool * _serializePool;

    /*i @brief (read-only) */
    int maxSerializedSize;
    /*i @brief (read-only) */
    int maxDeserializedSize;
    /*i @brief (read-only) */
    int serializedAllocThreshold;
    /*i @brief (read-only) */
    int deserializedAllocThreshold;

} RTICdrTypeObjectFactory;

extern RTICdrDllExport 
RTICdrTypeObjectFactory * RTICdrTypeObjectFactory_new(
    int maxSizeSerialized,
    int maxSizeDeserialized,
    int serializedDynamicAllocationThreshold,
    int deserializedDynamicAllocationThreshold,
    struct REDAFastBufferPoolProperty * poolProperty);

extern RTICdrDllExport 
void RTICdrTypeObjectFactory_delete(
    RTICdrTypeObjectFactory * self);

extern RTICdrDllExport 
struct RTICdrTypeObject * RTICdrTypeObjectFactory_createTypeObjectFromTypeCode(
    RTICdrTypeObjectFactory * self,
    const RTICdrTypeCode * typeCode);

extern RTICdrDllExport 
struct RTICdrTypeObject * RTICdrTypeObjectFactory_createTypeObjectBufferFromTypeCode(
    RTICdrTypeObjectFactory * self,
    RTICdrOctet * typeObjectMd5, /* out */
    const RTICdrTypeCode * typeCode);

extern RTICdrDllExport 
struct RTICdrTypeObject * RTICdrTypeObjectFactory_createTypeObjectBuffer(
    RTICdrTypeObjectFactory * self,
    int deserializedSize,
    RTIBool forceDynamicAllocation);

extern RTICdrDllExport
struct RTICdrTypeObject * RTICdrTypeObjectFactory_deserializeTypeObject(
    RTICdrTypeObjectFactory * self,
    RTICdrOctet * typeObjectMd5,
    struct RTICdrStream * stream,
    void * endpointData,
    void * endpointPluginQos);

extern RTICdrDllExport  
struct RTICdrTypeObject * RTICdrTypeObjectFactory_copyTypeObject(
    struct RTICdrTypeObjectFactory * self,
    const struct RTICdrTypeObject * source,
    RTIBool forceDynamicAllocation);

extern RTICdrDllExport 
RTIBool RTICdrTypeObjectFactory_deleteTypeObject(
    struct RTICdrTypeObjectFactory * self,
    const struct RTICdrTypeObject * typeObject);

extern RTICdrDllExport 
int RTICdrTypeObjectFactory_getTypeObjectDeserializedSize(
    struct RTICdrTypeObjectFactory * self,
    const struct RTICdrTypeObject * typeObject);


struct RTICdrTypeObjectAssignabilityProperty {
    /*e
     * When set to true, the assignability algorithm won't enforce the rule
     * that says that members of aggregation types (struct, union) with
     * the same ID must have the same name.
     *
     * For example, A and B would be assignable only if ignoreMemberNames is set
     * to true:
     *
     * struct A {
     *    long a;
     * };
     *
     * struct B {
     *    long b;
     * };
     */
    RTIBool ignoreMemberNames;

    /*e
     * When set to true, the assignability algorithm won't enforce the rule
     * that disallows assigning a sequence to another sequence with a smaller
     * bound.
     *
     * For example, sequence<long, 100> is assignable to sequence<long, 200> but
     * sequence<long, 200> is only assignable to sequence<long, 100> if
     * ignoreSequenceBounds is true.
     *
     * This property applies to sequence, string and map types. It does not
     * affect arrays, whose bounds must be equal in all cases.
     *
     * Note: the deserialization algorithm takes into can handle on a per-sample
     * basis objects that are not assignable, depending on the actual sequence
     * length in that sample.
     */
    RTIBool ignoreSequenceBounds;
};


#define RTI_CDR_TYPE_OBJECT_ASSIGNABILITY_PROPERTY_DEFAULT {                  \
    RTI_FALSE /* ignoreFieldNames */,                                         \
    RTI_FALSE /* ignoreSequenceBounds */                                      \
}

extern RTICdrDllExport RTIBool RTICdrTypeObject_serialize(
    void *endpointData,
    const struct RTICdrTypeObject *typeObject,
    struct RTICdrStream *stream,
    RTIBool serializeEncapsulation, 
    RTIEncapsulationId encapsulationId,
    RTIBool serializeSample,
    void *endpointPluginQos);

extern RTICdrDllExport
RTIBool RTICdrTypeObject_equals(const struct RTICdrTypeObject * self,
                                const struct RTICdrTypeObject * other);

extern RTICdrDllExport
RTIBool RTICdrTypeObject_equals_w_params(
    const struct RTICdrTypeObject * self,
    const struct RTICdrTypeObject * other,
    RTIBool printCause);

extern RTICdrDllExport RTIBool
RTICdrTypeObject_is_assignable(const struct RTICdrTypeObject * self,
                               const struct RTICdrTypeObject * other);

extern RTICdrDllExport RTIBool
RTICdrTypeObject_is_assignable_w_property(
    const struct RTICdrTypeObject * self,
    const struct RTICdrTypeObject * other,
    const struct RTICdrTypeObjectAssignabilityProperty * property);

extern RTICdrDllExport struct RTICdrTypeObject *
RTICdrTypeObject_createFromTypeCode(struct RTICdrTypeObject *self,
                                    RTICdrTypeCode *typeCode);

extern RTICdrDllExport RTIBool 
RTICdrTypeObject_convertToTypeCode(struct RTICdrTypeObject * self,
                                   RTICdrTypeCode **typeCode);

extern RTICdrDllExport void
RTICdrTypeObject_destroyTypeObject(struct RTICdrTypeObject *self);

extern RTICdrDllExport
RTIBool RTICdrTypeObject_copyContiguousBufferTypeObject(
    struct RTICdrTypeObject *dst, const struct RTICdrTypeObject *src);

extern RTICdrDllExport
unsigned int RTICdrTypeObject_getSerializedSampleSize(
    void * endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const struct RTICdrTypeObject * sample);

extern RTICdrDllExport RTIBool
RTICdrTypeObject_getFullyQualifiedName(
    struct RTICdrTypeObject * self,
    char * name,
    int maxNameLength);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* cdr_typeObject_h */
