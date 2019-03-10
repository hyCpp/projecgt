#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H
#include"AbstractProductA.h"
#include"AbstractProductB.h"

class AbstractProductA;
class AbstractProdcutB;

class AbstractFactory
{
public:
    AbstractFactory();
    ~AbstractFactory();

    virtual AbstractProductA* CreateProductA() = 0;
    virtual AbstractProdcutB* CreateProductB() = 0;
};

#endif // ABSTRACTFACTORY_H
