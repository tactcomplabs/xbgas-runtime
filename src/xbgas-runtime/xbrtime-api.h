/*
 * _XBRTIME_API_H_
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

/*!   \file xbrtime-api.h
      \brief XBGAS Runtime Data Transfer API Header File

      The XBGAS Runtime provides C/CXX level function interfaces
      for applications to conveniently utilize the shared memory
      capabilities present in the xBGAS extension to the RISC-V
      specification
*/

#ifndef _XBRTIME_API_H_
#define _XBRTIME_API_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdint.h>

/**
 * xbrtime_TYPE_MEMOP(TYPE *dest, TYPE *src, size_t nelems, int stride, int pe)
 *
 */

#define XBGAS_API_DECL_PUTGET(_memop, _opname, _type)       \
  /**                                                       \
   * @see xbrtime_TYPE_MEMOP                                \
   */                                                       \
  void xbrtime_##_opname##_##_memop(_type *dest,            \
                                  const _type *src,         \
                                  size_t nelems,            \
                                  int stride,               \
                                  int pe);                  \
                                                            \
  /**                                                       \
   * @see xbrtime_TYPE_MEMOP                                \
   */                                                       \
  void xbrtime_##_opname##_##_memop##_nb(_type *dest,       \
                                      const _type *src,     \
                                      size_t nelems,        \
                                      int stride,           \
                                      int pe);

  XBGAS_API_DECL_PUTGET(put, float, float)
  XBGAS_API_DECL_PUTGET(put, double, double)
  XBGAS_API_DECL_PUTGET(put, longdouble, long double)
  XBGAS_API_DECL_PUTGET(put, schar, signed char)
  XBGAS_API_DECL_PUTGET(put, char, char)
  XBGAS_API_DECL_PUTGET(put, short, short)
  XBGAS_API_DECL_PUTGET(put, int, int)
  XBGAS_API_DECL_PUTGET(put, long, long)
  XBGAS_API_DECL_PUTGET(put, longlong, long long)
  XBGAS_API_DECL_PUTGET(put, uchar, unsigned char)
  XBGAS_API_DECL_PUTGET(put, ushort, unsigned short)
  XBGAS_API_DECL_PUTGET(put, uint, unsigned int)
  XBGAS_API_DECL_PUTGET(put, ulong, unsigned long)
  XBGAS_API_DECL_PUTGET(put, ulonglong, unsigned long long)
  XBGAS_API_DECL_PUTGET(put, int8, int8_t)
  XBGAS_API_DECL_PUTGET(put, int16, int16_t)
  XBGAS_API_DECL_PUTGET(put, int32, int32_t)
  XBGAS_API_DECL_PUTGET(put, int64, int64_t)
  XBGAS_API_DECL_PUTGET(put, uint8, uint8_t)
  XBGAS_API_DECL_PUTGET(put, uint16, uint16_t)
  XBGAS_API_DECL_PUTGET(put, uint32, uint32_t)
  XBGAS_API_DECL_PUTGET(put, uint64, uint64_t)
  XBGAS_API_DECL_PUTGET(put, size, size_t)
  XBGAS_API_DECL_PUTGET(put, ptrdiff, ptrdiff_t)
  XBGAS_API_DECL_PUTGET(get, float, float)
  XBGAS_API_DECL_PUTGET(get, double, double)
  XBGAS_API_DECL_PUTGET(get, longdouble, long double)
  XBGAS_API_DECL_PUTGET(get, schar, signed char)
  XBGAS_API_DECL_PUTGET(get, char, char)
  XBGAS_API_DECL_PUTGET(get, short, short)
  XBGAS_API_DECL_PUTGET(get, int, int)
  XBGAS_API_DECL_PUTGET(get, long, long)
  XBGAS_API_DECL_PUTGET(get, longlong, long long)
  XBGAS_API_DECL_PUTGET(get, uchar, unsigned char)
  XBGAS_API_DECL_PUTGET(get, ushort, unsigned short)
  XBGAS_API_DECL_PUTGET(get, uint, unsigned int)
  XBGAS_API_DECL_PUTGET(get, ulong, unsigned long)
  XBGAS_API_DECL_PUTGET(get, ulonglong, unsigned long long)
  XBGAS_API_DECL_PUTGET(get, int8, int8_t)
  XBGAS_API_DECL_PUTGET(get, int16, int16_t)
  XBGAS_API_DECL_PUTGET(get, int32, int32_t)
  XBGAS_API_DECL_PUTGET(get, int64, int64_t)
  XBGAS_API_DECL_PUTGET(get, uint8, uint8_t)
  XBGAS_API_DECL_PUTGET(get, uint16, uint16_t)
  XBGAS_API_DECL_PUTGET(get, uint32, uint32_t)
  XBGAS_API_DECL_PUTGET(get, uint64, uint64_t)
  XBGAS_API_DECL_PUTGET(get, size, size_t)
  XBGAS_API_DECL_PUTGET(get, ptrdiff, ptrdiff_t)
#undef XBGAS_API_DECL_PUTGET

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* _XBRTIME_TYPES_H_ */

/* EOF */
