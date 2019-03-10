#include"ConcreteFactory.h"
#include<iostream>
#include"ConcreteProduct1.h"
#include"ConcreteProduct2.h"

using namespace std;

ConcreteFactory::ConcreteFactory()
{
    std::cout<<"this is concreteFactory()"<<std::endl;
}

ConcreteFactory::~ConcreteFactory()
{

}

Product* ConcreteFactory::CreateProduct(Factory_key key)
{
    switch(key){
    case KEY_PRODUCT_ONE:
        return ConcreteProduct1::GetInstance();
        break;
    case KEY_PRODUCT_TWO:
        return ConcreteProduct2::GetInstance();
        break;
    default:
        std::cout<<"This is null!"<<std::endl;
    }
}

