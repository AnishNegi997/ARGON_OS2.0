# SimpleOS Project Chronology and Execution Flow

## Project Development Timeline

### Phase 1: Bootloader Development
1. **Boot Sector Implementation**
   ```assembly
   # boot/boot.asm
   # First code to execute when computer starts
   - BIOS loads first sector (boot.bin)
   - Sets up initial environment
   - Switches to protected mode
   - Loads kernel from disk
   ```

### Phase 2: Kernel Implementation
1. **Kernel Loading**
   ```c
   // kernel/kernel.c
   // Loaded by bootloader
   - Initializes hardware
   - Sets up memory management
   - Initializes screen buffer
   - Starts shell process
   ```

### Phase 3: Shell Development
1. **Shell Interface**
   ```c
   // shell/shell.c
   // Started by kernel
   - Provides command prompt
   - Handles user input
   - Processes commands
   ```

## Execution Flow

### 1. System Boot Sequence
```
BIOS → boot.bin → kernel.bin → shell
```

1. **BIOS Stage**
   - Power-on self-test
   - Loads boot.bin from first sector

2. **Bootloader Stage (boot.bin)**
   - File: `boot/boot.asm`
   - Actions:
     - Sets up segments
     - Enables A20 line
     - Switches to protected mode
     - Loads kernel.bin

3. **Kernel Stage (kernel.bin)**
   - File: `kernel/kernel.c`
   - Dependencies:
     - `kernel/screen.c`
     - `kernel/keyboard.c`
   - Actions:
     - Initializes hardware
     - Sets up interrupt handlers
     - Initializes memory management
     - Loads shell

4. **Shell Stage**
   - File: `shell/shell.c`
   - Dependencies:
     - `shell/commands.c`
     - `shell/parser.c`
   - Actions:
     - Displays prompt
     - Handles user input
     - Executes commands

## File Dependencies and Load Order

### 1. Boot Process Files
```
boot/
├── boot.asm       # Entry point
├── gdt.asm        # Global Descriptor Table
└── protected.asm  # Protected mode switch
```

### 2. Kernel Files
```
kernel/
├── kernel.c       # Main kernel file
├── screen.c       # Screen management
├── keyboard.c     # Keyboard handling
└── memory.c       # Memory management
```

### 3. Shell Files
```
shell/
├── shell.c        # Shell interface
├── commands.c     # Command implementations
└── parser.c       # Command parsing
```

## Build and Run Process

### 1. Build Sequence
```bash
# 1. Compile bootloader
nasm -f bin boot/boot.asm -o boot.bin

# 2. Compile kernel
i686-elf-gcc -c kernel/kernel.c -o kernel.o
i686-elf-gcc -c kernel/screen.c -o screen.o
# Link kernel objects
i686-elf-ld -T linker.ld -o kernel.bin kernel.o screen.o

# 3. Compile shell
i686-elf-gcc -c shell/shell.c -o shell.o
i686-elf-gcc -c shell/commands.c -o commands.o
# Link shell objects
i686-elf-ld -T shell.ld -o shell.bin shell.o commands.o
```

### 2. Image Creation
```bash
# Create disk image
dd if=boot.bin of=os.img bs=512 count=1
dd if=kernel.bin of=os.img bs=512 seek=1
```

### 3. Run Process
```bash
# Run in QEMU
qemu-system-i386 -drive format=raw,file=os.img,if=floppy -m 32M
```

## Component Interaction Flow

1. **Boot Stage**
   ```
   BIOS
   └── boot.bin
       └── Loads kernel.bin
   ```

2. **Kernel Stage**
   ```
   kernel.bin
   ├── Initializes hardware
   ├── Sets up memory
   └── Loads shell.bin
   ```

3. **Shell Stage**
   ```
   shell.bin
   ├── Displays prompt
   ├── Accepts commands
   └── Executes programs
   ```

## Testing Individual Components

### 1. Bootloader Testing
```bash
# Test boot sector alone
qemu-system-i386 -fda boot.bin
```

### 2. Kernel Testing
```bash
# Compile and test kernel
make kernel
make test-kernel
```

### 3. Shell Testing
```bash
# Compile and test shell
make shell
make test-shell
```

## Debugging Flow

1. **Boot Debugging**
   ```bash
   make debug-boot
   # In another terminal:
   gdb
   target remote localhost:1234
   ```

2. **Kernel Debugging**
   ```bash
   make debug-kernel
   # Set breakpoints in kernel code
   ```

3. **Shell Debugging**
   ```bash
   make debug-shell
   # Monitor shell behavior
   ```

## Common Development Workflow

1. Make changes to source files
2. Run `make clean`
3. Run `make` to build all components
4. Run `make run` to test in QEMU
5. If issues occur:
   - Use `make debug` for debugging
   - Check component-specific logs
   - Test individual components 