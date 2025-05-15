#ifndef SHELL_H
#define SHELL_H

#include <string.h>

// Maximum command length and arguments
#define MAX_COMMAND_LENGTH 256
#define MAX_ARGS 16

// Shell functions
void init_shell(void);
void handle_input(char c);
void backspace(void);

#endif 