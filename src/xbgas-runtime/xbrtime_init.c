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

/* ------------------------------------------------- GLOBALS */
XBRTIME_DATA *__XBRTIME_CONFIG;

/* ------------------------------------------------- FUNCTION PROTOTYPES */
size_t __xbrtime_asm_get_memsize();
int __xbrtime_asm_get_id();
int __xbrtime_asm_get_npes();
uint64_t __xbrtime_asm_get_startaddr();

extern void xbrtime_close(){

  /* TODO; free all the memory */

  if( __XBRTIME_CONFIG != NULL ){
    free( __XBRTIME_CONFIG );
  }
}

extern int xbrtime_init(){

  /* vars */
  int i = 0;

  /* allocate the structure in the local heap */
  __XBRTIME_CONFIG = NULL;
  __XBRTIME_CONFIG = malloc( sizeof( XBRTIME_DATA ) );
  if( __XBRTIME_CONFIG == NULL ){
    return -1;
  }

  __XBRTIME_CONFIG->_MMAP       = NULL;
  __XBRTIME_CONFIG->_ID         = __xbrtime_asm_get_id();
  __XBRTIME_CONFIG->_MEMSIZE    = __xbrtime_asm_get_memsize();
  __XBRTIME_CONFIG->_NPES       = __xbrtime_asm_get_npes();
  __XBRTIME_CONFIG->_START_ADDR = __xbrtime_asm_get_startaddr();

  // we deem anything less than a 4K page to be
  // too small for our needs
  if( __XBRTIME_CONFIG->_MEMSIZE < 4096 ){
    free( __XBRTIME_CONFIG );
    return -1;
  }

  __XBRTIME_CONFIG->_FREEBLOCKS = (__XBRTIME_CONFIG->_MEMSIZE/4096);

  /* init the PE mapping structure */
  for( i=0; i<__XBRTIME_CONFIG->_NPES; i++ ){
    __XBRTIME_CONFIG->_MAP[i]._LOGICAL   = i;
    __XBRTIME_CONFIG->_MAP[i]._PHYSICAL  = i+1;
  }
  for( i=__XBRTIME_CONFIG->_NPES; i<__XBRTIME_MAX_PE; i++ ){
    __XBRTIME_CONFIG->_MAP[i]._LOGICAL   = -1;
    __XBRTIME_CONFIG->_MAP[i]._PHYSICAL  = -1;
  }
  return 0;
}

/* EOF */
