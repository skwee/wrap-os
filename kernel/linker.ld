ENTRY(start)

SECTIONS
{
	. = 0xC0100000;

	.text : AT(ADDR(.text) - 0xC0000000)
	{
		code = .; _code = .; __code = .;
		*(.text)
		*(.gnu.linkonce.t*)
	}
	
	.rodata ALIGN(0x1000) : AT(ADDR(.rodata) - 0xC0000000)
	{
		rodata = .; _rodata = .; __rodata = .;
		*(.rodata*)
		*(.gnu.linkonce.r*)
		
		start_ctors = .; _start_ctors = .; __start_ctors = .;
		*(.ctor*)
		end_ctors = .; _end_ctors = .; __end_ctors = .;
		
		start_dtors = .; _start_dtors = .; __start_dtors = .;
		*(.dtor*)
		end_dtors = .; _end_dtors = .; __end_dtors = .;
	}

	.data ALIGN(0x1000) : AT(ADDR(.data) - 0xC0000000)
	{
		data = .; _data = .; __data = .;
		*(.data)
		*(.gnu.linkonce.d*)
	}

	.bss ALIGN(0x1000) : AT(ADDR(.bss) - 0xC0000000)
	{
		bss = .; _bss = .; __bss = .;
		*(.COMMON*)
		*(.bss)
		*(.gnu.linkonce.b*)
		ebss = .;
	}
	
	/DISCARD/ :
	{
		*(.comment)
		*(.eh_frame)
	}

	end = .; _end = .; __end = .;
}