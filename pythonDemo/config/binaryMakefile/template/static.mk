#=====================================xxxxxx.a=====================================

include $(CLEAR_VARS)

LOCAL_IS_HOST_MODULE :=

LOCAL_MODULE_CLASS := STATIC_LIBRARIES

LOCAL_MODULE_TAGS := optional

LOCAL_MODULE := xxxxxx

LOCAL_MODULE_STEM := xxxxxx

LOCAL_SRC_FILES := $(TARGET_PRODUCT)/staticlib/xxxxxx.a

LOCAL_BUILT_MODULE_STEM := xxxxxx.a

LOCAL_MODULE_SUFFIX := .a

LOCAL_UNINSTALLABLE_MODULE := true

include $(BUILD_PREBUILT)
