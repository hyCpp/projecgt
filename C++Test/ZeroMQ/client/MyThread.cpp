#include "MyThread.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <pthread.h>
#include <unistd.h>

MyThread::MyThread(const std::string pName)
{
    m_Thread_Name = pName;
    p_CThread = new CThread();
}

MyThread::~MyThread()
{
    delete p_CThread;
    p_CThread = nullptr;
}

void MyThread::ThreadEntry()
{
    run();
}

bool MyThread::mainLoop()
{
    if (!p_CThread->createThread(this)) {
        printf("Create Thread Fail...\n");
        return false;
    }
}

void MyThread::Notify()
{
    p_CThread->Notify();
}

void MyThread::Wait()
{
    p_CThread->Wait();
}
