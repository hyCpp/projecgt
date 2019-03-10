#ifndef CTHREAD
#define CTHREAD
#include"MyThread.h"
#include <pthread.h>
#include <stdio.h>
class MyThread;

struct ThreadData
{
    MyThread* thread;
};

class CThread
{
public:
    CThread();
    ~CThread();

    virtual bool createThread(MyThread *mThread, unsigned long stack_size=8*1024);
    virtual void sleepSec(unsigned long sec);
    static void entryThread(ThreadData *threadParm);
    void Notify();
    void Wait();
private:
    pthread_t m_ThreadId;
    pthread_attr_t m_Thread_Attr;
    pthread_cond_t m_cond;
    pthread_mutex_t m_mutex;
    pthread_mutexattr_t m_attr;
};


#endif // CTHREAD

