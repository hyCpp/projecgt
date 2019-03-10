LOCAL_PATH := $(call my-dir)



#=====================================devicemanager=====================================

include $(CLEAR_VARS)

LOCAL_IS_HOST_MODULE :=

LOCAL_MODULE_CLASS := EXECUTABLES

LOCAL_MODULE_TAGS := optional

LOCAL_MODULE := devicemanager

LOCAL_MODULE_STEM := devicemanager

LOCAL_SRC_FILES := $(TARGET_PRODUCT)/bin/devicemanager

LOCAL_BUILT_MODULE_STEM := devicemanager

LOCAL_MODULE_SUFFIX :=

LOCAL_STRIP_MODULE := true

LOCAL_MODULE_PATH := $(TARGET_ROOT_OUT_SBIN)

LOCAL_SHARED_LIBRARIES := libicuuc \
    libcutils \
    liblog \
    libbinder \
    libncprocess \
    libncore \
    libutils \
    libnceventengine \
    libncservice \
    libnceventsys \


include $(BUILD_PREBUILT)


#=====================================libdmsprotodummy=====================================

include $(CLEAR_VARS)

LOCAL_IS_HOST_MODULE :=

LOCAL_MODULE_CLASS := SHARED_LIBRARIES

LOCAL_MODULE_TAGS := optional

OVERRIDE_BUILT_MODULE_PATH := $(TARGET_OUT_INTERMEDIATE_LIBRARIES)

LOCAL_MODULE := libdmsprotodummy

LOCAL_MODULE_STEM := libdmsprotodummy

LOCAL_SRC_FILES := $(TARGET_PRODUCT)/sharedlib/libdmsprotodummy.so

LOCAL_BUILT_MODULE_STEM := libdmsprotodummy.so

LOCAL_MODULE_SUFFIX := .so

LOCAL_STRIP_MODULE := true

LOCAL_MODULE_PATH := $(TARGET_ROOT_OUT)/lib

LOCAL_SHARED_LIBRARIES := libncore libcutils libutils

$(TARGET_OUT_INTERMEDIATE_LIBRARIES)/libdmsprotodummy.so: $(foreach dependlib,$(LOCAL_SHARED_LIBRARIES),$(TARGET_OUT_INTERMEDIATE_LIBRARIES)/$(dependlib).so)

include $(BUILD_PREBUILT)


#=====================================GENHEADFILE=====================================

include $(CLEAR_VARS)

LOCAL_COPY_HEADERS := GENHEADFILE/*.h \

LOCAL_COPY_HEADERS_TO :=
include $(BUILD_COPY_HEADERS)

