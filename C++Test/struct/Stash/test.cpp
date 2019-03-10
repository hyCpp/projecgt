#include"Stash.h"
#include<assert.h>
#include<stdio.h>
#define BUFFSIZE 80

int main() {
    Stash intStash, stringStash;
    int i;
    FILE* file;
    char buf[BUFFSIZE];
    char* cp;

    initialize(&intStash, sizeof(int));

    printf("sizeof(int) = %d", sizeof(int));

    for (i = 0; i < 100; i++) {
        add(&intStash, &i);
    }

    initialize(&stringStash, sizeof(char) * BUFFSIZE);

    file = fopen("/home/huyang/myTest/C++Test/struct/LIBTEST.C", "r");

    assert(file);

    while(fgets(buf, BUFFSIZE, file)) {
        add(&stringStash, buf);
    }

    fclose(file);

    for (i = 0; i < count(&intStash); i++) {
        printf("fetch(&inStash, %d = %d\n", i, *(int*)fetch(&intStash, i));
    }

    i = 0;

    while ((cp = (char*)fetch(&stringStash, i++)) != 0) {
        printf("fetch(&stringstash, %d) = %d", i - 1, cp);
    }

    putchar('\n');
    cleanup(&intStash);
    cleanup(&stringStash);
}
