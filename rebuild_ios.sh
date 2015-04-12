rm -rf      __builds/ios
rm -rf      __platforms/ios
mkdir -p    __builds/ios
mkdir -p    __platforms/ios
mkdir -p    __platforms/ios/lib/universal
pushd       __builds/ios
cmake ../.. -DCMAKE_TOOLCHAIN_FILE=../../toolchains/ios.cmake -DCMAKE_INSTALL_PREFIX=../../__platforms/ios -G Xcode
popd
./build_ios.sh $1
