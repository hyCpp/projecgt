#include "EventSystem.h"
#include "EV_Sync.h"
#include <stdio.h>
#include <string.h>
#include "EV_ChannelFactory.h"

EventSystem* EventSystem::m_pInstance = nullptr;
EV_Sync _Ev_sync;
EventSystem* EventSystem::Instance()
{
    Sync _sync(_Ev_sync);
    if (m_pInstance == nullptr) {
        m_pInstance = new EventSystem();
    }
    return m_pInstance;
}

void EventSystem::Destory()
{
    Sync _sync(_Ev_sync);
    if (nullptr != m_pInstance)
    {
        delete m_pInstance;
        m_pInstance = nullptr;
    }
}

EventSystem::EventSystem()
{
    memset(m_processname, 0, 256);
}

EventSystem::~EventSystem()
{
//    EV_CommandSender cSender;
//    cSender.SendCommandToProxy(EV_COMMAND_QUIT);

//    EV_EventProxyManager::Instance()->Stop();
//    EV_EventLogManager::Destroy();
//    EV_EventProxyManager::Destroy();
//    EV_EventReceiverMgr::Instance()->Stop();
//    EV_EventReceiverMgr::Destroy();
    EV_ChannelFactory::Destory();
}

void EventSystem::Initialize(const char *processName)
{
    strcpy(m_processname, processName);
    EV_ChannelFactory::Instance()->Initialize(processName);

//    EV_EventReceiverMgr::Instance();
}

void EventSystem::Start()
{

}

void EventSystem::Stop()
{

}

std::string EventSystem::dumpStatus()
{

}
