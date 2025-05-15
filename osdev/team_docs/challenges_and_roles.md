# ARGON_OS Development: Challenges and Learning Experience

## Technical Stack Used
1. **Languages**
   - Assembly (NASM) for bootloader
   - C for kernel and system programming
   - Make for build system

2. **Tools and Emulators**
   - QEMU for system emulation
   - GCC cross-compiler for x86
   - GNU Make for build automation
   - GDB for debugging

3. **Hardware Interface**
   - x86 architecture
   - VGA text mode interface
   - Keyboard controller
   - Memory management unit

## Key Learning Outcomes & Team Challenges

### Major Technical Challenges (and Solutions)
- **Screen Buffer and Cursor Management:**
  - Implemented robust `scroll_screen` and improved backspace/cursor logic to prevent display bugs.
- **Command Input and Parsing:**
  - Enhanced shell parsing to support quoted arguments and robust input handling.
- **File System Safety:**
  - Defensive printing and null-termination to prevent screen corruption from `ls` and file operations.
- **Process Management:**
  - Implemented round-robin scheduling and safe process creation/termination.
- **Command History:**
  - Added up/down arrow support for recalling previous commands, with safe buffer management.
- **Build System:**
  - Resolved cross-compilation and dependency issues for reliable builds.
- **Documentation:**
  - Maintained clear, up-to-date docs for roles, challenges, and solutions.

### Team Member Learning Experiences
- **Boot/Kernel:** Low-level system init, memory, hardware-software interaction.
- **Shell:** Command parsing, UI, robust input/output, command history.
- **File System:** In-memory FS, file ops, defensive programming.
- **Process Management:** Scheduling, state management, resource allocation.

## Key Lessons Learned
- Importance of robust buffer and screen management.
- Value of systematic debugging and clear error messages.
- Need for defensive programming in OS code.
- Team coordination and documentation are critical for complex projects.

## Future Improvements
- Persistent file system (disk-backed)
- Virtual memory and paging
- Advanced process scheduling
- Networking and GUI support
- More device drivers and system utilities

## Project Impact on Team Skills
- Low-level programming, system design, debugging, and professional project management.

## Resources and References Used
- Intel x86 manuals, OSDev Wiki, GNU docs, QEMU/GCC/Make, OS textbooks, and C/assembly guides.

---

*For error resolution and running instructions, see the main README and setup_and_running_guide.md.* 