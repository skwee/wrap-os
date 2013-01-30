/*
 * Wrap OS
 * Copyright (C) 2010 Dmitry 'skwee' Kudryavtsev
 *
 * See COPYING file for license
 */
#include <klib/memory.hpp>

namespace wrap{
	namespace klib{

		void memset(void* ptr, char value, size_t num){
			char* tmp = (char*)ptr;
			while(num-- != 0){
				*tmp = value;
				tmp++;
			}
		}

	}
}
