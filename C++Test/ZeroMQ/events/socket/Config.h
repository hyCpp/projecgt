#ifndef CONFIG
#define CONFIG
#include <boost/shared_ptr.hpp>
#include "boost/function.hpp"
//#include "google/protobuf/message_lite.h"
#include "/usr/local/include/google/protobuf/message_lite.h"

class EventContext;
typedef ::google::protobuf::MessageLite  protoBufMsg;
typedef protoBufMsg* bufMsgPtr;
typedef boost::function<void(bufMsgPtr)> MsgCallBack;
typedef boost::function<void(const std::string& id, bufMsgPtr)> MsgCallBackWithId;
typedef boost::function<void(const EventContext& context, bufMsgPtr)> MsgCallBackWithContext;

#endif // CONFIG

