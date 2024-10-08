#!/bin/bash

cd ..
mkdir build
cd build

cmake .. -DBUILD_TESTS=ON

make

ctest