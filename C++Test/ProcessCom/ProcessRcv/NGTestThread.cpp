#include "NGTestThread.h"
#include <pthread.h>
#include "../../LogConfig/Log_Func.h"
#include "NGTestServiceStub.h"

NGTestThread::NGTestThread()
    : m_thread(0)
{

}

NGTestThread::~NGTestThread()
{
}

bool NGTestThread::createThread(NGTestServiceStub* stub, unsigned long stack_size)
{
    LOGD_FUNC();

    if (stub == nullptr) {
        TCLOGD("NGTestServiceStub ptr is null!");
        return false;
    }

    int err;
    pthread_attr_init(&m_threadAttr);
    pthread_attr_setschedpolicy(&m_threadAttr, SCHED_FIFO);
    pthread_attr_setscope(&m_threadAttr, PTHREAD_SCOPE_SYSTEM);
    pthread_attr_setstacksize(&m_threadAttr, stack_size);


    err = pthread_create(&m_thread, &m_threadAttr, (void* (*)(void*))entryThread, stub);

    if (err != 0) {
        TCLOGD("Failed to create and start the thread! ");
        m_thread = 0;
        return false;
    }

    pthread_detach(m_thread);

    return true;
}

void NGTestThread::entryThread(NGTestServiceStub* stub)
{
    LOGD_FUNC();
    stub->receiveMsg();
    pthread_exit(0);
}
