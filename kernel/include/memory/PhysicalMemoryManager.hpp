/*
 * Wrap OS
 * Copyright (C) 2010 Dmitry 'skwee' Kudryavtsev
 *
 * See COPYING file for license
 */
#ifndef _WRAP_KRN_ARCH_X86_MM_PHYSICAL_MEMORY_MANAGER_HPP_
#define _WRAP_KRN_ARCH_X86_MM_PHYSICAL_MEMORY_MANAGER_HPP_

#include <arch/types.hpp>
#include <memory/MemoryMap.hpp>

namespace wrap {
	namespace memory {

		/** Initialize physical memory manager.  */
		void pmm_init(uint32t total_physical_memory);

		/** Allocate one block. */
		physical_address pmm_alloc_block();

		/** Free block. */
		void pmm_free_block(physical_address addr);

		/** Reserve single block. */
		void pmm_reserve_block(uint32t block);

		/** Reserve memory region. */
		void pmm_reserve_region(physical_address start_addr, physical_address end_addr);
	}
}

#endif
