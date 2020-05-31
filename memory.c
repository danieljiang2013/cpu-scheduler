#include "memory.h"
#include "process.h"
#include <stdlib.h>
#include <stdio.h>


//initialize the memory
Memory* initialize_memory(int mem_size){
    Memory* m = malloc(sizeof(Memory));

    m->mem_size = mem_size;

    return m;
}


// insert a process into the end of memory queue
void insert_in_memory(Memory* m, Process* p, int current_time){

    Process* head = m->process_queue_head;   

    //if memory is empty, insert at head
    if (head == NULL){

        head = p;
        head->next = NULL;
        head->prev = NULL;
    }
}


//loads specified amount of processes from disk into memory
//returns pointer to memory with processes loaded in
Memory* load_disk_to_memory(Process* disk, Memory* memory, int num_processes, int current_time){
    
    //if num_processes = -1, no limit, load all processes into memory
    if (num_processes==-1){
        memory->process_queue_head = disk;

        Process* temp = memory->process_queue_head;

        while (temp!=NULL){
            temp->memory_insert_time = current_time;
            //printf("temp_time_insert: %d\n", temp->memory_insert_time);
            temp=temp->next;
        }
        
    }


    return memory;
}