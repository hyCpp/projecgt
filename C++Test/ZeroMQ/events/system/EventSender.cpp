#include "EventSender.h"
#include <boost/scoped_ptr.hpp>
#include "EV_ChannelFactory.h"

EventSender::EventSender()
{

}

EventSender::~EventSender()
{

}

void EventSender::SendEvent(const char *msgName, bufMsgPtr msg)
{
    SendEvent(msgName, msg, NULL);
}

void EventSender::SendEvent(const char *msgName, bufMsgPtr msg, const EventContext &context)
{
    return SendEvent(msgName, msg, &context);
}

void EventSender::SendEvent(const char *msgName, bufMsgPtr msg_, const EventContext *context)
{
    if (nullptr == context) {
        printf("SendEvent --> %s", msgName);
    }

    if (nullptr == msg_) {
        printf("SendEvent | msg is NULL");
        return;
    }

    boost::scoped_ptr<protoBufMsg> msg(msg_);
    if (nullptr == msgName) {
        printf("SendEvent | msgName is NULL");
        return;
    }

    bool retCheck = IsRequestProto(msg->GetTypeName());
    if ((nullptr == context && retCheck) || (nullptr != context && (!retCheck))) {
        printf("SendEvent | Ctx check faile");
        return;
    }

    std::string message;
//    msg->SerializeToString(&message);

    EV_Socket* pSocket = nullptr;
    pSocket = EV_ChannelFactory::Instance()->GetPubSocket(EV_CNL_PROXY);
    if (nullptr != pSocket) {
        pSocket->Send(msgName, message, context);
    }


    // Send Inproc
    pSocket = EV_ChannelFactory::Instance()->GetPubSocket(EV_CNL_INPROC);
    if (nullptr != pSocket) {
        pSocket->Send(msgName, message, context);
    }
}

bool EventSender::Reply(const EventContext &context, bufMsgPtr msg)
{
    std::string msgNameStr("");
    if (nullptr != msg) {
        msgNameStr = msg->GetTypeName();
        char cStr[256];
        int j = 0;
        for (int i = 0; i < msgNameStr.size(); ++i) {
            if (msgNameStr.at(i) == '.') {
                cStr[j] = ':';
                ++j;
                cStr[j] = ':';
                ++j;
            }
            else {
                cStr[j] = msgNameStr.at(i);
                ++j;
            }
        }

        msgNameStr.assign(cStr, j);
    }
    return Reply(context, msgNameStr.c_str(), msg);
}

bool EventSender::Reply(const EventContext &context, const char *msgName, bufMsgPtr msg)
{
    boost::scoped_ptr<protoBufMsg> pMsg(msg);

    std::string msgNameStr(msgName);
    std::string msgData("");
    if (nullptr != pMsg) {
//        pMsg->SerializeToString(&msgData);
    }

    // log playing, can use reply func as addr is invalid.
//    if (WORK_STATUS_OFF == EV_EventProxyBase::GetWorkType()) {
//        return false;
//    }

    if (1 == context.m_proxyFlag) {
        printf("EV_EventSender::Reply ev(%s) size(%d)", msgNameStr.c_str(), msgData.size());
        if (nullptr != context.m_spReplyCBFunc) {
            (*context.m_spReplyCBFunc)(context, pMsg.get());
            return true;
        }
    }
    else
    {
        printf("EV_EventSender::Reply ev(%s) size(%d)", msgNameStr.c_str(), msgData.size());
        if (nullptr != context.m_spReplyCBFunc) {
            (*context.m_spReplyCBFunc)(context, pMsg.get());
            return true;
        }
    }
    return false;
}

bool EventSender::IsRequestProto(const std::string &name)
{
    int indexcheck = name.find_last_of(".");
    if (indexcheck<0)
    {
        indexcheck = name.find_last_of("::");
    }
    std::string check = name.substr(indexcheck + 1, strlen("Request"));
    if (0 == check.compare("Request"))
    {
        return true;
    }
    return false;
}
