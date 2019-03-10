#ifndef COUNTINGSEMIMPL_H
#define COUNTINGSEMIMPL_H
#include "CountingSemBase.h"
#include <semaphore.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <pthread.h>

class CountingSemImpl : public CountingSemBase
{
public:
    CountingSemImpl(unsigned int init_sem_count);
    ~CountingSemImpl();

    virtual bool Wait(Mode mode, unsigned long timeout);
    virtual bool Post(void);

private:
    sem_t m_sem;
};

#endif // COUNTINGSEMIMPL_H
