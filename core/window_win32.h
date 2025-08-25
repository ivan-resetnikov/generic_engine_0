/*
 * $FILENAME apart of game_10
 * Copyright (c) 2025-present Ivan Reshetnikov, see license.txt
*/

#ifndef WINDOW_WIN32_H
#define WINDOW_WIN32_H

#include "platform_def.h"
#ifdef PLATFORM_WINDOWS

#define UNICODE
#include <windows.h>
#include <stdint.h>

#include "log.h"

typedef struct {
    HWND win_handle;

    uint8_t is_open;
} WindowContext;

void create_window(WindowContext* win);
void start_main_loop();
void close_window(WindowContext* win);

inline LRESULT CALLBACK wnd_process(HWND wnd, UINT msg, WPARAM wnd_param, LPARAM wnd_lparam);

inline void create_window(WindowContext* win)
{
    HINSTANCE win_instance = GetModuleHandle(NULL);

    const wchar_t CLASS_NAME[]  = L"generic_engine_0_window_class";

    // Window class
    WNDCLASS wnd_class = {0};
    wnd_class.lpfnWndProc   = wnd_process;
    wnd_class.hInstance     = win_instance;
    wnd_class.lpszClassName = CLASS_NAME;
    RegisterClass(&wnd_class);

    // Window
    win->win_handle = CreateWindowEx(
        0,
        CLASS_NAME,
        L"Generic Engine 0",
        WS_OVERLAPPEDWINDOW,

        CW_USEDEFAULT, CW_USEDEFAULT, 640, 480,

        NULL,
        NULL,
        win_instance,
        NULL
        );

    if (win->win_handle == NULL) {
        LOG_CRITICAL("Failed to create the window!");
        return;
    }

    ShowWindow(win->win_handle, 0); // Hide until main loop started
}

/*
 * Opens a window on the main screen.
*/
inline void start_main_loop(WindowContext* win, void (*draw_surface_update)(void))
{
    ShowWindow(win->win_handle, 1);

    win->is_open = 1;
    
    while (win->is_open) {
        MSG msg;
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) {
                win->is_open = 0;
                break;
            }

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        draw_surface_update();
    }
}

inline void close_window(WindowContext* win)
{
    DestroyWindow(win->win_handle);
}

inline LRESULT CALLBACK wnd_process(HWND win, UINT msg, WPARAM wnd_param, LPARAM wnd_lparam)
{
    switch (msg)
    {
    case WM_DESTROY: {
        DestroyWindow(win);
        return 0;
    } break;
    default: {
        return DefWindowProc(win, msg, wnd_param, wnd_lparam);
    } break;
    }
}

#endif // #ifdef PLATFORM_WINDOWS

#endif // #ifdef WINDOW_WIN32_H
