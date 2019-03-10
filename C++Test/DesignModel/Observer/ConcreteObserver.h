#ifndef CONCRETEOBSERVER_H
#define CONCRETEOBSERVER_H
#include "Observer.h"
#include "Subject.h"

class ConcreteObserver : public Observer
{
public:
    ConcreteObserver(std::string name, Subject* pSub);
    ~ConcreteObserver();

    virtual void Update();
};

#endif // CONCRETEOBSERVER_H
