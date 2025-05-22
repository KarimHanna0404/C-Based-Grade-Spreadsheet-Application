cmake_minimum_required(VERSION 3.29)
project(untitled1 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled1 main.c
        SpreadSheet.c
        SpreadSheet.h
        ordering.c
        data.c
        calc.c)
