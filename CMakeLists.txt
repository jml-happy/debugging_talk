cmake_minimum_required(VERSION 3.14)
project(debugging_talk)

set(CMAKE_CXX_STANDARD 14)

add_executable(debugging_talk main.cpp tests.cpp tests.h debugging/segfault.cpp debugging/segfault.h multiprocess/parent.c)
add_executable(multi_procs multiprocess/parent.c multiprocess/child.c multiprocess/grandchild.c multiprocess/child.h multiprocess/bakery.c multiprocess/globals.c multiprocess/globals.h multiprocess/circular_queue.c multiprocess/circular_queue.h)
add_executable(bubble_sort debugging/bubble_sort.cpp)