#ifndef TESTTHREAD_H
#define TESTTHREAD_H
#include "CThread.h"
#include "MsgQueueBase.h"

class TestThreadA : public CThread
{
public:
    TestThreadA(const std::string pName);
    ~TestThreadA();

    virtual void mainLoop();

    void setMsgQueue(MsgQueueBase* p);

private:
    MsgQueueBase* p_Queue_Rev;
};

#endif // TESTTHREAD_H
