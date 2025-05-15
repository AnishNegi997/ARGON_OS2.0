#ifndef SCREEN_H
#define SCREEN_H

// Screen dimensions
#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_MEMORY 0xB8000

// Screen functions
void init_screen(void);
void clear_screen(void);
void print_char(char c);
void print_string(const char* str);
void update_cursor(void);

// Internal functions - not exposed in header
// void backspace(void);
// void scroll_screen(void);

#endif 