#!/bin/bash
rm -rf build/
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=${VCPKGROOT}/scripts/buildsystems/vcpkg.cmake
make