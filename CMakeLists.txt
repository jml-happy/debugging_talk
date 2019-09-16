cmake_minimum_required(VERSION 3.14)
project(debugging_talk)

set(CMAKE_CXX_STANDARD 14)

add_executable(debugging_talk main.cpp tests.cpp tests.h debugging/segfault.cpp debugging/segfault.h)