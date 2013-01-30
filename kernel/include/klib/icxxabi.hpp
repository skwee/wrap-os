/*
 * Wrap OS
 * Copyright (C) 2010 Dmitry 'skwee' Kudryavtsev
 *
 * See COPYING file for license
 */
#ifndef _WRAP_KRN_KLIB_ICXXABI_H_
#define _WRAP_KRN_KLIB_ICXXABI_H_

//maximum number of function that can be registered with atexit()
#define ATEXIT_MAX_FUNCS	128

#ifdef __cplusplus
extern "C" {
#endif

	typedef unsigned uarch_t;

	/** ABI requires 64bit type */
	__extension__ typedef int __guard __attribute__((mode(__DI__)));

	struct atexit_func_entry_t{
		void (*destructor_func)(void *);
		void* obj_ptr;
		void* dso_handle;
	};

	int __cxa_atexit(void (*f)(void *), void* objptr, void* dso);
	//void __cxa_finalize(void *f);
	int __cxa_guard_acquire(__guard *);
	void __cxa_guard_release(__guard *);
	//void __cxa_guard_abort(__guard *);

#ifdef __cplusplus
}
#endif

#endif
