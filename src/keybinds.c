#include <stdint.h>
#include "sdl.h"
#include "macros.h"
#include "keybinds.h"

const struct Keybind keybinds[] = {
    { 'q', KMOD_CTRL, zoom_out },
    { 'e', KMOD_CTRL, zoom_in },
};

// Handle registered keybinds
void handle_keybinds(uint32_t* event) {
    // Only handle pressed keys
    if (*event != KEY_DOWN) return;

    // Cast the event as a keyboard event
    struct KeyboardEvent* key_event = (struct KeyboardEvent*)event;

    // Ignore repeats
    if (key_event->repeat) return;

    // Get the currently pressed key and mod
    struct Keysym sym = key_event->keysym;
    char key = (char)sym.keycode;
    enum Keymod mod = sym.mod;

    // Trigger the bind. A hashmap would be negligibly better here.
    for (size_t i = 0; i < (sizeof(keybinds) / sizeof(keybinds[0])); i++) {
        if (keybinds[i].key == key && (keybinds[i].mod & mod) != 0) {
            keybinds[i].handler();
        }
    }
}
