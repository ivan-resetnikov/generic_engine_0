/*
 * $FILENAME apart of game_10
 * Copyright (c) 2025-present Ivan Reshetnikov, see license.txt
*/

#ifndef WINDOW_WIN32_H
#define WINDOW_WIN32_H

#include "log.h"

typedef struct {

} WindowContext;

void create_window(WindowContext* win);
void close_window(WindowContext* win);

inline void create_window(WindowContext* win)
{
    LOG("Unimplemented");
}

inline void close_window(WindowContext* win)
{
    LOG("Unimplemented");
}

#endif // #ifdef WINDOW_WIN32_H
