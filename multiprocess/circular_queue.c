//
// Created by happy on 9/18/19.
//

#include <stdlib.h>
#include "circular_queue.h"

// new fi_Queue
pid_num_Q getNew_PN_Queue() {
    pid_num_Q Q;
    Q.head = NULL;
    Q.tail = NULL;
    return Q;
}

Q_nd * getNewPN_Node(int i) {
    Q_nd * p = malloc(sizeof(Q_nd));
    p->next = NULL;
    p->number = i;
    p->consumer_pid = NULL;
    p->producer_pid = getpid;
    return p;
}

// Push an element onto the queue
void PN_Queue_PUSH(pid_num_Q *const Q, Q_nd* new_node) {
    if (Q->head == NULL) {
        Q->head = new_node;
    }
    if (Q->tail != NULL) {
        Q->tail->next = new_node;
    }
    Q->tail = new_node;
}

// Pop the head element from the queue and return it
Q_nd * PN_Queue_POP(pid_num_Q *const Q) {
    Q_nd * p = Q->head;
    if (p != NULL)
        Q->head = Q->head->next;
    return p;
}

// Free an entire queue
void PN_Queue_FREE(pid_num_Q *const Q) {
    if (Q == NULL)
        return;

    Q_nd *tmp;
    while (Q->head != NULL) {
        tmp = Q->head;
        Q->head = Q->head->next;
        free(tmp);
    }
    Q->tail = NULL;
}