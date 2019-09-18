cmake_minimum_required(VERSION 3.14)
project(debugging_talk)

set(CMAKE_CXX_STANDARD 14)

add_executable(debugging_talk main.cpp tests.cpp tests.h examples/segfault.cpp examples/segfault.h multiprocess/parent.c)
add_executable(multi_procs multiprocess/parent.c multiprocess/child.c multiprocess/grandchild.c multiprocess/child.h multiprocess/bakery.c multiprocess/globals.c multiprocess/globals.h multiprocess/circular_queue.c multiprocess/circular_queue.h multiprocess/parent.h multiprocess/bakery.h multiprocess/grandchild.h)
add_executable(bubble_sort_iterative examples/bubble_sort_iterative.cpp)
add_executable(bubble_sort_recursive examples/bubble_sort_recursive.cpp)
add_executable(insertion_sort_recursive examples/insertion_sort_recursive.cpp)
add_executable(dft_on_graph examples/graph_dft_stack.cpp)