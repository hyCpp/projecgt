#ifndef MSGQUEUEIMPL_H
#define MSGQUEUEIMPL_H
#include "MsgQueueBase.h"
#include <queue>
#include "MutexBase.h"
#include "CountingSemBase.h"
#include "OperatingSystemFactory.h"

class MsgQueueImpl : public MsgQueueBase
{
public:
    MsgQueueImpl(const std::string pName = NULL);
    ~MsgQueueImpl();

    virtual bool recvMsg(unsigned int &code, void * &msg);
    virtual bool sendMsg(unsigned int code, void *msg);

private:
    std::queue<Elements> m_Queue;
    MutexBase* p_Mutex;
    CountingSemBase* p_Sem;
};

#endif // MSGQUEUEIMPL_H
