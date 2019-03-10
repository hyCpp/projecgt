#ifndef COMMUNICATIONCLASS_H
#define COMMUNICATIONCLASS_H
#include"Service.h"
#include<QObject>
#include"TransferPython.h"

class TransferPython;
class Service;

class CommunicationClass : QObject
{
    Q_OBJECT
public:
    CommunicationClass();
    ~CommunicationClass();

    static void QSignalSlotsBindService(Service* s_p);
};

#endif // COMMUNICATIONCLASS_H
