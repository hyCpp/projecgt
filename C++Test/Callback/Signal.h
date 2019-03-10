#ifndef SIGNAL
#define SIGNAL
#include "Slot.h"

#define CONNECT(sender, signal, receiver, slot) sender.signal.bind(receiver, slot)

template<typename T1, typename T2>
class Signal
{
public:
    template<typename T>
    void bind(T* pObj,void (T::*pFunc)(T1 param, T2 param1))
    {
        m_slots.push_back(new Slot<T1, T2>(pObj, pFunc));
    }

    ~Signal()
     {
         typename std::vector<Slot<T1, T2>* >::iterator iter;
         for (iter = m_slots.begin(); iter != m_slots.end(); iter++)
         {
             delete *iter;
         }
     }

    void operator () (T1 param, T2 param1)
    {
        typename std::vector<Slot<T1, T2>* >::iterator iter;
        for (iter = m_slots.begin(); iter != m_slots.end(); iter++)
        {
            (*iter)->perform(param, param1);
        }
    }

private:
    std::vector<Slot<T1, T2>* > m_slots;
};

#endif // SIGNAL

