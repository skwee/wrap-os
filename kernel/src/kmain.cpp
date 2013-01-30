/*
 * Wrap OS
 * Copyright (C) 2010 Dmitry 'skwee' Kudryavtsev
 *
 * See COPYING file for license
 */
#include <kmain.h>
#include <arch/Architecture.hpp>
#include <memory/PhysicalMemoryManager.hpp>

extern unsigned long _start_ctors, _end_ctors, _start_dtors, _end_dtors;

static void kpit_handler(wrap::arch::interrupt_registers_t __attribute__((unused))regs){
}

/** Kernel entry point. */
static void kentry(multiboot_info_t* mbi, unsigned long kernel_stack_bottom);

// kernel loader
void kloader(multiboot_info_t* mbi, unsigned long kernel_stack_bottom) {
	//call static constructors
	for(unsigned long* c(&_start_ctors); c < &_end_ctors; ++c)
		((void (*) (void)) (*c)) ();

	//call kernel
	kentry(mbi, kernel_stack_bottom);

	//call static destructors
	for(unsigned long* d(&_start_dtors); d < &_end_dtors; ++d)
		((void (*) (void)) (*d)) ();
}

static void kentry(multiboot_info_t* mbi, unsigned long kernel_stack_bottom){
	//100Hz frequency = every 10ms pit interrupt called
	const wrap::uint32t pit_frequency = 100;

	//initialize architecture
	wrap::arch::initialize(pit_frequency, kpit_handler);

	//initialize physical memory manager
	wrap::memory::pmm_init((mbi->mem_lower + mbi->mem_upper) * 1024);

	for(;;){}
}
