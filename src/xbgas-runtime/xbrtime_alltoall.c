/*
 * _XBRTIME_ALLTOALL_C_
 *
 * Copyright (C) 2017-2019  Tactical Computing Laboratories, LLC
 * All Rights Reserved
 * contact@tactcomplabs.com
 *
 * This file is a part of the XBGAS-RUNTIME package.  For license
 * information, see the LICENSE file in the top level directory
 * of the distribution.
 *
 */

#include "xbrtime.h"

/* A very simple and naive implementation until a better algorithm is found */
#define XBGAS_ALLTOALL(_type, _typename)                                                                                               \
void xbrtime_##_typename##_alltoall_shift_exchange(_type *dest, const _type *src, size_t nelems, int stride)
{

}

void xbrtime_##_typename##_alltoall(_type *dest, const _type *src, size_t nelems, int stride)
{

}

    XBGAS_ALLTOALL(float, float)
    XBGAS_ALLTOALL(double, double)
    XBGAS_ALLTOALL(char, char)
    XBGAS_ALLTOALL(unsigned char, uchar)
    XBGAS_ALLTOALL(signed char, schar)
    XBGAS_ALLTOALL(unsigned short, ushort)
    XBGAS_ALLTOALL(short, short)
    XBGAS_ALLTOALL(unsigned int, uint)
    XBGAS_ALLTOALL(int, int)
    XBGAS_ALLTOALL(unsigned long, ulong)
    XBGAS_ALLTOALL(long, long)
    XBGAS_ALLTOALL(unsigned long long, ulonglong)
    XBGAS_ALLTOALL(long long, longlong)
    XBGAS_ALLTOALL(uint8_t, uint8)
    XBGAS_ALLTOALL(int8_t, int8)
    XBGAS_ALLTOALL(uint16_t, uint16)
    XBGAS_ALLTOALL(int16_t, int16)
    XBGAS_ALLTOALL(uint32_t, uint32)
    XBGAS_ALLTOALL(int32_t, int32)
    XBGAS_ALLTOALL(uint64_t, uint64)
    XBGAS_ALLTOALL(int64_t, int64)
    XBGAS_ALLTOALL(size_t, size)
    XBGAS_ALLTOALL(ptrdiff_t, ptrdiff)
    //  XBGAS_ALLTOALL(long double, longdouble)

#undef XBGAS_ALLTOALL
