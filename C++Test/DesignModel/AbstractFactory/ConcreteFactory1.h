#ifndef CONCRETEFACTORY1_H
#define CONCRETEFACTORY1_H
#include"AbstractFactory.h"

class ConcreteFactory1 : public AbstractFactory
{
public:
    ConcreteFactory1();
    ~ConcreteFactory1();

    AbstractProductA* CreateProductA();
    AbstractProdcutB* CreateProductB();
};

#endif // CONCRETEFACTORY1_H
