#ifndef WEAKPTRTEST
#define WEAKPTRTEST
#include <memory>
#include <stdio.h>
#include "../../LogConfig/Log_Func.h"

class B;
class A
{
public:
    A()
        :m_a(99)
    {}

    ~A()
    {
        TCLOGD("destory A");
    }

    void printA()
    {
        LOGD_FUNC();
        LOGD("m_a is %d", m_a);
        LOGD("s_pToB.use_count() is %d", s_pToB.use_count());
    }


    std::shared_ptr<B> s_pToB;

private:
    int m_a;
};

class B
{
public:
    B()
        : m_b(100)
    {}

    ~B()
    {
        TCLOGD("destory B");
    }

    void printB()
    {
        LOGD("m_b is %d", m_b);
        LOGD("s_pToA.use_count() is %d", s_pToA.use_count());
    }


    std::shared_ptr<A> s_pToA;
private:
    int m_b;
};















class weakB;
class weakA
{
public:
    weakA()
        : m_weakA(99)
    {}
    ~weakA()
    {
        TCLOGD("destory weakA");
    }

    void printWeakA()
    {
        std::shared_ptr<weakB> weakPtr = s_pToWeakB.lock();
        if (weakPtr) {
            LOGD("weakPtr.use_count() is %d", weakPtr.use_count());
        }
    }

    std::weak_ptr<weakB> s_pToWeakB;

private:
    int m_weakA;
};

class weakB
{
public:
    weakB()
        : m_weakB(100)
    {}
    ~weakB()
    {
        TCLOGD("destory weakB");
    }

    void printWeakB()
    {
        LOGD("s_pToShareA.use_count() is %d", s_pToShareA.use_count());
    }

    std::shared_ptr<weakA> s_pToShareA;

private:
    int m_weakB;
};
#endif // WEAKPTRTEST

