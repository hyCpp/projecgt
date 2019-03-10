#include<string.h>
#include<iostream>
#include <curl/curl.h>
#include <unistd.h>
#include <VR_AwakeAudioToServer.h>

//void test(VR_AwakeAudioToServer* ptr)
//{
//    printf("notify begin -------\n");

//    while (1) {
//        sleep(2);
//        ptr->setUploadPath("tset");
//        printf("Notify \n");
//    }
//}

static char errorBuffer[CURL_ERROR_SIZE];

static int writer(char* data, size_t size, size_t nmemb, std::string* writerData)
{
    unsigned long sizes = size * nmemb;
    if (writerData == NULL) {
        return 0;
    }

    writerData->append(data, sizes);
    return sizes;
}


static bool init(CURL*& conn, char* url, std::string* p_buffer)
{
    CURLcode code;
    conn = curl_easy_init(); // 函数得到 easy interface型指针
    if (conn == NULL) {
        printf("Failed to create CURL connection\n");
        exit(EXIT_FAILURE);
    }

    // curl_easy_setopt :

    /**
        CURLOPT_URL: URL地址
        URLOPT_WRITEFUNCTION 实现回调函数,CURLOPT_WRITEDATA用于表明CURLOPT_WRITEFUNCTION函数中的stream指针的来源
        CURLOPT_FOLLOWLOCATION  设置重定位URL
        CURLOPT_TIMEOUT 设置传输时间，CURLOPT_CONNECTIONTIMEOUT 设置连接等待时间
        CURLOPT_READFUNCTION 读取数据传递给远程主机,CURLOPT_READDATA 表明CURLOPT_READFUNCTION函数原型中的stream指针来源
        CURLOPT_POSTFIELDS: POST参数
        CURLOPT_WRITEFUNCTION: 对返回的数据进行操作的函数地址
        CURLOPT_WRITEDATA: 设置WRITEFUNCTION的第四个参数值
        CURLOPT_POST: 设置为非0表示本次操作为POST
        CURLOPT_VERBOSE: 设置为非0在执行时打印请求信息
        CURLOPT_HEADER: 设置为非0将响应头信息同响应体一起传给WRITEFUNCTION
        CURLOPT_FOLLOWLOCATION: 设置为非0，响应头信息Location
*/
    code = curl_easy_setopt(conn, CURLOPT_ERRORBUFFER, errorBuffer); // 设置传输选项
    if (code != CURLE_OK) {
        printf("Failed to set error buffer [%s]\n", errorBuffer);
        return false;
    }

    code = curl_easy_setopt(conn, CURLOPT_URL, url);
    if (code != CURLE_OK) {
        printf("Failed to set url [%s]\n", errorBuffer);
        return false;
    }

    code = curl_easy_setopt(conn, CURLOPT_FOLLOWLOCATION, 1);
    if (code != CURLE_OK) {
        printf("Failed to set error buffer [%s]\n", errorBuffer);
        return false;
    }

    code = curl_easy_setopt(conn, CURLOPT_WRITEFUNCTION, writer); // 设置的传输选项，实现回调函数以完成用户特定任务
    if (code != CURLE_OK) {
        printf("Failed to set writer  [%s]\n", errorBuffer);
        return false;
    }

    code = curl_easy_setopt(conn, CURLOPT_WRITEDATA, p_buffer);
    if (code != CURLE_OK) {
        printf("Failed to set writer date [%s]\n", errorBuffer);
        return false;
    }

    return true;
}


void download()
{
    CURL* conn = NULL;
    CURLcode code;
    std::string buffer;
    curl_global_init(CURL_GLOBAL_DEFAULT); // 初始化libcurl, 这个函数只能用一次, 其实在调用curl_global_cleanup 函数后仍然可再用, 不能保证线程安全
    char* url = "172.16.211.50/cc2/cc/getfile.php";

    if (!init(conn, url, &buffer)) {
        printf("Connection initializion failed\n");
        exit(EXIT_FAILURE);
    }

    code = curl_easy_perform(conn); // 函数完成传输任务
    if (code != CURLE_OK) {
        printf("Failed to get ‘%s’ [%s]\n", url, errorBuffer);
        exit(EXIT_FAILURE);
    }

    FILE* file = fopen("1.gif", "wb");
    fseek(file, 0, SEEK_SET);
    fwrite(buffer.c_str(), 1, buffer.size(), file);
    fclose(file);
    curl_easy_cleanup(conn);
    printf("%s\n", buffer.c_str());
}


int main()
{
    VR_AwakeAudioToServer* ptr = new VR_AwakeAudioToServer("/home/huyang/AudioUploadServer.txt");
    ptr->mainLoop();

//    pthread_t Id;
//    int err = pthread_create(&Id, NULL, (void* (*)(void*))test, ptr);
//    if (err != 0) {
//        exit(0);
//    }
    while(1);
}
