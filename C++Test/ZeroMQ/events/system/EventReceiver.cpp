#include "EventReceiver.h"
#include "boost/bind.hpp"

EventReceiver::EventReceiver(const char *moduleName)
{
    m_pReceiverImpl = new EventReceiverImpl(moduleName);
}

EventReceiver::~EventReceiver()
{
    StopReceive();
    if (nullptr != m_pReceiverImpl) {
        delete m_pReceiverImpl;
    }
}

void EventReceiver::Subscribe(const char *msgName, MsgCallBack callback)
{
//    EventProxyManager::Instance()->Subscribe(msgName);

    if (nullptr != m_pReceiverImpl) {
        m_pReceiverImpl->Subscribe(msgName, callback);
    }
}

void EventReceiver::SubscribeWithContext(const char *msgName, MsgCallBackWithContext callback)
{
    if (nullptr != m_pReceiverImpl) {
        m_pReceiverImpl->Subscribe(msgName, callback);
    }
}

void EventReceiver::UnSubscribe(const char *msgName)
{
    if (nullptr != m_pReceiverImpl) {
        m_pReceiverImpl->UnSubscribe(msgName);
    }
}

void EventReceiver::StartReceive()
{
    if (nullptr != m_pReceiverImpl) {
        MsgCallBackWithContext cb = boost::bind(&EventReceiverImpl::ModuleReplyCallback, m_pReceiverImpl, _1, _2);
        SubscribeWithContext("common::request", cb);
        m_pReceiverImpl->StartReceive();
    }
}

void EventReceiver::StopReceive()
{
    if (nullptr != m_pReceiverImpl) {
        m_pReceiverImpl->StopReceive();
    }
}
