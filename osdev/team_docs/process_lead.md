# Process Management Lead

## Your Role
You are responsible for process creation, scheduling, and inter-process communication.

## Learning Path

### 1. Process Basics (Week 1)
- Understanding processes vs threads
- Process states and lifecycle
- Context switching
- Process control blocks (PCB)

### 2. Scheduling (Week 2)
- Round-robin scheduling
- Process queues
- Timer interrupts
- Task switching

### 3. Inter-Process Communication (Weeks 3-4)
- Message passing
- Shared memory
- Synchronization primitives
- Process coordination

## Your Files

### Process Management
```c
// process/process.c - You'll implement this
struct PCB {
    int pid;
    void* stack_pointer;
    enum ProcessState state;
    // ... more fields
};

int create_process(void (*function)());
void terminate_process(int pid);
void schedule_next_process(void);
```

### Scheduler
```c
// process/scheduler.c - You'll implement this
void init_scheduler(void);
void schedule(void);
void add_to_queue(struct PCB* process);
```

### IPC
```c
// process/ipc.c - You'll implement this
void send_message(int to_pid, void* msg, size_t size);
void* receive_message(int from_pid);
void* create_shared_memory(size_t size);
```

## Key Deliverables
1. Process creation and termination
2. Round-robin scheduler
3. Basic IPC mechanisms
4. Context switching

## Learning Resources
1. [OSDev Wiki - Processes](https://wiki.osdev.org/Processes)
2. [Operating Systems: Three Easy Pieces - Process Chapter](https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-intro.pdf)
3. [Little Book of Semaphores](https://greenteapress.com/wp/semaphores/)

## Testing Your Code
```c
// Example test process
void test_process() {
    while(1) {
        print_string("Process running...\n");
        yield();
    }
}

// Test creation
int pid = create_process(test_process);
```

## Dependencies with Other Roles
- Needs memory management from Kernel Lead
- Shell Lead will use your process creation
- File System Lead needs process info for file handles 