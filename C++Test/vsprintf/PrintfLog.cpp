#include"PrintfLog.h"
#include<stdio.h>
#include<cstdarg>
#include<stdarg.h>
#include<stdlib.h>

bool PrintLog::m_bLogStatus = false;
#define LOG_MAX_LENGTH 256

void PrintLog::outPut(char* formatstr, ...)
{
    if (m_bLogStatus) {
        char str[LOG_MAX_LENGTH];
        va_list vArgList;
        va_start (vArgList, formatstr);
        vsprintf(str, formatstr, vArgList);
        va_end(vArgList);
        printf("%s\n", str);
    }
}

bool PrintLog::getLogStatus()
{
    return m_bLogStatus;
}

void PrintLog::setLogStatus(bool bStatus)
{
    m_bLogStatus = bStatus;
}

PrintLog::PrintLog()
{
}


