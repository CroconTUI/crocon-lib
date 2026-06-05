# CroconTUI
Crocon Terminal User Interface Framework. Developed with maximum backward compatibillity for Windows and Unix-like OS, such as GNU/Linux.

## Minimum system requirements

### For use in programs

* **Windows NT 3.1 and higher**
* **GNU/Linux with ELF support**
    * glibc >= 1.9.9
    * `xterm` or `xterm-256color` for full colors support

### For building and linking static and dynamic libraries
* **Windows NT 3.1 and higher**
    * Microsoft Visual C++ 2.0 and higher
* **GNU/Linux with a.out or ELF support**
    * glibc >= 2.1.2
    * GCC >= 2.95.2
    * bash >= 2.03

To check the current versions of components, enter the commands:
```sh
uname -a         # linux
ldd --version    # glibc
bash --version   # bash
gcc --version    # gcc
```

See [OS compabillity table](docs/eng/supported-os.md).

### How to Build

First, clone the our repositories via [Repo Launcher](https://github.com/GerritCodeReview/git-repo):

```sh
repo init -u https://github.com/CroconTUI/crocon-manifest -b main
repo sync
```

**On Windows**, run the `make.bat` script from the `build` directory in the project root directory.

> [!NOTE]
> NMAKE is present in the VS Developer Command Prompt. In MSVC 2.0, launching a separate command prompt is not required.
> You can enable debug symbols before building by specifying the `CROCON_DEBUG` variable on the command line or directly: `make [target] y`

**On Linux:**
```sh
chmod +x ./build/make.sh
./make.sh --prefix /usr/local/lib
```

> [!NOTE]
> You can enable debugging symbols using the `--enable-debug` flag, and extend support for older Linux distros using the `--enable-legacy-support` flag.
