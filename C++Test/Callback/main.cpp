#include "Signal.h"
#include "../LogConfig/Log_Func.cpp"
#include <string>

class receiver
{
public:
    void callback(std::string a, int n)
    {
        LOGD("receiver : %s %d", a.c_str(), n);
    }
};

class receiver1
{
public:
    void callback1(std::string a, int n)
    {
        LOGD("receiver1 : %s %d", a.c_str(), n);
    }
};

class sender
{
public:
    sender(): m_value("") , m_num(0)  {}
    std::string get_value()
    {
        return m_value;
    }

    int get_num()
    {
        return m_num;
    }

    void set_value(std::string new_value, int n)
    {
        if (new_value!=m_value)
        {
            m_value = new_value;
            m_num = n;
            m_valueChanged(new_value, n);
        }
    }

    Signal<std::string, int> m_valueChanged;

private:
    std::string m_value;
    int m_num;
};

int main()
{
    TC_Log::setLogStatus(true);
    receiver r;
    receiver1 r2;
    sender s;

    CONNECT(s, m_valueChanged, &r , &receiver::callback);
    CONNECT(s, m_valueChanged, &r2, &receiver1::callback1);
    s.set_value("test", 10);

    return 0;
}
