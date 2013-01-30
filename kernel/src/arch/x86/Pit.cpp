/*
 * Wrap OS
 * Copyright (C) 2010 Dmitry 'skwee' Kudryavtsev
 *
 * See COPYING file for license
 */
#include <arch/x86/Pit.hpp>
#include <arch/x86/Io.hpp>
#include <arch/x86/Interrupts.hpp>

namespace wrap{
	namespace arch{

		void pit_init(uint32t frequency, intr_handler_t handler){
			//calculate count
			uint32t count = pit::clock_rate / frequency;

			//calculate low and hight portions of the divisor
			uint8t low = static_cast<uint8t>(count & 0xFF);
			uint8t high = static_cast<uint8t>((count >> 8) & 0xFF);

			//set PIT command
			io::outportb(pit::CommandRegisterPort, pit::BinaryMode |
					pit::Mode3 | pit::LoByteHiByte | pit::Channel0);

			//send low and high parts of divisor
			io::outportb(pit::Channel0DataPort, low);
			io::outportb(pit::Channel0DataPort, high);

			//set interrupt handler
			intr_set_handler(interrupt::Intel8253ProgrammableIntervalTimer, handler);
		}

	}
}
