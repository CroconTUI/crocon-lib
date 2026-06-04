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

> [!NOTE]
> Based on this requirement, the following GNU/Linux distributions released no earlier than 1998-2000 for the target glibc version may be suitable:
> * **glibc 2.0, ELF**
>   * **Debian 2.0** (July 1998) \
>     Linux 2.0.34, GCC 2.7.2.3, glibc 2.0.7, bash 2.01
>   * **Mandrake Linux 7.0** (January 2000) \
>     Linux 2.2.14, GCC 2.95.2, glibc 2.1.2, bash 2.03
>   * **SUSE Linux 8.1** (September 2002) \
>     Linux 2.4.19, GCC 3.2, glibc 2.2.5, bash 2.05
> * **glibc 2.0, ELF32 / glibc 2.2.5, ELF64**
>   * **Ubuntu 8.04** (April 2008) \
>     Linux 2.6.24, GCC 4.2.4, glibc 2.7, bash 3.2.39
> * **glibc 2.5, ELF**
>   * **Debian 8.11.0** (April 2015) \
>     Linux 3.16.0, GCC 4.9.2, glibc 2.19, bash 4.3.30
> * **glibc 2.34, ELF**
>   * **Debian 13** (August 2025) \
>     Linux 6.12.74, GCC 14.2.0, glibc 2.41, bash 5.2.37

### How to Build

First, clone the our repositories via [Repo Launcher](https://github.com/GerritCodeReview/git-repo):

```sh
repo init -u https://github.com/CroconTUI/crocon-manifest -b main
repo sync
```

**On Windows**, run the `make.bat` script from the `build` directory in the project root directory.

_NMAKE is present in the VS Developer Command Prompt. In MSVC 2.0, launching a separate command prompt is not required._

**On Linux:**
```sh
chmod +x ./build/make.sh
./make.sh --prefix /lib     # for install library type '/lib' or '/lib64'
```
