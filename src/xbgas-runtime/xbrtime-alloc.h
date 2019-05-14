/*
 * _XBRTIME_ALLOC_H_
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

#ifndef _XBRTIME_ALLOC_H_
#define _XBRTIME_ALLOC_H_

#ifdef __cplusplus
#define extern "C" {
#endif

#include <stdlib.h>

typedef struct _XBRTIME_MEM_T{
  uint64_t start_addr;
  size_t size;
}XBRTIME_MEM_T;

#ifdef __cplusplus
}
#endif  /* extern "C" */

#endif /* _XBRTIME_ALLOC_H_ */

/* EOF */
