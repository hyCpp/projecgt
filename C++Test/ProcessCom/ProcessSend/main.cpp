#include "NGTestService.h"
#include "../../LogConfig/Log_Func.cpp"

int main()
{
    TC_Log::setLogStatus(true);
    NGTestService service;
    service.onInit();
    service.sendMsg();
}
