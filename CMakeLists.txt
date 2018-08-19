cmake_minimum_required(VERSION 3.9)
project(queue C)

set(CMAKE_C_STANDARD 99)

add_executable(queue main.c include/queue.h src/queue.c)