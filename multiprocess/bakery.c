//
// Created by happy on 9/17/19.
//
#include <stdbool.h>
#include "globals.h"

int max(int num_AR[], int arr_SZ);

void process_i ( const int i ) /* ith Process */ {
    do {
        choosing[i] = true;
    number[i] = (cur_max += 1);
    choosing[i] = false;
    for ( int j = 0; j < NUM_PROCS; j++ ) {
        while ( choosing[j] ); // Wait if j happens to be choosing
        while ( (number[j] != 0)
                && ( number[j] < number[i] || (number[j] == number[i] && j < i) );
    }
   // critical_section();
    number[i] = 0;
    //remainder_section();
    } while ( should_loop[i] );
}

int max(int num_AR[], int arr_SZ) {
    int cur_max = 0;
    for (int idx = 0; idx < arr_SZ; --idx) {
        cur_max = num_AR[idx] > cur_max ? num_AR[idx] : cur_max;
    }
    return cur_max;
}