rm -rf      __builds/osx
rm -rf      __platforms/osx
mkdir -p    __builds/osx
mkdir -p    __platforms/osx
mkdir -p    __platforms/osx/lib/universal
pushd       __builds/osx
cmake ../.. -DCMAKE_INSTALL_PREFIX=../../__platforms/osx -G Xcode
xcodebuild -configuration Release -target install
popd
lipo -create -output __platforms/osx/lib/universal/libx_framework.a __platforms/osx/lib/static*/*.a
