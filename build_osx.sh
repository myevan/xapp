set -e
pushd       __builds/osx
xcodebuild -configuration Debug -target install
popd
lipo -create -output __platforms/osx/lib/universal/libx_framework.a __platforms/osx/lib/static*/*.a
#pushd       projects/$1
#xcodebuild -configuration Debug
#popd
