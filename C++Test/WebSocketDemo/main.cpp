#include <libwebsockets.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>
#include "WebSocketClient.h"
#include <stdio.h>
#include <../VR/toolsManager/VR_CurlHttpTool.h>
#include <netdb.h>
#include <arpa/inet.h>
//#include <websocketpp/websocketpp/config/asio_client.hpp>
//#include <websocketpp/websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/websocketpp/client.hpp>
//#include <boost/asio/ssl.hpp>
#include <uuid/uuid.h>
#include "base64.h"
//#include "sha1.h"
#include <pthread.h>
#include <boost/algorithm/string.hpp>

typedef websocketpp::client<websocketpp::config::asio_client> client;
typedef websocketpp::config::asio_client::message_type::ptr message_ptr;
//typedef websocketpp::lib::shared_ptr<boost::asio::ssl::context> context_ptr;
typedef client::connection_ptr connection_ptr;

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

//void on_socket_init(websocketpp::connection_hdl hdl) {
//     m_socket_init = std::chrono::high_resolution_clock::now();
//}

// 打开连接时的回调
void on_open(client *c, websocketpp::connection_hdl hdl) {
    std::string msg = "{" \
                      "action: start," \
                      "content-type: audio/l16;rate=22050" \
                    "}";
    // 发送文本消息
    c->send(hdl, msg, websocketpp::frame::opcode::text);
    c->get_alog().write( websocketpp::log::alevel::app, "Tx: " + msg);
    printf("send msg = %s\n", msg.c_str());
}

// 连接失败时的回调
void on_fail(client *c, websocketpp::connection_hdl hdl) {
    c->get_alog().write( websocketpp::log::alevel::app, "Connection Failed");
    printf("Connection Failed\n");
}

// 接收到服务器发来的WebSocket消息后的回调
void on_message(client *c, websocketpp::connection_hdl hdl, message_ptr msg) {
    c->get_alog().write( websocketpp::log::alevel::app, "Rx: " + msg->get_payload());
    printf("recv msg = %s\n", msg->get_payload().c_str());
    // 关闭连接，导致事件循环退出
    c->close(hdl, websocketpp::close::status::normal, "" );
}

// 关闭连接时的回调
void on_close(client *c, websocketpp::connection_hdl hdl ) {
}

void boostWebSocket(const std::string& str)
{
    printf("token is [%s]\n", str.c_str());
    // 初始化ASIO ASIO
    client echo_client;
    echo_client.clear_access_channels(websocketpp::log::alevel::frame_header);
    echo_client.clear_access_channels(websocketpp::log::alevel::frame_payload);

    std::string uri = "wss://stream.watsonplatform.net/speech-to-text/api/v1/recognize?watson-token=" + str + "&model=es-ES_BroadbandModel";
//    std::string uri = "wss://echo.websocket.org";
    try {
         echo_client.init_asio();

         // 注册回调函数
//         echo_client.set_tls_init_handler([&echo_client](websocketpp::connection_hdl){
//             return websocketpp::lib::make_shared<boost::asio::ssl::context>(boost::asio::ssl::context::tlsv1);
//         });
         echo_client.set_open_handler(std::bind(&on_open, &echo_client, ::_1));
         echo_client.set_fail_handler(std::bind(&on_fail, &echo_client, ::_1));
         echo_client.set_message_handler(std::bind(&on_message, &echo_client, ::_1, ::_2));
         echo_client.set_close_handler(std::bind(&on_close, &echo_client, ::_1));

//         // 在事件循环启动前创建一个连接对象
         websocketpp::lib::error_code ec;
         client::connection_ptr con = echo_client.get_connection(uri, ec);

         if (ec) {
             std::cout << "could not create connection because: " << ec.message() << std::endl;
             return;
         }

         echo_client.connect(con);
         con->get_handle(); // 连接句柄，发送消息时必须要传入

         // 启动事件循环（ASIO的io_service），当前线程阻塞
         echo_client.run();
     } catch ( const std::exception &e ) {
         std::cout << e.what() << std::endl;
     } catch ( websocketpp::lib::error_code e ) {
         std::cout << e.message() << std::endl;
     } catch ( ... ) {
         std::cout << "other exception" << std::endl;
     }
}







static int interrupted, bad = 1, status;
static struct lws *client_wsi;

static int callback_http(struct lws *wsi, enum lws_callback_reasons reason, void *user, void *in, size_t len)
{
    printf("current reason value is [%d]\n", reason);
    switch (reason) {

    /* because we are protocols[0] ... */
    case LWS_CALLBACK_CLIENT_CONNECTION_ERROR:
        lwsl_err("CLIENT_CONNECTION_ERROR: %s\n",
                 in ? (char *)in : "(null)");
        client_wsi = NULL;
        break;

    case LWS_CALLBACK_ESTABLISHED_CLIENT_HTTP:
        status = lws_http_client_http_response(wsi);
        lwsl_user("Connected with server response: %d\n", status);
        break;

        /* chunks of chunked content, with header removed */
    case LWS_CALLBACK_RECEIVE_CLIENT_HTTP_READ:
        lwsl_user("RECEIVE_CLIENT_HTTP_READ: read %d\n", (int)len);
        return 0; /* don't passthru */

        /* uninterpreted http content */
    case LWS_CALLBACK_RECEIVE_CLIENT_HTTP:
    {
        char buffer[1024 + LWS_PRE];
        char *px = buffer + LWS_PRE;
        int lenx = sizeof(buffer) - LWS_PRE;

        if (lws_http_client_read(wsi, &px, &lenx) < 0)
            return -1;
    }
        return 0; /* don't passthru */

    case LWS_CALLBACK_COMPLETED_CLIENT_HTTP:
        lwsl_user("LWS_CALLBACK_COMPLETED_CLIENT_HTTP\n");
        client_wsi = NULL;
        bad = status != 200;
        lws_cancel_service(lws_get_context(wsi)); /* abort poll wait */
        break;

    case LWS_CALLBACK_CLOSED_CLIENT_HTTP:
        client_wsi = NULL;
        bad = status != 200;
        lws_cancel_service(lws_get_context(wsi)); /* abort poll wait */
        break;

    default:
        break;
    }

    return lws_callback_http_dummy(wsi, reason, user, in, len);
}

struct pss {
    int send_a_ping;
};


static const struct lws_protocols protocols[] = {
{
    "chat",
    callback_http,
    sizeof(struct pss),
    0,
},
{ NULL, NULL, 0, 0 }
};

static void sigint_handler(int sig)
{
    interrupted = 1;
}


int IBMTest(const std::string str)
{
    std::string ip("stream.watsonplatform.net");
    struct hostent *p_hostent = gethostbyname(ip.c_str());

    if (p_hostent == nullptr) {
        printf("gethostbyname failed!\n");
        return -1;
    }

    sockaddr_in addr_server;
    addr_server.sin_family = AF_INET;
    addr_server.sin_port = htons(443);
    memcpy(&(addr_server.sin_addr), p_hostent->h_addr_list[0], sizeof(addr_server.sin_addr));

    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    int res = connect(sock, (sockaddr*)&addr_server, sizeof(addr_server));

    if(res == -1) {
        cout<< "Connect failed !!"<<endl;
        close(sock);
        return -1;
    }

    string sendData = "GET /speech-to-text/api/v1/recognize?watson-token=" + str + "&model=es-ES_BroadbandModel HTTP/1.1\x0d\x0a";
    sendData += "Upgrade: websocket\x0d\x0a";
    sendData += "Host: stream.watsonplatform.net\x0d\x0a";
    sendData += "Connection: Upgrade\x0d\x0a";
    sendData += "Sec-WebSocket-Key: dGhlIHNhbXBsZSBub25jZQ==\x0d\x0a";
    sendData += "Sec-WebSocket-Version: 13\x0d\x0a";
    sendData += "Sec-WebSocket-Protocol: chat, superchat\x0d\x0a";
//    sendData += "Origin: wss://stream.watsonplatform.net\x0d\x0a";
    sendData += "\x0d\x0a";

    printf("protocol is %s\n", sendData.c_str());

    if (send(sock, sendData.c_str(), sendData.size(), MSG_NOSIGNAL) == -1) {
        printf("send failed !!!\n");
    }
    printf("send success !!!\n");

    std::string resp;
    char rec_buff[1024];
    while (recv(sock, rec_buff, sizeof(rec_buff), 0) > 0) {
        resp += string(rec_buff);
        memset(rec_buff, 0, sizeof(rec_buff));
    }

    printf("resp = %s\n", resp.c_str());
    close(sock);
    return -1;
}

inline size_t onWriteData(void * buffer, size_t size, size_t nmemb, void * userp)
{
    std::string * str = dynamic_cast<std::string *>((std::string *)userp);
    str->append((char *)buffer, size * nmemb);
    return nmemb;
}


static struct lws_context *context;
static int zero_length_ping;
static const char* url = "speech-to-text/api/v1/recognize";
static const char* ads = "wss://stream.watsonplatform.net";
static const char* token = "";
static const char* model = "es-ES_BroadbandModel";

static const struct lws_protocol_vhost_options pvo_ads = {
    NULL,
    NULL,
    "ads",
    (char*)&ads
};

static const struct lws_protocol_vhost_options pvo_url = {
    &pvo_ads,
    NULL,
    "url",
    (char*)&url
};

static const struct lws_protocol_vhost_options pvo_token = {
    &pvo_url,
    NULL,
    "watson-token",
    (char*)&token
};

static const struct lws_protocol_vhost_options pvo_model = {
    &pvo_model,
    NULL,
    "model",
    (char*)&model
};

static const struct lws_protocol_vhost_options pvo = {
    NULL,
    &pvo_model,
    NULL,
    NULL
};

static const struct lws_protocols ws_protocols[] = {
{
    NULL,
    callback_http,
    128,
    0,
},
{ NULL, NULL, 0, 0 }
};


static volatile int exit_sig = 0;
void sighdl(int sig) {
    lwsl_notice("%d traped", sig);
    exit_sig = 1;
}
#define MAX_PAYLOAD_SIZE  10 * 1024
struct session_data {
    int msg_count;
    unsigned char buf[LWS_PRE + MAX_PAYLOAD_SIZE];
    int len;
};

int callback(struct lws *wsi, enum lws_callback_reasons reason, void *user, void *in, size_t len) {
    struct session_data *data = (struct session_data *) user;
    switch ( reason ) {
        case LWS_CALLBACK_CLIENT_ESTABLISHED:   // 连接到服务器后的回调
            lwsl_notice( "Connected to server\n" );
            break;
        case LWS_CALLBACK_CLIENT_RECEIVE:       // 接收到服务器数据后的回调，数据为in，其长度为len
            lwsl_notice( "Rx: %s\n", (char *) in );
            break;
        case LWS_CALLBACK_CLIENT_WRITEABLE:     // 当此客户端可以发送数据时的回调
            if ( data->msg_count < 3 ) {
                // 前面LWS_PRE个字节必须留给LWS
                memset( data->buf, 0, sizeof( data->buf ));
                char *msg = (char *) &data->buf[ LWS_PRE ];
                data->len = sprintf( msg, "你好 %d", ++data->msg_count );
                lwsl_notice( "Tx: %s\n", msg );
                // 通过WebSocket发送文本消息
                lws_write( wsi, &data->buf[ LWS_PRE ], data->len, LWS_WRITE_TEXT );
            }
            break;
    }
    return 0;
}

struct lws_protocols protocols2[] = {
    {
    //协议名称，协议回调，接收缓冲区大小
    "",
    callback,
    sizeof( struct session_data ),
    MAX_PAYLOAD_SIZE,
    },
    {
    NULL, NULL,   0 // 最后一个元素固定为此格式
    }
};

static int connect_client(const std::string str)
{
    signal(SIGTERM, sighdl);
    printf("Enter connect_client function\n");
    struct lws_context_creation_info info = { 0 };

    struct lws_client_connect_info i;

    memset(&info, 0, sizeof(info));

    info.iface = nullptr;
    info.port = CONTEXT_PORT_NO_LISTEN;
    info.protocols = protocols2;
    //info.pvo = &pvo;
    context = lws_create_context(&info);

    std::string token = str;
    std::string url = "/speech-to-text/api/v1/recognize";
    std::string param = "&model=es-ES_BroadbandModel";
    std::string path = url + token + param;

    i.context = context;
    i.port = 443;
    i.address = "stream.watsonplatform.net";
    i.path = path.c_str();
    i.host = "stream.watsonplatform.net";
    i.origin = "wss://stream.watsonplatform.net";
    i.ssl_connection = 0;
//    i.pwsi = &client_wsi;
    i.method = "POST";
    i.protocol = protocols2[0].name;

    struct lws *_wsi = lws_client_connect_via_info(&i);
    while (!exit_sig) {
        lws_service(context, 10000);
        lws_callback_on_writable(_wsi);
    }
    lws_context_destroy(context);
    printf("Exit connect_client function\n");
}


void test3()
{
    std::string resp;
    CURL* curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, "https://stream.watsonplatform.net/authorization/api/v1/token?url=https://stream.watsonplatform.net/speech-to-text/api");
    curl_easy_setopt(curl, CURLOPT_HEADER, false);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, onWriteData);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*) &resp);
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, true);
    curl_easy_setopt(curl, CURLOPT_USERPWD, "cdc333fa-f2b8-4bf7-87b0-abc1453ca8d1:gWZIPLVdVX87");
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false);
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);
//    WebSocketClient* _p = WebSocketClient::getInstance();
//    _p->SendHtmlData(resp);
//    _p->connectIBM(resp);

//    sleep(1);
//    _p->sendDataToIBM(startVR);
//    IBMTest(resp);
//    boostWebSocket(resp);
//    int code = connect_client(resp);
//    printf("Code is [%d]\n", code);
}

//void WEIRUAN()
//{
//    uuid_t uuid;
//    char str_uuid[64];
//    uuid_generate(uuid);
//    uuid_unparse(uuid, str_uuid);
//    printf("uuid = %s\n", str_uuid);

//    VR_CurlHttpTool cht;
//    cht.setDebug(false);

//    std::string token = "https://api.cognitive.microsoft.com/sts/v1.0/issueToken";
//    std::string response;

//    CurlMap params;
//    CurlMap header;

//    header.insert(make_pair<string, string>("Content-Length", "0"));
//    header.insert(make_pair<string, string>("Ocp-Apim-Subscription-Key", "199dfcafd3da478eaee2a4b35c238de9"));
//    header.insert(make_pair<string, string>("Host", "api.cognitive.microsoft.com"));
//    header.insert(make_pair<string, string>("Content-type", "application/x-www-form-urlencoded"));
//    header.insert(make_pair<string, string>("Connection", "Keep-Alive"));

//    cht.PostHttp(token, header, params, &response);

//    std::string Authorization("Bearer ");
//    Authorization.append(response);

//    response.clear();
//    header.clear();

//    printf("token = %s\n", Authorization.c_str());
//}

bool StringToHex(const string &input, string &out)
{
    out.clear();
    string tmp;
    stringstream ss;
    for(int i = 0; i < input.size(); i++) {
        ss<<hex<<int(input[i])<<endl;
        ss>>tmp;
        out += tmp;
    }

    return true;
}

int huyangGetHttp(const string &ip, std::string& resp)
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


int main()
{
//    string PayloadData = "{\"action\": \"start\",\"content-type\": \"audio/wav;rate=16000\"}";
//    std::cout<<PayloadData.size()<<std::endl;
//    string startVR = "81 85";

//    IBMTest();
//    test3();
//    while(true);
//    WEIRUAN();
//    std::string resp;
//    WebSocketClient* _p = WebSocketClient::getInstance();
//    huyangGetHttp("api.goseek.cn", resp);
//    printf("resp is [%s]\n", resp.c_str());


    VR_CurlHttpTool curlHttp;
    CurlMap mapformat;
//    mapformat["client_id"] = "42bc8cbfbe1847c2bfe00546a7deb080";
//    mapformat["response_type"] = "code";
//    mapformat["redirect_uri"] = "https://www.baidu.com";
//    mapformat["state"] = "34fFs29kd09";

    std::string resp;
//    std::string url = "https://accounts.spotify.com/authorize";
    CurlMap header;
//    int code = curlHttp.GetHttp(url, header, mapformat, &resp);
    url = "https://accounts.spotify.com/en/login";

    int code = curlHttp.GetHttp(url, header, mapformat, &resp);
    std::string cookie = curlHttp.getCookie();
    cookie = cookie.substr(cookie.find("csrf_token") + 10, cookie.size());
    boost::trim(cookie);

    printf("cookie = %s\n", cookie.c_str());
    std::cout<<"resp = "<<resp<<std::endl;

    std::cout<<"========================================post format======================================="<<std::endl;

    mapformat.clear();
    resp.clear();
    header.clear();
    url = "https://accounts.spotify.com/api/login";

    mapformat["remember"] = "true";
    mapformat["username"] = "huyang@iauto.com";
    mapformat["password"] = "123456suntec";
    mapformat["csrf_token"] = cookie;
    mapformat["captcha_token"] = "";

//    header["Accept"] = "application/json, text/plain, */*";
//    header["Accept-Encoding"] = "gzip, deflate, br";
//    header["Accept-Language"] = "zh-CN,zh;q=0.8";
//    header["Connection"] = "keep-alive";
//    header["Content-Length"] = "222";
//    header["Content-Type"] = "application/x-www-form-urlencoded";
//    header["Cookie"] = "_gat=1; csrf_token="+ cookie + "; fb_continue=https%3A%2F%2Faccounts.spotify.com%2Fen%2Fstatus; remember=huyang%40iauto.com; _ga=GA1.2.2622537.1542957362; _gid=GA1.2.125532698.1543204866";
//    header["Host"] = "accounts.spotify.com";
//    header["Origin"] = "https://accounts.spotify.com";
//    header["Referer"] = "https://accounts.spotify.com/en/login";

    CurlMap nullmap;
    code = curlHttp.PostHttp(url, header, nullmap, mapformat, &resp);
    std::cout<<"resp = "<<resp<<std::endl;
    std::cout<<"code = "<<code<<std::endl;

}
