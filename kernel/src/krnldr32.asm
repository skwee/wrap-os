; Wrap Kernel Loader
; Copyright(c) 2010 Dmitry 'skwee' Kudryavtsev
;
; See COPYING file for licence.

global		start	; make start visible
extern		kloader	; kernel main entry point

; multiboot header
MODULE_ALIGN	equ 1<<0					; align modules to page boundaries
MEMINFO			equ 1<<1					; memory map
MAGIC			equ 0x1BADB002				; magic number
FLAGS			equ MODULE_ALIGN | MEMINFO	; flags
CHECKSUM		equ -(MAGIC + FLAGS)		; checksum

KERNEL_VIRTUAL_BASE	equ	0xC0000000			; kernel will be at 3GB
KERNEL_DIR_NUMBER	equ (KERNEL_VIRTUAL_BASE >> 22)	; kernel directory number

section .data

; create boot page table
align 0x1000
boot_page_table:
	%assign i 0
	%rep 1024
		dd	0x00000003 + (i * 4096)
	%assign i i+1
	%endrep

; create boot page directory
align 0x1000
boot_page_directory:
	; identity map first 4MB
	dd	0x00000003 + (boot_page_table - KERNEL_VIRTUAL_BASE)
	times (KERNEL_DIR_NUMBER - 1) dd 0

	; map high pages of kernel
	dd 0x00000003 + (boot_page_table - KERNEL_VIRTUAL_BASE)
	times (1024 - KERNEL_DIR_NUMBER - 1) dd 0

section .text
align	4

; mutliboot header
multiboot_header:
	dd MAGIC
	dd FLAGS
	dd CHECKSUM

STACKSIZE	equ 0x1000	; 4mb stack

; kernel loader entry point
start:

; set high half
higher_half:
	; load boot page directory
	mov	ecx,	(boot_page_directory - KERNEL_VIRTUAL_BASE)
	mov	cr3,	ecx

	; enable pagin
	mov	ecx,	cr0
	or	ecx,	0x80000000
	mov	cr0,	ecx

	; go to higher half
	lea	ecx,	[kernel_start]
	jmp	ecx

; execute kernel
kernel_start:
	; we dont need identity paging anymore, so disable it
	mov	dword [boot_page_directory],	0
	invlpg	[0]

	xchg	bx,		bx					; bochs magic breakpoint
	mov		esp,	stack+STACKSIZE		; set stack
	push	esp							; save initial position of stack
	add		ebx,	KERNEL_VIRTUAL_BASE	; convert multiboot struct to virtual address
	push	ebx							; pass multiboot struct
	cli									; disable interrupts
	call	kloader						; call loader
	cli
	hlt	; halt computer

section .bss
align 32
stack:
	resb STACKSIZE
