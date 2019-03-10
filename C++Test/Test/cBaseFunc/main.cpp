#include <string>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <functional>
#include <algorithm>
#include <stdint.h>

int *f(int a[], int i)
{
    return &*(a + i);
}

template<class T>
struct negate : public std::unary_function<T ,T> {
    T operator () (const T& x) const {
        return -x;
    }
};

template<class F>
double sum1(F f, int n, int m)
{
    double result = 0;
    for (int i = n; i < m; ++i) {
        result += f(i);
    }

    return result;
}

double sum(double(*Func)(double), int n, int m)
{
    double result = 0;

    for (int i = n; i < m; ++i) {
        result += Func(i);
    }

    return result;
}

void test() {
    int n = 0;
    for (int i = 0; i < 100000; ++i) {
        for (int j = 0; j < 100000; ++j) {
            for (int k = 0; k < 100000; ++k) {
                n = i + j + k;
                if (n > 1000) {
                    goto Func_End_Process;
                }
            }
        }
    }
    printf("----------------------\n");
Func_End_Process:
    printf("n = [%d]\n", n);
}

void test1() {
    int n = 0;

    loop : if (getchar() != '\n') {
        n++;
        goto loop;
    }
}

void test2() {
    int a[] = {1,2, 3};
    *f(a, 2) = 13;
    printf("%d \n", *f(a, 2));
    printf("%f \n", sum(sin, 1, 3));
    printf("%f \n", sum1(negate<double>(), 1, 3));
}

int main()
{

}
