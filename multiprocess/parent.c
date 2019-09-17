//
// Created by happy on 9/17/19.
//

#include <unistd.h>
#include <wait.h>

int main() {

    // Store children's PID's
    pid_t children[5];
    // Hold return pid so we can check if parent or child
    pid_t pid_ret = 0;
    for (int i = 0;i < 5; i++) {
        pid_ret = fork();
        // true if child
        if (!pid_ret) {
            /* exec child */
        }
    }
    pid_t wait_ret = 0;
    wait_ret =  wait(NULL);

}