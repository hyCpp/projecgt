#ifndef PRODUCT_H
#define PRODUCT_H
#include<vector>
#include<string>
#include<iostream>

using namespace std;

class Product
{
public:
    Product();
    ~Product();
    void AddPart(const string part);
    void ShowPart();

private:
    vector<string> parts;
};


#endif // PRODUCT_H
