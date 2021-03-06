/*
 * This file is part of the Micro Python project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Damien P. George
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "MicroBit.h"

extern "C" {

#include "py/runtime.h"
#include "modmicrobit.h"

typedef struct _microbit_compass_obj_t {
    mp_obj_base_t base;
    MicroBitCompass *compass;
} microbit_compass_obj_t;

mp_obj_t microbit_compass_is_calibrated(mp_obj_t self_in) {
    microbit_compass_obj_t *self = (microbit_compass_obj_t*)self_in;
    return mp_obj_new_bool(self->compass->isCalibrated());
}
MP_DEFINE_CONST_FUN_OBJ_1(microbit_compass_is_calibrated_obj, microbit_compass_is_calibrated);

mp_obj_t microbit_compass_calibrate(mp_obj_t self_in) {
    microbit_compass_obj_t *self = (microbit_compass_obj_t*)self_in;
    self->compass->calibrateAsync();
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_1(microbit_compass_calibrate_obj, microbit_compass_calibrate);

mp_obj_t microbit_compass_is_calibrating(mp_obj_t self_in) {
    microbit_compass_obj_t *self = (microbit_compass_obj_t*)self_in;
    return mp_obj_new_bool(self->compass->isCalibrating());
}
MP_DEFINE_CONST_FUN_OBJ_1(microbit_compass_is_calibrating_obj, microbit_compass_is_calibrating);

mp_obj_t microbit_compass_clear_calibration(mp_obj_t self_in) {
    microbit_compass_obj_t *self = (microbit_compass_obj_t*)self_in;
    self->compass->clearCalibration();
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_1(microbit_compass_clear_calibration_obj, microbit_compass_clear_calibration);

mp_obj_t microbit_compass_heading(mp_obj_t self_in) {
    microbit_compass_obj_t *self = (microbit_compass_obj_t*)self_in;
    return mp_obj_new_int(self->compass->heading());
}
MP_DEFINE_CONST_FUN_OBJ_1(microbit_compass_heading_obj, microbit_compass_heading);

mp_obj_t microbit_compass_get_x(mp_obj_t self_in) {
    microbit_compass_obj_t *self = (microbit_compass_obj_t*)self_in;
    return mp_obj_new_int(self->compass->getX());
}
MP_DEFINE_CONST_FUN_OBJ_1(microbit_compass_get_x_obj, microbit_compass_get_x);

mp_obj_t microbit_compass_get_y(mp_obj_t self_in) {
    microbit_compass_obj_t *self = (microbit_compass_obj_t*)self_in;
    return mp_obj_new_int(self->compass->getY());
}
MP_DEFINE_CONST_FUN_OBJ_1(microbit_compass_get_y_obj, microbit_compass_get_y);

mp_obj_t microbit_compass_get_z(mp_obj_t self_in) {
    microbit_compass_obj_t *self = (microbit_compass_obj_t*)self_in;
    return mp_obj_new_int(self->compass->getZ());
}
MP_DEFINE_CONST_FUN_OBJ_1(microbit_compass_get_z_obj, microbit_compass_get_z);

STATIC const mp_map_elem_t microbit_compass_locals_dict_table[] = {
    { MP_OBJ_NEW_QSTR(MP_QSTR_heading), (mp_obj_t)&microbit_compass_heading_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_is_calibrated), (mp_obj_t)&microbit_compass_is_calibrated_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_calibrate), (mp_obj_t)&microbit_compass_calibrate_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_is_calibrating), (mp_obj_t)&microbit_compass_is_calibrating_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_clear_calibration), (mp_obj_t)&microbit_compass_clear_calibration_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_get_x), (mp_obj_t)&microbit_compass_get_x_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_get_y), (mp_obj_t)&microbit_compass_get_y_obj },
    { MP_OBJ_NEW_QSTR(MP_QSTR_get_z), (mp_obj_t)&microbit_compass_get_z_obj },
};

STATIC MP_DEFINE_CONST_DICT(microbit_compass_locals_dict, microbit_compass_locals_dict_table);

STATIC const mp_obj_type_t microbit_compass_type = {
    { &mp_type_type },
    .name = MP_QSTR_MicroBitCompass,
    .print = NULL,
    .make_new = NULL,
    .call = NULL,
    .unary_op = NULL,
    .binary_op = NULL,
    .attr = NULL,
    .subscr = NULL,
    .getiter = NULL,
    .iternext = NULL,
    .buffer_p = {NULL},
    .stream_p = NULL,
    .bases_tuple = MP_OBJ_NULL,
    /* .locals_dict = */ (mp_obj_t)&microbit_compass_locals_dict,
};

const microbit_compass_obj_t microbit_compass_obj = {
    {&microbit_compass_type},
    .compass = &uBit.compass,
};

}
