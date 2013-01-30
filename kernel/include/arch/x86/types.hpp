/*
 * Wrap OS
 * Copyright (C) 2010 Dmitry 'skwee' Kudryavtsev
 *
 * See COPYING file for license
 */
#ifndef _WRAP_KRN_ARCH_X86_TYPES_HPP_
#define _WRAP_KRN_ARCH_X86_TYPES_HPP_

namespace wrap {

#ifndef NULL
#define NULL ((void*)0)
#endif

	typedef unsigned int size_t;

	typedef unsigned char uint8t;
	typedef unsigned short uint16t;
	typedef unsigned long uint32t;

	typedef signed char int8t;
	typedef signed short int16t;
	typedef signed long int32t;

	enum SelectorType{
		SelectorKernelCode	= 0x08,
		SelectorKernelData	= 0x10
	};

	//TODO finish
	#define KASSERT(exp)

}

#endif
