#include "EventReceiverImpl.h"
#include <boost/atomic.hpp>
static boost::atomic<int> generator(0);

EventReceiverImpl::EventReceiverImpl(const char *moduleName)
    : m_pcSubSocket(nullptr)
    , m_cModuleName(moduleName)
{
    int iIncrement = generator.fetch_add(1);
    m_iTaskGroupId = 0x00010000 + iIncrement;
    if (iIncrement > 128) {
        printf("EventReceiverImpl Receiver task groupid error!");
    }

    m_pcSubSocket = EV_ChannelFactory::Instance()->GetSubSocket(EV_CNL_INPROC, moduleName);
    //    m_identityId = EV_EventMapTable::GetIdentity(m_cModuleName);
    //    if (EV_IDENTITY_DEFAULT == m_identityId) {
    //        EV_LOGE("EventReceiverImpl:moduleName:%s, getidentity failed\n", moduleName);
    //    }

    m_dwLastEOutTC = 0;
}

EventReceiverImpl::~EventReceiverImpl()
{

}

void EventReceiverImpl::StartReceive()
{

}

void EventReceiverImpl::StopReceive()
{

}

void EventReceiverImpl::Subscribe(const char *msgName, MsgCallBack callback)
{
    if (nullptr == callback) {
        printf("Subscribe callback is NULL");
        return;
    }

    if (nullptr == m_pcSubSocket) {
        printf("Subscribe socket is NULL");
        return;
    }

    std::string key(msgName);
    EventMap::iterator it = m_EventMap.find(key);

    // msgName does not exist
    if (it == m_EventMap.end()) {

        m_EventMap.insert(EventPair(key, callback));
        m_pcSubSocket->Subscribe(msgName);
        printf("%s Subscribe ev:(%s)", m_cModuleName.c_str(), msgName);
    }
}

void EventReceiverImpl::Subscribe(const char *msgName, MsgCallBackWithContext callback)
{
    if (nullptr == callback) {
        printf("Subscribe callback is NULL");
        return;
    }

    if (nullptr == m_pcSubSocket) {
        printf("Subscribe socket is NULL");
        return;
    }

    std::string key(msgName);
    EventMapContext::iterator it = m_EventMapContext.find(key);

    // msgName does not exist
    if (it == m_EventMapContext.end()) {
        m_EventMapContext.insert(EventPairContext(key, callback));
        m_pcSubSocket->Subscribe(msgName);
        printf("%s Subscribe ev:(%s)", m_cModuleName.c_str(), msgName);
    }
}

void EventReceiverImpl::UnSubscribe(const char *msgName)
{
    if (nullptr != m_pcSubSocket) {
        m_pcSubSocket->UnSubscribe(msgName);
        std::string key(msgName);
        m_EventMap.erase(key);
        m_EventMapContext.erase(key);
    }
}

void EventReceiverImpl::TaskCallback(EV_SOCKET_RECV_RESULT eRslt, std::string msgName, std::string message, EventContext context)
{

}

const std::string& EventReceiverImpl::GetModuleName()
{
    return m_cModuleName;
}

bool EventReceiverImpl::onEvent(EV_Socket *socket, short evType)
{

}

void EventReceiverImpl::ModuleReplyCallback(const EventContext &context, bufMsgPtr pMsg)
{

}
