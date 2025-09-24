#include "util.h"

float clamp(float val, float min, float max) {
    return (val < min) ? min : (val > max) ? max : val;
}

void* offset(void* ptr, ssize_t num) {
    return (void*)((char*)ptr + num);
}
