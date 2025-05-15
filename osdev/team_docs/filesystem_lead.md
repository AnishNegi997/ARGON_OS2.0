# File System Lead

## Your Role
You are responsible for implementing the file system, directory management, and file operations.

## Learning Path

### 1. File System Basics (Week 1)
- File system structure
- Disk organization
- File allocation methods
- Directory organization

### 2. File Operations (Week 2)
- File creation/deletion
- Reading and writing files
- Directory operations
- File descriptors

### 3. Advanced Features (Weeks 3-4)
- File permissions
- File buffering
- Error handling
- File system utilities

## Your Files

### File System Core
```c
// fs/fs.c - You'll implement this
struct FileSystem {
    int total_blocks;
    int free_blocks;
    void* block_bitmap;
    // ... more fields
};

void init_filesystem(void);
int format_disk(void);
struct Block* allocate_block(void);
```

### File Operations
```c
// fs/file.c - You'll implement this
int file_open(const char* filename, int mode);
void file_close(int fd);
size_t file_read(int fd, void* buffer, size_t size);
size_t file_write(int fd, const void* buffer, size_t size);
```

### Directory Management
```c
// fs/directory.c - You'll implement this
struct DirectoryEntry {
    char name[256];
    int inode_number;
    enum FileType type;
};

int create_directory(const char* path);
int list_directory(const char* path);
int delete_directory(const char* path);
```

## Key Deliverables
1. Basic file system implementation
2. File operations (create, read, write, delete)
3. Directory management
4. File system utilities (format, check)

## Learning Resources
1. [OSDev Wiki - File Systems](https://wiki.osdev.org/File_Systems)
2. [Operating Systems: Three Easy Pieces - File System Chapter](https://pages.cs.wisc.edu/~remzi/OSTEP/file-intro.pdf)
3. [File System Implementation Guide](https://www.cs.princeton.edu/courses/archive/fall09/cos318/lectures/File-System-Implementation.pdf)

## Detailed Learning Resources

### File System Basics
1. **File System Concepts**
   - [File System Basics](https://wiki.osdev.org/File_Systems)
   - [FAT File System](https://wiki.osdev.org/FAT) - Simple first filesystem
   - Key concepts:
     - Inodes and directories
     - File allocation
     - Directory structure
     - File descriptors

2. **Disk Management**
   - [Disk Access](https://wiki.osdev.org/ATA_PIO_Mode)
   - [Disk Partitioning](https://wiki.osdev.org/Partition_Table)
   - Practice tasks:
     - Read/write disk sectors
     - Handle disk partitions
     - Implement disk cache

### File Operations
1. **Basic Operations**
   - [File Operations Guide](https://www.cs.princeton.edu/courses/archive/fall19/cos318/lectures/File-Systems.pdf)
   - [File Descriptor Implementation](https://wiki.osdev.org/File_Descriptors)
   - Implementation tasks:
     - Create/delete files
     - Read/write operations
     - Seek functionality

2. **Buffering and Caching**
   - [Buffer Cache Design](https://pages.cs.wisc.edu/~remzi/OSTEP/file-implementation.pdf)
   - [File System Caching](https://wiki.osdev.org/Cache)
   - Projects:
     - Implement buffer cache
     - Handle dirty blocks
     - Write-back policies

### Directory Management
1. **Directory Structure**
   - [Directory Implementation](https://wiki.osdev.org/Directories)
   - [Path Resolution](https://wiki.osdev.org/Path_Resolution)
   - Practice:
     - Create directory entries
     - Implement path lookup
     - Handle . and .. entries

2. **File Organization**
   - [File Allocation Methods](https://www.geeksforgeeks.org/file-allocation-methods/)
   - [Indexed Allocation](https://wiki.osdev.org/Indexed_File_Allocation)
   - Implementation:
     - Contiguous allocation
     - Linked allocation
     - Indexed allocation

### Advanced Features
1. **File System Reliability**
   - [Journaling](https://wiki.osdev.org/Journaling)
   - [File System Consistency](https://pages.cs.wisc.edu/~remzi/OSTEP/file-journaling.pdf)
   - Projects:
     - Implement basic journaling
     - Handle crash recovery
     - File system check

2. **Performance Optimization**
   - [File System Performance](https://pages.cs.wisc.edu/~remzi/OSTEP/file-ffs.pdf)
   - [Disk Scheduling](https://wiki.osdev.org/Disk_Scheduling)
   - Tasks:
     - Optimize block placement
     - Implement read-ahead
     - Handle fragmentation

### Video Resources
1. [File System Implementation](https://www.youtube.com/watch?v=n2AAhiujAqs)
2. [Operating System - File System](https://www.youtube.com/playlist?list=PLBlnK6fEyqRjXhgWfdWIjyU1oqeCeBdYv)

### Books
1. "Operating Systems: Three Easy Pieces" - File System chapters
2. "The Design and Implementation of the FreeBSD Operating System" - File System section
3. "Understanding the Linux Kernel" - Chapter 12 (File System)

### Practice Projects
1. **Week 1**: Simple file operations
2. **Week 2**: Directory management
3. **Week 3**: File allocation
4. **Week 4**: File system utilities

### Debugging Tools
1. [File System Debugger](https://wiki.osdev.org/Filesystem_Debugging)
2. [Disk Image Tools](https://wiki.osdev.org/Disk_Images)

### Example File Systems to Study
1. **FAT32**
   - Simple structure
   - Good starting point
   - Well-documented

2. **ext2**
   - Unix-like structure
   - More advanced features
   - Good learning resource

### Community Resources
1. [File System Development Forum](https://forum.osdev.org/viewforum.php?f=14)
2. [Linux File System Mailing List](https://lore.kernel.org/linux-fsdevel/)
3. [File System Stack Exchange](https://unix.stackexchange.com/questions/tagged/filesystem)

## Testing Your Code
```c
// Example file operations
void test_filesystem() {
    // Create and write to file
    int fd = file_open("test.txt", O_CREAT | O_WRITE);
    file_write(fd, "Hello, World!", 13);
    file_close(fd);
    
    // Read from file
    char buffer[100];
    fd = file_open("test.txt", O_READ);
    size_t bytes = file_read(fd, buffer, 100);
    file_close(fd);
}
```

## Dependencies with Other Roles
- Needs memory management from Kernel Lead
- Process Management Lead needs file handles
- Shell Lead needs file system commands 