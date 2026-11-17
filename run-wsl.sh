#!/usr/bin/env bash
cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &&
cmake -S program -B build/wsl &&
cmake --build build/wsl --parallel &&
cd program &&
../build/wsl/digitalshelf