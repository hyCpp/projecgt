#ifndef NESTED_H
#define NESTED_H
struct stack {
    struct link {
        void* Data;
        link* Next;
        void initialize(void* data, link* next);
    } * head;

    void initialize();
    void push(void* data);
    void* peek();
    void* pop();
    void cleanUp();
};

#endif // NESTED_H
