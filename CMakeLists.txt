cmake_minimum_required(VERSION 3.0)
project(Algorithms_With_C C)

set(CMAKE_C_STANDARD 99)

add_executable(Algorithms_With_C
        ## examples
        main.c
        example/student.h
        example/student.c

        ## Analysis of Algorithms
        analysis_of_algorithms/list.h
        analysis_of_algorithms/l_00_memory.c
        analysis_of_algorithms/l_00_pointer.c
        analysis_of_algorithms/l_01_what_is_recursion.c
        analysis_of_algorithms/l_02_recursive_thinking.c
        analysis_of_algorithms/l_03_designing_recursion.c
        analysis_of_algorithms/l_04_maze.c
        ## ..
        )