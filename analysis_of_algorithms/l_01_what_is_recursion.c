#include <stdio.h>
#include "list.h"

int recursive(int n);                   /* 재귀호출                  */
int factorial(int n);                   /* 팩토리얼                  */
int tail_rec_factorial(int n, int d);   /* 꼬리재귀 형태의 팩토리얼     */
int fibonacci(int n);                   /* 피보나치수열               */
int gcd(int m, int n);                  /* 최대공약수-유클리드호제법    */

/*
 * Function     : l_01_what_is_recursion
 * Description  : main function of what is recursion part
 * Calls        : main.c/analysis_of_algorithms()
 * Input        : void
 * Output       : void
 * Return       : N/A
 * Others       : N/A
 */
void l_01_what_is_recursion(){
    int result  = 0;
    result      = recursive(10);
    printf("recursive Result : %d\n", result);

    result      = factorial(10);
    printf("factorial Result : %d\n", result);

    result      = tail_rec_factorial(10, 1);
    printf("tail_rec_factorial Result : %d\n", result);

    result      = fibonacci(40);
    printf("fibonacci Result : %d\n", result);

    result      = gcd(12, 7);
    printf("gcd Result : %d\n", result);
}

/*
 * Function     : recursive
 * Description  : 재귀호출의 기본적인 형태, 종료식과 재귀 점화식이 하나씩 존재한다.
 * Calls        : l_01_what_is_recursion.c/l_01_what_is_recursion()
 * Input        : int n
 * Output       : int
 * Return       : N/A
 * Others       : stack-overflow
 *                함수 호출정보는 stack frame 형태로 call stack에 저장되는데,
 *                stack 에 쌓인 정보가 한계점에 이르게 되면 stack-overflow가 발생된다.
 *                재귀적 호출이 미처 완료하지 못한 function 내에서 새로운 함수 호출로 인해
 *                발생되는 문제로 이는 tail-recursion 형태로 변환하여 해결 가능하다.
 */
int recursive(int n){
    if (n <= 0) {                       /* base case (종료식) */
        return 0;                       /* return 0; 으로 함수 종료 */
    } else {                            /* 종료식을 만족하지 않는 경우 */
        printf("index : %d\n", n);      /* 재귀 호출시 감산 되는 인덱스 정보 출력 */
        return n + recursive(n -1);  /* recursive case : base case 로 수렴하기 위한 재귀 호출 (점화식) */
    }
}

/*
 * Function     : factorial
 * Description  : 입력된 정수 보다 작은 모든 양의 정수의 곱
 * Calls        : l_01_what_is_recursion.c/l_01_what_is_recursion()
 * Input        : int n
 * Output       : int
 * Return       : N/A
 * Others       : N/A
 */
int factorial(int n){
    if (n == 0){
        return 1;
    } else {
        return n*factorial(n-1);
    }
}

/*
 * Function     : tail_rec_factorial
 * Description  : 꼬리재귀 형태의 팩토리얼
 * Calls        : l_01_what_is_recursion.c/l_01_what_is_recursion()
 * Input        : int n
 * Output       : int
 * Return       : N/A
 * Others       : 재귀 호출 되는 함수는 call stack 에 적재되지 않고 함수 종료 후
 *                동일 함수를 재 호출 하는 형태로 동작하게 되며 컴파일러 옵션에 따라 새로운 함수 호출
 *                주소를 생성하지 않고 기존 함수 호출 주소를 반복하는 형식으로도 처리가능하다.
 */
int tail_rec_factorial(int n, int d){
    if (n <= 0){
        return d;
    } else {
        return tail_rec_factorial((n - 1), (n * d));
    }
}

/*
 * Function     : fibonacci
 * Description  : 피보나치 수열, 한 쌍의 토끼가 매월 한쌍의 새끼를 낳을 경우 입력받은
 *                n개월 후 전체 토끼쌍의 수를 나열한 수열
 *                (suppose 토끼는 죽지 않는다, 2개월이상된 토끼는 번식이 가능하다)
 *                ex. [3개월 : 1 + 1 = 2], [4개월 : 1 + 2 = 3], [5개월 : 2 + 3 = 5],
 *                    [6개월 : 3 + 5 = 8], [6개월 : 5 + 8 = 13]
 * Calls        : l_01_what_is_recursion.c/l_01_what_is_recursion()
 * Input        : int n
 * Output       : int
 * Return       : N/A
 * Others       : N/A
 */
int fibonacci(int n){
    if (n < 2){
        return n;
    } else {
        // 3개월째 부모 한쌍이 한쌍의 새끼토끼 쌍을 출산 = 2
        // 4개월째 부모 한쌍이 한쌍의 새끼토끼 쌍을 출산 + 기존 토끼 한쌍(1개월) = 3
        // 4개월째 부모 두쌍이 두쌍의 새끼토끼 쌍을 출산 + 기존 토끼 한쌍(1개월) = 5
        // 5개월째 부모 세쌍이 세쌍의 새끼토끼 쌍을 출산 + 기존 토끼 두쌍(1개월) = 8
        // 6개월째 부모 다섯쌍이 다섯쌍의 새끼토끼 쌍을 출산 + 기존 토끼 세쌍(1개월) = 13
        // 결과론적으로 피보나치 수열은 직전과 재직전의 수의 합과 같으므로 아래와 같이 계산한다.
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

/*
 * Function     : GCD(Greatest Common Divisor)
 * Description  : 최대 공약수 유클리드 호제법 (Euclidean Algorithm)]
 *                [유클리드 호제법이란?]
 *                두 수가 서로 상대방 수로 나누어 원하는 결과를 얻는 알고리즘 양식.
 * Calls        : l_01_what_is_recursion.c/l_01_what_is_recursion()
 * Input        : int m, int n
 * Output       : int
 * Return       : N/A
 * Others       : [약수] divisor : 어떤 수로 정수가 나누어 떨어지는지를 이르는 말.
 */
int gcd(int m, int n) {
    if(m < n) {
        int tmp = m; m = n; n = tmp; //swap m and n
    }
    if(m % n == 0) {
        return n;
    } else {
        return gcd(n, m % n);
    }
}