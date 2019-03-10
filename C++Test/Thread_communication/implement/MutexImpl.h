#ifndef MUTEXIMPL_H
#define MUTEXIMPL_H
#include "MutexBase.h"
#include <sys/time.h>
#include <pthread.h>
#include <errno.h>

class MutexImpl : public MutexBase
{
public:
    MutexImpl(const std::string pName = NULL);
    ~MutexImpl();

    virtual bool Lock();
    virtual bool UnLock();

private:
    pthread_t m_Thread;
    pthread_mutex_t m_Mutex;
    pthread_mutexattr_t m_Mutex_Attr;
};

#endif // MUTEXIMPL_H
