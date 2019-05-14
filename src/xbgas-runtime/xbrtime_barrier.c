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



//uint64_t iter = 1;
/* ------------------------------------------------- FUNCTION PROTOTYPES */
void __xbrtime_asm_fence();
void __xbrtime_asm_quiet_fence();
void __xbrtime_remote_touch( uint64_t addr, uint64_t target, uint64_t sense );
uint32_t xbrtime_decode_pe( int pe );

extern void xbrtime_barrier(){
	/*if(__XBRTIME_CONFIG->_INIT == 0){
		__XBRTIME_CONFIG->_INIT = 1;
  	xbrtime_barrier_full();
		return;
	}*/

  volatile uint64_t sense = SENSE;
  //volatile uint64_t tmp = 0x00ull;
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
		// reset iteration once 
		//if(iter == UINT64_MAX)
		//	iter = 0;
		//__sync_fetch_and_add(&iter, 1);
		//__sync_fetch_and_add(&sense,iter);
		//iter++;
    //store the sense to the remote target
  	__xbrtime_remote_touch( addr, target, sense);	
		
#ifdef XBGAS_DEBUG
	printf("\033[1m\033[32m XBGAS_DEBUG:: PE = %d, complete remote touch, sense = %ld, addr = 0x%lx, __XBRTIME_CONFIG->_BARRIER[sense]=%lx \033[0m \n",xbrtime_mype(), sense, addr,  __XBRTIME_CONFIG->_BARRIER[sense]);
  printf( "XBGAS_DEBUG : PE=%d; SUCCESS TOUCHING REMOTE ADDRESS\n", xbrtime_mype() );
#endif
  //__xbrtime_asm_quiet_fence();

#ifdef XBGAS_DEBUG
	printf("\033[1m\033[35m XBGAS_DEBUG:: PE = %d, about to run __sync_fetch_and_add()\033[0m \n",xbrtime_mype());
#endif
  //tmp = __sync_add_and_fetch(&__XBRTIME_CONFIG->_BARRIER[sense],0);
  //__sync_fetch_and_add(&__XBRTIME_CONFIG->_BARRIER[SENSE],0);
#ifdef XBGAS_DEBUG
	printf("XBGAS_DEBUG:: PE = %d, sense = %ld, tmp = 0x%lx\n",xbrtime_mype(), sense, tmp);
#endif

  /* spinwait on local value */
 while( __XBRTIME_CONFIG->_BARRIER[SENSE] != (sense) ){
    //__sync_fetch_and_add(&__XBRTIME_CONFIG->_BARRIER[__XBRTIME_CONFIG->_SENSE],0);
    //tmp = __sync_add_and_fetch(&__XBRTIME_CONFIG->_BARRIER[sense],0);
  	//__xbrtime_asm_quiet_fence();
#ifdef XBGAS_DEBUG
		printf("XBGAS_DEBUG:: PE = %d, sense = %ld, local barrier var = 0x%lx\n",xbrtime_mype(), sense, __XBRTIME_CONFIG->_BARRIER[SENSE]);
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
  __XBRTIME_CONFIG->_BARRIER[SENSE] = 0xdeadbeefull;
  /*if( SENSE == 0 ){
    SENSE = 1;
  }else{
    SENSE = 0;
  }*/
	// Avoid conditional statements
  SENSE = 1 - SENSE;

#ifdef XBGAS_DEBUG
  printf( "XBGAS_DEBUG : PE=%d; BARRIER COMPLETE\n", xbrtime_mype() );
#endif
}

extern void xbrtime_barrier_full(){
  volatile uint64_t sense = __XBRTIME_CONFIG->_SENSE_FULL;
  volatile uint64_t tmp = 0x00ull;
  uint64_t target = 0x00ull;
  uint64_t addr = 0x00ull;
	int mype = 0;
	int i    = 0;
	volatile int flag = 1;
	int size = 0;
	
  /* sanity check */
	size = xbrtime_num_pes();
  if( size == 1 ){
    return ;
  }
	mype = xbrtime_mype();
  /* force a heavy fence */
  __xbrtime_asm_fence();
#ifdef XBGAS_DEBUG
	printf("XBGAS_DEBUG:: PE = %d, sense = %ld, complete __xbrtime_asm_fence()\n",xbrtime_mype(), sense);
#endif

	if(mype != 0){
		//printf("XBGAS_DEBUG:: PE = %d starts the barrier, sense = %ld, BARRIER_FULL[0]= %lu\n",xbrtime_mype(), sense,  __XBRTIME_CONFIG->_BARRIER_FULL[0+sense*size]);
    target = 0;
  	target = (uint64_t)(xbrtime_decode_pe((int)(target)));
  	addr = (uint64_t)(&__XBRTIME_CONFIG->_BARRIER_FULL[mype + sense*size]);
 		__xbrtime_remote_touch( addr, target, sense+1 );
  	__xbrtime_asm_quiet_fence();
  	/* spinwait on local value */
  	tmp = __sync_fetch_and_add(&__XBRTIME_CONFIG->_BARRIER_FULL[0 + sense*size],0);
  	while( tmp != sense+1 ){
    	tmp = __sync_fetch_and_add(&__XBRTIME_CONFIG->_BARRIER_FULL[0 + sense*size],0);
			//	printf("PE = %d, BARRIER_FULL[%ld] = %ld\n",mype, sense*size, __XBRTIME_CONFIG->_BARRIER_FULL[0 + sense*size]);
  		__xbrtime_remote_touch( addr, target,  sense+1 );
  		__xbrtime_asm_quiet_fence();
  	}
		//reset the local barrier var
		//printf("XBGAS_DEBUG:: PE = %d finishes the second stage of the barrier, __XBRTIME_CONFIG->_BARRIER_FULL[0]= %lu\n",xbrtime_mype(), __XBRTIME_CONFIG->_BARRIER_FULL[0+sense*size]);
		//__XBRTIME_CONFIG->_BARRIER_FULL[0 + sense*size] = 0;
	}
	else{  // PE0
		//printf("XBGAS_DEBUG:: PE = %d starts the barrier, sense = %ld\n",xbrtime_mype(), sense);
  	addr = (uint64_t)(&__XBRTIME_CONFIG->_BARRIER_FULL[0 + sense*size]);
		// spinlock until all the rest PEs touches their barrier
		while(flag){
			flag 	= 0;
			tmp 	= 0;
			for(i = 1; i < xbrtime_num_pes(); i++){
  			tmp = __sync_fetch_and_add(&__XBRTIME_CONFIG->_BARRIER_FULL[i + sense*size],0);
		//		printf("PE = %d, BARRIER_FULL[%ld] = %ld\n",mype, i + sense*size, __XBRTIME_CONFIG->_BARRIER_FULL[i + sense*size]);
				if(tmp != sense + 1)	
					flag = 1;
			}
		}
		flag = 2;
		while(flag){
		for(i = 1; i < xbrtime_num_pes(); i++ ){		
			// rest local barrier var
			target = (uint64_t)(xbrtime_decode_pe((int)(i)));
			//printf("PE = %d, touch target = %ld\n",mype, target);
			__xbrtime_remote_touch( addr, target, sense + 1 );	
  		__xbrtime_asm_quiet_fence();
		}
		flag--;
		}
	//	printf("XBGAS_DEBUG:: PE = %d finishes the second stage of the barrier\n",xbrtime_mype());
	}


  /* switch the sense */
	for(i = 0; i < xbrtime_num_pes()*2; i++ )
			//__XBRTIME_CONFIG->_BARRIER_FULL[i] = 0xdeadbeeful;
  //__XBRTIME_CONFIG->_BARRIER_FULL[0] = 0xdeadbeefull;
  if( sense == 0 ){
    __XBRTIME_CONFIG->_SENSE_FULL = 1;
  }else{
    __XBRTIME_CONFIG->_SENSE_FULL = 0;
  }


#ifdef XBGAS_DEBUG
  printf( "XBGAS_DEBUG : PE=%d; FULL BARRIER COMPLETE\n", xbrtime_mype() );
#endif
}

/* EOF */
