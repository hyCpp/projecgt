#include "SocketContext.h"

void* SocketContext::m_context = nullptr;

SocketContext::SocketContext()
{

}

SocketContext::~SocketContext()
{

}

void* SocketContext::context()
{
    return m_context;
}

void SocketContext::createContext()
{
    m_context = zmq_ctx_new();
}

void SocketContext::destroyContext()
{
    zmq_term(m_context);
    m_context = nullptr;
}
