#include "util.h"

// Clamp a value between min and max
float clamp(float val, float min, float max) {
    return (val < min) ? min : (val > max) ? max : val;
}

// Offset a pointer by some amount
void* offset(void* ptr, ssize_t num) {
    return (void*)((char*)ptr + num);
}

// Get the class name of an object assuming gcc layout
char* get_class_name(void* obj) {
    void*** vtable   = *(void****)obj;
    void**  typeinfo = *(vtable-1);
    void*   name     = *(typeinfo+1);
    return name;
}
