#!/bin/bash

ant debug && adb install -r bin/pulse-android-debug.apk && adb shell am start -n pt.fraunhofer.pulse/pt.fraunhofer.pulse.App
