#ifndef ABSTRACTION_H
#define ABSTRACTION_H
#include"AbstractionImpl.h"

class Abstraction
{
public:
    virtual void printName(AbstractionImpl* abs) = 0;
};

#endif // ABSTRACTION_H
