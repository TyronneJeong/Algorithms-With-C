#include <stdio.h>
#include <time.h>
#include "example/student.h"
#include "analysis_of_algorithms/list.h"

void student_func(){
    Student *student = create_student("Risah", 33);
    view_student(student);
    delete_student(student);
} /* example code */

void analysis_of_algorithms(){
    l_00_memory();
//    l_01_recursion();
//    l_02_powerset();
} /* analysis_of_algorithms */

int main() {
    clock_t start_time = clock();
    printf("Hello, World!\n\n");

    /**
     * 수행
     **/
    // student_func();
    analysis_of_algorithms();

    printf("\nBye, World!\nelapsed time >> %lf seconds\n", (double)(clock()-start_time)/CLOCKS_PER_SEC);
    return 0;
} /* main function */