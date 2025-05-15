#ifndef PROCESS_H
#define PROCESS_H

#define MAX_PROCESSES 32
#define DEFAULT_QUANTUM 5

// Process states
typedef enum {
    READY,
    RUNNING,
    WAITING,
    TERMINATED
} ProcessState;

// Process structure
typedef struct {
    int pid;                    // Process ID
    char name[32];           // Process name
    ProcessState state;    // Current state
    int time_quantum;          // Time slice
    int burst_time;           // Total execution time needed
    int time_remaining;       // Time left to execute
} Process;

// Process queue
typedef struct {
    Process* processes[MAX_PROCESSES];
    int front;
    int rear;
    int size;
} Queue;

// Process management functions
void init_scheduler(void);
int create_process(const char* name, int burst_time);
void kill_process(int pid);
void schedule(void);
void display_processes(void);
int is_process_alive(int pid);
int get_running_process_count(void);

// Queue operations
void queue_init(Queue* q);
void queue_push(Queue* q, Process* p);
Process* queue_pop(Queue* q);
int queue_is_empty(Queue* q);

#endif 