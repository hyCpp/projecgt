#ifndef EVENTRECEIVER
#define EVENTRECEIVER
#include "Config.h"
#include "EventReceiverImpl.h"

class EventReceiver
{
public:
    EventReceiver(const char* moduleName);
    virtual ~EventReceiver();

    virtual void Subscribe(const char* msgName, MsgCallBack callback);
    virtual void SubscribeWithContext(const char* msgName, MsgCallBackWithContext callback);

    virtual void UnSubscribe(const char* msgName);
    virtual void StartReceive();
    virtual void StopReceive();

private:
    EventReceiverImpl* m_pReceiverImpl;

    EventReceiver(const EventReceiver&);
    EventReceiver& operator = (const EventReceiver&);
};

#endif // EVENTRECEIVER

