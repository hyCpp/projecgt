#include "EV_Socket.h"

EV_Socket::EV_Socket(int type, bool monitor)
    : Socket(static_cast<SocketType>(type))
    , m_dealWithDisconnect(false)
    , m_pSocket(nullptr)
{
    if (monitor) {
        m_pSocket = new EV_Socket(EV_Socket::SOCKTYPE_PAIR, false);
    }
}

EV_Socket::~EV_Socket()
{
    delete m_pSocket;
    m_pSocket = nullptr;
}

bool EV_Socket::Send(const char *command, const EventContext *context)
{
    return Send(command, "", context);
}

bool EV_Socket::Send(const char *msgName, const std::string &msg, const EventContext *context)
{
    printf("EV_Socket Send = [%s]\n", msgName);
    if (msgName == nullptr) {
        return false;
    }

    bool _sendOk = true;

    {
        Sync sync(m_sync);

        if (nullptr == context && 0 == msg.length()) {
            _sendOk = Socket::Send(msgName, strlen(msgName) * sizeof(char), OPTION_NO_WAIT);
        }
        else if (IsCapableOf(CAPABILITY_EMPTY_BLOCK)) {
            _sendOk = Socket::Send(msgName, strlen(msgName) * sizeof(char), OPTION_MORE_BLOCK);

            if (_sendOk) {
                if (nullptr == context) {
                    _sendOk = Socket::Send(msg.data(), msg.length(), OPTION_NO_WAIT);
                }
                else {
                    std::string SeriallizeString = context->Seriallize();
                    int iContextBufSize = SeriallizeString.size();
                    const char * pContextBuf = SeriallizeString.data();
                    if (nullptr != pContextBuf) {
                        // send Message
                        _sendOk = Socket::Send(msg.data(), msg.length(), OPTION_MORE_BLOCK);
                        if (_sendOk) {
                            _sendOk = Socket::Send(pContextBuf, iContextBufSize, OPTION_NO_WAIT);
                        }
                    }
                }
            }
        }
        else {
            std::string header = msgName;
            if (msg.length() > 0) {
                header += "&data";
            }
            if (nullptr != context) {
                header += "&context";
            }
            if (msg.length() > 0 || NULL != context) {
                _sendOk = Socket::Send(header.data(), header.length(), OPTION_MORE_BLOCK);
            }
            else {
                _sendOk = Socket::Send(header.data(), header.length(), OPTION_NO_WAIT);
            }

            if (_sendOk && msg.length() > 0) {
                if (NULL != context) {
                    _sendOk = Socket::Send(msg.data(), msg.length(), OPTION_MORE_BLOCK);
                }
                else {
                    _sendOk = Socket::Send(msg.data(), msg.length(), OPTION_NO_WAIT);
                }
            }

            if (_sendOk && NULL != context) {
                std::string SeriallizeString = context->Seriallize();
                _sendOk = Socket::Send(SeriallizeString.data(), SeriallizeString.length(), OPTION_NO_WAIT);
            }
        }
    }
}

bool EV_Socket::Recv(std::string *msg)
{
    if (nullptr == msg) {
        return false;
    }

    AbstractDataBlock* block = nullptr;
    if (Socket::Recv(&block)) {
        msg->append(reinterpret_cast<const char*>(block->GetData()), block->GetLength());
        delete block;
        return true;
    }

    return false;
}

bool EV_Socket::Monitor(const char *addr, uint32_t events)
{
    if (Socket::Monitor(addr, events)) {
        m_pSocket->Connect(addr);
        return true;
    }

    return false;
}

AbstractSocket* EV_Socket::GetMonitor()
{
    return m_pSocket;
}

void EV_Socket::SetDealWithDisconnect()
{
    m_dealWithDisconnect = true;
}

bool EV_Socket::IsDealWithDisconnect()
{
    return m_dealWithDisconnect;
}

EV_SOCKET_RECV_RESULT EV_Socket::Recv(std::string *msgName, std::string *msg, EventContext *context)
{
    if (nullptr == msgName || nullptr == msg) {
        printf("EV_SocketImpl_ZMQ::Recv msgName = %p, msg = %p, context = %p.\n", msgName, msg, context);
        return EV_SOCKET_RECV_FAILED;
    }

    msgName->clear();
    msg->clear();

    Sync sync(m_sync);

    // 1st: Receive MsgName or command
    if (!Recv(msgName)) {
        printf("Failed to receive message name.");
        return EV_SOCKET_RECV_FAILED;
    }

    bool bHasData = true;
    bool bHasContext = true;
    if (!IsCapableOf(CAPABILITY_EMPTY_BLOCK)) {
        // strip signatures appended to message name.
        bHasData =  msgName->find("&data") != std::string::npos ? true : false;
        bHasContext = msgName->find("&context") != std::string::npos ? true : false;

        size_t seperator = msgName->find("&");
        if (std::string::npos != seperator) {
            msgName->erase(seperator);
        }
    }

    if (IsCapableOf(CAPABILITY_EMPTY_BLOCK)) {
        bHasData = HasMoreData();
    }
    if (bHasData) {
        if (!Recv(msg)) {
            printf("Failed to receive message body.");
            return EV_SOCKET_RECV_FAILED;
        }
    }
    else {
        printf("Missing message body.");
        return EV_SOCKET_RECV_FAILED;
    }

    if (IsCapableOf(CAPABILITY_EMPTY_BLOCK)) {
        bHasContext = HasMoreData();
    }

    if (bHasContext) {
        std::string messageContext;
        if (!Recv(&messageContext)) {
            printf("Failed to receive message body.");
            return EV_SOCKET_RECV_FAILED;
        }
        else {
            if (nullptr != context) {
                context->Deseriallize(messageContext.data(), messageContext.size());
            }
        }
    }
    else if (nullptr != context) {
//        context->m_desModuleId = EV_IDENTITY_WHOLE;
    }

    int count = 0;
    while (HasMoreData()) {
        std::string discard;
        if (Recv(&discard)) {
            ++count;
            printf("event %s has more | count: %d, size:%", msgName->c_str(), count, discard.size());
        }
    }

    printf("ReceiveEvent(): %s", msgName->data());
    // Check it is command or not
    if (0 == memcmp("EV_COMMAND_QUIT", msgName->data(), msgName->size())) {
        return EV_SOCKET_RECV_QUIT;
    }

    return bHasContext ? EV_SOCKET_RECV_CONTEXT : EV_SOCKET_RECV_DATA;
}









