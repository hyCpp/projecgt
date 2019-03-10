#include "boostBindDemo.h"
#include "boostBindDemoDefind.h"
#include "boost/bind.hpp"
#include "boost/function.hpp"
#include "boost/assign/list_of.hpp"
#include <iostream>
#include <map>

using namespace std;

/** this is frist method*/
typedef void (boostBindDemo::*RespEventFunc1)(std::string &str, boostDemoBindList *list);
const std::map<boostDemo::boostDemo_printFunc, RespEventFunc1>::value_type map_init_data[] =
{
    std::map<boostDemo::boostDemo_printFunc, RespEventFunc1>::value_type(boostDemo::boostDemo_printFunc_Demo1, &boostBindDemo::printDemo1),
    std::map<boostDemo::boostDemo_printFunc, RespEventFunc1>::value_type(boostDemo::boostDemo_printFunc_Demo2, &boostBindDemo::printDemo2),
    std::map<boostDemo::boostDemo_printFunc, RespEventFunc1>::value_type(boostDemo::boostDemo_printFunc_Demo3, &boostBindDemo::printDemo3),
    std::map<boostDemo::boostDemo_printFunc, RespEventFunc1>::value_type(boostDemo::boostDemo_printFunc_Demo4, &boostBindDemo::printDemo4),
    std::map<boostDemo::boostDemo_printFunc, RespEventFunc1>::value_type(boostDemo::boostDemo_printFunc_Demo5, &boostBindDemo::printDemo5)
};
const static std::map<boostDemo::boostDemo_printFunc, RespEventFunc1> VrMMDemoMap(map_init_data, map_init_data + 5);

/** this is third method*/
typedef void (boostBindDemo::*selectBindDemo)(std::string &str, boostDemoBindList *list);
typedef boost::function<void(std::string &str, boostDemoBindList *ist)> FuncBindDemo;

static const std::map<boostDemo::boostDemo_printFunc, selectBindDemo> boostDemoFunc =
        boost::assign::map_list_of
        (boostDemo::boostDemo_printFunc_Demo1, &boostBindDemo::printDemo1)
        (boostDemo::boostDemo_printFunc_Demo2, &boostBindDemo::printDemo2)
        (boostDemo::boostDemo_printFunc_Demo3, &boostBindDemo::printDemo3)
        (boostDemo::boostDemo_printFunc_Demo4, &boostBindDemo::printDemo4)
        (boostDemo::boostDemo_printFunc_Demo5, &boostBindDemo::printDemo5);

boostBindDemo::boostBindDemo()
{
    /** this is second method*/
    m_VrMMFuncMap[boostDemo::boostDemo_printFunc_Demo1] = &boostBindDemo::printDemo1;
    m_VrMMFuncMap[boostDemo::boostDemo_printFunc_Demo2] = &boostBindDemo::printDemo2;
    m_VrMMFuncMap[boostDemo::boostDemo_printFunc_Demo3] = &boostBindDemo::printDemo3;
    m_VrMMFuncMap[boostDemo::boostDemo_printFunc_Demo4] = &boostBindDemo::printDemo4;
    m_VrMMFuncMap[boostDemo::boostDemo_printFunc_Demo5] = &boostBindDemo::printDemo5;
}

boostBindDemo::~boostBindDemo()
{

}

void boostBindDemo::selectPrintDemo(string &str, boostDemoBindList *list)
{
    boostDemo::boostDemo_printFunc funcCode;
    funcCode = list->getBoostDemoFunc();

    /** this is frist method*/
//    std::map<boostDemo::boostDemo_printFunc, selectBindDemo>::const_iterator it
//            = boostDemoFunc.find(funcCode);

//    if (it != boostDemoFunc.end()) {
//        FuncBindDemo func;
//        func = boost::bind(it->second, this , _1, _2);
//        func(str, list);
//    }

    /** this is second method*/
//    RespEventFunc func = m_VrMMFuncMap[funcCode];
//    boostBindDemo boostDemo;
//    (boostDemo.*func)(str, list);

    /** this is third method*/
    std::map<boostDemo::boostDemo_printFunc, selectBindDemo>::const_iterator it
            = VrMMDemoMap.find(funcCode);

    if (it != boostDemoFunc.end()) {
        RespEventFunc1 func = it->second;
        boostBindDemo* boostDemo;
        (boostDemo->*func)(str, list);
    }
}

void boostBindDemo::printDemo1(std::string &str, boostDemoBindList* list)
{
    std::cout<<"this is Demo one"<<str<<std::endl;
}

void boostBindDemo::printDemo2(std::string &str, boostDemoBindList *list)
{
    std::cout<<"this is Demo two"<<str<<std::endl;
    list->printfLSomething();
}

void boostBindDemo::printDemo3(std::string &str, boostDemoBindList *list)
{
    std::cout<<"this is Demo three"<<str<<std::endl;
}

void boostBindDemo::printDemo4(std::string &str, boostDemoBindList *list)
{
    std::cout<<"this is Demo four"<<str<<std::endl;
}

void boostBindDemo::printDemo5(std::string &str, boostDemoBindList *list)
{
    std::cout<<"this is Demo five"<<str<<std::endl;
}
