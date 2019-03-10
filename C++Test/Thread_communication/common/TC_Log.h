#ifndef TC_LOG_H
#define TC_LOG_H
#define LOG_MAX_LENGTH 256

class TC_Log
{
public:
    TC_Log();
    ~TC_Log();
    void output(char* formatStr, ...);
    static void setLogStatus(bool status);
    static bool getLogStatus();

private:
    TC_Log(const TC_Log& x);
    TC_Log& operator = (const TC_Log& x);

    static bool m_bLogStatus;
};

#endif // TC_LOG_H
