#include "ConcreteObserver1.h"
#include <stdio.h>

ConcreteObserver1::ConcreteObserver1(std::string name, Subject *pSub)
    : Observer(name, pSub)
{

}

ConcreteObserver1::~ConcreteObserver1()
{

}

void ConcreteObserver1::Update()
{
#ifdef DEBUG
    printf("Hi, %s %s\n", m_Name.c_str(),p_Sub->m_Action.c_str());
#endif
}

