#include "EV_ChannelFactory.h"
#include "SocketContext.h"

const std::string CHANNEL_PRIFIX[] =
{
    "inproc://transit/"
    , "ipc:///tmp/navi.eventsys."
    , "inproc://monitor.ipc."
    , "inproc://transit_proxy/"
};

EV_ChannelFactory* EV_ChannelFactory::m_pChannelFactory = nullptr;
EV_Sync EV_ChannelFactory::s_cSync;
EV_ChannelFactory* EV_ChannelFactory::Instance()
{
    if (m_pChannelFactory == nullptr) {
        m_pChannelFactory = new EV_ChannelFactory();
    }

    return m_pChannelFactory;
}

EV_ChannelFactory::EV_ChannelFactory()
{
    SocketContext::createContext();
    for (int i = 0; i < EV_CNL_NUM; i++)
    {
        m_pPubArray[i] = nullptr;
    }
}

EV_ChannelFactory::~EV_ChannelFactory()
{
    for (int i = 0; i < EV_CNL_NUM; i++)
    {
        if (NULL != m_pPubArray[i])
        {
            delete m_pPubArray[i];
            m_pPubArray[i] = NULL;
        }
    }

    for (SocketMap::iterator it = m_SubMap.begin(); it != m_SubMap.end(); ++it)
    {
        if (nullptr != it->second)
        {
            delete it->second;
            it->second = nullptr;
        }
    }

    for (SocketMap::iterator it = m_PairMap.begin(); it != m_PairMap.end(); ++it)
    {
        if (nullptr != it->second)
        {
            delete it->second;
            it->second = nullptr;
        }
    }

    m_SubMap.clear();
    m_PairMap.clear();
    SocketContext::destroyContext();
}

void EV_ChannelFactory::Destory()
{
    if (nullptr != m_pChannelFactory)
    {
        delete m_pChannelFactory;
        m_pChannelFactory = nullptr;
    }
}

void EV_ChannelFactory::Initialize(const char* processName)
{
    m_processName = processName;

    // inproc
    m_pPubArray[EV_CNL_INPROC] = new EV_Socket(EV_Socket::EV_SOCKTYPE_PUB);
    m_pPubArray[EV_CNL_INPROC]->Bind((CHANNEL_PRIFIX[EV_CNL_INPROC] + m_processName).c_str());

    // proxy
    m_pPubArray[EV_CNL_PROXY] = new EV_Socket(EV_Socket::EV_SOCKTYPE_PUB);
    m_pPubArray[EV_CNL_PROXY]->Bind((CHANNEL_PRIFIX[EV_CNL_PROXY] + m_processName).c_str());

    // ipc and ipc_monitor
    m_pPubArray[EV_CNL_IPC] = new EV_Socket(EV_Socket::EV_SOCKTYPE_PUB);
    m_pPubArray[EV_CNL_IPC]->Bind((CHANNEL_PRIFIX[EV_CNL_IPC] + m_processName).c_str());
    // tcp has no pub socket
}

EV_Socket* EV_ChannelFactory::GetSubSocket(EV_CNL_TYPE type, const char *moduleName)
{
    if (EV_CNL_NUM <= type)
    {
        return nullptr;
    }

    Sync sync(s_cSync);

    std::string key(moduleName);
    SocketMap::iterator it = m_SubMap.find(key);

    // channel does not exist
    if (it == m_SubMap.end())
    {
        EV_Socket* socket = nullptr;
        switch (type)
        {
        case EV_CNL_IPC:
            socket = new EV_Socket(EV_Socket::EV_SOCKTYPE_SUB, true);   // need to monitor
            socket->Connect((CHANNEL_PRIFIX[type] + moduleName).c_str());
            socket->Monitor((CHANNEL_PRIFIX[EV_CNL_IPC_MONITOR]+moduleName).c_str(), AbstractSocket::kEventDisconnected);
            printf("%s(%p) Connect to channel %s", m_processName.c_str(), socket, (CHANNEL_PRIFIX[type] + moduleName).c_str());
            break;
        case EV_CNL_TCP:
            socket = new EV_Socket(EV_Socket::EV_SOCKTYPE_SUB);
            socket->Connect((CHANNEL_PRIFIX[type] + moduleName).c_str());
            printf("%s(%p) Connect to channel %s", m_processName.c_str(), socket, (CHANNEL_PRIFIX[type] + moduleName).c_str());
            break;
        default:
            socket = new EV_Socket(EV_Socket::EV_SOCKTYPE_SUB);
            socket->Connect((CHANNEL_PRIFIX[type] + m_processName).c_str());
            printf("%s(%p) Connect to channel %s", moduleName, socket, (CHANNEL_PRIFIX[type] + m_processName).c_str());
            SubscribeCommand(socket);
            break;
        }

        m_SubMap.insert(SocketPair(key, socket));
        return socket;
    }
    else
    {
        return it->second;
    }
}

EV_Socket* EV_ChannelFactory::GetPubSocket(EV_CNL_TYPE type)
{
    if (EV_CNL_NUM <= type)
    {
        return nullptr;
    }

    return m_pPubArray[type];
}

EV_Socket* EV_ChannelFactory::GetPairSocket(EV_CNL_TYPE type, const char *moduleName)
{
    if (EV_CNL_NUM <= type)
    {
        return nullptr;
    }

    Sync sync(s_cSync);

    std::string key(moduleName);
    SocketMap::iterator it = m_PairMap.find(key);

    // channel does not exist
    if (it == m_PairMap.end())
    {
        EV_Socket* socket = new EV_Socket(EV_Socket::EV_SOCKTYPE_DEALER);
        if (nullptr != socket)
        {
            m_PairMap.insert(SocketPair(key, socket));

            switch (type)
            {
            case EV_CNL_TCP:
                // bind tcp://10.0.2.2 will cause crash in Emulator
                // I have to change it to connect as a client instead.
                socket->Connect((CHANNEL_PRIFIX[type] + moduleName).c_str());
                printf("%s Bind to channel %s", m_processName.c_str(), (CHANNEL_PRIFIX[type] + moduleName).c_str());
                break;
            default:
                m_PairMap.erase(key);
                delete socket;
                socket = nullptr;
                break;
            }
            return socket;
        }
        return nullptr;
    }
    else
    {
        return it->second;
    }
}

EV_Socket* EV_ChannelFactory::GetMonitorSocket(EV_CNL_TYPE type)
{
    if (EV_CNL_IPC_MONITOR == type)
    {
        return m_pPubArray[EV_CNL_IPC_MONITOR];
    }

    return nullptr;
}

void EV_ChannelFactory::SubscribeCommand(EV_Socket *socket)
{
    if (nullptr != socket) {
        socket->Subscribe("EV_COMMAND_");
    }
}
