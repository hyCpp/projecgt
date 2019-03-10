#include "OA_Center.h"
#include "json/json.h"
#include <unistd.h>

const string EmployeeInfoUrl = "http://oa-center/Programs/KQ/EmployeeInfoStatistic.aspx";
const string oaUrl = "http://oa-center/Programs/login/login.aspx";
const string EmployeeReqUrl = "http://oa-center/Programs/KQ/EmployeeRequestOvertime.aspx";
const string holidayUrl = "http://api.goseek.cn/Tools/holiday?date=";

OA_Center::OA_Center()
    : cookies("")
    , m_spCurlHttp(new CurlHttp)
    , m_spHeaderList(new OaMap)
    , m_spResponseData(new string)
    , m_overTimeCount(0)
{
}

OA_Center::~OA_Center()
{

}

int OA_Center::Login(const std::string& user, const std::string& pwd)
{
    dataClear();
    m_spCurlHttp->setDebug(false);
    m_spHeaderList->insert(make_pair("Accept", "text/html,application/xhtml+xm…plication/xml;q=0.9,*/*;q=0.8"));
    m_spHeaderList->insert(make_pair("Accept-Encoding", "gzip, deflate"));
    m_spHeaderList->insert(make_pair("Accept-Language", "zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2"));
    m_spHeaderList->insert(make_pair("Cache-Control", "max-age=0"));
    m_spHeaderList->insert(make_pair("Connection", "keep-alive"));
    m_spHeaderList->insert(make_pair("Content-Type", "application/x-www-form-urlencoded"));
    m_spHeaderList->insert(make_pair("Referer", oaUrl));
    m_spHeaderList->insert(make_pair("Host", "oa-center"));
    m_spHeaderList->insert(make_pair("Upgrade-Insecure-Requests", "1"));
    m_spHeaderList->insert(make_pair("User-Agent", "Mozilla/5.0 (Windows NT 6.1; W…) Gecko/20100101 Firefox/57.0"));
    int code = m_spCurlHttp->GetHttp(oaUrl, m_spHeaderList.get(), nullptr, m_spResponseData.get());
    if (code != 0) {
        return code;
    }
    m_spCurlHttp->getHtmlInputInfo(*(m_spResponseData.get()), m_UrlBody);
    m_UrlBody["tbPassword"] = pwd;
    m_UrlBody["tbUserName"] = user;

    m_spResponseData->clear();
    code = m_spCurlHttp->PostHttp(oaUrl, m_spHeaderList.get(), nullptr, m_spResponseData.get(), m_UrlBody, public_post);
    m_spCurlHttp->getCookies(*(m_spResponseData.get()), cookies);
    m_spHeaderList->insert(make_pair("Cookie", cookies.c_str()));
    (*(m_spHeaderList.get()))["Referer"] = EmployeeInfoUrl;

    if (code == 0) {
        printf("                =================================================  Login success  =============================================\n\n\n");
    }
    else {
        printf("                =================================================  Login failed   =============================================\n\n\n");
    }

    return code;
}

int OA_Center::EmployeeInfo()
{
    m_spResponseData->clear();
    m_UrlBody.clear();

    int code = m_spCurlHttp->GetHttp(EmployeeInfoUrl, m_spHeaderList.get(), nullptr, m_spResponseData.get());

    m_spCurlHttp->getHtmlInputInfo(*(m_spResponseData.get()), m_UrlBody);
    OaMap::const_iterator it;
    printf("%s\n", m_spResponseData.get()->c_str());
    for (it = m_UrlBody.begin(); it != m_UrlBody.end(); ++it) {
        printf("key = %s, value = %s \n", it->first.c_str(), it->second.c_str());
    }

    m_spResponseData->clear();
    m_UrlBody["TimeSelect"] = "RadioButtonPREV_MONTH";
    m_spCurlHttp->PostHttp(EmployeeInfoUrl, m_spHeaderList.get(), nullptr, m_spResponseData.get(), m_UrlBody, public_post);
    displayTable(*(m_spResponseData.get()));

    return code;
}

int OA_Center::OvertimeApply(const std::string& reason)
{
    int code;
    (*(m_spHeaderList.get()))["Referer"] = EmployeeReqUrl;
    m_spResponseData->clear();
    code = m_spCurlHttp->GetHttp(EmployeeReqUrl, m_spHeaderList.get(), nullptr, m_spResponseData.get());
    m_spCurlHttp->getHtmlInputInfo(*(m_spResponseData.get()), m_UrlBody);
    string __EVENTVALIDATION = m_UrlBody["__EVENTVALIDATION"];
    string __VIEWSTATE = m_UrlBody["__VIEWSTATE"];
    string __VIEWSTATEGENERATOR = m_UrlBody["__VIEWSTATEGENERATOR"];

    for (OverTimeData data : m_Overtime) {
        m_spResponseData->clear();
        code = m_spCurlHttp->GetHttp(EmployeeReqUrl, m_spHeaderList.get(), nullptr, m_spResponseData.get());
        m_spCurlHttp->getHtmlInputInfo(*(m_spResponseData.get()), m_UrlBody);
        OaMap map;
        map["__VIEWSTATE"] = __VIEWSTATE;
        map["__VIEWSTATEGENERATOR"] = __VIEWSTATEGENERATOR;
        map["__EVENTVALIDATION"] = __EVENTVALIDATION;
        map["TextBoxREASON"] = reason;
        map["TextBoxDATE_FROM"] = data.beginDate;
        map["DropDownListTIME_FROM"] = data.beginTime;
        map["TextBoxDATE_TO"] = data.endDate;
        map["DropDownListTIME_TO"] = data.endTime;
        map["btnAddLine"] = "添加明细";

        m_spResponseData->clear();
        code = m_spCurlHttp->PostHttp(EmployeeReqUrl, m_spHeaderList.get(), nullptr, m_spResponseData.get(), map, public_post);
        m_spCurlHttp->getHtmlInputInfo(*(m_spResponseData.get()), m_UrlBody);
        map.clear();
        map["__VIEWSTATEGENERATOR"] = m_UrlBody["__VIEWSTATEGENERATOR"];
        map["__VIEWSTATE"] = m_UrlBody["__VIEWSTATE"];
        map["__EVENTVALIDATION"] = m_UrlBody["__EVENTVALIDATION"];
        map["TextBoxREASON"] = reason;
        map["TextBoxDATE_FROM"] = data.beginDate;
        map["DropDownListTIME_FROM"] = data.beginTime;
        map["TextBoxDATE_TO"] = data.endDate;
        map["DropDownListTIME_TO"] = data.endTime;
        map["btnPost"] = "提交";
        code = m_spCurlHttp->PostHttp(EmployeeReqUrl, m_spHeaderList.get(), nullptr, m_spResponseData.get(), map, public_post);
        usleep(5000);
    }

    return code;
}


void OA_Center::displayTable(const std::string &table)
{
    if (!table.empty()) {
        std::string _table = m_spCurlHttp->getHtmlContentTransforXml(table, "<table", "</table>");
        if (!_table.empty()) {
            OvertimeDataVec overTimeVec;
            OverTimeData overTime;
            NGVUIXMLStrParse parse(_table);
            printf("=====================================================================考勤表=============================================================================\n\n");
            printf("       日期          星期          刷卡次数             出勤刷卡          离勤刷卡      迟到（分钟）      早退（分钟）       旷工（小时）         事由\n");
            XmlVector row = parse.GetXMLListNodeValue("//table/tr/td/span");
            for (size_t i = 0; i < row.size(); ++i) {

                printf("   %-15s", row.at(i).c_str());
                if (!((i + 1) % 9)) {
                    printf("\n");
                }
                else if (!(i % 9)) {
                    overTime.beginDate = row.at(i);
                }
                else if (!((i + 6) % 9)) {
                    overTime.beginTime = row.at(i);
                }
                else if (!((i + 5) % 9)) {
                    overTime.endTime = row.at(i);
                }
                if (!overTime.beginDate.empty() && !overTime.beginTime.empty()
                        && !overTime.endTime.empty()) {
                    overTimeVec.push_back(overTime);
                    overTime.beginDate.clear();
                    overTime.beginTime.clear();
                    overTime.endTime.clear();
                }
            }
            printf("\n==========================================================================================================================================================\n\n\n\n");
            OvertimeInfo(overTimeVec);
        }
    }
    printf("               ========================================加班详情===========================================\n\n");
    printf("                      开始日期          结束日期          开始时间       结束时间    加班总时间(分钟）   \n");
    for (OverTimeData data : m_Overtime) {
        printf("                     %s        %s          %s          %s          %s  \n", data.beginDate.c_str(),
               data.endDate.c_str(), data.beginTime.c_str(), data.endTime.c_str(), data.overtime.c_str());
    }
    printf("                                                                                        %0.2f(h)\n", m_overTimeCount / 60.0);
    printf("               ==========================================================================================\n\n");
}

void OA_Center::timeOperation(const OverTimeData& overTimedata)
{
    vector<int> vecBeginInt;
    vector<int> vecEndInt;
    OverTimeData data;

    for (string out : split(overTimedata.beginTime, ":")) {
        vecBeginInt.push_back(atoi(out.c_str()));
    }
    for (string out : split(overTimedata.endTime, ":")) {
        vecEndInt.push_back(atoi(out.c_str()));
    }
    if (vecEndInt.size() != 3 || vecBeginInt.size() != 3) {
        printf("time splie error!\n");
        return;
    }

    if (isHoliday(overTimedata.beginDate) == 0) {
        if (6 <= vecEndInt[0] && vecEndInt[0] < 18) {
            return;
        }
        if (vecEndInt[0] == 18 && vecEndInt[1] < 52) {
            return;
        }

        data.beginTime = "18:30";
        data.beginDate = overTimedata.beginDate;
        data.endDate = overTimedata.beginDate;
        data.endTime = FormatTime(overTimedata.endTime, true);

        if (vecEndInt[0] <= 5) {
            data.endDate = NextDay(data.beginDate).c_str();
        }

        if (!data.endTime.empty()) {
            data.overtime = std::to_string(OverTimeCount(vecBeginInt, vecEndInt));
            m_Overtime.push_back(data);
            data.endDate.clear();
            data.overtime.clear();
        }
    }
    else {
        data.endTime = FormatTime(overTimedata.endTime, true);
        data.beginTime = FormatTime(overTimedata.beginTime, false);
        data.endDate = overTimedata.beginDate;
        data.beginDate = overTimedata.beginDate;
        if (vecEndInt[0] <= 5) {
            data.endDate = NextDay(data.beginDate).c_str();
        }
        if (!data.endTime.empty()) {
            data.overtime = std::to_string(OverTimeCountOfWeek(vecBeginInt, vecEndInt));
            m_Overtime.push_back(data);
            data.endDate.clear();
            data.overtime.clear();
        }
    }
}

string OA_Center::FormatTime(const string &time, bool flag)
{
    string data;
    vector<int> vecEndInt;
    for (string out : split(time, ":")) {
        vecEndInt.push_back(atoi(out.c_str()));
    }

    if (vecEndInt.size() == 3) {
        int hour = vecEndInt[0];
        int mins = vecEndInt[1];

        if (hour < 10) {
            data.append("0");
        }

        if (flag) {
            if (mins < 30 ) {
                data.append(to_string(hour));
                data.append(":30");
            }
            else {
                data.append(to_string(hour + 1));
                data.append(":00");
            }
        }
        else {
            if (mins < 30 ) {
                data.append(to_string(hour));
                data.append(":00");
            }
            else {
                data.append(to_string(hour));
                data.append(":30");
            }
        }
    }

    return data;
}

int OA_Center::isHoliday(const std::string& str)
{
    string date = splits(str, "-");

    OaMap header;
    header.insert(make_pair("Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8"));
    header.insert(make_pair("Accept-Encoding", "gzip, deflate"));
    header.insert(make_pair("Accept-Language", "zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2"));
    header.insert(make_pair("Cache-Control", "max-age=0"));
    header.insert(make_pair("Connection", "keep-alive"));
    header.insert(make_pair("Host", "api.goseek.cn"));
    header.insert(make_pair("Referer", "http://api.goseek.cn/"));
    header.insert(make_pair("Upgrade-Insecure-Requests", "http://api.goseek.cn/"));

    string res;
    m_spCurlHttp->setHeader(false);
    m_spCurlHttp->PostHttp(holidayUrl + date, &header, nullptr, &res);
    m_spCurlHttp->setHeader(true);
    Json::Reader reader;
    Json::Value root;

    if (!reader.parse(res.c_str(), res.c_str() + strlen(res.c_str()), root)) {
        printf("json parse failed\n");
        return -1;
    }
    int data = root["data"].asInt();
    return data;
}

bool OA_Center::isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return true;
    }
    return false;
}

string OA_Center::NextDay(const std::string& str)
{
    string dateStr("");
    DateInfo date;
    if (str.empty()) return dateStr;

    vector<int> _date;
    for (string out : split(str, "-")) {
        _date.push_back(atoi(out.c_str()));
    }

    if (_date.size() != 3) return dateStr;
    date.year = _date[0];
    date.month = _date[1];
    date.day = _date[2];

    if (date.month == 12 && date.day == 31) {
            date.month = 1;
            date.day = 1;
            date.year++;
    }
    else if (((date.month == 4) || (date.month == 6) || (date.month == 11) || (date.month == 9)) && date.day == 30) {
            date.month++;
            date.day = 1;
    }
    else if (date.month == 2) {
        if (isLeapYear(date.year)) {
            if (date.day == 29) {
                date.day = 1;
                date.month++;
            }
            else date.day++;
        }
        else {
            if (date.day == 28) {
                date.day = 1;
                date.month++;
            }
            else date.day++;
        }
    }
    else if (date.day == 31) {
        date.month++;
        date.day++;
    }
    else date.day++;

    dateStr.append(to_string(date.year)+ "-");
    if (date.month < 10) {
        dateStr.append("0" + to_string(date.month) + "-");
    }
    else {
        dateStr.append(to_string(date.month) + "-");
    }
    if (date.day < 10) {
        dateStr.append("0" + to_string(date.day));
    }
    else {
        dateStr.append(to_string(date.day));
    }

    return dateStr;
}

string OA_Center::splits(const string &str, const string &delim)
{
    string result("");
    if (str.empty()) {
        return result;
    }

    char* _str = new char[str.length() + 1];
    strcpy(_str, str.c_str());

    char* _delim = new char[delim.length() + 1];
    strcpy(_delim, delim.c_str());

    char* ptr = strtok(_str, _delim);
    while (ptr) {
        result.append(ptr);
        ptr = strtok(nullptr, _delim);
    }

    delete _str;
    delete _delim;

    return result;
}

vector<string> OA_Center::split(const string &str, const string &delim)
{
    vector<string> result;
    if (str.empty()) {
        return result;
    }

    char* _str = new char[str.length() + 1];
    strcpy(_str, str.c_str());

    char* _delim = new char[delim.length() + 1];
    strcpy(_delim, delim.c_str());

    char* ptr = strtok(_str, _delim);
    while (ptr) {
        string _s(ptr);
        result.push_back(_s);
        ptr = strtok(nullptr, _delim);
    }

    delete _str;
    delete _delim;

    return result;
}

void OA_Center::OvertimeInfo(const OvertimeDataVec& overTime)
{
    for (OverTimeData data : overTime) {
        timeOperation(data);
    }
}

int OA_Center::OverTimeCount(const vector<int> &begin, const vector<int> &end)
{
    int count = (end.at(0) - begin.at(0) - 9) * 60 + end.at(1) - begin.at(1) - 30;
    m_overTimeCount = m_overTimeCount + count;
    return count;
}

int OA_Center::OverTimeCountOfWeek(const vector<int> &begin, const vector<int> &end)
{
    int count = (end.at(0) - begin.at(0)) * 60 + end.at(1) - begin.at(1);
    m_overTimeCount = m_overTimeCount + count;
    return count;
}

void OA_Center::dataClear()
{
    m_spResponseData->clear();
    m_UrlBody.clear();
    cookies.clear();
    m_spHeaderList->clear();
}
