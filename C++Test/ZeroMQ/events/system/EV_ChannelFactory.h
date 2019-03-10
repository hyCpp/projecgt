#ifndef EV_CHANNELFACTORY
#define EV_CHANNELFACTORY

#include "EV_Socket.h"
#include <map>

enum EV_CNL_TYPE
{
    EV_CNL_INPROC,
    EV_CNL_IPC,
    EV_CNL_IPC_MONITOR,
    EV_CNL_TCP,
    EV_CNL_PROXY,
    EV_CNL_NUM
};

class EV_ChannelFactory
{
public:
    virtual ~EV_ChannelFactory();
    static EV_ChannelFactory* Instance();
    static void Destory();
    void Initialize(const char* processName);

    EV_Socket* GetPubSocket(EV_CNL_TYPE type);
    EV_Socket* GetSubSocket(EV_CNL_TYPE type, const char* moduleName);
    EV_Socket* GetPairSocket(EV_CNL_TYPE type, const char* moduleName);
    EV_Socket* GetMonitorSocket(EV_CNL_TYPE type);

private:
    EV_ChannelFactory();
    EV_ChannelFactory(const EV_ChannelFactory&);
    EV_ChannelFactory& operator = (const EV_ChannelFactory&);

    void SubscribeCommand(EV_Socket* socket);

    typedef std::map<std::string, EV_Socket*> SocketMap;
    typedef std::pair<std::string, EV_Socket*> SocketPair;

    EV_Socket*      m_pPubArray[EV_CNL_NUM];
    SocketMap       m_SubMap;
    SocketMap       m_PairMap;
    std::string     m_processName;
    static EV_Sync  s_cSync;
    static EV_ChannelFactory* m_pChannelFactory;
};

#endif // EV_CHANNELFACTORY

