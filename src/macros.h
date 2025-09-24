#pragma once

#include <dlfcn.h>
#include <stdio.h>

void* find_orig(char* name);

#define LOG(fmt, ...) \
    fprintf(stderr, "[hook|%s] " fmt "\n", __func__, ##__VA_ARGS__)

#define ORIG_SET (orig && ((size_t)orig != -1))

#define _GET_MACRO(_1, _2, NAME, ...) NAME

#define _CALL_ORIG1(call) \
    if (ORIG_SET) { (call); } \
    return;                   \

#define _CALL_ORIG2(call, fallback) \
    if (ORIG_SET) {    \
        return (call); \
    }                  \
    return (fallback); \

#define CALL_ORIG(...) \
    _GET_MACRO(__VA_ARGS__, _CALL_ORIG2, _CALL_ORIG1)(__VA_ARGS__)

#define INIT_ORIG(name) \
    static _##name orig = NULL;           \
    if (!orig) {                          \
        orig = (_##name)find_orig(#name); \
    }                                     \

void* find_orig(char* name) {
    void* orig = dlsym(RTLD_NEXT, name);

    if (!orig) {
        LOG("Could not find original function '%s'\n", name);
        orig = (void*)-1;
    } else {
        LOG("Hook set up for '%s'\n", name);
    }

    return orig;
}
