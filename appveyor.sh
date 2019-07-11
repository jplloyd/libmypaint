#!/usr/bin/env bash

set -e

echo "-- Current PATH --"
echo $PATH

whereis pacman

echo "-- pacman version --"
pacman --version || exit 1

# alias pacman='pacman --noconfirm --sync --refresh'

# pacman pacman && pacman --sysupgrade || exit 1

PKG_PREFIX="mingw-w64-$MSYS2_ARCH"

echo "Prefix: $PKG_PREF"

pacman --noconfirm -S --needed \
       base-devel \
       ${PKG_PREFIX}-json-c \
       ${PKG_PREFIX}-glib2 \
       ${PKG_PREFIX}-gobject-introspection


# Make sure that we have the macro files available
for p in `pacman --noconfirm -Ql ${PKG_PREFIX}-glib2 | grep "\.m4" | xargs readlink -e | xargs dirname | sort --unique`
do
    ACLOCAL_PATH=$p:$ACLOCAL_PATH
done
export ACLOCAL_PATH

./autogen.sh && ./configure && make distcheck
