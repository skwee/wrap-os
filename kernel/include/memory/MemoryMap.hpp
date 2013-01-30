/*
 * Wrap OS
 * Copyright (C) 2010 Dmitry 'skwee' Kudryavtsev
 *
 * See COPYING file for license
 */
#ifndef _WRAP_KRN_MEMORY_MEMORY_MAP_HPP_
#define _WRAP_KRN_MEMORY_MEMORY_MAP_HPP_

#include <arch/types.hpp>

namespace wrap{
	namespace memory{
		typedef uint32t physical_address;
		typedef uint32t virtual_address;

		static const uint32t	block_size 	= 4096;
		static const uint32t	page_size	= 4096;

		static const uint32t	kernel_stack_size = 4096;

		namespace addr{
			/** Real mode interrupt vector table */
			static const physical_address ivt_start 		= 0x00000000;
			static const physical_address ivt_end 			= 0x000003FF;

			/** BIOS data area */
			static const physical_address bda_start 		= 0x00000400;
			static const physical_address bda_end			= 0x000004FF;

			/** Extended BIOS area */
			static const physical_address ebda_start		= 0x0009FC00;
			static const physical_address ebda_end			= 0x0009FFFF;

			/** VGA Frame buffer */
			static const physical_address vga_fb_start		= 0x000A0000;
			static const physical_address vga_fb_end		= 0x000AFFFF;

			/** VGA Text monochrome */
			static const physical_address vga_tm_start		= 0x000B0000;
			static const physical_address vga_tm_end		= 0x000B7FFF;

			/** VGA text color */
			static const physical_address vga_tc_start		= 0x000B8000;
			static const physical_address vga_tc_end		= 0x000BFFFF;

			/** Video BIOS (ROM) */
			static const physical_address video_bios_start	= 0x000C0000;
			static const physical_address video_bios_end	= 0x000C7FFF;

			/** BIOS Shadow area (ROM) */
			static const physical_address bios_shadow_start	= 0x000C8000;
			static const physical_address bios_shadow_end	= 0x000EFFFF;

			/** System BIOS (ROM) */
			static const physical_address smbios_start		= 0x000F0000;
			static const physical_address smbios_end		= 0x000FFFFF;

			static const virtual_address kernel_stack_bottom	= 0xDFFFFFFF;
			static const virtual_address kernel_stack_top		= (kernel_stack_bottom - kernel_stack_size + 1);
			static const virtual_address kernel_stack_guard		= (kernel_stack_top - page_size);

			static const virtual_address kernel_base_address	= 0xC0000000;
			static const physical_address kernel_phys_address	= 0x00100000;
		}

#define phys_to_virt(x) (x) + wrap::memory::addr::kernel_base_address
#define virt_to_phys(x) (x) - wrap::memory::addr::kernel_base_address
	}
}

#endif
