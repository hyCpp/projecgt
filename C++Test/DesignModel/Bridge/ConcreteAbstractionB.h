#ifndef CONCRETEABSTRACTIONB_H
#define CONCRETEABSTRACTIONB_H
#include"Abstraction.h"

class ConcreteAbstractionB : public Abstraction
{
public:
    ConcreteAbstractionB();
    ~ConcreteAbstractionB();

    void printName(AbstractionImpl* abs);
};
#endif // CONCRETEABSTRACTIONB_H
