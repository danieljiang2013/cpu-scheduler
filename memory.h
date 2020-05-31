#ifndef MEMORY_H
#define MEMORY_H

#include "process.h"

//represents the memory that the CPU has access to
typedef struct memory_t{

    int mem_size; //size of memory in KB

    Process* process_queue_head; //head of linked list of processes in memory


}Memory;

Memory* initialize_memory(int mem_size);
void insert_in_memory(Memory* m, Process* p, int current_time);
Memory* load_disk_to_memory(Process* disk, Memory* memory, int num_processes, int current_time);

#endif