#include "MsgQueueImpl.h"
#include <sys/syscall.h>
#include <pthread.h>
#include <unistd.h>
#include "Log_Func.h"

MsgQueueImpl::MsgQueueImpl(const std::string pName)
    :MsgQueueBase(pName)
{
    p_Mutex = OperatingSystemFactory::newMutex("Msg_Mutex");
    p_Sem = OperatingSystemFactory::newCountingSem(0);
}

MsgQueueImpl::~MsgQueueImpl()
{

}

bool MsgQueueImpl::recvMsg(unsigned int &code, void * &msg)
{
//    LOGD_FUNC();
    Elements elements;

    p_Sem->Wait();
    p_Mutex->Lock();

    if (m_Queue.empty()) {
        p_Mutex->UnLock();
        return false;
    }

    elements = m_Queue.front();
    m_Queue.pop();

    code = elements.msg_code;
    msg = elements.p_message;

    p_Mutex->UnLock();
    return true;
}

bool MsgQueueImpl::sendMsg(unsigned int code, void *msg)
{
//    LOGD_FUNC();
    Elements elements;

    p_Mutex->Lock();
    elements.msg_code = code;
    elements.p_message = msg;
    m_Queue.push(elements);

    p_Sem->Post();
    p_Mutex->UnLock();
    return true;
}


