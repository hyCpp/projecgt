#include "NGTestServiceStub.h"
#include "../../LogConfig/Log_Func.cpp"

#include <stdio.h>
#include <sstream>
#include<stdlib.h>
#include <queue>

int main()
{
    TC_Log::setLogStatus(true);
    NGTestServiceStub serviceStub;

    serviceStub.onInit();

    TCLOGD("--------Test--------");
    while (1);

}
