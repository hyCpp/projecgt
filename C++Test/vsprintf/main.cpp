#include "PrintfLog.h"
#include "Log.h"

int main()
{
    int num = 199;
    float fnum = 129.3;
    char str[4] = "abc";
    PrintLog::setLogStatus(true);
    LOGD("%d %f %s", num, fnum, str);
    LOGD_FUNC();
}

