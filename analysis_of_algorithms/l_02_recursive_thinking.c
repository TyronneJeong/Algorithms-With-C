#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

char*   substr(char *str, int position, int length);    /* 문자열 부분 잘라내기                */
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
 * Others       : substr함수의 재귀형태로 리턴되는 동적 할당 변수는 해제가 필요한지 확인필요
 */
int length(char *str){
    if(str != NULL && str[0] == '\0') {
        return 0;
    } else {
        return 1 + length(substr(str, 1, (strlen(str)-1)));
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
 */
char* substr(char *str, int position, int length) {
    char *p;
    int c = 0;

    // printf("%p\n", p);                           // heap space 주소
    // printf("%p\n", *p);                          // char 자료형의 주소 (※ *p = malloc 하면 안된다.)
    // printf("%d\n", sizeof p);                    // 주소공간의 크기
    // printf("%d\n", sizeof *p);                   // char 타입의 크기
    // printf("%d\n", sizeof (char));               // char 타입의 크기

    p = malloc((sizeof (char) * length) + 1);

    // printf("after malloc : %s\n", p);            // 최초 할당 후 저장된 값 출력
    // printf("after malloc : %d\n", sizeof p);     // 주소공간의 크기
    // printf("after malloc : %d\n", sizeof *p);    // char 타입의 크기

    // memset 을 이용한 데이터 filling
    // memset(p, ' ', 3);                            // 선언된 변수의 길이 2byte + NULL 문자 입력용 1byte 추가 분
    // printf("after memset : %s\n", p);             // 최초 할당 후 저장된 값 출력
    // printf("after memset : %p\n", p);             // 기존의 주소정보와 동일함

    // malloc + memset = calloc
    // p = calloc((sizeof (char) * length) + 1, sizeof (char));
    // printf("after calloc : %s\n", p);             // 최초 할당 후 저장된 값 출력

    // heap space 할당량을 초과하거나 메모리 할당이 실패한 경우 malloc 은 NULL 을 리턴한다.
    if(p == NULL) {
        printf("unable to allocate memoey. \n");
        exit(1);
    }

    // char 하나씩 주소 공간에 복사
    for (c = 0; c < length; c++) {
        *(p + c) = *(str + position - 1);
        str++;
    }
    *(p + c) = '\0';
    return p;
}