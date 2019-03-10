#include"Director.h"

Director::Director()
{

}

Director::~Director()
{

}

void Director::Construct(Builder *builder)
{
    builder->BuilderHead();
    builder->BuilderBody();
    builder->BuilderHand();
    builder->BuilderFeet();
}
