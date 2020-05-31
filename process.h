#ifndef PROCESS_H
#define PROCESS_H


typedef struct process_t{
    int time_arrived;
    int pid;
    int mem_size;
    int job_time;
    int job_time_remaining;
    int memory_insert_time; //what time the process was put into memory

    struct process_t* prev;
    struct process_t* next;
    
    
}Process;


Process* create_process(int time_arrived, int pid, int mem_size, int job_time);
Process* read_processes_to_disk(char* filename );

#endif