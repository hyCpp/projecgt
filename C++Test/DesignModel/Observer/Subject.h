#ifndef SUBJECT_H
#define SUBJECT_H
#include "Observer.h"
#include <vector>

using namespace std;

class Subject
{
public:
    Subject();
    ~Subject();

    virtual void Attach(Observer *pObserver) = 0;
    virtual void Detach(Observer *pObserver) = 0;
    virtual void Notify() = 0;

public:
    std::string m_Action;
    std::vector<Observer*> m_ObsList;
};

#endif // SUBJECT_H
