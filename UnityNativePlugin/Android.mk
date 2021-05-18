LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := UnityNativePlugin_shared
LOCAL_MODULE_FILENAME := libUnityNativePlugin
LOCAL_CFLAGS    := -Werror
CPP_FILES := $(shell find $(LOCAL_PATH)/UnityNativePlugin -name *.cpp)
CPP_FILES += $(shell find $(LOCAL_PATH)/UnityNativePlugin -name *.c)
LOCAL_SRC_FILES += $(CPP_FILES:$(LOCAL_PATH)/%=%)
LOCAL_C_INCLUDES := $(LOCAL_PATH)/UnityNativePlugin
LOCAL_LDLIBS    := -llog

include $(BUILD_SHARED_LIBRARY)