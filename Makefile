# Makfile for wrap Operating system
# Copyright(c) 2010 Dmitry 'skwee' Kudryavtsev
#
# See COPYING file for licence.

#------------------------------------------
# Directories
#------------------------------------------
PROJECTDIR	= ./
OBJDIR		= $(PROJECTDIR)obj/
BINDIR		= $(PROJECTDIR)bin/

#------------------------------------------
# Architecture and output
#------------------------------------------
ARCH			= i386
ARCHX			= x86
OUTPUT_FORMAT	= elf
TARGET			= $(ARCH)-$(OUTPUT_FORMAT)

#------------------------------------------
# Tools
#------------------------------------------
CC		= @$(TARGET)-gcc
CXX		= @$(TARGET)-g++
AS		= @nasm
LD		= @$(TARGET)-ld
AR		= @$(TARGET)-ar
PRINT	= @printf

#------------------------------------------
# Color Defines
#------------------------------------------
COLOR_RED	= \033[0;31m
COLOR_GRN	= \033[0;32m
COLOR_YLW	= \033[0;33m
COLOR_PRPL	= \033[0;34m
COLOR_PINK	= \033[0;35m
COLOR_CYAN	= \033[0;36m
COLOR_WHT	= \033[0;37m
COLOR_REDB	= \033[1;31m
COLOR_GRNB	= \033[1;32m
COLOR_YLWB	= \033[1;33m
COLOR_PRPLB	= \033[1;34m
COLOR_PINKB	= \033[1;35m
COLOR_CYANB	= \033[1;36m
COLOR_WHTB	= \033[1;37m
COLOR_END	= \033[0m

#------------------------------------------
# Make files
#------------------------------------------
include $(PROJECTDIR)kernel/kernel.mk

first:
	$(PRINT) "$(COLOR_RED)Please select target to make, or 'make help' for help \n$(COLOR_END)"
	
help:
	$(PRINT) "$(COLOR_GRN)Welcome Wrap Make System. Here are the possible make options\n$(COLOR_END)"
	$(PRINT) "$(COLOR_GRN)\tkernel - make kernel\n$(COLOR_END)"
	
iso: $(KERNEL_BINARY_NAME)
	cp $(KERNEL_BINARY_NAME) $(PROJECTDIR)isofiles/boot/
	genisoimage.exe -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -boot-info-table -o wrap.iso isofiles
	
.PHONY: iso help