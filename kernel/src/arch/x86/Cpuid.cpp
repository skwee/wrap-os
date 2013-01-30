/*
 * Wrap OS
 * Copyright (C) 2010 Dmitry 'skwee' Kudryavtsev
 *
 * See COPYING file for license
 */
#include <arch/x86/cpuid.hpp>
#include <klib/memory.hpp>

namespace wrap{
	namespace arch{

		void cpuid(CpuidCode code , uint32t out[4]){
			__asm__ __volatile__("cpuid" : "=a"(*out), "=b"(*(out + 1)),
					"=c"(*(out + 2)), "=d"(*(out + 3)) : "0"(code));
		}

	}
}
