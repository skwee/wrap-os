; Wrap Kernel
; Copyright(c) 2010 Dmitry 'skwee' Kudryavtsev
;
; See COPYING file for licence.

; Make it visible for C code
global gdt_load
global idt_load

; Load GDT
gdt_load:
	mov	eax,	[esp + 4]	; Get GDT pointer that was passed
	lgdt		[eax]		; Load GDT

	mov	ax,		0x10		; 0x10 = Data selector of kernel

	; Set all data segments
	mov	ds,		ax
	mov es,		ax
	mov fs,		ax
	mov gs,		ax
	mov ss,		ax

	; Enter protected mode (Uncommend if boot loader is not GRUB)
	;mov	eax,	cr0
	;or	al,		1
	;mov cr0,	eax

	jmp	0x08:.gdt_load		; Far jump to update cs (0x08 = Code selector of kernel)

.gdt_load:
	ret

; Load IDT
idt_load:
	mov	eax,	[esp + 4]	; Get LDT pointer that was passed
	lidt		[eax]		; Load IDT

	ret
