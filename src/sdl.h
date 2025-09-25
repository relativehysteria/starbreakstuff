#pragma once

#include <stdint.h>

#define KEY_DOWN 0x300
#define KEY_UP   0x301

enum Keymod {
    KMOD_NONE   = 0x0000,
    KMOD_LSHIFT = 0x0001,
    KMOD_RSHIFT = 0x0002,
    KMOD_SHIFT  = KMOD_LSHIFT | KMOD_RSHIFT,
    KMOD_LCTRL  = 0x0040,
    KMOD_RCTRL  = 0x0080,
    KMOD_CTRL   = KMOD_LCTRL | KMOD_RCTRL,
};

struct Keysym {
    int32_t scancode;
    int32_t keycode;
    uint16_t mod;
};

struct KeyboardEvent {
    uint32_t type;
    uint32_t timestamp;
    uint32_t window_id;
    uint8_t  state;
    uint8_t  repeat;
    uint8_t  padding0;
    uint8_t  padding1;
    struct Keysym keysym;
};
