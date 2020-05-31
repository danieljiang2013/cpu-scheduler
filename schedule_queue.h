#ifndef SCHEDULE_QUEUE_H
#define SCHEDULE_QUEUE_H

#include "process.h"
// queue style linked list that contains processes waiting to be run on CPU
typedef struct schedule_queue_t{
    
    Process* head;

}Schedule_queue;

Schedule_queue* create_schedule_queue();

#endif