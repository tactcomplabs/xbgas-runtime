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
//#define INIT_ADDR 0xBB00000000000000ull
//#define END_ADDR 0xAA00000000000000ull

volatile uint64_t *barrier;


/* ------------------------------------------------- FUNCTION PROTOTYPES */
void __xbrtime_ctor_reg_reset();

__attribute__((constructor)) void __xbrtime_ctor(){
  /* initialize the unnecessary registers */
  __xbrtime_ctor_reg_reset();
  barrier = malloc(sizeof(uint64_t)*2*10);	
//	printf("CTOR: Init\n");
	//int init = 0;
//	*((uint64_t *)INIT_ADDR) = init;
	//if(init || *((uint64_t *)INIT_ADDR))
		//init = 0;	

}
__attribute__((destructor)) void __xbrtime_dtor(){
  /* free_barrier */
	//uint64_t end = 0;
	//*((uint64_t *)END_ADDR) = end;
	//if(end || *((uint64_t *)END_ADDR))
		//end = 1;
  free ((void*)barrier); 	
//	printf("DTOR: Free\n");


}
