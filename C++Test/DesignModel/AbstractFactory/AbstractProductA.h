#ifndef ABSTRACTPRODUCTA_H
#define ABSTRACTPRODUCTA_H
#include<iostream>

using namespace std;

class AbstractProductA
{
public:
    AbstractProductA();
    ~AbstractProductA();

    virtual void printName() = 0;
};

#endif // ABSTRACTPRODUCTA_H
