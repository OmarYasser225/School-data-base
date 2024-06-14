cmake_minimum_required(VERSION 3.25)
project(DataBase C)

set(CMAKE_C_STANDARD 11)

add_executable(DataBase main.c student.h student.c feature.h feature.c operation.h operation.c)
