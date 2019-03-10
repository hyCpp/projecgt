#include "ConcreteAggregate.h"
#include "ConcreteIterator.h"

ConcreteAggregate::ConcreteAggregate()
{
    m_VecItems.clear();
}

ConcreteAggregate::~ConcreteAggregate()
{
    if (NULL != p_Iter) {
        delete p_Iter;
        p_Iter = NULL;
    }
}

Iterator* ConcreteAggregate::CreateIterator()
{
    if (NULL == p_Iter) {
        p_Iter = new ConcreteIterator(this);
    }
    return p_Iter;
}

int ConcreteAggregate::Count()
{
    return m_VecItems.size();
}

void ConcreteAggregate::Push(const std::string &strValue)
{
    m_VecItems.push_back(strValue);
}

std::string ConcreteAggregate::Pop(const int nIndex)
{
    std::string strRet;

    if (nIndex < Count()) {
        strRet = m_VecItems[nIndex];
    }
    return strRet;
}
