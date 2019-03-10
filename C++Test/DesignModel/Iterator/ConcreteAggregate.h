#ifndef CONCRETEAGGREGATE_H
#define CONCRETEAGGREGATE_H
#include "Aggregate.h"
#include "Iterator.h"

class ConcreteAggregate : public Aggregate
{
public:
    ConcreteAggregate();
    ~ConcreteAggregate();

    Iterator* CreateIterator();
    int Count();
    void Push(const std::string &strValue);
    std::string Pop(const int nIndex);

private:
    std::vector<std::string> m_VecItems;
    Iterator* p_Iter;
};

#endif // CONCRETEAGGREGATE_H
