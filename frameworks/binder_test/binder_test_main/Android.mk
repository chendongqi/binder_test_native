LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
    main_binder_test.cpp
    
LOCAL_MODULE:= main_binder_test
LOCAL_MODULE_TAGS := optional

LOCAL_SHARED_LIBRARIES := \
    liblog \
    libbinder \
    libutils \
    libbindertestservice \
    libbindertest

LOCAL_C_INCLUDES := \
    $(TOP)/frameworks/binder_test

include $(BUILD_EXECUTABLE)
