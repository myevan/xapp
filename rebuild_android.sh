rm -rf      __builds/android-armeabi-v7a
rm -rf      __platforms/android-armeabi-v7a
mkdir -p    __platforms/android-armeabi-v7a
mkdir -p    __builds/android-armeabi-v7a
mkdir -p    projects/android_project/libs/armeabi-v7a
pushd       __builds/android-armeabi-v7a
cmake ../.. -DCMAKE_TOOLCHAIN_FILE=../../toolchains/android.cmake -DANDROID_NDK=$NDK_HOME -DCMAKE_BUILD_TYPE=Release -DANDROID_ABI=armeabi-v7a -DCMAKE_INSTALL_PREFIX=../../__platforms/android-armeabi-v7a -DJNI_PACKAGE_NAME=x_framework 
popd
./build_android.sh $1
