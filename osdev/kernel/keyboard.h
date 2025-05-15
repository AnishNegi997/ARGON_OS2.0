#ifndef KEYBOARD_H
#define KEYBOARD_H

// Keyboard ports
#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

// Keyboard functions
void init_keyboard(void);
char getchar(void);
void handle_keypress(void);

#endif 