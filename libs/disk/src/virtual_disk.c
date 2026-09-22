// SPDX-License-Identifier: Apache 2.0
// Copyright 2026, Ne.app. All rights reserved
// Official repository: https://github.com/ne-app/hattu

#include <virtual_disk.h>
#include <stdio.h>
#include <openssl/md5.h>

/// The macros defined here are used internally by the library.
#ifndef LIBDISK_VER
#define LIBDISK_VER (0x101)
#endif

#ifndef LIBDISK_START_OFF
#define LIBDISK_START_OFF (1024)
#endif

#ifndef LIBDISK_SECTOR_SZ
#define LIBDISK_SECTOR_SZ (512)
#endif

typedef FILE* libdisk_file_t;

LIBDISK_EXTERN_C int32_t libdisk_check_boot_sector(const struct libdisk_disk_interface* in) {
  if (in == LIBDISK_NULL) return LIBDISK_EXIT_FAILURE;
  if (in->f_type == 0L) return LIBDISK_EXIT_FAILURE;
  if (in->f_flags == 0L) return LIBDISK_EXIT_FAILURE;
  if (in->f_crc32 == 0L) return LIBDISK_EXIT_FAILURE;
  if (in->f_disk_size == 0L) return LIBDISK_EXIT_FAILURE;
  if (in->f_sector_size == 0L) return LIBDISK_EXIT_FAILURE;

  return (in->f_cur_sz > 0 && in->f_type != 0 && in->f_magic == LIBDISK_DISK_MAGIC)
             ? LIBDISK_EXIT_SUCCESS
             : LIBDISK_EXIT_FAILURE;
}

LIBDISK_EXTERN_C int32_t libdisk_create_boot_sector_vdf(struct libdisk_disk_interface* in,
                                                    const char*                    ldi_file) {
  if (in == LIBDISK_NULL) return LIBDISK_EXIT_FAILURE;
  if (in->f_crc32 == 0) return LIBDISK_EXIT_FAILURE;
  if (in->f_disk_size == 0) return LIBDISK_EXIT_FAILURE;

  in->f_magic = LIBDISK_DISK_MAGIC;

  in->f_cur_buf_sz = LIBDISK_SECTOR_SZ;
  in->f_cur_sz     = LIBDISK_SECTOR_SZ;

  in->f_version = LIBDISK_VER;

  in->f_type  = libdisk_disk_interface_phys;
  in->f_flags = libdisk_disk_bitrate_fast;

  if (ldi_file && *ldi_file != 0) {
    libdisk_file_t f_ldi = fopen(ldi_file, "wb");

    in->f_sector_size = LIBDISK_SECTOR_SZ;

    if (f_ldi) {
      fwrite(in, sizeof(struct libdisk_disk_interface), SEEK_SET + LIBDISK_START_OFF, f_ldi);

      fflush(f_ldi);
      fclose(f_ldi);

      f_ldi = NULL;
    }
  }

  return LIBDISK_EXIT_SUCCESS;
}
