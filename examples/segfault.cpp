//
// Created by happy on 9/16/19.
//
#include <vector>
#include "segfault.h"

std::vector<int> array;

void segfault_a() {
    for (int i = 0; i < 10; i++) {
        array.push_back(i);
    }
    segfault_b();
}

void segfault_b() {
    array[4] = array[3];
    segfault_c();
}

void segfault_c() {
    int j = 5;
    int i = array[2] + j;
    segfault_d(i);
}

void segfault_d(int idx) {
    idx += array[3];
    segfault_e(idx);
}

void segfault_e(int idx) {
    idx--;
    int * p = (int *)array[300];
    *p = 50;
}