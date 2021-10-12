#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <memory.h>
#include "student.h"

Student *create_student(const char* name, int num) {
    Student *student = (Student*)malloc(sizeof(Student));
    memset(student, 0, sizeof(Student));
    strncpy(student->name, name, MAX_NAME_LEN);
    student->num = num;
    return student;
} /* create new student on memory*/

void view_student(Student *student) {
    printf("student name :%s, number: %d\n", student->name, student->num);
} /* get student information in memory */

void delete_student(Student *student) {
    free(student);
} /* free to memory having student information */