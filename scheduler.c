#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#include "process.h"
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

    printf("filename: %s\n",filename);
    printf("algorithm: %s\n",algo);
    printf("mem_algo: %s\n",mem_algo);
    
    //read the processes onto a "disk" which is a linked list of all the processes that will be run
    Process* disk = read_processes_to_disk(filename);
    //traverse the disk list

    Process* p = disk;
    while(p!=NULL){
        printf("pid: %d\n",p->pid);
        p=p->next;
    }


}