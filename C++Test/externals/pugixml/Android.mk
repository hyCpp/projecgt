LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE:= libpugixml-navi

LOCAL_MODULE_TAGS   := optional

LOCAL_C_INCLUDES += $(LOCAL_PATH) \

LOCAL_SRC_FILES:= \
        pugixml.cpp \

LOCAL_CFLAGS += -DCOMPILER_GCC_SMT -Wall -Werror -Wunused -Wunreachable-code
LOCAL_CXXFLAGS += -DCOMPILER_GCC_SMT -fno-rtti -std=c++11

include $(BUILD_STATIC_LIBRARY)
