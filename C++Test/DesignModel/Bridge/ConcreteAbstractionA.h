#ifndef CONCRETEABSTRACTIONA_H
#define CONCRETEABSTRACTIONA_H
#include"Abstraction.h"

class ConcreteAbstractionA : public Abstraction
{
public:
    ConcreteAbstractionA();
    ~ConcreteAbstractionA();

    void printName(AbstractionImpl* abs);
};

#endif // CONCRETEABSTRACTIONA_H
