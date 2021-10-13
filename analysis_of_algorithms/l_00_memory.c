/**
 * [Memory Layout]
 * - 운영 체제가 제공하는 메모리 영역의 구조.
 *
 *  ***************************************************************************
 *  *                           low  memory address                           *
 *  ***************************************************************************
 *  * 1. code/text segment : binary image of the process (read only)
 *  * 2. data      segment : static variable explicitly initialized
 *  * 3. bss       segment : Uninitialized static variables, filled with zeros
 *  * 4. heap      segment : [↓] dynamic memory allocation through (malloc/new) (free/delete)
 *  *                        (grows toward higher memory addresses)
 *  * 5. stack     segment : [↑] Automatic variable(local to function's scope), caller's return address, etc.
 *  *                        (grows toward lower memory addresses)
 *  * 9. OS Kernel Space   : User code cannot read from nor write to these addresses.
 *  ***************************************************************************
 *  *                           high memory address                           *
 *  ***************************************************************************
 *
 * 1. code/text segment
 *    - 실행가능한 명령어를 포함하고 있는 메모리 영역.
 *    - 상수 와 함수가 저장 된다. (함수내 변수들은 stack 영역에 저장된다.)
 *    - Stack 과 Heap 보다 아래에 위치하는데 이는 두 영역으로 부터 덮어 씌워지는 것을 방지 하기 위함이다.
 *    - 읽기전용 영역이다.
 *
 * 2. data segment (initialized data segment)
 *    - 프로그래머에 의해 초기화된 전역(global)변수와 정적변수(static)변수를 포함하고 있다.
 *    - 이 공간은 런타임시 변경이 가능한 공간이지만 read-only 공간과 read-write 공간이 분리되어 있다.
 *    - e.g 함수 밖에 선언된 전역 변수의 경우 read-write 공간에 저장된다.
 *
 * 3. bss segment (uninitialized data segment)
 *    - bss segment 는 초기화 되지 않은 data segment
 *    - read-write 공간으로 프로그램이 실행전에 OS 커널에 의해 0으로 초기화 된다.
 *    - 코드상에서 명시적으로 초기화 되지 않은 전역, 정적 변수를 포함한다.
 *
 * 4. Heap segment
 *    - 낮은 주소공간에서 높은 주소공간으로 데이터가 저장된다.
 *    - 메모리상 BSS 다음에 위치하며, 동적 메모리 할당이 일어나는 장소로 런타임시 그 크기가 결정된다.
 *
 * 5. stack segment
 *    - 높은 주소에서 낮은 주소공간으로 데이터가 저장되며 LIFO(last in first out) 구조를 따른다.
 *    - 함수 호출에 필요한 데이터가 저장되고 그 데이터를 stack frame 이라고 부른다.
 *    - stack frame 이 stack segment 에 저장되며, stack frame 은 automatic 변수와 임시변수, 함수 리턴시 돌아갈 주소값을 포함하고 있다.
 */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

const int CONST_VALUE = 30;      // constant value declaration
static int static_variable = 70; // initialized static variable declaration
int g_uninitial;                 // uninitialized global variable declaration
int g_initial = 30;              // initialized global variable declaration
int function();                  // function declaration
int function() {
    return 20;
}

void l_00_memory() {
    int local_variable1 = 30;  // local 1 variable (initialized)
    int local_variable2;       // local 2 variable (unintialized)

    printf("input any number : ");
    scanf(" %d", &local_variable2);

    char *arr = malloc(sizeof(char) * 10);  // dynamic memory allocation

    /* print pointer address info */
    printf("\n");
    printf("constant         Memory Address : %p \n", &CONST_VALUE);
    printf("function         Memory Address : %p \n", function);
    printf("static  variable Memory Address : %p \n", &static_variable);
    printf("init    variable Memory Address : %p \n", &g_initial);
    printf("uninit  variable Memory Address : %p \n", &g_uninitial);
    printf("local1  variable Memory Address : %p \n", &local_variable1);
    printf("local2  variable Memory Address : %p \n", &local_variable2);
    printf("dynamic variable Memory Address : %p \n", arr);
}

/**
 * [Process 와 Thread 의 차이]
 * - Program(or Application) 은 어떠한 일을 수행하는 명령어릐 집합으로, 프로그래밍 언어로 생성되어
 * 컴퓨터내 실행가능한 형태(디스크 또는 메모리)로 저장되어 있다. 이때,
 *
 * [Process]
 * - 프로세스는 실행중인 프로그램을 의미하며, 명령 수행에 필요한 메모리와 자원을 할당 받아 동작하는 주체이다.
 * - 프로세스는 상호 배타적으로 분리된 메모리 공간을 할당 받아 다른 프로세스와는 직접 적인 영향을 주지 않는다.
 *
 * [Thread]
 * - 스레드는 프로세스가 발생시키는 실행 단위로, 프로세스가 실행되면 스레드 역시 메모리와 자원을 할당 받아 동작한다.
 * - 하나의 프로세스는 여러개의 스레드를 생성할 수 있다.(가벼운 동작)
 * - 복수개의 스레드가 존재하는 경우, 각 스레드는 자신만의 레지스터와 스택을 할당 받지만 나머지는 서로 모두 공유하게 된다.
 * - 따라서 하나의 스레드는 다른 스레드에 미치는 영향이 크다. (반면, 스레드간 통신이 간단하고 빠르다.)
 */