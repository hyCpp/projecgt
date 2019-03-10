#ifndef CONCRETEBUILDER1_H
#define CONCRETEBUILDER1_H
#include"Builder.h"

class ConcreteBuilder1 : public Builder
{
private:
    Product product;

public:
    ConcreteBuilder1();
    ~ConcreteBuilder1();

    virtual void BuilderHead();
    virtual void BuilderBody();
    virtual void BuilderHand();
    virtual void BuilderFeet();

    virtual Product GetPerson();
};
#endif // CONCRETEBUILDER1_H
