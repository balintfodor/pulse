#!/bin/bash

cd pulse-android
android update project --path . --target android-17

read -p "Please enter the path to the Android NDK root folder: " -i "$HOME/" -e NDK_PATH
echo "ndk.dir=$NDK_PATH" >> local.properties

wget -c http://downloads.sourceforge.net/project/opencvlibrary/opencv-android/2.4.5/OpenCV-2.4.5-android-sdk.zip

mkdir -p libs/
unzip OpenCV-2.4.5-android-sdk.zip -d libs/
rm OpenCV-2.4.5-android-sdk.zip

cd libs/OpenCV-2.4.5-android-sdk/sdk/java/
android update project --path . --target android-17
cd ../../../../
#ant debug
