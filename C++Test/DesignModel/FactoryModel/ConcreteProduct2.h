#ifndef CONCRETEPRODUCT2_H
#define CONCRETEPRODUCT2_H
#include"Product.h"

class ConcreteProduct2 : public Product
{
public:
    ConcreteProduct2();
    ~ConcreteProduct2();

    void printName();
    static ConcreteProduct2* GetInstance();

private:
    static ConcreteProduct2* pConcreteProduct2;
};
#endif // CONCRETEPRODUCT2_H
