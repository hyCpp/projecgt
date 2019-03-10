#ifndef CONCRETECLASSA_H
#define CONCRETECLASSA_H
#include "AbstractClass.h"

class ConcreteClassA : public AbstractClass
{
public:
    ConcreteClassA();
    ~ConcreteClassA();

    virtual void PrimitiveOper1();
    virtual void PrimitiveOper2();
};

#endif // CONCRETECLASSA_H
