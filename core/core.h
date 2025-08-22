/*
 * $FILENAME apart of game_10
 * Copyright (c) 2025-present Ivan Reshetnikov, see license.txt
*/

#ifndef CORE_H
#define CORE_H

// Determine platform
#ifdef __linux__
    #define PLATFORM_LINUX
#endif
#ifdef _WIN32
    #define PLATFORM_WINDOWS
#endif

#include "log.h"

#endif // #ifdef CORE_H