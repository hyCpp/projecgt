#include"ConcreteProduct2.h"
ConcreteProduct2* ConcreteProduct2::pConcreteProduct2 =NULL;

ConcreteProduct2::ConcreteProduct2()
{

}

ConcreteProduct2::~ConcreteProduct2()
{

}

void ConcreteProduct2::printName()
{
    std::cout<<"this is ConcreteProduct2"<<std::endl;
}

ConcreteProduct2* ConcreteProduct2::GetInstance()
{
    if (pConcreteProduct2 == NULL) {
        pConcreteProduct2 = new ConcreteProduct2;
    }
    return pConcreteProduct2;
}
