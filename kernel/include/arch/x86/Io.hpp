/*
 * Wrap OS
 * Copyright (C) 2010 Dmitry 'skwee' Kudryavtsev
 *
 * See COPYING file for license
 */
#ifndef _WRAP_KRN_ARCH_X86_IO_HPP_
#define _WRAP_KRN_ARCH_X86_IO_HPP_

#include <arch/x86/types.hpp>

namespace wrap{
	namespace io{
		static inline void outportb(uint16t port, uint8t value){
			__asm__ __volatile__("outb %1, %0" :  :"dN"(port), "a"(value));
		}

		static inline uint8t inportb(uint16t port){
			uint8t ret;
			__asm__ __volatile__("inb %1, %0" : "=a"(ret) : "dN"(port));
			return ret;
		}
	}
}

#endif
