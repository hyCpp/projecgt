#ifndef EV_SOCKET
#define EV_SOCKET

#include "Socket.h"
#include <string>
#include "Events_Context.h"
#include "EV_Sync.h"

enum EV_SOCKET_RECV_RESULT
{
    EV_SOCKET_RECV_FAILED = -1,
    EV_SOCKET_RECV_QUIT = 0,
    EV_SOCKET_RECV_DATA,
    EV_SOCKET_RECV_CONTEXT,
};

class EV_Socket : public Socket
{
public:
    enum
    {
        EV_SOCKTYPE_PUB = SOCKTYPE_PUB,
        EV_SOCKTYPE_SUB = SOCKTYPE_SUB,
        EV_SOCKTYPE_PAIR = SOCKTYPE_PAIR,
        EV_SOCKTYPE_DEALER = SOCKTYPE_DEALER
    };

    EV_Socket(int type, bool monitor = false);
    virtual ~EV_Socket();

    virtual bool Monitor(const char* addr, uint32_t events);

    virtual AbstractSocket* GetMonitor();

    virtual bool Send(const char* command, const EventContext* context = nullptr);
    virtual bool Send(const char* msgName, const std::string &msg, const EventContext* context = nullptr);

    virtual bool Recv(std::string* msg);
    virtual EV_SOCKET_RECV_RESULT Recv(std::string* msgName, std::string* msg, EventContext* context);

    virtual void SetDealWithDisconnect();
    virtual bool IsDealWithDisconnect();

private:
    EV_Socket(const EV_Socket&);
    EV_Socket& operator = (const EV_Socket&);

    bool m_dealWithDisconnect;
    Socket* m_pSocket;
    EV_Sync m_sync;
};

#endif // EV_SOCKET

