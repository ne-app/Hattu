// SPDX-License-Identifier: Propietary
// Copyright 2026, Ne.app. All rights reserved
// Official repository: https://github.com/ne-app-ci/distro

#pragma once

#include <stdint.h>
#include <stdlib.h>

#ifndef LIBDISK_EXTERN_C
#ifdef __cplusplus
#define LIBDISK_EXTERN_C extern "C"
#else
#define LIBDISK_EXTERN_C extern
#endif
#endif

#ifndef LIBDISK_EXIT_SUCCESS
#define LIBDISK_EXIT_SUCCESS (1)
#endif

#ifndef LIBDISK_EXIT_FAILURE
#define LIBDISK_EXIT_FAILURE (0)
#endif

#ifndef LIBDISK_NULL
#define LIBDISK_NULL (nullptr)
#endif

#ifndef final
#define final
#endif

#ifndef LIBDISK_DISK_MAGIC
#define LIBDISK_DISK_MAGIC (0x44775566)
#endif

struct libdisk_disk_interface final {
  int32_t f_magic;
  int32_t f_type;
  int32_t f_flags;
  int64_t f_fd;
  int64_t f_cur_sz, f_cur_buf_sz;
};

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


LIBDISK_EXTERN_C int32_t libdisk_check_boot_sector(const struct libdisk_disk_interface* in);