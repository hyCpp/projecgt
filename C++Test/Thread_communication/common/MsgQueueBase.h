#ifndef MSGQUEUEBASE_H
#define MSGQUEUEBASE_H
#include<string>

typedef struct {
    unsigned int msg_code;
    void *p_message;
} Elements;

class MsgQueueBase
{
public:
    MsgQueueBase(const std::string pName = NULL);
    virtual ~MsgQueueBase();

    virtual bool recvMsg(unsigned int &code, void* &msg) = 0;
    virtual bool sendMsg(unsigned int code, void* msg) = 0;

    std::string getName();

private:
    std::string m_Queue_Name;
};

#endif // MSGQUEUEBASE_H
