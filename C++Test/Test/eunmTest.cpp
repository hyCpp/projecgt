#include "test.h"
#include <iostream>
//#include<QVariant>
//#include<QList>
//#include<QMap>
#include<string>
#include<stdlib.h>
#include <sstream>
#include <unistd.h>
#include <boost/format.hpp>
#include <vector>
#include <string.h>
#include <list>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node()
        : data(0)
        , next(NULL)
    {
    }
};

int count =0;

Node* createLink(Node* node)
{
    for (int i = 0; i < 5; ++i) {
        Node* ptr = (Node *)malloc(sizeof(Node));
        ptr->data = i;
        ptr->next = node;
        node = ptr;
    }
    return node;
}

void display(Node* node)
{
    while (node != NULL) {
        printf("%d\n",node->data);
        node = node->next;
    }
}

Node* reverse(Node* node)
{
    Node* temp;
    Node* newNode ;
    if (node == NULL || node->next == NULL) {
        printf("-------------------------------- \n");
        return node;
    }

    temp = node->next;

    printf("after_node->data = %d\n", node->next->data);

    newNode = reverse(temp); //reverse(node->next->next->next->next->next) newNode->data = 0

    temp->next = node;
    printf("after_node->data = %d\n", node->next->data);
    node->next = NULL;

    return newNode;
}

Node* reverse1(Node *node)
{
    Node* temp;
    Node* newNode;

    newNode->data = node->data;

    while (node->next != NULL) {
        temp = node;

        newNode->next = temp->next;
        temp = newNode->next;
        node = node->next;
    }

    return newNode;
}

const static std::string sessionStateChanged = "<event name=\"sessionStateChanged\">"
                                                  "<state>%1%</state>"
                                              "</event>";

typedef void (*TestFuncPtr)(char* str);

void ConcreteTestFuncPtr(char* str)
{
    printf("ptr = %s\n", str);
}

TestFuncPtr testFunc = &ConcreteTestFuncPtr;

void notifyMsgCome1(const std::string& str)
{

    (*testFunc)(const_cast<char*>(str.c_str()));
}

class FuncPtr
{
public:
    FuncPtr(){
        m_TestFuncPtr = ConcreteTestFuncPtr;
    }
    ~FuncPtr(){}

    void notifyMsgCome(const std::string& str)
    {
        if (m_TestFuncPtr != NULL) {
            (*m_TestFuncPtr)(const_cast<char*>(str.c_str()));
        }
        else {
            printf("m_TestFuncPtr is NULL!\n");
        }
    }

private:
    TestFuncPtr m_TestFuncPtr;
};

void splitHighItemNumber(const std::string &str, std::vector<int> &list)
{
    char* temp = new char[strlen(str.c_str()) + 1];
    strcpy(temp, str.c_str());

    const char* split = ",";
    char* ptr = strtok(temp, split);

    while(ptr != NULL) {
        std::string toInt(ptr);
        list.push_back(atoi(toInt.c_str()));
        ptr = strtok(NULL, split);
    }

    delete[] temp;
    temp = NULL;
}

std::string ConvertToString(double value)
{
    char str[255] = { 0 };
    sprintf(str, "%f", value);
    return std::string(str);
}

std::string transferLonAndLat(const std::string& value)
{
    int temp = atof(value.c_str()) * 60 * 60 * 256;
    return std::to_string(temp);
}

int main () {

//    FuncPtr func;
//    std::string test = "testFuncPtr";
//    func.notifyMsgCome(test);

//    notifyMsgCome1(test);


//    std::string sdlXml = "<event name = \"dynamiccommand\">";

//    for (int i = 0; i < test.size(); ++i) {
//        std::string  data = test.at(i);
//        stringstream  ss;
//        std::string intTransferString;
//        ss << i;
//        ss >> intTransferString;
//        std::string temp = "<dynamic id = \""+intTransferString+"\" name = \""+data+"\"/>";
//        sdlXml+=temp;
//    }

//    sdlXml = sdlXml + "</event>";

//    std::cout<<sdlXml<<std::endl;


//    QList<QVariant> list;

//    for (int i = 0; i < 10; ++i) {
//        list.append("Demo");
//    }

//    int n;
//    char buf[3];
//    n = read(0,buf,sizeof(buf));

//    if(3 == n && buf[0] == 27 && buf[1] == 91)
//    {
//        printf("3 == n && buf[0] == 27 && buf[1] == 91        buf = %d\n", buf[2]);
//    }
//    else if(1 == n)
//    {
//        printf("1 == n       buf = %d\n", buf[0]);
//    }
//            printf("n = %d\n", n);
//            printf("buf[0] = %d\n", buf[0]);
//            printf("buf[1] = %d\n", buf[1]);
//            printf("buf[2] = %d\n", buf[2]);

//    Node* node =  NULL;
//    node = createLink(node);
//    display(node);

//    const std::string str = (boost::format (sessionStateChanged) % "off").str().c_str();
//    std::cout<<str<<std::endl;

//    node = reverse(node);
//    display(node);
//    node = reverse1(node);
//    display(node);



//    std::string item = "4,5,s,6,7";
//    std::vector<int> test;
//    splitHighItemNumber(item, test);

//    printf("test.size = [%d]\n", test.size());

//    for(int i = 0; i < test.size(); ++i) {
//        printf("high = [%d]\n", test.at(i));
//    }


//    std::cout<< ConvertToString(double(atoi(transferLonAndLat("121.214119").c_str())) / 921600) <<std::endl;


    std::list<int> target;

    for (int i = 13; i > 0; --i) {
        if (!target.empty()) {
            std::list<int>::const_reference iter = target.front();
            target.pop_front();
            target.push_back(iter);
        }
        target.push_back(i);
    }

    for (int i : target) {
        std::cout<< i << " ";
    }
    std::cout<<std::endl;

    while (!target.empty()) {
        std::cout<< "input : " << target.back() << std::endl;
        target.pop_back();
        if (target.empty()) {
            break;
        }

        std::list<int>::const_reference iter = target.back();
        target.pop_back();
        target.push_front(iter);
    }
}

