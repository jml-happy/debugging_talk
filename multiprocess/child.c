//
// Created by happy on 9/17/19.
//

#include <unistd.h>
#include <errno.h>
#include <wait.h>
#include <stdio.h>
#include "globals.h"
#include "bakery.h"
#include "grandchild.h"

void doChild(int my_id) {
#if DEBUG
    printf("I'm a child and my num is: %d, and my PID is: %d\n", my_id, getpid());
#endif
    for (int i = 0; i < NUM_GRANDCHILDREN; i++) {
        pid_t pid_ret = 0;
        pid_ret = fork();
        // true if child
        if (!pid_ret) {
            doGrandChild( (NUM_CHILDREN*(my_id + 1)) +i);
        }
    }
    goToBakery_CHILD(my_id);
    pid_t childpid;
    while ((childpid = waitpid(-1, NULL, WNOHANG)))
        if ((childpid == -1) && (errno != EINTR))
            break;
}