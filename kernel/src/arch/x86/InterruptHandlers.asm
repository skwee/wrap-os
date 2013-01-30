; Wrap Kernel
; Copyright(c) 2010 Dmitry 'skwee' Kudryavtsev
;
; See COPYING file for licence.

; ISR with error code macro
%macro ISR_ERR_CODE 1
	global	isr%1						; make visible
	isr%1:								; entry point
		cli								; disable interrupts
		push	byte	%1				; push interrupt number
		jmp		__intr_common_entry		; jump to common handler
		sti								; enable interrupts
%endmacro

; ISR with no error code macro
%macro ISR_NO_ERR_CODE 1
	global	isr%1						; make visible
	isr%1:								; entry point
		cli								; disable interrupts
		push	byte	0				; push dymmu error code
		push	byte	%1				; push interrupt number
		jmp		__intr_common_entry		; jump to commong handler
		sti								; enable interrupts
%endmacro

; IRQ macro
%macro IRQ_DEF 2
	global irq%1						; make visible
	irq%1:								; entry point
		cli								; disable interrupts
		push	byte 	0				; push dummy error code
		push	byte	%2				; push interrupt number
		jmp 	__intr_common_entry		; call commong entry
		sti								; enable interrupts
%endmacro

extern intr_common_handler		; import common handler from C code

; common interrupt handler
__intr_common_entry:
	; up to this point eflags, return cs, return eip,
	; error code, and interrupt number pushed to stack
	pusha		; push eax, ecx, eds, ebx, esp, ebp, esi, edi

	; push segment registers
	push	ds
	push	es
	push	fs
	push	gs
	push	ss

	; set data segment to kernel data selector
	mov		ax,	0x10
	mov		ds, ax
	mov		es,	ax
	mov		fs,	ax
	mov		gs, ax
	mov		ss, ax

	call	intr_common_handler	; call common handler

	; pop segment registers
	pop 	ss
	pop		gs
	pop		fs
	pop		es
	pop		ds

	popa

	add	esp,	8 	; clean pushed error code and interrup number
	iret			; return


; common ISRs
ISR_NO_ERR_CODE	 0
ISR_NO_ERR_CODE	 1
ISR_NO_ERR_CODE	 2
ISR_NO_ERR_CODE	 3
ISR_NO_ERR_CODE	 4
ISR_NO_ERR_CODE	 5
ISR_NO_ERR_CODE	 6
ISR_NO_ERR_CODE	 7
ISR_ERR_CODE	 8
ISR_NO_ERR_CODE	 9
ISR_ERR_CODE	10
ISR_ERR_CODE	11
ISR_ERR_CODE	12
ISR_ERR_CODE	13
ISR_ERR_CODE	14
ISR_NO_ERR_CODE	15
ISR_NO_ERR_CODE	16
ISR_NO_ERR_CODE	17
ISR_NO_ERR_CODE	18
ISR_NO_ERR_CODE	19
ISR_NO_ERR_CODE	20
ISR_NO_ERR_CODE	21
ISR_NO_ERR_CODE	22
ISR_NO_ERR_CODE	23
ISR_NO_ERR_CODE	24
ISR_NO_ERR_CODE	25
ISR_NO_ERR_CODE	26
ISR_NO_ERR_CODE	27
ISR_NO_ERR_CODE	28
ISR_NO_ERR_CODE	29
ISR_NO_ERR_CODE	30
ISR_NO_ERR_CODE	31

;  IRQ_NUM  Interrupt number
;        V   V
IRQ_DEF	 0,	32
IRQ_DEF	 1,	33
IRQ_DEF	 2,	34
IRQ_DEF	 3,	35
IRQ_DEF	 4,	36
IRQ_DEF	 5,	37
IRQ_DEF	 6,	38
IRQ_DEF	 7,	39
IRQ_DEF	 8,	40
IRQ_DEF	 9,	41
IRQ_DEF	10,	42
IRQ_DEF	11,	43
IRQ_DEF	12,	44
IRQ_DEF	13,	45
IRQ_DEF	14,	46
IRQ_DEF	15,	47
