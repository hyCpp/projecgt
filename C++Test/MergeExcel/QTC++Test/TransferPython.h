#ifndef TRANSFERPYTHON_H
#define TRANSFERPYTHON_H
#include<iostream>
#include<QObject>
using namespace std;

class TransferPython : public QObject
{
    Q_OBJECT
public:
    TransferPython();
    bool transferPythonToMsg();
public slots:
    void setAfterAndBefore(const QString &After, const QString &Before);

signals:
    void notifyServiceMergeMsg(const std::string& msg);

private:
    string m_after;
    string m_Before;
};

#endif // TRANSFERPYTHON_H
