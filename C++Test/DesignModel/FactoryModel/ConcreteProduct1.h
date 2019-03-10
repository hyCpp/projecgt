#ifndef CONCRETEPRODUCT1_H
#define CONCRETEPRODUCT1_H
#include"Product.h"

class ConcreteProduct1 : public Product
{
public:
    ConcreteProduct1();
    ~ConcreteProduct1();

    void printName();
    static ConcreteProduct1* GetInstance();

private:
    static ConcreteProduct1* pConcreteProduct1;
};
#endif // CONCRETEPRODUCT1_H
