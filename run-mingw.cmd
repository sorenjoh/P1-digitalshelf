@echo off
cd /d "%~dp0"
cmake -S program -B build/mingw-make -G "MinGW Makefiles" -DCMAKE_C_COMPILER=gcc && cmake --build build/mingw-make --parallel && cd program && "..\build\mingw-make\digitalshelf.exe"