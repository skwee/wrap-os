/*
 * Wrap OS
 * Copyright (C) 2010 Dmitry 'skwee' Kudryavtsev
 *
 * See COPYING file for license
 */
#ifndef _WRAP_KRN_MEMORY_PLACEMENT_ALLOCATOR_HPP_
#define _WRAP_KRN_MEMORY_PLACEMENT_ALLOCATOR_HPP_

#include <arch/types.hpp>
#include <memory/MemoryMap.hpp>

namespace wrap {
	namespace memory {
		namespace allocator {

			/**
			 * Placement allocator.
			 */
			class PlacementAllocator {
			public:
				/* Allocate block. */
				static void* Allocate(size_t size);

				/* Allocate aligned block. */
				static void* AllocateAligned(size_t size);

				/* Free block. */
				static void Free(void* UNUSED(addr)) {}

				/* Get placement address. */
				static memory::virtual_address GetPlacementAddress() { return static_cast<memory::virtual_address>(mPlacementAddress); }

			private:
				static uint32t mPlacementAddress; /**< Current location of placement address */
			};

		}
	}
}

#endif
