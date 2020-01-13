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
#include <malloc.h>

#include "mypaint-stroke-enum.c"
#include "mypaint-stroke-params.h"

struct MyPaintStrokeParams {
  float float_params[STROKE_NUM_PARAMS];
};

size_t
mypaint_stroke_params_get_size()
{
    return sizeof(MyPaintStrokeParams);
}

MyPaintStrokeParams*
mypaint_stroke_params_new()
{
    return malloc(sizeof(MyPaintStrokeParams));
}

void
mypaint_stroke_params_free(MyPaintStrokeParams* params)
{
    free(params);
}

void
mypaint_stroke_params_init(MyPaintStrokeParams* params)
{
    params->float_params[STROKE_PARAM_XTILT] = 0.0;
    params->float_params[STROKE_PARAM_YTILT] = 0.0;
    params->float_params[STROKE_PARAM_VIEWZOOM] = 1.0;
    params->float_params[STROKE_PARAM_VIEWROTATION] = 0.0;
    params->float_params[STROKE_PARAM_BARRELROTATION] = 0.0;
}

/* Setters/Getters */

void
mypaint_stroke_params_xtilt_set(MyPaintStrokeParams* params, float xtilt)
{
    params->float_params[STROKE_PARAM_XTILT] = xtilt;
}

float
mypaint_stroke_params_xtilt_get(const MyPaintStrokeParams* params)
{
    return params->float_params[STROKE_PARAM_XTILT];
}

void
mypaint_stroke_params_ytilt_set(MyPaintStrokeParams* params, float ytilt)
{
    params->float_params[STROKE_PARAM_YTILT] = ytilt;
}

float
mypaint_stroke_params_ytilt_get(const MyPaintStrokeParams* params)
{
    return params->float_params[STROKE_PARAM_YTILT];
}

void
mypaint_stroke_params_viewzoom_set(MyPaintStrokeParams* params, float viewzoom)
{
    params->float_params[STROKE_PARAM_VIEWZOOM] = viewzoom;
}

float
mypaint_stroke_params_viewzoom_get(const MyPaintStrokeParams* params)
{
    return params->float_params[STROKE_PARAM_VIEWZOOM];
}

void
mypaint_stroke_params_viewrotation_set(MyPaintStrokeParams* params, float viewrotation)
{
    params->float_params[STROKE_PARAM_VIEWROTATION] = viewrotation;
}

float
mypaint_stroke_params_viewrotation_get(const MyPaintStrokeParams* params)
{
    return params->float_params[STROKE_PARAM_VIEWROTATION];
}

void
mypaint_stroke_params_barrelrotation_set(MyPaintStrokeParams* params, float barrelrotation)
{
    params->float_params[STROKE_PARAM_BARRELROTATION] = barrelrotation;
}

float
mypaint_stroke_params_barrelrotation_get(const MyPaintStrokeParams* params)
{
    return params->float_params[STROKE_PARAM_BARRELROTATION];
}

/* Internal access */

float*
mypaint_stroke_params_floats(MyPaintStrokeParams * params) {
  return params->float_params;
}

int
mypaint_stroke_params_num_floats() {
  return STROKE_NUM_PARAMS;
}

/* Index functions */

int
mypaint_stroke_params_index_xtilt()
{
    return STROKE_PARAM_XTILT;
}

int
mypaint_stroke_params_index_ytilt()
{
    return STROKE_PARAM_YTILT;
}

int
mypaint_stroke_params_index_viewzoom()
{
    return STROKE_PARAM_VIEWZOOM;
}

int
mypaint_stroke_params_index_viewrotation()
{
    return STROKE_PARAM_VIEWROTATION;
}

int
mypaint_stroke_params_index_barrelrotation()
{
    return STROKE_PARAM_BARRELROTATION;
}
