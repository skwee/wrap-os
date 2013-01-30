# Makfile for wrap kernel
# Copyright(c) 2010 Dmitry 'skwee' Kudryavtsev
#
# See COPYING file for licence.

#------------------------------------------
# Directories
#------------------------------------------
KERNELDIR		= $(PROJECTDIR)kernel/
KERNELOBJDIR	= $(OBJDIR)kernel/
KERNELSRC 		= $(KERNELDIR)src/
KERNELINC 		= $(KERNELDIR)include/

#------------------------------------------
# Flags
#------------------------------------------
KRN_BUILD	= KDEBUG
KRN_CCFLAGS	= -c -std=gnu99 -Wall -Wextra -Winline -Werror -nostdlib -nostdinc \
		-fno-builtin -fno-stack-protector -nodefaultlibs \
		-pedantic -Wshadow -Wcast-align -Wmissing-declarations \
		-Wredundant-decls -Wnested-externs \
		-Wstrict-prototypes -Wmissing-prototypes -Wwrite-strings \
		-I$(KERNELINC) -D ARCH_$(ARCH) -D $(KRN_BUILD)
		
KRN_CXXFLAGS = -c -Wall -Wextra -Werror -nostdlib -fno-builtin -nostartfiles \
		-ffreestanding \
		-nodefaultlibs -fno-exceptions -fno-rtti -fno-stack-protector -pedantic \
		-Wshadow -Wcast-align -Wmissing-declarations -Wredundant-decls -Wwrite-strings \
		-I$(KERNELINC) -D ARCH_$(ARCH) -D $(KRN_BUILD)
		
KRN_ASFLAGS	= -f $(OUTPUT_FORMAT) -w+orphan-labels
KRN_LDFLAGS	= -T$(KERNELDIR)linker.ld
KRN_ARFLAGS	= -rcs

#------------------------------------------
# Files
#------------------------------------------
ENTRY_FILES		:= $(wildcard $(KERNELSRC)*.asm $(KERNELSRC)*.cpp)
ENTRY_OBJECTS 	:= $(ENTRY_FILES)
ENTRY_OBJECTS 	:= $(ENTRY_OBJECTS:.asm=.o)
ENTRY_OBJECTS 	:= $(ENTRY_OBJECTS:.cpp=.o)

KRN_MODULE_DIRS	:= arch/$(ARCHX) memory/allocator memory klib
KRN_FILES		:= $(foreach DIR,$(KRN_MODULE_DIRS),$(wildcard $(KERNELSRC)$(DIR)/*.asm $(KERNELSRC)$(DIR)/*.cpp $(KERNELSRC)$(DIR)/*.c))
KRN_OBJECTS		:= $(KRN_FILES)
KRN_OBJECTS		:= $(KRN_OBJECTS:.asm=.o)
KRN_OBJECTS		:= $(KRN_OBJECTS:.cpp=.o)
KRN_OBJECTS		:= $(KRN_OBJECTS:.c=.o)

OBJECTS = \
	$(patsubst %, $(OBJDIR)%, $(ENTRY_OBJECTS)) \
	$(patsubst %, $(OBJDIR)%, $(KRN_OBJECTS))

KERNEL_BINARY_NAME = $(BINDIR)kernel32.elf

#------------------------------------------
# Rules
#------------------------------------------
kernel: $(OBJECTS) kernel-link

kernel-link:
	$(PRINT) "$(COLOR_GRN)[LD ]$(COLOR_END) $(KERNEL_BINARY_NAME) \n"
	$(LD) $(KRN_LDFLAGS) $(OBJECTS) -o $(KERNEL_BINARY_NAME)
	
$(OBJDIR)%.o: %.cpp
	@mkdir -p $(dir $@)
	$(PRINT) "$(COLOR_GRN)[CXX]$(COLOR_END) $< \n"
	$(CXX) $(KRN_CXXFLAGS) $< -o $@
	
$(OBJDIR)%.o: %.c
	@mkdir -p $(dir $@)
	$(PRINT) "$(COLOR_GRN)[CC ]$(COLOR_END) $< \n"
	$(CC) $(KRN_CCFLAGS) $< -o $@
	
$(OBJDIR)%.o: %.asm
	@mkdir -p $(dir $@)
	$(PRINT) "$(COLOR_GRN)[AS ]$(COLOR_END) $< \n"
	$(AS) $(KRN_ASFLAGS) $< -o $@
	
kernel-clean:
	rm -rf $(KERNELOBJDIR)*
	rm -f $(KERNEL_BINARY_NAME)