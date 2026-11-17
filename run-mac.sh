#!/usr/bin/env bash
cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &&
cmake -S program -B build/mac &&
cmake --build build/mac --parallel &&
cd program &&
../build/mac/digitalshelf