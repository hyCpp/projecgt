#include "boostDemoBindList.h"
#include <stdio.h>
#include "../../LogConfig/Log_Func.h"

boostDemoBindList::~boostDemoBindList()
{
}

boostDemoBindList::boostDemoBindList()
{
}

const boostDemo_printFunc boostDemoBindList::getBoostDemoFunc() const
{
    return m_boostDemoFunc;
}

void boostDemoBindList::setBoostDemoFunc(boostDemo_printFunc func)
{
    m_boostDemoFunc = func;
}

void boostDemoBindList::printfLSomething()
{
    printf("This is boostDemoBindList\n");
    TCLOGD("This is boostDemoBindList");
}
