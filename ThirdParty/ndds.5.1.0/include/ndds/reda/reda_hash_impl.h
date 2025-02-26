/* (c) Copyright, Real-Time Innovations, Inc. 2003-2009. All rights reserved. */
/*
 * @(#)reda_hash_impl.h    generated by: makeheader    Sat Nov 23 02:38:00 2013
 *
 *		built from:	hash_impl.ifc
 */

#ifndef reda_hash_impl_h
#define reda_hash_impl_h


#ifdef __cplusplus
    extern "C" {
#endif



#define RTI_ABS(x)      (((x) >= 0) ? (x) : (-(x)))

#define REDAHash_hashSimpleIntMacro(key, numHashBuckets) \
    ( RTI_ABS(*((int *)(key)) % (numHashBuckets)) )

#define REDAHash_hashSimpleDoubleIntMacro(key, numHashBuckets) \
    ( RTI_ABS( (*((int *)(key)) + *(((int *)(key))+1))  % (numHashBuckets)) )

#define REDAHash_hashSimpleTripleIntMacro(key, numHashBuckets) \
    ( RTI_ABS( (*((int *)(key)) + *(((int *)(key))+1) + *(((int *)(key))+2))  % \
        (numHashBuckets)) )

#define REDAHash_hashSimpleQuadIntMacro(key, numHashBuckets) \
    ( RTI_ABS( (*((int *)(key)) + *(((int *)(key))+1) + *(((int *)(key))+2) + \
        *(((int *)(key))+3))  % (numHashBuckets)) )

#define REDAHash_hashSimpleFiveIntMacro(key, numHashBuckets) \
    ( RTI_ABS( (*((int *)(key)) + *(((int *)(key))+1) + *(((int *)(key))+2) + \
        *(((int *)(key))+3) + *(((int *)(key))+4)) % (numHashBuckets)) )

#define REDAHash_callFncOrUseMacro(hashDefinition, key) \
   ((hashDefinition->hashFunction == REDAHash_hashSimpleInt) ? \
    REDAHash_hashSimpleIntMacro(key, hashDefinition->numberOfBuckets) : \
    ((hashDefinition->hashFunction == REDAHash_hashSimpleDoubleInt) ? \
     REDAHash_hashSimpleDoubleIntMacro(key, hashDefinition->numberOfBuckets) : \
     ((hashDefinition->hashFunction == REDAHash_hashSimpleTripleInt) ? \
      REDAHash_hashSimpleTripleIntMacro(key, hashDefinition->numberOfBuckets) :\
      ((hashDefinition->hashFunction==REDAHash_hashSimpleQuadInt) ? \
       REDAHash_hashSimpleQuadIntMacro(key, hashDefinition->numberOfBuckets) : \
       ((hashDefinition->hashFunction==REDAHash_hashSimpleFiveInt) ? \
        REDAHash_hashSimpleFiveIntMacro(key, hashDefinition->numberOfBuckets) : \
        hashDefinition->hashFunction(key, hashDefinition->numberOfBuckets))))))

#define REDAHash_computeHash(hashDefinition, key) \
    (((hashDefinition)->numberOfBuckets <= 1) ? 0 : \
     REDAHash_callFncOrUseMacro((hashDefinition), (key)))


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* reda_hash_impl_h */
