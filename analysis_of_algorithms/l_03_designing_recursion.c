#include <stdio.h>
#include "list.h"

int seq_search_implicit(int data[], int end, int target); /* 순차검색 - 암시적 변수사용  */
int seq_search_explicit(int data[], int start, int end, int target); /* 순차검색 - 명시적 변수사용 */

/*
 * Function     : l_03_designing_recursion
 * Description  : main function of designing recursion part
 * Calls        : main.c/analysis_of_algorithms()
 * Input        : void
 * Output       : void
 * Return       : N/A
 * Others       : 순환적 알고리즘의 설계
 * * - 적어도 하나의 base case 종료식을 가지고 있어야 한다.
 * - recursion case 는 하나 이상이여야 한다.
 *      ㄴ 모든 recursion case 는 결국 base case 로 수렴 해야 한다.
 * - 암시적(implicit)매개변수를 명시적(explicit)매개변수로 변경하라.
 */
void l_03_designing_recursion() {
    int serial_number[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    seq_search_implicit(serial_number, 5, 7);
    seq_search_explicit(serial_number, 0, 9, 7);
}

/*
 * Function     : seq_search_implicit
 * Description  :
 * Calls        : l_03_designing_recursion.c/l_03_designing_recursion()
 * Input        : int data[], int end, int target
 * Output       : int
 * Return       : N/A
 * Others       : [암시적 (implicit) 매개변수 사용]
 *                아래 반복문(for)에서 생성된 매개변수 i 는 초기값 0과 종료값 n 가 외부의 정의없이
 *                함수내 지역 변수로 사용되고 종료된다.
 */
int seq_search_implicit(int data[], int end, int target) {
    for (int i = 0; i < n; ++i) {
        if(data[i] == target){
            return i;
        }
    }
    return -1;
}

/*
 * Function     : seq_search_explicit
 * Description  :
 * Calls        : l_03_designing_recursion.c/l_03_designing_recursion()
 * Input        : int data[], int n, int target
 * Output       : int
 * Return       : N/A
 * Others       : [명시적 (explicit) 매개변수 사용]
 *                반복문(for)에서 사용되던 매개변수 i 의 시작과 종료 값을 파라미터로 설정하였다.
 *                이로 재귀 함수의 종료 조건을 만족 시킬 변수 값이 명시적으로 할당 되었다.
 */
int seq_search_explicit(int data[], int start, int end, int target) {
    return 0;
}

// 순차탐색 ver 1.

// 순차탐색 ver 2.

// 최댓값 찾기 ver 1.

// 최댓값 찾기 ver 2.

// 이진탐색 binary search