/*
 * Wrap OS
 * Copyright (C) 2010 Dmitry 'skwee' Kudryavtsev
 *
 * See COPYING file for license
 */
#include <arch/x86/DescriptorTable.hpp>
#include <arch/x86/Interrupts.hpp>
#include <klib/memory.hpp>

namespace wrap{
	namespace arch{

		/** GDT selectors. */
		static gdt_entry_t __attribute__((aligned(16))) _gdtSelectors[gdt::MaxSelectors];

		/** IDT Entries. */
		static idt_entry_t __attribute__((aligned(16))) _idtEntries[interrupt::MaxInterrupts];

		/** Load GDT to CPU. */
		extern "C" void gdt_load(unsigned long);

		/** Load IDT to CPU. */
		extern "C" void idt_load(unsigned long);

		void gdt_init(){
			//define gdt pointer
			gdt_pointer_t gdt_ptr;

			//set null selector (null selector must be always set)
			gdt_set_gate(gdt::NullSelector, 0, 0, 0, 0);

			//set kernel code selector
			uint8t access = gdt::access_byte::SegmentInMemory | gdt::access_byte::Ring0 |
					gdt::access_byte::CsDsDescriptor | gdt::access_byte::SegmentExecutable |
					gdt::access_byte::ConformingExecPrivl | gdt::access_byte::ReadWriteDsReadExecCs |
					gdt::access_byte::AccessBit0;
			uint8t granularity = gdt::granularity_byte::GranularitySize4Kb |
					gdt::granularity_byte::Segment32Bits | gdt::granularity_byte::OsReservedMsb |
					gdt::granularity_byte::OsReservedLsb;
			gdt_set_gate(gdt::KernelCodeSelector, 0x0, 0xFFFFFFFF, access, granularity);

			//set kernel data selector
			access = gdt::access_byte::SegmentInMemory | gdt::access_byte::Ring0 |
					gdt::access_byte::CsDsDescriptor | gdt::access_byte::SegmentNotExecutable |
					gdt::access_byte::DirectionGrowsUp | gdt::access_byte::ReadWriteDsReadExecCs |
					gdt::access_byte::AccessBit0;
			gdt_set_gate(gdt::KernelDataSelector, 0x0, 0xFFFFFFFF, access, granularity);

			//set pointer
			gdt_ptr.limit = (sizeof(gdt_entry_t) * gdt::MaxSelectors) - 1;
			gdt_ptr.base = (uint32t)&_gdtSelectors;

			//load gdt
			gdt_load((unsigned long)&gdt_ptr);
		}

		void idt_init(){
			//define idt pointer
			idt_pointer_t idt_ptr;

			//set attributes to present and Ring0 privilege and type to 32bit interrupt gate
			uint8t type_attr = idt::type_attr_byte::Present | idt::type_attr_byte::Ring0 |
					idt::type_attr_byte::i386bit32InterruptGate;

			klib::memset(&_idtEntries, 0, sizeof(idt_entry_t) * interrupt::MaxInterrupts);

			//set must defined ISRs
			idt_set_gate( 0, (unsigned long) isr0, SelectorKernelCode, type_attr);
			idt_set_gate( 1, (unsigned long) isr1, SelectorKernelCode, type_attr);
			idt_set_gate( 2, (unsigned long) isr2, SelectorKernelCode, type_attr);
			idt_set_gate( 3, (unsigned long) isr3, SelectorKernelCode, type_attr);
			idt_set_gate( 4, (unsigned long) isr4, SelectorKernelCode, type_attr);
			idt_set_gate( 5, (unsigned long) isr5, SelectorKernelCode, type_attr);
			idt_set_gate( 6, (unsigned long) isr6, SelectorKernelCode, type_attr);
			idt_set_gate( 7, (unsigned long) isr7, SelectorKernelCode, type_attr);
			idt_set_gate( 8, (unsigned long) isr8, SelectorKernelCode, type_attr);
			idt_set_gate( 9, (unsigned long) isr9, SelectorKernelCode, type_attr);
			idt_set_gate(10, (unsigned long)isr10, SelectorKernelCode, type_attr);
			idt_set_gate(11, (unsigned long)isr11, SelectorKernelCode, type_attr);
			idt_set_gate(12, (unsigned long)isr12, SelectorKernelCode, type_attr);
			idt_set_gate(13, (unsigned long)isr13, SelectorKernelCode, type_attr);
			idt_set_gate(14, (unsigned long)isr14, SelectorKernelCode, type_attr);
			idt_set_gate(15, (unsigned long)isr15, SelectorKernelCode, type_attr);
			idt_set_gate(16, (unsigned long)isr16, SelectorKernelCode, type_attr);
			idt_set_gate(17, (unsigned long)isr17, SelectorKernelCode, type_attr);
			idt_set_gate(18, (unsigned long)isr18, SelectorKernelCode, type_attr);
			idt_set_gate(19, (unsigned long)isr19, SelectorKernelCode, type_attr);
			idt_set_gate(20, (unsigned long)isr20, SelectorKernelCode, type_attr);
			idt_set_gate(21, (unsigned long)isr21, SelectorKernelCode, type_attr);
			idt_set_gate(22, (unsigned long)isr22, SelectorKernelCode, type_attr);
			idt_set_gate(23, (unsigned long)isr23, SelectorKernelCode, type_attr);
			idt_set_gate(24, (unsigned long)isr24, SelectorKernelCode, type_attr);
			idt_set_gate(25, (unsigned long)isr25, SelectorKernelCode, type_attr);
			idt_set_gate(26, (unsigned long)isr26, SelectorKernelCode, type_attr);
			idt_set_gate(27, (unsigned long)isr27, SelectorKernelCode, type_attr);
			idt_set_gate(28, (unsigned long)isr28, SelectorKernelCode, type_attr);
			idt_set_gate(29, (unsigned long)isr29, SelectorKernelCode, type_attr);
			idt_set_gate(30, (unsigned long)isr30, SelectorKernelCode, type_attr);
			idt_set_gate(31, (unsigned long)isr31, SelectorKernelCode, type_attr);

			//set pointer
			idt_ptr.limit = (sizeof(idt_entry_t) * interrupt::MaxInterrupts) - 1;
			idt_ptr.base = (uint32t)&_idtEntries;

			//load idt
			idt_load((unsigned long)&idt_ptr);
		}

		void gdt_set_gate(gdt::GDTSelector sid, uint32t base, uint32t limit, uint8t access, uint8t granularity){
			//get selector
			gdt_entry_t* sel = &_gdtSelectors[sid];

			//set selector limit
			sel->limit = limit & 0xFFFF;

			//set base
			sel->base_low = base & 0xFFFF;
			sel->base_middle = (base >> 16) & 0xFF;
			sel->base_high = (base >> 24) & 0xFF;

			//set access
			sel->access = access;

			//combine granularity (4 high bits) and bit 16-19 of the limit
			granularity = granularity | ((limit >> 16) & 0xF);

			//set granularity
			sel->granularity = granularity;
		}

		void idt_set_gate(uint8t idt_num, uint32t base, SelectorType selector, uint8t flags){
			//get entry
			idt_entry_t* entry = &_idtEntries[idt_num];

			//set low and high bases
			entry->base_low = base & 0xFFFF;
			entry->base_high = (base >> 16) & 0xFFFF;

			//set selector
			entry->selector = selector;

			//set zero
			entry->zero = 0;

			//set flags
			entry->type_attr = flags;
		}
	}
}
