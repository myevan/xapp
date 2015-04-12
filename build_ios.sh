set -e
pushd       __builds/ios
xcodebuild -configuration Debug -sdk iphonesimulator -arch i386 -arch x86_64 -target install
xcodebuild -configuration Debug -sdk iphoneos -arch armv7 -arch armv7s -arch arm64 -target install
popd
lipo -create -output __platforms/ios/lib/universal/libx_framework.a __platforms/ios/lib/static*/*.a
#pushd       projects/$1
#xcodebuild -configuration Debug
#popd
