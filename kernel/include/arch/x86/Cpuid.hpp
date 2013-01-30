/*
 * Wrap OS
 * Copyright (C) 2010 Dmitry 'skwee' Kudryavtsev
 *
 * See COPYING file for license
 */
#ifndef _WRAP_KRN_ARCH_X86_CPUID_HPP_
#define _WRAP_KRN_ARCH_X86_CPUID_HPP_

#include <arch/x86/types.hpp>

namespace wrap{
	namespace arch{

		enum CpuidCode{
		};
		/* Check if cpuid is supported. Return value 0 = not supported, > 0 supported */
		extern "C" int cpuid_supported();

		/* CPUID command. out contains the output of the 4 registers (eax-ebx-ecx-edx) (not all of them might be used) */
		void cpuid(CpuidCode code , uint32t out[4]);

	}
}

#endif
