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
void __xbrtime_asm_fence();
void __xbrtime_asm_quiet_fence();
void __xbrtime_remote_touch( uint64_t addr, uint64_t target, uint64_t sense );
uint32_t xbrtime_decode_pe( int pe );

extern void xbrtime_barrier(){
  volatile uint64_t sense = __XBRTIME_CONFIG->_SENSE;
  volatile uint64_t tmp = 0x00ull;
  uint64_t target = 0x00ull;
  uint64_t addr = 0x00ull;

  /* sanity check */
  if( xbrtime_num_pes() == 1 ){
    return ;
  }
  /* force a heavy fence */
  __xbrtime_asm_fence();

#ifdef XBGAS_DEBUG
	printf("XBGAS_DEBUG:: PE = %d, sense = %ld, complete __xbrtime_asm_fence()\n",xbrtime_mype(), sense);
#endif
  /* derive the correct target pe */
  if( xbrtime_mype() != (xbrtime_num_pes()-1) ){
    target = xbrtime_mype()+1;
  }

#ifdef XBGAS_DEBUG
  printf( "XBGAS_DEBUG : PE=%d; BARRIER TARGET=%d\n", xbrtime_mype(),
          (int)(target) );
#endif

  /* convert to physical pe */
  target = (uint64_t)(xbrtime_decode_pe((int)(target)));

  /* inform the target */
  addr = (uint64_t)(&__XBRTIME_CONFIG->_BARRIER[sense]);
#ifdef XBGAS_DEBUG
  printf( "XBGAS_DEBUG : PE=%d; TOUCHING REMOTE ADDRESS ON PHYSICAL TARGET=%d\n",
          xbrtime_mype(),
          (int)(target) );
#endif
  //store the sense+1 to the remote target
  __xbrtime_remote_touch( addr, target, sense + 1 );
#ifdef XBGAS_DEBUG
	printf("\033[1m\033[32m XBGAS_DEBUG:: PE = %d, complete remote touch, sense = %ld, addr = 0x%lx, __XBRTIME_CONFIG->_BARRIER[sense]=%lx \033[0m \n",xbrtime_mype(), sense, addr,  __XBRTIME_CONFIG->_BARRIER[sense]);
  printf( "XBGAS_DEBUG : PE=%d; SUCCESS TOUCHING REMOTE ADDRESS\n", xbrtime_mype() );
#endif
  __xbrtime_asm_quiet_fence();

#ifdef XBGAS_DEBUG
	printf("\033[1m\033[35m XBGAS_DEBUG:: PE = %d, about to run __sync_fetch_and_add()\033[0m \n",xbrtime_mype());
#endif
  /* spinwait on local value */
  tmp = __sync_fetch_and_add(&__XBRTIME_CONFIG->_BARRIER[sense],0);
#ifdef XBGAS_DEBUG
	printf("XBGAS_DEBUG:: PE = %d, sense = %ld, tmp = 0x%lx\n",xbrtime_mype(), sense, tmp);
#endif
  while( tmp != (sense + 1) ){
    tmp = __sync_fetch_and_add(&__XBRTIME_CONFIG->_BARRIER[sense],0);
  	__xbrtime_remote_touch( addr, target, sense + 1 );
  	__xbrtime_asm_quiet_fence();

    //tmp = __sync_add_and_fetch(&__XBRTIME_CONFIG->_BARRIER[sense],0);
#ifdef XBGAS_DEBUG
		printf("XBGAS_DEBUG:: PE = %d, sense = %ld, tmp = 0x%lx\n",xbrtime_mype(), sense, tmp);
#endif
  }
#if 0
  tmp = __XBRTIME_CONFIG->_BARRIER;
  while( tmp != sense ){
    tmp = __XBRTIME_CONFIG->_BARRIER;
  }
#endif

#ifdef XBGAS_DEBUG
	printf("XBGAS_DEBUG:: PE = %d, complete  __sync_fetch_and_add()\n",xbrtime_mype());
#endif
  /* switch the sense */
  /*__XBRTIME_CONFIG->_BARRIER[sense] = 0xdeadbeefull;
  if( sense == 0 ){
    __XBRTIME_CONFIG->_SENSE = 1;
  }else{
    __XBRTIME_CONFIG->_SENSE = 0;
  }*/
	// Avoid conditional statements
  __XBRTIME_CONFIG->_SENSE = 1 - sense;

#ifdef XBGAS_DEBUG
  printf( "XBGAS_DEBUG : PE=%d; BARRIER COMPLETE\n", xbrtime_mype() );
#endif
}

/* EOF */
