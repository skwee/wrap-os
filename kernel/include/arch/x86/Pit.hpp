/*
 * Wrap OS
 * Copyright (C) 2010 Dmitry 'skwee' Kudryavtsev
 *
 * See COPYING file for license
 */
#ifndef _WRAP_KRN_ARCH_X86_PIT_HPP_
#define _WRAP_KRN_ARCH_X86_PIT_HPP_

#include <arch/x86/types.hpp>
#include <arch/x86/Interrupts.hpp>

namespace wrap{
	namespace arch{

		/* Initialize pit with given frequency and handler function */
		void pit_init(uint32t frequency, intr_handler_t handler);

		namespace pit{
			enum PitPorts{
				Channel0DataPort	= 0x40,	//channel 0 = irq0
				Channel1DataPort	= 0x41, //channel 1 = DRAM refresh
				Channel2DataPort	= 0x42, //channel 2 = PC speaker
				CommandRegisterPort	= 0x43	//mode/command register
			};

			/* PIT clock rate */
			static const uint32t clock_rate	= 1193182;

			enum BcdBinary{
				BinaryMode	= 0x00,
				BcdMode		= 0x01
			};

			enum OperatingMode{
				Mode0	= 0x00,	//interrupt on terminal count
				Mode1	= 0x02,	//hardware re-triggerable one-shot
				Mode2	= 0x04,	//rate generator
				Mode3	= 0x06,	//square wave generator
				Mode4	= 0x08,	//software triggered strobe
				Mode5	= 0x0A	//hardware triggered strobe
			};

			enum AccessMode{
				LatchCount		= 0x00,
				LoByteOnly		= 0x10,
				HiByteOnly		= 0x20,
				LoByteHiByte	= 0x30
			};

			enum Channel{
				Channel0	= 0x00,
				Channel1	= 0x40,
				Channel2	= 0x80,
				ReadBackCmd	= 0xC0
			};
		}

	}
}

#endif
