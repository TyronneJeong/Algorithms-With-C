#include <stdio.h>
#include "list.h"
int recursive(int n);   // 재귀호출
int factorial(int n);   // 팩토리얼
int fibonacci(int n);   // 피보나치수열
int gcf(int m, int n);  // 최대공약수-유클리드호제법

void l_01_recursion(){
    int result = 0;
    result = recursive(10);
    printf("recursive Result : %d\n", result);

    result = factorial(10);
    printf("factorial Result : %d\n", result);

    result = fibonacci(10);
    printf("fibonacci Result : %d\n", result);

    result = gcf(12, 12);
    printf("gcf Result : %d\n", result);
}

// recursive
// DESC :
int recursive(int n){
    if (n <= 0){ // Base case : 종료식
        return 0;
    } else {
        printf("Remained Index : %d\n", n);
        return n + recursive(n -1); // Recursive case : base case 로 수렴하기 위한 재귀 호출
    }
}

// factorial
// DESC :
int factorial(int n){
    if (n == 0){
        return 1;
    } else {
        return n*factorial(n-1);
    }
}

// fibonacci 수열
// DESC :
int fibonacci(int n){
    if (n < 2){
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

// GCF(Greatest Common Factor) 최대 공약수 유클리스 호제법 (Euclidean Algorithm)
// DESC :
int gcf(int m, int n) {
    if(m < n) {
        int tmp = m; m = n; n = tmp; //swap m and n
    }
    if(m % n == 0) {
        return n;
    } else {
        return gcf(n, m % n);
    }
}