#=====================================module_variable=====================================

include $(CLEAR_VARS)

LOCAL_IS_HOST_MODULE := true

LOCAL_MODULE_CLASS := EXECUTABLES

tags_variable

LOCAL_MODULE := module_variable

LOCAL_MODULE_STEM := stem_variable

LOCAL_SRC_FILES := host/bin/stem_variable

LOCAL_BUILT_MODULE_STEM := stem_variable

LOCAL_MODULE_SUFFIX :=

LOCAL_STRIP_MODULE := true

LOCAL_MODULE_PATH := $(HOST_OUT)/bin

sharedlib_variable

include $(BUILD_PREBUILT)
