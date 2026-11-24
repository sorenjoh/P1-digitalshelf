# DigitalShelf

Run the commands for your platform from the repository root. Each script builds and launches DigitalShelf.

## macOS

Install the Xcode Command Line Tools and CMake. If you use Homebrew, run:

```sh
xcode-select --install
brew install cmake
```

Once installation finishes, run:

```sh
bash run-mac.sh
```

## Windows (MinGW-w64 via MSYS2)

In the MSYS2 UCRT64 terminal, install the build tools:

```sh
pacman -S --needed mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-ninja
```

In Windows Command Prompt, run:

```cmd
run-mingw.cmd
```

The script expects MSYS2 at `C:\msys64`.

## WSL

In an Ubuntu or Debian WSL terminal, install the build tools:

```sh
sudo apt update
sudo apt install build-essential cmake
```

Then run:

```sh
bash run-wsl.sh
```
