#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>

using namespace std;

#define K 1024

int main() 
{
    char* c;
    int i = 0;
    c = (char*)malloc(1);

    while(1) {
        c += i*K;
        *c = 'a';
        std::cout<<i<<std::endl;
        i++;
    }
}
