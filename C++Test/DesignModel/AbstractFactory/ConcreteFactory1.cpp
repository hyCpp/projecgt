#include"ConcreteFactory1.h"
#include"ProductA1.h"
#include"ProductB1.h"

ConcreteFactory1::ConcreteFactory1()
{

}

ConcreteFactory1::~ConcreteFactory1()
{

}

AbstractProductA* ConcreteFactory1::CreateProductA()
{
    return new ProductA1();
}

AbstractProdcutB* ConcreteFactory1::CreateProductB()
{
    return new ProductB1();
}
