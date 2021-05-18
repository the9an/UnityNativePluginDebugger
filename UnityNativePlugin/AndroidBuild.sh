ANDROID_NDK_ROOT= #YOUR NDK PATH

$ANDROID_NDK_ROOT/ndk-build NDK_PROJECT_PATH=. NDK_APPLICATION_MK=$SRCROOT/Application.mk $*
rm -rf $SRCROOT/Plugins/Android/**
mv -f $SRCROOT/libs/** $SRCROOT/Plugins/Android/

rm -rf $SRCROOT/libs
rm -rf $SRCROOT/obj
