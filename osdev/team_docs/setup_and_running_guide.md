# SimpleOS Setup and Running Guide

## Prerequisites Installation

### 1. Required Tools
```bash
# For Ubuntu/Debian
sudo apt-get update
sudo apt-get install -y \
    build-essential \
    nasm \
    qemu-system-x86 \
    gdb \
    make \
    git

# For Arch Linux
sudo pacman -S \
    base-devel \
    nasm \
    qemu \
    gdb \
    make \
    git
```

### 2. Cross-Compiler Setup
```bash
# Create directory for cross-compiler
mkdir -p ~/opt/cross
cd ~/opt/cross

# Download and extract binutils and GCC
wget https://ftp.gnu.org/gnu/binutils/binutils-2.41.tar.gz
wget https://ftp.gnu.org/gnu/gcc/gcc-13.2.0/gcc-13.2.0.tar.gz

# Build binutils
tar xf binutils-2.41.tar.gz
mkdir build-binutils
cd build-binutils
../binutils-2.41/configure --target=i686-elf --prefix="$HOME/opt/cross" --with-sysroot --disable-nls --disable-werror
make
make install

# Build GCC
cd ..
tar xf gcc-13.2.0.tar.gz
mkdir build-gcc
cd build-gcc
../gcc-13.2.0/configure --target=i686-elf --prefix="$HOME/opt/cross" --disable-nls --enable-languages=c --without-headers
make all-gcc
make all-target-libgcc
make install-gcc
make install-target-libgcc
```

### 3. Environment Setup
Add to your ~/.bashrc or ~/.zshrc:
```bash
export PATH="$HOME/opt/cross/bin:$PATH"
```

## Project Setup

### 1. Clone Repository
```bash
git clone https://github.com/yourusername/SimpleOS.git
cd SimpleOS
```

### 2. Directory Structure Setup
```bash
mkdir -p osdev/{boot,kernel,shell}
mkdir -p osdev/team_docs
```

## Building and Running Components

### 1. Building the Bootloader
```bash
cd osdev/boot
# Compile boot sector
nasm -f bin boot.asm -o boot.bin
# Verify binary size (should be 512 bytes)
ls -l boot.bin
```

### 2. Building the Kernel
```bash
cd ../kernel
# Compile kernel source
i686-elf-gcc -c kernel.c -o kernel.o -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -c screen.c -o screen.o -ffreestanding -O2 -Wall -Wextra

# Link kernel objects
i686-elf-ld -T linker.ld -o kernel.bin kernel.o screen.o
```

### 3. Building the Shell
```bash
cd ../shell
# Compile shell source
i686-elf-gcc -c shell.c -o shell.o -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -c commands.c -o commands.o -ffreestanding -O2 -Wall -Wextra

# Link shell objects
i686-elf-ld -T shell.ld -o shell.bin shell.o commands.o
```

## Running Different Components

### 1. Testing Bootloader Only
```bash
# From boot directory
qemu-system-i386 -fda boot.bin
```

### 2. Testing Full System
```bash
# From project root
# Create disk image
dd if=/dev/zero of=os.img bs=512 count=2880
dd if=boot/boot.bin of=os.img conv=notrunc bs=512 count=1
dd if=kernel/kernel.bin of=os.img conv=notrunc bs=512 seek=1

# Run in QEMU
qemu-system-i386 -drive format=raw,file=os.img,if=floppy -m 32M
```

## Debugging Guide

### 1. Bootloader Debugging
```bash
# Terminal 1
qemu-system-i386 -fda boot.bin -s -S

# Terminal 2
gdb
target remote localhost:1234
set architecture i8086
break *0x7c00
continue
```

### 2. Kernel Debugging
```bash
# Terminal 1
qemu-system-i386 -drive format=raw,file=os.img,if=floppy -s -S

# Terminal 2
gdb kernel/kernel.bin
target remote localhost:1234
break kernel_main
continue
```

### 3. Shell Debugging
```bash
# Use GDB with symbols
i686-elf-gcc -g -c shell/shell.c -o shell/shell.o
i686-elf-gcc -g -c shell/commands.c -o shell/commands.o
i686-elf-ld -T shell.ld -o shell.bin shell/shell.o shell/commands.o

# Then debug as above
```

## Common Issues and Solutions

### 1. Build Issues
- **Error**: "nasm: command not found"
  - Solution: `sudo apt-get install nasm`

- **Error**: "i686-elf-gcc: command not found"
  - Solution: Ensure cross-compiler is in PATH

- **Error**: "Disk image too large"
  - Solution: Check sector count in dd commands

### 2. Runtime Issues
- **Error**: "Operating system not found"
  - Check boot.bin size (must be 512 bytes)
  - Verify boot signature (0x55AA)

- **Error**: "Kernel panic"
  - Check kernel linking address
  - Verify memory map

### 3. Debug Issues
- **Error**: "Cannot connect to QEMU"
  - Ensure QEMU is running with -s -S
  - Check if port 1234 is free

## Testing Commands

### 1. File Operations
```bash
# In SimpleOS shell
create test.txt
write test.txt "Hello World"
read test.txt
```

### 2. System Commands
```bash
# In SimpleOS shell
help
clear
ls
```

## Performance Monitoring

### 1. Memory Usage
```bash
# In QEMU monitor (Ctrl-Alt-2)
info mem
```

### 2. CPU Usage
```bash
# In QEMU monitor
info registers
```

## Maintenance Tasks

### 1. Cleaning Build Files
```bash
# From project root
make clean
```

### 2. Updating Source
```bash
# Update and rebuild
git pull
make clean
make
```

### 3. Creating Backups
```bash
# Backup disk image
cp os.img os.img.backup
``` 