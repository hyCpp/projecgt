#ifndef BOOSTBINDDEMO_H
#define BOOSTBINDDEMO_H
#include "boostDemoBindList.h"
#include "boostBindDemoDefind.h"
#include<string>
#include<map>
using namespace std;

class boostBindDemo
{
public:
    boostBindDemo();
    ~boostBindDemo();

    void selectPrintDemo(std::string &str, boostDemoBindList *list);
    void printDemo1(std::string &str, boostDemoBindList *list);
    void printDemo2(std::string &str, boostDemoBindList *list);
    void printDemo3(std::string &str, boostDemoBindList *list);
    void printDemo4(std::string &str, boostDemoBindList *list);
    void printDemo5(std::string &str, boostDemoBindList *list);

private:
    typedef void (boostBindDemo::*RespEventFunc)(std::string &str, boostDemoBindList *list);
    typedef std::map<boostDemo::boostDemo_printFunc, RespEventFunc> VrMMFuncMAP;
    VrMMFuncMAP m_VrMMFuncMap;
};

#endif // BOOSTBINDDEMO_H
