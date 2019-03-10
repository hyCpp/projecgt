#include <stdio.h>
#include <string>
#include <iostream>
#include <string.h>
#include<stdlib.h>

using namespace std;
void test(int* x) {
    *x =10;
}

void testInt(int &x) {
    x =10;
}

void test1(std::string* y) {
    std::string b = "test";
    y = &b;
}

void test2(std::string* &y) {
    std::string b = "test";
    y = &b;
}

void test3(std::string* str) {
    *str = "test";
}

void stringConcate(char* dest, char *source) {
    while (*dest != '\0') {
        dest++;
    }

    while ((*dest = *source) != '\0') {
        source++;
        dest++;
    }
}

int main() {
    /**
    int x[3][2] = {
      10, 20 ,30 ,40 ,50 ,60
    };

    int i, j;

    printf("x = %p\n", x);
    printf("\n");

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 2; ++j) {
            printf("&x[%d][%d] = %p\n", i, j, &x[i][j]);
        }
    }

    printf("\n");

    for (i = 0; i < 3; ++i) {
        printf("x[%d] = %p\n", i, x[i]);
    }

    printf("\n");

    for (i = 0; i < 3; ++i) {
        printf("x + %d = %p\n", i, x + i);
    }
    */

    /**  testEnum  abc = testEnum::testEnum_test1;
    std::cout<<abc<<std::endl;
    int x = 0;
    test(&x); // & is Real argument
    printf("x = %d",x);

    std::string* y = new std::string;
    *y = "";
    test1(y); //formal parametrt
    printf("y = %s",(*y).c_str());

    std::string* y1 = new std::string;
    *y1 = "";
    test2(y1);
    printf("y = %s",(*y1).c_str());    nutshell1::media::testEnum1  abc = nutshell1::media::testEnum1::testEnum_test1;
        std::cout<<abc<<std::endl;

    std::string str = "";
    test3(&str);
    printf("str = %s\n", str.c_str());
    */


    /**
    int x = 100;
    int *p1 = &x;
    int **p2 = &p1;
    printf("&x  = %p\n",&x);
    printf("&p1=%p, p1=%p\n", &p1, p1);
    printf("**p2=%d, *p1=%d\n",**p2, *p1);
    printf("*p2=%p, p2=%p\n",*p2, p2);

    char* test = "This is only test";
    char* t1 = test;
    char **t2 = &t1;
    char ***t3 = &t2;
    printf("test = %p\n", &test);
    printf("t1 = %p\n", &t1);
    printf("t2 = %p\n", t2);
    printf("t3 = %p\n", t3);
    */

    /**
    int arr[] = {1,2,3,4}; //arr is constant point
    int *ptr = arr; //ptr is variable point
    int i, size;
    size = (sizeof arr/sizeof(arr[0]));
    for (i = 0; i <size; ++i) {
        printf("&arr[%d] = %x\n", i, &arr[i]);
    }
    for (i = 0; i <size; ++i) {
        printf("arr + %d = %x\n", i, arr + i);
    }
    for (i = 0; i <size; ++i) {
        printf("*(arr+%d) = %x\n", i, *(arr + i));
    }

    for (i = 0; i <size; ++i) {
        printf("ptr+%d = %x\n", i, ptr + i);
    }
    for (i = 0; i <size; ++i) {
        printf("ptr[%d] = %d\n", i, ptr[i]);
    }
    for (i = 0; i <size; ++i) {
        printf("*(ptr+%d) = %d\n", i, *(ptr + i));
    }
    */

    /**
    int arr[3][4] = {0,1,2,3, 4,5,6,7, 8,9,10,11};
    int *ptr1[3] = {arr[0], arr[1], arr[2]};
    int **ptr = ptr1;
    printf("value = %d\n", *    namespace name {
    enum test{

    };
    };(*(arr+1)+1));
    printf("value = %d\n", ptr[1][1]);
    printf("value = %d\n", *(ptr[1]+1));
    printf("value = %d\n", *(*(ptr+1)+1));
    */

//    int a;

//    a =static_cast<int>(Voice::testEnum::test1);
//    Voice::testEnum test = Voice::testEnum::test1;

//    printf("t = %d", test);
    /**
    char str1[1000] = "The distance instance in the world,";
    char *str2 = " Is not between in death and life.";
    stringConcate(str1, str2);
    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);
    */

//    int test = 9;
//    testInt(test);
//    printf("%d\n", test);

//    union test{
//        int one;
//        char* str;
//        bool two;
//    };

//    test t;
//    t.one = 1;
//    t.str = "test";
//    t.two = false;
//    printf("%d %s %d", t.one, t.str, t.two);

    const char* str = "hello world"; // 就是 char *s 只是一个保存字符串首地址的指针变量
    const char test[] = {"huyang"}; // 许多连续的内存单元 str = test,ok ; test = str,error
    printf("%s\n", &test[0]);

    str = "no";

    printf("%s\n", str);
    printf("%d\n", sizeof(str));
    printf("%d\n", sizeof(test));

    for (int i = 0; i < strlen(str); ++i) {
        printf("%c", *str++);
    }

//    char* const str1 = "hello world";
//    str1 = "no";
//    printf("%s\n", str1);
    char  **s ;
    s = (char **) malloc(sizeof(char**));
    *s =  "hello world";
}
