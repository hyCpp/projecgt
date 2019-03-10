#include"Singleton.h"

Singleton* Singleton::m_instance = NULL;

Singleton::Singleton()
{
    std::cout<<"This is Singleton"<<std::endl;
}

Singleton* Singleton::Instance()
{
    if(m_instance == NULL)
    {
        m_instance = new Singleton();
    }
    return m_instance;
}
