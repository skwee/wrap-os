/*
 * Wrap OS
 * Copyright (C) 2010 Dmitry 'skwee' Kudryavtsev
 *
 * See COPYING file for license
 */
#ifndef _WRAP_KRN_ARCH_TYPES_HPP_
#define _WRAP_KRN_ARCH_TYPES_HPP_

#if defined(ARCH_i386) || defined(ARCH_i586)
#include <arch/x86/types.hpp>
#else
#error "Invalid or not supported architecture defined"
#endif

#define UNUSED(x) UNUSED_ ## x __attribute__((unused))

#endif
