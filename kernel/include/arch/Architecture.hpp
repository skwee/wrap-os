/*
 * Wrap OS
 * Copyright (C) 2010 Dmitry 'skwee' Kudryavtsev
 *
 * See COPYING file for license
 */
#ifndef _WRAP_KRN_ARCH_ARCHITECTURE_HPP_
#define _WRAP_KRN_ARCH_ARCHITECTURE_HPP_

#if defined(ARCH_i386) || defined(ARCH_i586)
#include <arch/x86/DescriptorTable.hpp>
#include <arch/x86/Pic.hpp>
#include <arch/x86/Pit.hpp>
#else
#error "Invalid or not supported architecture defined"
#endif

namespace wrap{
	namespace arch{
		inline void initialize(uint32t pit_frequency, intr_handler_t pit_handler){
			gdt_init();
			idt_init();
			pic_init();
			pit_init(pit_frequency, pit_handler);
		}
	}
}

#endif
