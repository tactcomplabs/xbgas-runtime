/*
 * _XBRTIME_H_
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

/*!   \file xbrtime.h
      \brief XBGAS Runtime Top-Level Header File

      The XBGAS Runtime provides C/CXX level function interfaces
      for applications to conveniently utilize the shared memory
      capabilities present in the xBGAS extension to the RISC-V
      specification
*/

#ifndef _XBRTIME_H_
#define _XBRTIME_H_

#ifdef __cplusplus
#define extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* ---------------------------------------- REQUIRED HEADERS */
#include "xbrtime-types.h"
#include "xbrtime-api.h"
#include "xbrtime-alloc.h"
#include "xbrtime-version.h"
#include "xbrtime-macros.h"
#include "xbrtime-collectives.h"
#include "xbrtime-atomics.h"

/* ---------------------------------------- FUNCTION PROTOTYPES */

/*!   \fn int xbrtime_init()
      \brief Initializes the XBGAS Runtime environment
      \return 0 on success, nonzero otherwise
*/
extern int xbrtime_init();

/*!   \fn void xbrtime_close()
      \brief Closes the XBGAS Runtime environment
      \return void
*/
extern void xbrtime_close();

/*!   \fn int xbrtime_addr_accessible( const void *addr, int pe )
      \brief Checks to see whether the address on the target pe can be reached
      \param addr is a pointer to a valid address
      \param pe is the target processing element
      \return 1 on success, 0 otherwise
*/
extern int xbrtime_addr_accessible( const void *addr, int pe );

/*!   \fn void *xbrtime_malloc( size_t sz )
      \brief Allocates a block of contiguous shared memory of minimum size, 'sz'
      \param sz is the minimum size of the allocated block
      \return Valid pointer on success, NULL otherwise
*/
extern void *xbrtime_malloc( size_t sz );

/*!   \fn void xbrtime_free( void *ptr )
      \brief Free's a target memory block starting at ptr
      \param *ptr is a valid base pointer to an allocated block
      \return Void
*/
extern void xbrtime_free( void *ptr );

/*!   \fn int xbrtime_mype()
      \brief Returns the logical PE number of the calling entity
      \return Logical PE on success, nonzero otherwise
*/
extern int xbrtime_mype();


/*!   \fn int xbrtime_num_pes()
      \brief Returns the total number of configured PEs
      \return Total PEs on success, nonzero otherwise
*/
extern int xbrtime_num_pes();

/*!   \fn void xbrtime_barrier()
      \brief Performs a global barrier operation of all configured PEs
      \return Void
*/
extern void xbrtime_barrier();



#ifdef __cplusplus
}
#endif  /* extern "C" */

#endif /* _XBRTIME_H_ */

/* EOF */
