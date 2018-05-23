/*
 * _XBRTIME_INIT_C_
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

XBRTIME_DATA __XBRTIME_CONFIG;

extern int xbrtime_init( int NPEs, size_t MSIZE ){

  /* vars */
  int i = 0;

  /* sanity check */

  __XBRTIME_CONFIG._MEMSIZE = MSIZE;
  __XBRTIME_CONFIG._NPES = NPEs;
  __XBRTIME_CONFIG._START_ADDR = __XBRTIME_BASE_ADDR;

  /* -- todo, retrieve the local id */

  /* init the PE mapping structure */
  for( i=0; i<NPEs; i++ ){
    __XBRTIME_CONFIG._MAP[i]._LOGICAL   = i;
    __XBRTIME_CONFIG._MAP[i]._PHYSICAL  = i;
  }
  for( i=NPEs; i<__XBRTIME_MAX_PE; i++ ){
    __XBRTIME_CONFIG._MAP[i]._LOGICAL   = -1;
    __XBRTIME_CONFIG._MAP[i]._PHYSICAL  = -1;
  }
  return 0;
}

/* EOF */
