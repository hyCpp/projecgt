#ifndef TESTTHREADB_H
#define TESTTHREADB_H
#include "CThread.h"
#include "MsgQueueBase.h"

class TestThreadB : public CThread
{
public:
    TestThreadB(const std::string pName);
    ~TestThreadB();

    virtual void mainLoop();

    void setMsgQueue(MsgQueueBase* p);

private:
    MsgQueueBase* p_Queue_Send;
};
#endif // TESTTHREADB_H
