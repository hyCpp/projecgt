#ifndef PRODUCT_H
#define PRODUCT_H
#include<iostream>
using namespace std;

class Product
{
public:
    Product();
    ~Product();
    virtual void printName() = 0;
};
#endif // FACTORY_H
