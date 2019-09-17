//
// Created by happy on 9/17/19.
//

#include "globals.h"

int cur_max = 0;

bool choosing[NUM_PROCS] = {false, false,
                            false, false,
                            false, false,
                            false, false,
                            false, false};

int number[NUM_PROCS] = {0, 0,
                         0, 0,
                         0, 0,
                         0, 0,
                         0, 0};

bool should_loop[NUM_PROCS] = {true, true,
                               true, true,
                               true, true,
                               true, true,
                               true, true};