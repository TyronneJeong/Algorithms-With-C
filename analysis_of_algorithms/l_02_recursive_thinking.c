#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

char*   substr(char *str, int position, int length);    /* 문자열 부분 잘라내기               */
int     length(char *str);                              /* 입력 문자열의 길이측정              */
void    print_str_token(char *str);                     /* 문자열을 문자 단위로 출력           */
void    print_reverse_str(char *str);                   /* 문자열 뒤집어 출력                 */
void    print_int_to_binary(int n);                     /* 숫자를 2진수로 출력                */
int     sum_of_array(int numb[], int begin);            /* 배열에 담긴 숫자들의 합을 리턴       */

/*
 * Function     : l_02_recursive_thinking
 * Description  : main function of recursive thinking part
 * Calls        : main.c/analysis_of_algorithms()
 * Input        : void
 * Output       : void
 * Return       : N/A
 * Others       : N/A
 */
void l_02_recursive_thinking() {
    char *sample = "sample"; // static memory allocation
    printf("length result : %d\n", length(sample));

    print_str_token(sample);
    printf("\n");

    print_reverse_str(sample);
    printf("\n");

    print_int_to_binary(5);
    printf("\n");

    int a[] = {1, 2, 3, 4, 5};
    int result = sum_of_array(a, 0);
    printf("sum of array : %d", result);
}

/*
 * Function     : length
 * Description  : 입력 된 문자열의 길이를 반환한다.
 * Calls        : l_02_recursive_thinking.c/l_02_recursive_thinking
 * Input        : char *str
 * Output       : int
 * Return       : N/A
 * Others       : N/A
 */
int length(char *str){
    if(str != NULL && str[0] == '\0') {
        return 0;
    } else {
        char *rtn_Str = substr(str, 1, (strlen(str)-1));
        int string_length = 1 + length(rtn_Str);
        free(rtn_Str);
        return string_length;
    }
}

/*
 * Function     : print_str_token
 * Description  : 입력 된 문자열을 토큰 단위로 분리하여 출력한다.
 * Calls        : l_02_recursive_thinking.c/l_02_recursive_thinking
 * Input        : char *str
 * Output       : int
 * Return       : N/A
 * Others       : substr함수의 재귀형태로 리턴되는 동적 할당 변수는 해제가 필요한지 확인필요
 */
void print_str_token(char *str){
    if(str != NULL && str[0] == '\0') {
        return;
    } else {
        printf("%c, ", str[0]);
        return print_str_token(substr(str, 2, (strlen(str))));
    }
}

/*
 * Function     : print_reverse_str
 * Description  : 입력 된 문자열을 역순으로 출력한다.
 * Calls        : l_02_recursive_thinking.c/l_02_recursive_thinking
 * Input        : char *str
 * Output       : void
 * Return       : N/A
 * Others       : call stack에서 함수가 종료될 때 LIFO 순으로 종료되는 특징을 이용한 로직
 */
void print_reverse_str(char *str) {
    if (*str) {
        print_reverse_str(str+1);
        printf("%c", *str);
    }
}

/*
 * Function     : print_int_to_binary
 * Description  : 입력 받은 정수는 2진수의 바이너리 형태로 출력한다.
 * Calls        : l_02_recursive_thinking.c/l_02_recursive_thinking
 * Input        : int n
 * Output       : void
 * Return       : N/A
 * Others       : [10진수를 2진수로 변환하는 방법]
 *                - 각 수를 2로 나누어 더이상 나누어 떨어지지 않는 수와 나머지 값을 모두
 *                나열하면 2진수가 된다.
 *                5   /2 = 2 나머지 1
 *                2   /2 = 1 나머지 0
 *                1   /2 = 0 나머지 1
 *                답 : 0101
 */
void print_int_to_binary(int n){
    if(n <= 0){
        printf("%d", n/2);
    } else {
        print_int_to_binary(n/2);
        printf("%d", n%2);
    }
}

/*
 * Function     : sum_of_array
 * Description  : 입력 받은 배열 내 저장된 모든 정수들의 합을 리턴한다
 * Calls        : l_02_recursive_thinking.c/l_02_recursive_thinking
 * Input        : int numb[], int begin
 * Output       : int
 * Return       : N/A
 * Others       : 배열과 재귀호출시 참조할 배열 인덱스 값을 같이 전달한다.
 */
int sum_of_array(int numb[], int begin){
    if(numb[begin] == NULL){
        return 0;
    } else {
        return numb[begin] + sum_of_array(numb, begin+1);
    }
}

/*
 * Function     : substr
 * Description  : 입력 받은 문자열의 시작과 종료 구간만을 잘라 리턴한다.
 * Calls        : l_02_recursive_thinking.c/l_02_recursive_thinking
 * Input        : char *str, int position, int length
 * Output       : char*
 * Return       : N/A
 * Others       : [dynamic memory allocation - malloc, memset, calloc]
 *                메모리 할당 이 끝나고 나면 void* 포인터 형식으로 주소값이 리턴된다.
 *                C의 경우는 void* 포인터는 대입자료형으로 자동 케스팅 되므로 별도의 캐스팅
 *                (char*)malloc(size) 은 생략 가능하다.
 *                동적으로 할당된 메모리는 사용후 반드시 메모리 해제(free)가 필요하다.
 *                해제 되지 않은 동적 메모리 공간은 프로그램이 종료될때까지 재사용이 불가능하다.
 *                이때 해제 되지 않은채 남은 주소 공간을 허상참조(dangling reference) 라고 한다.
 *
 *                [memset 을 이용한 초기화]
 *                ex) memset(p, ' ', (sizeof (char) * length) + 1);
 *                - 파라미터로 전달된 메모리 공간 p를 ' '라는 문자로 length의 길이만큼 채워진다.
 *                - end marker 를 위하여 입력 문자열의 길이 + 1 만큼을 초기화 해야한다.
 *
 *                [calloc 을 이용한 초기화]
 *                ex) p = calloc((sizeof (char) * length) + 1, sizeof (char));
 *                malloc 이후 memset 까지를 포함한 동작으로 메모리 할당과 초기화를 동시에 진행한다.
 *
 *                [realloc 을 이용한 재할당]
 *                ex) p = realloc(p, length);
 *                - 파라미터로 전달된 주소공간 p를 length 라는 크기만큼 재할당 한다.
 *                - 재할당시 기존 내용은 유지된다.
 *                - 기존 주소공간을 재사용하지만 재사용이 불가능한 경우 새로운 주소공간을 확보 한다.
 */
char* substr(char *str, int position, int length) {
    char *p;
    int c = 0;
    p = malloc((sizeof (char) * length) + 1);
    if(p == NULL) { // heap space 할당량을 초과하거나 메모리 할당이 실패한 경우 malloc 은 NULL 을 리턴한다.
        printf("unable to allocate memoey. \n");
        exit(EXIT_FAILURE); // EXIT_FAILURE : 1
    }
    for (c = 0; c < length; c++) { // char 하나씩 주소 공간에 복사
        *(p + c) = *(str + position - 1);
        str++;
    }
    *(p + c) = '\0';
    return p;
}