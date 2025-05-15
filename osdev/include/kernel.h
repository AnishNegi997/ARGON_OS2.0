#ifndef KERNEL_H
#define KERNEL_H

#define NULL ((void*)0)

#include <stddef.h>
#include <stdint.h>

// Video functions
void init_video(void);
void clear_screen(void);
void print_char(char c);
void print_string(const char* str);
void print_int(int num);
void update_cursor(void);
void scroll_up(void);
void scroll_down(void);

// Keyboard functions
char getchar(void);

// String functions
int strcmp(const char* s1, const char* s2);
size_t strlen(const char* str);
char* strcpy(char* dest, const char* src);
char* strncpy(char* dest, const char* src, size_t n);

// System control functions
void shutdown(void);
void reboot(void);

// Shell functions
void init_shell(void);
void run_shell(void);

// Kernel functions
void kmain(void) __attribute__((section(".text.boot")));

// Utility functions
void int_to_string(int num, char* str);
int string_to_int(const char* str);

#endif 