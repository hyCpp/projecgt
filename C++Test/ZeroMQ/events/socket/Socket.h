#ifndef SOCKET
#define SOCKET
#include "AbstractSocket.h"

class Socket : public AbstractSocket
{
public:
    Socket(SocketType type);
    virtual ~Socket();

    virtual void* getSocket();
    virtual bool Bind(const char* addr);
    virtual bool unBind(const char* addr);
    virtual bool Connect(const char* addr);
    virtual bool DisConnect(const char* addr);
    virtual bool Send(const void* data, size_t size, uint32_t options = 0);
    virtual bool Recv(AbstractDataBlock** block, uint32_t options = 0);
    virtual bool Subscribe(const char* msg);
    virtual bool UnSubscribe(const char* msg);
    virtual bool IsCapableOf(SocketCapability capability);
    virtual bool Monitor(const char* addr, uint32_t events);
    virtual bool RecvMonitorInfo(MonitorInfo* info, uint32_t options = 0);
    virtual bool HasMoreData();

private:
    Socket(const Socket&);
    Socket& operator = (const Socket&);

    SocketType          m_type;
    AbstractSocket*     m_pSocket;
};

#endif // SOCKET

