#ifndef ITERATOR_H
#define ITERATOR_H
#include <stdio.h>
#include <string>
#include <vector>

class Iterator
{
public:
    Iterator();
    ~Iterator();

    virtual std::string First() = 0;
    virtual std::string Next() = 0;
    virtual std::string GetValue() =0;
    virtual bool IsEnd() = 0;
};

#endif // ITERATOR_H
