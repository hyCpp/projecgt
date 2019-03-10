#include "CurlHttp.h"
#include <iostream>
#include "NGVUIXMLStrParse.h"
inline size_t onWriteData(void * buffer, size_t size, size_t nmemb, void * userp)
{
    std::string * str = dynamic_cast<std::string *>((std::string *)userp);
    str->append((char *)buffer, size * nmemb);
    return nmemb;
}

CurlHttp::CurlHttp()
    : m_debug(false)
    , m_header(true)
    , m_timeout(10000)
{
}

CurlHttp::~CurlHttp()
{

}

void CurlHttp::setDebug(bool bug)
{
    m_debug = bug;
}

void CurlHttp::setHeader(bool bug)
{
    m_header = bug;
}

void CurlHttp::setTimeOut(int time)
{
    m_timeout = time;
}

int CurlHttp::GetHttp(const std::string &url, const CurlMap *headers, CurlMap const* form, std::string *response)
{
    CURL* curl = curl_easy_init();
    struct curl_slist * slist = nullptr;
    struct curl_httppost *formpost = nullptr;
    struct curl_httppost *lastptr = nullptr;

    if (headers) {
        this->appendHeaders(*headers, &slist);
    }

    if (form) {
        this->appendFormat(*form, &formpost, &lastptr);
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, slist);
    curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "");
    curl_easy_setopt(curl, CURLOPT_HEADER, m_header);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, onWriteData);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*) response);
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, true);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, this->m_timeout);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, this->m_debug);

    int status_code = curl_easy_perform(curl);

    curl_slist_free_all(slist);
    curl_easy_cleanup(curl);

    return status_code;
}

int CurlHttp::PostHttp(const std::string& url, CurlMap const* headers, CurlMap const* form, std::string * response, postType type, const std::string& body)
{
    CURL* curl = curl_easy_init();
    struct curl_slist * slist = nullptr;
    struct curl_httppost *formpost = nullptr;
    struct curl_httppost *lastptr = nullptr;

    if (headers) {
        this->appendHeaders(*headers, &slist);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, slist);
    }
    if (type == public_post) {
        curl_easy_setopt(curl, CURLOPT_POST, true);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, body.size());
    }
    if (type == multipart_post) {
        if (form) {
            this->appendFormat(*form, &formpost, &lastptr);
        }
        curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_HEADER, m_header);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, onWriteData);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) response);
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, true);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    // curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "");
    curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, this->m_timeout);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, this->m_debug);

    int status_code = curl_easy_perform(curl);

    if (status_code == CURLE_OK) {
        struct curl_slist* cookies = nullptr;
        long resCode;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &resCode);

        if ((long)200 <= resCode && (long)resCode < 300) {
//            printf("OK \n");
        }
        else if (300 <= resCode && resCode< 400) {
            printf("Redirection \n");
        }
        else if (400 <= resCode && resCode < 500) {
            printf("client error \n");
        }
        else if (500 <= resCode) {
            printf("service error \n");
        }
        curl_slist_free_all(cookies);
    }

    if (type == multipart_post) {
        curl_formfree(formpost);
    }

    curl_slist_free_all(slist);
    curl_easy_cleanup(curl);

    return status_code;
}

int CurlHttp::PostHttp(const std::string &url, const CurlMap *headers, const CurlMap *form, std::string *response, const CurlMap &body, postType type)
{
    string _body = this->makeUrlParams(body);
    return this->PostHttp(url, headers, form, response, type, _body);
}

void CurlHttp::getCookies(const std::string& source, std::string& target) const
{
    target.clear();
    if (source.empty()) {
        return;
    }

    string setCookie("Set-Cookie:");
    string::size_type cookieBegin = source.find(setCookie) + setCookie.size();
    if (cookieBegin == std::string::npos) {
        return;
    }

    string::size_type cookieEnd = source.find(";", cookieBegin);
    if (cookieEnd == std::string::npos) {
        return;
    }

    target = source.substr(cookieBegin, cookieEnd - cookieBegin);

    string::size_type index = 0;
    while((index = target.find(' ', index)) != std::string::npos)
    {
        target.erase(index ,1);
    }
}

std::string CurlHttp::makeUrlParams(const CurlMap &params) const
{
    std::string body("");
    CurlMap::const_iterator it;
    for (it = params.begin(); it != params.end(); ++it) {
        char* key = curl_escape(it->first.c_str(), (int) it->first.size());
        char* value = curl_escape(it->second.c_str(), (int) it->second.size());
        body.append(key);
        body.append("=");
        body.append(value);
        body.append("&");
        curl_free(key);
        curl_free(value);
    }

    return body;
}

void CurlHttp::appendHeaders(const CurlMap &headers, curl_slist **slist) const
{
    ostringstream os;
    CurlMap::const_iterator it;
    for (it = headers.begin(); it != headers.end(); ++it) {
        os << it->first << ":" << it->second;
        *slist = curl_slist_append(*slist, os.str().c_str());
        os.str("");
    }
}

void CurlHttp::appendFormat(const CurlMap &formData, curl_httppost **form, curl_httppost **last) const
{
    CurlMap::const_iterator it;
    for (it = formData.begin(); it != formData.end(); ++it) {
        curl_formadd(form, last, CURLFORM_COPYNAME, (it->first).c_str(), CURLFORM_COPYCONTENTS, (it->second).c_str(), CURLFORM_END);
    }
}

string CurlHttp::getHtmlContentTransforXml(const string &str, const string& begin, const string& end) const
{
    if (str.empty()) {
        return "";
    }
    string::size_type firstValue = str.find(begin);
    if (firstValue == std::string::npos) {
        return "";
    }
    string::size_type lastValue = str.find(end);
    if (lastValue == std::string::npos) {
        return "";
    }

    return str.substr(firstValue, lastValue - firstValue + end.size());
}

string CurlHttp::getValueByKeyOfInput(const string& source, const string &key, const string &attrName) const
{
    if (source.empty()) {
        return "";
    }
    if (key.empty()) {
        return "";
    }

    string::size_type firstPos = source.find(key) + 1;
    if (firstPos == string::npos) {
        return "";
    }

    string::size_type valuePos = source.find(attrName, firstPos) + 1;
    if (valuePos == string::npos) {
        return "";
    }

    string::size_type valueBeginPos = source.find("\"", valuePos) + 1;
    if (valueBeginPos == string::npos) {
        return "";
    }

    string::size_type valueEndPos = source.find("\"", valueBeginPos);
    if (valueEndPos == string::npos) {
        return "";
    }

    return source.substr(valueBeginPos, valueEndPos - valueBeginPos);
}

void CurlHttp::getHtmlInputInfo(const string &html, CurlMap &data)
{
    data.clear();
    string body = getHtmlContentTransforXml(html, "<body", "</body>");
    NGVUIXMLStrParse parse(body);
    data = parse.GetXMLAttrMap("//body");
}
