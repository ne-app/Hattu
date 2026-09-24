// SPDX-License-Identifier: Apache 2.0
// Copyright 2026, Ne.app. All rights reserved
// Official repository: https://github.com/ne-app/hattu

#pragma once

#ifdef __X11_FONTS_INCL__
#include <X11/fonts/font.h>
#endif

#ifdef __ANTX__
#include <AntX.h>
#endif

#ifdef __ANT__
#include <Ant.h>
#endif

#ifdef __linux__
#include <unistd.h>
#endif

struct _FONTLAYER;
struct _FONTINFO;
struct _FONTRENDERINFO;

typedef void (*_FLRegisterFont)(struct _FONTINFO*);
typedef void (*_FLUnRegisterFont)(struct _FONTLAYER*);
typedef void (*_FLLoadFont)(struct _FONTINFO*);
typedef void (*_FLUnLoadFont)(struct _FONTLAYER*);
typedef void (*_FLRenderFont)(struct _FONTLAYER*, struct _FONTRENDERINFO*);

typedef void* FONTHANDLE;

#ifndef IMPORT_C
#ifdef __cplusplus
#define IMPORT_C extern "C"
#else
#define IMPORT_C
#endif
#endif

IMPORT_C __int32_t FLLoadLibrary(void);

IMPORT_C __int32_t FLFreeLibrary(void);

IMPORT_C void* FLLibraryInfo(size_t flags, size_t* out_sz);
