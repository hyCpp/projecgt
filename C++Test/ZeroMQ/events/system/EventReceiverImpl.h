#ifndef EVENTRECEIVERIMPL
#define EVENTRECEIVERIMPL
#include <string>
#include <Config.h>
#include <Events_Context.h>
#include "EV_Socket.h"
#include <map>
#include "EV_ChannelFactory.h"
#include <stdio.h>

class EventReceiverImpl
{
public:
    friend class EventReceiverMgr;

    EventReceiverImpl(const char* moduleName);
    virtual ~EventReceiverImpl();

    const std::string& GetModuleName();

    void Subscribe(const char* msgName, MsgCallBack callback);
    void Subscribe(const char* msgName, MsgCallBackWithContext callback);

    void UnSubscribe(const char* msgName);
    void StartReceive();
    void StopReceive();

    void ModuleReplyCallback(const EventContext& context, bufMsgPtr pMsg);

    virtual bool onEvent(EV_Socket* socket, short evType);

    void TaskCallback(EV_SOCKET_RECV_RESULT eRslt, std::string msgName, std::string message, EventContext context);

private:
    typedef std::map<std::string, MsgCallBack> EventMap;
    typedef std::pair<std::string, MsgCallBack> EventPair;

    typedef std::map<std::string, MsgCallBackWithContext> EventMapContext;
    typedef std::pair<std::string, MsgCallBackWithContext> EventPairContext;

    EventMap         m_EventMap;
    EventMapContext  m_EventMapContext;

    EV_Socket*  m_pcSubSocket;
    const std::string m_cModuleName;
    int64_t m_identityId;
    int   m_iTaskGroupId;
    uint32_t m_dwLastEOutTC;

    EventReceiverImpl(const EventReceiverImpl&);
    EventReceiverImpl& operator = (const EventReceiverImpl&);
};

#endif // EVENTRECEIVERIMPL

