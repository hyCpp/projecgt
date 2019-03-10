#include<stdlib.h>
#include<assert.h>
#include"Nested.h"

void stack::link::initialize(void *data, link *next) {
    Data = data;
    Next = next;
}

void stack::initialize() {
    head = 0;
}

void* stack::peek() {
    return head->Data;
}

void* stack::pop() {
    if (head == 0) {
        return 0;
    }

    void* result = head->Data;
    link* oldHead = head;
    head = head->Next;
    free(oldHead);
    return result;
}

void stack::push(void *data) {
    link* newLink = (link*)malloc(sizeof(link));
    assert(newLink);
    newLink->initialize(data, head);
    head = newLink;
}

void stack::cleanUp() {
    link* cursor = head;
    while (head) {
        cursor = cursor->Next;
        free(head->Data);
        free(head);
        head = cursor;
    }
}
