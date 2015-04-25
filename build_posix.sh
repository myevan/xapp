pushd       __builds/posix/framework
make install VEROBSE=1
popd
pushd       __builds/posix/projects/$1
make clean
make install VERBOSE=1
popd
pushd       __platforms/posix/bin
./$1
popd
