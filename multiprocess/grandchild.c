//
// Created by happy on 9/17/19.
//

#include <unistd.h>
#include <stdio.h>
#include "globals.h"
#include "bakery.h"
#include "grandchild.h"

void doGrandChild(int my_id) {
#if DEBUG
    printf("I'm a grandchild and my num is: %d, and my PID is: %d\n", my_id, getpid());
#endif
    goToBakery_GRANDCHILD(my_id);
}