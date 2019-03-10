#include "Log.h"
#include "PrintfLog.h"

Log::Log(const char *tag, const char *func)
    : m_tag(tag)
    , m_func(func)
{
     LOGD("[%s]  -> [%s]", m_tag, m_func);
}

Log::~Log()
{
    LOGD("[%s]  <- [%s]", m_tag, m_func);
}
