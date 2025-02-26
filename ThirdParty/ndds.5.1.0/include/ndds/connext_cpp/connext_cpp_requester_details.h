/* (c) Copyright, Real-Time Innovations, Inc. 2003-2009. All rights reserved. */
/*
 * @(#)connext_cpp_requester_details.h    generated by: makeheader    Sat Nov 23 02:41:09 2013
 *
 *		built from:	requester_details.ifcxx
 */

#ifndef connext_cpp_requester_details_h
#define connext_cpp_requester_details_h


#include <stdexcept>
#include <memory>

#include "clock/clock_interface.h"

#include "ndds/ndds_namespace_cpp.h"

#include "connext_cpp/connext_cpp_dll.h"
#include "connext_cpp/connext_cpp_exception.h"
#include "connext_cpp/connext_cpp_infrastructure.h"
#include "connext_cpp/connext_cpp_untyped_common.h"
#include "connext_cpp/connext_cpp_requester_params.h"


namespace connext {
namespace details {

using namespace DDS;

// --- RequesterUntypedImpl: --------------------------------------------------

class XMQCPPDllExport RequesterUntypedImpl : public EntityUntypedImpl {
public: 
    virtual ~RequesterUntypedImpl();

protected:

    RequesterUntypedImpl(
        const RequesterParams& params,
        RegisterTypeFunc register_request_type_fnc,
        RegisterTypeFunc register_reply_type_fnc,
        int size_of_reply,
        bool isStringDataReader);

    bool wait_for_replies(
        const DDS_Duration_t& max_wait,
        int min_sample_count,
        const SampleIdentity_t& related_request_id);

    void get_reply_loaned(
        void *** received_data,
        int * data_count,
        SampleInfoSeq& info_seq,
        Long max_samples,
        const SampleIdentity_t& related_request_id,
        bool take);

private:
    // --- Helper methods: ----------------------------------------------------

    ReadCondition * create_correlation_condition(
            DDS_SampleStateMask state_kind,
            const SequenceNumber_t& sequence_number);

private:
    // --- Members: -----------------------------------------------------------

    std::auto_ptr<FastObjectPool<DDS::WaitSet> > waitset_pool;

private:
    // --- Types: -------------------------------------------------------------

    class RequesterTopicBuilder : public EntityUntypedImpl::TopicBuilder {
    public:

        explicit RequesterTopicBuilder(RequesterUntypedImpl * requester)
            : _requester(requester)
        {
        }

        virtual Topic * create_writer_topic(
            const EntityParams& params,
            const char * writer_type_name);
    
        virtual TopicDescription * create_reader_topic(
            const EntityParams& params,
            const char * reader_type_name);

    private:
        RequesterUntypedImpl * _requester;
        friend class RequesterUntypedImpl;
    };
};

// --- RequesterImpl: ---------------------------------------------------------

template <typename TReq, typename TRep>
class XMQCPPDllExport RequesterImpl : private RequesterUntypedImpl {
public:

    // --- types: -------------------------------------------------------------

    typedef TReq Request;
    typedef TRep Reply;
    typedef typename dds_type_traits<TReq>::DataWriter RequestDataWriter;
    typedef typename dds_type_traits<TRep>::DataReader ReplyDataReader;
    typedef typename dds_type_traits<TReq>::TypeSupport RequestTypeSupport;
    typedef typename dds_type_traits<TRep>::TypeSupport ReplyTypeSupport;
    typedef typename details::type_support_adapter<TReq> RequestTypeSupportAdapter;
    typedef typename details::type_support_adapter<TRep> ReplyTypeSupportAdapter;
    typedef typename dds_type_traits<TRep>::LoanedSamplesType LoanedSamplesType;

    // --- ctors: -------------------------------------------------------------

    RequesterImpl(const RequesterParams& params);
    virtual ~RequesterImpl();

    // --- send_request methods: ----------------------------------------------

    void send_request_impl(char *);
    void send_request_impl(const char *);
    void send_request_impl(const std::string &);
    void send_request_impl(WriteSampleRef<char *> &);
    void send_request_impl(WriteSampleRef<const char *> &);
    void send_request_impl(WriteSampleRef<std::string> &);
    void send_request_impl(WriteSample<char *> &);
    void send_request_impl(WriteSample<const char *> &);
    void send_request_impl(WriteSample<std::string> &);

    template <class UReq>
    void send_request_impl(WriteSample<UReq> &);

    template <class UReq>
    void send_request_impl(WriteSampleRef<UReq> &);

    template <class UReq>
    void send_request_impl(const UReq &);

    // --- receive/get_reply methods: -----------------------------------------

    inline bool receive_reply(
        connext::Sample<TRep>& reply,
        const DDS_Duration_t& timeout);

    inline bool receive_reply(
        connext::SampleRef<TRep> reply,
        const DDS_Duration_t& timeout);

    inline bool wait_for_replies(
        int min_reply_count,
        const DDS_Duration_t& max_wait);

    inline bool wait_for_replies(
        int min_reply_count,
        const DDS_Duration_t& max_wait,
        const SampleIdentity_t& related_request_id);

    inline bool get_reply(
        connext::Sample<TRep>& reply, bool take);

    inline bool get_reply(
        Sample<TRep>& reply,
        const SampleIdentity_t& related_request_id, bool take);

    inline bool get_reply(
        connext::SampleRef<TRep> reply, bool take);

    inline bool get_reply(
        SampleRef<TRep> reply,
        const SampleIdentity_t& related_request_id, bool take);

    LoanedSamplesType get_replies(int max_samples, bool take);
    LoanedSamplesType get_replies(
        int max_samples, const SampleIdentity_t& related_request_id, bool take);
    LoanedSamplesType receive_replies(const DDS_Duration_t& timeout);
    LoanedSamplesType receive_replies(
        int min_request_count,
        int max_request_count,
        const DDS_Duration_t & max_wait);

    inline void log_and_rethrow(
        const connext::Rethrowable& ex,
        const char * METHOD_NAME);

    // --- query methods: -----------------------------------------------------

    inline RequestDataWriter * get_datawriter() const;
    inline ReplyDataReader * get_datareader() const;
};

// --- RequesterImpl implementation: ------------------------------------------

template <typename TReq, typename TRep>
RequesterImpl<TReq, TRep>::RequesterImpl(const RequesterParams& params) 
    : RequesterUntypedImpl(params,
                           &RequestTypeSupportAdapter::register_type,
                           &ReplyTypeSupportAdapter::register_type,
                           sizeof(TRep),
                           UsesStringDataReader<TRep>::value) 
{
    // For char*, const char*, and std::string we use DDSStringDataReader. 
    // We pass UsesStringDataReader<TRep>::value = 1.
}

template <typename TReq, typename TRep>
RequesterImpl<TReq, TRep>::~RequesterImpl() 
{
}

template <typename TReq, typename TRep>
void RequesterImpl<TReq, TRep>::send_request_impl(char * str)
{
    Request_Type_Must_Be_A_String_Type<UsesStringDataWriter<TReq>::value>();

    WriteParams_t info;
    EntityUntypedImpl::send_sample(
        reinterpret_cast<const void *>(&str), info);
}

template <typename TReq, typename TRep>
void RequesterImpl<TReq, TRep>::send_request_impl(const char * str)
{
    Request_Type_Must_Be_A_String_Type<UsesStringDataWriter<TReq>::value>();

    WriteParams_t info;
    EntityUntypedImpl::send_sample(
        reinterpret_cast<const void *>(&str), info);
}

template <typename TReq, typename TRep>
void RequesterImpl<TReq, TRep>::send_request_impl(const std::string & request)
{
    Request_Type_Must_Be_A_String_Type<UsesStringDataWriter<TReq>::value>();

    WriteParams_t info;
    const char * str = request.c_str();
    EntityUntypedImpl::send_sample(
        reinterpret_cast<const void *>(&str), info);
}

template <typename TReq, typename TRep>
void RequesterImpl<TReq, TRep>::send_request_impl(WriteSampleRef<char *> & request)
{
    Request_Type_Must_Be_A_String_Type<UsesStringDataWriter<TReq>::value>();

    request.info().replace_auto = true;
    const char * str = request.data();
    EntityUntypedImpl::send_sample(
        reinterpret_cast<const void *>(&str), request.info());
}

template <typename TReq, typename TRep>
void RequesterImpl<TReq, TRep>::send_request_impl(WriteSample<char *> & request)
{
    Request_Type_Must_Be_A_String_Type<UsesStringDataWriter<TReq>::value>();

    request.info().replace_auto = true;
    const char * str = request.data();
    EntityUntypedImpl::send_sample(
        reinterpret_cast<const void *>(&str), request.info());
}

template <typename TReq, typename TRep>
void RequesterImpl<TReq, TRep>::send_request_impl(
    WriteSample<std::string>& request)
{
    Request_Type_Must_Be_A_String_Type<UsesStringDataWriter<TReq>::value>();

    request.info().replace_auto = true;
    const char * str = request.c_str();
    EntityUntypedImpl::send_sample(
        reinterpret_cast<const void *>(&str), request.info());
}

template <typename TReq, typename TRep>
void RequesterImpl<TReq, TRep>::send_request_impl(
    WriteSampleRef<std::string>& request)
{
    Request_Type_Must_Be_A_String_Type<UsesStringDataWriter<TReq>::value>();

    request.info().replace_auto = true;
    const char * str = request.data().c_str();
    EntityUntypedImpl::send_sample(
        reinterpret_cast<const void *>(&str), request.info());
}

template <typename TReq, typename TRep>
void RequesterImpl<TReq, TRep>::send_request_impl(
    WriteSampleRef<const char *> & request)
{
    Request_Type_Must_Be_A_String_Type<UsesStringDataWriter<TReq>::value>();

    request.info().replace_auto = true;
    const char * str = request.data();
    EntityUntypedImpl::send_sample(
        reinterpret_cast<const void *>(&str), request.info());
}

template <typename TReq, typename TRep>
void RequesterImpl<TReq, TRep>::send_request_impl(
    WriteSample<const char *> & request)
{
    Request_Type_Must_Be_A_String_Type<UsesStringDataWriter<TReq>::value>();

    request.info().replace_auto = true;
    const char * str = request.data();
    EntityUntypedImpl::send_sample(
        reinterpret_cast<const void *>(&str), request.info());
}

template <typename TReq, typename TRep>
template <class UReq>
void RequesterImpl<TReq, TRep>::send_request_impl(WriteSample<UReq> & request)
{
    Write_Sample_Types_Must_Match_Assertion_Failure<is_same<TReq, UReq>::value>();

    request.info().replace_auto = true;
    EntityUntypedImpl::send_sample(
        reinterpret_cast<const void *>(&request.data()), request.info());
}

template <typename TReq, typename TRep>
template <class UReq>
void RequesterImpl<TReq, TRep>::send_request_impl(WriteSampleRef<UReq> & request)
{
    Write_Sample_Types_Must_Match_Assertion_Failure<is_same<TReq, UReq>::value>();

    request.info().replace_auto = true;
    EntityUntypedImpl::send_sample(
        reinterpret_cast<const void *>(&request.data()), request.info());
}

template <typename TReq, typename TRep>
template <class UReq>
void RequesterImpl<TReq, TRep>::send_request_impl(const UReq & request)
{
    // Compile-type assertion: TReq and URep must be the same type
    Write_Sample_Types_Must_Match_Assertion_Failure<is_same<TReq, UReq>::value>();

    WriteParams_t info;
    EntityUntypedImpl::send_sample(
        reinterpret_cast<const void *>(&request), info);
}

template <typename TReq, typename TRep>
bool RequesterImpl<TReq, TRep>::receive_reply(
    connext::Sample<TRep>& reply,
    const DDS_Duration_t& max_wait)
{
    init_sample_info(reply.info());
    LoanedSamplesType ls = 
        receive_replies(1 /* min */, 1 /* max */, max_wait);

    if (ls.length() == 0) {
        return false;
    }

    copy_sample(reply, ls.data_seq()[0], ls.info_seq()[0]);

    return true;
}

template <typename TReq, typename TRep>
bool RequesterImpl<TReq, TRep>::receive_reply(
    connext::SampleRef<TRep> reply,
    const DDS_Duration_t& max_wait)
{
    init_sample_info(reply.info());
    LoanedSamplesType ls = 
        receive_replies(1 /* min */, 1 /* max */, max_wait);

    if (ls.length() == 0) {
        return false;
    }

    copy_sample_ref(reply, ls.data_seq()[0], ls.info_seq()[0]);

    return true;
}

template <typename TReq, typename TRep> 
typename RequesterImpl<TReq, TRep>::LoanedSamplesType 
RequesterImpl<TReq, TRep>::receive_replies(
    int min_reply_count,
    int max_reply_count,
    const DDS_Duration_t& max_wait)
{
    SampleInfoSeq info_seq;
    void ** dataPtrArray = NULL;
    int dataCount = 0;

    EntityUntypedImpl::receive_sample_loaned(
        &dataPtrArray,
        &dataCount,
        info_seq,
        max_reply_count,
        max_wait,
        min_reply_count);

    if (dataCount == 0) {
        return LoanedSamplesType();
    }

    return create_loaned_samples<TRep>(
        dataPtrArray, dataCount, info_seq, get_datareader());
}


template <typename TReq, typename TRep>
typename RequesterImpl<TReq, TRep>::LoanedSamplesType
RequesterImpl<TReq, TRep>::receive_replies(
    const DDS_Duration_t& timeout)
{
    return receive_replies(1, DDS_LENGTH_UNLIMITED, timeout);
}


template <typename TReq, typename TRep>
bool RequesterImpl<TReq, TRep>::wait_for_replies(
    int min_reply_count,
    const DDS_Duration_t& max_wait)
{
    return EntityUntypedImpl::wait_for_any_sample(
            max_wait, min_reply_count);
}

template <typename TReq, typename TRep>
bool RequesterImpl<TReq, TRep>::wait_for_replies(
    int min_reply_count,
    const DDS_Duration_t& max_wait,
    const SampleIdentity_t& related_request_id)
{
    return RequesterUntypedImpl::wait_for_replies(
            max_wait, min_reply_count, related_request_id);
}


template <typename TReq, typename TRep>
bool RequesterImpl<TReq, TRep>::get_reply(
    connext::Sample<TRep>& reply, bool take)
{
    init_sample_info(reply.info());
    LoanedSamplesType ls = get_replies(1, take);

    if (ls.data_seq().length() == 0) {
        return false;
    }

    copy_sample(reply, ls.data_seq()[0], ls.info_seq()[0]);

    return true;
}

template <typename TReq, typename TRep>
inline bool RequesterImpl<TReq, TRep>::get_reply(
    Sample<TRep>& reply,
    const SampleIdentity_t& related_request_id, bool take)
{
    init_sample_info(reply.info());
    LoanedSamplesType ls = get_replies(1, related_request_id, take);

    if (ls.data_seq().length() == 0) {
        return false;
    }

    copy_sample(reply, ls.data_seq()[0], ls.info_seq()[0]);

    return true;
}

template <typename TReq, typename TRep>
bool RequesterImpl<TReq, TRep>::get_reply(
    connext::SampleRef<TRep> reply, bool take)
{
    init_sample_info(reply.info());
    LoanedSamplesType ls = get_replies(1, take);

    if (ls.data_seq().length() == 0) {
        return false;
    }

    copy_sample_ref(reply, ls.data_seq()[0], ls.info_seq()[0]);

    return true;
}

template <typename TReq, typename TRep>
inline bool RequesterImpl<TReq, TRep>::get_reply(
    SampleRef<TRep> reply,
    const SampleIdentity_t& related_request_id, bool take)
{
    init_sample_info(reply.info());
    LoanedSamplesType ls = get_replies(1, related_request_id, take);

    if (ls.data_seq().length() == 0) {
        return false;
    }

    copy_sample_ref(reply, ls.data_seq()[0], ls.info_seq()[0]);

    return true;
}


template <typename TReq, typename TRep>
typename RequesterImpl<TReq, TRep>::LoanedSamplesType 
RequesterImpl<TReq, TRep>::get_replies(int max_samples, bool take)
{
    SampleInfoSeq info_seq;
    void ** dataPtrArray = NULL;
    int dataCount = 0;

    EntityUntypedImpl::get_sample_loaned(
        &dataPtrArray, &dataCount, info_seq, max_samples, take);

    if (dataCount == 0) {
        // Empty collection
        return LoanedSamplesType();
    }

    return create_loaned_samples<TRep>(
        dataPtrArray, dataCount, info_seq, get_datareader());
}

template <typename TReq, typename TRep>
typename RequesterImpl<TReq, TRep>::LoanedSamplesType 
RequesterImpl<TReq, TRep>::get_replies(
    int max_samples, 
    const SampleIdentity_t& related_request_id,
    bool take)
{
    SampleInfoSeq info_seq;
    void ** dataPtrArray = NULL;
    int dataCount = 0;

    RequesterUntypedImpl::get_reply_loaned(
        &dataPtrArray, &dataCount, info_seq, 1, related_request_id, take);

    if (dataCount == 0) {
        // Empty collection
        return LoanedSamplesType();
    }

    return create_loaned_samples<TRep>(
        dataPtrArray, dataCount, info_seq, get_datareader());
}


template <typename TReq, typename TRep>
typename RequesterImpl<TReq, TRep>::RequestDataWriter *
RequesterImpl<TReq, TRep>::get_datawriter() const
{
    return dds_type_traits<TReq>::DataWriter::narrow(
        RequesterUntypedImpl::get_datawriter());
}

template <typename TReq, typename TRep>
typename RequesterImpl<TReq, TRep>::ReplyDataReader *
RequesterImpl<TReq, TRep>::get_datareader() const
{
    return dds_type_traits<TRep>::DataReader::narrow(
        RequesterUntypedImpl::get_datareader());
}

template <typename TReq, typename TRep>
void RequesterImpl<TReq, TRep>::log_and_rethrow(
    const connext::Rethrowable& ex,
    const char * METHOD_NAME)
{
    EntityUntypedImpl::log_and_rethrow(ex, "Requester", METHOD_NAME);
}


} // namespace details
} // namespace connext

#endif /* connext_cpp_requester_details_h */
