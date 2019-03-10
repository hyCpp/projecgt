#ifndef PRINTFLOG_H
#define PRINTFLOG_H

class PrintLog
{
public:
    PrintLog();

    void outPut(char* formatstr, ...);
    static void setLogStatus(bool bStatus);
    static bool getLogStatus();

private:
    static bool m_bLogStatus;
    const char* m_tag;
    const char* m_func;
};

#endif // PRINTFLOG_H
