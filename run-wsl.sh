#!/usr/bin/env bash
ROOT="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"

cmake -S "$ROOT/program" -B "$ROOT/build/wsl" &&
cmake --build "$ROOT/build/wsl" --parallel &&
cd "$ROOT/program" &&
"$ROOT/build/wsl/digitalshelf"