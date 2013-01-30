/* multiboot.h - the header for Multiboot */
/* Copyright (C) 1999, 2001  Free Software Foundation, Inc.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA. */


#define MB_MEMORY_FLAG		0x00000001
#define MB_BOOTDEV_FLAG		0x00000002
#define MB_CMD_FLAG			0x00000004
#define MB_MODS_FLAG		0x00000008
#define MB_AOUT_SYM_FLAG	0x00000010
#define MB_ELF_SYM_FLAG		0x00000020
#define MB_MEM_MAP_FLAG		0x00000040
#define MB_DRIVE_FLAG		0x00000080
#define MB_CONFIG_FLAG		0x00000100
#define MB_BL_NAME_FLAG		0x00000200
#define MB_APM_TABLE_FLAG	0x00000400
#define MB_VBE_FLAG			0x00000800

/* The Multiboot header. */
typedef struct multiboot_header{
	unsigned long magic;
    unsigned long flags;
    unsigned long checksum;
    unsigned long header_addr;
    unsigned long load_addr;
    unsigned long load_end_addr;
    unsigned long bss_end_addr;
    unsigned long entry_addr;
}multiboot_header_t;

/* The symbol table for a.out. */
typedef struct aout_symbol_table{
	unsigned long tabsize;
    unsigned long strsize;
    unsigned long addr;
    unsigned long reserved;
}aout_symbol_table_t;

/* The section header table for ELF. */
typedef struct elf_section_header_table{
	unsigned long num;
    unsigned long size;
    unsigned long addr;
    unsigned long shndx;
}elf_section_header_table_t;

/* The Multiboot information. */
typedef struct multiboot_info{
	unsigned long flags;
	unsigned long mem_lower;
	unsigned long mem_upper;
	unsigned long boot_device;
    unsigned long cmdline;
    unsigned long mods_count;
    unsigned long mods_addr;
	union{
		aout_symbol_table_t aout_sym;
        elf_section_header_table_t elf_sec;
    }u;
	unsigned long mmap_length;
    unsigned long mmap_addr;
	unsigned long drives_length;
	unsigned long drives_addr;
	unsigned long config_table;
	unsigned long boot_loader_name;
	unsigned long apm_table;
	unsigned long vbe_control_info;
	unsigned long vbe_mode_info;
	unsigned long vbe_mode;
	unsigned long vbe_interface_seg;
	unsigned long vbe_interface_off;
	unsigned long vbe_interface_len;
}multiboot_info_t;

/* The module structure. */
typedef struct module{
	unsigned long mod_start;
    unsigned long mod_end;
    unsigned long string;
    unsigned long reserved;
}module_t;

/* The memory map. Be careful that the offset 0 is base_addr_low
but no size. */
typedef struct memory_map{
	unsigned long size;
    unsigned long base_addr_low;
    unsigned long base_addr_high;
    unsigned long length_low;
    unsigned long length_high;
    unsigned long type;
}memory_map_t;
