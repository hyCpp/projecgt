#ifndef ABSTRACTCLASS_H
#define ABSTRACTCLASS_H
#include <stdio.h>

class AbstractClass
{
public:
    AbstractClass();
    ~AbstractClass();

    void TemplateFunc();

    virtual void PrimitiveOper1() = 0;
    virtual void PrimitiveOper2() = 0;
};

#endif // ABSTRACTCLASS_H
