#ifndef FS_H
#define FS_H

#define MAX_FILES 32
#define MAX_FILENAME 32
#define MAX_CONTENT 512

// Simple file structure
struct File {
    char name[MAX_FILENAME];
    char content[MAX_CONTENT];
    int size;
    int is_used;
};

// Simple directory structure (single directory for simplicity)
struct Directory {
    struct File files[MAX_FILES];
    int file_count;
};

// File system functions
void init_fs(void);
void create_file(const char* name);
void delete_file(const char* name);
int write_file(const char* name, const char* content);
int read_file(const char* name, char* buffer);
void list_files(void);

#endif 