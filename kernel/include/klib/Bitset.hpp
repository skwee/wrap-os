/*
 * Wrap OS
 * Copyright (C) 2010 Dmitry 'skwee' Kudryavtsev
 *
 * See COPYING file for license
 */
#ifndef _WRAP_KRN_KLIB_BITSET_HPP_
#define _WRAP_KRN_KLIB_BITSET_HPP_

#include <arch/types.hpp>
#include <klib/memory.hpp>

namespace wrap{
	namespace klib{

#define BITSET_BIT_INDEX(bit)	(bit / 32)
#define BITSET_BIT_OFFSET(bit)	(bit % 32)

		/**
		 * Bitset data type.
		 * @param Allocator The type of the allocator to use.
		 */
		template<typename Allocator>
		class Bitset{
		public:
			static const uint32t invalid_block = static_cast<uint32t>(-1); /**< Invalid block. */

			/** Constructor. DOES NOT Creates new bitset. */
			Bitset():mBitset(0),mTotalBits(0){}

			/** Destructor. */
			~Bitset() { Destroy(); }

			/** Create new bitset. */
			inline void Create(uint32t total_bits);

			/** Destroy bitset. */
			inline void Destroy();

			/** Set specific bit to used. */
			inline void Set(uint32t bit);

			/** Clear specific bit. */
			inline void Clear(uint32t bit);

			/** Test specific bit. */
			inline bool Test(uint32t bit);

			/** Get first free bit index. */
			inline uint32t FirstFree();

		private:
			uint32t*	mBitset;		/**< The bitset itself. */
			uint32t		mTotalBits;		/**< Total bits in bitset. */
		};

		template<typename Allocator>
		void Bitset<Allocator>::Create(uint32t total_bits){
			mTotalBits = total_bits;
			uint32t needed_cells = mTotalBits / 32;
			mBitset = reinterpret_cast<uint32t*>(Allocator::Allocate(needed_cells));
			memset(mBitset, 0, needed_cells);
		}

		template<typename Allocator>
		void Bitset<Allocator>::Destroy(){
			if(mBitset != 0){
				Allocator::Free(mBitset);
			}
		}

		template<typename Allocator>
		void Bitset<Allocator>::Set(uint32t bit){
			KASSERT(mBitset != 0 && bit <= mTotalBits);
			mBitset[BITSET_BIT_INDEX(bit)] |= (1 << BITSET_BIT_OFFSET(bit));
		}

		template<typename Allocator>
		void Bitset<Allocator>::Clear(uint32t bit){
			KASSERT(mBitset != 0 && bit <= mTotalBits);
			mBitset[BITSET_BIT_INDEX(bit)] &= ~(1 << BITSET_BIT_OFFSET(bit));
		}

		template<typename Allocator>
		bool Bitset< Allocator>::Test(uint32t bit){
			KASSERT(mBitset != 0 && bit <= mTotalBits);
			return (mBitset[BITSET_BIT_INDEX(bit)] & (1 << BITSET_BIT_OFFSET(bit)));
		}

		template<typename Allocator>
		uint32t Bitset<Allocator>::FirstFree(){
			uint32t total_cells = BITSET_BIT_INDEX(mTotalBits);

			for(uint32t i = 0; i < total_cells; ++i){
				if(mBitset[i] == 0xFFFFFFFF) continue;

				for(uint32t j = 0; j < 32; ++j){
					if(!(mBitset[i] & (1 << j))){
						return i * 32 + j;
					}
				}
			}

			return invalid_block;
		}

	}
}

#endif
