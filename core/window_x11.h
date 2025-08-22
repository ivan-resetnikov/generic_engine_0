/*
 * $FILENAME apart of game_10
 * Copyright (c) 2025-present Ivan Reshetnikov, see license.txt
*/

#ifndef WINDOW_X11_H
#define WINDOW_X11_H

#include <X11/Xlib.h>
#include <stdint.h>

#include "log.h"

typedef struct {
    Display* display;
    int screen;
    Window window;

    int8_t is_open;
} WindowContext;

void create_window(WindowContext* win);
void start_main_loop();
void close_window(WindowContext* win);

/*
 * Opens a window on the main screen.
*/
inline void create_window(WindowContext* win)
{
    win->display = XOpenDisplay(NULL);
    win->screen = DefaultScreen(win->display);

    win->window = XCreateSimpleWindow(win->display,
        RootWindow(win->display, win->screen),
        0, 0,              // x, y
        640, 480,          // width, height
        0,                 // border width
        BlackPixel(win->display, win->screen),
        BlackPixel(win->display, win->screen));
    
    XMapWindow(win->display, win->window);
    XFlush(win->display);
}

inline void start_main_loop(WindowContext* win, void (*draw_surface_update)(void))
{
    win->is_open = 1;
    
    while (win->is_open) {
        while (XPending(win->display)) {
            XEvent e;
            XNextEvent(win->display, &e);

            if (e.type == DestroyNotify) {
                win->is_open = 0;
                return;
            }
        }

        draw_surface_update();
    }
}

inline void close_window(WindowContext* win)
{
    XDestroyWindow(win->display, win->window);
    XCloseDisplay(win->display);
}

#endif // #ifdef WINDOW_X11_H