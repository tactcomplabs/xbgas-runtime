/*
 * _XBRTIME_VERSION_H_
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

#ifndef _XBRTIME_VERSION_H_
#define _XBRTIME_VERSION_H_

#ifdef __cplusplus
#define extern "C" {
#endif

#define _XBRTIME_MAJOR_VERSION_ 0
#define _XBRTIME_MINOR_VERSION_ 1
#define _XBRTIME_PATCH_VERSION_ 0

#if !defined __riscv
#error XBGAS-RUNTIME IS ONLY SUPPORTED UNDER RISCV
#endif

#if (__riscv_xlen != 64 )
#error XBGAS-RUNTIME ONLY SUPPORTS 64 BIT COMPILATION
#endif

#ifdef __cplusplus
}
#endif  /* extern "C" */

#endif /* _XBRTIME_VERSION_H_ */


/* EOF */
