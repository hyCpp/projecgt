#include"ConcreteAbstractionA.h"
#include"ConcreteAbstractionB.h"
#include"ConcreteAbstractionImplA.h"
#include"ConcreteAbstractionImplB.h"
int main()
{
    AbstractionImpl *abs = new ConcreteAbstractionImplA();
    AbstractionImpl *abs1= new ConcreteAbstractionImplB();

    Abstraction *a = new ConcreteAbstractionA();
    a->printName(abs);
    a->printName(abs1);

    Abstraction *b = new ConcreteAbstractionB();
    b->printName(abs);
    b->printName(abs1);
}
