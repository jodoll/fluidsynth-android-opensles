/* FluidSynth - A Software Synthesizer
 *
 * Copyright (C) 2003  Peter Hanappe and others.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA
 */

#ifndef _FLUID_CONV_H
#define _FLUID_CONV_H

#include "fluidsynth_priv.h"

#define FLUID_CENTS_HZ_SIZE     1200
#define FLUID_VEL_CB_SIZE       128
#define FLUID_CB_AMP_SIZE       1441
#define FLUID_PAN_SIZE          1002

void fluid_conversion_config(void);

fluid_real_t fluid_ct2hz_real(fluid_real_t cents);
fluid_real_t fluid_ct2hz(fluid_real_t cents);
fluid_real_t fluid_cb2amp(fluid_real_t cb);
fluid_real_t fluid_tc2sec(fluid_real_t tc);
fluid_real_t fluid_tc2sec_delay(fluid_real_t tc);
fluid_real_t fluid_tc2sec_attack(fluid_real_t tc);
fluid_real_t fluid_tc2sec_release(fluid_real_t tc);
fluid_real_t fluid_act2hz(fluid_real_t c);
fluid_real_t fluid_hz2ct(fluid_real_t c);
fluid_real_t fluid_pan(fluid_real_t c, int left);
fluid_real_t fluid_balance(fluid_real_t balance, int left);
fluid_real_t fluid_concave(fluid_real_t val);
fluid_real_t fluid_convex(fluid_real_t val);

extern fluid_real_t fluid_ct2hz_tab[FLUID_CENTS_HZ_SIZE];
extern fluid_real_t fluid_vel2cb_tab[FLUID_VEL_CB_SIZE];
extern fluid_real_t fluid_cb2amp_tab[FLUID_CB_AMP_SIZE];
extern fluid_real_t fluid_concave_tab[128];
extern fluid_real_t fluid_convex_tab[128];
extern fluid_real_t fluid_pan_tab[FLUID_PAN_SIZE];


#endif /* _FLUID_CONV_H */
