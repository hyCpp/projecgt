#include "MutexBase.h"

MutexBase::MutexBase(const std::string pName)
{
    if (pName.compare("") != 0) {
        m_Mutex_Name = pName;
    }
}

MutexBase::~MutexBase()
{

}

std::string MutexBase::getName()
{
    return m_Mutex_Name;
}
