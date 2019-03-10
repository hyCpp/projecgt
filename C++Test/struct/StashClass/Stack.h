#ifndef STASH_H
#define STASH_H
#include<stdlib.h>
#include<assert.h>

class Stack {
    struct link{
        void* Data;
        link* Next;
        void initialize(void* data, link* next);
    } * head;

public:
    Stack();
    ~Stack();
    void push(void* data);
    void* peek();
    void* pop();
};

#endif // STASH_H
