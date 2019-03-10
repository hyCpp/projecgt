#ifndef THREADPOOLDEMO
#define THREADPOOLDEMO

#include <thread>
#include <atomic>
#include <mutex>
#include <iostream>
#include <condition_variable>
#include <list>
#include <vector>
#include <queue>
#include <string>
#include <functional>
#include <future>

const int MAX_THREAD_NUM = 20;

class ThreadPoolDemo
{
public:
    using EventTask = std::function<void()>;

public:
    ThreadPoolDemo();
    ThreadPoolDemo(int size = 5);
    ThreadPoolDemo(const ThreadPoolDemo&) = delete;
    ThreadPoolDemo& operator = (const ThreadPoolDemo&) = delete;
    ThreadPoolDemo(ThreadPoolDemo&&) = default;
    ~ThreadPoolDemo();

    bool Initialize();
    int IdleThreadCount() const;
    int getTaskCount() const;
    bool addThread(int count = 1);
    void onStop();

    template<typename Func, typename... Args>
    auto ExecuteResult(Func&& func, Args&&... args)->std::future<decltype(func(args...))> {
        if (!m_IsRunnable) throw std::runtime_error("Threadpool is stopped");

        using RetType = decltype(func(args...));
        using PackagedTask = std::packaged_task<RetType()>;

        std::shared_ptr<PackagedTask> task = std::make_shared<PackagedTask>(
                    std::bind(std::forward<Func>(func), std::forward<Args>(args)...)
                    );

//        PackagedTask task(std::bind(std::forward<Func>(func), std::forward<Args>(args)...));

        std::future<RetType> future = task->get_future();
        {
            std::lock_guard<std::mutex> lock(m_lock);
            m_TaskQueue.emplace([task](){
//                (*task)();
                task->operator()();
            });
        }

        m_ConditionVariable.notify_one();

        return future;
    }

    template<typename Func, typename... Args>
    void Execute(Func&& func, Args&&... args) {
        if (!m_IsRunnable) throw std::runtime_error("Threadpool is stopped");
        auto task = std::bind(std::forward<Func>(func), std::forward<Args>(args)...);
        {
            std::lock_guard<std::mutex> lock(m_lock);
            m_TaskQueue.emplace(task);
        }
        m_ConditionVariable.notify_one();
    }

private:


private:
    std::mutex m_lock;
    std::atomic<bool> m_IsRunnable;
    std::atomic<int> m_IdleThreadNum;
    std::list<std::thread> m_ThreadPool;
    std::condition_variable m_ConditionVariable;
    std::queue<EventTask> m_TaskQueue;
};


#endif // THREADPOOLDEMO

