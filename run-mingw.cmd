@echo off
setlocal
set "PATH=C:\msys64\ucrt64\bin;%PATH%"
cd /d "%~dp0"
cmake -S program -B build/mingw-ninja -G Ninja -DCMAKE_C_COMPILER=gcc && cmake --build build/mingw-ninja --parallel && cd program && "..\build\mingw-ninja\digitalshelf.exe"