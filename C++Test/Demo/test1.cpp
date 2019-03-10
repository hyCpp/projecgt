#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

char onechar(const char* string = 0) {
	static const char* s;
	if (string) {
		s = string;
		return *s;
	} else {
		//allege(s, "un-initialized s");
	}
	
	if (*s == '\0') {
		return 0;
	}
	return *s++;
}

int main() 
{
    char* a = "hello world";
    onechar(a);
    char c;
    while ((c = onechar()) != 0) {
        std::cout<<c<<std::endl;
    }    
}

