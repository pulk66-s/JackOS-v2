BOOT			= ./src/boot
BIN				= ./bin
BUILD			= ./build
UTILS			= ./src/utils
STRING_LIB		= $(UTILS)/string
KERNEL			= ./src/kernel
LINKER			= ./src/linker.ld
KERNEL_BIN		= $(BIN)/kernel.bin
KERNEL_BUILD	= $(BUILD)/kernelfull.o
OS_BIN			= $(BIN)/os.bin

NASM			= nasm
BOOT_SRC		= $(BOOT)/boot.asm
BOOT_BIN		= $(BIN)/boot.bin
BOOT_FLAGS		= -f bin

CC				= /home/me-an-intellectuel/Bureau/LD_ELF_I386/zip/i686-elf-tools-linux/bin/i686-elf-gcc
INCLUDES		= -I./src -I$(UTILS)
CFLAGS			= -g -ffreestanding -falign-jumps -falign-functions -falign-labels -falign-loops -fstrength-reduce -fomit-frame-pointer -finline-functions -Wno-unused-function -fno-builtin -Werror -Wno-unused-label -Wno-cpp -Wno-unused-parameter -nostdlib -nostartfiles -nodefaultlibs -Wall -O0 $(INCLUDES)
SRC				= $(KERNEL)/kernel.c \
				$(STRING_LIB)/strlen.c \

OBJ				= $(SRC:.c=.o)


ASM_FLAGS		= -f elf -g
ASM_SRC			= $(KERNEL)/entry_point.asm
ASM_OBJ			= $(ASM_SRC:.asm=.o)
KERNEL_FILES	= $(ASM_OBJ) \
				$(OBJ)

LD				= /home/me-an-intellectuel/Bureau/LD_ELF_I386/zip/i686-elf-tools-linux/bin/i686-elf-ld
LDFLAGS			= -g -relocatable

all: boot_bin kernel_bin
	dd if=./bin/boot.bin >> $(OS_BIN)
	dd if=./bin/kernel.bin >> $(OS_BIN)
	dd if=/dev/zero bs=1048576 count=16 >> $(OS_BIN)

qemu: all
	qemu-system-i386 $(OS_BIN)

boot_bin:
	$(NASM) $(BOOT_FLAGS) $(BOOT_SRC) -o $(BOOT_BIN)

kernel_bin: $(KERNEL_FILES)
	$(LD) $(LDFLAGS) $(KERNEL_FILES) -o $(KERNEL_BUILD)
	$(CC) $(CFLAGS) -T $(LINKER) -o $(KERNEL_BIN) -ffreestanding -O0 -nostdlib $(KERNEL_BUILD)

clean:
	$(RM) $(OBJ)
	$(RM) $(ASM_OBJ)
	$(RM) $(KERNEL_BIN)
	$(RM) $(BOOT_BIN)
	$(RM) $(BUILD)/*.o
	$(RM) $(KERNEL_BUILD)

fclean: clean
	$(RM) $(OS_BIN)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -std=gnu99 -c $< -o $@

%.o: %.asm
	$(NASM) $(ASM_FLAGS) $< -o $@