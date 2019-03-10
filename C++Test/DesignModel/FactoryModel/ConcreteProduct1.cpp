#include"ConcreteProduct1.h"
#include"Product.h"

ConcreteProduct1* ConcreteProduct1::pConcreteProduct1 = NULL;

ConcreteProduct1::ConcreteProduct1()
{

}

ConcreteProduct1::~ConcreteProduct1()
{

}

void ConcreteProduct1::printName()
{
    std::cout<<"this is ConcreteProduct1"<<std::endl;
}

ConcreteProduct1* ConcreteProduct1::GetInstance()
{
    if (pConcreteProduct1 == NULL) {
        pConcreteProduct1 = new ConcreteProduct1;
    }
    return pConcreteProduct1;
}
