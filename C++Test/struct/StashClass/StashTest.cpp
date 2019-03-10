#include<stdio.h>
#include<string.h>
#include<assert.h>
#include"Stack.h"
#define BUFFSIZE 100

int main(int argc, char* argv[]) {
    Stack textLines;
    FILE* file = fopen(argv[1], "r");
    char* s;
    char buf[BUFFSIZE];

    printf("%d", argc);

    file = fopen(argv[1], "r");

    assert(file);

    while(fgets(buf, BUFFSIZE, file)) {
        char* string = (char*)malloc(strlen(buf) + 1);
        assert(string);
        strcpy(string, buf);
        textLines.push(string);
    }

    while ((s = (char*)textLines.pop()) != 0) {
        printf("%s", s);
        free(s);
    }

    return 0;
}
