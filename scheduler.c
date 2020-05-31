#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#include "process.h"
#include "memory.h"
#include "schedule_queue.h"

//function prototypes
void scheduler_simulation(Process* disk, char* algo, char* mem_algo, Memory* memory, int total_processes);

//reads input variables and populates the virtual disk with processes to be run
int main(int argc, char* argv[]){

    char* filename; //input filename
    char* algo; //ff, rr or cs
    char* mem_algo;
    int mem_size;
    int quantum = 10; //default quantum size of 10s

    //scan command line for input variables
    char input;
    while ((input = getopt(argc, argv, "f:a:m:s:q:")) != EOF){
        switch (input){
            //set input filename
            case 'f':
                filename = optarg;
                break;

            //set scheduling-algorithm
            case 'a':
                algo = optarg;
                break;
            
            //set memory-allocation algorithm
            case 'm':
                mem_algo = optarg;
                break;

            //set memory size
            case 's':
                mem_size = atoi(optarg);
                break;
            
            //set quantum
            case 'q':
                quantum = atoi(optarg);
                break;
        }
    }
    /**
    printf("filename: %s\n",filename);
    printf("algorithm: %s\n",algo);
    printf("mem_algo: %s\n",mem_algo);
    **/
    //create memory of specified size
    Memory* memory = initialize_memory(mem_size);

    //read the processes onto a "disk" which is a linked list of all the processes that will be run
    Process* disk = read_processes_to_disk(filename);

    //traverse the disk list and count how many processes there are in total
    int total_processes = 0;
    Process* p = disk;
    while(p!=NULL){
        total_processes++;
        p=p->next;
    }
    //run the scheduling simulation
    scheduler_simulation(disk, algo, mem_algo, memory, total_processes);
}

//runs the actual scheduling simulation, given the list of proceeses, algorithm
//TODO: implement memory simulation
void scheduler_simulation(Process* disk, char* algo, char* mem_algo, Memory* memory, int total_processes){

    //keeps track of current time
    int clock = 0;
    //keep track of number of remaining processes
    int remaining_processes = total_processes;

    int CPU_STATE = 0;//0 = idle, 1 = running

    /**load processes from disk to memory, depending on memory algorithm used and mem_size
    if unlimited memory, load all processes into memory at the beginning (implement this first)
    **/

    if (strcasecmp(mem_algo, "u") == 0){
        //load all processes from disk into memory
        load_disk_to_memory(disk, memory, -1, clock);
    }
    double max_overhead = 0, avg_overhead = 0, current_overhead = 0, total_overhead = 0;
    int turnaround_total = 0;
    int finish_times[total_processes]; //keep track of process finishing times

    //perform CPU scheduling 
    //first-come first-served algorithm
    if (strcasecmp(algo, "ff") == 0){

        Process* temp = memory->process_queue_head;

        //while there are processes in memory to run, run them
        while(temp!=NULL){

            printf("%d, RUNNING, id=%d, remaining-time=%d\n",clock, temp->pid,temp->job_time_remaining);
            clock+=temp->job_time;//increment clock by amount of time spent on process


            //current process has finished, calculate statistics and move onto next
            finish_times[total_processes-remaining_processes] = clock;
            current_overhead = (double)(clock - temp->time_arrived) / (double)temp->job_time;
            total_overhead+=current_overhead;
            if (current_overhead > max_overhead){
                max_overhead=current_overhead;}

            remaining_processes--;
            printf("%d, FINISHED, id=%d, proc-remaining=%d\n",clock, temp->pid, remaining_processes);
            turnaround_total+=clock-temp->time_arrived;
            temp=temp->next;
        }

    }

    //round-robin scheduling algorithm
    if (strcasecmp(algo, "rr") == 0){

    }

    //print final statistics 

    //calculate througput; average, minimum and maximum number of processes completed in 60s intervals
    //avg is rounded up to nearest int
    int avg_throughput = 0, min_througput = total_processes, max_througput = 0;

    int current_interval_end = 60;
    int current_time = 1;
    int i=0;
    int count = 0;
    while(i < total_processes){
        current_time = finish_times[i];
        if (current_time <= current_interval_end){
            
            count++;
            if (count>max_througput){
                max_througput = count;
            }
            i++;
        }
        else{//go next interval
            if (count<min_througput){
                min_througput = count;
            }
            current_interval_end+=60;
            count = 0;
        }
    }
    avg_throughput = total_processes/(clock/60);
    printf("Throughput %d, %d, %d\n", avg_throughput, min_througput, max_througput);
    //average turnaround time rounded up to nearest integer
    printf("Turnaround time %d\n",(turnaround_total+total_processes-1)/total_processes);
    //Calculate maximum and average overhead time (rounded to 2 decimal), overhead = turnaround / job time
    avg_overhead = total_overhead / total_processes;
    printf("Time overhead %.2f %.2f\n", max_overhead, avg_overhead);
    printf("Makespan %d",clock);

}