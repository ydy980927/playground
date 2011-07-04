#ifndef FRENDERER_H
#define FRENDERER_H

#include "fender.h"

/**
 *
 */
void renderer_init();

/**
 *
 */
void renderer_calculate_fps();

/**
 *
 */
float renderer_get_fps();

/**
 *
 */
void renderer_resize(int w, int h);

/**
 *
 */
void renderer_render(void);

#endif