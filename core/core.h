/*
 * $FILENAME apart of game_10
 * Copyright (c) 2025-present Ivan Reshetnikov, see license.txt
*/

#ifndef CORE_H
#define CORE_H

#include "log.h"

#if defined(PLATFORM_WINDOWS)
    #include "window_win32.h"
#endif
#if defined(PLATFORM_LINUX)
    #include "window_x11.h"
#endif

#endif // #ifdef CORE_H