/*
 * $FILENAME apart of game_10
 * Copyright (c) 2025-present Ivan Reshetnikov, see license.txt
*/

#ifndef PLATFORM_DEF_H
#define PLATFORM_DEF_H

#ifdef __linux__
    #define PLATFORM_LINUX
#endif
#ifdef _WIN32
    #define PLATFORM_WINDOWS
#endif

#endif