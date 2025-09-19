#pragma once

#include <stdint.h>
#include "macros.h"

// Enums, structs and shit

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
typedef void (*_windowEventCallback)(enum window_event, void*);
typedef uint32_t (*_SDL_PollEvent)(void* event);
typedef void    (*_SDL_GetWindowSize)(void*, int*, int*);
// typedef int32_t (*_SDL_Init)(uint32_t);
// typedef void    (*_windowEventCallback)(enum window_event, void*);

// Constant game pointers
// static _windowEventCallback win_event_callback = (_windowEventCallback)0x477e10;
// static void** user_data = (void**)0x847610;
// static void** stage = (void**)0x82eeb8;
static uint32_t* canvas_h = (uint32_t*)0x847418;
static uint32_t* canvas_w = (uint32_t*)0x84741c;

// Function signatures
// void resize_window();
// struct stage_object get_stage_object(void);
// char* get_class_name(void* obj);
// void* find_orig(char* name);
// void reinitialize_offsets(void* world_client);
void* offset(void* ptr, ssize_t num) { return (void*)((char*)ptr + num); }
