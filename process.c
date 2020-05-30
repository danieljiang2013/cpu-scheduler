#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "process.h"
#define BUFFER_SIZE 256


//creates and returns a pointer to a Process 
Process* create_process(int time_arrived, int pid, int mem_size, int job_time){

    Process* p = malloc(sizeof(Process));

    p->time_arrived = time_arrived;
    p->pid = pid;
    p->mem_size = mem_size;
    p->job_time = job_time;
    p->job_time_remaining = job_time;

    
    return p;
}


/*** reads list of processes from input file and stores them as a linked list of Processes, meant to simulate a disk. 
***  Should only be called once at start of simulation
***/
Process* read_processes_to_disk(char* filename ){

    char buffer[BUFFER_SIZE];
    FILE* fp;
    fp = fopen(filename, "r");

    //keeps track of whether disk is empty or not
    bool empty = true;

    //read processes from file line by line and create a Process object for each
    while (fgets(buffer, BUFFER_SIZE, fp)){

        int time_arrived;
        int pid;
        int mem_size;
        int job_time;

        sscanf(buffer,"%d%d%d%d",&time_arrived,&pid,&mem_size,&job_time);
    }
    
    Process* disk_head;
    Process* disk_tail = NULL;
    Process* current_process;
    
    //create the first process, this process serves as the head of the disk
    if(empty){
        current_process = create_process(time_arrived, pid, mem_size, job_time);
        current_process->prev = NULL;
        disk_head = current_process;
        disk_tail = current_process;
        empty = false;
    }

    //add current process onto end of disk list
    else{
        current_process = create_process(time_arrived, pid, mem_size, job_time);
        current_process->next = NULL;
        
        current_process->prev = disk_tail;

    }
    Process* p = malloc(sizeof(Process));
    return p;
}