#include "WebSocketClient.h"
#include <map>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>
#include <curl/curl.h>
#include <sstream>
#include <map>
#include <openssl/err.h>
#include <functional>
#include <sys/stat.h>

using namespace std;

WebSocketClient* WebSocketClient::m_pWebSocketClient = nullptr;

WebSocketClient::WebSocketClient():
        m_listenfd(0),
        m_token(""),
        m_ssl(nullptr),
        m_socket(-1),
        m_ctx(nullptr),
        m_cond(PTHREAD_COND_INITIALIZER)
{
    pthread_mutexattr_init(&m_attr);
    pthread_mutexattr_settype(&m_attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&m_mutex, &m_attr);
    if(-1 == init()) {
        return;
    }
}

WebSocketClient::~WebSocketClient()
{
    pthread_mutexattr_destroy(&m_attr);
    pthread_mutex_destroy(&m_mutex);
    SSL_shutdown(m_ssl); //关闭SSL套接字
    SSL_free(m_ssl); //释放SSL套接字
    SSL_CTX_free(m_ctx); //释放SSL会话环境
    close(m_socket);
}

WebSocketClient *WebSocketClient::getInstance(){
    if(m_pWebSocketClient == nullptr) {
        m_pWebSocketClient = new WebSocketClient();
    }
    return m_pWebSocketClient;
}

int WebSocketClient::init(){
    SSL_load_error_strings(); //加载SSL错误信息
    SSLeay_add_ssl_algorithms(); //添加SSL的加密/HASH算法
    const SSL_METHOD *meth = SSLv23_client_method(); 	//客户端，服务端选择SSLv23_server_method()
    m_ctx = SSL_CTX_new(meth); 	//建立新的SSL上下文
    if (m_ctx == nullptr) {
        printf("SSL_CTX_new failed!\n");
        return -1;
    }

    m_ssl = SSL_new(m_ctx); //建立SSL
    if(m_ssl == nullptr) {
        printf("SSL_new failed!\n");
        return -1;
    }

    sockaddr_in addr_server;
    addr_server.sin_family = AF_INET;
    addr_server.sin_port = htons(HTTPSWSSPORT);
    struct hostent *p_hostent = gethostbyname("stream.watsonplatform.net");
    if (p_hostent == nullptr) {
        printf("gethostbyname failed!\n");
        return -1;
    }

    memcpy(&(addr_server.sin_addr), p_hostent->h_addr_list[0], sizeof(addr_server.sin_addr));

    m_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(connect(m_socket, (sockaddr*)&addr_server, sizeof(addr_server)) == -1) {
        cout<< "Connect failed !!"<<endl;
        close(m_socket);
        return -1;
    }

    SSL_set_fd(m_ssl, m_socket); //将SSL与TCP SOCKET 连接
    int sslRet = SSL_connect(m_ssl); 	//SSL连接
    if(sslRet == -1) {
        cout<<"SSL_connect error ";
        return -1;
    }

//    std::thread startRecv(recvThread, this);
//    startRecv.detach();

    return 1;
}


int WebSocketClient::connectIBM(const std::string& str)
{
    string sendData = "GET  /speech-to-text/api/v1/recognize?watson-token=" + str + "&model=zh-CN_BroadbandModel HTTP/1.1\r\n";
    sendData += "Host: stream.watsonplatform.net\r\n";
    sendData += "Connection: Upgrade\r\n";
    sendData += "Upgrade: websocket\r\n";
    sendData += "Sec-WebSocket-Key: OqMJI0t/cOl6d6JNE+Op0g==\r\n";
    sendData += "Sec-WebSocket-Version: 13\r\n";
    sendData += "Sec-WebSocket-Protocol: chat, superchat\r\n";
    sendData += "Origin: wss://stream.watsonplatform.net\r\n";
    sendData += "\r\n";

    int sslRet = SSL_write(m_ssl, sendData.c_str(), sendData.size());
    if (sslRet == -1) {
        std::cout<<"SSL_write failed !!!"<<std::endl;
        return -1;
    }

    char rec_buff[1024];
    size_t rec_buff_size = 1024;
    string resp;
    ssize_t ires = 0;

    SSL_read(m_ssl, rec_buff, rec_buff_size);
    std::cout<<rec_buff<<std::endl;
    resp += string(rec_buff);
    memset(rec_buff, 0, rec_buff_size);
    resp.clear();

    string _startVR = "{\"action\": \"start\",\"content-type\": \"audio\/wav;rate=22050\", \"interim_results\": true}";
    std::cout<<"start vr : "<<std::endl;
    std::cout<<_startVR<<std::endl;
//    WebSocketSend((const unsigned char*)_startVR.c_str(), (unsigned int)_startVR.size(), opcode_text);

    WebSocketSend_(_startVR.c_str(), _startVR.size(), opcode_text);

//    sslRet = SSL_write(m_ssl, startVR.c_str(), startVR.size());
//    if (sslRet == -1) {
//        printf("SSL_write failed !!!\n");
//    }



    string body("/home/huyang/MyDemo/dectation_large1.wav");
    struct stat file_info;
    FILE* fp = nullptr;
    stat(body.c_str(), &file_info);
    long fileSize = file_info.st_size;
    std::cout<<"fileSize " << fileSize<<std::endl;

    fp = fopen(body.c_str(), "rb");
    if (fp == nullptr) {
        printf("fopen .wav file error !!");
        fclose(fp);
        return -1;
    }



    bool firstSend = true;

    while(true) {
//        ires = SSL_read(m_ssl, rec_buff, rec_buff_size);
        ires = WebSocketRecv((unsigned char*)rec_buff, 1024);
//        unsigned char payloadData[1024];
//        int state = DataFrameDecoding((unsigned char*)rec_buff, ires, payloadData, 1024);
//        std::cout<<"payloadData =  "<<string((const char*)payloadData)<<std::endl;
//        std::cout<<"state =  "<<state<<std::endl;

        int nRes = SSL_get_error(m_ssl, ires);
        resp += string((const char*)rec_buff);
        memset(rec_buff, 0, rec_buff_size);
        std::cout<<"size = "<<ires<<std::endl;
        std::cout<<"resp = "<<resp<<std::endl;

        if (nRes == SSL_ERROR_NONE) {
            if (ires > 0) {
                if (resp.find("state") != std::string::npos) {
                    if (firstSend) {
                        std::thread sendFile(&WebSocketClient::sendWavData, this);
                        sendFile.detach();
                        firstSend = false;
                    }
                }
            }
            else {
                break;
            }
        }
        else {
            std::cout<<"SSL_ERROR !!!!"<<std::endl;
            break;
        }
    }

    printf("resp = %s\n", resp.c_str());
    return 1;
}

int WebSocketClient::sendWavData()
{
    string body("/home/huyang/MyDemo/BAC009S0764W0250.wav");
    struct stat file_info;
    FILE* fp = nullptr;
    stat(body.c_str(), &file_info);
    long fileSize = file_info.st_size;
    std::cout<<"fileSize " << fileSize<<std::endl;

    fp = fopen(body.c_str(), "rb");
    if (fp == nullptr) {
        printf("fopen .wav file error !!");
        fclose(fp);
        return -1;
    }


    int rc;
    char postContent[16384];
    while (rc = fread(postContent, 1, 16384, fp) != 0) {
        WebSocketSend_((const char*)postContent, 16384, opcode_binary);

        memset(postContent, 0, 16384);
    }

    fclose(fp);
    sleep(2);

    string stopVR = "{\"action\": \"stop\"}";
    WebSocketSend_(stopVR.c_str(), stopVR.size(), opcode_text);

//    WebSocketSend_(stopVR.c_str(), stopVR.size(), opcode_text);
}

int WebSocketClient::sendDataToIBM(const string &data)
{
    std::cout<<"sendDataToIBM "<<data<<std::endl;

    pthread_mutex_lock(&m_mutex);
    m_MsgQueue.push(data);
    pthread_mutex_unlock(&m_mutex);

    pthread_mutex_lock(&m_mutex);
    pthread_cond_signal(&m_cond);
    pthread_mutex_unlock(&m_mutex);
}

bool WebSocketClient::run()
{
    std::cout<<"run"<<std::endl;

    char rec_buff[1024];
    size_t rec_buff_size = 1024;
    int cnt = 0;
    string resp;
    ssize_t ires = 0;

    while(true) {
        if (!m_MsgQueue.empty()) {
            std::string msg("");
            pthread_mutex_lock(&m_mutex);
            msg = m_MsgQueue.front();
            m_MsgQueue.pop();
            pthread_mutex_unlock(&m_mutex);
            std::cout<<"run1"<<std::endl;

            if (!msg.empty()) {
                std::cout<<"msg is "<<msg<<std::endl;
                int sslRet = SSL_write(m_ssl, msg.c_str(), msg.size());
                if (sslRet == -1) {
                    printf("SSL_write failed !!!\n");
                }
            }
        }
        else {
            std::cout<<"wait"<<std::endl;
            pthread_mutex_lock(&m_mutex);
            pthread_cond_wait(&m_cond, &m_mutex);
            pthread_mutex_unlock(&m_mutex);
        }

        bool flag = true;
        while (flag) {
            ires = SSL_read(m_ssl, rec_buff, rec_buff_size - cnt);
            int nRes = SSL_get_error(m_ssl, ires);
            resp += string(rec_buff);
            memset(rec_buff, 0, rec_buff_size);

            std::cout<<"nRes = "<<nRes<<std::endl;
            if (nRes == SSL_ERROR_NONE) {
                if (ires > 0) {
                    std::cout<<"ires1 = "<<ires<<std::endl;
                    cnt += ires;
                    if (cnt >= rec_buff_size) {
                        flag = false;
                    }
                    continue;
                }
                else if (ires == 0) {
                    std::cout<<"ires2 = "<<ires<<std::endl;
                    flag = false;
                }
            }

            std::cout<<"resp = "<<resp<<std::endl;
            resp.clear();
        }
    }
}

void WebSocketClient::recvThread(WebSocketClient* ssl)
{
    std::cout<<"recvThread"<<std::endl;
    ssl->run();
}

int WebSocketClient::GetHttp(const string &ip, std::string& resp)
{
    resp.clear();

    struct hostent *p_hostent = gethostbyname(ip.c_str());

    if (p_hostent == nullptr) {
        printf("gethostbyname failed!\n");
        return -1;
    }

    sockaddr_in addr_server;
    addr_server.sin_family = AF_INET;
    addr_server.sin_port = htons(80);
    memcpy(&(addr_server.sin_addr), p_hostent->h_addr_list[0], sizeof(addr_server.sin_addr));

    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    int res = connect(sock, (sockaddr*)&addr_server, sizeof(addr_server));

    if(res == -1) {
        cout<< "Connect failed !!"<<endl;
        close(sock);
        return -1;
    }

    string sendData = "GET / HTTP/1.1\r\n";
    sendData += "Host: api.goseek.cn\r\n";
    sendData += "Connection: keep-alive\r\n";
    sendData += "Accept: text/html,application/xhtml+xm…plication/xml;q=0.9,*/*;q=0.8\r\n";
    sendData += "Accept-Encoding: gzip, deflate\r\n";
    sendData += "Accept-Language: zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2\r\n";
    sendData += "Cache-Control: max-age=0\r\n";
    sendData += "Upgrade-Insecure-Requests: http://api.goseek.cn\r\n";
    sendData += "Content-Type: application/x-www-form-urlencoded\r\n";
    sendData += "Referer: http://api.goseek.cn\r\n";
    sendData += "\r\n";

    printf("%s\n", sendData.c_str());

    if (send(sock, sendData.c_str(), sendData.size(), 0) == -1) {
        printf("send failed !!!\n");
    }

    char rec_buff[1024];
    size_t rec_buff_size = 1024;
    ssize_t cnt;

    while (true) {
        cnt = recv(sock, rec_buff, rec_buff_size, 0);
        if (cnt == rec_buff_size) {
            resp += string(rec_buff);
            memset(rec_buff, 0, rec_buff_size);

        }
        else {
            if (cnt == 0) {
                break;
            }
            if (cnt > 0 && cnt < rec_buff_size) {
                resp += string(rec_buff);
                break;
            }
        }
    }

    printf("%d\n", cnt);

    close(sock);
    return -1;
}

int WebSocketClient::GetHttps(const string &ip, std::string& resp)
{
    resp.clear();

    SSL_load_error_strings(); //加载SSL错误信息
    SSLeay_add_ssl_algorithms(); //添加SSL的加密/HASH算法
    const SSL_METHOD *meth = SSLv23_client_method(); 	//客户端，服务端选择SSLv23_server_method()
    SSL_CTX* ctx = SSL_CTX_new(meth); 	//建立新的SSL上下文
    if (ctx == nullptr) {
        ERR_print_errors_fp(stderr);
        printf("SSL_CTX_new failed!\n");
        return -1;
    }

    SSL* ssl = SSL_new(ctx); //建立SSL
    if(ssl == nullptr) {
        printf("SSL_new failed!\n");
        return -1;
    }

    sockaddr_in addr_server;
    addr_server.sin_family = AF_INET;
    addr_server.sin_port = htons(443);
    struct hostent *p_hostent = gethostbyname(ip.c_str());
    if (p_hostent == nullptr) {
        printf("gethostbyname failed!\n");
        return -1;
    }

    memcpy(&(addr_server.sin_addr), p_hostent->h_addr_list[0], sizeof(addr_server.sin_addr));

    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(connect(sock, (sockaddr*)&addr_server, sizeof(addr_server)) == -1) {
        cout<< "Connect failed !!"<<endl;
        close(sock);
        return -1;
    }

    SSL_set_fd(ssl, sock); //将SSL与TCP SOCKET 连接
    int sslRet = SSL_connect(ssl); 	//SSL连接
    if(sslRet == -1) {
        cout<<"SSL_connect error ";
        return -1;
    }

    string sendData = "GET /authorization/api/v1/token?url=https://stream.watsonplatform.net/speech-to-text/api HTTP/1.1\r\n";
    sendData += "Origin:https://stream.watsonplatform.net\r\n";
    sendData += "Host:stream.watsonplatform.net\r\n";
    sendData += "Connection:keep-alive\r\n";

    std::string userPwd = "cdc333fa-f2b8-4bf7-87b0-abc1453ca8d1:gWZIPLVdVX87";
    char* baseCode = base64_encode(userPwd.c_str(), userPwd.size());
    sendData += "Authorization:Basic " + std::string(baseCode) + "\r\n";

    sendData += "Accept:text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n";
    sendData += "Accept-Encoding:gzip, deflate, br\r\n";
    sendData += "Accept-Language:zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2\r\n";
    sendData += "Upgrade-Insecure-Requests:1\r\n";

    sendData += "\r\n";
    printf("%s\n", sendData.c_str());


    sslRet = SSL_write(ssl, sendData.c_str(), sendData.size());
    if (sslRet == -1) {
        printf("SSL_write failed !!!\n");
        return -1;
    }

    char rec_buff[1024];
    size_t rec_buff_size = 1024;
    ssize_t cnt;

    while(true) {
        cnt = SSL_read(ssl, rec_buff, rec_buff_size);
        printf("%d\n", cnt);
        resp += string(rec_buff);
        memset(rec_buff, 0, rec_buff_size);

        if (cnt <= 0) {
            break;
        }
    }

    SSL_shutdown(ssl); //关闭SSL套接字
    SSL_free(ssl); //释放SSL套接字
    SSL_CTX_free(ctx); //释放SSL会话环境
    close(sock);
    return -1;
}


int WebSocketClient::buildFrameHead(unsigned char* head, const unsigned char* data, unsigned int len, FrameHead type)
{
    unsigned char maskKey[4] = {0};
    int pos = 0;

    // FIN, RSV1, RSV2, RSV3 : 1bit, opcode : 4bit; eg: 0x81(10000001) 指示这个是消息的最后片段,%x1 代表一个文本帧
    switch (type) {
    case opcode_continuation:
        head[pos++] = 0x00;
        break;
    case opcode_text:
        head[pos++] = 0x81;
        break;
    case opcode_binary:
        head[pos++] = 0x82;
        break;
    case opcode_close:
        head[pos++] = 0x88;
        break;
    case opcode_pong:
        head[pos++] = 0x8A;
        break;
    case opcode_ping:
        head[pos++] = 0x89;
        break;
    default:
        break;
    }

    head[pos] = 0x80;

    if (len < 126) { // 如果0-125，这是负载长度
        head[pos++] |= (len & 0x7F); // 0x7F(0111 1111) & len = len, 0x80(10000000) | len = 1(len),第八位代表需要掩码
    }
    else if (len < 65536) { // 如果126，之后的两字节解释为一个16位的无符号整数是负载长度
        head[pos++] |= 0x7E;
        head[pos++] = (char)((len >> 8) & 0xFF);
        head[pos++] = (unsigned char)((len >> 0) & 0xFF);
    }
    else if (len < 0xFFFFFFFF) {
        head[pos++] |= 0x7F;
        head[pos++] = 0; //(char)((len >> 56) & 0xFF);   // 数据长度变量是 unsigned int dataLen, 暂时没有那么多数据
        head[pos++] = 0; //(char)((len >> 48) & 0xFF);
        head[pos++] = 0; //(char)((len >> 40) & 0xFF);
        head[pos++] = 0; //(char)((len >> 32) & 0xFF);
        head[pos++] = (char)((len >> 24) & 0xFF);        // 到这里就够传4GB数据了
        head[pos++] = (char)((len >> 16) & 0xFF);
        head[pos++] = (char)((len >> 8) & 0xFF);
        head[pos++] = (char)((len >> 0) & 0xFF);
    }


//    getRandomMaskKey(maskKey, sizeof(maskKey));    // 随机生成掩码
    maskKey[0] = 0xF2;
    maskKey[1] = 0xE9;
    maskKey[2] = 0x12;
    maskKey[3] = 0xBA;
    head[pos++] = (char)maskKey[0];
    head[pos++] = (char)maskKey[1];
    head[pos++] = (char)maskKey[2];
    head[pos++] = (char)maskKey[3];

    unsigned char temp1, temp2;
    for(int i = 0, count = 0; i < len; i++) {
        temp1 = maskKey[count];
        temp2 = data[i];
        head[pos++] = (char)(((~temp1) & temp2) | (temp1 & (~temp2)));  // 异或运算后得到数据
        count += 1;
        if(count >= sizeof(maskKey)) {   // maskKey[4]循环使用
            count = 0;
        }
        head[pos] = '\0';
    }

    return pos;
}

int WebSocketClient::WebSocketSend_(const char *data, int len, FrameHead type)
{
    int retLen;

    unsigned char* head = new unsigned char[sizeof(unsigned char) * (len + 128)];
    memset(head, 0, (len + 128));
//    char* head = (char*)malloc(sizeof(char) * (len + 128));
    retLen = buildFrameHead(head, (const unsigned char*)data, len, type);
    std::cout<<"send Msg data size = "<<retLen<<std::endl;

    int sslRet = SSL_write(m_ssl, head, retLen);
    std::cout<<"actual Send Msg Data size = "<<sslRet<<std::endl;
    if (sslRet == -1) {
        printf("SSL_write failed !!!\n");
        return -1;
    }

    delete head;
    head = nullptr;
    return sslRet;
}

int WebSocketClient::WebSocketRecv(unsigned char* payloadData, int len)
{
    char rec_buff[1024];
    size_t rec_buff_size = 1024;
    int dataSize;
    dataSize = SSL_read(m_ssl, rec_buff, rec_buff_size);

    FrameHead type = DataFrameType((unsigned char*)rec_buff, dataSize);
    std::cout<<"type = "<<type<<std::endl;

    if (type == opcode_text || type == opcode_binary || type == opcode_continuation) {

        memset(rec_buff, 0, rec_buff_size * sizeof(char));
        dataSize = SSL_read(m_ssl, rec_buff, rec_buff_size);
        memcpy(payloadData, rec_buff, strlen(rec_buff));
//        std::cout<<"actuall recv data = "<<std::string(rec_buff)<<std::endl;
//        type = DataFrameDecoding((unsigned char*)rec_buff, dataSize, payloadData);
//        std::cout<<"payloadData =  "<<string((const char*)payloadData)<<std::endl;
    }
    if (type == opcode_noOpCode) {
        memset(rec_buff, 0, rec_buff_size * sizeof(char));
        dataSize = SSL_read(m_ssl, rec_buff, rec_buff_size);
        type = DataFrameDecoding_((unsigned char*)rec_buff, dataSize, payloadData);
        std::cout<<"payloadData =  "<<string((const char*)payloadData)<<std::endl;
    }

    return dataSize;
}

WebSocketClient::FrameHead WebSocketClient::DataFrameType(unsigned char *data, int dataLen)
{
    if (dataLen != 2) {
        std::cout<<"opcode_noOpCode"<<std::endl;
        return opcode_noOpCode;
    }

    FrameHead ret;
    char type = data[0] & 0x0F;

    if ((data[0] & 0x80) == 0x80) {
        if (type == 0x01) {
            ret = opcode_text;
        }
        else if (type == 0x02) {
            ret = opcode_binary;
        }
        else if (type == 0x08) {
            ret = opcode_close;
        }
        else if (type == 0x09) {
            ret = opcode_ping;
        }
        else if (type == 0x0A) {
            ret = opcode_binary;
        }
        else if (type == 0x08) {
            ret = opcode_pong;
        }
        else {
            return opcode_error;
        }
    }
    else if ((data[0] & 0x80) == 0x00) {
        ret = opcode_continuation;
    }
    else {
        return opcode_error;
    }

    return ret;
}

WebSocketClient::FrameHead WebSocketClient::DataFrameDecoding(unsigned char *data, int dataLen, unsigned char* payloadData)
{
    FrameHead ret;
    unsigned int payloadLen = 0;
    unsigned int dataStart = 2;
    int count = 0;
    bool isMask;

    if((data[0] & 0x80) == 0x80) {
        isMask = true;
        count = 4;
    }
    else {
        isMask = false;
        count = 0;
    }

    std::cout<<isMask<<std::endl;

    payloadLen = data[0] & 0x7F;
    if (payloadLen == 126) {

        if (dataLen < 4) {
            return opcode_error;
        }

        payloadLen = data[1];
        payloadLen = (payloadLen << 8) + data[2];
        if (dataLen < payloadLen + 4) {
            return opcode_error;
        }
        if (isMask) {
            dataStart = 6;
            // do something
        }
        else {
            dataStart = 2;
        }
    }
    else if (payloadLen == 127) {

        if (dataLen < 10) {
            return opcode_error;
        }

        if(data[1] != 0 || data[2] != 0 || data[3] != 0 || data[4] != 0) {  // 使用8个字节存储长度时, 前4位必须为0, 装不下那么多数据...
            return opcode_error;
        }
        payloadLen = data[5];
        payloadLen = (payloadLen << 8) + data[6];
        payloadLen = (payloadLen << 8) + data[7];
        payloadLen = (payloadLen << 8) + data[8];
        if(dataLen < payloadLen + 10) {
            return opcode_error;
        }

        if(isMask) {
            dataStart = 12;
            // do something
        }
        else {
            dataStart = 8;
        }
    } else {

        if(dataLen < payloadLen + 2) {
            return opcode_error;
        }

        if(isMask) {
            dataStart = 6;
        }
        else {
            dataStart = 0;
        }
    }

    if (dataLen < payloadLen + dataStart) {
        return opcode_error;
    }

    if (isMask) {

    }
    else {
        memcpy(payloadData, &data[dataStart], payloadLen);
        payloadData[payloadLen] = '\0';
    }

    return ret;
}

WebSocketClient::FrameHead WebSocketClient::DataFrameDecoding_(unsigned char *data, int dataLen, unsigned char* payloadData)
{
    FrameHead ret;
    unsigned int payloadLen = 0;
    unsigned int dataStart = 2;
    int count = 0;
    bool isMask;

    if((data[1] & 0x80) == 0x80) {
        isMask = true;
        count = 4;
    }
    else {
        isMask = false;
        count = 0;
    }

    payloadLen = data[1] & 0x7F;
    if (payloadLen == 126) {
        if (dataLen < 4) {
            return opcode_error;
        }

        payloadLen = data[2];
        payloadLen = (payloadLen << 8) + data[3];
        if (dataLen < payloadLen + 4 + count) {
            return opcode_error;
        }
        if (isMask) {
            dataStart = 6;
            // do something
        }
        else {
            dataStart = 4;
        }
    }
    else if (payloadLen == 127) {
        if (dataLen < 10) {
            return opcode_error;
        }

        if(data[2] != 0 || data[3] != 0 || data[4] != 0 || data[5] != 0) {  // 使用8个字节存储长度时, 前4位必须为0, 装不下那么多数据...
            return opcode_error;
        }
        payloadLen = data[6];
        payloadLen = (payloadLen << 8) + data[7];
        payloadLen = (payloadLen << 8) + data[8];
        payloadLen = (payloadLen << 8) + data[9];
        if(dataLen < payloadLen + 10 + count) {
            return opcode_error;
        }
        if(isMask) {
            dataStart = 14;
            // do something
        }
        else {
            dataStart = 10;
        }
    } else {

        if(dataLen < payloadLen + 2 + count) {
            return opcode_error;
        }

        if(isMask) {
            dataStart = 6;
        }
        else {
            dataStart = 2;
        }
    }

    if (dataLen < payloadLen + dataStart) {
        return opcode_error;
    }

    if (isMask) {

    }
    else {
        memcpy(payloadData, &data[dataStart], payloadLen);
        payloadData[payloadLen] = '\0';
    }

    return ret;
}


void WebSocketClient::getRandomMaskKey(unsigned char *buf, unsigned int len)
{
    unsigned int i;
    unsigned char temp;
    srand((int)time(0));
    for(i = 0; i < len; i++) {
        temp = (unsigned char)(rand()%256);
        if(temp == 0) {  // 随机数不要0, 0 会干扰对字符串长度的判断
            temp = 128;
        }
        buf[i] = temp;
    }
}

//void WebSocketClient::invertedString(char *str, int len)
//{
//    int i;
//    char temp;
//    for (i = 0; i < len/2; ++i) {
//        temp = *(str + i);
//        *(str + i) = *(str + len - i - 1);
//        *(str + len - i - 1) = temp;
//    }
//}


//int WebSocketClient::buildFrameHead(const unsigned char* data, unsigned int dataLen, unsigned char* package, unsigned int packageMaxLen, FrameHead type)
//{
//    unsigned char maskKey[4] = {0};    // 掩码
//    unsigned char temp1, temp2;
//    int count;
//    unsigned int i, len = 0;

//    if (packageMaxLen < 2) {
//        return -1;
//    }

//    switch (type) {
//    case opcode_continuation:
//        *package++ = 0x00;
//        break;
//    case opcode_text:
//        *package++ = 0x81;
//        break;
//    case opcode_binary:
//        *package++ = 0x82;
//        break;
//    case opcode_close:
//        *package++ = 0x88;
//        break;
//    case opcode_pong:
//        *package++ = 0x8A;
//        break;
//    case opcode_ping:
//        *package++ = 0x89;
//        break;
//    default:
//        return -1;
//    }

//    *package = 0x80;
//    len += 1;

//    if (dataLen < 126) {
//        std::cout<<"payloadLen = 126"<<std::endl;
//        *package++ |= (dataLen & 0x7F);
//        len += 1;
//    }
//    else if (dataLen < 65536) {
//        std::cout<<"payloadLen = 65536"<<std::endl;
//        if(packageMaxLen < 4) {
//            return -1;
//        }
//        *package++ |= 0x7E;
//        *package++ = (char)((dataLen >> 8) & 0xFF);
//        *package++ = (unsigned char)((dataLen >> 0) & 0xFF);
//        len += 3;
//    }
//    else if(dataLen < 0xFFFFFFFF) {
//        std::cout<<"payloadLen = 0xFFFFFFFF"<<std::endl;
//        if(packageMaxLen < 10) {
//            return -1;
//        }
//        *package++ |= 0x7F;
//        *package++ = 0; //(char)((dataLen >> 56) & 0xFF);   // 数据长度变量是 unsigned int dataLen, 暂时没有那么多数据
//        *package++ = 0; //(char)((dataLen >> 48) & 0xFF);
//        *package++ = 0; //(char)((dataLen >> 40) & 0xFF);
//        *package++ = 0; //(char)((dataLen >> 32) & 0xFF);
//        *package++ = (char)((dataLen >> 24) & 0xFF);        // 到这里就够传4GB数据了
//        *package++ = (char)((dataLen >> 16) & 0xFF);
//        *package++ = (char)((dataLen >> 8) & 0xFF);
//        *package++ = (char)((dataLen >> 0) & 0xFF);
//        len += 9;
//    }

//    if(packageMaxLen < len + dataLen + 4) {
//        return -1;
//    }
////    getRandomMaskKey(maskKey, sizeof(maskKey));    // 随机生成掩码
//    maskKey[0] = 0xF2;
//    maskKey[1] = 0xE9;
//    maskKey[2] = 0x12;
//    maskKey[3] = 0xBA;
//    *package++ = maskKey[0];
//    *package++ = maskKey[1];
//    *package++ = maskKey[2];
//    *package++ = maskKey[3];
//    len += 4;

//    for(i = 0, count = 0; i < dataLen; i++) {
//        temp1 = maskKey[count];
//        temp2 = data[i];
//        *package++ = (char)(((~temp1) & temp2) | (temp1 & (~temp2)));  // 异或运算后得到数据
//        count += 1;
//        if(count >= sizeof(maskKey)) {   // maskKey[4]循环使用
//            count = 0;
//        }
//        len += i;
//        *package = '\0';
//    }

//    return len;
//}

//int WebSocketClient::WebSocketSend(const unsigned char* data, unsigned int dataLen, FrameHead type)
//{
//    unsigned char *webSocketPackage;
//    unsigned int retLen;
//    webSocketPackage = (unsigned char *)calloc(1, sizeof(char)*(dataLen + 128));
//    memset(webSocketPackage, 0, (dataLen + 128));
//    retLen = buildFrameHead(data, dataLen, webSocketPackage, (dataLen + 128), type);
//    std::cout<<"retLen = "<<strlen((const char*)webSocketPackage)<<std::endl;
//    for(int i = 0; i < strlen((const char*)webSocketPackage); i++)  printf("%.2X ", webSocketPackage[i]);
//    std::cout<<std::endl;

//    int sslRet = SSL_write(m_ssl, webSocketPackage, retLen);
//    if (sslRet == -1) {
//        printf("SSL_write failed !!!\n");
//        return -1;
//    }

//    free(webSocketPackage);

//    return sslRet;
//}

char* WebSocketClient::base64_decode(const char *data, int data_len)
{
    int ret_len = (data_len / 4) * 3;
    int equal_count = 0;
    char *ret = NULL;
    char *f = NULL;
    int tmp = 0;
    int temp = 0;
    char need[3];
    int prepare = 0;
    int i = 0;
    if (*(data + data_len - 1) == '=') {
        equal_count += 1;
    }
    if (*(data + data_len - 2) == '=') {
        equal_count += 1;
    }
    if (*(data + data_len - 3) == '=') { //seems impossible
        equal_count += 1;
    }
    switch (equal_count) {
    case 0:
        ret_len += 4;//3 + 1 [1 for NULL]
        break;
    case 1:
        ret_len += 4;//Ceil((6*3)/8)+1
        break;
    case 2:
        ret_len += 3;//Ceil((6*2)/8)+1
        break;
    case 3:
        ret_len += 2;//Ceil((6*1)/8)+1
        break;
    }
    ret = (char *)malloc(ret_len);
    if (ret == NULL)
    {
        printf("No enough memory.\n");
        exit(0);
    }
    memset(ret, 0, ret_len);
    f = ret;
    while (tmp < (data_len - equal_count))
    {
        temp = 0;
        prepare = 0;
        memset(need, 0, 4);
        while (temp < 4)
        {
            if (tmp >= (data_len - equal_count))
            {
                break;
            }
            prepare = (prepare << 6) | (find_pos(data[tmp]));
            temp++;
            tmp++;
        }
        prepare = prepare << ((4-temp) * 6);
        for (i=0; i<3 ;i++ )
        {
            if (i == temp)
            {
                break;
            }
            *f = (char)((prepare>>((2-i)*8)) & 0xFF);
            f++;
        }
    }
    *f = '\0';
    return ret;
}

char* WebSocketClient::base64_encode(const char* data, int data_len)
{
    const char base[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
    //int data_len = strlen(data);
    int prepare = 0;
    int ret_len;
    int temp = 0;
    char *ret = NULL;
    char *f = NULL;
    int tmp = 0;
    char changed[4];
    int i = 0;
    ret_len = data_len / 3;
    temp = data_len % 3;
    if (temp > 0)
    {
        ret_len += 1;
    }
    ret_len = ret_len*4 + 1;
    ret = (char *)malloc(ret_len);

    if ( ret == NULL)
    {
        printf("No enough memory.\n");
        exit(0);
    }
    memset(ret, 0, ret_len);
    f = ret;
    while (tmp < data_len)
    {
        temp = 0;
        prepare = 0;
        memset(changed, '\0', 4);
        while (temp < 3)
        {
            //printf("tmp = %d\n", tmp);
            if (tmp >= data_len)
            {
                break;
            }
            prepare = ((prepare << 8) | (data[tmp] & 0xFF));
            tmp++;
            temp++;
        }
        prepare = (prepare<<((3-temp)*8));

        for (i = 0; i < 4 ;i++ )
        {
            if (temp < i)
            {
                changed[i] = 0x40;
            }
            else
            {
                changed[i] = (prepare>>((3-i)*6)) & 0x3F;
            }
            *f = base[changed[i]];
            //printf("%.2X", changed[i]);
            f++;
        }
    }
    *f = '\0';

    return ret;
}

char WebSocketClient::find_pos(char ch)
{
    const char base[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
    char *ptr = (char*)strrchr(base, ch);//the last position (the only) in base[]
    return (ptr - base);
}
