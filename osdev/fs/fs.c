#include "fs.h"
#include "../include/kernel.h"
#include <stddef.h>

// File system data structures
typedef struct {
    char name[MAX_FILENAME];
    char content[MAX_CONTENT];
    int used;
} File;

static File files[MAX_FILES];

// Initialize file system
void init_fs(void) {
    // Initialize all file slots as unused
    for (int i = 0; i < MAX_FILES; i++) {
        files[i].used = 0;
        files[i].name[0] = '\0';
        files[i].content[0] = '\0';
    }
}

// Create a new file
void create_file(const char* name) {
    // Find free slot
    int slot = -1;
    for (int i = 0; i < MAX_FILES; i++) {
        if (!files[i].used) {
            slot = i;
            break;
        }
    }
    
    if (slot == -1) {
        print_string("Error: No free file slots\n");
        return;
    }
    
    // Check if file already exists
    for (int i = 0; i < MAX_FILES; i++) {
        if (files[i].used && strcmp(files[i].name, name) == 0) {
            print_string("Error: File already exists\n");
            return;
        }
    }
    
    // Initialize new file
    strncpy(files[slot].name, name, MAX_FILENAME - 1);
    files[slot].name[MAX_FILENAME - 1] = '\0';
    files[slot].content[0] = '\0';
    files[slot].used = 1;
    
    print_string("Created file: ");
    print_string(name);
    print_char('\n');
}

// Delete a file
void delete_file(const char* name) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (files[i].used && strcmp(files[i].name, name) == 0) {
            files[i].used = 0;
            files[i].name[0] = '\0';
            files[i].content[0] = '\0';
            print_string("Deleted file: ");
            print_string(name);
            print_char('\n');
            return;
        }
    }
    print_string("Error: File not found\n");
}

// Write content to a file
int write_file(const char* name, const char* content) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (files[i].used && strcmp(files[i].name, name) == 0) {
            strncpy(files[i].content, content, MAX_CONTENT - 1);
            files[i].content[MAX_CONTENT - 1] = '\0';
            print_string("Wrote to file: ");
            print_string(name);
            print_char('\n');
            return 0;
        }
    }
    print_string("Error: File not found\n");
    return -1;
}

// Read content from a file
int read_file(const char* name, char* buffer) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (files[i].used && strcmp(files[i].name, name) == 0) {
            strcpy(buffer, files[i].content);
            return 0;
        }
    }
    print_string("Error: File not found\n");
    return -1;
}

// List all files
void list_files(void) {
    int found = 0;
    print_string("=== Files ===\n");
    for (int i = 0; i < MAX_FILES; i++) {
        if (files[i].used) {
            files[i].name[MAX_FILENAME - 1] = '\0'; // Defensive null-termination
            print_string(files[i].name);
            print_char('\n');
            found = 1;
        }
    }
    if (!found) {
        print_string("No files.\n");
    }
    print_string("============\n");
} 