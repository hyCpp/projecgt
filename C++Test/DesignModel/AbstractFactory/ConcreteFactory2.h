#ifndef CONCRETEFACTORY2_H
#define CONCRETEFACTORY2_H
#include"AbstractFactory.h"

class ConcreteFactory2 : public AbstractFactory
{
public:
    ConcreteFactory2();
    ~ConcreteFactory2();

    AbstractProductA* CreateProductA();
    AbstractProdcutB* CreateProductB();
};

#endif // CONCRETEFACTORY2_H
