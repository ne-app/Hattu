# SPDX-License-Identifier: Propietary
# Copyright 2026, Ne.app. All rights reserved
#  Official repository: https://github.com/ne-app-ci/distro

cmake_minimum_required(VERSION 3.25.1)

project(ADB DESCRIPTION "The LibVirtualDisk SDK in modern C" HOMEPAGE_URL "docs.libdisk.nekernel.org")

set(CMAKE_C_STANDARD 17)

set(NEAPP_LIBDISK_SOURCES
  libdisk/src/libdisk.c
)

add_library(VirtualDisk SHARED ${NEAPP_LIBDISK_SOURCES})
