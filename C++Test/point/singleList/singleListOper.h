#ifndef SINGLELISTOPER_H
#define SINGLELISTOPER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

struct student {
    char name[100];
    int score;
    struct student *next;
};

class singleListOper
{
public:
    singleListOper();
    ~singleListOper();

    void insertFunc(void);
    void sortFunc(void);
    void deleteFunc(void);
    void displayFunc(void);
    void modifyFunc(void);
    void anyKeyFunc(void);

    student *sp_Ptr;
    student *sp_Head;
    student *sp_Current;
    student *sp_Prev;
};

#endif // SINGLELISTOPER_H
