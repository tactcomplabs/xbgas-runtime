/*
 * _XBRTIME_ALLOC_C_
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


extern void *xbrtime_malloc( size_t sz ){
  void *ptr = NULL;

  if( sz == 0 ){
    return NULL;
  }

  return ptr;
}

extern void xbrtime_free( void *ptr ){
  if( ptr == NULL ){
    return ;
  }
}
