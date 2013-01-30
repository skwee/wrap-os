/*
 * Wrap OS
 * Copyright (C) 2010 Dmitry 'skwee' Kudryavtsev
 *
 * See COPYING file for license
 */
#ifndef _WRAP_KRN_ARCH_X86_INTERRUPTS_HPP_
#define _WRAP_KRN_ARCH_X86_INTERRUPTS_HPP_

#include <arch/x86/types.hpp>

namespace wrap{
	namespace arch{

		struct interrupt_registers_t{
			unsigned long ss, gs, fs, es, ds;	/* Segment registers */
			unsigned long edi, esi, ebp, esp, ebx, edx, ecx, eax; /* pusha */
			unsigned long intr_num, error_code;	/* Interrupt number and error code */
			unsigned long eip, cs, eflags; /* Pushed by CPU */
		};

		/* Pointer to interrupt handler function */
		typedef void (*intr_handler_t)(interrupt_registers_t);

		namespace interrupt{
			enum InterrupList{
				DivisionByZero						= 0,
				Debug,
				NonMaskableInterrupt,
				Breakpoint,
				IntoDetectedOverflow,
				OutOfBounds,
				InvalidOpcode,
				NoCoprocessor,
				DoubleFault,
				CoprocessorSegmentOverrun,
				BadTss,
				SegmentNotPresent,
				StackFault,
				GeneralProtectionFault,
				PageFault,
				UnknownInterrupt,
				CoprocessorFault,
				AlignmentCheckException,
				MachineCheckException,
				//19-31 Reserved
				Intel8253ProgrammableIntervalTimer 	= 32,
				Intel8042KeyboardController,
				Intel8259SlavePic,
				Uart8250SerialCom2Com4,
				Uart8250SerialCom1Com3,
				Intel8255ParallelPortLpt2,
				Intel82072AFloppyDiskController,
				Intel8255ParallelPortLpt1,
				RealTimeClock						= 40,
				//41-43 reserved
				Intel8042Ps2MouseController			= 44,
				MathCoprocessor,
				HardDiskController1,
				HardDiskController2,
				MaxInterrupts						= 256,
				MaxReservedIsrs						= 31
			};
		}

		/* Extern common interrupt handler. */
		extern "C" void intr_common_handler(interrupt_registers_t);

		/* Set interrupt handler */
		void intr_set_handler(uint8t intr_num, intr_handler_t handler);

		/* Reserved interrupt services */
		extern "C" void isr0 ();	/* Division by zero 				*/
		extern "C" void isr1 ();	/* Debug							*/
		extern "C" void isr2 ();	/* Non-Mask-able interrupt			*/
		extern "C" void isr3 ();	/* Breakpoint						*/
		extern "C" void isr4 ();	/* Into detected overflow			*/
		extern "C" void isr5 ();	/* Out of bounds					*/
		extern "C" void isr6 ();	/* Invalid opcode					*/
		extern "C" void isr7 ();	/* No coproceossor					*/
		extern "C" void isr8 ();	/* Double fault						*/
		extern "C" void isr9 ();	/* Coprocessor segment overrun 		*/
		extern "C" void isr10();	/* Bad TSS							*/
		extern "C" void isr11();	/* Segment not present				*/
		extern "C" void isr12();	/* Stack fault						*/
		extern "C" void isr13();	/* General protection fault			*/
		extern "C" void isr14();	/* Page fault						*/
		extern "C" void isr15();	/* Unknown interrupt				*/
		extern "C" void isr16();	/* Coprocessor fault				*/
		extern "C" void isr17();	/* Alignment check exception (486+)	*/
		extern "C" void isr18();	/* Machine check exception (586+)	*/
		extern "C" void isr19();	/* Reserved							*/
		extern "C" void isr20();	/* Reserved							*/
		extern "C" void isr21();	/* Reserved							*/
		extern "C" void isr22();	/* Reserved							*/
		extern "C" void isr23();	/* Reserved							*/
		extern "C" void isr24();	/* Reserved							*/
		extern "C" void isr25();	/* Reserved							*/
		extern "C" void isr26();	/* Reserved							*/
		extern "C" void isr27();	/* Reserved							*/
		extern "C" void isr28();	/* Reserved							*/
		extern "C" void isr29();	/* Reserved							*/
		extern "C" void isr30();	/* Reserved							*/
		extern "C" void isr31();	/* Reserved							*/

		/* Master PIC IRQs */
		extern "C" void irq0 ();	/* int32 Intel 8253/4 PIT */
		extern "C" void irq1 ();	/* int33 Intel 8042 keyboard */
		extern "C" void irq2 ();	/* int34 Intel 8259 slave PIC */
		extern "C" void irq3 ();	/* int35 8250 UART Serial port COM 2 & 4 */
		extern "C" void irq4 ();	/* int36 8250 UART Serial port COM 1 & 3 */
		extern "C" void irq5 ();	/* int37 Intel 8255 parallel port LPT2 */
		extern "C" void irq6 ();	/* int38 Intel 82072A floppy disk controller */
		extern "C" void irq7 ();	/* int39 Intel 8255 parallel port LPT1 */

		/* Slave PIC IRQs */
		extern "C" void irq8 ();	/* int40 Real time clock (RTC) */
		extern "C" void irq9 ();	/* int41 Reserved */
		extern "C" void irq10();	/* int42 Reserved */
		extern "C" void irq11();	/* int43 Reserved */
		extern "C" void irq12();	/* int44 Intel 8042 PS/2 mouse controller */
		extern "C" void irq13();	/* int45 Math coprocessor */
		extern "C" void irq14();	/* int46 HD controller 1 */
		extern "C" void irq15();	/* int47 HD controller 2 */
	}
}

#endif
