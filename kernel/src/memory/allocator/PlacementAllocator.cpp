/*
 * Wrap OS
 * Copyright (C) 2010 Dmitry 'skwee' Kudryavtsev
 *
 * See COPYING file for license
 */
#include <memory/allocator/PlacementAllocator.hpp>
#include <memory/MemoryMap.hpp>

//end of kernel
extern unsigned long _end;

namespace wrap {
	namespace memory {
		namespace allocator {

			//set placement address
			uint32t PlacementAllocator::mPlacementAddress = (uint32t) &_end;

			void* PlacementAllocator::Allocate(size_t size) {
				uint32t addr = mPlacementAddress;
				mPlacementAddress += size;
				return reinterpret_cast<void*> (addr);
			}

			void* PlacementAllocator::AllocateAligned(size_t size) {
				//align to block boundary
				if ((mPlacementAddress & (block_size - 1)) != 0) {
					mPlacementAddress &= (0xFFFFFFFF - block_size + 1);
					mPlacementAddress += block_size;
				}
				return Allocate(size);
			}

		}
	}
}
