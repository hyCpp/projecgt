#ifndef LOG_H
#define LOG_H
#define FC_LOG_TAG "Test"
#define LOGD(type, ...) {PrintLog p; p.outPut(type, __VA_ARGS__);}
#define LOG_DEBUG_FUNC_INOUT(tag)  Log log((tag), (__PRETTY_FUNCTION__))
#define LOGD_FUNC() LOG_DEBUG_FUNC_INOUT(FC_LOG_TAG)

class Log{
public:
    Log(const char* tag, const char* func);
    ~Log();

private:
    Log(const Log& a);
    Log& operator = (const Log& a);

    const char* m_tag;
    const char* m_func;
};

#endif // LOG_H
