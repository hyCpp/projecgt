#ifndef CONCRETEPRODUCTA1_H
#define CONCRETEPRODUCTA1_H
#include"AbstractProductA.h"

class ProductA1 : public AbstractProductA
{
public:
    ProductA1();
    ~ProductA1();

    void printName();
};

#endif // CONCRETEPRODUCTA1_H
