//
// Created by happy on 9/17/19.
//

#include "globals.h"

bool choosing[NUM_PROCS] = {false, false,
                            false, false,
                            false, false,
                            false, false,
                            false, false};

int ticket_array[NUM_PROCS] = {0, 0,
                               0, 0,
                               0, 0,
                               0, 0,
                               0, 0};

bool should_loop[NUM_PROCS] = {true, true,
                               true, true,
                               true, true,
                               true, true,
                               true, true};