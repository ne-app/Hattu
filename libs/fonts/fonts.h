// SPDX-License-Identifier: Propietary
// Copyright 2026, Ne.app. All rights reserved
// Official repository: https://github.com/ne-app-ci/distro

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
