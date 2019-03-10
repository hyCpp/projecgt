#ifndef WEBSOCKETCLIENT
#define WEBSOCKETCLIENT

#include "WebSocketHandler.h"

#define TIMEWAIT 100
#define BUFFLEN 2048
#define MAXEVENTSSIZE 20
#define IP "204.79.197.200"
#define HTTPWSPORT 80
#define HTTPSWSSPORT 443


#define IBM_HOST_NAME "wss://stream.watsonplatform.net/speech-to-text/api/v1/recognize"
#include <thread>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <openssl/ssl.h>
#include <queue>
#include <atomic>
#include <condition_variable>
#include <mutex>

using namespace std;

class WebSocketClient {
public:
    typedef unsigned char BYTE;
    typedef unsigned long long LLONG;
    enum FrameHead {
        opcode_continuation = 0,
        opcode_text,
        opcode_binary,
        opcode_close,
        opcode_pong,
        opcode_ping,
        opcode_error,
        opcode_noOpCode,
    };

    int init();

    int connectIBM(const std::string& str);
    int sendDataToIBM(const std::string& data);

    int GetHttp(const std::string& ip, std::string& resp);
    int GetHttps(const std::string& ip, std::string& resp);

    char* base64_encode(const char* data, int data_len);
    char* base64_decode(const char *data, int data_len);
    char find_pos(char ch);
public:

    static WebSocketClient *getInstance();

private:
    WebSocketClient();
    ~WebSocketClient();

    static void recvThread(WebSocketClient* ssl);
    bool run();

    // --------------
//    void invertedString(char *str, int len);
//    int buildFrameHead(const unsigned char* data, unsigned int dataLen, unsigned char* package, unsigned int packageMaxLen, FrameHead type);
//    int WebSocketSend(const unsigned char *data, unsigned int dataLen, FrameHead type);


    //---------------
    int buildFrameHead(unsigned char* head, const unsigned char* data, unsigned int len, FrameHead type);
    int WebSocketSend_(const char* data, int len, FrameHead type);
    void getRandomMaskKey(unsigned char *buf, unsigned int len);

    int sendWavData();


    int WebSocketRecv(unsigned char* data, int len);
    FrameHead DataFrameDecoding(unsigned char *data, int dataLen, unsigned char* payloadData);
    FrameHead DataFrameDecoding_(unsigned char *data, int dataLen, unsigned char* payloadData);
    FrameHead DataFrameType(unsigned char *data, int dataLen);


private:
    int m_listenfd;
    static WebSocketClient *m_pWebSocketClient;
    string m_token;
    SSL* m_ssl;
    int m_socket;
    SSL_CTX* m_ctx;
    std::queue<std::string> m_MsgQueue;

    pthread_mutex_t m_mutex;
    pthread_mutexattr_t m_attr;
    pthread_cond_t m_cond;

};

#endif // WEBSOCKETCLIENT

