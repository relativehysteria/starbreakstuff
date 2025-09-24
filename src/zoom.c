#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "zoom.h"
#include "hook.h"
#include "util.h"

void zoom_in()  { apply_zoom(+ZOOM_STEP); }
void zoom_out() { apply_zoom(-ZOOM_STEP); }

void apply_zoom(float step) {
    static float zoom_factor = 1.0f;

    // Clamp the zoom factor between the defined limits
    zoom_factor = clamp(zoom_factor + step, ZOOM_MIN, ZOOM_MAX);

    // Override the display dimensions
    OVERRIDE_WIDTH  = (uint32_t)(BASE_WIDTH  * zoom_factor);
    OVERRIDE_HEIGHT = (uint32_t)(BASE_HEIGHT * zoom_factor);

    LOG("Zoom factor: %.2f, New dimensions: %u x %u",
           zoom_factor, OVERRIDE_WIDTH, OVERRIDE_HEIGHT);
}

void resize_window() {
    static bool resizing = false;

    // If there's no stage or we're resizing the window already, quit
    if (*STAGE == NULL || resizing) { return; }
    resizing = true;

    // Get the current game client
    struct stage_object obj = get_stage_object();

    // If we're in-game, re-center the screen
    if (strcmp(obj.name, "10GameClient") == 0) {
        // Force the game to recenter the screen
        void* world_client = *(void**)offset(obj.ptr, 0x80);
        reinitialize_offsets(world_client);
    }

    resizing = false;
}

struct stage_object get_stage_object(void) {
    void* deref  = *STAGE;
    char* child  = (char*)offset(deref, 0x30);

    struct stage_object obj;
    obj.ptr  = **(void***)child;
    obj.name = get_class_name(obj.ptr);

    return obj;
}

char* get_class_name(void* obj) {
    void*** vtable   = *(void****)obj;
    void**  typeinfo = *(vtable-1);
    void*   name     = *(typeinfo+1);
    return name;
}

void reinitialize_offsets(void* world_client) {
    if (world_client) {
        void* world_view = *(void**)offset(world_client, 0x80);
        bool* offsets_initialized = (bool*)offset(world_view, 0xB8);
        *offsets_initialized = false;

        (WIN_EVENT_CALLBACK)(WE_SIZE_CHANGED, *USER_DATA);
    }
}
