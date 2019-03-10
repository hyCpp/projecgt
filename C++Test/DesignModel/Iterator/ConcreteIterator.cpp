#include "ConcreteIterator.h"

ConcreteIterator::ConcreteIterator(Aggregate *pAggregate)
    : m_nCurrent(0)
    , p_Aggregate(pAggregate)
{

}

ConcreteIterator::~ConcreteIterator()
{

}

std::string ConcreteIterator::First()
{
    return p_Aggregate->Pop(0);
}

std::string ConcreteIterator::GetValue()
{
    return p_Aggregate->Pop(m_nCurrent);
}

std::string ConcreteIterator::Next()
{
    std::string strRet;
    m_nCurrent++;
    if (m_nCurrent < p_Aggregate->Count()) {
        strRet = p_Aggregate->Pop(m_nCurrent);
    }
    return strRet;
}

bool ConcreteIterator::IsEnd()
{
    bool is = m_nCurrent >= p_Aggregate->Count() ? true : false;
    return is;
}
