#=====================================module_variable.a=====================================

include $(CLEAR_VARS)

LOCAL_IS_HOST_MODULE := true

LOCAL_MODULE_CLASS := STATIC_LIBRARIES

LOCAL_MODULE_TAGS := optional

LOCAL_MODULE := module_variable

LOCAL_MODULE_STEM := stem_variable

LOCAL_SRC_FILES := host/staticlib/stem_variable.a

LOCAL_BUILT_MODULE_STEM := stem_variable.a

LOCAL_MODULE_SUFFIX := .a

LOCAL_UNINSTALLABLE_MODULE := true

include $(BUILD_PREBUILT)
