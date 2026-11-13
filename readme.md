# DigitalShelf

Run these commands from the repository root.

## WSL (Ubuntu or Debian)

Install the tools if needed, then build and run:

```sh
sudo apt update
sudo apt install build-essential cmake
cmake -S . -B build-wsl
cmake --build build-wsl
./build-wsl/digitalshelf
```

## Windows (MinGW-w64 via MSYS2)

Open **MSYS2 UCRT64**. Install GCC, CMake and Ninja if needed, then build and run:

```sh
pacman -S --needed mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-ninja
cmake -S . -B build-ucrt64 -G Ninja
cmake --build build-ucrt64
./build-ucrt64/digitalshelf.exe
``` Youssef
cmake --build build-ucrt64-Ninja
.\build-ucrt64-Ninja\digitalshelf.exe