#ifndef OBSERVER_H
#define OBSERVER_H
#include <string>

using namespace std;
class Subject;

class Observer
{
public:
    Observer(std::string name, Subject* pSub);
    ~Observer();

    virtual void Update() = 0;

protected:
    std::string m_Name;
    Subject* p_Sub;
};

#endif // OBSERVER_H
