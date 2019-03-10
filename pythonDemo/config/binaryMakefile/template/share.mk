#=====================================xxxxxx.so=====================================

include $(CLEAR_VARS)

LOCAL_IS_HOST_MODULE :=

LOCAL_MODULE_CLASS := SHARED_LIBRARIES

yyyyyy

OVERRIDE_BUILT_MODULE_PATH := $(TARGET_OUT_INTERMEDIATE_LIBRARIES)

LOCAL_MODULE := xxxxxx

LOCAL_MODULE_STEM := xxxxxx

LOCAL_SRC_FILES := $(TARGET_PRODUCT)/sharedlib/xxxxxx.so

LOCAL_BUILT_MODULE_STEM := xxxxxx.so

LOCAL_MODULE_SUFFIX := .so

LOCAL_STRIP_MODULE := true

oooooo

hhhhhh

$(TARGET_OUT_INTERMEDIATE_LIBRARIES)/xxxxxx.so: $(foreach dependlib,$(LOCAL_SHARED_LIBRARIES),$(TARGET_OUT_INTERMEDIATE_LIBRARIES)/$(dependlib).so)

include $(BUILD_PREBUILT)
