#ifndef OPERATINGSYSTEMFACTORY_H
#define OPERATINGSYSTEMFACTORY_H
#include "OperatingSystemBase.h"
#include "MutexBase.h"
#include "CountingSemBase.h"
#include "MsgQueueBase.h"
#include <string>
#include <stdio.h>

class OperatingSystemBase;
class CountingSemBase;
class MutexBase;
class MsgQueueBase;

class OperatingSystemFactory
{
public:
    static OperatingSystemBase *newOperatingSystem();
    static CountingSemBase *newCountingSem(unsigned int init);
    static MutexBase *newMutex(const std::string pName = NULL);
    static MsgQueueBase *newMsgQueueBase(const std::string pName = NULL);
};

#endif // OPERATINGSYSTEMFACTORY_H
