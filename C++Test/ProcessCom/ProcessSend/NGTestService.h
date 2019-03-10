#ifndef NGTESTSERVICE
#define NGTESTSERVICE
#include <stdio.h>
#include <string>

struct MsgData
{
    long int msgType;
    char msgText[BUFSIZ];
};

class NGTestService
{

public:
    NGTestService();
    ~NGTestService();

    void onInit();
    void sendMsg();

private:
    MsgData m_msgData;
    int m_msgId;
    char m_buffer[BUFSIZ];
};

#endif // NGTESTSERVICE

