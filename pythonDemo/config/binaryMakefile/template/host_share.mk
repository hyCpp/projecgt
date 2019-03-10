#=====================================module_variable.so=====================================

include $(CLEAR_VARS)

LOCAL_IS_HOST_MODULE := true

LOCAL_MODULE_CLASS := SHARED_LIBRARIES

tags_variable

OVERRIDE_BUILT_MODULE_PATH := $(HOST_OUT_INTERMEDIATE_LIBRARIES)

LOCAL_MODULE := module_variable

LOCAL_MODULE_STEM := stem_variable

LOCAL_SRC_FILES := host/sharedlib/stem_variable.so

LOCAL_BUILT_MODULE_STEM := stem_variable.so

LOCAL_MODULE_SUFFIX := .so

LOCAL_STRIP_MODULE := true

LOCAL_MODULE_PATH := $(HOST_OUT)/lib

sharedlib_variable

$(HOST_OUT_INTERMEDIATE_LIBRARIES)/stem_variable.so: $(foreach dependlib,$(LOCAL_SHARED_LIBRARIES),$(HOST_OUT_INTERMEDIATE_LIBRARIES)/$(dependlib).so)

include $(BUILD_PREBUILT)
