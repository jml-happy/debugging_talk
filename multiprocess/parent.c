//
// Created by happy on 9/17/19.
//

#include <unistd.h>
#include <wait.h>
#include <errno.h>
#include "child.h"
#include "parent.h"
#include "circular_queue.h"
#include "globals.h"

int lock = 0;

int main() {
    ///// INIT ////
    master_Q = getNew_PN_Queue();
    master_Q_length = 0;
    for (int i = 0; i < NUM_PROCS; i++) {
        choosing[i] = false;
        ticket_array[i] = 0;
        should_loop[i] = 0;
    }

    // Hold return pid so we can check if parent or child
    for (int i = 0;i < NUM_CHILDREN; i++) {
        pid_t pid_ret = 0;
        pid_ret = fork();
        // true if child
        if (!pid_ret) {
            doChild(i);
        }
    }
    pid_t childpid;
    while ((childpid = waitpid(-1, NULL, WNOHANG)))
        if ((childpid == -1) && (errno != EINTR))
            break;
}