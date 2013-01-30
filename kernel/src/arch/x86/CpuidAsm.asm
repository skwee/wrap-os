; Wrap Kernel
; Copyright(c) 2010 Dmitry 'skwee' Kudryavtsev
;
; See COPYING file for licence.

global cpuid_supported	; make it visible

cpuid_supported:
	pushfd						; push eflags
	pop		eax					; get eflags to eax
	mov		ecx,	eax			; save eax
	xor		eax,	0x200000	; flip
	push	eax
	popfd						; set eflags
	pushfd
	pop		eax
	xor		eax,	ecx			; mask changed bits
	shr		eax,	21			; move bit 21 to bit 0
	and		eax,	1			; and mask others
	ret
