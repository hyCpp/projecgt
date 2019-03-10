#include"Product.h"
#include"Factory.h"
#include"ConcreteFactory.h"
#include"ConcreteProduct1.h"

int main()
{
    Factory *f = new ConcreteFactory();
    Product *p = f->CreateProduct(KEY_PRODUCT_TWO);
    p->printName();
}
