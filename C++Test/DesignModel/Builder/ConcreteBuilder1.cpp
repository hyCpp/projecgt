#include"ConcreteBuilder1.h"

ConcreteBuilder1::ConcreteBuilder1()
{

}

ConcreteBuilder1::~ConcreteBuilder1()
{

}

void ConcreteBuilder1::BuilderHead()
{
    product.AddPart("thinHead");
}

void ConcreteBuilder1::BuilderBody()
{
    product.AddPart("thinBody");
}

void ConcreteBuilder1::BuilderHand()
{
    product.AddPart("thinHand");
}

void ConcreteBuilder1::BuilderFeet()
{
    product.AddPart("thinFeet");
}

Product ConcreteBuilder1::GetPerson()
{
    return product;
}
