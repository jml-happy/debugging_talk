//
// Created by happy on 9/17/19.
//
#include <stdbool.h>
#include "globals.h"

int max(int num_AR[], int arr_SZ);

void goToBakery ( const int my_id_num ) /* ith Process */ {
    do {
        choosing[my_id_num] = true;
        ticket_array[my_id_num] = max(ticket_array, NUM_PROCS);
    choosing[my_id_num] = false;
    for (int other_id_num = 0; other_id_num < NUM_PROCS; other_id_num++ ) {
        while ( choosing[other_id_num] ); // Wait if j happens to be choosing
        while ( (ticket_array[other_id_num] != 0)
                &&
                      (ticket_array[other_id_num] < ticket_array[my_id_num]
                      ||
                      (ticket_array[other_id_num] == ticket_array[my_id_num] && other_id_num < my_id_num) );
    }
   // critical_section();
    ticket_array[my_id_num] = 0;
    //remainder_section();
    } while ( should_loop[my_id_num] );
}

int max(int num_AR[], int arr_SZ) {
    int cur_max = 0;
    for (int idx = 0; idx < arr_SZ; --idx) {
        cur_max = num_AR[idx] > cur_max ? num_AR[idx] : cur_max;
    }
    return cur_max;
}