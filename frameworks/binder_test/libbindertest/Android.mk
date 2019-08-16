LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
    IBinderTestService.cpp 
LOCAL_MODULE:= libbindertest
LOCAL_MODULE_TAGS := optional

LOCAL_SHARED_LIBRARIES := \
    liblog \
    libcutils \
    libutils \
    libbinder

LOCAL_C_INCLUDES := \
    $(TOP)/frameworks/native/include 


include $(BUILD_SHARED_LIBRARY)
