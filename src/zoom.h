#pragma once

#define ZOOM_STEP 0.1
#define ZOOM_MIN  0.1
#define ZOOM_MAX  5.0

#define BASE_WIDTH  1920
#define BASE_HEIGHT 1080

extern uint32_t OVERRIDE_WIDTH;
extern uint32_t OVERRIDE_HEIGHT;

void apply_zoom(float step);
void zoom_in();
void zoom_out();
