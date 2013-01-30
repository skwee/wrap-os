/*
 * Wrap OS
 * Copyright (C) 2010 Dmitry 'skwee' Kudryavtsev
 *
 * See COPYING file for license
 */
#ifndef _WRAP_KRN_ARCH_X86_PIC_HPP_
#define _WRAP_KRN_ARCH_X86_PIC_HPP_

#include <arch/x86/types.hpp>

namespace wrap{
	namespace arch{

		/* Initialize PIC. */
		void pic_init();

		/* Send EOI (end of interrupt) command to PIC. inum - Interrupt number raised by PIC. */
		void pic_send_eoi(uint8t inum);

		namespace pic{
			enum PicInterrupts{
				BaseMasterInterrupt	= 32,
				BaseSlaveInterrupt	= 40,
				MaxInterruptsPerPic	= 8
			};

			enum PicPorts{
				MasterCommandPort	= 0x20,
				MasterDataPort		= 0x21,
				SlaveCommandPort	= 0xA0,
				SlaveDataPort		= 0xA1
			};

			enum PicCommands{
				EndOfInterrupt		= 0x20
			};

			enum ICW1{
				Icw1Icw4Required	= 0x01,
				Icw1Single			= 0x02,
				Icw1Interval4		= 0x04,
				Icw1Level			= 0x08,
				Icw1Init			= 0x10
			};

			enum ICW4{
				Icw4Mode8086		= 0x01,
				Icw4AutoEoi			= 0x02,
				Icw4MasterBuffer	= 0x04,
				Icw4BufferedMode	= 0x08,
				Icw4NestedMode		= 0x10
			};
		}

#define IS_PIC_INTERRUPT(intr) ((intr >= wrap::arch::pic::BaseMasterInterrupt) && (intr < (wrap::arch::pic::BaseSlaveInterrupt + wrap::arch::pic::MaxInterruptsPerPic)))

	}
}

#endif
