#ifndef SIMPLE
#define SIMPLE
#include<iostream>
#include<string>
#include "../../LogConfig/Log_Func.h"

using namespace std;

class Simple {
    public:
    Simple(int param = 0) {
        number = param;
        LOGD("construct Simple : %d", number);
    }

    ~Simple() {
        LOGD("destory Simple : %d", number);
    }

    void PrintSomething() {
        LOGD("PrintSomething : %s", info_extend.c_str());
    }

    std::string info_extend;
    int number;
};
#endif // SIMPLE

