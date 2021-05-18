APP_STL := c++_static
APP_CPPFLAGS := -frtti -DCC_ENABLE_CHIPMUNK_INTEGRATION=1 -std=c++11 -fsigned-char -Wno-extern-c-compat
APP_LDFLAGS := -latomic

APP_OPTIM        := debug
APP_ABI          := armeabi-v7a arm64-v8a x86
APP_PLATFORM     := android-16
APP_BUILD_SCRIPT := Android.mk