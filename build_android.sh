set -e
pushd       __builds/android-armeabi-v7a
make install VERBOSE=1
popd
cp __platforms/android-armeabi-v7a/lib/*.so projects/$1/libs/armeabi-v7a/
pushd       projects/$1
ant debug install
popd
