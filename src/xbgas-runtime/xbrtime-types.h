/*
 * _XBRTIME_TYPES_H_
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

#ifndef _XBRTIME_TYPES_H_
#define _XBRTIME_TYPES_H_

#ifdef __cplusplus
#define extern "C" {
#endif

#include <stdint.h>

#define __XBRTIME_MAX_PE 2147483647

/*! \struct XBRTIME_PE_MAP
 *  \brief Defines the internal PE mapping
 *
 * Defines the internal logical to physical PE mapping
 *
 */
typedef struct{
  int _LOGICAL;           /*! XBRTIME_PE_MAP: Logical node ID */
  int _PHYSICAL;          /*! XBRTIME_PE_MAP: Physical node ID */
}XBRTIME_PE_MAP;

/*! \struct XBRTIME_DATA
 *  \brief Defines the internal xbrtime configuration data
 *
 * Defines the internal xbrtime configuration data that includes
 * the respective paramters of the parallel environment and the
 * contiguous memory regions
 *
 */
typedef struct{
  size_t    _MEMSIZE;     /*! XBRTIME_DATA: Size of the shared memory region (in bytes) */
  int       _ID;          /*! XBRTIME_DATA: Local node ID */
  int       _NPES;        /*! XBRTIME_DATA: Number of parallel elements */
  uint64_t  _START_ADDR;  /*! XBRTIME_DATA: Starting address of the shared memory region */
  XBRTIME_PE_MAP _MAP[__XBRTIME_MAX_PE]; /*! XBRTIME_DATA: PE Mappings */
}XBRTIME_DATA;

extern XBRTIME_DATA *__XBRTIME_CONFIG;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* _XBRTIME_TYPES_H_ */

/* EOF */
