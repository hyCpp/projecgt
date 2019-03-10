#include"ConcreteAbstractionB.h"
#include"AbstractionImpl.h"

ConcreteAbstractionB::ConcreteAbstractionB()
{

}

ConcreteAbstractionB::~ConcreteAbstractionB()
{

}

void ConcreteAbstractionB::printName(AbstractionImpl *abs)
{
    abs->displayName();
}
