#include <stdio.h>
#include <string.h>
#include "list.h"

int seq_search_implicit(int data[], int end, int target);                   /* 순차검색 - 암시적 변수사용 */
int seq_search_explicit(int data[], int begin, int end, int target);        /* 순차검색 - 명시적 변수사용 */
int seq_search_explicit_split(int data[], int begin, int end, int target);  /* 순차검색 - 명시적 변수사용 & 구간을 분리하여 탐색 */
int find_maximum_numb(int data[], int begin, int end);
int binary_search();
void what_is_pointer();

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

    result      = binary_search();
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

// 이진탐색 binary search
int binary_search(){
    // 이진 탐색 알고리즘 구혀늘 위해 준비해야 하는것
    // 스트링 배열
    // 스트링 비교 strcmp
    // 재귀식은 이전과 동일



    // 포인터에 대해
    // 이중 포인터 주소
    what_is_pointer();
    return -1;
}

void print_input_string(char *str){
    printf("%s\n", str);
}
void what_is_pointer(){
    printf("\n|********************************[ variables ]*******************************|");
    /* [initiate variables] ****************************************************************************/
    int int_value               = 1;
    double double_value         = 2;
    char char_value             = 'A';
    char *char_pointer          = "ABC";

    /* [print literals] ********************************************************************************/
    printf("\n");
    printf("int_value            is : %d\n", int_value);
    printf("double_value         is : %f\n", double_value);
    printf("char_value           is : %c\n", char_value);
    printf("char_pointer         is : %s\n", char_pointer);                     // '\0' 를 만날떄까지 출력하는건가?

    /* [basic value] ***********************************************************************************/
    printf("\n");
    printf("int_value            is : %d\n", int_value);                        // literal of int_value
    printf("&int_value           is : %d\n", &int_value);                       // address of int_value
    printf("*int_value           is : not working\n");                          // it is not work. cause, pointer does not knows correct address to get value. pointer is only for use address value.
    printf("*char_value          is : not working\n");                          // it is not work. cause, pointer does not knows correct address to get value. pointer is only for use address value.

    printf("\n");
    int_value = 3;
    printf("set 3 to int_value   is : %d\n", int_value);                        // literal of int_value
    printf("set 3 to &int_value  is : %d (same address)\n", &int_value);        // nothing change the address of int_value

    printf("\n");
    int int_value_copy = int_value;                                             // create new variable to save value from int_value
    printf("int_value_copy       is : %d\n", int_value_copy);                   // int_value_copy has same value between int_value
    printf("&int_value_copy      is : %d (diff address)\n", &int_value_copy);   // but, it is not allocated same address to int_value_copy

    printf("\n|*********************************[ arrays ]*********************************|");
    /* [initiate arrays] *******************************************************************************/
    int int_array[]             = {1, 2, 3, 4, 5};
    double double_array[]       = {1, 2, 3, 4, 5};
    char char_array[]           = {'A', 'B', 'C'};
    char *char_pointer_array[]  = {"ABC", "EFG", "HIJ"};

    /* [address of variables] **************************************************************************/
    /* '*' (pointer) 와  '&' (the address of operator) 의 관계 */
    printf("\n");
    printf("int_array %%d         is : %d\n", int_array);                       // int_array 변수에는 배열의 주소 값이 저장되어 있다.
    printf("int_array %%p         is : %p\n", int_array);                       // 변수 (int_array) 가 할당되어 있는 주소 정보가 출력 된다. (%p 파라미터는 32비트의 경우 16진수 주소 정보 8자리를 출력하는 포맷 형식 이다.)
    printf("&int_array           is : %p\n", &int_array);                       // It returns memory location of the variable.
    printf("&int_array[0]        is : %p\n", &int_array[0]);                    // 변수 (int_array) 가 가리키는 주소 정보와 동일한 주소 정보가 출력 된다.

    // %d (10진수) 형식의 정수형 변수 하나를 출력 요청하였으므로. 1이 리턴된다.
    // 출력 포맷(%d, %f, %c)은 기계적인 데이터를 읽어 화면에 나타내고자 하는 자료 형식으로 변환하는 구문이다.
    printf("\n");
    printf("*int_array           is : %d\n", *int_array);                       // 포인터는 주소 정보에 존재하는 실제 값을 리턴 한다.
    printf("*&int_array[0]       is : %d\n", *&int_array[0]);                   // 변수가 가리키는 곳

    printf("\n");
    printf("*&int_array          is : %d\n", *&int_array);                      // 새롭게 가리키는 주소가 가리키는 목적지의 정보를 읽어온다.
    printf("&*&int_array         is : %d\n", &*&int_array);                     // 값이 저장된 주소공간을 가리키는 값 을 포인터로 가리키고 그 주소정보를 다시 확인함
    printf("&*&*int_array        is : %d\n", &*&*&int_array);                   // 값이 저장된 주소공간을 가리키는 값 을 포인터로 가리키고 그 주소공간을 가리키는 값 을 포인터로 가리키고 그 주소정보를 다시 확인함

    printf("\n|******************************[ array cursor ]******************************|");
    /* [size of variables] *****************************************************************************/
    printf("\n");
    printf("int    size          is : %d\n", sizeof(int));                      // int 형 자료의 크기 4byte
    printf("double size          is : %d\n", sizeof(double));                   // double 형 자료의 크기 8byte
    printf("char*  size          is : %d\n", sizeof(char*));                    // char 형 자료의 크기 4byte

    printf("\n");
    printf("int                  is : %d, %p\n", (int*)1         , (int*)1);
    printf("double               is : %d, %p\n", (double*)1      , (double*)1);
    printf("char                 is : %d, %p\n", sizeof(char)    , sizeof(char)); // TODO ? 왜 char 만 다르지?

    /* [move cursor] ***********************************************************************************/
    printf("\n");
    printf("*int_array + 1       is : %d\n", *int_array + 1);                   // 주소값에서의 연산 : 주소공간에서 n * (4byte) 만큼 이동한 위치의 정수 값을 가져온다.
    printf("*int_array + (int)1  is : %d\n", *int_array + (int)1);              // 캐스팅 타입의 영향은 받지 않는다. 덧셈 연산은 오로지 자료형의 크기에 비례하여 계산된다.
    printf("*int_array + (int*)1 is : %d\n", *int_array + (int*)1);             // 캐스팅 타입의 영향을 받는 예 : 주소공간에서 (int* = 4이므로) 4 * n * (4byte) 만큼 이동한 위치의 정수 값을 가져온다.

    printf("\n");
    printf("*double_array        is : %f\n", double_array);
    printf("*double_array + 1    is : %f\n", *double_array + 1);                // 주소값에서의 연산 : 주소공간에서 double size(8byte) * n 만큼 이동한 위치의 정수 값을 가져온다.

    printf("\n|*****************************[ double pointer ]*****************************|");
    /* [pointer variable] ******************************************************************************/
    printf("\n");
    int a       = 10;   // int 형 변수 a
    double b    = 20;   // double 형 변수 b
    int *p;             // 4 byte pointer variable (포인터 변수의 크기는 자료형에 따라 달라진다.)
    int **pp;           // double pointer variable
    double *dp;         // 8 byte pointer variable

    // 포인터 변수에는 기본적으로 주소 값이 들어와야 한다.
    printf("size of p   >> %d\n", sizeof(p));   // 4 byte 주소 정보
    printf("size of *p  >> %d\n", sizeof(*p));  // 4 byte int 값
    printf("size of dp  >> %d\n", sizeof(dp));  // 4 byte 주소 정보
    printf("size of *dp >> %d\n", sizeof(*dp)); // 8 byte double 값

    /* [서로 다른 크기의 포인터 변수 대입] ******************************************************************/
    printf("\n");
    dp = &a; // 4 byte int 형 변수의 주소 값 대입
    printf("value of *dp >> %d\n", *dp); // 4 byte int 로 출력시 정상 값 출력
    printf("value of *dp >> %f\n", *dp); // 8 byte double 로 출력시 0 리턴

    printf("\n");
    dp = &b; // 8 byte double 형 변수의 주소 값 대입
    printf("value of *dp >> %d\n", *dp); // 4 byte int 로 출력시 0 리턴
    printf("value of *dp >> %f\n", *dp); // 8 byte double 로 출력시 정상 값 출력

    /* [**] *******************************************************************************************/
    p  = &a; // p  --> a
    pp = &p; // pp --> p --> a

    printf("\n");
    printf("value   stored a     is : %d\n",    a);  // a    == 10
    printf("value   stored at p  is : %d\n",   *p);  // *p   == a (10)
    printf("value   stored at pp is : %d\n", **pp);  // **pp == a (10)

    printf("\n");
    printf("value   stored a     is : %d\n",    a);  // a  == 10
    printf("address of a         is : %p\n",   &a);  // &a == Ø

    printf("\n");
    printf("address stored at p  is : %p\n",    p);  // p  == &a
    printf("value   stored at p  is : %d\n",   *p);  // *p == a (10)

    printf("\n");
    printf("address of p         is : %p\n",   &p);  // &p == Ø
    printf("address stored at pp is : %p\n",   pp);  // pp == &p

    printf("\n");
    printf("address of pp        is : %p\n",  &pp);  // &pp  == &p
    printf("value   stored at pp is : %d\n", **pp);  // **pp == a

    printf("\n|****************************[ function pointer ]****************************|");
    /* [] ***********************************************************************************/
    printf("\n");
    void (*fp)(char* str);      // declare function pointer variable
    fp = print_input_string;
    fp("this function has been make by function pointer");

    // 다이나믹한 함수 호출

    printf("\n|****************************[ array pointer ]****************************|");
    // 다른 배열을 가리키는 포인터

    printf("\n|****************************[ pointer array ]****************************|");
    // 배열의 저장 데이터가 포인터

    printf("\n|****************************[ const pointer ]****************************|");
    // 포인터가 가리키는 내용을 변경하지 않겠다.
    // ex. const int* ptr;


    // 포인터가 가리키고 있는 주소 값을 변경하지 않겠다.
    // ex. char* const ptr;

    printf("\n|****************************[ void pointer ]****************************|");
    // 순수하게 메모리 주소값만 가진다.
}

