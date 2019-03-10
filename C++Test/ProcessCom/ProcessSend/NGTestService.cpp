#include "NGTestService.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <errno.h>
#include "../../LogConfig/Log_Func.h"
#include "NGTestDef.h"
#include <string.h>

NGTestService::NGTestService()
    : m_msgId(-1)
{

}

NGTestService::~NGTestService()
{

}

void NGTestService::onInit()
{
    m_msgId = msgget((key_t)1234, 0666 | IPC_CREAT);

    if (m_msgId == -1) {
        TCLOGD("msgget create is failed!");
        exit(EXIT_FAILURE);
    }
}

void NGTestService::sendMsg()
{
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("1: NaviShowList                2: ToDesnation\n");
    printf("3: viaPoint                    4: play Local \n");
    printf("5: Media setStatus             6: play Online\n");
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");

    while(true)
    {
        m_msgData.msgType = 1;
        fgets(m_buffer, BUFSIZ, stdin);
        strcpy(m_msgData.msgText, m_buffer);
        printf("buffer = [%s]", m_buffer);

        if(msgsnd(m_msgId, (void*)&m_msgData, BUFSIZ, 0) == -1)
        {
            printf("msgrcv create is failed!");
            exit(EXIT_FAILURE);
        }

        sleep(1);
    }

    exit(EXIT_SUCCESS);
}

/* EOF */


