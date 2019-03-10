#ifndef CURLHTTP
#define CURLHTTP
#include <stdio.h>
#include <curl/curl.h>
#include <sstream>
#include <map>
#include <string.h>

enum postType
{
    public_post,
    multipart_post,
};

typedef std::map<std::string, std::string> CurlMap;

using namespace std;
class CurlHttp
{
    typedef map<std::string, std::string> CurlMap;
public:
    CurlHttp();
    CurlHttp(const CurlHttp&) = delete;
    CurlHttp& operator = (const CurlHttp&) = delete;
    ~CurlHttp();
    int GetHttp(const string& url, CurlMap const* headers, CurlMap const* form, string *response);
    int PostHttp(const string& url, CurlMap const* headers, CurlMap const* form, string * response, postType type = public_post, const string& body = "");
    int PostHttp(const string& url, CurlMap const* headers, CurlMap const* form, string * response, const CurlMap& body, postType type = public_post);
    void setDebug(bool bug);
    void setHeader(bool bug);
    void setTimeOut(int time);

    string getValueByKeyOfInput(const string& source, const string& key, const string &attrName = "") const;
    void getCookies(const string& source, std::string& target) const;
    string getHtmlContentTransforXml(const string& source, const string &key, const string &attrName) const;
    void getHtmlInputInfo(const string& html, CurlMap& data);
private:
    void appendHeaders(CurlMap const & headers, curl_slist ** slist) const;
    void appendFormat(CurlMap const & formData , curl_httppost ** form, curl_httppost** last) const;
    string makeUrlParams(const CurlMap &params) const;

    bool m_debug;
    bool m_header;
    int m_timeout;
};

#endif // CURLHTTP

