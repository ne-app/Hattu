// SPDX-License-Identifier: Propietary
// Copyright 2026, Ne.app. All rights reserved
// Official repository: https://github.com/ne-app-ci/distro

#pragma once

#include <stdlib.h>

#ifndef final
#define final
#endif

struct libdisk_disk_interface;

enum {
    libdisk_disk_interface_invalid,
    libdisk_disk_interface_network = 500,
    libdisk_disk_interface_virt,
    libdisk_disk_interface_phys,
};

enum {
    libdisk_disk_bitrate_invalid,
    libdisk_disk_bitrate_slow = 600,
    libdisk_disk_bitrate_std,
    libdisk_disk_bitrate_fast,
    libdisk_disk_bitrate_very_fast,
};
