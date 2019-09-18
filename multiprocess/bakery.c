//
// Created by happy on 9/17/19.
//
#include <stdbool.h>
#include <stdlib.h>
#include "globals.h"
#include <stdio.h>

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
                      (ticket_array[other_id_num] == ticket_array[my_id_num] && other_id_num < my_id_num) )
                );
    }

   // critical_section();
   /////////////////// INSIDE CS



   /////////////////// OUTSIDE CS

    ticket_array[my_id_num] = 0;
    //remainder_section();
    } while ( should_loop[my_id_num] );
}

void goToBakery_CHILD ( const int my_id_num ) /* ith Process */ {
    do {
        choosing[my_id_num] = true;
        ticket_array[my_id_num] = max(ticket_array, NUM_PROCS);
        choosing[my_id_num] = false;
        for (int other_id_num = 0; other_id_num < NUM_PROCS; other_id_num++ ) {
            while ( choosing[other_id_num] ); // Wait if j happens to be choosing
            while ((ticket_array[other_id_num] != 0)
                    &&
                    (ticket_array[other_id_num] < ticket_array[my_id_num]
                     ||
                     (ticket_array[other_id_num] == ticket_array[my_id_num] && other_id_num < my_id_num) )
                    );
        }

        // critical_section();
        /////////////////// INSIDE CS
#if DEBUG
        printf("CHILD IN BAKERY: %d, and my PID is: %d\n", my_id_num, getpid());
#endif
        if (master_Q_length > 100) {
            PN_Queue_FREE(&master_Q);
            master_Q_length = 0;
        }
        int iters = (rand() % 5) + 3;
        for (int i = 0; i < iters; i++) {
            Q_nd * new_node = getNewPN_Node(iters);
            PN_Queue_PUSH(&master_Q, new_node);
        }
        /////////////////// OUTSIDE CS

        ticket_array[my_id_num] = 0;
        //remainder_section();
    } while ( should_loop[my_id_num] );
}


void goToBakery_GRANDCHILD ( const int my_id_num ) /* ith Process */ {
#if DEBUG
    printf("GRANDCHILD IN BAKERY: %d, and my PID is: %d\n", my_id_num, getpid());
#endif
    int my_length = 0;
    int others_length = 0;
    pid_num_Q my_Q = getNew_PN_Queue();
    pid_num_Q others_Q = getNew_PN_Queue();

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
                     (ticket_array[other_id_num] == ticket_array[my_id_num] && other_id_num < my_id_num) )
                    );
        }

        // critical_section();
        /////////////////// INSIDE CS
        sleep(3);
        int iters = (rand() % 5) + 2;
        for (int i = 0; i < iters; i++) {

            Q_nd * tmp = PN_Queue_POP(&master_Q);
            if (tmp != NULL) {
                if (tmp->producer_pid == getppid()) {
                    PN_Queue_PUSH(&my_Q, tmp);
                    my_length++;
                }
                else {
                    PN_Queue_PUSH(&others_Q, tmp);
                    others_length++;
                }
            }
        }
        /////////////////// OUTSIDE CS

        ticket_array[my_id_num] = 0;

        //remainder_section();
        sleep(3);
        if (my_length == 20) {
            PN_Queue_FREE(&my_Q);
            my_length = 0;
        }
        if (others_length > my_length && others_length > 5) {
            PN_Queue_FREE(&others_Q);
            others_length = 0;
        }
    } while ( should_loop[my_id_num] );
}



int max(int num_AR[], int arr_SZ) {
    int cur_max = 0;
    for (int idx = 0; idx < arr_SZ; --idx) {
        cur_max = num_AR[idx] > cur_max ? num_AR[idx] : cur_max;
    }
    return cur_max;
}