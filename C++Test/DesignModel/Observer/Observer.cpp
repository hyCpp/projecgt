#include "Observer.h"
#include "Subject.h"
#include <stdio.h>
Observer::Observer(string name, Subject *pSub)
{
    this->m_Name = name;
    this->p_Sub = pSub;
}

Observer::~Observer()
{

}
