/* (c) Copyright, Real-Time Innovations, Inc. 2003-2009. All rights reserved. */
/*
 * @(#)osapi_thread_impl.h    generated by: makeheader    Sat Nov 23 02:37:47 2013
 *
 *		built from:	thread_impl.ifc
 */

#ifndef osapi_thread_impl_h
#define osapi_thread_impl_h


  
#ifdef cplusplus
    extern "C" {
#endif


#define RTIOsapiThread_spin(spinCount)		\
{														\
	RTI_UINT64 spin;									\
	RTI_UINT64 ad, bd, cd;								\
	volatile RTI_UINT64 * a, * b, * c;					\
	a = &ad;											\
	b = &bd;											\
	c = &cd;											\
	for (spin = 0; spin < (spinCount); ++spin) {		\
		*a = 3;											\
		*b = 1;											\
		*c = (*a/(*b))*spin;							\
	}													\
}


#ifdef cplusplus
    }	/* extern "C" */
#endif

#endif /* osapi_thread_impl_h */
