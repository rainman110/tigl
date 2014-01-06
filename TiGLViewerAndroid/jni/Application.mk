#ANDROID APPLICATION MAKEFILE
APP_BUILD_SCRIPT := $(call my-dir)/Android.mk
#APP_PROJECT_PATH := $(call my-dir)

APP_OPTIM := release

APP_PLATFORM 	:= android-9
APP_STL 		:= gnustl_shared
APP_CPPFLAGS 	:= -fexceptions -frtti
APP_ABI 		:= armeabi-v7a
APP_MODULES     := TIGL_static tiglviewer-native