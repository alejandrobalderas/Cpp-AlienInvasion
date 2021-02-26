#!/bin/bash

# Install VCPKG
VCPKGROOT="/home/$(whoami)/vcpkg"
git clone https://github.com/microsoft/vcpkg $VCPKROOT
export VCPKGROOT
./bootstrap-vcpkg.sh

# Install needed libraries
vcpkg integrate install
vcpkg install sdl2 sdl2-image

# Build Project
rm -rf build/
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=${VCPKGROOT}/scripts/buildsystems/vcpkg.cmake
make