#ifndef EVENTSYSTEM
#define EVENTSYSTEM
#include <string>

namespace google
{
namespace protobuf
    {
        class MessageLite;
    }
}

class EventSystem
{
public:
    ~EventSystem();
    static EventSystem* Instance();
    static void Destory();

    void Initialize(const char* processName);
//    void AddEventFactory(EV_EventFactory * pFac);
    void Start();
    void Stop();
    std::string dumpStatus();

    ::google::protobuf::MessageLite* GetFactory(const std::string& msgName);

private:
    EventSystem();
    EventSystem(const EventSystem&);
    EventSystem& operator = (const EventSystem&);

    static EventSystem* m_pInstance;
    char m_processname[265];
};

#endif // EVENTSYSTEM

