#!/usr/bin/env bash

set -e

echo "-- Current PATH --"
echo $PATH

whereis pacman

echo "-- pacman version --"
pacman --version || exit 1

# alias pacman='pacman --noconfirm --sync --refresh'

# pacman pacman && pacman --sysupgrade || exit 1

alias pmn='pacman --noconfirm --needed'

PKG_PREFIX="mingw-w64-$MSYS2_ARCH"

echo "Prefix: $PKG_PREF"

echo "--- Aliases ---"
alias
echo "---------------"

pmn -S base-devel &&
pmn -S \
       ${PKG_PREFIX}-json-c \
       ${PKG_PREFIX}-glib2 \
       ${PKG_PREFIX}-gobject-introspection &&
./autogen.sh && ./configure && make distcheck
