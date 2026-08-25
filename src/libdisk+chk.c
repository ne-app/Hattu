// SPDX-License-Identifier: Propietary
// Copyright 2026, Ne.app. All rights reserved
// Official repository: https://github.com/ne-app-ci/distro

#include <libdisk/disk.h>

int32_t libdisk_check_boot_sector(struct libdisk_disk_interface* in)
{
    if (in == LIBDISK_NULL) return LIBDISK_EXIT_FAILURE;
    if (in->f_flags == 0) return LIBDISK_EXIT_FAILURE;

    return LIBDISK_EXIT_SUCCESS;
}
