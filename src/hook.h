#pragma once

#include <stdint.h>
#include "macros.h"

enum window_event {
    WE_INVALID = 0x0,
    WE_SIZE_CHANGED = 0x1,
    WE_RESIZED = 0x2,
    WE_FOCUS_LOST = 0x3,
};

struct stage_object {
    char* name;
    void* ptr;
};

// Library function definitions that we want to hook
typedef uint32_t (*_SDL_PollEvent)(void* event);
typedef void (*_SDL_GetWindowSize)(void*, int*, int*);
typedef void (*_windowEventCallback)(enum window_event, void*);

// Constant game pointers
static _windowEventCallback WIN_EVENT_CALLBACK = (_windowEventCallback)0x477e10;
static void** USER_DATA = (void**)0x847610;
static void** STAGE = (void**)0x82eeb8;
static uint32_t* CANVAS_H = (uint32_t*)0x847418;
static uint32_t* CANVAS_W = (uint32_t*)0x84741c;

// Function signatures
void resize_window();
struct stage_object get_stage_object(void);
char* get_class_name(void* obj);
void reinitialize_offsets(void* world_client);
