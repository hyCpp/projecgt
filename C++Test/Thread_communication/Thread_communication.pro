#####################################################################
# Automatically generated by qtpromaker
#####################################################################

TEMPLATE = app
TARGET = Thread_communication

SOURCES *= \
    ./ThreadTest/TestThreadA.cpp \
    ./ThreadTest/TestThreadB.cpp \
    ./common/CThread.cpp \
    ./common/CountingSemBase.cpp \
    ./common/MsgQueueBase.cpp \
    ./common/MutexBase.cpp \
    ./common/OperatingSystemBase.cpp \
    ./common/OperatingSystemFactory.cpp \
    ./common/TC_Log.cpp \
    ./implement/CountingSemImpl.cpp \
    ./implement/MsgQueueImpl.cpp \
    ./implement/MutexImpl.cpp \
    ./implement/OperatingSystemImpl.cpp \
    ./main.cpp \
    common/Log_Func.cpp

HEADERS *= \
    ./ThreadTest/TestThreadA.h \
    ./ThreadTest/TestThreadB.h \
    ./common/CThread.h \
    ./common/CountingSemBase.h \
    ./common/Log_Func.h \
    ./common/MsgQueueBase.h \
    ./common/MutexBase.h \
    ./common/OperatingSystemBase.h \
    ./common/OperatingSystemFactory.h \
    ./common/TC_Log.h \
    ./implement/CountingSemImpl.h \
    ./implement/MsgQueueImpl.h \
    ./implement/MutexImpl.h \
    ./implement/OperatingSystemImpl.h

PATHS *= \
    . \
    ./ThreadTest \
    ./common \
    ./implement

DEPENDPATH *= $$PATHS

INCLUDEPATH *= $$PATHS
