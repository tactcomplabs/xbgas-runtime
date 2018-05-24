/*
 * _XBRTIME_UTIL_C_
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

extern int xbrtime_addr_accessible( const void *addr, int pe ){
  if( pe > (__XBRTIME_CONFIG->_NPES-1) ){
    return 0;
  }

  if( ((uint64_t)(addr) >
      (__XBRTIME_CONFIG->_START_ADDR+__XBRTIME_CONFIG->_MEMSIZE)) ||
      ((uint64_t)(addr) < (__XBRTIME_CONFIG->_START_ADDR)) ){
    return 0;
  }

  return 1;
}

/* EOF */
