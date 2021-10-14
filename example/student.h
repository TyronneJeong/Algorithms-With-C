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
#define MAX_NAME_LEN    20  /* available max length character at name */

/*
 * Structure    : Student
 * Description  : It use to be store information about student id and names in memory.
 * Members      : int   num
 *                char  name[MAX_NAME_LEN]
 */
typedef struct Student Student;
struct Student{
    int     num;                   /* student id number    */
    char    name[MAX_NAME_LEN];    /* student name         */
};

Student *create_student(const char *name, int num); /* make new information about student in memory */
void view_student(Student *student);                /* search student information in memory */
void delete_student(Student *student);              /* remove the student information in memory */