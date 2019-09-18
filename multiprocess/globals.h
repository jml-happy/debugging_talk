//
// Created by happy on 9/17/19.
//

#ifndef DEBUGGING_TALK_GLOBALS_H
#define DEBUGGING_TALK_GLOBALS_H

#include <stdbool.h>
#include "circular_queue.h"

#define DEBUG 1

#define NUM_CHILDREN 3
#define NUM_GRANDCHILDREN 3
#define NUM_PROCS (NUM_CHILDREN + NUM_GRANDCHILDREN)

#define QUEUE_SZ 15

extern int master_Q_length;
extern bool choosing[NUM_PROCS];
extern int ticket_array[NUM_PROCS];
extern bool should_loop[NUM_PROCS];
extern pid_num_Q master_Q;

#endif //DEBUGGING_TALK_GLOBALS_H
