#include "Log_Func.h"

Log_Func::Log_Func(const char *tag, const char *func)
    : m_tag(tag)
    , m_func(func)
{
     LOGD("[%s]  -> [%s]", m_tag, m_func);
}

Log_Func::~Log_Func()
{
    LOGD("[%s]  <- [%s]", m_tag, m_func);
}
