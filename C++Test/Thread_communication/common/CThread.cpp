#include "CThread.h"
#include "OperatingSystemFactory.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <pthread.h>
#include <unistd.h>
#include "Log_Func.h"

CThread::CThread(const std::string pName)
{
    m_Thread_Name = pName;
    p_Operating_System = OperatingSystemFactory::newOperatingSystem();

    if (p_Operating_System == NULL)
    {
        printf("OS Create Fail ... \n");
        return;
    }
}

CThread::~CThread()
{

}

void CThread::ThreadEntry(CountingSemBase *pSem)
{
    LOGD_FUNC();
    bool res;
    res = initializeThread();
    if (res) {
        pSem->Post();
        mainLoop();
    }
}

bool CThread::run()
{
    LOGD_FUNC();
    LOGD("Thread Name is  [%s]", m_Thread_Name.c_str());
    if (!p_Operating_System->createThread(this)) {
        printf("Create Thread Fail...\n");
        return false;
    }
}

bool CThread::initializeThread()
{
    return true;
}
