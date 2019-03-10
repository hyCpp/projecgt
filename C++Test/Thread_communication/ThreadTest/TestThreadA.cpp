#include "TestThreadA.h"
#include <stdio.h>
#include <sys/syscall.h>
#include <pthread.h>
#include <unistd.h>
#include "Log_Func.h"

TestThreadA::TestThreadA(const std::string pName)
    : CThread(pName)
{

}

TestThreadA::~TestThreadA()
{

}

void TestThreadA::mainLoop()
{
    LOGD_FUNC();
    unsigned int code = 0;
    void *p_msg;
    while(1)
    {
        p_Queue_Rev->recvMsg(code, p_msg);
//        this->p_Operating_System->sleepSec(100000);
//#if TEST_RECV
        LOGD("%s  is Running....recv data from message queue: code is : [%d]  data is : [%s] \n", m_Thread_Name.c_str(), code, (char *)p_msg);
//#endif
    }
}

void TestThreadA::setMsgQueue(MsgQueueBase *p)
{
    p_Queue_Rev = p;
}
