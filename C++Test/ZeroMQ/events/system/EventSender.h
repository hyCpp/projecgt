#ifndef EVENTSENDER
#define EVENTSENDER
#include "EV_Socket.h"
#include "Events_Context.h"

class EventSender
{
public:
    EventSender();
    virtual ~EventSender();

    virtual void SendEvent(const char* msgName, bufMsgPtr msg);
    virtual void SendEvent(const char* msgName, bufMsgPtr msg, const EventContext& context);
    virtual bool Reply(const EventContext& context, bufMsgPtr msg);

    // forward to proxy channel, must use message name param
    virtual bool Reply(const EventContext& context, const char* msgName, bufMsgPtr msg);

protected:
    virtual bool IsRequestProto(const std::string& name);
    virtual void SendEvent(const char* msgName, bufMsgPtr msg_, const EventContext* context);
};

#endif // EVENTSENDER

