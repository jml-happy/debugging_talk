//
// Created by happy on 9/18/19.
//

#ifndef DEBUGGING_TALK_CIRCULAR_QUEUE_H
#define DEBUGGING_TALK_CIRCULAR_QUEUE_H

#include <unistd.h>

typedef struct _Q_nd {
    pid_t producer_pid; // parent
    pid_t consumer_pid; // child
    int number;
    struct _Q_nd *next;
} Q_nd;

typedef struct _Q {
    Q_nd * head;
    Q_nd * tail;
}pid_num_Q;

//// Functions to implement a fi_Queue (queue of file_info structs)

// new fi_Queue
pid_num_Q getNew_PN_Queue();

// get new node
Q_nd * getNewPN_Node(int i);

// Push an element to the queue
void PN_Queue_PUSH(pid_num_Q *const Q, Q_nd* new_node);

// Pop the head element from the queue and return a pointer to it
Q_nd * PN_Queue_POP(pid_num_Q *const Q);

// Free an entire queue
void PN_Queue_FREE(pid_num_Q *const Q);

#endif //DEBUGGING_TALK_CIRCULAR_QUEUE_H
