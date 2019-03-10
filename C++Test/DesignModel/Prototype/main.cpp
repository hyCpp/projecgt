#include"ConcretePrototype.h"
#include"ProtoType.h"

int main()
{
    Prototype* pt = new ConcretePrototype();
    Prototype* pt1 = pt->Clone();
    Prototype* pt2 = pt1->Clone();

    pt->show();
    pt1->show();
    pt2->show();

    delete pt;
    delete pt1;
    delete pt2;
}
