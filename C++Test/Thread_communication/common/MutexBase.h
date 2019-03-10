#ifndef MUTEXBASE_H
#define MUTEXBASE_H
#include <string>

class MutexBase
{
public:
    MutexBase(const std::string pName = NULL);
    ~MutexBase();
    virtual bool Lock() = 0;
    virtual bool UnLock() = 0;

    std::string getName();

protected:
    std::string m_Mutex_Name;
};

#endif // MUTEXBASE_H
