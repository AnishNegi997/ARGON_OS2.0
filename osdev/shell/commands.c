#include "../include/kernel.h"
#include "../fs/fs.h"
#include "../process/process.h"
#include "../kernel/screen.h"
#include "commands.h"
#include <stddef.h>

#define MAX_ARGS 16
#define MAX_CONTENT 1024

// Helper function to parse command string into argc/argv
static int parse_command(const char* command, char* argv[]) {
    int argc = 0;
    static char cmd_copy[MAX_CONTENT];
    
    // Make a copy of the command
    int i;
    for(i = 0; command[i] != '\0' && i < MAX_CONTENT - 1; i++) {
        cmd_copy[i] = command[i];
    }
    cmd_copy[i] = '\0';
    
    char* token = cmd_copy;
    
    // Skip leading spaces
    while (*token == ' ') token++;
    
    // Parse arguments
    while (*token && argc < MAX_ARGS) {
        argv[argc++] = token;
        
        // Find end of argument
        while (*token && *token != ' ') token++;
        
        // Replace space with null terminator
        if (*token) *token++ = '\0';
        
        // Skip spaces between arguments
        while (*token == ' ') token++;
    }
    
    return argc;
}

// Built-in commands
void cmd_help(void) {
    print_string("\n=== Available Commands ===\n\n");
    
    // Basic system commands
    print_string("help      - Show available commands\n");
    print_string("clear     - Clear screen\n");
    print_string("echo      - Echo the arguments\n");
    print_string("info      - Show system information\n");
    print_string("version   - Show OS version\n");
    print_string("shutdown  - Shutdown the system\n");
    print_string("reboot    - Reboot the system\n");
    
    // File system commands
    print_string("\nFile System:\n");
    print_string("ls        - List all files in system\n");
    print_string("create    - Create a new file (create filename)\n");
    print_string("write     - Write text to file (write filename text)\n");
    print_string("read      - Read file contents (read filename)\n");
    print_string("delete    - Delete a file (delete filename)\n");
    
    // Process commands
    print_string("\nProcess Management:\n");
    print_string("ps        - Show all running processes\n");
    print_string("run       - Start a new process (run processname)\n");
    print_string("kill      - Stop a process (kill pid)\n");
    print_string("demo      - Run process scheduling demo\n");
    print_string("\n");
}

void cmd_clear(void) {
    clear_screen();
}

void cmd_echo(const char* text) {
    if (text == NULL) {
        print_string("Usage: echo [text]\n");
        return;
    }
    print_string(text);
    print_string("\n");
}

void cmd_info(void) {
    print_string("\nAGRAN OS System Information\n");
    print_string("==========================\n");
    print_string("OS Name: AGRAN OS\n");
    print_string("Version: 1.0\n");
    print_string("Architecture: x86\n");
    print_string("Memory: 1.44 MB\n");
    print_string("Features:\n");
    print_string("- Basic File System\n");
    print_string("- Process Management\n");
    print_string("- Round Robin Scheduling\n");
    print_string("==========================\n");
}

void cmd_version(void) {
    print_string("AGRAN OS version 1.0\n");
}

void cmd_shutdown(void) {
    print_string("\nShutting down AGRAN OS...\n");
    print_string("It is now safe to turn off your computer.\n");
    shutdown();
}

void cmd_reboot(void) {
    print_string("\nRebooting AGRAN OS...\n");
    reboot();
}

// File system commands
void cmd_ls(int argc, char* argv[]) {
    (void)argc;
    (void)argv;
    list_files();
}

void cmd_create(int argc, char* argv[]) {
    if (argc < 2) {
        print_string("Usage: create <filename>\n");
        return;
    }
    create_file(argv[1]);
}

void cmd_write(int argc, char* argv[]) {
    if (argc < 3) {
        print_string("Usage: write <filename> <content>\n");
        return;
    }
    write_file(argv[1], argv[2]);
}

void cmd_read(int argc, char* argv[]) {
    if (argc < 2) {
        print_string("Usage: read <filename>\n");
        return;
    }
    char buffer[MAX_CONTENT];
    if (read_file(argv[1], buffer) >= 0) {
        print_string(buffer);
        print_string("\n");
    }
}

void cmd_delete(int argc, char* argv[]) {
    if (argc < 2) {
        print_string("Usage: delete <filename>\n");
        return;
    }
    delete_file(argv[1]);
}

// Process commands
void cmd_ps(int argc, char* argv[]) {
    (void)argc;
    (void)argv;
    display_processes();
}

void cmd_run(int argc, char* const argv[]) {
    if (argc < 2) {
        print_string("Error: Please provide a process name\n");
        print_string("Usage: run <process_name>\n");
        return;
    }

    // Create the process with a default burst time
    int pid = create_process(argv[1], DEFAULT_QUANTUM);
    if (pid >= 0) {
        print_string("Created process '");
        print_string(argv[1]);
        print_string("' with PID ");
        print_int(pid);
        print_string("\n");
    } else {
        print_string("Error: Failed to create process '");
        print_string(argv[1]);
        print_string("'\n");
    }
}

void cmd_kill(int argc, char* const argv[]) {
    if (argc < 2) {
        print_string("Usage: kill <pid>\n");
        return;
    }
    int pid = string_to_int(argv[1]);
    if (is_process_alive(pid)) {
        kill_process(pid);
        print_string("Killed process with PID ");
        print_string(argv[1]);
        print_string("\n");
    } else {
        print_string("No such process with PID ");
        print_string(argv[1]);
        print_string("\n");
    }
}

// Demo commands
void cmd_demo(int argc, char* argv[]) {
    (void)argc;
    (void)argv;
    print_string("\n=== Process Scheduling Demo ===\n");
    
    // Create test processes with shorter quantum times
    create_process("Task1", 2);
    create_process("Task2", 2);
    create_process("Task3", 2);
    
    // Run scheduling for a limited number of cycles
    print_string("\nRunning processes for demo...\n");
    for (int i = 0; i < 6; i++) {
        schedule();
        // Add a small delay between schedules
        for (volatile int j = 0; j < 1000000; j++) {}
    }
    
    // Clean up any remaining processes
    for (int i = 0; i < MAX_PROCESSES; i++) {
        if (is_process_alive(i)) {
            kill_process(i);
        }
    }
    
    print_string("\nDemo completed.\n");
}

void cmd_filedemo(int argc, char* argv[]) {
    (void)argc;
    (void)argv;
    print_string("\n=== File System Demo ===\n");
    create_file("test.txt");
    write_file("test.txt", "Hello, AGRAN OS!");
    print_string("Reading test.txt: ");
    char buffer[256];
    read_file("test.txt", buffer);
    print_string(buffer);
    print_char('\n');
    list_files();
    delete_file("test.txt");
    list_files();
}

// Command execution
void execute_command(const char* command) {
    char* argv[MAX_ARGS];
    int argc = parse_command(command, argv);
    
    if (argc == 0) return;
    
    // System commands
    if (strcmp(argv[0], "help") == 0) cmd_help();
    else if (strcmp(argv[0], "clear") == 0) cmd_clear();
    else if (strcmp(argv[0], "echo") == 0) cmd_echo(argc > 1 ? argv[1] : NULL);
    else if (strcmp(argv[0], "info") == 0) cmd_info();
    else if (strcmp(argv[0], "version") == 0) cmd_version();
    else if (strcmp(argv[0], "shutdown") == 0) cmd_shutdown();
    else if (strcmp(argv[0], "reboot") == 0) cmd_reboot();
    
    // File system commands
    else if (strcmp(argv[0], "ls") == 0) cmd_ls(argc, argv);
    else if (strcmp(argv[0], "create") == 0) cmd_create(argc, argv);
    else if (strcmp(argv[0], "write") == 0) cmd_write(argc, argv);
    else if (strcmp(argv[0], "read") == 0) cmd_read(argc, argv);
    else if (strcmp(argv[0], "delete") == 0) cmd_delete(argc, argv);
    
    // Process commands
    else if (strcmp(argv[0], "ps") == 0) cmd_ps(argc, argv);
    else if (strcmp(argv[0], "run") == 0) cmd_run(argc, argv);
    else if (strcmp(argv[0], "kill") == 0) cmd_kill(argc, argv);
    else if (strcmp(argv[0], "demo") == 0) cmd_demo(argc, argv);
    
    else {
        print_string("Unknown command: ");
        print_string(argv[0]);
        print_string("\nType 'help' for available commands\n");
    }
} 