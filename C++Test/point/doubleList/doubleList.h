#ifndef DOUBLELIST_H
#define DOUBLELIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

struct student {
    char name[20];
    int score;
    student *Left;
    student *right;
};

class doubleList
{
public:
    doubleList();
    ~doubleList();

    void initialize();
    void insertFunc();
    void deleteFunc();
    void displayFunc();
    void modifyFunc();

private:
    student *ptr;
    student *prev;
    student *current;
    student *head;
    student *tail;
};

#endif // DOUBLELIST_H
