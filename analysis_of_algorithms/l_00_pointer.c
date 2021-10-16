#include <stdio.h>
#include "list.h"

void print_input_string(char *str);
void add(int a, int b);
void subtract(int a, int b);
void multiply(int a, int b);
int* return_local_int_var_ptr();
int  compare(const void *a, const void *b);
void what_is_pointer();

/*
 * Function     : l_00_pointer
 * Description  : main function of pointer part
 * Calls        : main.c/analysis_of_algorithms()
 * Input        : void
 * Output       : void
 * Return       : N/A
 * Others       : N/A
 */
void l_00_pointer(){
    what_is_pointer();
}

/*
 * Function     : print_input_string
 * Description  : 입력 문자열을 출력한다. (void pointer 예시용)
 * Calls        : l_00_pointer.c/what_is_pointer()
 * Input        : char *str
 * Output       : void
 * Return       : N/A
 * Others       : N/A
 */
void print_input_string(char *str){
    printf("%s\n", str);
}

/*
 * Function     : add
 * Description  : 입력 받은 두 정수의 합을 출력 한다. (void pointer 예시용)
 * Calls        : l_00_pointer.c/what_is_pointer()
 * Input        : int a, int b
 * Output       : void
 * Return       : N/A
 * Others       : N/A
 */
void add(int a, int b) {
    printf("Addition is %d\n", a+b);
}

/*
 * Function     : subtract
 * Description  : 입력 받은 두 정수의 차를 출력 한다. (void pointer 예시용)
 * Calls        : l_00_pointer.c/what_is_pointer()
 * Input        : int a, int b
 * Output       : void
 * Return       : N/A
 * Others       : N/A
 */
void subtract(int a, int b) {
    printf("Subtraction is %d\n", a-b);
}

/*
 * Function     : multiply
 * Description  : 입력 받은 두 정수의 곱을 출력 한다. (void pointer 예시용)
 * Calls        : l_00_pointer.c/what_is_pointer()
 * Input        : int a, int b
 * Output       : void
 * Return       : N/A
 * Others       : N/A
 */
void multiply(int a, int b) {
    printf("Multiplication is %d\n", a*b);
}

/*
 * Function     : return_local_int_var_ptr
 * Description  : 함수내 지역 변수의 주소값을 리턴 한다.(dangling pointer 예시용)
 * Calls        : l_00_pointer.c/what_is_pointer()
 * Input        : void
 * Output       : int*
 * Return       : N/A
 * Others       : N/A
 */
int* return_local_int_var_ptr(){
    int num = 5;        // 지역변수는 해당 함수가 종료 된 후에는 사용 메모리가 해제 된다.
    return &num;        // 함수 종료 후 종료될 값의 주소를 리턴
}

/*
 * Function     : return_static_int_var_ptr
 * Description  : 함수내 static 으로 선언된 지역 변수의 주소값을 리턴 한다.(dangling pointer 예시용)
 * Calls        : l_00_pointer.c/what_is_pointer()
 * Input        : void
 * Output       : int*
 * Return       : N/A
 * Others       : N/A
 */
int* return_static_int_var_ptr(){
    static int num = 5; // static 공간에 선언된 변수는 함수 종료 후에도 값이 유지된다.
    return &num;        // 함수 종료 후 종료될 값의 주소를 리턴
}

/*
 * Function     : compare
 * Description  : 함수 인자로 사용된 void pointer 가 서로 같은지를 비교하여 차를 반환한다.(void pointer 예시용)
 * Calls        : l_00_pointer.c/what_is_pointer()
 * Input        : const void *a, const void *b
 * Output       : int
 * Return       : N/A
 * Others       : N/A
 */
int compare (const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

/*
 * Function     : what_is_pointer
 * Description  : pointer 변수를 정의하고 사용하는 다양한 예시를 제공한다.
 * Calls        : l_00_pointer.c/l_00_pointer()
 * Input        : void
 * Output       : void
 * Return       : N/A
 * Others       : [목차]
 *                01. 포인터 변수의 선언과 활용
 *                02. 배열 형태의 포인터 변수의 선언과 활용
 *                03. 포인터 변수에서 커서 이동과 선택
 *                04. 더블 포인터의 선언과 활용
 *                05. 함수 포인터의 선언과 활용
 *                06. 포인터 배열의 선언과 활용
 *                07. 배열 포인터의 선언과 활용
 *                08. 상수 포인터의 선언과 활용
 *                09. void 포인터의 선언과 활용
 *                10. dangling 포인터의 선언과 예시
 *                11. null 포인터의 선언과 예시
 *                12. wild 포인터의 선언과 예시
 */
void what_is_pointer(){
    printf("\n|*********************************************************************************************|");
    printf("\n|****************************************[ variables ]****************************************|");
    printf("\n|*********************************************************************************************|");
    /* 변수 선언 - decleare variables */
    int     int_value            = 1;
    double  double_value         = 2;
    char    char_value           = 'A';
    char    *char_pointer        = "ABC";

    /* 자료 유형별 저장 값 출력 */
    printf("\n");
    printf("int_value            is : %d\n", int_value);
    printf("double_value         is : %f\n", double_value);
    printf("char_value           is : %c\n", char_value);
    printf("char_pointer         is : %s\n", char_pointer);                     // '\0' 를 만날떄까지 출력하는건가?

    /* 값, 주소값, 포인터를 각 출력 */
    printf("\n");
    printf("int_value            is : %d\n", int_value);                        // int_value 의 값
    printf("&int_value           is : %d\n", &int_value);                       // int_value 의 주소 값
    printf("*int_value           is : not working\n");                          // int_value 자체는 리터럴 이므로 리터럴에 포인터 지칭은 불가능 하다.
    printf("*char_value          is : not working\n");                          // char_value 자체는 리터럴 이므로 리터럴에 포인터 지칭은 불가능 하다.

    printf("\n");
    int_value = 3;
    printf("set 3 to int_value   is : %d\n", int_value);                        // int_value 에 새로운 값을 담아 출력
    printf("set 3 to &int_value  is : %d (same address)\n", &int_value);        // 새로운 값을 저장하여도 주소 정보에는 변경이 없다.

    printf("\n");
    int int_value_copy = int_value;                                             // 새로운 변수를 선언 후 int_value 의 값을 대입 받은 경우.
    printf("int_value_copy       is : %d\n", int_value_copy);                   // int_value_copy 는 int_value와 동일한 값을 가지게 된다.
    printf("&int_value_copy      is : %d (diff address)\n", &int_value_copy);   // 하지만, int_value_copy 는 int_value 와 다른 주소 값을 가지게 된다.

    printf("\n|*********************************************************************************************|");
    printf("\n|*****************************************[ arrays ]******************************************|");
    printf("\n|*********************************************************************************************|");
    /* 각 자료형별 배열 변수 선언 */
    int     int_array[]             = {1, 2, 3, 4, 5};
    double  double_array[]          = {1, 2, 3, 4, 5};
    char    char_array[]            = {'A', 'B', 'C'};
    char    *char_pointer_array[]   = {"ABC", "EFG", "HIJ"};

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

    printf("\n|*********************************************************************************************|");
    printf("\n|**************************************[ array cursor ]***************************************|");
    printf("\n|*********************************************************************************************|");
    /* 각 자료형의 크기 값 출력 */
    printf("\n");
    printf("int    size          is : %d\n", sizeof(int));                      // int 형 자료의 크기 4byte
    printf("double size          is : %d\n", sizeof(double));                   // double 형 자료의 크기 8byte
    printf("char*  size          is : %d\n", sizeof(char*));                    // char 형 자료의 크기 4byte

    printf("\n");
    printf("int                  is : %d, %p\n", (int*)1         , (int*)1);
    printf("double               is : %d, %p\n", (double*)1      , (double*)1);
    printf("char                 is : %d, %p\n", sizeof(char)    , sizeof(char)); // TODO ? 왜 char 만 다르지?

    /* 배열 앨리먼트를 카리키는 커서의 이동 */
    printf("\n");
    printf("*int_array + 1       is : %d\n", *int_array + 1);                   // 주소값에서의 연산 : 주소공간에서 n * (4byte) 만큼 이동한 위치의 정수 값을 가져온다.
    printf("*int_array + (int)1  is : %d\n", *int_array + (int)1);              // 캐스팅 타입의 영향은 받지 않는다. 덧셈 연산은 오로지 자료형의 크기에 비례하여 계산된다.
    printf("*int_array + (int*)1 is : %d\n", *int_array + (int*)1);             // 캐스팅 타입의 영향을 받는 예 : 주소공간에서 (int* = 4이므로) 4 * n * (4byte) 만큼 이동한 위치의 정수 값을 가져온다.

    printf("\n");
    printf("*double_array        is : %f\n", double_array);
    printf("*double_array + 1    is : %f\n", *double_array + 1);                // 주소값에서의 연산 : 주소공간에서 double size(8byte) * n 만큼 이동한 위치의 정수 값을 가져온다.

    printf("\n|*********************************************************************************************|");
    printf("\n|*************************************[ double pointer ]**************************************|");
    printf("\n|*********************************************************************************************|");
    /* 포인터 & 더블 포인터 변수 선언 */
    int     a       = 10;   // int 형 변수 a
    double  b       = 20;   // double 형 변수 b
    int     *p;             // 4 byte pointer variable (포인터 변수의 크기는 자료형에 따라 달라진다.)
    int     **pp;           // double pointer variable
    double  *dp;            // 8 byte pointer variable

    /* 포인터 변수에는 기본적으로 주소 값이 들어와야 한다. */
    printf("\n");
    printf("size of p   >> %d\n", sizeof(p));       // 4 byte 주소 정보
    printf("size of *p  >> %d\n", sizeof(*p));      // 4 byte int 값
    printf("size of dp  >> %d\n", sizeof(dp));      // 4 byte 주소 정보
    printf("size of *dp >> %d\n", sizeof(*dp));     // 8 byte double 값

    /* 서로 다른 크기의 포인터 변수 대입 */
    dp = &a; // 4 byte int 형 변수의 주소 값 대입
    printf("\n");
    printf("value of *dp >> %d\n", *dp);            // 4 byte int 로 출력시 정상 값 출력
    printf("value of *dp >> %f\n", *dp);            // 8 byte double 로 출력시 0 리턴 (오류)

    dp = &b; // 8 byte double 형 변수의 주소 값 대입
    printf("\n");
    printf("value of *dp >> %d\n", *dp);            // 4 byte int 로 출력시 0 리턴
    printf("value of *dp >> %f\n", *dp);            // 8 byte double 로 출력시 정상 값 출력

    /* 더블 포인터 자료형의 활용 */
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

    printf("\n|*********************************************************************************************|");
    printf("\n|************************************[ function pointer ]*************************************|");
    printf("\n|*********************************************************************************************|");
    /* function pointer 의 선언 */
    void (*fp)(char* str);      // declare function pointer variable
    fp = print_input_string;

    printf("\n");
    fp("this function has been make by function pointer");

    /* function pointer 를 활용한 다이나믹한 함수 호출 */
    void (*fp_arr[])(int a, int b) = {add, subtract, multiply};

    /* 각 배열에 저장된 함수를 차례로 실행 시킨다. */
    for (int i = 0; i < 3; ++i) {
        fp_arr[i](3, 2);
    }

    printf("\n|*********************************************************************************************|");
    printf("\n|**************************************[ pointer array ]**************************************|");
    printf("\n|*********************************************************************************************|");
    /* 배열의 저장 데이터가 포인터 */
    int*    int_ptr_array[2];
    double* double_ptr_array[3];

    /* 저장된 공간의 크기 */
    printf("\n");
    printf("sizeof(int_ptr_array[0])    is %d\n", sizeof(int_ptr_array[0]));
    printf("sizeof(double_ptr_array[0]) is %d\n", sizeof(double_ptr_array[0]));

    /* 저장된 값의 종류와 호출 */
    int int_ptr1 = 1;
    int int_ptr2 = 2;
    int int_ptr3 = 3;

    int_ptr_array[0] = &int_ptr1;
    int_ptr_array[1] = int_ptr2;

    printf("\n");
    printf("int_ptr_array[0]     is %p\n"   , int_ptr_array[0]);    // 배열[0] 번째 원소는 주소값이 담겨 있다.
    printf("*int_ptr_array[0]    is %d\n"   , *int_ptr_array[0]);   // 포인터 변수로 주소 값을 호출 함
    printf("int_ptr_array[1]     is %d\n"   , int_ptr_array[1]);    // 주소값을 담지 않아도 정상 출력 됨.

    /* 자료형의 크기가 서로 다른 포인터 주소 대입 */
    int double_ptr1 = 1;
    int double_ptr2 = 2;

    double_ptr_array[0] = &double_ptr1; // 정상적인 주소값 대입
    double_ptr_array[1] = double_ptr2;  // 리터럴 대입
    double_ptr_array[2] = int_ptr3;     // 4byte int 형 주소값 대입

    printf("\n");
    printf("double_ptr_array[0]     is %p\n" , double_ptr_array[0]);    // 배열[0] 번째 원소는 주소값이 담겨 있다.
    printf("*double_ptr_array[0]    is %d\n" , *double_ptr_array[0]);   // 포인터 변수로 주소 값을 호출 함

    printf("\n");
    printf("double_ptr_array[1]     is %d\n" , double_ptr_array[1]);    // 주소값을 담지 않아도 정상 출력 됨.
    printf("double_ptr_array[1]     is %d\n" , double_ptr_array[1]);    // 주소값을 담지 않아도 정상 출력 됨.

    printf("\n");
    printf("double_ptr_array[2]     is %d\n" , double_ptr_array[2]);    // int 형 자료도 정상 출력 됨
    printf("*double_ptr_array[2] %%d is %d\n", double_ptr_array[2]);    // int 형 자료도 정상 출력 됨
    printf("*double_ptr_array[2] %%f is %f\n", double_ptr_array[2]);    // int 형 을 %f 출력시 0 리턴 (오류)

    printf("\n|*********************************************************************************************|");
    printf("\n|**************************************[ array pointer ]**************************************|");
    printf("\n|*********************************************************************************************|");
    /* deep copy */
    int int_arr[3] = {1, 2, 3};
    int (*int_arr_ptr)[3];      // 다른 배열을 가리키는 포인터
    int_arr_ptr = *int_arr;     // 포인터 대입은 deep copy

    printf("\n");
    printf("int_arr     address  is %p\n", int_arr);            // 서로다른 주소 정보를 가진다.
    printf("int_arr_ptr address  is %p\n", int_arr_ptr);        // 서로다른 주소 정보를 가진다.

    printf("\n");
    printf("int_arr[0]           is %d\n", int_arr[0]);         // int_arr의 앨리먼트와 int_arr_ptr의 앨리먼트의 값이 동일하다.
    printf("int_arr_ptr[0]       is %d\n", int_arr_ptr[0]);     // int_arr의 앨리먼트와 int_arr_ptr의 앨리먼트의 값이 동일하다.

    printf("\n");
    int_arr[0] = 9;
    printf("int_arr[0]           is %d\n", int_arr[0]);         // int_arr[0]의 앨리먼트의 값은 변경되었다.
    printf("int_arr_ptr[0]       is %d\n", int_arr_ptr[0]);     // int_arr_ptr[0]의 앨리먼트값은 변화가 없다.

    /* shallow copy */
    int_arr_ptr = &int_arr;     // 주소 값 대입은 shallow copy

    printf("\n");
    printf("int_arr     address  is %p\n" , int_arr);           // 동일한 주소정보를 가진다.
    printf("int_arr_ptr address  is %p\n" , int_arr_ptr);       // 동일한 주소정보를 가진다.

    printf("\n");
    printf("int_arr[0]           is %d\n" , int_arr[0]);        // int_arr의 앨리먼트와 int_arr_ptr의 앨리먼트의 값이 동일하다.
    printf("*int_arr_ptr[0]      is %d\n" , *int_arr_ptr[0]);   // int_arr의 앨리먼트와 int_arr_ptr의 앨리먼트의 값이 동일하다.

    int_arr[0] = 5;
    printf("\n");
    printf("int_arr[0] = 5\n");
    printf("int_arr[0]           is %d\n" , int_arr[0]);        // int_arr의 첫번째 앨리먼트에 5를 대입하였다.
    printf("*int_arr_ptr[0]      is %d\n" , *int_arr_ptr[0]);   // 참조복사 관계인 int_arr_ptr의 첫번째 앨리먼트에도 5가 출력된다.

    printf("\n|*********************************************************************************************|");
    printf("\n|**************************************[ const pointer ]**************************************|");
    printf("\n|*********************************************************************************************|");
    /* [const int*] : 입력 정수 값 대입의 상수화 (immutable) */
    int int_99 = 99;
    int int_999 = 999;

    const int* cont_int_ptr;
    cont_int_ptr = &int_99;                 // 참조 주소 정보 대입은 가능.

    printf("\n");
    printf("cont_int_ptr address is : %u\n", cont_int_ptr);
    printf("*cont_int_ptr value  is : %d\n", *cont_int_ptr);

    // *cont_int_ptr = 300;                 // 변수에 저장된 값 변경시 오류 발생
    cont_int_ptr = &int_999;                // 참조 주소 정보 대입은 가능.
    printf("\n");
    printf("cont_int_ptr address is : %u\n", cont_int_ptr);
    printf("*cont_int_ptr value  is : %d\n", *cont_int_ptr);

    /* [int* const] : 참조 주소정보 대입의 상수화 (immutable) */
    int* const int_const_ptr = &int_999;

    printf("\n");
    printf("int_const_ptr addr   is : %u\n", int_const_ptr);
    printf("*int_const_ptr value is : %d\n", *int_const_ptr);

    // *int_const_ptr = &int_99;            // 참조 주소 정보 변경시 오류 발생.
    *int_const_ptr = 333;                   // 변수에 저장된 값 변경은 가능.

    printf("\n");
    printf("int_const_ptr addr   is : %u\n", int_const_ptr);
    printf("*int_const_ptr value is : %d\n", *int_const_ptr);

    printf("\n|*********************************************************************************************|");
    printf("\n|**************************************[ void pointer ]***************************************|");
    printf("\n|*********************************************************************************************|");
    void *vptr; // 포인터 유형을 정의하지 않은 포인터를 의미하며, void pointer 는 포인터 '유형' 중 하나 이다.
    // 포인터 유형을 정의하는 것은 주소 공간마다 대입되는 자료형을 알기 위함이다.
    // 32bit 기준 주소 공간의 값은 8bit(1Byte) * 4 = 32bit 이므로. 주소 값은 자료형에 관계 없이 모두 4byte 가 된다.

    int     int_vp      = 1;
    float   float_vp    = 1.0;
    char    char_vp     = 'A';
    double  double_vp   = 9;
    char*   char_ptr_vp = "arabica coffee";

    vptr = &int_vp;
    printf("\n");
    printf("&int_vp              is %p\n", &int_vp);
    printf("vptr                 is %p\n", vptr);

    printf("\n");
    printf("casting size (int*)  is %d\n", sizeof(int*));       // 10진수 정수형 자료형
    printf("casting size (float*)is %d\n", sizeof(float*));     // 부동 소수점을 관리하는 자료형

    printf("\n");
    printf("*(int*)   vptr       is %d\n", *(int*)vptr);
    printf("*(long*)  vptr       is %ld\n", *(long*)vptr);      // 정상출력
    printf("*(float*) vptr       is %f\n", *(float*)vptr);      // void pointer 에 float 형으로 캐스팅을 하였지만 값은 나오지 않는다.

    printf("\n");
    vptr = &float_vp;
    printf("*(float*)vptr        is %f\n", *(float*)vptr);      // float 형 자료를 대입한 경우에는 정상적으로 출력된다.

    printf("\n");
    vptr = &char_vp;
    printf("*(char*)vptr         is %c\n", *(char*)vptr);       // 정상출력

    printf("\n");
    vptr = &double_vp;
    printf("*(double*)vptr       is %f\n", *(double*)vptr);     // 정상출력

    printf("\n");
    vptr = &char_ptr_vp;
    printf("*(char**)vptr        is %s\n", *(char**)vptr);      // char*의 경우는 더블 포인터를 이용하여 준다.

    // 참조 값의 비교
    int int_vp2 = 1;
    int result = compare(&int_vp, &int_vp2);                    // void pointer 를 인자로 받는 경우

    printf("\n");
    printf("compare result       is %d\n", int_vp == int_vp2 ); // 1 이 true
    printf("result of compare    is %d\n", result);             // 0 이 true

    printf("\n|*********************************************************************************************|");
    printf("\n|*************************************[ dangling pointer ]************************************|");
    printf("\n|*********************************************************************************************|");
    // int *rtn = return_local_int_var_ptr(); - 삭제된 메모리 공간을 참조 하는 포인터로 컴파일시 오류가 발생된다.
    int *rtn = return_static_int_var_ptr(); // 함수내 사용된 지역변수를 리턴 받기 위해서는 변수를 static 공간에 선언한다.

    printf("\n");
    printf("dangling pointer     is not working\n");
    printf("static pointer value is %d\n", *rtn);

    printf("\n|*********************************************************************************************|");
    printf("\n|**************************************[ null pointer ]***************************************|");
    printf("\n|*********************************************************************************************|");
    int *null_ptr = NULL;        // 초기화를 NULL 로 한 포인터 변수. NULL 은 알수 없는 '값'이다.
    printf("\n");
    printf("*null_ptr            is %p\n", null_ptr);

    printf("\n|*********************************************************************************************|");
    printf("\n|**************************************[ wild pointer ]***************************************|");
    printf("\n|*********************************************************************************************|");
    int *wild_ptr;               // 포인터 변수 선언 이후 별도의 초기화 하지 않은 변수를 wild pointer 라고 한다.
    printf("\n");
    // printf("*wild_ptr            is %p\n", *wild_ptr); // 출력 가능한 값이 존재하지 않는다.
}