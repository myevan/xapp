pushd       __builds/posix/framework
make install VEROBSE=1
popd
pushd       __builds/posix/projects/$1
make install VERBOSE=1
./$1
popd
