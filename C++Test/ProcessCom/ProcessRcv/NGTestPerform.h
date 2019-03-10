#ifndef NGTESTPERFORM
#define NGTESTPERFORM
#include <string>
#include <stdio.h>

class NGTestServiceStub;

class NGTestPerform
{
public:
    NGTestPerform();
    ~NGTestPerform();

    void static entryThread(NGTestServiceStub* pSem);
    bool createThread(NGTestServiceStub* stub, unsigned long stack_size = 8 * 1024);

private:
    pthread_t m_thread;
    pthread_attr_t m_threadAttr;
};

#endif // NGTESTPERFORM

