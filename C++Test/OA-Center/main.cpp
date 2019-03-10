#include "Log_Func.h"
#include "CurlHttp.h"
#include "OA_Center.h"
#include <iostream>
#include <fstream>

void deleteEnterSpace(string& s)
{
    size_t n = s.find_last_not_of( " \r\n\t" );
    if( n != string::npos)
    {
        s.erase( n + 1 , s.size() - n );
    }

    n = s.find_first_not_of ( " \r\n\t" );
    if( n != string::npos)
    {
        s.erase(0 , n);
    }
}

int main()
{
    /**
    TC_Log::setLogStatus(true);
    OA_Center* oa = new OA_Center;

    char str[256];
    char pwd[256];
    char reason[1024];
    char any[256];

#ifdef HY
    ifstream huyang("pwd");
    ostringstream buf;
    char ch;
    while (buf && huyang.get(ch)) {
        buf.put(ch);
    }
    string _ch = buf.str();
    deleteEnterSpace(_ch);
    strcpy(str, "3059");
    strcpy(pwd, _ch.c_str());
#else
    std::cout<<"请输入工号 : ";
    gets(str);
    std::cout<<"请输入密码 : ";
    gets(pwd);
#endif

    oa->Login(str, pwd);
    oa->EmployeeInfo();
    std::cout<<"请确认加班信息是否正确，quit退出，其他任意键继续 ... ";

    gets(any);
    std::string _any(any);
    if (_any.compare("quit") == 0) {
        return 0;
    }
    std::cout<<"请输入加班理由 : ";
    gets(reason);
    std::string _reason(reason);
    if (_reason.empty()) {
        return 0;
    }
    oa->OvertimeApply(reason);
    std::cout<<"申请完成，请到oa-center查看 ";
    */



    CurlHttp curlHttp;
    CurlMap mapformat;
    mapformat["client_id"] = "42bc8cbfbe1847c2bfe00546a7deb080";
    mapformat["response_type"] = "code";
    mapformat["redirect_uri"] = "https://www.baidu.com";
    mapformat["state"] = "34fFs29kd09";

    std::string resp;
    int code = curlHttp.GetHttp("https://accounts.spotify.com/", nullptr, &mapformat, &resp);
    std::cout<<resp<<std::endl;
//    std::cout<<code<<std::endl;
}
