/*
 * $FILENAME apart of game_10
 * Copyright (c) 2025-present Ivan Reshetnikov, see license.txt
*/

#ifndef LOG_H
#define LOG_H

#include "platform_def.h"

#if defined(PLATFORM_WINDOWS) || defined(PLATFORM_LINUX)

    #include <stdio.h>

    #define LOG(format_string, ...) \
        printf("Debug: %s:%d %s()\t" format_string "\n", __FILE_NAME__, __LINE__, __func__, ##__VA_ARGS__)

#endif

#endif // #ifdef CORE_H