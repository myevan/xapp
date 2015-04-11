pushd       __builds/android-armeabi-v7a
make install VERBOSE=1
popd
cp __platforms/android-armeabi-v7a/lib/*.so projects/android_project/libs/armeabi-v7a/
