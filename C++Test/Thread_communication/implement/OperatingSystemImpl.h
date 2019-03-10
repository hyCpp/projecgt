#ifndef OPERATINGSYSTEMIMPL_H
#define OPERATINGSYSTEMIMPL_H
#include "OperatingSystemBase.h"
struct ThreadData
{
    CThread* thread;
    CountingSemBase* Sem;
};

class OperatingSystemImpl : public OperatingSystemBase
{
public:
    OperatingSystemImpl();
    ~OperatingSystemImpl();

    virtual bool createThread(CThread *mThread,unsigned long stack_size=8*1024);
    virtual void sleepSec(unsigned long sec);
    static void entryThread(ThreadData *threadParm);

private:
    pthread_t m_ThreadId;
    pthread_attr_t m_Thread_Attr;
    CountingSemBase* p_Sem;
};

#endif // OPERATINGSYSTEMIMPL_H
