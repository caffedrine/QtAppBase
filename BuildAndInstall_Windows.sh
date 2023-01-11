# Building on Windows:
#	1. Make sure Qt is installed 	
#   2. Make sure MinGW path is added to environment: e.g: C:\Qt\Tools\mingw1120_64\bin
#   3. Run the script in this form:
#      BuildAndInstall_Windows.sh -DCMAKE_PREFIX_PATH="C:/Qt/6.4.1/mingw_64/lib/cmake"

# Building on linux:
# Pass -DCMAKE_PREFIX_PATH=../Toolchains/Qt5.15/5.15.2/gcc_64/lib/cmake 
# in order to use a custom Qt version. Otherwise, system's version will be used.
#!/usr/bin/env bash

rm -R build/Release
mkdir build/Release
cd build/Release

cmake ../../ -DCMAKE_BUILD_TYPE=Release -G "MinGW Makefiles" "$@"

mingw32-make all -j `nproc --ignore 1`

cmake ../../ --target install

# Wait to press anything
read -rn1