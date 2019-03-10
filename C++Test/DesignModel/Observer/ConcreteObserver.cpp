#include "ConcreteObserver.h"
#include <stdio.h>
#include "Subject.h"

ConcreteObserver::ConcreteObserver(std::string name, Subject *pSub)
    : Observer(name, pSub)
{

}

ConcreteObserver::~ConcreteObserver()
{

}

void ConcreteObserver::Update()
{
    printf("Hi, %s %s\n", m_Name.c_str(),p_Sub->m_Action.c_str());
}
