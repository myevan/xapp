rm -rf      __builds/posix
rm -rf      __platforms/posix
mkdir -p    __platforms/posix
mkdir -p    __builds/posix/framework
mkdir -p    __builds/posix/projects/$1
pushd       __builds/posix/framework
cmake ../../.. -DCMAKE_INSTALL_PREFIX=../../../__platforms/posix -DPOSIX=1
popd
pushd       __builds/posix/projects/$1
cmake ../../../../projects/$1 -DCMAKE_INSTALL_PREFIX=../../../../__platforms/posix -DPOSIX=1
popd
./build_posix.sh $1
