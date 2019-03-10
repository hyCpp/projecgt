#ifndef BUILER_H
#define BUILER_H
#include"Product.h"

class Builder
{
public:
    virtual void BuilderHead() = 0;
    virtual void BuilderBody() = 0;
    virtual void BuilderHand() = 0;
    virtual void BuilderFeet() = 0;
    virtual Product GetPerson() = 0;
};

#endif // BUILER_H
