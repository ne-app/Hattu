// SPDX-License-Identifier: Propietary
// Copyright 2026, Ne.app. All rights reserved
// Official repository: https://github.com/ne-app-ci/distro

#include <libdisk.h>
#include <stdio.h>

/// The macros defined here are used internally by the library.
#ifndef LIBDISK_VER
#define LIBDISK_VER (0x001)
#endif

#ifndef LIBDISK_SECTOR_SZ
#define LIBDISK_SECTOR_SZ (512)
#endif

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

LIBDISK_EXTERN_C int32_t 
libdisk_create_boot_sector(struct libdisk_disk_interface* in, const char* ldi_file) {
  if (in == LIBDISK_NULL)
    return LIBDISK_EXIT_FAILURE;
  
  in->f_magic = LIBDISK_DISK_MAGIC;

  in->f_cur_buf_sz = LIBDISK_SECTOR_SZ;
  in->f_cur_sz = LIBDISK_SECTOR_SZ;

  in->f_version = LIBDISK_VER;

  in->f_type = libdisk_disk_interface_phys;
  in->f_flags = libdisk_disk_bitrate_fast;

  if (ldi_file && *ldi_file != 0) {
    FILE* f_ldi = fopen(ldi_file, "wb");

    if (f_ldi) {
      fwrite(in, sizeof(in), SEEK_SET, f_ldi);

      fflush(f_ldi);
      fclose(f_ldi);

      f_ldi = NULL;
    }
  }

  return LIBDISK_EXIT_SUCCESS;
}
