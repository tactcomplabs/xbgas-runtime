/*
 * _XBRTIME_BARRIER_C_
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
void __xbrtime_asm_quiet_fence();
void __xbrtime_remote_touch( uint64_t addr, uint64_t target, uint64_t sense );
uint32_t xbrtime_decode_pe( int pe );

extern void xbrtime_barrier(){
  uint64_t sense = __XBRTIME_CONFIG->_SENSE;
  uint64_t target = 0x00ull;
  uint64_t addr = 0x00ull;
  uint64_t tmp = 0x00ull;

  /* sanity check */
  if( xbrtime_num_pes() == 1 ){
    return ;
  }

  /* derive the correct target pe */
  if( xbrtime_mype() != (xbrtime_num_pes()-1) ){
    target = xbrtime_mype()+1;
  }

  printf( "PE=%d; BARRIER TARGET=%d\n", xbrtime_mype(),
          (int)(target) );

  /* convert to physical pe */
  target = (uint64_t)(xbrtime_decode_pe((int)(target)));

  /* inform the target */
  addr = (uint64_t)(&__XBRTIME_CONFIG->_BARRIER);
  __xbrtime_remote_touch( addr, target, sense );
  __xbrtime_asm_quiet_fence();

  /* spinwait on local value */
  tmp = __sync_fetch_and_add(&__XBRTIME_CONFIG->_BARRIER,0);
  while( tmp != sense ){
    tmp = __sync_fetch_and_add(&__XBRTIME_CONFIG->_BARRIER,0);
  }

  /* switch the sense */
  if( sense == 0 ){
    __XBRTIME_CONFIG->_SENSE = 1;
  }else{
    __XBRTIME_CONFIG->_SENSE = 0;
  }
}

/* EOF */
