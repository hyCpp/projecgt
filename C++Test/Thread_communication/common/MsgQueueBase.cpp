#include "MsgQueueBase.h"

MsgQueueBase::MsgQueueBase(const std::string pName)
{
    if (pName.compare("") != 0) {
        m_Queue_Name = pName;
    }
}

MsgQueueBase::~MsgQueueBase()
{

}

std::string MsgQueueBase::getName()
{
    return m_Queue_Name;
}
