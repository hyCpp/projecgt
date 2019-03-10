#include "OperatingSystemImpl.h"
#include <stdio.h>
#include "OperatingSystemFactory.h"
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>
#include "Log_Func.h"
#include "boost/shared_ptr.hpp"

OperatingSystemImpl::OperatingSystemImpl()
    :OperatingSystemBase()
{
    m_ThreadId = 0;
}

OperatingSystemImpl::~OperatingSystemImpl()
{

}

void OperatingSystemImpl::entryThread(ThreadData *threadParm)
{
    LOGD_FUNC();
//    CThread *pThread = threadParm->thread;//(CThread*) threadParm[0];
//    CountingSemBase *pSem = threadParm->Sem;//(CountingSemBase*)threadParm[1];

    if (threadParm->thread != NULL) {
        threadParm->thread->ThreadEntry(threadParm->Sem);
    }
    else {
        printf("Thread Error...\n");
    }
    delete threadParm;
    threadParm = NULL;
    pthread_exit(0);
}

bool OperatingSystemImpl::createThread(CThread *mThread, unsigned long stack_size)
{
    LOGD_FUNC();
    unsigned long temp[2];
    int err;
    if (mThread == NULL) {
        printf("CLinuxOperatingSystem::CreateThread() : Thread pointer is NULL!  Can't begin the thread... ");
        return false;
    }

    p_thread = mThread;
    p_Sem = OperatingSystemFactory::newCountingSem(0);

    pthread_attr_init(&m_Thread_Attr);  //线程属性初始化
    pthread_attr_setschedpolicy(&m_Thread_Attr, SCHED_FIFO);
    pthread_attr_setscope(&m_Thread_Attr, PTHREAD_SCOPE_SYSTEM);
    pthread_attr_setstacksize(&m_Thread_Attr, stack_size);

    temp[0] = (unsigned long)p_thread;
    temp[1] = (unsigned long)p_Sem;
    ThreadData* threadData = new ThreadData;
    threadData->Sem = p_Sem;
    threadData->thread = p_thread;

    err = pthread_create(&m_ThreadId, &m_Thread_Attr, (void* (*)(void*))entryThread, threadData);

    if (err != 0) {
        printf("CLinuxOperatingSystem::CreateThread() : Failed to create and start the thread! ");
        p_thread = NULL;
        m_ThreadId = 0;
        return false;
    }

    pthread_detach(m_ThreadId);
    p_Sem->Wait();

    return true;
}

void OperatingSystemImpl::sleepSec(unsigned long sec)
{
    usleep(sec);
}
