/*
 * Wrap OS
 * Copyright (C) 2010 Dmitry 'skwee' Kudryavtsev
 *
 * See COPYING file for license
 */
#ifndef _WRAP_KRN_ARCH_X86_CPU_HPP_
#define _WRAP_KRN_ARCH_X86_CPU_HPP_

#include <arch/x86/types.hpp>

namespace wrap {
	namespace arch {
		namespace cpu {
			static inline void halt() {
				__asm__ __volatile__("hlt");
			}

			static inline void intr_enable() {
				__asm__ __volatile__("sti; nop");
			}

			static inline void intr_disable() {
				__asm__ __volatile__("cli");
			}

			static inline uint32t read_cr0() {
				uint32t r;
				__asm__ __volatile__("mov %%cr0, %0" : "=r"(r));
				return r;
			}

			static inline uint32t read_cr2() {
				uint32t r;
				__asm__ __volatile__("mov %%cr2, %0" : "=r"(r));
				return r;
			}

			static inline uint32t read_cr3() {
				uint32t r;
				__asm__ __volatile__("mov %%cr3, %0" : "=r"(r));
				return r;
			}

			static inline uint32t read_cr4() {
				uint32t r;
				__asm__ __volatile__("mov %%cr4, %0" : "=r"(r));
				return r;
			}

			static inline void write_cr0(uint32t v) {
				__asm__ __volatile__("mov %0, %%cr0" : : "r"(v));
			}

			static inline void write_cr3(uint32t v) {
				__asm__ __volatile__("mov %0, %%cr3" : : "r"(v));
			}

			static inline void write_cr4(uint32t v) {
				__asm__ __volatile__("mov %0, %%cr4" : : "r"(v));
			}
		}

	/*
	 * http://en.wikipedia.org/wiki/Control_register
	 * ------------------------ CR0 ------------------------
	 * bit 31 PG - Paging 				= If 1 enable paging and use CR3, else disable paging.
	 * bit 30 CD - Cache disable		= Globally enable/disable the memory cache.
	 * bit 29 NW - Non-write through	= Globally enable/disable write-back caching.
	 * bit 18 AM - Alignment mask		= Alignment check enabled if AM set, AC flag set
	 * 									  	(in EFLAGS register, and privilege level is 3)
	 * bit 16 WP - Write protect		= Determines whether the CPU can write to pages
	 * 									  	marked read-only
	 * bit  5 NE - Numeric error		= Enable internal x87 floating point error
	 * 									  	reporting when set, else enables PC style x87
	 * 										error detection
	 * bit  4 ET - Extension type		= On the 386, it allowed to specify whether the
	 * 										external math coprocessor was an 80287 or 80387
	 * bit  3 TS - Task Switched		= Allows saving x87 task context only after x87
	 * 										instruction used after task switch
	 * bit  2 EM - Emulation			= If set, no x87 floating point unit present,
	 * 										if clear, x87 FPU present
	 * bit  1 MP - Monitor co-processor	= Controls interaction of WAIT/FWAIT instructions
	 * 										with TS flag in CR0
	 * bit  0 PE - Protected-mode enabled = If 1, system is in protected mode,
	 * 										else system is in real mode
	 *
	 * ------------------------ CR1 ------------------------
	 * Reserved
	 *
	 * ------------------------ CR2 ------------------------
	 * Contains a value called Page Fault Linear Address (PFLA).
	 * When a page fault occurs, the address the program attempted to access
	 * is stored in the CR2 register.
	 *
	 * ------------------------ CR3 ------------------------
	 * Used when virtual addressing is enabled, hence when the PG bit is set in CR0.
	 * CR3 enables the processor to translate virtual addresses into physical addresses
	 * by locating the page directory and page tables for the current task. Typically,
	 * the upper 20 bits of CR3 become the page directory base register (PDBR).
	 *
	 * ------------------------ CR4 ------------------------
	 * Used in protected mode to control operations such as virtual-8086 support,
	 * enabling I/O breakpoints, page size extension and machine check exceptions.
	 * bit 14 SMXE			- SMX enable
	 * bit 13 VMXE			- VMX enable
	 * bit 10 OSXMMEXCPT	- Operating System Support for Unmasked SIMD Floating-Point Exceptions
	 * 							If set, enables unmasked SSE exceptions.
	 * bit  9 OSFXSR		- Operating system support for FXSAVE and FXSTOR instructions
	 * 							If set, enables SSE instructions and fast FPU save & restore
	 * bit  8 PCE			- Performance-Monitoring Counter enable
	 * 							If set, RDPMC can be executed at any privilege level, else
	 * 							RDPMC can only be used in ring 0.
	 * bit  7 PGE			- Page Global Enabled
	 * 							If set, address translations (PDE or PTE records) may be
	 * 							shared between address spaces.
	 * bit  6 MCE			- Machine Check Exception
	 * 							If set, enables machine check interrupts to occur.
	 * bit  5 PAE			- Physical Address Extension
	 * 							If set, changes page table layout to translate 32-bit virtual
	 * 							addresses into extended 36-bit physical addresses.
	 * bit  4 PSE			- Page Size Extensions
	 * 							If unset, page size is 4 KB, else page size is increased to 4 MB
	 * 							(or with PAE set, 2 MB).
	 * bit  3 DE			- Debugging Extensions
	 * bit  2 TSD			- Time Stamp Disable
	 * 							If set, RDTSC instruction can only be executed when in ring 0,
	 * 							otherwise RDTSC can be used at any privilege level.
	 * bit  1 PVI			- Protected-mode Virtual Interrupts
	 * 							If set, enables support for the virtual interrupt flag (VIF)
	 * 							in protected mode.
	 * bit  0 VME			- Virtual 8086 Mode Extensions
	 * 							If set, enables support for the virtual interrupt flag (VIF)
	 * 							in virtual-8086 mode.
	 */

	}
}

#endif
