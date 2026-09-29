// SPDX-License-Identifier: Apache 2.0
// Copyright 2026, Ne.app. All rights reserved
// Official repository: https://github.com/ne-app/hattu

#include <fonts.h>
#include <assert.h>
#include <dlfcn.h>

#ifndef FL_LIBRARY_SYM
#define FL_LIBRARY_SYM "_FLLibraryLen"
#endif

#ifndef FL_LIBRARY_PATH
#define FL_LIBRARY_PATH "libFontsRuntime.X11.so"
#endif

typedef void* blob_t;

static blob_t binary_info = NULL;

IMPORT_C __int32_t FLLoadLibrary(void) { 
    binary_info = dlopen(FL_LIBRARY_PATH, RTLD_LAZY);
    if (!binary_info) return EXIT_FAILURE;

    return EXIT_SUCCESS; 
}

IMPORT_C __int32_t FLFreeLibrary(void) { 
    dlclose(binary_info);
    return EXIT_SUCCESS; 
}

IMPORT_C blob_t FLLibraryInfo(size_t flags, size_t* out_sz) {
    if (!flags) return NULL;
    if (!out_sz) return NULL;

    /// do we even have flags? if not, just return nothing.
    if ((*out_sz) == 0) return NULL;
    assert(binary_info);

    blob_t len = dlsym(binary_info, FL_LIBRARY_SYM);
    if (len == NULL) return NULL;
    
    *out_sz = *(size_t*)len;
    
    return binary_info;
}
