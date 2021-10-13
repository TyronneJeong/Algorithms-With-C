#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * [recursion vs iteration]
 * - 모든 순환 함수는 반복문(iteration)으로 변경이 가능하다.
 * - 모든 반복문은 순환 함수(recursion)으로 변경이 가능하다.
 * - 순환함수는 복잡한 알고리즘을 단순하고 알기쉽게 표현하는 것이 가능함.
 * - 순환함수는 함수 호출에 따른 오버헤드가 발생 함(매개변수 전달, 액티베이션 프레임 생성 등)
 * - activation frame is stack frame.
 */
char* substr(char *str, int position, int length); // 문자열 부분 잘라내기
int  length(char *str);           // 입력 문자열의 길이측정
void print_str_token(char *str);  // 문자열을 문자 단위로 출력
void print_reverse_str(char *str);    // 문자열 뒤집어 출력
void print_int_to_binary(int n);  // 숫자를 2진수로 출력
int  sum_of_array(int numb[], int start); // 배열에 담긴 숫자들의 합을 리턴

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

/**
 * [length]
 * desc : 재귀 형태의 문자열 길이 계산.
 */
int length(char *str){
    if(str != NULL && str[0] == '\0') {
        return 0;
    } else {
        return 1 + length(substr(str, 1, (strlen(str)-1)));
    }
}

/**
 * [print_str_token]
 * desc : 문자열을 token 단위로 출력 한다.
 */
void print_str_token(char *str){
    if(str != NULL && str[0] == '\0') {
        return;
    } else {
        printf("%c, ", str[0]);
        return print_str_token(substr(str, 2, (strlen(str))));
    }
}

/**
 * [print_reverse_str]
 * desc : 문자열을 역순으로 출력한다. Stack의 LIFO 구조를 이용.
 */
void print_reverse_str(char *str) {
    if (*str) {
        print_reverse_str(str+1);
        printf("%c", *str);
    }
}

/**
 * [print_int_to_binary]
 * desc : 입력 받은 정수를 2진수로 변환하여 출력한다.
 */
void print_int_to_binary(int n){
    // 5   /2 = 2 나머지 1
    // 2   /2 = 1 나머지 0
    // 1   /2 = 0 나머지 1
    // 답 : 0101
    if(n <= 0){
        printf("%d", n/2);
    } else {
        print_int_to_binary(n/2);
        printf("%d", n%2);
    }
}

/**
 * [sum_of_array]
 * desc : 배열에 담긴 숫자들의 합을 리턴한다.
 */
int sum_of_array(int numb[], int start){
    if(numb[start] == NULL){
        return 0;
    } else {
        return numb[start] + sum_of_array(numb, start+1);
    }
}

/**
 * [substr]
 * desc : 문자열의 특정 구간을 잘라내어 리턴 한다.
 */
char *substr(char *str, int position, int length) {
    // memory allocation 이 끝나고 나면 void* 형식으로 주소값이 리턴된다.
    // C의 경우는 void* pointer는 해당 타입으로 자동 케스팅 되므로 (char*)malloc 식의 캐스팅은 생략 가능하다.
    // 동적으로 할당된 메모리는 사용후 반드시 메모리 해제(free)시켜야 한다.
    char *p;
    int c = 0;

    // printf("%p\n", p);             // heap space 주소
    // printf("%p\n", *p);            // char 자료형의 주소 (※ *p = malloc 하면 안된다.)
    // printf("%d\n", sizeof p);      // 주소공간의 크기
    // printf("%d\n", sizeof *p);     // char 타입의 크기
    // printf("%d\n", sizeof (char)); // char 타입의 크기

    p = malloc((sizeof (char) * length) + 1);

    // printf("after malloc : %s\n", p);            // 최초 할당 후 저장된 값 출력
    // printf("after malloc : %d\n", sizeof p);     // 주소공간의 크기
    // printf("after malloc : %d\n", sizeof *p);    // char 타입의 크기

    // memset 을 이용한 데이터 filling
    // memset(p, ' ', 3);                              // 선언된 변수의 길이 2byte + NULL 문자 입력용 1byte 추가 분
    // printf("after memset : %s\n", p);               // 최초 할당 후 저장된 값 출력
    // printf("after memset : %p\n", p);               // 기존의 주소정보와 동일함

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