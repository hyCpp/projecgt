#ifndef OA_CENTER
#define OA_CENTER

#include "CurlHttp.h"
#include "NGVUIXMLStrParse.h"
#include <memory>
#include <map>
using namespace std;
struct OverTimeData
{
    string beginTime;
    string endTime;
    string beginDate;
    string endDate;
    string overtime;
};

struct DateInfo
{
    int year;
    int month;
    int day;
};

class OA_Center
{
public:
    typedef map<string, string> OaMap;
    typedef vector<OverTimeData> OvertimeDataVec;
    OA_Center();
    ~OA_Center();
    int Login(const string& user, const string& pwd);
    int EmployeeInfo();
    int OvertimeApply(const string& reason);

private:
    OA_Center(const OA_Center&);
    OA_Center& operator = (const OA_Center&);
    void displayTable(const string &table);
    void timeOperation(const OverTimeData& data);
    void OvertimeInfo(const OvertimeDataVec& overTime);
    int OverTimeCount(const vector<int>& begin, const vector<int>& end);
    int OverTimeCountOfWeek(const vector<int>& begin, const vector<int>& end);
    int isHoliday(const std::string& str);
    string FormatTime(const string& time, bool flag);

    void dataClear();
    vector<string> split(const string& str, const string& delim);
    string splits(const string& str, const string& delim);

    bool isLeapYear(int year);
public:
    string NextDay(const std::string& str);

private:
    string cookies;
    shared_ptr<CurlHttp> m_spCurlHttp;
    shared_ptr<OaMap> m_spHeaderList;
    shared_ptr<string> m_spResponseData;
    int m_overTimeCount;

    OaMap m_UrlBody;
    OvertimeDataVec m_Overtime;
};

#endif // OA_CENTER

