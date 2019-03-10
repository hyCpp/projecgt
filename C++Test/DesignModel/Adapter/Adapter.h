#ifndef ADAPTER_H
#define ADAPTER_H
#include"Target.h"
#include"Adaptee.h"

class Adapter : public Target
{
public:
    Adapter(Adaptee* pAdaptee);
    Adapter();
    ~Adapter();

    void Request();

private:
    Adaptee* pAdaptee;
};
#endif // ADAPTER_H
