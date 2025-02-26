/* (c) Copyright, Real-Time Innovations, Inc. 2003-2009. All rights reserved. */
/*
 * @(#)connext_cpp_untyped_common.h    generated by: makeheader    Sat Nov 23 02:41:09 2013
 *
 *		built from:	untyped_common.ifcxx
 */

#ifndef connext_cpp_untyped_common_h
#define connext_cpp_untyped_common_h



#include <string>

#include "clock/clock_interface.h"

#include "ndds/ndds_cpp.h"
#include "ndds/ndds_namespace_cpp.h"

#include "connext_cpp/connext_cpp_dll.h"
#include "connext_cpp/connext_cpp_infrastructure.h"
#include "connext_cpp/connext_cpp_entity_params.h"

using namespace DDS;

class DDSTypeSupport;
class DDSDomainParticipant;

namespace connext {
namespace details {

XMQCPPDllExport
std::string log_and_rethrow_conditional(
    DDSDataWriter * datawriter,
    DDSDataReader * datareader,
    const connext::Rethrowable& ex,
    const char * CLASS_NAME,
    const char * METHOD_NAME,
    bool rethrow); 

XMQCPPDllExport
void init_sample_info(DDS::SampleInfo& info);

// --- EntityUntypedImpl: -----------------------------------------------------

// Common functionality shared by Requester and Replier 
class XMQCPPDllExport EntityUntypedImpl  {
public: 
    virtual ~EntityUntypedImpl();
    void swap(EntityUntypedImpl& other);
protected:

    static const char * const CLASS_NAME;

    // --- Creation: ----------------------------------------------------------

    typedef const char * (*RegisterTypeFunc)
        (TypeSupport *, DDSDomainParticipant *);

    class TopicBuilder {
    public:
        virtual Topic * create_writer_topic(
            const EntityParams& params,
            const char * writer_type_name) = 0;
    
        virtual TopicDescription * create_reader_topic(
            const EntityParams& params,
            const char * reader_type_name) = 0;

        virtual ~TopicBuilder() {}
    };

    EntityUntypedImpl();

    void initialize(
        const EntityParams& params,
        RegisterTypeFunc register_writer_type_fnc,
        RegisterTypeFunc register_reader_type_fnc,
        int sample_size,
        TopicBuilder& topic_builder,
        DataReaderListener * reader_listener,
        bool isStringDataReader,
        const char * role_name);

    void finalize();

    virtual void get_datawriter_qos(
        DDS_DataWriterQos& qos,
        const EntityParams& params,
        const char * topic_name,
        const char * role_name);

    virtual void get_datareader_qos(
        DDS_DataReaderQos& qos,
        const EntityParams& params,
        const char * topic_name,
        const char * role_name);

    // --- Send: --------------------------------------------------------------

    void send_sample(const void * data, WriteParams_t& info);

    // --- Wait: --------------------------------------------------------------

    bool wait_for_any_sample(
        const DDS_Duration_t& max_wait,
        int min_sample_count);
    
    bool wait_for_samples(
        const DDS_Duration_t& max_wait,
        int min_sample_count,
        WaitSet& waitset,
        ReadCondition * initial_condition,
        ReadCondition * condition);

    // --- Receive: -----------------------------------------------------------

    bool get_sample_loaned(
        void *** received_data,
        int * data_count,
        SampleInfoSeq& info_seq,
        Long data_seq_len, 
        Long data_seq_max_len, 
        Boolean data_seq_has_ownership,
        Long max_samples,
        ReadCondition * condition,
        bool take);

    bool get_sample_loaned(
        void *** received_data,
        int * data_count,
        SampleInfoSeq& info_seq,
        Long max_samples,
        bool take,
        ReadCondition * condition = NULL);

    bool receive_sample_loaned(
        void *** received_data,
        int * data_count,
        SampleInfoSeq& info_seq,
        Long max_samples,
        const DDS_Duration_t& max_wait,
        int min_sample_count);

    void return_loan(
        void** data_array, 
        SampleInfoSeq& info_seq);

    int touch_samples(int max_count, ReadCondition * condition);

    // --- Query: -------------------------------------------------------------

    DDSDataReader * get_datareader() const;
    DDSDataWriter * get_datawriter() const;

    // --- Validate: ----------------------------------------------------------

    void validate(int min_count, int max_count, DDS_Duration_t max_wait) const;

    // --- Logging helper: ----------------------------------------------------

    void log_and_rethrow(const connext::Rethrowable& ex,
                         const char * CLASS_NAME, 
                         const char * METHOD_NAME) const;

    // --- Members: -----------------------------------------------------------

protected:
    // <<uses>>
    DomainParticipant * _participant;
    Publisher * _publisher;
    Subscriber * _subscriber;
    Topic * _writer_topic;
    TopicDescription * _reader_topic;

    // <<owns>> 
    DataWriter * _writer;
    DataReader * _reader;

    WaitSet _waitset;
    ReadCondition * _not_read_sample_cond;
    ReadCondition * _any_sample_cond;
    RTIClock * _clock;

    int _sample_size;
    bool _isStringDataReader;
    DDS::Long _max_samples_per_read;
    bool _finalized;
};
 

DDS::TopicDescription * get_or_create_topic(
        DDS::DomainParticipant * participant,
        const char * name,
        const char * type_name,
        bool allow_cft);

std::string create_request_topic_name_from_service_name(
    std::string service_name);

std::string create_reply_topic_name_from_service_name(
    std::string service_name);

void get_datawriter_qos(
    DDS_DataWriterQos& qos,
    DDS::DomainParticipant * participant,
    const EntityParams& params);

void get_datareader_qos(
    DDS_DataReaderQos& qos,
    DDS::DomainParticipant * participant,
    const EntityParams& params);


} // namespace details
} // namespace connext


#endif /* connext_cpp_untyped_common_h */
