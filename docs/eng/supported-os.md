# CroconTUI OS Compatibility Table

### Microsoft Windows

_Source: <a href="http://www.malsmith.net/blog/visual-c-visual-history/">malsmith.net</a>, <a href="https://learn.microsoft.com/en-us/visualstudio/releases/2022/release-notes-v17.0">Microsoft Learn</a>_

16-bit versions of Windows are not supported, as Win16 does not support native TUI applications. DOS support may be added in future pre-releases.

<table>
  <tbody>
    <tr>
      <th>Target Makefile</th>
      <th width="180">Supported C/C++ compilers</th>
      <th width="180">Minimum Windows versions</th>
    </tr>
    <tr>
      <td rowspan="6"><code>vc2</code></td>
      <td>MSVC 2.0*</td>
      <td>Windows NT 3.1</td>
    </tr>
    <tr>
      <td>MSVC 4.0</td>
      <td rowspan="3">Windows NT 3.51</td>
    </tr>
    <tr>
      <td>MSVC 5.0</td>
    </tr>
    <tr>
      <td>MSVC 6.0</td>
    </tr>
    <tr>
      <td>MSVC 2002</td>
      <td>Windows NT 4.0</td>
    </tr>
    <tr>
      <td>MSVC 2003</td>
      <td>Windows 2000</td>
    </tr>
    <tr>
      <td rowspan="5"><code>vc8</code></td>
      <td>MSVC 2005</td>
      <td rowspan="2">Windows 2000</td>
    </tr>
    <tr>
      <td>MSVC 2008</td>
    </tr>
    <tr>
      <td>MSVC 2010</td>
      <td rowspan="3">Windows XP</td>
    </tr>
    <tr>
      <td>MSVC 2012</td>
    </tr>
    <tr>
      <td>MSVC 2013</td>
    </tr>
    <tr>
      <td rowspan="7"><code>vc14</code></td>
      <td>MSVC 2015</td>
      <td>Windows XP</td>
    </tr>
    <tr>
      <td rowspan="2">MSVC 2017</td>
      <td>Windows XP (optional)</td>
    </tr>
    <tr>
      <td rowspan="2">Windows Vista</td>
    </tr>
    <tr>
      <td>MSVC 2019</td>
    </tr>
    <tr>
      <td rowspan="2">MSVC 2022</td>
      <td>Windows Vista<br>(up to 14.30.30704)</td>
    </tr>
    <tr>
      <td>Windows 7</td>
    </tr>
    <tr>
      <td>MSVC 2026</td>
      <td>Windows 10</td>
    </tr>
  </tbody>
</table>

<sub>* Although Microsoft Visual C++ (MSVC) 2.0 can run as host IDE on Windows NT 3.1, it officially requires Windows NT 3.5 or higher.</sub>

### GNU/Linux (32-bit x86)

<table>
  <tbody>
    <tr>
      <th width="120" rowspan="2">Executable file format</th>
      <th width="120" rowspan="2">Minimum libc version</th>
      <th width="180" colspan="3">Host Linux distributions</th>
    </tr>
    <tr>
      <th>Product name</td>
      <th>Release date</th>
      <th width="180">Shipped with</th>
    </tr>
    <tr>
      <td rowspan="4">a.out<br>(<i>up to Linux 5.18</i>)</td>
      <td rowspan="4">BSD libc 4.6</td>
      <td rowspan="4">Slackware 2.0</td>
      <td rowspan="4"><b>Internet:</b> July 1994<br><b>CD:</b> May 1995</td>
      <td>Linux 1.2.8</td>
    </tr>
    <tr>
      <td>GCC 2.7.2.3</td>
    </tr>
    <tr>
      <td>BSD libc 4.6.27</td>
    </tr>
    <tr>
      <td>bash 1.14.4</td>
    </tr>
    <tr>
      <td rowspan="16">ELF</td>
      <td rowspan="16">glibc 2.0</td>
      <td rowspan="4">Debian 2.0</td>
      <td rowspan="4">July 1998</td>
      <td>Linux 2.0.34</td>
    </tr>
    <tr>
      <td>GCC 2.7.2.3</td>
    </tr>
    <tr>
      <td>glibc 2.0.7</td>
    </tr>
    <tr>
      <td>bash 2.01</td>
    </tr>
    <tr>
      <td rowspan="4">Mandrake Linux 7.0</td>
      <td rowspan="4">January 2000</td>
      <td>Linux 2.2.14</td>
    </tr>
    <tr>
      <td>GCC 2.95.2</td>
    </tr>
    <tr>
      <td>glibc 2.1.2</td>
    </tr>
    <tr>
      <td>bash 2.03</td>
    </tr>
    <tr>
      <td rowspan="4">SUSE Linux 8.1</td>
      <td rowspan="4">September 2002</td>
      <td>Linux 2.4.19</td>
    </tr>
    <tr>
      <td>GCC 3.2</td>
    </tr>
    <tr>
      <td>glibc 2.2.5</td>
    </tr>
    <tr>
      <td>bash 2.05</td>
    </tr>
    <tr>
      <td rowspan="4">Ubuntu 8.04</td>
      <td rowspan="4">April 2008</td>
      <td>Linux 2.6.24</td>
    </tr>
    <tr>
      <td>GCC 4.2.4</td>
    </tr>
    <tr>
      <td>glibc 2.7</td>
    </tr>
    <tr>
      <td>bash 3.2.39</td>
    </tr>
  </tbody>
</table>

### GNU/Linux (64-bit x86)
<table>
  <tbody>
    <tr>
      <th width="120" rowspan="2">Minimum libc version</th>
      <th width="180" colspan="3">Host Linux distributions</th>
    </tr>
    <tr>
      <th>Product name</td>
      <th>Release date</th>
      <th width="180">Shipped with</th>
    </tr>
    <tr>
      <td rowspan="12">glibc 2.2.5</td>
      <td rowspan="4">openSUSE 10.3</td>
      <td rowspan="4">September 2007</td>
      <td>Linux 2.6.22</td>
    </tr>
    <tr>
      <td>GCC 4.2.1</td>
    </tr>
    <tr>
      <td>glibc 2.6.1</td>
    </tr>
    <tr>
      <td>bash 3.2.25</td>
    </tr>
    <tr>
      <td rowspan="4">Ubuntu 8.04</td>
      <td rowspan="4">April 2008</td>
      <td>Linux 2.6.24</td>
    </tr>
    <tr>
      <td>GCC 4.2.4</td>
    </tr>
    <tr>
      <td>glibc 2.7</td>
    </tr>
    <tr>
      <td>bash 3.2.39</td>
    </tr>
    <tr>
      <td rowspan="4">Debian 6 (<i>Squeeze</i>)</td>
      <td rowspan="4">February 2011</td>
      <td>Linux 2.6.32</td>
    </tr>
    <tr>
      <td>GCC 4.4.5</td>
    </tr>
    <tr>
      <td>glibc 2.11.3</td>
    </tr>
    <tr>
      <td>bash 4.1.5</td>
    </tr>
    <tr>
      <td rowspan="4">glibc 2.5</td>
      <td rowspan="4">Debian 8 (<i>Jessie</i>)</td>
      <td rowspan="4">April 2015</td>
      <td>Linux 3.16.0</td>
    </tr>
    <tr>
      <td>GCC 4.9.2</td>
    </tr>
    <tr>
      <td>glibc 2.19</td>
    </tr>
    <tr>
      <td>bash 4.3.30</td>
    </tr>
    <tr>
      <td rowspan="4">glibc 2.34</td>
      <td rowspan="4">Debian 13 (<i>Jessie</i>)</td>
      <td rowspan="4">August 2025</td>
      <td>Linux 6.12.74</td>
    </tr>
    <tr>
      <td>GCC 14.2.0</td>
    </tr>
    <tr>
      <td>glibc 2.41</td>
    </tr>
    <tr>
      <td>bash 5.2.37</td>
    </tr>
    </tr>
  </tbody>
</table>
