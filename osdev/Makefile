# Compiler and assembler
ASM=nasm
CC=gcc
LD=ld

# Flags
ASMFLAGS=-f bin
CFLAGS=-m32 -fno-pie -fno-stack-protector -ffreestanding -O2 -Wall -Wextra -I./include
LDFLAGS=-m elf_i386 -T linker.ld -nostdlib

# Directories
BOOT_DIR=boot
KERNEL_DIR=kernel
SHELL_DIR=shell
FS_DIR=fs
PROCESS_DIR=process

# Files
BOOT_SRC=$(BOOT_DIR)/boot.asm
KERNEL_SRC=$(KERNEL_DIR)/kernel.c
SHELL_SRC=$(SHELL_DIR)/shell.c
COMMANDS_SRC=$(SHELL_DIR)/commands.c
FS_SRC=$(FS_DIR)/fs.c
PROCESS_SRC=$(PROCESS_DIR)/process.c

# Output files
BOOT_BIN=boot.bin
KERNEL_OBJ=kernel.o
SHELL_OBJ=shell.o
COMMANDS_OBJ=commands.o
FS_OBJ=fs.o
PROCESS_OBJ=process.o
OS_IMAGE=os.img

all: $(OS_IMAGE)

$(BOOT_BIN): $(BOOT_SRC)
	$(ASM) $(ASMFLAGS) $< -o $@

$(KERNEL_OBJ): $(KERNEL_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(SHELL_OBJ): $(SHELL_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(COMMANDS_OBJ): $(COMMANDS_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(FS_OBJ): $(FS_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(PROCESS_OBJ): $(PROCESS_SRC)
	$(CC) $(CFLAGS) -c $< -o $@

$(OS_IMAGE): $(BOOT_BIN) $(KERNEL_OBJ) $(SHELL_OBJ) $(COMMANDS_OBJ) $(FS_OBJ) $(PROCESS_OBJ)
	# Link kernel and shell
	$(LD) $(LDFLAGS) -o kernel.elf $(KERNEL_OBJ) $(SHELL_OBJ) $(COMMANDS_OBJ) $(FS_OBJ) $(PROCESS_OBJ)
	objcopy -O binary kernel.elf kernel.bin
	
	# Create a blank disk image (1.44MB)
	dd if=/dev/zero of=$@ bs=1024 count=1440
	
	# Write bootloader to first sector
	dd if=$(BOOT_BIN) of=$@ conv=notrunc
	
	# Write kernel starting at second sector
	dd if=kernel.bin of=$@ seek=1 conv=notrunc bs=512

run: $(OS_IMAGE)
	qemu-system-i386 -drive format=raw,file=$(OS_IMAGE),if=floppy -m 32M -monitor stdio -display gtk

debug: $(OS_IMAGE)
	qemu-system-i386 -drive format=raw,file=$(OS_IMAGE),if=floppy -m 32M -monitor stdio -display gtk -d int,cpu -D debug.log

clean:
	rm -f $(BOOT_BIN) $(KERNEL_OBJ) $(SHELL_OBJ) $(COMMANDS_OBJ) $(FS_OBJ) $(PROCESS_OBJ) $(OS_IMAGE) kernel.bin kernel.elf debug.log

iso: $(OS_IMAGE)
	genisoimage -o ../argon_os.iso -b os.img -no-emul-boot -boot-load-size 4 -boot-info-table .

.PHONY: all clean run debug iso 