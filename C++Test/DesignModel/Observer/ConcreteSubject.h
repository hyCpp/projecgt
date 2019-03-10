#ifndef CONCRETESUBJECT_H
#define CONCRETESUBJECT_H
#include "Subject.h"
#include "Observer.h"

class ConcreteSubject : public Subject
{
public:
    ConcreteSubject();
    ~ConcreteSubject();

    virtual void Attach(Observer *pObserver);
    virtual void Detach(Observer *pObserver);
    virtual void Notify();
};

#endif // CONCRETESUBJECT_H
