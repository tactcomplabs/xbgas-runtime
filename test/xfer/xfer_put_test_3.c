/* _XFER_PUT_TEST_3_C_
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

#include <stdio.h>
#include <inttypes.h>
#include "xbrtime.h"

#define _XBGAS_ALLOC_SIZE_ 8
#define _XBGAS_ALLOC_NELEMS_ 64

int main( int argc, char **argv ){
  int rtn = 0;
  int i   = 0;
  uint64_t *ptr = NULL;
  size_t sz = _XBGAS_ALLOC_SIZE_;
  size_t ne = _XBGAS_ALLOC_NELEMS_;

  printf( "Initializing xBGAS Runtime\n" );
  rtn = xbrtime_init();
  printf( "PE=%d; xBGAS is Initialized\n", xbrtime_mype() );

  printf( "PE=%d; Allocating %d bytes\n", xbrtime_mype(), (int)(sz) * (int)(ne));
  ptr = (uint64_t *)(xbrtime_malloc( sz*ne ));

  printf( "PE=%d; *PTR = 0x%"PRIu64"\n", xbrtime_mype(), (uint64_t)(ptr) );
  for( i=0; i<ne; i++ ){
    ptr[i] = (uint64_t)(xbrtime_mype()+i);
  }

  /* perform a barrier */
  printf( "PE=%d; EXECUTING BARRIER\n", xbrtime_mype() );
  xbrtime_barrier();

  if( xbrtime_mype() == 0 ){
    /* perform an operation */
    printf( "PE=%d; PERFORMING OPERATION\n", xbrtime_mype() );
    xbrtime_ulonglong_put((unsigned long long *)(ptr),
                          (unsigned long long *)(ptr),
                          ne,
                          1,
                          1 );
  }else{
    printf( "PE=%d; DOING NOTHING\n", xbrtime_mype() );
  }

  /* perform a barrier */
  printf( "PE=%d; EXECUTING BARRIER\n", xbrtime_mype() );
  xbrtime_barrier();

  printf( "PE=%d; PTR[0]=0x%"PRIu64"\n",
          xbrtime_mype(), ptr[0]);

  printf( "PE=%d; xBGAS is Closing\n", xbrtime_mype() );
  xbrtime_free( ptr );
  xbrtime_close();
  printf( "xBGAS is Closed\n" );

  return rtn;
}

/* EOF */
