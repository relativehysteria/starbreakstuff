#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "hook.h"
#include "macros.h"
#include "sdl.h"
#include "keybinds.h"
#include "zoom.h"

void SDL_GetWindowSize(void* window, int *w, int *h) {
    LOG("%x %x", OVERRIDE_WIDTH, OVERRIDE_HEIGHT);
    *w = OVERRIDE_WIDTH;
    *h = OVERRIDE_HEIGHT;
    *CANVAS_W = *w;
    *CANVAS_H = *h;
    // resize_window();
}

// Keybinds yay
uint32_t SDL_PollEvent(uint32_t* event) {
    INIT_ORIG(SDL_PollEvent);

    uint32_t result = orig(event);
    if (result) handle_keybinds(event);

    return result;
}
