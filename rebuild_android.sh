rm -rf      __builds/android-armeabi-v7a
rm -rf      __platforms/android-armeabi-v7a
mkdir -p    __platforms/android-armeabi-v7a
mkdir -p    __builds/android-armeabi-v7a
pushd       __builds/android-armeabi-v7a
cmake ../.. -DCMAKE_TOOLCHAIN_FILE=../../toolchains/android.cmake -DANDROID_NDK=$NDK_HOME -DANDROID_ABI=armeabi-v7a -DCMAKE_INSTALL_PREFIX=../../__platforms/android-armeabi-v7a -DANDROID_NATIVE_API_LEVEL=android-15 -DJNI_PACKAGE_NAME=x_framework -DCMAKE_BUILD_TYPE=Debug -DANDROID_PROJECT_DIR=../../projects/$1
popd
./build_android.sh $1
