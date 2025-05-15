# Kernel and Memory Management Lead

## Role & Contributions
You are responsible for the core OS functionality: bootloader, kernel initialization, screen and keyboard setup, and basic memory management.

## Implemented Features
- Custom x86 bootloader (boot.asm) that loads the kernel.
- Kernel initialization and entry point (kernel.c).
- Screen and keyboard driver integration.
- Basic memory management setup (static allocation, initialization).
- Provides core services for process management, file system, and shell.

## Demo-Ready Deliverables
- Bootloader loads and starts the kernel in QEMU.
- Kernel initializes hardware and displays a welcome message.
- Screen and keyboard input/output are functional.
- Memory is initialized and available for other modules.

## Key Files
- `boot/boot.asm` — Main bootloader
- `kernel/kernel.c` — Kernel entry and core logic
- `mm/memory.c` — Memory management (if implemented)

## Notes
- All implemented features are demo-ready and integrated with the rest of the OS.
- Further memory management (paging, malloc/free) can be added as stretch goals.

## Dependencies
- Process Management, File System, and Shell modules depend on kernel services.

---

*For full technical details, see code comments and the main README.*

## Learning Path

### 1. Assembly Language and Boot Process (Week 1)
- Learn x86 assembly basics
- Understand real mode vs protected mode
- Study the bootloader code (boot.asm)
- Key concepts: CPU modes, registers, interrupts

### 2. Kernel Basics (Week 2)
- C programming for kernel development
- Kernel entry point and initialization
- Screen output and basic I/O
- GDT (Global Descriptor Table)

### 3. Memory Management (Weeks 3-4)
- Memory segmentation
- Paging
- Memory allocation (malloc/free)
- Memory protection

## Learning Resources
1. [OSDev Wiki - Bare Bones](https://wiki.osdev.org/Bare_Bones)
2. [x86 Assembly Guide](https://www.cs.virginia.edu/~evans/cs216/guides/x86.html)
3. [Writing a Simple Operating System from Scratch](https://www.cs.bham.ac.uk/~exr/lectures/opsys/10_11/lectures/os-dev.pdf)

## Detailed Learning Resources

### Assembly Language
1. **x86 Assembly Basics**
   - [NASM Tutorial](https://cs.lmu.edu/~ray/notes/nasmtutorial/) - Start here for NASM syntax
   - [x86 Assembly Video Series](https://www.youtube.com/watch?v=VQAKkuLL31g&list=PLetF-YjXm-sCH6FrTz4AQhfH6INDQvQSn) - Visual learning
   - Practice exercises: Write simple boot sector programs

2. **Protected Mode**
   - [OSDev Protected Mode](https://wiki.osdev.org/Protected_Mode) - Complete guide
   - [GDT Tutorial](https://wiki.osdev.org/GDT_Tutorial) - Global Descriptor Table
   - Key topics to master:
     - Segment registers
     - Descriptor tables
     - Mode switching

### Kernel Development
1. **C for Operating Systems**
   - [C Programming for OS Development](https://www.cs.bham.ac.uk/~exr/lectures/opsys/10_11/lectures/os-dev.pdf) - Chapters 1-3
   - [Bare Bones Tutorial](https://wiki.osdev.org/Bare_Bones) - First kernel
   - Key concepts:
     - Inline assembly
     - Memory management
     - Hardware interaction

2. **Boot Process**
   - [BIOS Boot Process](https://wiki.osdev.org/BIOS) - Detailed explanation
   - [Multiboot Specification](https://www.gnu.org/software/grub/manual/multiboot/multiboot.html)
   - Practice: Write a bootloader that:
     - Switches to protected mode
     - Loads a kernel
     - Passes control to C code

### Memory Management
1. **Physical Memory**
   - [Memory Management Unit](https://wiki.osdev.org/Memory_Management_Unit)
   - [Page Frame Allocation](https://wiki.osdev.org/Page_Frame_Allocation)
   - Implementation tasks:
     - Write physical memory detector
     - Implement memory map

2. **Virtual Memory**
   - [Paging Tutorial](https://wiki.osdev.org/Paging_Tutorial)
   - [Virtual Memory Guide](https://www.cs.princeton.edu/courses/archive/fall19/cos318/lectures/Virtual-Memory.pdf)
   - Practice projects:
     - Implement basic paging
     - Set up kernel virtual memory

3. **Memory Allocation**
   - [Implementing malloc](https://wiki.osdev.org/Memory_Allocation)
   - [Dynamic Memory Allocation](https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/)
   - Implementation tasks:
     - Write simple allocator
     - Handle memory fragmentation

### Video Resources
1. [OS Development Series](https://www.youtube.com/playlist?list=PLHh55M_Kq4OApWScZyPl5HhgsTJS9MZ6M)
2. [Write Your Own Operating System](https://www.youtube.com/playlist?list=PLmlvkUN3-1MNKwINqdCDtTdNDjfBmWcZA)

### Books
1. "Operating Systems: Design and Implementation" by Andrew S. Tanenbaum
2. "Operating Systems: Three Easy Pieces" - Memory Management chapters
3. "The Art of Assembly Language Programming"

### Practice Projects
1. **Week 1**: Simple bootloader that prints message
2. **Week 2**: Basic kernel with screen output
3. **Week 3**: Physical memory manager
4. **Week 4**: Virtual memory and paging

### Debugging Tools
1. [QEMU Debugging Guide](https://wiki.osdev.org/QEMU_and_GDB)
2. [Bochs Debugger](https://wiki.osdev.org/Bochs)

### Community Resources
1. [OSDev Forums](https://forum.osdev.org/)
2. [Stack Overflow - OS Development](https://stackoverflow.com/questions/tagged/osdev)
3. [Reddit r/osdev](https://www.reddit.com/r/osdev/)

## Testing Your Code
```bash
# Build and test bootloader
nasm -f bin boot/boot.asm -o boot.bin

# Build and test kernel
gcc -m32 -fno-pie -c kernel/kernel.c -o kernel.o
```

## Dependencies with Other Roles
- Process Management Lead needs your memory management
- File System Lead needs your I/O functions
- Shell Lead needs your kernel services 