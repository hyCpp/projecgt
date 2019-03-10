#include "Socket.h"
#include "SocketImpl_ZMQ.h"

static AbstractSocket* createSocket(Socket::SocketType type)
{
    return new SocketImpl_ZMQ(type);
}

Socket::Socket(SocketType type)
    : AbstractSocket()
    , m_pSocket(nullptr)
    , m_type(type)
{
}

Socket::~Socket()
{
    if (m_pSocket != nullptr) {
        delete m_pSocket;
        m_pSocket = nullptr;
    }
}

void* Socket::getSocket()
{
    if (m_pSocket != nullptr) {
        return m_pSocket->getSocket();
    }
    return nullptr;
}

bool Socket::Bind(const char *addr)
{
    if (m_pSocket == nullptr) {
        m_pSocket = createSocket(m_type);
    }

    if (m_pSocket != nullptr) {
        return m_pSocket->Bind(addr);
    }
    return false;
}

bool Socket::unBind(const char *addr)
{
    if (m_pSocket != nullptr) {
        return m_pSocket->unBind(addr);
    }
    return false;
}

bool Socket::Connect(const char *addr)
{
    if (NULL == m_pSocket) {
        m_pSocket = createSocket(m_type);
    }

    if (NULL != m_pSocket) {
        return m_pSocket->Connect(addr);
    }

    return false;
}

bool Socket::DisConnect(const char *addr)
{
    if (nullptr != m_pSocket) {
        return m_pSocket->DisConnect(addr);
    }

    return true;
}

bool Socket::Subscribe(const char *msg)
{
    printf("(%p) Subscribe \"%s\"", this, msg);
    if (nullptr == m_pSocket) {
        m_pSocket = createSocket(m_type);
    }
    if (nullptr != m_pSocket) {
        return m_pSocket->Subscribe(msg);
    }

    return false;
}

bool Socket::UnSubscribe(const char *msg)
{
    printf("(%p) UnSubscribe \"%s\"", this, msg);
    if (nullptr != m_pSocket) {
        return m_pSocket->UnSubscribe(msg);
    }

    return false;
}

bool Socket::Send(const void *data, size_t size, uint32_t options)
{
    if (nullptr != m_pSocket) {
        return m_pSocket->Send(data, size, options);
    }

    return false;
}

bool Socket::Recv(AbstractDataBlock **block, uint32_t options)
{
    if (nullptr != m_pSocket) {
        return m_pSocket->Recv(block, options);
    }

    return false;
}

bool Socket::Monitor(const char *addr, uint32_t events)
{
    if (nullptr == m_pSocket) {
        m_pSocket = createSocket(m_type);
    }
    if (nullptr != m_pSocket) {
        return m_pSocket->Monitor(addr, events);
    }

    return false;
}

bool Socket::RecvMonitorInfo(MonitorInfo *info, uint32_t options)
{
    if (nullptr != m_pSocket) {
        return m_pSocket->RecvMonitorInfo(info, options);
    }

    return false;
}

bool Socket::IsCapableOf(SocketCapability capability)
{
    if (nullptr == m_pSocket) {
        m_pSocket = createSocket(m_type);
    }
    if (nullptr != m_pSocket) {
        return m_pSocket->IsCapableOf(capability);
    }

    return false;
}

bool Socket::HasMoreData()
{
    if (nullptr != m_pSocket) {
        return m_pSocket->HasMoreData();
    }

    return false;
}
