/*
 * _XBRTIME_MACROS_H_
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

/*!   \file xbrtime-macros.h
      \brief XBGAS Runtime Macro Header File

      The XBGAS Runtime provides C/CXX level function interfaces
      for applications to conveniently utilize the shared memory
      capabilities present in the xBGAS extension to the RISC-V
      specification
*/

#ifndef _XBRTIME_MACROS_H_
#define _XBRTIME_MACROS_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _XBRTIME_MIN_UNR_THRESHOLD_
/** @brief Minimum transfer unrolling (to hide latency) */
#define _XBRTIME_MIN_UNR_THRESHOLD_ 8
#endif

/** @brief Unrolling factor for unrolled transfer API functons */
#define _XBRTIME_UNROLL_FACTOR_ 4

/** @brief Defines the number of memory allocation slots */
#define _XBRTIME_MEM_SLOTS_ 2048

#ifdef __cplusplus
}
#endif  /* extern "C" */

#endif /* _XBRTIME_VERSION_H_ */


/* EOF */
