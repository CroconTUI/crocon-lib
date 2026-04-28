# Crocon
Crocon Terminal User Interface Framework. Developed with maximum compatibillity for Windows and Unix-like OS, such as GNU/Linux.

## Minimum system requirements

### For use in programs

* **Windows NT 3.1 and higher**
* **GNU/Linux with a.out or ELF support**
    * glibc >= 2.1.2
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
> Based on this requirement, the following GNU/Linux distributions released no earlier than 1998-2000 are suitable:
>
> * **Debian 2.0** (July 1998, build unsupported) \
>   target: GCC 3.2 and below, ELF \
>   host: Linux 2.0.34, glibc 1.9.9, GCC 2.7.2.3, bash 2.01
> * **Mandrake Linux 7.0** (January 2000) \
>   target: GCC 3.2 and below, ELF \
>   host: Linux 2.2.14, GCC 2.95.2, glibc 2.1.2, bash 2.03
> * **SUSE Linux 8.1** (September 2002) \
>   target: GCC 4.2.4 and below, ELF \
>   host: Linux 2.4.19, GCC 3.2, glibc 2.2.5, bash 2.05
> * **Ubuntu 8.04** (April 2008) \
>   target: GCC 4.9.2 and below, ELF \
>   host: Linux 2.6.24, glibc 2.7, bash 3.2.39, GCC 4.2.4
> * **Debian 8.11.0** (April 2015) \
>   target: GCC 4.9.2 and below, ELF \
>   host: Linux 3.16.0, glibc 2.19, bash 4.3.30, GCC 4.9.2
> * **Debian 13** (August 2025) \
>   target: GCC 4.2.4 - 14.2.0, ELF \
>   host: Linux 6.12.74, glibc 2.41, bash 5.2.37, GCC 14.2.0

### How to Build

**On Windows**, run the `make.bat` script from the `build` directory in the project root directory.

_NMAKE is present in the VS Developer Command Prompt. In MSVC 2.0, launching a separate command prompt is not required._

**On Linux:**
```sh
chmod +x ./build/make.sh
./make.sh --prefix /lib     # for install library type '/lib' or '/lib64'
```