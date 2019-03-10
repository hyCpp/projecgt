#include"ConcreteAbstractionA.h"

ConcreteAbstractionA::ConcreteAbstractionA()
{

}

ConcreteAbstractionA::~ConcreteAbstractionA()
{

}

void ConcreteAbstractionA::printName(AbstractionImpl *abs)
{
    abs->displayName();
}
