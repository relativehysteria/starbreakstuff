#pragma once

const float ZOOM_STEP = 0.1;
const float ZOOM_MIN  = 0.1;
const float ZOOM_MAX  = 5.0;

static const uint32_t BASE_WIDTH  = 1920;
static const uint32_t BASE_HEIGHT = 1080;

static uint32_t OVERRIDE_WIDTH  = BASE_WIDTH;
static uint32_t OVERRIDE_HEIGHT = BASE_HEIGHT;

void apply_zoom(float step);
void zoom_in();
void zoom_out();
