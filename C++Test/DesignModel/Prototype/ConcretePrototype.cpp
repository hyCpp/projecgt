#include"ConcretePrototype.h"

ConcretePrototype::ConcretePrototype()
{
    std::cout<<"ConcretePrototype Construction..."<<std::endl;
}

ConcretePrototype::~ConcretePrototype()
{
    std:: cout<<"Destory ConcretePrototype..."<<std::endl;
}

ConcretePrototype::ConcretePrototype(const ConcretePrototype &cp)
{
    std::cout<<"copy ConcretePrototype..."<<std::endl;
    this->id = cp.id;
    this->id ++;
}

ConcretePrototype* ConcretePrototype::Clone()
{
    ConcretePrototype* cpt = new ConcretePrototype(*this);
    return cpt;
}

void ConcretePrototype::show()
{
    std::cout<<"id = "<<id<<std::endl;
}
