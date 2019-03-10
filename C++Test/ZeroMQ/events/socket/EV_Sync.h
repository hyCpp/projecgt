#ifndef EV_SYNC
#define EV_SYNC
#include <pthread.h>

class EV_Sync
{
public:
    EV_Sync();
    virtual ~EV_Sync();

    void SyncStart();
    bool TrySyncStart();
    void SyncEnd();

private:
    EV_Sync(const EV_Sync& src) {}
    EV_Sync& operator = (const EV_Sync& src) { return *this; }

    pthread_mutex_t mutex;
    pthread_mutexattr_t attr;
};

class Sync
{
public:
    Sync(EV_Sync& cSync);
    ~Sync();

private:
    Sync(const Sync& cSync);
    Sync& operator=(const Sync& cSync);

    EV_Sync* m_sync;
};

#endif // EV_SYNC

