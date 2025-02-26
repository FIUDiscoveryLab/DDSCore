
/*
  WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

  This file was generated from HelloWorld.idl using "rtiddsgen".
  The rtiddsgen tool is part of the RTI Connext distribution.
  For more information, type 'rtiddsgen -help' at a command shell
  or consult the RTI Connext manual.
*/

#ifndef HelloWorld_1436885481_h
#define HelloWorld_1436885481_h

#ifndef NDDS_STANDALONE_TYPE
    #ifdef __cplusplus
        #ifndef ndds_cpp_h
            #include "ndds/ndds_cpp.h"
        #endif
    #else
        #ifndef ndds_c_h
            #include "ndds/ndds_c.h"
        #endif
    #endif
#else
    #include "ndds_standalone_type.h"
#endif


#define HelloWorld_LAST_MEMBER_ID 0
#ifdef __cplusplus
extern "C" {
#endif

        
extern const char *HelloWorldTYPENAME;
        

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
    struct HelloWorldSeq;

#ifndef NDDS_STANDALONE_TYPE
    class HelloWorldTypeSupport;
    class HelloWorldDataWriter;
    class HelloWorldDataReader;
#endif

#endif

            
    typedef struct HelloWorld
{

    DDS_Long  data;

            
} HelloWorld;                        
    
                            
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, start exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport __declspec(dllexport)
#endif

    
NDDSUSERDllExport DDS_TypeCode* HelloWorld_get_typecode(void); /* Type code */
    

DDS_SEQUENCE(HelloWorldSeq, HelloWorld);
        
NDDSUSERDllExport
RTIBool HelloWorld_initialize(
        HelloWorld* self);
        
NDDSUSERDllExport
RTIBool HelloWorld_initialize_ex(
        HelloWorld* self,
        RTIBool allocatePointers,RTIBool allocateMemory);
        
NDDSUSERDllExport
RTIBool HelloWorld_initialize_w_params(
        HelloWorld* self,
        const struct DDS_TypeAllocationParams_t * allocParams);

NDDSUSERDllExport
void HelloWorld_finalize(
        HelloWorld* self);
                        
NDDSUSERDllExport
void HelloWorld_finalize_ex(
        HelloWorld* self,RTIBool deletePointers);
       
NDDSUSERDllExport
void HelloWorld_finalize_w_params(
        HelloWorld* self,
        const struct DDS_TypeDeallocationParams_t * deallocParams);
        
NDDSUSERDllExport
void HelloWorld_finalize_optional_members(
        HelloWorld* self, RTIBool deletePointers);        
        
NDDSUSERDllExport
RTIBool HelloWorld_copy(
        HelloWorld* dst,
        const HelloWorld* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
  /* If the code is building on Windows, stop exporting symbols.
   */
  #undef NDDSUSERDllExport
  #define NDDSUSERDllExport
#endif



#endif /* HelloWorld_1436885481_h */
