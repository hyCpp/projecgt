#include "VR_AwakeAudioToServer.h"
#include <stdlib.h>
#include <stdio.h>

#define VR_CURL_POST_URL "http://34.235.234.175:8080/upload/file/upload"
static const char _curl_slist_append[] = "Expect:";
static char errorBuffer[CURL_ERROR_SIZE];


VR_AwakeAudioToServer::VR_AwakeAudioToServer(const std::string &path)
    : m_path(path)
    , MyThread("test")
{
    printf("UploadAudio VR_AwakeAudioToServer path : [%s] \n", m_path.c_str());
}

VR_AwakeAudioToServer::~VR_AwakeAudioToServer()
{
}

bool VR_AwakeAudioToServer::run()
{
//    printf("Run begin----- \n");
//    while(1) {
//        Wait();
//        printf("Run \n");
//    }
    UploadAudio();
}

void VR_AwakeAudioToServer::setUploadPath(const std::string &path)
{
    m_path.assign(path);
    Notify();
}

bool VR_AwakeAudioToServer::initUpload(CURL *&curl, char *url, const std::string& body)
{
    printf("initUpload \n");
    CURLcode res;
    struct curl_httppost* formpost = nullptr;
    struct curl_httppost* lastptr = nullptr;
    struct curl_slist* headerlist = nullptr;

    curl_formadd(&formpost, &lastptr, CURLFORM_COPYNAME, "input_file", CURLFORM_FILE, m_path.c_str(), CURLFORM_END);
    curl = curl_easy_init();

    res = curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errorBuffer);
    headerlist = curl_slist_append(headerlist, _curl_slist_append);
//    headerlist = curl_slist_append(headerlist, "Content-Type: multipart/form-data");

    if (nullptr == curl) {
        printf("curl_easy_init failed [%s]", errorBuffer);
        return false;
    }

    if (CURLE_OK != res) {
        printf("Failed to set error buffer [%s]", errorBuffer);
        return false;
    }

    res = curl_easy_setopt(curl, CURLOPT_URL, url);
    if (CURLE_OK != res) {
        printf("curl_easy_setopt failed [%s]", errorBuffer);
        return false;
    }

    res = curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
    if (CURLE_OK != res) {
        printf("curl_easy_setopt failed [%s]", errorBuffer);
        return false;
    }

//    res = curl_easy_setopt(curl, CURLOPT_POST, true);
//    if (CURLE_OK != res) {
//        printf("curl_easy_setopt failed [%s]", errorBuffer);
//        return false;
//    }

    res = curl_easy_setopt(curl, CURLOPT_NOSIGNAL, true);
    if (CURLE_OK != res) {
        printf("curl_easy_setopt failed [%s]", errorBuffer);
        return false;
    }

    res = curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);
    if (CURLE_OK != res) {
        printf("curl_easy_setopt failed [%s]", errorBuffer);
        return false;
    }

    res = curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false);
    if (CURLE_OK != res) {
        printf("curl_easy_setopt failed [%s]", errorBuffer);
        return false;
    }

    res = curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
    if (CURLE_OK != res) {
        printf("curl_easy_setopt failed [%s]", errorBuffer);
        return false;
    }

    res = curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5);
    if (CURLE_OK != res) {
        printf("curl_easy_setopt failed [%s]", errorBuffer);
        return false;
    }

//    res = curl_easy_setopt(curl, CURLOPT_HEADER, 1L);
//    if (CURLE_OK != res) {
//        VR_LOGD("curl_easy_setopt failed [%s]", errorBuffer);
//        return false;
//    }

    return true;
}

bool VR_AwakeAudioToServer::requestMsg()
{

}

bool VR_AwakeAudioToServer::UploadAudio()
{
    printf("upload Audio begin \n");

    CURLcode res;
    CURL *curl = nullptr;

    res = curl_global_init(CURL_GLOBAL_ALL); // init only one
    std::string body = "input_file=@/home/huyang/AudioUploadServer.txt";

    if (!initUpload(curl, VR_CURL_POST_URL, body)) {
        printf("UploadAudio Connection initializion failed \n");
        return false;
    }

    res = curl_easy_perform(curl);

    if (CURLE_OK != res) {
        printf("curl_easy_perform() failed=[%d][%s] \n", res, curl_easy_strerror(res));
    }

    printf("upload Audio success \n");

    curl_easy_cleanup(curl);
    return true;
}
