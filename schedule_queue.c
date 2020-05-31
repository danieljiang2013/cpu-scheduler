#include <stdlib.h>
#include "schedule_queue.h"
#include "process.h"

/**create and return pointer to start of schedule queue, 
 * 
**/
Schedule_queue* create_schedule_queue(){
    Schedule_queue* s = malloc(sizeof(Schedule_queue));
    return s;
}