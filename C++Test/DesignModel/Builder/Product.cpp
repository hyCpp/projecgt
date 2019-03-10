#include"Product.h"

Product::Product()
{
}

Product::~Product()
{
}

void Product::AddPart(const string part)
{
    parts.push_back(part);
}

void Product::ShowPart()
{
    for(int i = 0; i < parts.size(); ++i) {
        std::cout<<parts[i]<<std::endl;
    }
}
