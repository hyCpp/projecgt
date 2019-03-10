#include"ConcreteBuilder.h"

ConcreteBuilder::ConcreteBuilder()
{

}

ConcreteBuilder::~ConcreteBuilder()
{

}

void ConcreteBuilder::BuilderHead()
{
    product.AddPart("fatHead");
}

void ConcreteBuilder::BuilderBody()
{
    product.AddPart("fatBody");
}

void ConcreteBuilder::BuilderHand()
{
    product.AddPart("fatHand");
}

void ConcreteBuilder::BuilderFeet()
{
    product.AddPart("fatFeet");
}

Product ConcreteBuilder::GetPerson()
{
    return product;
}
