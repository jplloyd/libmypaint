rem Matrix-driven Appveyor CI script for libmypaint
rem Currently only does MSYS2 builds.
rem https://www.appveyor.com/docs/installed-software#mingw-msys-cygwin
rem Needs the following vars:
rem    MSYS2_ARCH:  x86_64 or i686
rem    MSYSTEM:  MINGW64 or MINGW32

rem Set the paths appropriately

PATH C:\msys64\%MSYSTEM%\bin;C:\msys64\usr\bin;%PATH%

rem Upgrade the MSYS2 platform
bash -lc "pacman --noconfirm --sync --refresh --refresh pacman"
bash -lc "pacman --noconfirm --sync --refresh --refresh --sysupgrade --sysupgrade"

rem Install required tools
bash -xlc "pacman --noconfirm -S --needed base-devel"

rem Install the relevant native dependencies
bash -xlc "pacman --noconfirm -S --needed mingw-w64-%MSYS2_ARCH%-json-c"
bash -xlc "pacman --noconfirm -S --needed mingw-w64-%MSYS2_ARCH%-glib2"
bash -xlc "pacman --noconfirm -S --needed mingw-w64-%MSYS2_ARCH%-gobject-introspection"

echo "Maybe this will shed some light:"
echo ""

bash -xlc "pacman -Ql mingw-w64-%MSYS2_ARCH%-glib2"

rem Invoke subsequent bash in the build tree
rem cd %APPVEYOR_BUILD_FOLDER%
rem set CHERE_INVOKING=yes

rem Build/test scripting
rem bash -xlc "set pwd"
rem bash -xlc "env"

rem bash -xlc "./autogen.sh"
rem bash -xlc "./configure"
rem bash -xlc "make distcheck"
