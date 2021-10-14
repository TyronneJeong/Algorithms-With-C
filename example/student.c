/*
 * Copyright (C), 2021-2021, Example Tech. Co., Ltd.
 * FileName: student.c
 * Description: manage student information in memory.
 * Change Logs:
    |Date           |Author       |Notes     |version
    |2021-10-14     |Tyronne      |N/A       |1.0.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

/*
 * Function     : create_student
 * Description  : create new information about student in memory
 * Calls        : main.c/student_func()
 * Input        : const char* name, int num
 * Output       : Student
 * Return       : structure Student
 * Others       : N/A
 */
Student *create_student(const char* name, int num) {
    Student *student = (Student*)malloc(sizeof(Student));
    memset(student, 0, sizeof(Student));
    strncpy(student->name, name, MAX_NAME_LEN);
    student->num = num;
    return student;
}

/*
 * Function     : view_student
 * Description  : search student information by id and print that information.
 * Calls        : main.c/student_func()
 * Input        : Student *student
 * Output       : void
 * Return       : N/A
 * Others       : N/A
 */
void view_student(Student *student) {
    printf("student name :%s, number: %d\n", student->name, student->num);
}

/*
 * Function     : delete_student
 * Description  : delete student information by user id.
 * Calls        : main.c/student_func()
 * Input        : Student *student
 * Output       : void
 * Return       : N/A
 * Others       : N/A
 */
void delete_student(Student *student) {
    free(student);
}