#include "process.h"
#include "../include/kernel.h"

// Global variables
static Process processes[MAX_PROCESSES];
static int next_pid = 0;
static Queue ready_queue;
static Process* current_process = NULL;

// Initialize the scheduler
void init_scheduler() {
    // Initialize process table
    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes[i].pid = -1;  // -1 indicates unused slot
        processes[i].state = TERMINATED;
        processes[i].name[0] = '\0';  // Empty name
        processes[i].time_quantum = 0;
        processes[i].burst_time = 0;
        processes[i].time_remaining = 0;
    }
    
    // Initialize ready queue
    queue_init(&ready_queue);
    current_process = NULL;
    next_pid = 0;
}

// Create a new process
int create_process(const char* name, int burst_time) {
    // Find a free process slot
    int pid = -1;
    for (int i = 0; i < MAX_PROCESSES; i++) {
        if (!is_process_alive(i)) {
            pid = i;
            break;
        }
    }

    if (pid == -1) {
        return -1; // No free slots
    }

    // Initialize the process
    Process* new_process = &processes[pid];
    new_process->pid = pid;
    strncpy(new_process->name, name, 31);
    new_process->name[31] = '\0';  // Ensure null termination
    new_process->state = READY;
    new_process->time_quantum = burst_time;
    new_process->burst_time = burst_time;
    new_process->time_remaining = burst_time;

    // Add to ready queue
    queue_push(&ready_queue, new_process);
    
    // Run one scheduling cycle to start it
    schedule();

    return pid;
}

// Kill a process
void kill_process(int pid) {
    if (pid < 0 || pid >= MAX_PROCESSES) {
        return;  // Invalid PID
    }
    
    Process* proc = &processes[pid];
    if (proc->state == TERMINATED) {
        return;  // Process already terminated
    }
    
    // Mark process as terminated
    proc->state = TERMINATED;
    proc->time_remaining = 0;
    
    // If this is the current process, schedule next one
    if (current_process && current_process->pid == pid) {
        current_process = NULL;
        schedule();
    }
}

// Check if a process is still alive
int is_process_alive(int pid) {
    if (pid < 0 || pid >= MAX_PROCESSES) {
        return 0;  // Invalid PID
    }
    return processes[pid].state != TERMINATED;
}

// Get count of running processes
int get_running_process_count() {
    int count = 0;
    for (int i = 0; i < MAX_PROCESSES; i++) {
        if (processes[i].state != TERMINATED && processes[i].pid != -1) {
            count++;
        }
    }
    return count;
}

// Schedule the next process
void schedule() {
    // Check if current process is done
    if (current_process != NULL) {
        if (current_process->time_remaining <= 0) {
            current_process->state = TERMINATED;
            print_string("Process terminated: ");
            print_string(current_process->name);
            print_char('\n');
            current_process = NULL;
        } else if (current_process->time_quantum <= 0) {
            // Reset quantum and put back in queue
            current_process->time_quantum = DEFAULT_QUANTUM;
            current_process->state = READY;
            queue_push(&ready_queue, current_process);
            current_process = NULL;
        } else {
            current_process->time_quantum--;
            current_process->time_remaining--;
            return;  // Continue running current process
        }
    }
    
    // Get next process from ready queue
    if (!queue_is_empty(&ready_queue)) {
        current_process = queue_pop(&ready_queue);
        current_process->state = RUNNING;
        
        print_string("Running process: ");
        print_string(current_process->name);
        print_char('\n');
    }
}

// Display all processes
void display_processes() {
    int found = 0;
    print_string("=== Active Processes ===\n");
    
    // First show running process if any
    if (current_process != NULL) {
        print_string("PID: ");
        print_int(current_process->pid);
        print_string(" Name: ");
        print_string(current_process->name);
        print_string(" State: RUNNING");
        print_string(" Time Remaining: ");
        print_int(current_process->time_remaining);
        print_char('\n');
        found = 1;
    }
    
    // Then show other processes
    for (int i = 0; i < MAX_PROCESSES; i++) {
        Process* p = &processes[i];
        if (p->pid != -1 && p != current_process && p->state != TERMINATED) {
            print_string("PID: ");
            print_int(p->pid);
            print_string(" Name: ");
            print_string(p->name);
            print_string(" State: ");
            
            switch(p->state) {
                case READY:
                    print_string("READY");
                    break;
                case WAITING:
                    print_string("WAITING");
                    break;
                default:
                    print_string("UNKNOWN");
                    break;
            }
            
            print_string(" Time Remaining: ");
            print_int(p->time_remaining);
            print_char('\n');
            found = 1;
        }
    }
    
    if (!found) {
        print_string("No active processes.\n");
    }
    print_string("=====================\n");
}

// Queue operations
void queue_init(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

void queue_push(Queue* q, Process* p) {
    if (q->size >= MAX_PROCESSES) {
        return;  // Queue is full
    }
    q->rear = (q->rear + 1) % MAX_PROCESSES;
    q->processes[q->rear] = p;
    q->size++;
}

Process* queue_pop(Queue* q) {
    if (q->size <= 0) {
        return NULL;  // Queue is empty
    }
    Process* p = q->processes[q->front];
    q->front = (q->front + 1) % MAX_PROCESSES;
    q->size--;
    return p;
}

int queue_is_empty(Queue* q) {
    return q->size == 0;
} 