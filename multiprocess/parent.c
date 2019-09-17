//
// Created by happy on 9/17/19.
//

#include <unistd.h>
#include <wait.h>
#include <errno.h>
#include "child.h"

int lock = 0;

int main() {

    // Store children's PID's
    pid_t children[5];
    // Hold return pid so we can check if parent or child
    pid_t pid_ret = 0;
    for (int i = 0;i < 5; i++) {
        pid_ret = fork();
        // true if child
        if (!pid_ret) {
            doChild();
        }
    }
    pid_t childpid;
    while (childpid = waitpid(-1, NULL, WNOHANG))
        if ((childpid == -1) && (errno != EINTR))
            break;
}