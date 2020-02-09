/*
 * _XBRTIME_GATHER_ALL_C_
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

#define XBGAS_GATHER_ALL(_type, _typename)                                                                                          \
void xbrtime_##_typename##_gather_all_bruck_concat(_type *dest, const _type *src, int *pe_msg_sz, int *pe_disp, size_t nelems)      \
{                                                                                                                                   \
    int i, j, numpes, my_rpe, numpes_log, r_partner, counter, stride, iter_msg_size, temp_rpe;                                      \
    numpes = xbrtime_num_pes();                                                                                                     \
    my_rpe = xbrtime_mype();                                                                                                        \
    numpes_log = (int) ceil((log(numpes)/log(2)));                                                                                  \
    _type *temp = (_type*) xbrtime_malloc(nelems * sizeof(_type));                                                                  \
    int adj_disp[numpes];                                                                                                           \
                                                                                                                                    \
    /* load local gather values to temp */                                                                                          \
    for(i = 0; i < pe_msg_sz[my_rpe]; i++)                                                                                          \
    {                                                                                                                               \
        temp[i] = src[i];                                                                                                           \
    }                                                                                                                               \
                                                                                                                                    \
    stride = 1;                                                                                                                     \
    counter = pe_msg_sz[my_rpe];                                                                                                    \
                                                                                                                                    \
    /* Ensure local values have been loaded to temp */                                                                              \
    xbrtime_barrier();                                                                                                              \
                                                                                                                                    \
    /* Perform get of concatenated segments */                                                                                      \
    for(i = 0; i < numpes_log - 1; i++)                                                                                             \
    {                                                                                                                               \
        r_partner = (my_rpe + stride) % numpes;                                                                                     \
                                                                                                                                    \
        /* Calculate message length for stage i*/                                                                                   \
        iter_msg_size = 0;                                                                                                          \
        for(j = r_partner; j < (r_partner + stride); j++)                                                                           \
        {                                                                                                                           \
            temp_rpe =  j % numpes;                                                                                                 \
            iter_msg_size = iter_msg_size + pe_msg_sz[temp_rpe];                                                                    \
        }                                                                                                                           \
        xbrtime_##_typename##_get(&(temp[counter]), temp, iter_msg_size, 1, r_partner);                                             \
        counter += iter_msg_size;                                                                                                   \
        stride *= 2;                                                                                                                \
        xbrtime_barrier();                                                                                                          \
    }                                                                                                                               \
                                                                                                                                    \
    /* Perform final iteration */                                                                                                   \
    r_partner = (my_rpe + stride) % numpes;                                                                                         \
    xbrtime_##_typename##_get(&(temp[counter]), temp, (nelems-counter), 1, r_partner);                                              \
    xbrtime_barrier();                                                                                                              \
                                                                                                                                    \
    /* Calculate adjusted displacement */                                                                                           \
    counter = 0;                                                                                                                    \
    for(i = my_rpe;  i < my_rpe + numpes; i++)                                                                                      \
    {                                                                                                                               \
        temp_rpe = i % numpes;                                                                                                      \
        adj_disp[temp_rpe] = counter;                                                                                               \
        counter += pe_msg_sz[temp_rpe];                                                                                             \
    }                                                                                                                               \
                                                                                                                                    \
    /* Load to dest offset as given by pe_disp */                                                                                   \
    for(i = 0; i < numpes; i++)                                                                                                     \
    {                                                                                                                               \
        for(j = 0; j < pe_msg_sz[i]; j++)                                                                                           \
        {                                                                                                                           \
            dest[(pe_disp[i])+j] = temp[(adj_disp[i])+j];                                                                           \
        }                                                                                                                           \
    }                                                                                                                               \
    xbrtime_free(temp);                                                                                                             \
}                                                                                                                                   \
                                                                                                                                    \
void xbrtime_##_typename##_gather_all_ring(_type *dest, const _type *src, int *pe_msg_sz, int *pe_disp, size_t nelems)              \
{                                                                                                                                   \
    int i, numpes, my_rpe, src_pe;                                                                                                  \
    numpes = xbrtime_num_pes();                                                                                                     \
    my_rpe = xbrtime_mype();                                                                                                        \
    src_pe = my_rpe;                                                                                                                \
                                                                                                                                    \
    /* Gather local PE values to dest */                                                                                            \
    for(i = 0; i < pe_msg_sz[my_rpe]; i++)                                                                                          \
    {                                                                                                                               \
        dest[(pe_disp[my_rpe])+i] = src[i];                                                                                         \
    }                                                                                                                               \
                                                                                                                                    \
    /* Put PE data to neighbor PE using ring algorithm */                                                                           \
    for(i = 0; i < numpes-1; i++)                                                                                                   \
    {                                                                                                                               \
        xbrtime_##_typename##_put(&(dest[(pe_disp[src_pe])]), &(dest[(pe_disp[src_pe])]), pe_msg_sz[src_pe], 1, (my_rpe+1)%numpes); \
        src_pe = (src_pe == 0 ? numpes-1 : src_pe - 1);                                                                             \
                                                                                                                                    \
        /* Ensure values received for next communication round */                                                                   \
        xbrtime_barrier();                                                                                                          \
    }                                                                                                                               \
}                                                                                                                                   \
                                                                                                                                    \
/* Wrapper function - bruck concatenation for small messages, ring for large messages */                                            \
void xbrtime_##_typename##_gather_all(_type *dest, const _type *src, int *pe_msg_sz, int *pe_disp, size_t nelems)                   \
{                                                                                                                                   \
    if((sizeof(_type)*nelems) < LARGE_GATHER_ALL)                                                                                   \
    {                                                                                                                               \
        xbrtime_##_typename##_gather_all_bruck_concat(dest, src, pe_msg_sz, pe_disp, nelems);                                       \
    }                                                                                                                               \
    else                                                                                                                            \
    {                                                                                                                               \
        xbrtime_##_typename##_gather_all_ring(dest, src, pe_msg_sz, pe_disp, nelems);                                               \
    }                                                                                                                               \
}

    XBGAS_GATHER_ALL(float, float)
    XBGAS_GATHER_ALL(double, double)
    XBGAS_GATHER_ALL(char, char)
    XBGAS_GATHER_ALL(unsigned char, uchar)
    XBGAS_GATHER_ALL(signed char, schar)
    XBGAS_GATHER_ALL(unsigned short, ushort)
    XBGAS_GATHER_ALL(short, short)
    XBGAS_GATHER_ALL(unsigned int, uint)
    XBGAS_GATHER_ALL(int, int)
    XBGAS_GATHER_ALL(unsigned long, ulong)
    XBGAS_GATHER_ALL(long, long)
    XBGAS_GATHER_ALL(unsigned long long, ulonglong)
    XBGAS_GATHER_ALL(long long, longlong)
    XBGAS_GATHER_ALL(uint8_t, uint8)
    XBGAS_GATHER_ALL(int8_t, int8)
    XBGAS_GATHER_ALL(uint16_t, uint16)
    XBGAS_GATHER_ALL(int16_t, int16)
    XBGAS_GATHER_ALL(uint32_t, uint32)
    XBGAS_GATHER_ALL(int32_t, int32)
    XBGAS_GATHER_ALL(uint64_t, uint64)
    XBGAS_GATHER_ALL(int64_t, int64)
    XBGAS_GATHER_ALL(size_t, size)
    XBGAS_GATHER_ALL(ptrdiff_t, ptrdiff)
    //  XBGAS_GATHER_ALL(long double, longdouble)

#undef XBGAS_GATHER_ALL
