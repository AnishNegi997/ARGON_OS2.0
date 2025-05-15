# Shell Lead

## Your Role
You are responsible for implementing the command-line interface, command processing, and user interaction.

## Learning Path

### 1. Shell Basics (Week 1)
- Command parsing
- Command execution
- Input/output handling
- Shell prompt design

### 2. Shell Commands (Week 2)
- Built-in commands
- External commands
- Command arguments
- Environment variables

### 3. Advanced Features (Weeks 3-4)
- Command history
- Tab completion
- Error handling
- User feedback

## Your Files

### Shell Core
```c
// shell/shell.c - You'll implement this
void shell_main(void);
void print_prompt(void);
void execute_command(const char* command);
void parse_arguments(char* command, char** args);
```

### Command Implementation
```c
// shell/commands.c - You'll implement this
// Built-in commands
void cmd_help(void);
void cmd_clear(void);
void cmd_echo(int argc, char** argv);
void cmd_ls(const char* path);
void cmd_cd(const char* path);
```

### Command Parser
```c
// shell/parser.c - You'll implement this
struct Command {
    char* name;
    char** args;
    int argc;
};

struct Command* parse_command_line(const char* input);
void free_command(struct Command* cmd);
```

## Key Deliverables
1. Working shell interface
2. Basic command set
3. Command history
4. Error handling

## Learning Resources

### Shell Fundamentals
1. **Shell Basics**
   - [Writing a Shell in C](https://brennan.io/2015/01/16/write-a-shell-in-c/)
   - [Shell Command Language](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html)
   - Key concepts:
     - Command parsing
     - Command execution
     - Shell builtins
     - Environment handling

2. **Input Processing**
   - [Line Editing](https://github.com/antirez/linenoise)
   - [Terminal Input](https://wiki.osdev.org/Terminal)
   - Practice tasks:
     - Read keyboard input
     - Handle special keys
     - Implement backspace

### Command Implementation
1. **Built-in Commands**
   - [Shell Commands Guide](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/contents.html)
   - [Command Implementation](https://wiki.osdev.org/Shell)
   - Implementation tasks:
     - help command
     - cd command
     - echo command
     - exit command

2. **External Commands**
   - [Process Creation](https://wiki.osdev.org/Process_Creation)
   - [Command Execution](https://wiki.osdev.org/Command_Line)
   - Projects:
     - Execute programs
     - Handle arguments
     - Manage environment

### Advanced Features
1. **Command History**
   - [History Implementation](https://github.com/antirez/linenoise/blob/master/linenoise.c)
   - [Command History Design](https://www.gnu.org/software/bash/manual/html_node/Command-History.html)
   - Practice:
     - Store commands
     - Navigate history
     - History search

2. **Tab Completion**
   - [Completion Tutorial](https://www.gnu.org/software/bash/manual/html_node/Programmable-Completion.html)
   - [Filename Completion](https://wiki.osdev.org/Filename_Completion)
   - Implementation:
     - Command completion
     - File completion
     - Context-aware completion

3. **Error Handling**
   - [Shell Error Handling](https://wiki.osdev.org/Error_Handling)
   - [Exit Codes](https://tldp.org/LDP/abs/html/exitcodes.html)
   - Tasks:
     - Error messages
     - Return codes
     - Error recovery

### Video Resources
1. [Build Your Own Shell](https://www.youtube.com/watch?v=z4LEuxMGGs8)
2. [Shell Programming Tutorial](https://www.youtube.com/playlist?list=PLS1QulWo1RIYmaxcEqw5JhK3b-6rgdWO_)

### Books
1. "Advanced Programming in the UNIX Environment"
2. "The Linux Programming Interface" - Shell chapters
3. "Unix Shell Programming" by Yashwant Kanetkar

### Practice Projects
1. **Week 1**: Basic command prompt
   - Read input
   - Parse commands
   - Execute built-ins

2. **Week 2**: Command execution
   - External commands
   - Arguments handling
   - Environment variables

3. **Week 3**: History and completion
   - Command history
   - Up/down navigation
   - Basic completion

4. **Week 4**: Advanced features
   - Tab completion
   - Error handling
   - Signal handling

### Debugging Tools
1. [Shell Script Debugger](https://www.gnu.org/software/bash/manual/html_node/Bash-POSIX-Mode.html)
2. [Command Line Tools](https://wiki.osdev.org/Command_Line_Tools)

### Example Shells to Study
1. **Dash**
   - Lightweight
   - Good for learning
   - Clean code

2. **Bash**
   - Feature-rich
   - Well-documented
   - Industry standard

### Community Resources
1. [Shell Programming Forum](https://unix.stackexchange.com/questions/tagged/shell)
2. [Bash Hackers Wiki](https://wiki.bash-hackers.org/)
3. [Shell Programming Guide](https://tldp.org/LDP/abs/html/)

### Testing Framework
```c
// shell_test.c
void test_command_parser() {
    char* input = "echo Hello World";
    struct Command* cmd = parse_command_line(input);
    assert(strcmp(cmd->name, "echo") == 0);
    assert(cmd->argc == 3);
    assert(strcmp(cmd->args[1], "Hello") == 0);
}

void test_command_execution() {
    // Test built-in commands
    assert(execute_command("help") == 0);
    assert(execute_command("cd /") == 0);
    
    // Test external commands
    assert(execute_command("ls -l") == 0);
}
```

## Testing Your Code
```c
// Example command implementation
void test_shell_commands() {
    // Test echo command
    char* args[] = {"echo", "Hello", "World", NULL};
    cmd_echo(3, args);
    
    // Test directory listing
    cmd_ls(".");
}
```

## Basic Commands to Implement
1. `help` - Show available commands
2. `clear` - Clear screen
3. `echo` - Print arguments
4. `ls` - List directory contents
5. `cd` - Change directory
6. `cat` - Display file contents
7. `mkdir` - Create directory
8. `rm` - Remove file/directory

## Dependencies with Other Roles
- Needs kernel services from Kernel Lead
- Uses process creation from Process Lead
- Requires file operations from File System Lead

## Shell Features Checklist
- [ ] Command prompt
- [ ] Command execution
- [ ] Built-in commands
- [ ] External commands
- [ ] Command history
- [ ] Tab completion
- [ ] Error messages
- [ ] User feedback 