#ifndef CTHREAD_H
#define CTHREAD_H
#include "string"
#include "CountingSemBase.h"
#include "OperatingSystemBase.h"
class OperatingSystemBase;
class CThread
{
public:
    CThread(const std::string pName);
    ~CThread();

    void ThreadEntry(CountingSemBase *pSem);

    bool run();

public:
    virtual bool initializeThread();
    virtual void mainLoop() = 0;

    OperatingSystemBase *p_Operating_System;
    std::string m_Thread_Name;
};

#endif // CTHREAD_H
