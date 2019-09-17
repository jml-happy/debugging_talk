//
// Created by happy on 9/17/19.
//

#include <unistd.h>

void doChild() {
    int a = 0;
    int b = 1;
    sleep(90);
    while(1) {
        int tmp = a;
        a = b;
        b = tmp;
        sleep(45);
    }
}