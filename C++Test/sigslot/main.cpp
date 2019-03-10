#include "../LogConfig/Log_Func.cpp"
#include <string>
#include "sigslot.h"

class receiver
{
public:
    void callback(std::string a)
    {
        LOGD("receiver : %s", a.c_str());
    }
};

class receiver1
{
public:
    void callback1(std::string a)
    {
        LOGD("receiver1 : %s", a.c_str());
    }
};

class sender
{
public:
    sender(): m_value("")  {}
    std::string get_value()
    {
        return m_value;
    }
    void set_value(std::string new_value)
    {
        if (new_value!=m_value)
        {
            m_value = new_value;
            m_valueChanged(new_value);

            while(1);
        }
    }

    signal<std::string> m_valueChanged;

private:
    std::string m_value;
};

int main()
{
    TC_Log::setLogStatus(true);
    receiver r;
    receiver1 r2;
    sender s;

    sigslot::connect(s, m_valueChanged, &r , &receiver::callback);
    CONNECT(s, m_valueChanged, &r2, &receiver1::callback1);
    s.set_value("test");

    return 0;
}

