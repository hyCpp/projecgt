#ifndef NGTESTSERVICESTUB
#define NGTESTSERVICESTUB

#include <string>
#include <stdio.h>
#include "replier.h"
#include "NGTestThread.h"
#include "NGTestPerform.h"
#include <queue>
#include <semaphore.h>

struct MsgData
{
    long int msgId;
    char msgText[8096];
};

class NGTestServiceStub
{
public:
    NGTestServiceStub();
    ~NGTestServiceStub();

    void onInit();
    void onDeInit();
    void receiveMsg();
    bool selectData(int n);
    void Run();

private:
    void Wait();
    void Post();

private:

    int m_msgId;
    MsgData m_msgData;
    replier* m_replier;
    NGTestThread* m_thread;
    NGTestPerform* m_perform;

    sem_t m_sem;
    pthread_mutex_t m_mutex;

    std::queue<std::string> m_queue;
    bool m_flag;
};

#endif // NGTESTSERVICESTUB

