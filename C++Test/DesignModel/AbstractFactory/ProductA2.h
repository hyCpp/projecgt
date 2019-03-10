#ifndef CONCRETEPRODUCTA2_H
#define CONCRETEPRODUCTA2_H
#include"AbstractProductA.h"

class ProductA2 : public AbstractProductA
{
public:
    ProductA2();
    ~ProductA2();

    void printName();
};
#endif // CONCRETEPRODUCTA2_H
