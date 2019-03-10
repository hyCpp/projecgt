#include"ConcreteFactory2.h"
#include"ProductA2.h"
#include"ProductB2.h"

ConcreteFactory2::ConcreteFactory2()
{

}

ConcreteFactory2::~ConcreteFactory2()
{

}

AbstractProductA*  ConcreteFactory2::CreateProductA()
{
    return new ProductA2();
}

AbstractProdcutB*  ConcreteFactory2::CreateProductB()
{
    return new ProductB2();
}
