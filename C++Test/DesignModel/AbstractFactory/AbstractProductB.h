#ifndef ABSTRACTPRODUCTB_H
#define ABSTRACTPRODUCTB_H
#include<iostream>

using namespace std;

class AbstractProdcutB
{
public:
    AbstractProdcutB();
    ~AbstractProdcutB();

    virtual void printName() = 0;
};

#endif // ABSTRACTFACTORYB_H
