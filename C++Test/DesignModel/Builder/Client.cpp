#include"ConcreteBuilder.h"
#include"Product.h"
#include"Director.h"

int main()
{
    Director* dir = new Director();
    Builder* builder = new ConcreteBuilder();
//    builder->BuilderBody();
//    builder->BuilderFeet();
//    builder->BuilderHand();
    dir->Construct(builder);
    Product Pro = builder->GetPerson();
    Pro.ShowPart();
}
