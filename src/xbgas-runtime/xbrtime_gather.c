/*
 * _XBRTIME_GATHER_C_
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

#define XBGAS_GATHER(_type, _typename)                                                                                                      \
void xbrtime_##_typename##_gather_tree(_type *dest, const _type *src, int *pe_msg_sz, int *pe_disp, size_t nelems, int root)                \
{                                                                                                                                           \
    int i, j, counter, numpes, my_rpe, my_vpe, numpes_log, mask, temp_rpe, two_i, r_partner, v_partner, iter_msg_size, r_i, zero_idx;       \
    _type *temp = (_type*) xbrtime_malloc(nelems * sizeof(_type));   /* Buffer space for messages */                                        \
    numpes = xbrtime_num_pes();                                                                                                             \
    my_rpe = xbrtime_mype();                                                                                                                \
    my_vpe = ((my_rpe >= root) ? (my_rpe - root) : (my_rpe + numpes - root));                                                               \
    numpes_log = (int) ceil((log(numpes)/log(2)));                                                                                          \
    mask = (int) (pow(2,numpes_log) - 1);                                                                                                   \
    int adj_disp[numpes];                                                                                                                   \
                                                                                                                                            \
    /* Calculate adj_disp by vpe */                                                                                                         \
    counter = 0;                                                                                                                            \
    for(i = 0; i < numpes; i++)                                                                                                             \
    {                                                                                                                                       \
        r_i = (i + root) % numpes;                                                                                                          \
        adj_disp[i] = counter;                                                                                                              \
        counter = counter + pe_msg_sz[r_i];                                                                                                 \
    }                                                                                                                                       \
                                                                                                                                            \
    /* Load temp values for each pe by vpe */                                                                                               \
    for(i = 0; i < pe_msg_sz[my_rpe]; i++)                                                                                                  \
    {                                                                                                                                       \
        temp[(adj_disp[my_vpe])+i] = src[i];                                                                                                \
    }                                                                                                                                       \
                                                                                                                                            \
    /* Ensure all PEs are ready for communication */                                                                                        \
    xbrtime_barrier();                                                                                                                      \
                                                                                                                                            \
    /* Perform communication if PE active at stage i and has valid partner */                                                               \
    for(i = 0; i < numpes_log; i++)                                                                                                         \
    {                                                                                                                                       \
        two_i = (int) pow(2,i);                                                                                                             \
        mask = mask ^ two_i;                                                                                                                \
        if(((my_vpe | mask) == mask) && ((my_vpe & two_i) == 0))                                                                            \
        {                                                                                                                                   \
            v_partner = (my_vpe ^ two_i) % numpes;                                                                                          \
            r_partner = (v_partner + root) % numpes;                                                                                        \
            if(my_vpe < v_partner)                                                                                                          \
            {                                                                                                                               \
                /* Calculate message length for stage i */                                                                                  \
                iter_msg_size = 0;                                                                                                          \
                for(j = v_partner; ((j < (v_partner + two_i)) && (j < numpes)); j++)                                                        \
                {                                                                                                                           \
                    temp_rpe = (j+root) % numpes;                                                                                           \
                    iter_msg_size = iter_msg_size + pe_msg_sz[temp_rpe];                                                                    \
                }                                                                                                                           \
                xbrtime_##_typename##_get(&temp[(adj_disp[v_partner])], &temp[(adj_disp[v_partner])], iter_msg_size, 1, r_partner);         \
            }                                                                                                                               \
        }                                                                                                                                   \
        xbrtime_barrier();                                                                                                                  \
   }                                                                                                                                        \
                                                                                                                                            \
   /* Copy data ordered by rpe to destination on root*/                                                                                     \
   if(my_vpe == 0)                                                                                                                          \
   {                                                                                                                                        \
       zero_idx = numpes - root;                                                                                                            \
       for(i = 0; i < nelems; i++)                                                                                                          \
       {                                                                                                                                    \
           dest[i] = temp[((adj_disp[zero_idx])+i)%nelems];                                                                                 \
       }                                                                                                                                    \
   }                                                                                                                                        \
   xbrtime_free(temp);                                                                                                                      \
}                                                                                                                                           \
                                                                                                                                            \
/* Wrapper function - only single algorithm used for gather collective at present */                                                        \
void xbrtime_##_typename##_gather(_type *dest, const _type *src, int *pe_msg_sz, int *pe_disp, size_t nelems, int root)                     \
{                                                                                                                                           \
    xbrtime_##_typename##_gather_tree(dest, src, pe_msg_sz, pe_disp, nelems, root);                                                         \
}

    XBGAS_GATHER(float, float)
    XBGAS_GATHER(double, double)
    XBGAS_GATHER(char, char)
    XBGAS_GATHER(unsigned char, uchar)
    XBGAS_GATHER(signed char, schar)
    XBGAS_GATHER(unsigned short, ushort)
    XBGAS_GATHER(short, short)
    XBGAS_GATHER(unsigned int, uint)
    XBGAS_GATHER(int, int)
    XBGAS_GATHER(unsigned long, ulong)
    XBGAS_GATHER(long, long)
    XBGAS_GATHER(unsigned long long, ulonglong)
    XBGAS_GATHER(long long, longlong)
    XBGAS_GATHER(uint8_t, uint8)
    XBGAS_GATHER(int8_t, int8)
    XBGAS_GATHER(uint16_t, uint16)
    XBGAS_GATHER(int16_t, int16)
    XBGAS_GATHER(uint32_t, uint32)
    XBGAS_GATHER(int32_t, int32)
    XBGAS_GATHER(uint64_t, uint64)
    XBGAS_GATHER(int64_t, int64)
    XBGAS_GATHER(size_t, size)
    XBGAS_GATHER(ptrdiff_t, ptrdiff)
    //  XBGAS_GATHER(long double, longdouble)

#undef XBGAS_GATHER
