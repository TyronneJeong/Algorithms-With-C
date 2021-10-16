#include <stdio.h>
#include <string.h>
#include "list.h"

int seq_search_implicit(int data[], int end, int target);                   /* 순차검색 - 암시적 변수사용 */
int seq_search_explicit(int data[], int begin, int end, int target);        /* 순차검색 - 명시적 변수사용 */
int seq_search_explicit_split(int data[], int begin, int end, int target);  /* 순차검색 - 명시적 변수사용 & 구간을 분리하여 탐색 */
int find_maximum_numb(int data[], int begin, int end);
int binary_search(char* str_arr[], char* target_str, int begin, int end);

/*
 * Function     : l_03_designing_recursion
 * Description  : main function of designing recursion part
 * Calls        : main.c/analysis_of_algorithms()
 * Input        : void
 * Output       : void
 * Return       : N/A
 * Others       : [순환적 알고리즘의 설계]
 *                재귀식은 적어도 하나의 base case(종료식) 을 가지고 있어야 한다.
 *                점화식 (recursion case) 은 적어도 하나 이상이여야 한다.
 *                ☞ 모든 recursion case 는 결국 base case 로 수렴 해야 한다.
 *                [암시적(implicit) 매개변수] 를 [명시적(explicit) 매개변수] 로 변경하라.
 *                ☞ seq_search_implicit 와 seq_search_explicit 로 구현
 */
void l_03_designing_recursion() {
    int serial_number[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int result  = 0;
//    result      = seq_search_implicit(serial_number, 5, 7);
//    printf("seq_search_implicit matching case is : %d\n", result);
//
//    result      = seq_search_explicit(serial_number, 0, 9, 7);
//    printf("seq_search_explicit matching case is : %d\n", result);
//
//    result      = seq_search_explicit_split(serial_number, 0, 9, 7);
//    printf("seq_search_explicit_split matching case is : %d\n", result);
//
//    result      = find_maximum_numb(serial_number, 0, 9);
//    printf("find_maximum_numb matching case is : %d\n", result);


    char* str_arr[] = {"singapore", "japan", "taiwan", "vietnam", "tailland", "indonesia", "malaysia", "korea"};
    char* target_str = "korea";
    result      = binary_search(str_arr, target_str, 0, 8);
    printf("binary_search matching case is : %d\n", result);
}

/*
 * Function     : seq_search_implicit
 * Description  : 탐색 구간 end 와 검색 값 target 을 입력받아 위치를 반환하는 함수
 * Calls        : l_03_designing_recursion.c/l_03_designing_recursion()
 * Input        : int data[], int end, int target
 * Output       : int
 * Return       : N/A
 * Others       : [암시적 (implicit) 매개변수 사용]
 *                아래 반복문(for)에서 생성된 매개변수 i 는 초기값 0과 종료값 n 가 외부의 정의없이
 *                함수내 지역 변수로 사용되고 종료된다.
 */
int seq_search_implicit(int data[], int end, int target) {
    for (int i = 0; i < end; ++i) {
        if(data[i] == target){
            return i;
        }
    }
    return -1;
}

/*
 * Function     : seq_search_explicit
 * Description  : 탐색 구간 begin, end 을 입력받아 검색 값 target 을 찾은 후 그 인덱스를 반환한다.
 * Calls        : l_03_designing_recursion.c/l_03_designing_recursion()
 * Input        : int data[], int end, int target
 * Output       : int
 * Return       : N/A
 * Others       : [명시적 (explicit) 매개변수 사용]
 *                반복문(for)에서 사용되던 매개변수 i 의 시작과 종료 값을 파라미터로 설정하였다.
 *                이로 재귀 함수의 종료 조건을 만족 시킬 변수 값이 명시적으로 할당 되었다.
 */
int seq_search_explicit(int data[], int begin, int end, int target) {
    if(begin > end){
        return -1;
    } else if (data[begin] == target) {
        return begin;
    } else {
        return seq_search_explicit(data, begin + 1, end, target);
    }
}

/*
 * Function     : seq_search_explicit_split
 * Description  : 검색 구간을 반으로 나누어 순차 탐색을 한 후 일치하는 항목의 인덱스를 반환한다.
 * Calls        : l_03_designing_recursion.c/l_03_designing_recursion()
 * Input        : int data[], int begin, int end, int target
 * Output       : int
 * Return       : N/A
 * Others       : N/A
 */
int seq_search_explicit_split(int data[], int begin, int end, int target) {
    if(begin > end){
        return -1;
    } else {
        int middle = (begin + end) / 2;
        if (data[middle] == target){
            return middle;
        }

        int index = seq_search_explicit_split(data, begin, middle - 1, target);
        if(index != -1){
            return index;
        } else {
            return seq_search_explicit_split(data, middle + 1, end, target);
        }
    }
}

/*
 * Function     : find_maximum_numb
 * Description  : 입력 된 배열의 값들 중 가장 큰 수를 리턴한다.
 * Calls        : l_03_designing_recursion.c/l_03_designing_recursion()
 * Input        : int data[], int begin, int end
 * Output       : int
 * Return       : N/A
 * Others       : N/A
 */
int find_maximum_numb(int data[], int begin, int end){
    if(begin == end){
        return data[begin];
    } else {
        int x = find_maximum_numb(data, begin, end-1);
        return data[begin] > x ? data[begin] : x;
    }
}

/*
 * Function     : find_maximum_numb_split
 * Description  : 입력 된 배열의 값들 중 가장 큰 수를 리턴한다.
 * Calls        : l_03_designing_recursion.c/l_03_designing_recursion()
 * Input        : int data[], int begin, int end
 * Output       : int
 * Return       : N/A
 * Others       : N/A
 */
int find_maximum_numb_split(int data[], int begin, int end){
    if(begin == end){
        return data[begin];
    } else {
        int middle = (begin + end) / 2;
        int max_value1 = find_maximum_numb(data, begin, middle);
        int max_value2 = find_maximum_numb(data, middle+1, end);
        return max_value1 > max_value2 ? max_value1 : max_value2;
    }
}

/*
 * Function     : binary_search
 * Description  : 입력 된 문자열 배열중 찾고자 하는 문자열의 인덱스 정보를 반환한다.
 * Calls        : l_03_designing_recursion.c/l_03_designing_recursion()
 * Input        : char* str_arr[], char* target_str, int begin, int end
 * Output       : int
 * Return       : N/A
 * Others       : N/A
 */
int binary_search(char* str_arr[], char* target_str, int begin, int end){
    if(begin > end){
        return -1;
    } else {
        int middle = (begin + end) / 2;
        printf("current value of middle is %d\n", middle);
        // 탐색순서 : 4 -> 1 -> 0 -> 2 -> 3 -> 6 -> 5 -> 7
        if (strcmp(str_arr[middle], target_str) == 0){
            return middle;
        }
        int index = binary_search(str_arr, target_str, begin, middle - 1);
        if(index != -1){
            return index;
        } else {
            return binary_search(str_arr, target_str, middle + 1, end);
        }
    }
}