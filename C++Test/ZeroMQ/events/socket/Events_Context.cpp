#include "Events_Context.h"
#include <stdio.h>

EventContext::EventContext()
    : m_fromModuleId(0)
    , m_desModuleId(0)
    , m_proxyFlag(0)
    , m_pFunctionObj(nullptr)
    , m_extenddata("")
{
}

EventContext::EventContext(const EventContext& context)
{
    *this = context;
}

EventContext& EventContext::operator=(const EventContext& context)
{
    if (NULL != context.m_pFunctionObj) {
        __sync_fetch_and_add(&(context.m_pFunctionObj->refCnt), 1);
    }
    m_fromModuleId = context.m_fromModuleId;
    m_desModuleId = context.m_desModuleId;
    m_proxyFlag = context.m_proxyFlag;
    m_spReplyCBFunc = context.m_spReplyCBFunc;
    m_pFunctionObj = context.m_pFunctionObj;
    m_extenddata = context.m_extenddata;
    return *this;
}

EventContext::~EventContext()
{
    if (NULL != m_pFunctionObj) {
        __sync_fetch_and_add(&(m_pFunctionObj->refCnt), -1);

        if (0 >= m_pFunctionObj->refCnt) {
            if (NULL != m_pFunctionObj->pRawFuncObj) {
                FuncWrapperBase * pObj = (FuncWrapperBase *)(m_pFunctionObj->pRawFuncObj);
                delete pObj;
                m_pFunctionObj->pRawFuncObj = nullptr;
            }
            delete m_pFunctionObj;
            m_pFunctionObj = nullptr;
        }
    }
}

void EventContext::SetStringData(const std::string &str)
{
    std::string tmpextenddata;
    const char * data = m_extenddata.data();
    int size = m_extenddata.size();
    if (size >= reservedsize)
    {
        tmpextenddata.assign(data, reservedsize);
    }
    else
    {
        char sztembuf[reservedsize];
        memset(sztembuf, 'X', reservedsize);
        tmpextenddata.assign(sztembuf, reservedsize);
    }
    tmpextenddata.append(str);
    m_extenddata = tmpextenddata;
}

std::string EventContext::GetStringData() const
{
    int size = m_extenddata.size();
    if (size >= reservedsize) {
        return m_extenddata.substr(reservedsize, size - reservedsize);
    }
    else {
        return std::string("");
    }
}

bool EventContext::AddNewFuncObjPtr(void* pFunction)
{
    if (nullptr == m_pFunctionObj && nullptr != pFunction) {
        m_pFunctionObj = new FunctionObj();
        m_pFunctionObj->pRawFuncObj = pFunction;
        m_pFunctionObj->refCnt = 1;
        return true;
    }
    else {
        return false;
    }
}

const void* EventContext::PeekFuncObjPtr() const
{
    if (nullptr != m_pFunctionObj) {
        return m_pFunctionObj->pRawFuncObj;
    }
    else {
        return nullptr;
    }
}

void EventContext::SetReservedData(std::string str)
{
    std::string userdata = GetStringData();
    char szReversed[reservedsize];
    memset(szReversed, 0, reservedsize);
    strncpy(szReversed, str.data(), reservedsize);
    m_extenddata.assign(szReversed, reservedsize);
    m_extenddata.append(userdata);
}

std::string EventContext::GetReservedData() const
{
    int exsize = m_extenddata.size();
    if (exsize >= reservedsize) {
        return m_extenddata.substr(0, reservedsize);
    }
    else
    {
        return std::string("");
    }
}

std::string EventContext::Seriallize() const
{
    std::string SeriallizeString;

    if (nullptr != m_pFunctionObj && nullptr != m_pFunctionObj->pRawFuncObj) {
        if (1 == m_proxyFlag) {
            printf("EV_EventContext::Seriallize Error (pFunctionObj cannot send to proxy)!\n");
        }

        int iModuleCnt = 0;
        int64_t destMId = m_desModuleId;
        for (int i = 0; i < 64; ++i) {
            iModuleCnt += 0x0000000000000001 & destMId;
            destMId = destMId > 1;
        }
        if (1 < iModuleCnt) {
            printf("EV_EventContext::Seriallize Error (desModuleId > 1)!\n");
        }
    }

    int ModuleIDSize = sizeof(int64_t);
    int ProxyFlagSize = sizeof(int);
    int CallBackSize = sizeof(EV_ReplyFunc<DumpCBCLS>::ReplyInnerAddr);
    int FunctionObjAddrSize = sizeof(FunctionObj*);
    int UserDataSize = m_extenddata.size();
    int size = ModuleIDSize * 2 + ProxyFlagSize + UserDataSize + CallBackSize + FunctionObjAddrSize;

    char* pData = new char[size];
    if (nullptr != pData)
    {
        char * temppData = pData;
        memcpy(temppData, &m_fromModuleId, ModuleIDSize);
        memcpy(temppData += ModuleIDSize, &m_desModuleId, ModuleIDSize);
        memcpy(temppData += ModuleIDSize, &m_proxyFlag, ProxyFlagSize);
        memcpy(temppData += ProxyFlagSize, m_spReplyCBFunc->GetReplyInnerAddr(), CallBackSize);

        memcpy(temppData += CallBackSize, &m_pFunctionObj, FunctionObjAddrSize);

        if (nullptr != m_pFunctionObj && nullptr != m_pFunctionObj->pRawFuncObj) {
            __sync_fetch_and_add(&(m_pFunctionObj->refCnt), 1);
        }

        memcpy(temppData += FunctionObjAddrSize, m_extenddata.data(), UserDataSize);

        SeriallizeString.append(pData, size);
        delete[] pData;
    }

    return SeriallizeString;
}

bool EventContext::Deseriallize(const char *str, int size)
{
    int ModuleIDSize = sizeof(int64_t);
    int ProxyFlagSize = sizeof(int);
    int CallBackSize = sizeof(EV_ReplyFunc<DumpCBCLS>::ReplyInnerAddr);
    int FunctionObjAddrSize = sizeof(FunctionObj*);
    int UserDataSize = size - ModuleIDSize*2 - ProxyFlagSize - CallBackSize - FunctionObjAddrSize;
    if (UserDataSize<0) {
        return false;
    }

    m_fromModuleId = *reinterpret_cast<const int64_t*>(str);
    m_desModuleId = *reinterpret_cast<const int64_t*>(str += ModuleIDSize);
    m_proxyFlag = *reinterpret_cast<const int*>(str += ModuleIDSize);
    EV_ReplyFuncBase* pfb = new EV_ReplyFunc<DumpCBCLS>;
    memcpy(pfb->GetReplyInnerAddr(), str += ProxyFlagSize, CallBackSize);

    memcpy(&m_pFunctionObj, str += CallBackSize, FunctionObjAddrSize);
    if (NULL != m_pFunctionObj && NULL != m_pFunctionObj->pRawFuncObj) {
        __sync_fetch_and_add(&(m_pFunctionObj->refCnt), -1);
    }

    m_spReplyCBFunc = boost::shared_ptr<EV_ReplyFuncBase>(pfb);
    const char* pUserData = reinterpret_cast<const char*>(str += FunctionObjAddrSize);
    m_extenddata.assign(pUserData, UserDataSize);

    return true;
}
