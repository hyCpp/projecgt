#ifndef LOG_FUNC_H
#define LOG_FUNC_H
#include "TC_Log.h"

#define FC_LOG_TAG "Thread_Communication"
#define LOGD(type, ...) {TC_Log p; p.output(type, __VA_ARGS__);}
#define LOG_DEBUG_FUNC_INOUT(tag)  Log_Func log((tag), (__PRETTY_FUNCTION__))
#define LOGD_FUNC() LOG_DEBUG_FUNC_INOUT(FC_LOG_TAG)
#define TCLOGD(...) {LOGD(__VA_ARGS__, "")}

class Log_Func{
public:
    Log_Func(const char* tag, const char* func);
    ~Log_Func();

private:
    Log_Func(const Log_Func& a);
    Log_Func& operator = (const Log_Func& a);

    const char* m_tag;
    const char* m_func;
};

#endif // LOG_FUNC_H
