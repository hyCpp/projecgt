#ifndef MYTHREAD
#define MYTHREAD
#include <string>
#include <CThread.h>
class CThread;

class MyThread
{
public:
    MyThread();
    MyThread(const std::string pName);
    ~MyThread();

    void ThreadEntry();

    virtual bool run() = 0;
    virtual bool mainLoop();
    void Notify();
    void Wait();
public:

    CThread *p_CThread;
    std::string m_Thread_Name;
};
#endif // MYTHREAD

