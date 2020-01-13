#ifndef MYPAINT_DAB_PARAMETERS_H
#define MYPAINT_DAB_PARAMETERS_H

/* libmypaint - The MyPaint Brush Library
 * Copyright (C) 2019 The MyPaint Team
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <stddef.h>

#include "mypaint-glib-compat.h"

G_BEGIN_DECLS

typedef struct MyPaintDabParams MyPaintDabParams;

/* Allocation, Initialization, Freeing */

size_t mypaint_dab_params_get_size();
MyPaintDabParams* mypaint_dab_params_new();
void mypaint_dab_params_init(MyPaintDabParams*);
void mypaint_dab_params_free(MyPaintDabParams*);

/* --------------------------------------- */

/* Getters/Setters */

void mypaint_dab_params_set_v1(MyPaintDabParams* self,
    float opacity, float hardness, float alpha_eraser, float aspect_ratio, float angle, float lock_alpha, float colorize,
    float posterize, float posterize_num, float paint);

void mypaint_dab_params_get_v1(const MyPaintDabParams* self,
    float* opacity, float* hardness, float* alpha_eraser, float* aspect_ratio, float* angle, float* lock_alpha,
    float* colorize, float* posterize, float* posterize_num, float* paint);

/* ------------------------------------ */

/* Access to internals - use with care */
float* mypaint_dab_params_floats(MyPaintDabParams* params);

/**
 * Number of float fields - do NOT use this to make assumption
 * about the size of the parameters type, only about the number
 * of float parameters accessible through indices.
 */
int mypaint_dab_params_num_floats();

/**
 *Index functions
 * for local caching and use with the floats accessor
 */
int mypaint_dab_params_index_opacity();
int mypaint_dab_params_index_hardness();
int mypaint_dab_params_index_alpha_eraser();
int mypaint_dab_params_index_aspect_eraser();
int mypaint_dab_params_index_angle();
int mypaint_dab_params_index_lock_alpha();
int mypaint_dab_params_index_colorize();
int mypaint_dab_params_index_posterize();
int mypaint_dab_params_index_posterize_num();
int mypaint_dab_params_index_pigment_factor();

G_END_DECLS

#endif
