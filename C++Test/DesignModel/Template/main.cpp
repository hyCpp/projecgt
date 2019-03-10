#include "AbstractClass.h"
#include "ConcreteClassA.h"
#include "ConcreteClassB.h"

int main()
{
    AbstractClass* abs = new ConcreteClassA();
    abs->TemplateFunc();

    AbstractClass* abs1 = new ConcreteClassB;
    abs1->TemplateFunc();
}
