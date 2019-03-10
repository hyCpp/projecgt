#ifndef SOCKETIMPL_ZMQ
#define SOCKETIMPL_ZMQ

#include <zmq.h>
#include "AbstractSocket.h"

class SocketImpl_ZMQ : public AbstractSocket
{
public:
    SocketImpl_ZMQ(SocketType type);
    virtual ~SocketImpl_ZMQ();


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

protected:
    void* m_pSocket;

private:

    class DataBlock : public AbstractDataBlock ,public zmq_msg_t
    {
    public:
        DataBlock();
        ~DataBlock();
        size_t GetLength();
        const void* GetData();
    };

    SocketImpl_ZMQ(const SocketImpl_ZMQ&);
    SocketImpl_ZMQ& operator = (const SocketImpl_ZMQ&);
};

#endif // SOCKETIMPL_ZMQ

