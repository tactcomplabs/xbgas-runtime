/* _INIT_TEST_5_C_
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

int main( int argc, char **argv ){
  int rtn = 0;

  printf( "Querying mype prior to initializaton\n" );
  if( xbrtime_mype() != -1 ){
    printf( "failed to catch error with xbrtime_mype() prior to init\n" );
    return -1;
  }
  printf( "Success; caught the error\n" );

  printf( "Querying num_pes prior to initializaton\n" );
  if( xbrtime_num_pes() != -1 ){
    printf( "failed to catch error with xbrtime_num_pes() prior to init\n" );
    return -1;
  }
  printf( "Success; caught the error\n" );

  return rtn;
}

/* EOF */
