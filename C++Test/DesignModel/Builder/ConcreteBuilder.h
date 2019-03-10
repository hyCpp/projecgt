#ifndef CONCRETEBUILDER_H
#define CONCRETEBUILDER_H
#include"Builder.h"

class ConcreteBuilder : public Builder
{
private:
    Product product;

public:
    ConcreteBuilder();
    ~ConcreteBuilder();

    virtual void BuilderHead();
    virtual void BuilderBody();
    virtual void BuilderHand();
    virtual void BuilderFeet();

    virtual Product GetPerson();
};

#endif // CONCRETEBUILDER_H
