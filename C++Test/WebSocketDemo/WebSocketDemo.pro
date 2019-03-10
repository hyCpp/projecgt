#####################################################################
# Automatically generated by qtpromaker
#####################################################################

TEMPLATE = app
TARGET = WebSocketDemo
QMAKE_CXXFLAGS += -std=c++11

PATHS *= \
    ./../externals/libwebsockets/build \
    ./../externals/libwebsockets/build/include \
    ./../externals/websocketpp/include

DEPENDPATH *= $$PATHS

INCLUDEPATH *= $$PATHS

SOURCES += \
    main.cpp \
    WebSocketClient.cpp \
    WebSocketHandler.cpp \
    ../VR/toolsManager/VR_CurlHttpTool.cpp \


LIBS += -L$$PWD/../externals/libwebsockets/build/lib/ -lwebsockets
LIBS += -L$$PWD/../../../../../usr/lib/x86_64-linux-gnu/ -lcurl -lcrypto -lssl -luuid -lboost_system -pthread

INCLUDEPATH += $$PWD/../externals/libwebsockets/build/include
DEPENDPATH += $$PWD/../externals/libwebsockets/build/include
DEPENDPATH += $$PWD/../externals/websocketpp/include
INCLUDEPATH += $$PWD/../externals/websocketpp/include

HEADERS += \
    WebSocketClient.h \
    WebSocketHandler.h \
    ../VR/toolsManager/VR_CurlHttpTool.cpp \
    base64.h \
    intLib.h \
    sha1.h

INCLUDEPATH += $$PWD/../../../../../usr/lib/x86_64-linux-gnu
DEPENDPATH += $$PWD/../../../../../usr/lib/x86_64-linux-gnu
