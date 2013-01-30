/*
 * Wrap OS
 * Copyright (C) 2010 Dmitry 'skwee' Kudryavtsev
 *
 * See COPYING file for license
 */
#include <memory/PhysicalMemoryManager.hpp>
#include <klib/Bitset.hpp>
#include <memory/allocator/PlacementAllocator.hpp>

namespace wrap{
	namespace memory{

		static uint32t									_maxMemory;
		klib::Bitset<allocator::PlacementAllocator> 	_memoryMap;

		void pmm_init(uint32t total_physical_memory){
			_maxMemory = total_physical_memory;
			_memoryMap.Create(_maxMemory / block_size);
		}

		physical_address pmm_alloc_block(){
			//find first free block
			uint32t block = _memoryMap.FirstFree();

			//check if block is valid
			if(block == klib::Bitset<allocator::PlacementAllocator>::invalid_block){
				//TODO Panic!!
			}

			//mark block as used
			_memoryMap.Set(block);

			//return block address
			return static_cast<physical_address>(block * block_size);
		}

		void pmm_free_block(physical_address addr){
			//get block number
			uint32t block = addr / block_size;

			//make sure this block was marked as used before
			if(_memoryMap.Test(block)){
				//TODO PANIC!!!
			}

			//clean block
			_memoryMap.Clear(block);
		}

		void pmm_reserve_block(uint32t block){
			_memoryMap.Set(block);
		}

		void pmm_reserve_region(physical_address start_addr, physical_address end_addr){
			//get start and end block
			uint32t start = start_addr / block_size;
			uint32t end = end_addr / block_size;

			for(uint32t i = start; i <= end; ++i){
				_memoryMap.Set(i);
			}
		}

	}
}
