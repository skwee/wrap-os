/*
 * Wrap OS
 * Copyright (C) 2010 Dmitry 'skwee' Kudryavtsev
 *
 * See COPYING file for license
 */
#ifndef _WRAP_KRN_SYSTEM_BIOS_HPP_
#define _WRAP_KRN_SYSTEM_BIOS_HPP_

#include <arch/types.hpp>

namespace wrap{
	namespace system{

		struct bda_intalled_hardware_t{
			uint16t	diskette_avial_for_boot	: 1;	//bit     0: =1 if diskette available for boot
			uint16t have_math_co_processor	: 1;	//bit     1: =1 if math co-processor
			uint16t	have_pointing_device	: 1;	//bit     2: =1 if pointing device installed
			uint16t	__reserved_4			: 1;	//bit     3: reserved
			uint16t	initial_video_mode		: 2;	//bit   4-5: initial video mode. 00b=EGA,VGA,PGA, 01b=40x25 color, 10b=80x25 color, 11b=80x25 mono
			uint16t	diskette_drive_num		: 2;	//bit   6-7: number of diskette drives minus 1
			uint16t	__reserved_3			: 1;	//bit     8: reserved
			uint16t	serial_device_num		: 3;	//bit 11- 9: number of serial devices
			uint16t __reserved_2			: 1;	//bit    12: reserved
			uint16t	__reserved_1			: 1;	//bit    13: reserved
		}__attribute__((packed));

		struct bda_keyboard_status_flag1_t{
			uint8t	right_shift_pressed		: 1;	//bit 0: =1 right shift pressed
			uint8t	left_shift_pressed		: 1;	//bit 1: =1 left shift pressed
			uint8t	either_ctrl_pressed		: 1;	//bit 2: =1 either CTRL pressed
			uint8t	either_alt_pressed		: 1;	//bit 3: =1 either ALT pressed
			uint8t	scroll_lock_active		: 1;	//bit 4: =1 scroll lock active
			uint8t	num_lock_active			: 1;	//bit 5: =1 num lock active
			uint8t	caps_lock_active		: 1;	//bit 6: =1 caps lock active
			uint8t	insert_active			: 1;	//bit 7: =1 insert active
		}__attribute__((packed));

		struct bda_keyboard_status_flag2_t{
			uint8t	left_ctrl_pressed		: 1;	//bit 0: =1 left CTRL pressed
			uint8t	left_alt_pressed		: 1;	//bit 1: =1 left ALT pressed
			uint8t	sys_req_pressed			: 1;	//bit 2: =1 Sys Req pressed
			uint8t	pause_state_active		: 1;	//bit 3: =1 pause state active
			uint8t	scroll_lock_pressed		: 1;	//bit 4: =1 scroll lock pressed
			uint8t	num_lock_pressed		: 1;	//bit 5: =1 num lock pressed
			uint8t	caps_lock_pressed		: 1;	//bit 6: =1 caps lock pressed
			uint8t	insert_pressed			: 1;	//bit 7: =1 insert pressed
		};

		struct bda_diskette_recalib_status_t{
			uint8t	recalibrate_diskette0		: 1;	//bit 0
			uint8t	recalibrate_diskette1		: 1;	//bit 1
			uint8t	recalibrate_diskette2		: 1;	//bit 2
			uint8t	recalibrate_diskette3		: 1;	//bit 3
			uint8t	__reserved					: 3;	//bit 6-4
			uint8t	diskette_hw_intr_occured	: 1;	//bit 7
		};

		struct bda_diskett_motor_status_t{
			uint8t	diskette0_motor_on				: 1;	//bit 0
			uint8t	diskette1_motor_on				: 1;	//bit 1
			uint8t	diskette2_motor_on				: 1;	//bit 2
			uint8t	diskette3_motor_on				: 1;	//bit 3
			uint8t	diskette_drive_number_selected	: 2;	//bit 5-4
			uint8t	__reserved						: 1;	//bit 6
			uint8t	current_operation				: 1;	//bit 7: =1 current op is write or format, =0 current op is read or verify
		};

		struct bios_data_area{
			uint16t							base_io_serial[4];				//COM1-2-3-4 base IO addresses
			uint16t							base_io_parallel[3];			//LPT1-2-3
			uint16t							ebda_segment_addr;				//EBDA segment address
			bda_intalled_hardware_t			equipment_word;					//Equipment word
			uint8t							manifacturing_test;				//Manufacturing test
			uint16t							base_memory_size_kbytes;		//Base memory size in Kbytes
			uint8t							bios_control_flags;				//??
			bda_keyboard_status_flag1_t		keyboard_status_flag1;			//keyboard status flag 1
			bda_keyboard_status_flag2_t		keyboard_status_flag2;			//keyboard status flag 2
			uint8t							alt_numpad_work_area;			//Alt numpad work area
			uint16t							ptr_next_char_kb_buff;			//pointer to next char in keyboard buffer
			uint16t							ptr_first_free_kb_buff;			//pointer to first free slot in keyboard buffer
			uint8t							keyboard_buffer[32];			//keyboard buffer
			bda_diskette_recalib_status_t	diskette_recalibration_status;	//diskette recalibration status
			bda_diskett_motor_status_t		diskette_motor_status;			//diskette motor status
		};

		void bios_init();
		const bios_data_area* const bios_get_data_area();

	}
}

#endif
