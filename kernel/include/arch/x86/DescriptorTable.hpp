/*
 * Wrap OS
 * Copyright (C) 2010 Dmitry 'skwee' Kudryavtsev
 *
 * See COPYING file for license
 */
#ifndef _WRAP_KRN_ARCH_X86_DESCRIPTOR_TABLE_HPP_
#define _WRAP_KRN_ARCH_X86_DESCRIPTOR_TABLE_HPP_

#include <arch/x86/types.hpp>

namespace wrap{
	namespace arch{

		/** Single entry in GDT table. */
		struct gdt_entry_t{
			uint16t		limit;			/* Segment limit */
			uint16t		base_low;		/* Low part of base address */
			uint8t		base_middle;	/* Middle part of base address */
			uint8t		access;			/* Access byte */
			uint8t		granularity;	/* Granularity byte */
			uint8t		base_high;		/* High part of base address */
		}__attribute__((packed));

		/** GDT Pointer. */
		struct gdt_pointer_t{
			uint16t		limit;			/* Size of GDT minus 1 */
			uint32t		base;			/* Address of first entry in GDT */
		}__attribute__((packed));

		/** IDT structure. */
		struct idt_entry_t{
			uint16t		base_low;	/* Low 16 bit of ISR */
			uint16t		selector;	/* Selector number */
			uint8t		zero;		/* Always zero */
			uint8t		type_attr;	/* Type and attributes */
			uint16t		base_high;	/* High 16 bit of ISR */
		}__attribute__((packed));

		/** IDT pointer structure. */
		struct idt_pointer_t{
			uint16t		limit;		/* Size of IDT minus 1 */
			uint32t		base;		/* Address of first entry in IDT */
		}__attribute__((packed));

		namespace gdt{
			enum GDTSelector{
				NullSelector		= 0,
				KernelCodeSelector	= 1,
				KernelDataSelector	= 2,
				MaxSelectors
			};
		}

		/**
		 * Initialize global descriptor table.
		 */
		void gdt_init();

		/**
		 * Initialize interrupt descriptor table.
		 */
		void idt_init();

		/** Set single GDT entry. */
		void gdt_set_gate(gdt::GDTSelector sid, uint32t base, uint32t limit, uint8t access, uint8t granularity);

		/** Set single IDT entry. */
		void idt_set_gate(uint8t idt_num, uint32t base, SelectorType selector, uint8t flags);

		namespace gdt{
			/** Access byte break down */
			/*
			 * |pr|privl|dt|ex|dc|rw|ac|
			 * pr 		- present bit			(1 bit )
			 * 		Must be 1 for all valid selectors.
			 *
			 * privl 	- Ring level 			(2 bits)
			 * 		00 - Ring0 privilege.
			 * 		01 - Ring1 privilege.
			 * 		10 - Ring2 privilege.
			 * 		11 - Ring3 privilege.
			 *
			 * dt		- Descriptor type		(1 bit )
			 * 		0 - System selector.
			 * 		1 - Code or Data selector.
			 *
			 * ex		- Executable bit		(1 bit )
			 * 		0 - Code cannot be executed (data selector).
			 * 		1 - Code in this segment can be executed (code selector).
			 *
			 * dc		- Direction/Conforming 	(1 bit )
			 * 		Direction bit for data selectors:
			 * 			0 - Segment grows up.
			 * 			1 - Segment grows down.
			 * 		Conforming bit for code selectors:
			 * 			0 - Code in this segment can be executed only from
			 * 				ring set in privl bit.
			 * 			1 - Code in this segment can be executed from equal
			 * 				or lower privilege level.
			 *
			 * rw		- Read/Write			(1 bit )
			 * 			0 - Read only for data selectors, execute only for code selectors.
			 * 			1 - Read&Write for data selectors, read&execute for code selectors.
			 *
			 * ac		- Access bit			(1 bit )
			 * 			Set to 0, CPU sets this to 1 when segment is accessed.
			 */
			namespace access_byte{
				enum Present{
					SegmentNotInMemory		= 0x00,
					SegmentInMemory			= 0x80
				};

				enum PrivilegeLevel{
					Ring0					= 0x00,
					Ring1					= 0x20,
					Ring2					= 0x40,
					Ring3					= 0x60
				};

				enum DescriptorType{
					SystemDescriptor		= 0x00,
					CsDsDescriptor			= 0x10
				};

				enum Executable{
					SegmentNotExecutable	= 0x00,
					SegmentExecutable		= 0x08
				};

				enum DirectionConforming{
					DirectionGrowsUp		= 0x00,
					DirectionGrowsDown		= 0x04,
					ConformingExecPrivl		= 0x00,
					ConformingExecEqLow		= 0x04
				};

				enum ReadWrite{
					ReadOnlyDsExecOnlyCs	= 0x00,
					ReadWriteDsReadExecCs	= 0x02
				};

				enum Access{
					AccessBit0	= 0x00,
					AccessBit1	= 0x01
				};
			}

			/** Granularity byte breakdown (note 4MSB is granularity, 4LSB are bits 19-16 of the limit */
			/*
			 * |gr|sz|os1|os2|
			 * gr		- Granularity bit
			 * 		0 - Limit is in 1B blocks.
			 * 		1 - Limit is in 4KiB blocks.
			 *
			 * sz		- Size bit.
			 * 		0 - Selector defines 16 bit protected mode.
			 * 		1 - Selector defines 32 bit protected mode.
			 *
			 * os1		- Reserved for OS use.
			 * os2		- Reserved for OS use.
			 */
			namespace granularity_byte{
				enum GranularitySize{
					GranularitySize1B	= 0x00,
					GranularitySize4Kb	= 0x80
				};

				enum Size{
					Segment16Bits		= 0x00,
					Segment32Bits		= 0x40
				};

				enum OsReservedBits{
					OsReservedMsb		= 0x00,
					OsReservedLsb		= 0x00
				};
			}
		}

		namespace idt{
			/** Flag byte breakdown */
			/*
			 * |p|priv|s|gatetype|
			 *
			 * p 	- present bit.
			 * 	0 - Not present (if interrupt is not used).
			 * 	1 - Present.
			 *
			 * priv	- Privilege level.
			 * 	00 - Ring 0.
			 * 	01 - Ring 1.
			 * 	10 - Ring 2.
			 * 	11 - Ring 3.
			 *
			 * s	- Storage segment. ??? Should be 0 for interrupt gates.
			 * 	0 -
			 * 	1 -
			 *
			 * gatetype	- Gate type
			 * 	0101 - 80386 32-bit task gate.
			 * 	0110 - 80286 16-bit interrupt gate.
			 * 	0111 - 80286 16-bit trap gate.
			 * 	1110 - 80386 32-bit interrupt gate.
			 * 	1111 - 80386 32-bit trap gate.
			 */
			namespace type_attr_byte{
				enum PresentType{
					NotPresent	= 0x00,
					Present		= 0x80
				};

				enum Privilege{
					Ring0		= 0x00,
					Ring1		= 0x20,
					Ring2		= 0x40,
					Ring3		= 0x60
				};

				enum GateType{
					i386bit32TaskGate		= 0x05,
					i286bit16InterruptGate	= 0x06,
					i286bit16TrapGate		= 0x07,
					i386bit32InterruptGate	= 0x0E,
					i386bit32TrapGate		= 0x0F
				};
			}
		}
	}
}

#endif
