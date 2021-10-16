#include <stdio.h>
#include <time.h>
#include "example/student.h"
#include "analysis_of_algorithms/list.h"

/*
 * Function     : student_func
 * Description  : main function of example part
 * Calls        : main.c/main()
 * Input        : void
 * Output       : void
 * Return       : N/A
 * Others       : N/A
 */
void student_func(){
    Student *student = create_student("Risah", 33);
    view_student(student);
    delete_student(student);
}

/*
 * Function     : analysis_of_algorithms
 * Description  : main function of analysis_of_algorithms part
 * Calls        : main.c/main()
 * Input        : void
 * Output       : void
 * Return       : N/A
 * Others       : N/A
 */
void analysis_of_algorithms(){
//    l_00_memory();
//    l_00_pointer();
//    l_01_what_is_recursion();
//    l_02_recursive_thinking();
    l_03_designing_recursion();
//    l_04_maze();
}

/*
 * Function     : main()
 * Description  : main function of application
 * Calls        : main.c
 * Input        : void
 * Output       : int
 * Return       : N/A
 * Others       : N/A
 */
int main() {
    clock_t start_time = clock();
    printf("Hello, World!\n\n");

    // student_func();
    analysis_of_algorithms();

    printf("\nBye, World!\nelapsed time >> %lf seconds\n", (double)(clock()-start_time)/CLOCKS_PER_SEC);
    return 0;
}