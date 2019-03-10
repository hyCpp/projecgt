#include "Observer.h"
#include "Subject.h"
#include "ConcreteSubject.h"
#include "ConcreteObserver.h"
#include "ConcreteObserver1.h"
#include <stdio.h>
int main()
{
    Subject* sub = new ConcreteSubject();
    Observer* obs = new ConcreteObserver("Jack", sub);
    Observer* obs1 = new ConcreteObserver1("rose", sub);

    sub->Attach(obs);
    sub->Attach(obs1);

    sub->m_Action = "boss is not here";
    sub->Notify();

    sub->m_Action = "boss is coming";
    sub->Notify();
}
