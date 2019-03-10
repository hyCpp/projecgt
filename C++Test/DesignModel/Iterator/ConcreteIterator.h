#ifndef CONCRETEITERATOR_H
#define CONCRETEITERATOR_H
#include "Iterator.h"
#include "Aggregate.h"

class ConcreteIterator : public Iterator
{
public:
    ConcreteIterator(Aggregate* pAggregate);
    ~ConcreteIterator();

    std::string First();
    std::string Next();
    std::string GetValue();
    bool IsEnd();

private:
    Aggregate* p_Aggregate;
    int m_nCurrent;
};

#endif // CONCRETEITERATOR_H
