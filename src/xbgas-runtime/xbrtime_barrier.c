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
#define SENSE __XBRTIME_CONFIG->_SENSE
//#define XBGAS_DEBUG



/* ------------------------------------------------- FUNCTION PROTOTYPES */
void __xbrtime_asm_fence();
void __xbrtime_asm_quiet_fence();
void __xbrtime_remote_touch( _XBRTIME_XLEN_ addr, _XBRTIME_XLEN_ target, _XBRTIME_XLEN_ sense );
uint32_t xbrtime_decode_pe( int pe );

extern void xbrtime_barrier(){

	int32_t 								i 							= 0; 
	int32_t									stride 					= 1;
  volatile _XBRTIME_XLEN_ sense 					= SENSE;
  _XBRTIME_XLEN_ 					target 					= 0x00ull;
  _XBRTIME_XLEN_ 					addr 						= 0x00ull;
	_XBRTIME_XLEN_					num_pe 					= xbrtime_num_pes();
	
  /* sanity check */
  if( num_pe == 1 ){
    return ;
  }
	
	/*Get the total iterations */
	_XBRTIME_XLEN_  mype   = xbrtime_mype();
	_XBRTIME_XLEN_	 iter   = (_XBRTIME_XLEN_)(log(num_pe)/log(2));
	if (iter < log(num_pe)/log(2))
		iter++;
  
  /* force a heavy fence */
  __xbrtime_asm_fence();

#ifdef XBGAS_DEBUG
	printf("XBGAS_DEBUG:: PE = %d, sense = %ld, complete __xbrtime_asm_fence()\n",xbrtime_mype(), sense);
#endif
	while(i < iter){
  	/* derive the correct target pe */
		target 	= (mype + stride)%num_pe; 
#ifdef XBGAS_DEBUG
  	printf( "XBGAS_DEBUG : PE=%d; BARRIER TARGET=%d\n", xbrtime_mype(),
          (int)(target) );
#endif

  	target 	= (_XBRTIME_XLEN_)(xbrtime_decode_pe((int)(target)));
  	addr 		= (_XBRTIME_XLEN_)(&__XBRTIME_CONFIG->_BARRIER[sense*10+i]);
#ifdef XBGAS_DEBUG
  	printf( "XBGAS_DEBUG : PE=%d; TOUCHING REMOTE ADDRESS ON PHYSICAL TARGET=%d\n",
          xbrtime_mype(),
          (int)(target) );
#endif
  	__xbrtime_remote_touch( addr, target, stride);	
#ifdef XBGAS_DEBUG
		printf("\033[1m\033[32m XBGAS_DEBUG:: PE = %d, complete remote touch, sense = %ld, addr = 0x%lx, __XBRTIME_CONFIG->_BARRIER[sense]=%lx \033[0m \n",xbrtime_mype(), sense, addr,  __XBRTIME_CONFIG->_BARRIER[sense]);
  	printf( "XBGAS_DEBUG : PE=%d; SUCCESS TOUCHING REMOTE ADDRESS\n", xbrtime_mype() );
#endif


  	/* spinwait on local value */
 		while( __XBRTIME_CONFIG->_BARRIER[SENSE*10+i] != stride ){
#ifdef XBGAS_DEBUG
			printf("XBGAS_DEBUG:: PE = %d, sense = %ld, local barrier var = 0x%lx\n",xbrtime_mype(), sense, __XBRTIME_CONFIG->_BARRIER[SENSE]);
#endif
		}


		stride *= 2;
		i++;

	}



  //__xbrtime_asm_quiet_fence();

  //tmp = __sync_add_and_fetch(&__XBRTIME_CONFIG->_BARRIER[sense],0);
  //__sync_fetch_and_add(&__XBRTIME_CONFIG->_BARRIER[SENSE],0);

  /* spinwait on local value */
#if 0
  tmp = __XBRTIME_CONFIG->_BARRIER;
  while( tmp != sense ){
    tmp = __XBRTIME_CONFIG->_BARRIER;
  }
#endif

  /* switch the sense */
	for (i = 0; i < iter; i++)
  	__XBRTIME_CONFIG->_BARRIER[SENSE*10+i] = 0xdeadbeefull;
	// Flip the Sense
  SENSE = 1 - SENSE;

#ifdef XBGAS_DEBUG
  printf( "XBGAS_DEBUG : PE=%d; BARRIER COMPLETE\n", xbrtime_mype() );
#endif
}


/* EOF */
