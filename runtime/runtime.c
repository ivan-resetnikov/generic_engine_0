/*
 * $FILENAME apart of game_10
 * Copyright (c) 2025-present Ivan Reshetnikov, see license.txt
*/

#include "../core/core.h"

void draw_surface_update();

WindowContext g_window = {0};

int main(int arg_count, char* arg_vec[])
{
    LOG("runtime");

    create_window(&g_window);
    start_main_loop(&g_window, draw_surface_update);
    close_window(&g_window);

    return 0;
}

void draw_surface_update()
{
    // Most likely, one display call per <refresh rate>
    // 60Hz = 60 calls per second / 60 FPS
}
