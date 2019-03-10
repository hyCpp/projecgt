#ifndef AGGREGATE_H
#define AGGREGATE_H
#include <string>
#include <stdio.h>
#include "Iterator.h"

class Aggregate
{
public:
    Aggregate();
    ~Aggregate();

    virtual int Count() = 0;
    virtual void Push(const std::string& strValue) = 0;
    virtual std::string Pop(const int nIndex) = 0;
    virtual Iterator* CreateIterator() =0;

};

#endif // AGGERGATE_H
