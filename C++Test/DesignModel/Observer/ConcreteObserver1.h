#ifndef CONCRETEOBSERVER1_H
#define CONCRETEOBSERVER1_H
#include "Subject.h"

class ConcreteObserver1 : public Observer
{
public:
    ConcreteObserver1(std::string name, Subject* pSubject);
    ~ConcreteObserver1();

    virtual void Update();
};
#endif // CONCRETEOBSERVER1_H
