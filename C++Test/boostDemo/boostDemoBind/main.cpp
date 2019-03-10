#include "boostDemoBindList.h"
#include"boostBindDemo.h"
#include "boostBindDemoDefind.h"
#include<string>

using namespace std;

int main()
{
    boostBindDemo *test = new boostBindDemo;
    boostDemoBindList *list = new boostDemoBindList();
    list->setBoostDemoFunc(boostDemo_printFunc_Demo2);
    std::string str = " only by test";
    test->selectPrintDemo(str, list);
}
