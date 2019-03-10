#ifndef NGTESTTHREAD
#define NGTESTTHREAD
#include <string>
#include <stdio.h>

class NGTestServiceStub;

class NGTestThread
{
public:
    NGTestThread();
    ~ NGTestThread();

    void static entryThread(NGTestServiceStub* pSem);
    bool createThread(NGTestServiceStub* stub, unsigned long stack_size = 8 * 1024);

private:
    pthread_t m_thread;
    pthread_attr_t m_threadAttr;
};

#endif // NGTESTTHREAD

