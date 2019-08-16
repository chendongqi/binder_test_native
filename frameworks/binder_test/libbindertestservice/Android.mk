LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
    BinderTestService.cpp
LOCAL_MODULE:= libbindertestservice
LOCAL_MODULE_TAGS := optional

LOCAL_SHARED_LIBRARIES := \
    liblog \
    libcutils \
    libutils \
    libbinder \
    libbindertest

LOCAL_C_INCLUDES := \
    $(TOP)/frameworks/native/include \
    $(TOP)/frameworks/binder_test


include $(BUILD_SHARED_LIBRARY)
