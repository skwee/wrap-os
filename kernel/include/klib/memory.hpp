/*
 * Wrap OS
 * Copyright (C) 2010 Dmitry 'skwee' Kudryavtsev
 *
 * See COPYING file for license
 */
#ifndef _WRAP_KRN_KLIB_MEMORY_HPP_
#define _WRAP_KRN_KLIB_MEMORY_HPP_

#include <arch/x86/types.hpp>

namespace wrap{
	namespace klib{

		void memset(void* ptr, char value, size_t num);

	}
}

#endif
