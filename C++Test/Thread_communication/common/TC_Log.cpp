#include "TC_Log.h"
#include <stdio.h>
#include <cstdarg>
#include <stdarg.h>
#include <stdlib.h>

bool TC_Log::m_bLogStatus = false;

TC_Log::TC_Log()
{

}

TC_Log::~TC_Log()
{

}

void TC_Log::output(char* formatStr, ...)
{
    if (m_bLogStatus) {
        char str[LOG_MAX_LENGTH];
        va_list vArgList;
        va_start (vArgList, formatStr);
        vsprintf(str, formatStr, vArgList);
        va_end(vArgList);
        printf("%s\n", str);
    }
}

void TC_Log::setLogStatus(bool status)
{
    m_bLogStatus = status;
}

bool TC_Log::getLogStatus()
{
    return m_bLogStatus;
}
