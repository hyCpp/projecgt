#ifndef CONCRETEFACTORY_H
#define CONCRETEFACTORY_H
#include"Factory.h"

class ConcreteFactory : public Factory
{
public:
    ConcreteFactory();
    ~ConcreteFactory();
    Product* CreateProduct(Factory_key key);
};

#endif // CONCRETEFACTORY_H
