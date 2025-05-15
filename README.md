# ARGON_OS Project

A simple educational operating system for learning OS concepts, built by a team of four. This project demonstrates core OS features including process management, file system, shell, and device drivers.

## Project Structure
```
ARGON_OS/
└── osdev/                 # Main project directory
    ├── boot/             # Bootloader
    ├── kernel/           # Kernel code
    ├── mm/               # Memory Management
    ├── process/          # Process Management
    ├── fs/               # File System
    ├── drivers/          # Device Drivers
    ├── shell/            # Shell Interface
    ├── include/          # Common Headers
    ├── team_docs/        # Team Documentation
    ├── Makefile          # Build system
    └── linker.ld         # Linker script
```

## Key Features (Demo-Ready)
- **Bootloader:** Custom x86 boot sector, loads kernel.
- **Kernel:** Hardware initialization, screen, keyboard, process management.
- **Shell:** Command-line interface, command parsing, and execution.
- **Command History:** Use up/down arrows to recall previous commands.
- **File System:** In-memory file system with create, write, read, delete, and list (`ls`) commands. Defensive printing to avoid screen corruption.
- **Process Management:** Process creation, round-robin scheduling, and termination.
- **Device Drivers:** Keyboard and screen.
- **Error Handling:** User-friendly error messages for file and process operations.
- **Demo Commands:** For process scheduling and file system.
- **Robust Input Handling:** Clean prompt redraw, safe buffer management.

## Team Roles & Contributions
- **Kernel/Memory:** Bootloader, kernel init, screen, keyboard, memory setup.
- **Process Management:** Process creation, scheduling, kill, demo.
- **File System:** In-memory FS, file operations, `ls`, error handling.
- **Shell/UI:** Command parsing, history, prompt, user feedback.

## Build & Run Instructions
### Prerequisites
- GCC compiler
- NASM assembler
- QEMU emulator
- Make build system

### Build & Run
```bash
# Install dependencies (if needed)
sudo apt-get install nasm gcc make qemu-system-x86

# Build the OS
cd osdev
make clean && make

# Run in QEMU (standard mode)
make run

# Run in QEMU (debug mode, with logging)
make debug
```

## Demo Script (for Presentation)
1. **Boot the OS in QEMU.**
2. **Show the shell prompt and help command.**
3. **Demonstrate command history** (type a command, use up/down arrows to recall).
4. **Create, write, read, and delete files.**
5. **List files with `ls` (show safe, clean output).**
6. **Show process management:** create, list, and kill processes.
7. **Show error handling:** try to read a non-existent file, kill a non-existent process, etc.
8. **Each team member explains their module and code.
**

## Notes for Evaluation
- Each module is demo-ready and can be shown independently.
- Code is robust, with defensive programming and error handling.
- Documentation and code comments are present throughout.
- Further features (e.g., persistent file system, advanced shell) can be added as stretch goals.

## Redundant/Removed Sections
- Repeated build instructions and overly detailed learning paths have been condensed.
- Only features actually implemented are listed above.
- For full technical details, see code comments and `team_docs/`.

---

**This project demonstrates 60–70% of a full educational OS, with clear division of work and demo-ready features for each team member.**

## Team Roles

### 1. Kernel and Memory Management
- **Responsibilities**: Bootloader, kernel initialization, memory management
- **Documentation**: [Kernel Lead Guide](team_docs/kernel_lead.md)
- **Key Files**: `boot/boot.asm`, `kernel/kernel.c`, `mm/memory.c`

### 2. Process Management
- **Responsibilities**: Process creation, scheduling, IPC
- **Documentation**: [Process Lead Guide](team_docs/process_lead.md)
- **Key Files**: `process/process.c`, `process/scheduler.c`

### 3. File System
- **Responsibilities**: File operations, directory management
- **Documentation**: [File System Lead Guide](team_docs/filesystem_lead.md)
- **Key Files**: `fs/fs.c`, `fs/file.c`, `fs/directory.c`

### 4. Shell Interface
- **Responsibilities**: Command processing, user interaction
- **Documentation**: [Shell Lead Guide](team_docs/shell_lead.md)
- **Key Files**: `shell/shell.c`, `shell/commands.c`

## Getting Started

1. Choose your role from the team roles above
2. Read your role's documentation in the `team_docs` folder
3. Set up your development environment:
   ```bash
   # Install dependencies
   sudo apt-get install nasm gcc make qemu-system-x86

   # Build the OS
   cd osdev
   make clean && make
   
   # Run in QEMU
   make debug
   ```

## Build Instructions
```bash
# Clean previous build
make clean

# Build all components
make

# Run in emulator
make debug
```

## Team Coordination
- Each team member works in their assigned directory
- Regular team meetings to integrate components
- Use Git for version control
- Test your component before integration

## Project Overview
ARGON_OS is an educational operating system project designed to help understand fundamental OS concepts through hands-on implementation. This project is divided among 4 team members, each focusing on specific core components.

## Team Roles and Responsibilities

### Role 1: Kernel and Memory Management Lead
**Core Responsibilities:**
- Kernel initialization and boot process
- Memory management implementation
- System calls handling

**Learning Path:**
1. Study bootloader and kernel basics
   - x86 architecture
   - Real mode vs Protected mode
   - Memory segmentation
2. Memory Management concepts
   - Memory allocation/deallocation
   - Paging system
   - Memory protection

**Key Deliverables:**
- Working bootloader
- Basic memory manager
- Memory allocation functions (malloc/free)
- Memory protection mechanisms

### Role 2: Process Management and Scheduling Lead
**Core Responsibilities:**
- Process creation and management
- Task scheduling
- Inter-process communication

**Learning Path:**
1. Process Management concepts
   - Process states
   - Context switching
   - Task scheduling algorithms
2. IPC Mechanisms
   - Message passing
   - Shared memory
   - Synchronization

**Key Deliverables:**
- Process creation/termination system
- Simple round-robin scheduler
- Basic IPC mechanisms
- Process state management

### Role 3: File System and I/O Lead
**Core Responsibilities:**
- File system implementation
- I/O operations
- Device drivers

**Learning Path:**
1. File System concepts
   - File organization
   - Directory structure
   - File operations
2. Device Management
   - Device drivers
   - I/O handling
   - Interrupt management

**Key Deliverables:**
- Basic file system (create, read, write, delete)
- Directory management
- Device driver framework
- Keyboard and display drivers

### Role 4: Shell and User Interface Lead
**Core Responsibilities:**
- Shell implementation
- Command processing
- User interface

**Learning Path:**
1. Shell concepts
   - Command parsing
   - Command execution
   - User interaction
2. System Interface
   - System commands
   - Error handling
   - User feedback

**Key Deliverables:**
- Interactive shell
- Command history
- Basic system commands
- Error handling and display

## Project Timeline

### Phase 1 (Weeks 1-2): Setup and Basic Implementation
- Setup development environment
- Implement basic bootloader
- Create simple shell interface
- Establish basic memory management

### Phase 2 (Weeks 3-4): Core Features
- Implement process management
- Add file system basics
- Enhance shell functionality
- Develop memory management features

### Phase 3 (Weeks 5-6): Advanced Features
- Add inter-process communication
- Implement advanced shell features
- Enhance file system
- Add security features

### Phase 4 (Weeks 7-8): Integration and Testing
- Integrate all components
- Test system stability
- Fix bugs
- Document the system

## Development Setup

### Prerequisites
- GCC compiler
- NASM assembler
- QEMU emulator
- Make build system

### Build Instructions
```bash
# Clean previous build
make clean

# Build the OS
make

# Run in QEMU
make debug
```

## Detailed Project Structure and Build Flow

### Complete Folder Structure
```
ARGON_OS/
├── boot/
│   ├── boot.asm          # Main bootloader
│   ├── gdt.asm           # Global Descriptor Table setup
│   └── disk.asm          # Disk reading routines
│
├── kernel/
│   ├── kernel.c          # Main kernel file
│   ├── kernel.h          # Kernel header
│   ├── interrupt.c       # Interrupt handling
│   └── io.c              # I/O operations
│
├── mm/                   # Memory Management
│   ├── memory.c          # Memory operations
│   ├── memory.h          # Memory definitions
│   ├── paging.c          # Paging implementation
│   └── heap.c            # Heap management
│
├── process/              # Process Management
│   ├── process.c         # Process operations
│   ├── process.h         # Process definitions
│   ├── scheduler.c       # Task scheduler
│   └── ipc.c             # Inter-process communication
│
├── fs/                   # File System
│   ├── fs.c              # File system operations
│   ├── fs.h              # File system definitions
│   ├── directory.c       # Directory handling
│   └── file.c            # File operations
│
├── drivers/              # Device Drivers
│   ├── keyboard.c        # Keyboard driver
│   ├── screen.c          # Screen output
│   ├── timer.c           # System timer
│   └── disk.c            # Disk driver
│
├── shell/
│   ├── shell.c           # Shell implementation
│   ├── shell.h           # Shell definitions
│   ├── commands.c        # Command implementations
│   └── parser.c          # Command parser
│
├── include/              # Common Headers
│   ├── types.h           # Type definitions
│   ├── system.h          # System-wide definitions
│   └── string.h          # String operations
│
├── lib/                  # Common Libraries
│   ├── string.c          # String functions
│   └── stdlib.c          # Standard functions
│
├── docs/                 # Documentation
│   ├── kernel.md         # Kernel documentation
│   ├── memory.md         # Memory management docs
│   └── filesystem.md     # File system docs
│
├── Makefile             # Build system
├── linker.ld            # Linker script
└── README.md            # Project documentation

```

### Build Order and Dependencies
1. **Stage 1: Boot Process**
   ```
   boot.asm → boot.bin
   ```

2. **Stage 2: Kernel Core**
   ```
   kernel.c
   ├── io.c
   ├── interrupt.c
   └── memory.c
   ```

3. **Stage 3: Essential Drivers**
   ```
   drivers/
   ├── screen.c
   ├── keyboard.c
   └── timer.c
   ```

4. **Stage 4: Memory Management**
   ```
   mm/
   ├── memory.c
   ├── paging.c
   └── heap.c
   ```

5. **Stage 5: Process Management**
   ```
   process/
   ├── process.c
   └── scheduler.c
   ```

6. **Stage 6: File System**
   ```
   fs/
   ├── fs.c
   ├── directory.c
   └── file.c
   ```

7. **Stage 7: Shell**
   ```
   shell/
   ├── shell.c
   ├── commands.c
   └── parser.c
   ```

### System Flow Diagram
```
Boot Process
    │
    ▼
Bootloader (boot.asm)
    │   [Loads kernel into memory]
    ▼
Kernel Initialization (kernel.c)
    │
    ├─────────────┬─────────────┬─────────────┐
    ▼             ▼             ▼             ▼
Memory Manager  Process      File System    Device
(memory.c)     Manager      (fs.c)         Drivers
    │          (process.c)      │          (drivers/*)
    │             │             │             │
    └─────────────┴─────────────┴─────────────┘
                  │
                  ▼
            Shell (shell.c)
                  │
                  ▼
            User Interface
```

### Component Dependencies
```
Shell
  ├── Process Management
  │     ├── Memory Management
  │     └── File System
  │
File System
  ├── Memory Management
  └── Device Drivers
  
Process Management
  ├── Memory Management
  └── Device Drivers
  
Memory Management
  └── Device Drivers
  
Device Drivers
  └── Kernel Core
```

### Build Process Flow
1. **Compilation Order:**
   ```
   1. Assemble boot.asm → boot.bin
   2. Compile kernel and core components
   3. Compile drivers
   4. Compile memory management
   5. Compile process management
   6. Compile file system
   7. Compile shell
   8. Link everything → kernel.bin
   9. Create disk image with boot.bin and kernel.bin
   ```

2. **Final Image Creation:**
   ```
   boot.bin (First sector)
      │
      ▼
   kernel.bin (Following sectors)
      │
      ▼
   Final OS Image (os.img)
   ```

## Learning Resources

### General OS Development
- [OSDev Wiki](https://wiki.osdev.org/)
- [Operating Systems: Three Easy Pieces](https://pages.cs.wisc.edu/~remzi/OSTEP/)
- [Little OS Book](https://littleosbook.github.io/)

### Assembly and Low-level Programming
- [NASM Tutorial](https://cs.lmu.edu/~ray/notes/nasmtutorial/)
- [x86 Assembly Guide](https://www.cs.virginia.edu/~evans/cs216/guides/x86.html)

### C Programming for OS Development
- [C Programming Language (K&R)](https://www.amazon.com/Programming-Language-2nd-Brian-Kernighan/dp/0131103628)
- [Low-Level Programming in C](https://www.amazon.com/Low-Level-Programming-Assembly-Execution-Architecture/dp/1484224021)

## Testing and Debugging

### Unit Testing
- Each component should have basic test cases
- Use QEMU debugging features
- Implement logging mechanisms

### Integration Testing
- Test component interactions
- System stability tests
- Performance testing

## Documentation Guidelines
- Comment your code thoroughly
- Update README with new features
- Document APIs and interfaces
- Maintain a development log

## Communication and Collaboration
- Regular team meetings
- Code review sessions
- Use Git for version control
- Document major decisions

## Future Enhancements
- GUI implementation
- Network stack
- More advanced file system
- Security features
- Multi-user support

## Contributing
1. Fork the repository
2. Create feature branch
3. Commit changes
4. Push to branch
5. Create Pull Request

## License
This project is for educational purposes. 