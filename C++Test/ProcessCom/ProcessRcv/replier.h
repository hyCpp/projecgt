#ifndef REPLIER
#define REPLIER
#include <string>
#include "../../LogConfig/Log_Func.h"

class replier
{
public:
    replier()
    {

    }

    ~replier()
    {

    }

    void recv(const std::string& msg)
    {
        LOGD_FUNC();
        LOGD("msg is [%s]\n", msg.c_str());
    }
};

#endif // REPLIER

