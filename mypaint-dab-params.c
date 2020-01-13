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

#include "mypaint-dab-enum.c"
#include "mypaint-dab-params.h"
#include "mypaint-brush-settings.h"

struct MyPaintDabParams {
  float float_params[DAB_NUM_PARAMS];
};

size_t
mypaint_dab_params_get_size()
{
    return sizeof(MyPaintDabParams);
}

MyPaintDabParams*
mypaint_dab_params_new()
{
    MyPaintDabParams* params =  malloc(sizeof(MyPaintDabParams));
    if (params) {
      mypaint_dab_params_init(params);
    }
    return params;
}

void
mypaint_dab_params_free(MyPaintDabParams* params)
{
    free(params);
}

void
mypaint_dab_params_init(MyPaintDabParams* params)
{
    float* real_params = params->float_params;
    real_params[DAB_PARAM_OPAQUE] = mypaint_brush_setting_info(MYPAINT_BRUSH_SETTING_OPAQUE)->def;
    real_params[DAB_PARAM_HARDNESS] = mypaint_brush_setting_info(MYPAINT_BRUSH_SETTING_HARDNESS)->def;
    real_params[DAB_PARAM_ALPHA_ERASER] = mypaint_brush_setting_info(MYPAINT_BRUSH_SETTING_ERASER)->def;
    real_params[DAB_PARAM_ASPECT_RATIO] = mypaint_brush_setting_info(MYPAINT_BRUSH_SETTING_ELLIPTICAL_DAB_RATIO)->def;
    real_params[DAB_PARAM_ANGLE] = mypaint_brush_setting_info(MYPAINT_BRUSH_SETTING_ELLIPTICAL_DAB_ANGLE)->def;
    real_params[DAB_PARAM_LOCK_ALPHA] = mypaint_brush_setting_info(MYPAINT_BRUSH_SETTING_LOCK_ALPHA)->def;
    real_params[DAB_PARAM_COLORIZE] = mypaint_brush_setting_info(MYPAINT_BRUSH_SETTING_COLORIZE)->def;
    real_params[DAB_PARAM_POSTERIZE] = mypaint_brush_setting_info(MYPAINT_BRUSH_SETTING_POSTERIZE)->def;
    real_params[DAB_PARAM_POSTERIZE_NUM] = mypaint_brush_setting_info(MYPAINT_BRUSH_SETTING_POSTERIZE_NUM)->def;
    real_params[DAB_PARAM_PIGMENT_FACTOR] = mypaint_brush_setting_info(MYPAINT_BRUSH_SETTING_PAINT_MODE)->def;
}

/* Setters/Getters */

void
mypaint_dab_params_set_v1(
    MyPaintDabParams* self, float opacity, float hardness, float alpha_eraser, float aspect_ratio, float angle,
    float lock_alpha, float colorize, float posterize, float posterize_num, float pigment_factor)
{
    float* p = self->float_params;
    p[DAB_PARAM_OPAQUE] = opacity;
    p[DAB_PARAM_HARDNESS] = hardness;
    p[DAB_PARAM_ALPHA_ERASER] = alpha_eraser;
    p[DAB_PARAM_ASPECT_RATIO] = aspect_ratio;
    p[DAB_PARAM_ANGLE] = angle;
    p[DAB_PARAM_LOCK_ALPHA] = lock_alpha;
    p[DAB_PARAM_COLORIZE] = colorize;
    p[DAB_PARAM_POSTERIZE] = posterize;
    p[DAB_PARAM_POSTERIZE_NUM] = posterize_num;
    p[DAB_PARAM_PIGMENT_FACTOR] = pigment_factor;
}

void
mypaint_dab_params_get_v1(
    const MyPaintDabParams* self, float* opacity, float* hardness, float* alpha_eraser, float* aspect_ratio,
    float* angle, float* lock_alpha, float* colorize, float* posterize, float* posterize_num, float* paint)
{
    const float* p = self->float_params;
    *opacity = p[DAB_PARAM_OPAQUE];
    *hardness = p[DAB_PARAM_HARDNESS];
    *alpha_eraser = p[DAB_PARAM_ALPHA_ERASER];
    *aspect_ratio = p[DAB_PARAM_ASPECT_RATIO];
    *angle = p[DAB_PARAM_ANGLE];
    *lock_alpha = p[DAB_PARAM_LOCK_ALPHA];
    *colorize = p[DAB_PARAM_COLORIZE];
    *posterize = p[DAB_PARAM_POSTERIZE];
    *posterize_num = p[DAB_PARAM_POSTERIZE_NUM];
    *paint = p[DAB_PARAM_PIGMENT_FACTOR];
}

/* ------------------------------------ */

float* mypaint_dab_params_floats(MyPaintDabParams* params) {
  return params->float_params;
}

int
mypaint_dab_params_num_floats() {
  return DAB_NUM_PARAMS;
}

int mypaint_dab_params_index_opacity() {return DAB_PARAM_OPAQUE;}
int mypaint_dab_params_index_hardness() {return DAB_PARAM_HARDNESS;}
int mypaint_dab_params_index_alpha_eraser() {return DAB_PARAM_ALPHA_ERASER;}
int mypaint_dab_params_index_aspect_ratio() {return DAB_PARAM_ASPECT_RATIO;}
int mypaint_dab_params_index_angle() {return DAB_PARAM_ANGLE;}
int mypaint_dab_params_index_lock_alpha() {return DAB_PARAM_LOCK_ALPHA;}
int mypaint_dab_params_index_colorize() {return DAB_PARAM_COLORIZE;}
int mypaint_dab_params_index_posterize() {return DAB_PARAM_POSTERIZE;}
int mypaint_dab_params_index_posterize_num() {return DAB_PARAM_POSTERIZE_NUM;}
int mypaint_dab_params_index_pigment_factor() {return DAB_PARAM_PIGMENT_FACTOR;}
