#include <stdio.h>
#include "list.h"

int recursive(int n);   // 재귀호출
int factorial(int n);   // 팩토리얼
int tail_rec_factorial(int n, int d); // 꼬리재귀 형태의 팩토리얼
int fibonacci(int n);   // 피보나치수열
int gcd(int m, int n);  // 최대공약수-유클리드호제법

void l_01_what_is_recursion(){
    int result = 0;
    result = recursive(10);
    printf("recursive Result : %d\n", result);

    result = factorial(10);
    printf("factorial Result : %d\n", result);

    result = tail_rec_factorial(10, 1);
    printf("tail_rec_factorial Result : %d\n", result);

    result = fibonacci(40);
    printf("fibonacci Result : %d\n", result);

    result = gcd(12, 7);
    printf("gcd Result : %d\n", result);
}

/**
 * [recursive]
 * desc : 재귀호출의 기본적인 형태, 종료식과 반복 호출이 나란히 존재한다.
 * 재귀 호출시 호출되는 함수들은 스텍 프레임에 저장 된다.
 *
 * [Stack Overflow]
 * - Process finished with exit code -1073741571 (0xC00000FD)
 * 함수 호출이 한계점에 이르면 Stack Overflow 가 발생되므로
 * 이를 꼬리재귀 형태로 변환하여 Stack Overflow 를 방지 할 수 있다.
 */
int recursive(int n){
    if (n <= 0){ // base case (종료식)
        return 0;
    } else {
        printf("Remained Index : %d\n", n);
        return n + recursive(n -1); // recursive case : base case 로 수렴하기 위한 재귀 호출 (점화식)
    }
}

/**
 * [factorial]
 * desc : 입력된 정수 보다 작은 모든 양의 정수의 곱
 * 재귀 호출시 반복 되는 호출 정보는 스택 프레임에 저장된다.
 */
int factorial(int n){
    if (n == 0){
        return 1;
    } else {
        return n*factorial(n-1); // recursive case (점화식)
    }
}

/**
 * [tail_rec_factorial]
 * desc : 꼬리재귀 형태의 팩토리얼
 * 호출 되는 함수가 스텍 프레임에서 반환 된 후 새롭게 함수 호출이 일어난다.
 */
int tail_rec_factorial(int n, int d){
    if (n <= 0){
        return d;
    } else {
        return tail_rec_factorial((n - 1), (n * d));
    }
}

/**
 * [fibonacci]
 * desc : 피보나치 수열, 한 쌍의 토끼가 매월 한쌍의 새끼를 낳을 경우 입력받은 n
 * 개월 후 전체 토끼쌍의 수를 나열한 수열
 * (suppose 토끼는 죽지 않는다, 2개월이상된 토끼는 번식이 가능하다)
 * ex. [3개월 : 1 + 1 = 2], [4개월 : 1 + 2 = 3], [5개월 : 2 + 3 = 5], [6개월 : 3 + 5 = 8]
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

/**
 * [GCD(Greatest Common Divisor)
 * desc : 최대 공약수 유클리드 호제법 (Euclidean Algorithm)]
 * 유클리드 호제법이란?
 * - 두 수가 서로 상대방 수로 나누어 원하는 결과를 얻는 알고리즘 양식.
 *
 * [약수] divisor : 어떤 수로 정수가 나누어 떨어지는지를 이르는 말.
 * 입력 받은 두 정수는 각각 다른 종류의 나누어 떨어지는 정수가 존재한다.
 * 이 정수들 중 서로 일치하는 최대 공약수를 구하여라
 *
 * [특징]
 * 두 수가 서로 정수로 나누어 떨어지는 경우 작은 수가 최대공약수 이다.
 * 두 수가 서로 정수로 나누어 떨어지지 않는 경우 나머지 값을 이용해 최대공약수를 다시 산출 할 수 있다.
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