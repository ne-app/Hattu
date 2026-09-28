// SPDX-License-Identifier: Apache 2.0
// Copyright 2026, Ne.app. All rights reserved
// Official repository: https://github.com/ne-app/hattu

#include <fonts.h>

static void* binary_info = NULL;

IMPORT_C __int32_t FLLoadLibrary(void) { return EXIT_SUCCESS; }

IMPORT_C __int32_t FLFreeLibrary(void) { return EXIT_SUCCESS; }

IMPORT_C void* FLLibraryInfo(size_t flags, size_t* out_sz) {
    if (!flags) return NULL;
    if (!out_sz) return NULL;

    /// do we even have flags? if not, just return nothing.
    if ((*out_sz) == 0) return NULL;

    *out_sz = 0;
    assert(binary_info);
    return binary_info;
}
