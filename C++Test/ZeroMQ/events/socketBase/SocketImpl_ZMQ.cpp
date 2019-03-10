#include "SocketImpl_ZMQ.h"
#include "SocketContext.h"

// -------------DataBlock--------------
SocketImpl_ZMQ::DataBlock::DataBlock()
    : AbstractDataBlock()
{
    zmq_msg_init(this);
}

SocketImpl_ZMQ::DataBlock::~DataBlock()
{
    zmq_msg_close(this);
}

size_t SocketImpl_ZMQ::DataBlock::GetLength()
{
    zmq_msg_size(this);
}

const void* SocketImpl_ZMQ::DataBlock::GetData()
{
    return zmq_msg_data(this);
}

// -------------SocketImpl_ZMQ---------------

SocketImpl_ZMQ::SocketImpl_ZMQ(SocketType type)
    : AbstractSocket()
    , m_pSocket(nullptr)
{
    signed int realtype = ZMQ_PAIR;  // inproc model, ZMQ_PAIR类型的套接字被设计用来在线程间进行传输
    switch (type) {
    case SOCKTYPE_PUB:
        realtype = ZMQ_PUB;
        break;
    case SOCKTYPE_SUB:
        realtype = ZMQ_SUB;
        break;
    case SOCKTYPE_ROUTER:
        // ZMQ_REQ的升级, 当收到一个消息的时候，在向应用进程转发之前，会拿掉消息中的第一帧, 并且把这个帧作为接下来要路由到的目的地址的唯一标识符,
        // 如果消息的目的地址指向的对端不再存在了，这个消息就会被丢弃
        realtype = ZMQ_ROUTER;
        break;
    case SOCKTYPE_DEALER:
        realtype = ZMQ_DEALER; // ZMQ_REP的升级, 所有被发送的消息都会在所有被连接的对端进行循环，并且从所连接的对端中接收到的每一个消息都会进行平等的排队。
        break;
    default:
    case SOCKTYPE_PAIR:
        realtype = ZMQ_PAIR;
        break;
    }

    // 当使用inproc和ipc时contxt对象必须是同一个对象,当使用tcp时发送端和接受端分别创建一个context
    void* context = SocketContext::context();

    if (context != nullptr) {
        m_pSocket = zmq_socket(context, realtype);
    }
}

SocketImpl_ZMQ::~SocketImpl_ZMQ()
{
    if (nullptr != m_pSocket) {
        zmq_close(m_pSocket);
        m_pSocket = nullptr;
    }
}

void* SocketImpl_ZMQ::getSocket()
{
    return m_pSocket;
}

bool SocketImpl_ZMQ::Bind(const char *addr)
{
    // ipc://address 进程间的传输
    // inproc://someaddress 进程内传输
    // tcp:// + ip + : + port
    if (m_pSocket != nullptr) {
        if (0 == zmq_bind(m_pSocket, addr)) {
            return true;
        }
    }
    return false;
}

bool SocketImpl_ZMQ::unBind(const char *addr)
{
    if (m_pSocket != nullptr) {
        if (0 == zmq_unbind(m_pSocket, addr)) {
            return true;
        }
    }
    return false;
}

bool SocketImpl_ZMQ::Connect(const char *addr)
{
    if (m_pSocket != nullptr) {
        if (0 == zmq_connect(m_pSocket, addr)) {
            return true;
        }
    }
    return false;
}

bool SocketImpl_ZMQ::DisConnect(const char *addr)
{
    if (m_pSocket != nullptr) {
        if (0 != zmq_disconnect(m_pSocket, addr)) {
            return true;
        }
    }
    return false;
}

bool SocketImpl_ZMQ::Subscribe(const char *msg)
{
    void* _socket = getSocket();
    if (_socket != nullptr && msg != nullptr) {
        if (zmq_setsockopt(_socket, ZMQ_SUBSCRIBE, msg, strlen(msg)) == 0) {
            return true;
        }
    }
    return false;
}

bool SocketImpl_ZMQ::UnSubscribe(const char *msg)
{
    void* _socket = getSocket();
    if (_socket != nullptr && msg != nullptr) {
        if (zmq_setsockopt(_socket, ZMQ_UNSUBSCRIBE, msg, strlen(msg)) == 0) {
            return true;
        }
    }
    return false;
}

bool SocketImpl_ZMQ::Send(const void *data, size_t size, uint32_t options)
{
    if (m_pSocket != nullptr) {
        int realoptions = 0;
        if (options & OPTION_MORE_BLOCK) {
            realoptions |= ZMQ_SNDMORE; // 当前正在发送的消息是个多帧消息，并且接下来还会发送更多的消息
        }
        if (options & OPTION_NO_WAIT) {
            realoptions |= ZMQ_DONTWAIT; // 非阻塞模式
        }

        int rc = zmq_send(m_pSocket, data, size, realoptions);

        if (static_cast<size_t>(rc) == size) {
            return true;
        }
    }
    return false;
}

bool SocketImpl_ZMQ::Recv(AbstractDataBlock **block, uint32_t options)
{
    if (m_pSocket == nullptr) {
        return false;
    }

    *block = nullptr;

    DataBlock* data = new DataBlock();

    if (data = nullptr) {
        return false;
    }

    int flag = 0;
    if (options & OPTION_NO_WAIT) {
        flag |= ZMQ_DONTWAIT;
    }

    int rc = zmq_msg_recv(data, m_pSocket, flag);
    if (rc < 0) {
        *block = nullptr;
        delete data;
        data = nullptr;
        return false;
    }

    *block = data;
    return true;
}

bool SocketImpl_ZMQ::IsCapableOf(SocketCapability capability)
{
    switch (capability) {
    case CAPABILITY_EMPTY_BLOCK:
        return true;
    default:
        return false;
    }
}

bool SocketImpl_ZMQ::Monitor(const char *addr, uint32_t events)
{
    if (m_pSocket == nullptr || addr == nullptr || strlen(addr) == 0) {
        return false;
    }

    int realevents = 0;
    if (events & kEventConnected) {
        realevents |= ZMQ_EVENT_CONNECTED;
    }
    if (events & kEventConnectDelayed) {
        realevents |= ZMQ_EVENT_CONNECT_DELAYED;
    }
    if (events & kEventConnectRetried) {
        realevents |= ZMQ_EVENT_CONNECT_RETRIED;
    }
    if (events & kEventListening) {
        realevents |= ZMQ_EVENT_LISTENING;
    }
    if (events & kEventBindFailed) {
        realevents |= ZMQ_EVENT_BIND_FAILED;
    }
    if (events & kEventAccepted) {
        realevents |= ZMQ_EVENT_ACCEPTED;
    }
    if (events & kEventAcceptFailed) {
        realevents |= ZMQ_EVENT_ACCEPT_FAILED;
    }
    if (events & kEventClosed) {
        realevents |= ZMQ_EVENT_CLOSED;
    }
    if (events & kEventCloseFailed) {
        realevents |= ZMQ_EVENT_CLOSE_FAILED;
    }
    if (events & kEventDisconnected) {
        realevents |= ZMQ_EVENT_DISCONNECTED;
    }
    if (events & kEventGreeted) {
        return false;  // not supported.
    }

    int rc = zmq_socket_monitor(m_pSocket, addr, realevents);

    return rc < 0 ? false : true;
}

bool SocketImpl_ZMQ::RecvMonitorInfo(MonitorInfo *info, uint32_t options)
{
    if (info == nullptr) {
        return false;
    }
    AbstractDataBlock* block = nullptr;
    if (Recv(&block, options)) {
        if (block != nullptr) {
            int flag = 0;
            if (block->GetData() != nullptr) {
                const MonitorInfo* event = reinterpret_cast<const MonitorInfo*>(block->GetData());

                switch (event->event) {
                case ZMQ_EVENT_CONNECTED:
                    info->event = kEventConnected;
                    printf("和远程已经建立了连接了,这个新连接的文件描述符是%d.\n", event->fd);
                    break;
                case ZMQ_EVENT_CONNECT_DELAYED:
                    info->event = kEventConnectDelayed;
                    printf("尝试将同步连接,变成异步连接\n");
                    break;
                case ZMQ_EVENT_CONNECT_RETRIED:
                    info->event = kEventConnectRetried;
                    printf("尝试重新连接,其重新连接的间隔为%d\n", event->fd);
                    break;
                case ZMQ_EVENT_LISTENING:
                    info->event = kEventListening;
                    printf("正在准备接受连接..., 其文件描述符是监听套接字:%d\n", event->fd);
                    break;
                case ZMQ_EVENT_BIND_FAILED:
                    info->event = kEventBindFailed;
                    printf("不能绑定到地址,其错误信息是:%s\n", zmq_strerror(event->fd));
                    break;
                case ZMQ_EVENT_ACCEPTED:
                    info->event = kEventAccepted;
                    printf("有一个新的连接已经被接受, 其文件描述符或者句柄是:%d\n", event->fd);
                    break;
                case ZMQ_EVENT_ACCEPT_FAILED:
                    info->event = kEventAcceptFailed;
                    printf("不能接受一个来自于客户端的连接:其错误信息是:%s\n", zmq_strerror(event->fd));
                    break;
                case ZMQ_EVENT_CLOSED:
                    info->event = kEventClosed;
                    printf("标识为%d的连接已经关闭连接了.\n", event->fd);
                    break;
                case ZMQ_EVENT_CLOSE_FAILED:
                    info->event = kEventCloseFailed;
                    break;
                case ZMQ_EVENT_DISCONNECTED:
                    info->event = kEventDisconnected;
                    printf("连接崩溃,出现崩溃的文件描述符是%d\n", event->fd);
                    break;
                default:
                    printf("Unknown event received: %d\n", flag);
                    delete block;
                    block = nullptr;
                    return false;
                }
                delete block;
                block = nullptr;
                return true;
            }
            else {
                return false;
            }
        }
    }
    return false;
}

bool SocketImpl_ZMQ::HasMoreData()
{
    if (NULL == m_pSocket) {
        return false;
    }

    int64_t more = 0;
    size_t more_size = sizeof(more);
    int rc = zmq_getsockopt(m_pSocket, ZMQ_RCVMORE, &more, &more_size);
    if (rc != 0) {
        return false;
    }

    return more != 0 ? true : false;
}









