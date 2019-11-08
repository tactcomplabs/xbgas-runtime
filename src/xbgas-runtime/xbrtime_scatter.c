/*
 * _XBRTIME_SCATTER_C_
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

#define XBGAS_SCATTER(_type, _typename)                                                                                                 \
void xbrtime_##_typename##_scatter_tree(_type *dest, const _type *src, int *pe_msg_sz, int *pe_disp, size_t nelems, int root)           \
{                                                                                                                                       \
    int i, j, counter, numpes, my_rpe, my_vpe, numpes_log, mask, temp_rpe, two_i, r_partner, v_partner, iter_msg_size, r_i;             \
    _type *temp = (_type *) xbrtime_malloc(nelems * sizeof(_type));  /* Buffer space for messages */                                    \
    numpes = xbrtime_num_pes();                                                                                                         \
    my_rpe = xbrtime_mype();                                                                                                            \
    my_vpe = ((my_rpe >= root) ? (my_rpe - root) : (my_rpe + numpes - root));                                                           \
    numpes_log = (int) ceil((log(numpes)/log(2)));  /* Number of commmuication stages */                                                \
    mask = (int) (pow(2,numpes_log) - 1);                                                                                               \
    int adj_disp[numpes];                                                                                                               \
                                                                                                                                        \
    /* Calculate adj_disp by vpe */                                                                                                     \
    counter = 0;                                                                                                                        \
    for(i = 0; i < numpes; i++)                                                                                                         \
    {                                                                                                                                   \
        r_i = (i + root) % numpes;                                                                                                      \
        adj_disp[i] = counter;                                                                                                          \
        counter = counter + pe_msg_sz[r_i];                                                                                             \
    }                                                                                                                                   \
                                                                                                                                        \
    /* Load temp buffer on root by vpe */                                                                                               \
    counter = 0;                                                                                                                        \
    if(my_vpe == 0)                                                                                                                     \
    {                                                                                                                                   \
        for(i = 0; i < numpes; i++)                                                                                                     \
        {                                                                                                                               \
            temp_rpe = (i+root) % numpes;                                                                                               \
            for(j = 0; j < pe_msg_sz[temp_rpe]; j++)                                                                                    \
            {                                                                                                                           \
                temp[counter++] = src[(pe_disp[temp_rpe]+j)];                                                                           \
            }                                                                                                                           \
        }                                                                                                                               \
    }                                                                                                                                   \
                                                                                                                                        \
    /* Ensure all PEs are ready for communication */                                                                                    \
    xbrtime_barrier();                                                                                                                  \
                                                                                                                                        \
    /* Perform communication if PE active at stage i and has valid partner */                                                           \
    for(i = numpes_log-1; i >= 0; i--)                                                                                                  \
    {                                                                                                                                   \
        two_i = (int) pow(2,i);                                                                                                         \
        mask = mask ^ two_i;                                                                                                            \
        if(((my_vpe & mask) == 0) && ((my_vpe & two_i) == 0))                                                                           \
        {                                                                                                                               \
            v_partner = (my_vpe ^ two_i) % numpes;                                                                                      \
            r_partner = (v_partner + root) % numpes;                                                                                    \
            if(my_vpe < v_partner)                                                                                                      \
            {                                                                                                                           \
                /* Calculate message length for stage i*/                                                                               \
                iter_msg_size = 0;                                                                                                      \
                for(j = v_partner; ((j < (v_partner + two_i)) && (j < numpes)); j++)                                                    \
                {                                                                                                                       \
                    temp_rpe = (j+root) % numpes;                                                                                       \
                    iter_msg_size = iter_msg_size + pe_msg_sz[temp_rpe];                                                                \
                }                                                                                                                       \
                xbrtime_##_typename##_put(&temp[(adj_disp[v_partner])], &temp[(adj_disp[v_partner])], iter_msg_size, 1, r_partner);     \
            }                                                                                                                           \
        }                                                                                                                               \
        xbrtime_barrier();                                                                                                              \
   }                                                                                                                                    \
                                                                                                                                        \
   /* Copy data to destination */                                                                                                       \
   for(i = 0; i < pe_msg_sz[my_rpe]; i++)                                                                                               \
   {                                                                                                                                    \
       dest[i] = temp[(adj_disp[my_vpe])+i];                                                                                            \
   }                                                                                                                                    \
   xbrtime_free(temp);                                                                                                                  \
}                                                                                                                                       \
                                                                                                                                        \
/* Wrapper function - only single algorithm used for scatter collective at present */                                                   \
void xbrtime_##_typename##_scatter(_type *dest, const _type *src, int *pe_msg_sz, int *pe_disp, size_t nelems, int root)                \
{                                                                                                                                       \
    xbrtime_##_typename##_scatter_tree(dest, src, pe_msg_sz, pe_disp, nelems, root);                                                    \
}

    XBGAS_SCATTER(float, float)
    XBGAS_SCATTER(double, double)
    XBGAS_SCATTER(char, char)
    XBGAS_SCATTER(unsigned char, uchar)
    XBGAS_SCATTER(signed char, schar)
    XBGAS_SCATTER(unsigned short, ushort)
    XBGAS_SCATTER(short, short)
    XBGAS_SCATTER(unsigned int, uint)
    XBGAS_SCATTER(int, int)
    XBGAS_SCATTER(unsigned long, ulong)
    XBGAS_SCATTER(long, long)
    XBGAS_SCATTER(unsigned long long, ulonglong)
    XBGAS_SCATTER(long long, longlong)
    XBGAS_SCATTER(uint8_t, uint8)
    XBGAS_SCATTER(int8_t, int8)
    XBGAS_SCATTER(uint16_t, uint16)
    XBGAS_SCATTER(int16_t, int16)
    XBGAS_SCATTER(uint32_t, uint32)
    XBGAS_SCATTER(int32_t, int32)
    XBGAS_SCATTER(uint64_t, uint64)
    XBGAS_SCATTER(int64_t, int64)
    XBGAS_SCATTER(size_t, size)
    XBGAS_SCATTER(ptrdiff_t, ptrdiff)
    //  XBGAS_SCATTER(long double, longdouble)

#undef XBGAS_SCATTER
