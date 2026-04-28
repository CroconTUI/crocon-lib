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
> Based on this requirement, the following GNU/Linux distributions released no earlier than 1999-2000 are suitable:
>
> * **Mandrake Linux 7.0** \
>   _January 2000: Linux 2.2.14, glibc 2.1.2, bash 2.03, GCC 2.95.2_
> * **SUSE Linux 7.0** \
>   _August 2000: Linux 2.2.16, glibc 2.1.3, bash 2.04, GCC 2.95.2_
> * **SUSE Linux 8.1** \
>   _September 2002: Linux 2.4.19, glibc 2.2.5, bash 2.05, GCC 3.2_
> * **Ubuntu 8.04** \
>   _April 2008: Linux 2.6.24, glibc 2.7, bash 3.2.39, GCC 4.2.4_
> * **Debian 8.11.0** \
>   _April 2015: Linux 3.16.0, glibc 2.19, bash 4.3.30, GCC 4.9.2_
> * **Debian 13** \
>   _August 2025: Linux 6.12.74, glibc 2.41, bash 5.2.37, GCC 14.2.0_

### How to Build

**On Windows**, run the `make.bat` script from the `build` directory in the project root directory.

_NMAKE is present in the VS Developer Command Prompt._

**On Linux:**
```sh
chmod +x ./build/make.sh
./make.sh --prefix /lib     # for install library type '/lib' or '/lib64'
```