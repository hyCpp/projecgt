#ifndef ABSTRACTSOCKET
#define ABSTRACTSOCKET

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "AbstractDataBlock.h"

class AbstractSocket
{
public:
    enum SocketType
    {
        SOCKTYPE_PUB,
        SOCKTYPE_SUB,
        SOCKTYPE_PAIR,
        SOCKTYPE_DEALER,
        SOCKTYPE_ROUTER
    };

    enum
    {
        OPTION_MORE_BLOCK = 1,
        OPTION_NO_WAIT = 2
    };

    enum MonitorEvent
    {
        kEventConnected         = 1,
        kEventConnectDelayed    = 2,
        kEventConnectRetried    = 4,
        kEventListening         = 8,
        kEventBindFailed        = 16,
        kEventAccepted          = 32,
        kEventAcceptFailed      = 64,
        kEventClosed            = 128,
        kEventCloseFailed       = 256,
        kEventDisconnected      = 512,
        kEventGreeted           = 1024
    };

    enum SocketCapability
    {
        CAPABILITY_EMPTY_BLOCK  // send/receive data block of 0-byte size
    };

    struct MonitorInfo
    {
        uint32_t event;
        int fd;
    };

    AbstractSocket() {}
    virtual ~AbstractSocket() {}
    virtual void* getSocket() = 0;
    virtual bool Bind(const char* addr) = 0;
    virtual bool unBind(const char* addr) = 0;
    virtual bool Connect(const char* addr) = 0;
    virtual bool DisConnect(const char* addr) = 0;
    virtual bool Send(const void* data, size_t size, uint32_t options = 0) = 0;
    virtual bool Recv(AbstractDataBlock** block, uint32_t options = 0) = 0;
    virtual bool Subscribe(const char* msg) = 0;
    virtual bool UnSubscribe(const char* msg) = 0;
    virtual bool IsCapableOf(SocketCapability capability) = 0;
    virtual bool Monitor(const char* addr, uint32_t events) = 0;
    virtual bool RecvMonitorInfo(MonitorInfo* info, uint32_t options = 0) = 0;
    virtual bool HasMoreData() = 0;

private:
    AbstractSocket(const AbstractSocket&);
    AbstractSocket& operator = (const AbstractSocket&);
};

#endif // ABSTRACTSOCKET

