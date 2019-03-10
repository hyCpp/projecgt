#include"CommunicationClass.h"

CommunicationClass::CommunicationClass()
{

}

CommunicationClass::~CommunicationClass()
{

}

void CommunicationClass::QSignalSlotsBindService(Service *s_p)
{
    TransferPython* tf = new TransferPython();
    connect(s_p, SIGNAL(notifyPythonClass(const QString &, const QString &)),
            tf, SLOT(setAfterAndBefore(const QString &, const QString &)));
    connect(tf, SIGNAL(notifyServiceMergeMsg(const std::string&)),
            s_p, SLOT(acceptTransferPythonMsgIsFinished(const std::string&)));
    connect(tf, SIGNAL(notifyServiceMergeMsg(const std::string&)),
            s_p, SLOT(acceptTransferPythonMsgIsError(const std::string&)));
}

