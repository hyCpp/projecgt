#=====================================GENHEADFILE=====================================

include $(CLEAR_VARS)

LOCAL_COPY_HEADERS := GENHEADFILE/*.h \

LOCAL_COPY_HEADERS_TO :=
include $(BUILD_COPY_HEADERS)
