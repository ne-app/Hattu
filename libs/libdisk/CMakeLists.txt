# SPDX-License-Identifier: Propietary
# Copyright 2026, Ne.app. All rights reserved
# Official repository: https://github.com/ne-app-ci/distro

cmake_minimum_required(VERSION 3.25.1)

project(VirtualDisk DESCRIPTION "The LibVirtualDisk SDK in Modern C." HOMEPAGE_URL "libVirtualDisk.ne-app.eu")

set(CMAKE_C_STANDARD 17)

if (DEFINED VD_INCLUDE_C_EXTENSIONS)
set(CMAKE_C_EXTENSIONS 1)
endif()

set(NEAPP_LIBDISK_SOURCES libdisk/src/libdisk.c)

add_library(VirtualDisk SHARED ${NEAPP_LIBDISK_SOURCES})
