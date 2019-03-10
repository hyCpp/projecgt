#ifndef SOCKETCONTEXT
#define SOCKETCONTEXT
#include <zmq.h>

class SocketContext
{
public:
    static void createContext();
    static void* context();
    static void destroyContext();

private:
    SocketContext();
    ~SocketContext();

    static void* m_context;
};

#endif // SOCKETCONTEXT

