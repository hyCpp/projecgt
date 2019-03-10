#include "ThreadTest/TestThreadA.h"
#include "ThreadTest/TestThreadB.h"
#include "MsgQueueBase.h"
#include "OperatingSystemBase.h"
#include "OperatingSystemFactory.h"
#include "OperatingSystemImpl.h"
#include <unistd.h>
#include "TC_Log.h"

int main() {
    TC_Log::setLogStatus(true);
    MsgQueueBase *q = OperatingSystemFactory::newMsgQueueBase("B to A message Queue");

    TestThreadA *a = new TestThreadA("A Thread");
    TestThreadB *b = new TestThreadB("B Thread");

    a->setMsgQueue(q);
    b->setMsgQueue(q);

    a->run();
    b->run();
    while(1){
    }
}

