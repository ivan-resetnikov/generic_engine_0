/*
 * $FILENAME apart of game_10
 * Copyright (c) 2025-present Ivan Reshetnikov, see license.txt
*/

#ifndef LOG_H
#define LOG_H

#include "platform_def.h"

#ifdef PLATFORM_WINDOWS
    #define FILE_NAME (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#endif
#ifdef PLATFORM_LINUX
    #define FILE_NAME __FILE_NAME__
#endif

#if defined(PLATFORM_WINDOWS) || defined(PLATFORM_LINUX)

    #include <stdio.h>

    #define LOG_DEBUG(format_string, ...) \
        printf("Debug:    %s:%d %s()\t" format_string "\n", FILE_NAME, __LINE__, __func__, ##__VA_ARGS__)
    
    #define LOG_ERROR(format_string, ...) \
        printf("Error:    %s:%d %s()\t" format_string "\n", FILE_NAME, __LINE__, __func__, ##__VA_ARGS__)
    
    #define LOG_CRITICAL(format_string, ...) \
        printf("Critical: %s:%d %s()\t" format_string "\n", FILE_NAME, __LINE__, __func__, ##__VA_ARGS__)

#endif

#endif // #ifdef LOG_H
