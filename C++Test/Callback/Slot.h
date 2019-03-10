#ifndef SLOT
#define SLOT

#include <vector>
#include "../LogConfig/Log_Func.h"

template<typename T1, typename T2>
class SlotBase
{
public:
    virtual void perform(T1 param, T2 param1) = 0;
};


template<typename T, typename T1, typename T2>
class SlotImpl : public SlotBase<T1, T2>
{
public:
    SlotImpl(T* t, void(T::*pFunc)(T1, T2))
    {
        m_pFunc = pFunc;
        m_pObj = t;
    }

    ~SlotImpl()
    {

    }

    void perform(T1 param, T2 param1)
    {
        (m_pObj->*m_pFunc)(param, param1);
    }

private:
    T* m_pObj;
    void (T::*m_pFunc)(T1, T2);
};

template<typename T1, typename T2>
class Slot
{
public:
    template<typename T>
    Slot(T* obj, void (T::*pFunc)(T1, T2))
    {
        m_pSlotBase = new SlotImpl<T, T1, T2>(obj, pFunc);
    }

    ~Slot()
    {
        delete m_pSlotBase;
        m_pSlotBase = NULL;
    }

    void perform(T1 param, T2 param1)
    {
        m_pSlotBase->perform(param, param1);
    }

private:
    SlotBase<T1, T2>* m_pSlotBase;
};

#endif // SLOT

