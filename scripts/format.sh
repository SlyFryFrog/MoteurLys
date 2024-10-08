#!/bin/bash

cd ..

# Uses git submodule w/ utilities to format engine-specific code
./vendor/CodePingouin/f_clang_format -d Lys -f .clang-format -r

./vendor/CodePingouin/f_clang_format -d Fleur -f .clang-format -r

./vendor/CodePingouin/f_clang_format -d demo -f .clang-format -r