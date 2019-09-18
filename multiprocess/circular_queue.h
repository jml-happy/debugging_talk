//
// Created by happy on 9/18/19.
//

#ifndef DEBUGGING_TALK_CIRCULAR_QUEUE_H
#define DEBUGGING_TALK_CIRCULAR_QUEUE_H

#include <unistd.h>

struct _cq_node {
    pid_t producer_pid; // parent
    pid_t consumer_pid; // child
    int number; //
    struct _cq_node *next;
};

#endif //DEBUGGING_TALK_CIRCULAR_QUEUE_H
