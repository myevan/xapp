rm -rf      __builds/ios
rm -rf      __platforms/ios
mkdir -p    __builds/ios
mkdir -p    __platforms/ios
mkdir -p    __platforms/ios/lib/universal
pushd       __builds/ios
cmake ../.. -DCMAKE_TOOLCHAIN_FILE=../../toolchains/ios.cmake -DCMAKE_INSTALL_PREFIX=../../__platforms/ios -G Xcode
xcodebuild -configuration Release -sdk iphonesimulator -arch i386 -arch x86_64 -target install
xcodebuild -configuration Release -sdk iphoneos -arch armv7 -arch armv7s -arch arm64 -target install
popd
lipo -create -output __platforms/ios/lib/universal/libx_framework.a __platforms/ios/lib/static*/*.a

