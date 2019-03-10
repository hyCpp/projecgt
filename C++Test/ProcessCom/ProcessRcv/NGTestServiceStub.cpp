#include "NGTestServiceStub.h"
#include <errno.h>
#include <sys/msg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../LogConfig/Log_Func.h"
#include "NGTestDef.h"
#include <pthread.h>

NGTestServiceStub::NGTestServiceStub()
    : m_msgId(-1)
    , m_flag(true)
{
    m_thread = new NGTestThread;
    m_perform = new NGTestPerform;
}

NGTestServiceStub::~NGTestServiceStub()
{

    if (m_thread != nullptr) {
        delete m_thread;
        m_thread = nullptr;
    }

    if (m_perform != nullptr) {
        delete m_perform;
        m_perform = nullptr;
    }
}


void NGTestServiceStub::onInit()
{
    LOGD_FUNC();

    m_msgId = msgget((key_t)1234, 0666 | IPC_CREAT);

    if (m_msgId == -1) {
        TCLOGD("msgget create is failed!");
        exit(EXIT_FAILURE);
    }

    if (!m_thread->createThread(this)) {
        TCLOGD("create Thread fail!");
    }

    if (!m_perform->createThread(this)) {
        TCLOGD("create Thread fail!");
    }
}

void NGTestServiceStub::receiveMsg()
{
    LOGD_FUNC();

    while (true) {
        if (msgrcv(m_msgId, (void*)&m_msgData, BUFSIZ, 0, 0) == -1) {
            TCLOGD("msgrcv create is failed!");
            exit(EXIT_FAILURE);
        }

        int n = atoi(m_msgData.msgText);
        selectData(n);
    }

}

void NGTestServiceStub::onDeInit()
{
    if (msgctl(m_msgId, IPC_RMID, 0) == -1) {
        TCLOGD("msgrcv destory is failed!");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}

bool NGTestServiceStub::selectData(int n)
{
    LOGD_FUNC();
    std::string result;

    switch (n) {
    case 1:
        result = "FC_VUI_TEST_SHOWLIST";
        break;
    case 2:
        result = "FC_VUI_TEST_NAVI_TODESTINATION";
        break;
    case 3:
        result = "FC_VUI_TEST_NAVI_VIAPOINT";
        break;
    case 4:
        result = "FC_VUI_TEST_MEDIA_LOCAL";
        break;
    case 5:
        result = "FC_VUI_TEST_MEDIA_SETSTATUS";
        break;
    case 6:
        result = "FC_VUI_TEST_MEDIA_PLAYONLINE";
        break;
    default:
        break;
    }

    m_queue.push(result);
    LOGD("m_queue.size = [%d]", m_queue.size());

    Post();
}

void NGTestServiceStub::Run()
{
    LOGD_FUNC();

    while(true) {
        if (m_queue.empty()) {
            TCLOGD("queue is empty");
            Wait();
        }

        TCLOGD("--------------1--------------");

        std::string sp = m_queue.front();
        m_queue.pop();

        TCLOGD("--------------2--------------");

        if (sp.compare("") != 0) {
            m_replier->recv(sp);
        }
    }
}

void NGTestServiceStub::Wait()
{
    while(1) {
        if (!m_flag) {
            m_flag = true;
            break;
        }
    }
}

void NGTestServiceStub::Post()
{
    m_flag = false;
}
