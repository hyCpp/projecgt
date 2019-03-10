#include"Stack.h"

void Stack::link::initialize(void *data, link *next) {
    Data = data;
    Next = next;
}

Stack::Stack() {
    head = 0;
}

Stack::~Stack() {
    link* cursor = head;
    while (head) {
        cursor = cursor->Next;
        free(head->Data);
        free(head);
        head = cursor;
    }

    head = NULL;
}

void Stack::push(void *data) {
    link* newLink = (link*)malloc(sizeof(link));
    assert(newLink);
    newLink->initialize(data, head);
    head = newLink;
}

void* Stack::peek() {
    return head->Data;
}

void* Stack::pop() {
    if (head == 0) {
        return 0;
    }

    void* result = head->Data;
    link* oldHead = head;
    head = head->Next;
    free(oldHead);
    return result;
}


