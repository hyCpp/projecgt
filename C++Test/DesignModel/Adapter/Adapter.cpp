#include"Adapter.h"

Adapter::Adapter(Adaptee* pAdaptee) : pAdaptee(pAdaptee)
{

}

Adapter::Adapter()
{

}

Adapter::~Adapter()
{
    delete pAdaptee;
    pAdaptee = NULL;
    std::cout<<"Destory pAdaptee..."<<std::endl;
}

void Adapter::Request(){
    std::cout<<"Request : ";
    pAdaptee->SpecificRequest(10);
}
