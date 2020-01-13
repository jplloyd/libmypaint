#ifndef MYPAINT_STROKE_PARAMETERS_H
#define MYPAINT_STROKE_PARAMETERS_H

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

typedef struct MyPaintStrokeParams MyPaintStrokeParams;

/* Allocation, Initialization, Deallocation */

size_t
mypaint_stroke_params_get_size();

MyPaintStrokeParams *
mypaint_stroke_params_new();

void
mypaint_stroke_params_init(MyPaintStrokeParams *);

void
mypaint_stroke_params_free(MyPaintStrokeParams *);

/* --------------------------------------- */

/* Direct getters/setters */

void
mypaint_stroke_params_xtilt_set(MyPaintStrokeParams*, float xtilt);

float
mypaint_stroke_params_xtilt_get(const MyPaintStrokeParams*);

void
mypaint_stroke_params_ytilt_set(MyPaintStrokeParams*, float ytilt);

float
mypaint_stroke_params_ytilt_get(const MyPaintStrokeParams*);

void
mypaint_stroke_params_viewzoom_set(MyPaintStrokeParams*, float viewzoom);

float
mypaint_stroke_params_viewzoom_get(const MyPaintStrokeParams*);

void
mypaint_stroke_params_viewrotation_set(MyPaintStrokeParams*, float viewrotation);

float
mypaint_stroke_params_viewrotation_get(const MyPaintStrokeParams*);

void
mypaint_stroke_params_barrelrotation_set(MyPaintStrokeParams*, float barrelrotation);

float
mypaint_stroke_params_barrelrotation_get(const MyPaintStrokeParams*);

/* ------------------------------------ */

/* Access to internals */
float*
mypaint_stroke_params_floats(MyPaintStrokeParams *);

/**
 * Number of float fields - do NOT use this to make assumption
 * about the size of the parameters type, only about the number
 * of float parameters accessible through indices.
 */
int
mypaint_stroke_params_num_floats();


/**
 *Index functions
 * for local caching and use with the floats accessor
 *
 */
int
mypaint_stroke_params_index_xtilt();

int
mypaint_stroke_params_index_ytilt();

int
mypaint_stroke_params_index_viewzoom();

int
mypaint_stroke_params_index_viewrotation();

int
mypaint_stroke_params_index_barrelrotation();

#endif
