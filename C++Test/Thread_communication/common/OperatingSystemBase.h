#ifndef OPERATINGSYSTEMBASE_H
#define OPERATINGSYSTEMBASE_H
#include "CThread.h"

class CThread;

class OperatingSystemBase
{
public:
    OperatingSystemBase();
    ~OperatingSystemBase();

    virtual bool createThread(CThread *mThread, unsigned long stack_size = 8 * 1024) = 0;
    virtual void sleepSec(unsigned long sec) = 0;

protected:
    CThread *p_thread;
};

#endif // OPERATINGSYSTEMBASE_H
