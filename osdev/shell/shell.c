#include "../kernel/screen.h"
#include "../kernel/keyboard.h"
#include "shell.h"
#include "commands.h"
#include <stddef.h>

// Prototype for int_to_string implemented in kernel.c
void int_to_string(int num, char* str);

#define MAX_COMMAND_LENGTH 256
#define MAX_ARGS 16
#define HISTORY_SIZE 2

// Buffer for command input
static char input[MAX_COMMAND_LENGTH];
static int pos = 0;

// Command history
static char history[HISTORY_SIZE][MAX_COMMAND_LENGTH] = {0};
static int history_count = 0;
static int history_pos = 0;
static int navigating_history = 0;

// Helper to redraw the input line
void redraw_input() {
    print_char('\r');           // Move cursor to start of line
    print_string("$ ");
    print_string(input);
    pos = strlen(input);
}

// Handle keyboard input
void handle_input(char c) {
    // Arrow key handling (assuming get_arrow_key returns special codes)
    if ((unsigned char)c == 0x80) { // Up arrow
        if (history_count > 0) {
            if (!navigating_history) {
                history_pos = history_count - 1;
                navigating_history = 1;
            } else if (history_pos > 0) {
                history_pos--;
            }
            if (history_pos >= 0 && history_pos < history_count) {
                memset(input, 0, MAX_COMMAND_LENGTH);
                int idx = (history_count <= HISTORY_SIZE) ? history_pos : (history_pos % HISTORY_SIZE);
                strncpy(input, history[idx], MAX_COMMAND_LENGTH - 1);
                input[MAX_COMMAND_LENGTH - 1] = '\0';
                redraw_input();
            }
        }
        return;
    }
    if ((unsigned char)c == 0x81) { // Down arrow
        if (navigating_history && history_count > 0) {
            if (history_pos < history_count - 1) {
                history_pos++;
                if (history_pos >= 0 && history_pos < history_count) {
                    memset(input, 0, MAX_COMMAND_LENGTH);
                    int idx = (history_count <= HISTORY_SIZE) ? history_pos : (history_pos % HISTORY_SIZE);
                    strncpy(input, history[idx], MAX_COMMAND_LENGTH - 1);
                    input[MAX_COMMAND_LENGTH - 1] = '\0';
                    redraw_input();
                }
            } else {
                navigating_history = 0;
                memset(input, 0, MAX_COMMAND_LENGTH);
                redraw_input();
            }
        }
        return;
    }
    if (c == '\n') {
        print_string("\n");
        input[pos] = '\0';
        execute_command(input);
        // Store in history if not empty
        if (pos > 0) {
            strncpy(history[history_count % HISTORY_SIZE], input, MAX_COMMAND_LENGTH - 1);
            history[history_count % HISTORY_SIZE][MAX_COMMAND_LENGTH - 1] = '\0';
            history_count++;
        }
        memset(input, 0, MAX_COMMAND_LENGTH); // Clear buffer
        pos = 0;
        navigating_history = 0;
        redraw_input();
        return;
    }
    else if (c == '\b') {
        if (pos > 0) {
            pos--;
            input[pos] = '\0';
            backspace();
        }
    }
    else if (pos < MAX_COMMAND_LENGTH - 1) {
        input[pos++] = c;
        print_char(c);
    }
}

// Initialize shell
void init_shell(void) {
    clear_screen();
    print_string("Welcome to AGRAN OS v0.1\n");
    print_string("Type 'help' for a list of commands\n\n");
    print_string("$ ");
    pos = 0;
}

// Run the shell
void run_shell(void) {
    while (1) {
        handle_input(getchar());
    }
}

// Move cursor back and clear character
void backspace(void) {
    print_char('\b');  // Move cursor back
    print_char(' ');   // Clear the character
    print_char('\b');  // Move cursor back again
} 