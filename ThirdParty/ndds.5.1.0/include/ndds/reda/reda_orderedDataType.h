/* (c) Copyright, Real-Time Innovations, Inc. 2003-2009. All rights reserved. */
/*
 * @(#)reda_orderedDataType.h    generated by: makeheader    Sat Nov 23 02:38:02 2013
 *
 *		built from:	orderedDataType.ifc
 */

#ifndef reda_orderedDataType_h
#define reda_orderedDataType_h


  #ifndef reda_dll_h
    #include "reda/reda_dll.h"
  #endif
  #ifndef osapi_alignment_h
    #include "osapi/osapi_alignment.h"
  #endif
#ifdef __cplusplus
    extern "C" {
#endif

struct REDAOrderedDataType; /* forward declare to appease compiler */

struct REDABuffer; /* forward declare to appease compiler */

typedef int (*REDAOrderedDataTypeCompareFunction)(const void *left,
							 const void *right);

typedef int (*REDAOrderedDataTypeCompareWithUserDataFunction)(const void *left,
                                                                     const void *right,
                                                                     const void * userData);

typedef void
(*REDAOrderedDataTypePrintFunction)(const void *ptr, const char *desc,
				    int indent);

extern REDADllExport int
REDAOrderedDataType_getInstanceSize(const struct REDAOrderedDataType *me);

extern REDADllExport RTIOsapiAlignment
REDAOrderedDataType_getInstanceAlignment(const struct REDAOrderedDataType *me);

extern REDADllExport REDAOrderedDataTypeCompareFunction
REDAOrderedDataType_getCompareFnc(const struct REDAOrderedDataType *me);

extern REDADllExport REDAOrderedDataTypePrintFunction
REDAOrderedDataType_getPrintFnc(const struct REDAOrderedDataType *me);

extern REDADllExport void
REDAOrderedDataType_define(struct REDAOrderedDataType *me, 
			   int instanceSize,
			   RTIOsapiAlignment instanceAlignment,
			   REDAOrderedDataTypeCompareFunction compareFnc,
			   REDAOrderedDataTypePrintFunction printFnc);

extern REDADllExport 
REDAOrderedDataTypeCompareFunction REDAOrderedDataType_defineCompareFromSize(
    int size);

extern REDADllExport
int REDAOrderedDataType_compareInt(const void *left, const void *right);

extern REDADllExport
int REDAOrderedDataType_compareUInt(const void *left, const void *right);

extern REDADllExport char *
REDAOrderedDataType_toStringInt(const void *me, struct REDABuffer *buf);

extern REDADllExport
int REDAOrderedDataType_compareDoubleInt(const void *left, const void *right);

extern REDADllExport
int REDAOrderedDataType_compareDoubleUInt(const void *left, const void *right);

extern REDADllExport char *
REDAOrderedDataType_toStringDoubleInt(const void *me, struct REDABuffer *buf);

extern REDADllExport
int REDAOrderedDataType_compareTripleInt(const void *left, const void *right);

extern REDADllExport
int REDAOrderedDataType_compareTripleUInt(const void *left, const void *right);

extern REDADllExport char *
REDAOrderedDataType_toStringTripleInt(const void *me, struct REDABuffer *buf);

extern REDADllExport
int REDAOrderedDataType_compareQuadInt(const void *left, const void *right);

extern REDADllExport
int REDAOrderedDataType_compareQuadUInt(const void *left, const void *right);

extern REDADllExport
int REDAOrderedDataType_compareFiveUInt(const void *left, const void *right);

extern REDADllExport
int REDAOrderedDataType_compareSixUInt(const void *left, const void *right);

extern REDADllExport
int REDAOrderedDataType_comparePointer(const void *left, const void *right);

extern REDADllExport
int REDAOrderedDataType_compareQuadPointer(const void *left, const void *right);

extern REDADllExport
int REDAOrderedDataType_compareUnsupported(const void *left, const void *right);

extern REDADllExport char *
REDAOrderedDataType_toStringQuadInt(const void *me, struct REDABuffer *buf);

extern REDADllExport char *
REDAOrderedDataType_toStringFiveInt(const void *me, struct REDABuffer *buf);

extern REDADllExport const void *REDAOrderedDataType_compareUsingFnc(
    REDAOrderedDataTypeCompareFunction compareFnc,
    const void *leftData, const void *rightData);

extern REDADllExport 
void REDAOrderedDataType_printInt(const void *me, const char *desc,
				  int indent);

extern REDADllExport 
void REDAOrderedDataType_printDoubleInt(const void *me, const char *desc,
					int indent);

extern REDADllExport 
void REDAOrderedDataType_printTripleInt(const void *me, const char *desc,
					int indent);

extern REDADllExport 
void REDAOrderedDataType_printQuadInt(const void *me, const char *desc,
				      int indent);

extern REDADllExport 
void REDAOrderedDataType_printFiveInt(const void *me, const char *desc,
				      int indent);

extern REDADllExport 
void REDAOrderedDataType_printPointer(const void *me, const char *desc,
				      int indent);

extern REDADllExport 
void * REDAOrderedDataType_binarySearch(const void * key,
                                        const void * base,
                                        int num,
                                        size_t size,
                                        REDAOrderedDataTypeCompareFunction compareFnc);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

/* pick up performance boosting macro */
  #include "reda/reda_orderedDataType_impl.h"

#endif /* reda_orderedDataType_h */
