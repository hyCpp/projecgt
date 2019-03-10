#include "OperatingSystemFactory.h"
#include "CountingSemImpl.h"
#include "MsgQueueImpl.h"
#include "MutexImpl.h"
#include "OperatingSystemImpl.h"

CountingSemBase* OperatingSystemFactory::newCountingSem(unsigned int init)
{
    return new CountingSemImpl(init);
}

MsgQueueBase* OperatingSystemFactory::newMsgQueueBase(const std::string pName)
{
    return new MsgQueueImpl(pName);
}

MutexBase* OperatingSystemFactory::newMutex(const std::string pName)
{
    return new MutexImpl(pName);
}

OperatingSystemBase* OperatingSystemFactory::newOperatingSystem()
{
    return new OperatingSystemImpl();
}


