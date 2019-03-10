#include "ThreadPoolDemo.h"


ThreadPoolDemo::ThreadPoolDemo()
{

}

ThreadPoolDemo::ThreadPoolDemo(int size)
    : m_IsRunnable(true),
      m_IdleThreadNum(size < 1 ? 1 : size)
{

}

ThreadPoolDemo::~ThreadPoolDemo()
{
    onStop();
}

bool ThreadPoolDemo::Initialize()
{
    AddThread(m_IdleThreadNum.load());
}

bool ThreadPoolDemo::AddThread(int count)
{
    for (; m_ThreadPool.size() < MAX_THREAD_NUM && count > 0; --count) {
        m_ThreadPool.emplace_back([this]{
            while (m_IsRunnable) {
                EventTask _task;
                {
                    std::unique_lock<std::mutex> lock(m_lock);
                    m_ConditionVariable.wait(lock, [this]{
                        return !m_IsRunnable || !m_TaskQueue.empty();
                    });

                    if (!m_IsRunnable) return;

                    _task = std::move(m_TaskQueue.front());
                    m_TaskQueue.pop();
                }
                m_IdleThreadNum--;
                _task();
                m_IdleThreadNum++;
            }
        });
    }
}

int ThreadPoolDemo::IdleThreadCount() const
{
    return m_IdleThreadNum.load();
}

int ThreadPoolDemo::getTaskCount() const
{
    return m_TaskQueue.size();
}

void ThreadPoolDemo::onStop()
{
    m_IsRunnable.store(false);
    m_ConditionVariable.notify_all();
    for (std::thread& thread : m_ThreadPool) {
        if (thread.joinable()) {
            thread.join();
        }
    }

}
