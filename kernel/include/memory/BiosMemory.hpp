/*
 * Wrap OS
 * Copyright (C) 2010 Dmitry 'skwee' Kudryavtsev
 *
 * See COPYING file for license
 */
#ifndef _WRAP_KRN_MEMORY_BIOS_MEMORY_HPP_
#define _WRAP_KRN_MEMORY_BIOS_MEMORY_HPP_

#include <memory/MemoryMap.hpp>

/** http://www.bioscentral.com/misc/bda.htm */

/**
 * ---------------------------------------------------
 * ------------------- CAUTION -----------------------
 * -     Not BDA nor EBDA is fully standardized      -
 * ---------------------------------------------------
 */

namespace wrap {
	namespace memory {
		namespace addr {
			namespace bda {
				//static const uint8t base_io_serial1 			= 0x00; //base IO serial 1
				//static const uint8t base_io_serial2 			= 0x02; //base IO serial 2
				//static const uint8t base_io_serial3 			= 0x04; //base IO serial 3
				//static const uint8t base_io_serial4 			= 0x06; //base IO serial 4
				//static const uint8t base_io_parallel1			= 0x08; //base IO parallel 1
				//static const uint8t base_io_parallel2			= 0x0A; //base IO parallel 2
				//static const uint8t base_io_parallel3			= 0x0C; //base IO parallel 3
				//static const uint8t base_io_parallel4			= 0x0E; //base IO parallel 4
				//static const uint8t ebda_addr					= 0x0E; //segment address of EBDA
				//static const uint8t equipment_word				= 0x16; //equipment word
				//static const uint8t interrupt_flag				= 0x12; //interrupt flag - manufacturing test
				//static const uint8t memory_size					= 0x13; //memory size in KiB
				//static const uint8t err_code_adptr_mem			= 0x15; //error code for AT+, adapter memory for PC and XT
				//static const uint8t keyboard_shift_flag1		= 0x17; //keyboard shift flag 1
				//static const uint8t keyboard_shift_flag2		= 0x18; //keyboard shift flag 2
				//static const uint8t alt_numpad_data				= 0x19; //Alt + Numpad data
				//static const uint8t next_char_keyboard_buff		= 0x1A; //pointer to address of next character in keyboard buffer
				//static const uint8t last_char_keyboard_buff		= 0x1C; //pointer to address of last character in keyboard buffer
				//static const uint8t keyboard_buffer				= 0x1E; //keyboard buffer
				//static const uint8t fdd_calibration_status		= 0x3E; //floppy disk drive calibration status
				//static const uint8t fdd_motor_status			= 0x3F; //floppy disk drive motor status
				//static const uint8t fdd_motor_timeout			= 0x40; //floppy disk drive motor timeout
				//static const uint8t fdd_status					= 0x41; //floppy disk drive status
				//static const uint8t hdf_controller_status_reg0 	= 0x42; //hard disk and floppy controller status register 0
				//static const uint8t fdd_controller_status_reg1 	= 0x43; //floppy drive controller status register 1
				//static const uint8t fdd_controller_status_reg2 	= 0x44; //floppy drive controller status register 2
				//static const uint8t fdd_controller_cylinder_num = 0x45; //floppy disk controller: cylinder number
				//static const uint8t fdd_controller_head_num		= 0x46; //floppy disk controller: head number
				//static const uint8t fdd_controller_sector_num	= 0x47; //floppy disk controller: sector number
				//static const uint8t fdd_controller_byte_written	= 0x48; //floppy disk controller: number of byte written
				//static const uint8t active_video_mode			= 0x49; //active video mode settings
				//static const uint8t num_screen_cols				= 0x4A; //number of text columns per row for active video mode
				//static const uint8t active_video_page_size		= 0x4C; //size of active video page in bytes
				//static const uint8t offset_active_video_page	= 0x4E; //offset address to active video page
				//static const uint8t cursor_position_vpage0		= 0x50; //cursor position for video page 0
				//static const uint8t cursor_position_vpage1		= 0x52; //cursor position for video page 1
				//static const uint8t cursor_position_vpage2		= 0x54; //cursor position for video page 2
				//static const uint8t cursor_position_vpage3		= 0x56; //cursor position for video page 3
				//static const uint8t cursor_position_vpage4		= 0x58; //cursor position for video page 4
				//static const uint8t cursor_position_vpage5		= 0x5A; //cursor position for video page 5
				//static const uint8t cursor_position_vpage6		= 0x5C; //cursor position for video page 6
				//static const uint8t cursor_position_vpage7		= 0x5E; //cursor position for video page 7
				//static const uint8t cursor_shape				= 0x60;	//cursor shape
				//static const uint8t active_video_page			= 0x62; //active video page
				static const uint8t base_crt_io_addr			= 0x63; //base IO port address for video display adapter
				//static const uint8t crt_control_register		= 0x65; //video display adapter internal mode register
				//static const uint8t color_palette				= 0x66; //color palette
				//static const uint8t adapter_rom_offset_addr		= 0x67; //adapter ROM offset address
				//static const uint8t adapter_rom_segment_addr	= 0x69; //adapter ROM segment address
				//static const uint8t last_interrupt				= 0x6B; //last interrupt (not PC)
				//static const uint8t counter_interrupt_1a		= 0x6C; //counter for interrupt 1Ah
				//static const uint8t timer_24_hour_flag			= 0x70; //timer 24 hour flag
				//static const uint8t keyboard_ctrl_break_flag	= 0x71; //keyboard ctrl-break flag
				//static const uint8t soft_reset_flag				= 0x72; //soft reset flag
				//static const uint8t hdd_last_operation_status	= 0x74; //status of last hard disk operation
				//static const uint8t hdd_count					= 0x75; //number of hard disk drives
				//static const uint8t hdd_control_byte			= 0x76; //hard disk control byte
				//static const uint8t hdd_io_offset_addr			= 0x77; //offset address of hard disk IO port (XT)
				//static const uint8t parallel_port1_timeout		= 0x78; //parallel port 1 timeout
				//static const uint8t parallel_port2_timeout		= 0x79; //parallel port 2 timeout
				//static const uint8t parallel_port3_timeout		= 0x7A; //parallel port 3 timeout
				//static const uint8t parallel_port4_timeout		= 0x7B; //parallel port 4 timeout
				//static const uint8t serial_port1_timeout		= 0x7C; //serial port 1 timeout
				//static const uint8t serial_port2_timeout		= 0x7D; //serial port 2 timeout
				//static const uint8t serial_port3_timeout		= 0x7E; //serial port 3 timeout
				//static const uint8t serial_port4_timeout		= 0x7F; //serial port 4 timeout
				//static const uint8t keyboard_buffer_start_addr	= 0x80; //starting address of keyboard buffer
				//static const uint8t keyboard_buffer_end_addr	= 0x82; //ending address of keyboard buffer
				//static const uint8t video_rows_count			= 0x84; //number of video rows minus 1
				//static const uint8t scan_line_per_char_count	= 0x85; //number of scan lines per character
				//static const uint8t video_display_adapter_opts	= 0x87; //video display adapter options
				//static const uint8t video_displat_adapter_swtch	= 0x88; //video display adapter switches
				//static const uint8t vga_video_flag1				= 0x89; //VGA video flag 1
				//static const uint8t vga_video_flag2				= 0x8A; //VGA video flag 2
				//static const uint8t fdd_configuration_data		= 0x8B; //floppy disk configuration data
				//static const uint8t hdd_controller_status		= 0x8C; //hard disk drive controller status
				//static const uint8t hdd_error					= 0x8D; //hard disk drive error
				//static const uint8t hdd_task_complete_flag		= 0x8E; //hard disk drive complete flag
				//static const uint8t fdd_information				= 0x8F; //floppy disk drive information
				//static const uint8t diskette0_media_state		= 0x90; //diskette 0 media state
				//static const uint8t diskette1_media_state		= 0x91; //diskette 1 media state
				//static const uint8t diskette0_op_start_state	= 0x92;	//diskette 0 operation start state
				//static const uint8t diskette1_op_start_state	= 0x93; //diskette 1 operation start state
				//static const uint8t diskette0_current_cylinder	= 0x94; //diskette 0 current cylinder
				//static const uint8t diskette1_current_cylinder	= 0x95; //diskette 1 current cylinder
				//static const uint8t keyboard_status_flag3		= 0x96; //keyboard status flag 3
				//static const uint8t keyboard_status_flag4		= 0x97; //keyboard status flag 4
				//static const uint8t addr_user_wait_flag_ptr		= 0x98; //segment:offset address of user wait flag pointer
				//static const uint8t user_wait_count				= 0x9C; //user wait count
				//static const uint8t user_wait_flag				= 0xA0; //user wait flag
				//static const uint8t lan_bytes					= 0xA1; //local area network bytes
				//static const uint8t addr_vparam_control_block	= 0xA8; //segment:offset address of video parameter control block
				//static const uint8t reserved					= 0xAC; //reserved
				//static const uint8t intra_app_comm_area			= 0xF0; //intra-applications communication area
			}

			namespace ebda {
				//static const uint8t	ebda_size_in_kblocks		= 0x000; //size of EBDA in 1k blocks
				//static const uint8t unknown						= 0x002; //unknown
				//static const uint8t post_error_entries_count	= 0x017; //Number of POST error entries
				//static const uint8t error_log					= 0x018; //error log
				//static const uint8t mouse_driver_device_call	= 0x022; //mouse driver device far call
				//static const uint8t mouse_flag1					= 0x026; //mouse flag 1
				//static const uint8t mouse_flag2					= 0x027; //mouse flag 2
				//static const uint8t mouse_data					= 0x028; //mouse data
				//static const uint8t unknown						= 0x030; //unknown
				//static const uint8t watch_dog_timer				= 0x039; //watch dog timer
				//static const uint8t unknown						= 0x03B; //unknown
				//static const uint8t hd0_param_table				= 0x03D; //hard disk 0 parameter table
				//static const uint8t hd1_param_table				= 0x04D; //hard disk 1 parameter table
				//static const uint8t unknown						= 0x05D; //unknown
				//static const uint8t cache_control				= 0x068; //cache control
				//static const uint8t unknown						= 0x069; //unknown
				//static const uint8t keyboard_repeat_rate		= 0x06E; //keyboard repeat rate
				//static const uint8t keyboard_repeat_delay		= 0x06F; //delay until keyboard repeats
				//static const uint8t attached_hd_number			= 0x070; //number of hard drives attached
				//static const uint8t dma_hd_channel				= 0x071; //DMA channel hard drive
				//static const uint8t hd_interrupt_status			= 0x072; //hard drive interrupt status
				//static const uint8t hd_operation_status			= 0x073; //hard drive operation status
				//static const uint8t old_76h_interrupt_vector	= 0x074; //old interrupt 76h vector pointer
				//static const uint8t hd_dma_type					= 0x078; //hard drive DMA type
				//static const uint8t hd_last_op_status			= 0x079; //hard drive status of last operation
				//static const uint8t hd_timeout_value			= 0x07A; //hard drive timeout value
				//static const uint8t unknown						= 0x07B; //unknown
				//static const uint8t hd_ctrl_return_status		= 0x07E; //hard drive controller return status words
				//static const uint8t unknown						= 0x08E; //unknown
				//static const uint8t diskette_drive_type			= 0x0E7; //diskette drive type
				//static const uint8t unknown						= 0x0E8; //unknown
				//static const uint8t hd_parameters_loaded		= 0x0EC; //hard drive parameters loaded
				//static const uint8t unknown						= 0x0ED; //unknown
				//static const uint8t cpu_family_id				= 0x0EE; //CPU Family ID
				//static const uint8t cpu_stepping				= 0x0EF; //CPU stepping
				//static const uint8t unknown						= 0x0F0; //unknown
				//static const uint8t keyboard_id					= 0x117; //keyboard ID
				//static const uint8t unknown						= 0x119; //unknown
				//static const uint8t non_bios_intr_18h_flag		= 0x11A; //non BIOS interrupt 18h flag
				//static const uint8t unknown						= 0x11B; //unknown
				//static const uint8t user_intr_18h_far_ptr		= 0x11D; //user interrupt 18h far pointer
				//static const uint8t unknown						= 0x121; //unknown
			}
		}
	}
}

#endif
