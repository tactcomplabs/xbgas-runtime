/*
 * _XBRTIME_CTOR_C_
 *
 * Copyright (C) 2017-2018 Tactical Computing Laboratories, LLC
 * All Rights Reserved
 * contact@tactcomplabs.com
 *
 * This file is a part of the XBGAS-RUNTIME package.  For license
 * information, see the LICENSE file in the top level directory
 * of the distribution.
 *
 */

#include "xbrtime.h"

/* ------------------------------------------------- FUNCTION PROTOTYPES */
void __xbrtime_ctor_reg_reset();

__attribute__((constructor)) void __xbrtime_ctor(){
  /* initialize the unnecessary registers */
  __xbrtime_ctor_reg_reset();
}
