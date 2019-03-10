#ifndef CONCRETECLASSB_H
#define CONCRETECLASSB_H
#include "AbstractClass.h"

class ConcreteClassB : public AbstractClass
{
public:
    ConcreteClassB();
    ~ConcreteClassB();

    virtual void PrimitiveOper1();
    virtual void PrimitiveOper2();
};
#endif // CONCRETECLASSB_H
