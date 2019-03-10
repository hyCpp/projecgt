#include "MutexImpl.h"
#include <stdio.h>

MutexImpl::MutexImpl(const std::string pName)
    :MutexBase(pName)
{
    m_Thread = (pthread_t)0;
    pthread_mutexattr_init(&m_Mutex_Attr);

    if (pthread_mutexattr_settype(&m_Mutex_Attr, PTHREAD_MUTEX_ERRORCHECK_NP)) //mutex init
    {
        printf("CLinuxMutex::CnlLinuxMutex() : Failed to set mutex attibutes\n");
    }
    pthread_mutex_init(&m_Mutex, &m_Mutex_Attr);
}

MutexImpl::~MutexImpl()
{

}

bool MutexImpl::Lock()
{
    bool lock = false;

    int result = pthread_mutex_lock(&m_Mutex);
    switch (result) {
    case 0:
        m_Thread = pthread_self(); //get thread self id
        lock = true;
        break;
    case EDEADLK:
        lock = true;
    default:
        break;
    }
    return lock;
}

bool MutexImpl::UnLock()
{
    bool unLock = true;
    int result;

    if (pthread_self() != m_Thread) {
        unLock = false;
        printf("CnlLinuxMutex::Unlock() :  Error - Mutex not locked or not owned by the thread! \n");
    }
    else {
        result = pthread_mutex_unlock(&m_Mutex);
        if (result < 0) {
            unLock = false;
        }
    }

    return unLock;
}


