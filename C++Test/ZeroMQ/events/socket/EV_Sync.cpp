#include "EV_Sync.h"

EV_Sync::EV_Sync()
{
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&mutex, &attr);
}

EV_Sync::~EV_Sync()
{
    pthread_mutexattr_destroy(&attr);
    pthread_mutex_destroy(&mutex);
}

bool EV_Sync::TrySyncStart()
{
    int ret = pthread_mutex_trylock(&mutex);
    return (ret == 0) ? true : false;
}

void EV_Sync::SyncStart()
{
    pthread_mutex_lock(&mutex);
}

void EV_Sync::SyncEnd()
{
    pthread_mutex_unlock(&mutex);
}


Sync::Sync(EV_Sync &cSync)
    : m_sync(&cSync)
{
    if (m_sync) m_sync->SyncStart();
}

Sync::~Sync()
{
    if (m_sync) m_sync->SyncEnd();
}
