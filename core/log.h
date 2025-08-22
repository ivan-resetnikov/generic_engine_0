/*
 * $FILENAME apart of game_10
 * Copyright (c) 2025-present Ivan Reshetnikov, see license.txt
*/

#ifndef CORE_H
#define CORE_H

#if defined(PLATFORM_WINDOWS) || defined(PLATFORM_LINUX)
#define LOG(format_string, ...) \
    printf("Debug %s:%d @%s - " format_string "\n", __FILENAME__, __LINE__, __func__, ##__VA_ARGS__)
#endif

#endif // #ifdef CORE_H