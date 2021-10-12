#pragma once
#define MAX_NAME_LEN  20
/*******************************************************
 * [Naming Conventions]
 *******************************************************
 * Struct              PascalCase
 * Struct Members      lower_case
 * Enum                PascalCase
 * Enum Members        ALL_CAPS
 * MACRO n CONSTANT    ALL_CAPS
 * Functions           lower_case()
 * Global  variables   g_lower_case
 * Local   variables   lower_case
 * Trivial variables   i,x,n,f etc...
 ********************************************************/
typedef struct Student Student;
struct Student{
    char name[MAX_NAME_LEN];
    int num;
}; /* comment is here */

Student *create_student(const char *name, int num);
void view_student(Student *student);
void delete_student(Student *student);