#ifndef EVENTS_CONTEXT
#define EVENTS_CONTEXT
#include <string>
#include "google/protobuf/message_lite.h"
#include "Config.h"

class EventContext;

class EV_ReplyFuncBase
{
public:
    virtual void operator() (const EventContext& evcontext, const bufMsgPtr pMsg) {}

    EV_ReplyFuncBase() {}
    virtual ~EV_ReplyFuncBase() {}
    friend class EventContext;
private:
    virtual void* GetReplyInnerAddr() = 0;
};

template<typename obj>
class EV_ReplyFunc: public EV_ReplyFuncBase
{
public:
    typedef void (obj::*replycallback)(const EventContext& evcontext, const bufMsgPtr pMsg);

    EV_ReplyFunc()
        : m_cReplyInnerAddr() {}

    EV_ReplyFunc(obj* pThis, replycallback pfc)
        : m_cReplyInnerAddr(pThis, pfc)
    {

    }

    virtual ~EV_ReplyFunc() {}

    virtual void operator() (const EventContext& evcontext, const bufMsgPtr pMsg)
    {
        if (nullptr != m_cReplyInnerAddr.m_pThis && nullptr != m_cReplyInnerAddr.m_pfc) {
            ((m_cReplyInnerAddr.m_pThis)->*(m_cReplyInnerAddr.m_pfc))(evcontext, pMsg);
        }
    }

    friend class EventContext;

private:
    virtual void* GetReplyInnerAddr()
    {
        return &m_cReplyInnerAddr;
    }

    struct ReplyInnerAddr
    {
        ReplyInnerAddr()
        : m_pThis(nullptr)
        , m_pfc(nullptr)
        {
        }

        ReplyInnerAddr(obj* pThis, replycallback pfc)
        : m_pThis(pThis)
        , m_pfc(pfc)
        {
        }

        obj* m_pThis;
        replycallback m_pfc;
    };

    ReplyInnerAddr m_cReplyInnerAddr;
};

template<typename obj>
boost::shared_ptr<EV_ReplyFuncBase> ReplyCBBind(obj* pc, void (obj::*replycallback)(const EventContext& evcontext, const bufMsgPtr pMsg))
{
    boost::shared_ptr<EV_ReplyFuncBase> spfb = boost::shared_ptr<EV_ReplyFuncBase>(new EV_ReplyFunc<obj>(pc, replycallback));
    return spfb;
}

class FuncWrapperBase
{
public:
    virtual ~FuncWrapperBase() {}
};

template<typename FUNCCLS>
class FuncWrapper : public FuncWrapperBase
{
public:
    FuncWrapper(FUNCCLS * pFunc)
    {
        m_pfunc = pFunc;
    }
    virtual ~FuncWrapper()
    {
        if (nullptr != m_pfunc)
        {
            delete m_pfunc;
        }
    }
    FUNCCLS * m_pfunc;
};

class EventContext
{
public:
    EventContext();
    EventContext(const EventContext& context);
    EventContext& operator=(const EventContext& context);
    ~EventContext();

    void SetStringData(const std::string &str);
    std::string GetStringData() const;
    bool AddNewFuncObjPtr(void* pFunction);
    const void* PeekFuncObjPtr() const;

    friend class EV_Socket;
    friend class SocketImpl_ZMQ;

public:
    int64_t                             m_fromModuleId;
    int64_t                             m_desModuleId;
    signed int                          m_proxyFlag;
    boost::shared_ptr<EV_ReplyFuncBase> m_spReplyCBFunc;

private:
    enum {
        reservedsize = 256
    };

    class DumpCBCLS
    {
    public:
        void func(const EventContext& evcontext, bufMsgPtr pMsg) {}
    };

    struct FunctionObj
    {
        void * pRawFuncObj;
        int refCnt;
    };

    friend class EV_Socket;
    void SetReservedData(std::string str);
    std::string GetReservedData() const;
    std::string Seriallize() const;
    bool Deseriallize(const char* str, int size);

    FunctionObj* m_pFunctionObj;
    std::string  m_extenddata;
};

#endif // EVENTS_CONTEXT

