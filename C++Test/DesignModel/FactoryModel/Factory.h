#ifndef FACTORY_H
#define FACTORY_H
#include"Product.h"
#include"Const.h"

class Product;

class Factory
{
public:
    Factory();
    ~Factory();
    virtual Product* CreateProduct(Factory_key key) = 0;
};

#endif // FACTORY_H
