// SPDX-License-Identifier: Propietary
// Copyright 2026, Ne.app. All rights reserved
// Official repository: https://github.com/ne-app-ci/distro

#include <libdisk.h>

LIBDISK_EXTERN_C int32_t
libdisk_check_boot_sector(const struct libdisk_disk_interface *in) {
  if (in == LIBDISK_NULL)
    return LIBDISK_EXIT_FAILURE;

  if (in->f_flags == 0L)
    return LIBDISK_EXIT_FAILURE;

  return (in->f_cur_sz > 0 && in->f_type != 0 &&
          in->f_magic == LIBDISK_DISK_MAGIC)
             ? LIBDISK_EXIT_SUCCESS
             : LIBDISK_EXIT_FAILURE;
}
