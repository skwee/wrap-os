/*
 * Wrap OS
 * Copyright (C) 2010 Dmitry 'skwee' Kudryavtsev
 *
 * See COPYING file for license
 */
#ifndef _WRAP_KRN_KLIB_STDARG_H_
#define _WRAP_KRN_KLIB_STDARG_H_

#ifndef _VA_LIST
#define _VA_LIST
typedef char *va_list;
#endif

#define __va_rounded_size(t) \
	(((sizeof(t) + sizeof(int) - 1) / sizeof(int)) * sizeof(int))

#ifdef __GNUC__
#define va_start(v, l) \
	((v) = ((va_list) __builtin_next_arg(l)))
#else
#define va_start(v, l) \
	((v) = ((va_list) (&l) + __va_rounded_size(l)))
#endif

#define va_end(v) (void)0

#define va_arg(v, l) \
	(((v) = (v) + __va_rounded_size(l)), \
	 *((l*)(void*)((v) - __va_rounded_size(l))))

#endif
