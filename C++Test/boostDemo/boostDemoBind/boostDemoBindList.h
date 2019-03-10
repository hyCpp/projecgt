#ifndef BOOSTDEMOBINDLIST_H
#define BOOSTDEMOBINDLIST_H
#include "boostBindDemoDefind.h"

using namespace boostDemo;

class boostDemoBindList
{
public:
    boostDemoBindList();
    ~boostDemoBindList();

    void setBoostDemoFunc(boostDemo_printFunc func);
    const boostDemo_printFunc getBoostDemoFunc() const;

    void printfLSomething();

private:
     boostDemo_printFunc m_boostDemoFunc;
};

#endif // BOOSTDEMOBINDLIST_H
