#include "TestThreadB.h"
#include <stdio.h>
#include <sys/syscall.h>
#include <pthread.h>
#include <unistd.h>
#include "Log_Func.h"

TestThreadB::TestThreadB(const std::string pName)
    :CThread(pName)
{

}

TestThreadB::~TestThreadB()
{

}

void TestThreadB::mainLoop()
{
    LOGD_FUNC();
    unsigned int code = 0;
    char  *p_msg="hello Thread A";
    while(1)
    {
        LOGD("%s is Running....send data to message queue... code = [%d]\n",m_Thread_Name.c_str(), code);
        p_Queue_Send->sendMsg(code, (void*)p_msg);
        code++;
        this->p_Operating_System->sleepSec(500000);
    }
}

void TestThreadB::setMsgQueue(MsgQueueBase *p)
{
    p_Queue_Send = p;
}

