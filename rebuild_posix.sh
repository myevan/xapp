rm -rf      __builds/posix
rm -rf      __platforms/posix
mkdir -p    __platforms/posix
mkdir -p    __builds/posix/framework
mkdir -p    __builds/posix/projects/hello
pushd       __builds/posix/framework
cmake ../../.. -DCMAKE_INSTALL_PREFIX=../../../__platforms/posix -DPOSIX=1
make install VEROBSE=1
popd
pushd       __builds/posix/projects/hello
cmake ../../../../projects/posix_project -DCMAKE_INSTALL_PREFIX=../../../../__platforms/posix -DPOSIX=1
make install VERBOSE=1
./hello
popd
