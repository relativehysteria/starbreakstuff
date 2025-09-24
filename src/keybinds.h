#pragma once

#include "zoom.h"

typedef void (*KeybindHandler)(void);

struct Keybind {
    char key;
    enum Keymod mod;
    KeybindHandler handler;
};

void handle_keybinds(uint32_t* event);


static struct Keybind keybinds[] = {
    { 'q', KMOD_CTRL, zoom_out },
    { 'e', KMOD_CTRL, zoom_in },
};
