#ifndef TARGET_H
#define TARGET_H
#include"iostream"

using namespace std;

class Target
{
public:
    Target();
    ~Target();

    virtual void Request();
};

#endif // TARGET_H
