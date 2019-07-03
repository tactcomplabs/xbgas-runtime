/* _ALLOC_TEST_KF_1_C_
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
#include "xbrtime.h"

#define _XBGAS_ALLOC_SIZE_ 0

int main( int argc, char **argv ){
  int rtn = 0;
  void *ptr = NULL;
  size_t sz = _XBGAS_ALLOC_SIZE_;

  printf( "Initializing xBGAS Runtime\n" );
  rtn = xbrtime_init();
  printf( "xBGAS is Initialized\n" );

  printf( "Allocating %d bytes\n", (int)(sz) );
  ptr = xbrtime_malloc( sz );
  if( ptr == NULL ){
    printf( "Successfully caught erroneous condition\n" );
    xbrtime_close();
    return 0;
  }else{
    printf( "Erroneously allocated 0 bytes of memory\n" );
    rtn = -1;
  }

  printf( "PTR = %p\n", ptr );

  xbrtime_free( ptr );

  printf( "xBGAS is Closing\n" );
  xbrtime_close();
  printf( "xBGAS is Closed\n" );

  return rtn;
}

/* EOF */
