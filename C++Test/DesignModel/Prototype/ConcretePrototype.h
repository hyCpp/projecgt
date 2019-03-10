#ifndef CONCRETEPROTOTYPE_H
#define CONCRETEPROTOTYPE_H
#include"ProtoType.h"
#include"iostream"

using namespace std;

class ConcretePrototype : public Prototype
{
public:
    ConcretePrototype();
    ConcretePrototype(const ConcretePrototype& cp);
    ~ConcretePrototype();

    ConcretePrototype* Clone();
    void show();
};

#endif // CONCRETEPROTOTYPE_H
