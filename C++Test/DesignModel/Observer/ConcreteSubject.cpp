#include "ConcreteSubject.h"
#include <stdio.h>
#include <string>
ConcreteSubject::ConcreteSubject()
{
}

ConcreteSubject::~ConcreteSubject()
{

}

void ConcreteSubject::Attach(Observer *pObserver)
{
    m_ObsList.push_back(pObserver);
}

void ConcreteSubject::Detach(Observer *pObserver)
{
    vector<Observer*>::iterator it;

    for (it = m_ObsList.begin(); it != m_ObsList.end(); ++it) {
        if ( pObserver == (*it)) {
            m_ObsList.erase(it);
        }
    }
}

void ConcreteSubject::Notify()
{
    vector<Observer*>::iterator it;

    for (it = m_ObsList.begin(); it != m_ObsList.end(); ++it) {
        (*it)->Update();
    }
}
