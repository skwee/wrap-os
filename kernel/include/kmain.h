/*
 * Wrap OS
 * Copyright (C) 2010 Dmitry 'skwee' Kudryavtsev
 *
 * See COPYING file for license
 */
#ifndef _WRAP_KRN_MAIN_H_
#define _WRAP_KRN_MAIN_H_

#include <boot/multiboot.h>
#include <klib/icxxabi.hpp>

/** Kernel loader. */
extern "C" void kloader(multiboot_info_t* mbi, unsigned long kernel_stack_bottom);

#endif
