#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <stdint.h>
#include <signal.h>
#include <string.h>
#include <stdbool.h>
#include "hook.h"
#include "macros.h"

void SDL_GetWindowSize(void* window, int *w, int *h) {
    *w = 1920 * 2;
    *h = 1080 * 2;
    *canvas_w = *w;
    *canvas_h = *h;
    // resize_window();
}

// void resize_window() {
//     static bool resizing = false;
//
//     // If there's no stage or we're resizing the window already, quit
//     if (*stage == NULL || resizing) { return; }
//     resizing = true;
//
//     // Get the current game client
//     struct stage_object obj = get_stage_object();
//
//     // If we're in-game, re-center the screen
//     if (strcmp(obj.name, "10GameClient") == 0) {
//         // Force the game to recenter the screen
//         void* world_client = *(void**)((char*)obj.ptr+0x80);
//         reinitialize_offsets(world_client);
//     }
//
//     resizing = false;
// }
//
// struct stage_object get_stage_object(void) {
//     void* deref  = *stage;
//     char* child  = (char*)deref+0x30;
//
//     struct stage_object obj;
//     obj.ptr  = **(void***)child;
//     obj.name = get_class_name(obj.ptr);
//
//     return obj;
// }
//
// char* get_class_name(void* obj) {
//     void*** vtable   = *(void****)obj;
//     void**  typeinfo = *(vtable-1);
//     void*   name     = *(typeinfo+1);
//     return name;
// }
//
// void reinitialize_offsets(void* world_client) {
//     if (world_client) {
//         void* world_view = *(void**)((char*)world_client+0x80);
//         bool* offsets_initialized = (bool*)((char*)world_view+0xB8);
//         *offsets_initialized = false;
//
//         (win_event_callback)(WE_SIZE_CHANGED, *user_data);
//     }
// }
