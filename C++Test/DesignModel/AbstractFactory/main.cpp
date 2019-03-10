#include"AbstractFactory.h"
#include"AbstractProductA.h"
#include"AbstractProductB.h"
#include"ConcreteFactory1.h"
#include"ConcreteFactory2.h"


int main()
{
    AbstractFactory* af1 = new ConcreteFactory1();
    AbstractFactory* af2 = new ConcreteFactory2();

    AbstractProductA* pa1 = af1->CreateProductA();
    AbstractProdcutB* pb1 = af1->CreateProductB();
    pa1->printName();
    pb1->printName();

    AbstractProductA* pa2 = af2->CreateProductA();
    AbstractProdcutB* pb2 = af2->CreateProductB();
    pa2->printName();
    pb2->printName();
}
