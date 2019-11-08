/*
 * _XBRTIME_REDUCE_C_
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

/* For use with min/max reduction */
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

#define XBGAS_REDUCE(_type, _typename, _funcname, _op)                                                                                                  \
void xbrtime_##_typename##_reduce_##_funcname##_tree(_type *dest, const _type *src, size_t nelems, int stride, int root)                                \
{                                                                                                                                                       \
    int i, j, numpes, my_rpe, my_vpe, numpes_log, mask, two_i, r_partner, v_partner;                                                                    \
    stride = ((stride == 0) ? 1 : stride);   /* Avoid memory allocation problem */                                                                      \
    _type *temp = (_type*) malloc(nelems * (sizeof(_type) * stride));                                                                                   \
    _type *accumulate = (_type*) xbrtime_malloc(nelems * (sizeof(_type) * stride));                                                                     \
    numpes = xbrtime_num_pes();                                                                                                                         \
    my_rpe = xbrtime_mype();                                                                                                                            \
    my_vpe = ((my_rpe >= root) ? (my_rpe - root) : (my_rpe + numpes - root));                                                                           \
    numpes_log = (int) ceil((log(numpes)/log(2)));  /* Number of commmuication stages */                                                                \
    mask = (int) (pow(2,numpes_log) - 1);                                                                                                               \
                                                                                                                                                        \
    /* Load accumulate buffer on each PE */                                                                                                             \
    for(i = 0; i < nelems; i++)                                                                                                                         \
    {                                                                                                                                                   \
        accumulate[i*stride] = src[i*stride];                                                                                                           \
    }                                                                                                                                                   \
                                                                                                                                                        \
    /* Ensure accumulate buffer is ready */                                                                                                             \
    xbrtime_barrier();                                                                                                                                  \
                                                                                                                                                        \
    /* Perform communication if PE active at stage i and has valid partner */                                                                           \
    for(i = 0; i < numpes_log; i++)                                                                                                                     \
    {                                                                                                                                                   \
        two_i = (int) pow(2,i);                                                                                                                         \
        mask = mask ^ two_i;                                                                                                                            \
        if(((my_vpe | mask) == mask) && ((my_vpe & two_i) == 0))                                                                                        \
        {                                                                                                                                               \
            v_partner = (my_vpe ^ two_i) % numpes;                                                                                                      \
            r_partner = (v_partner + root) % numpes;                                                                                                    \
            if(my_vpe < v_partner)                                                                                                                      \
            {                                                                                                                                           \
                xbrtime_##_typename##_get(temp, accumulate, nelems, stride, r_partner);                                                                 \
                for(j = 0; j < nelems; j++)                                                                                                             \
                {                                                                                                                                       \
                    accumulate[j*stride] = (_type) accumulate[j*stride] _op temp[j*stride];                                                             \
                }                                                                                                                                       \
            }                                                                                                                                           \
        }                                                                                                                                               \
        xbrtime_barrier();                                                                                                                              \
    }                                                                                                                                                   \
                                                                                                                                                        \
    /* Copy data to destination on root*/                                                                                                               \
    if(my_vpe == 0)                                                                                                                                     \
    {                                                                                                                                                   \
        for(i = 0; i < nelems; i++)                                                                                                                     \
        {                                                                                                                                               \
            dest[i*stride] = accumulate[i*stride];                                                                                                      \
        }                                                                                                                                               \
    }                                                                                                                                                   \
    xbrtime_free(accumulate);                                                                                                                           \
    free(temp);                                                                                                                                         \
}                                                                                                                                                       \
                                                                                                                                                        \
void xbrtime_##_typename##_reduce_##_funcname##_rabenseifner(_type *dest, const _type *src, size_t nelems, int stride, int root)                        \
{                                                                                                                                                       \
    int i, j, numpes, my_rpe, my_lpe, my_vpe, r_partner, l_partner, numpes_log_floor, p_prime, remainder, counter;                                      \
    numpes = xbrtime_num_pes();                                                                                                                         \
    my_rpe = xbrtime_mype();                                                                                                                            \
    my_lpe = ((my_rpe >= root) ? (my_rpe - root) : (my_rpe + numpes - root)); /* Logical PE abstraction - ensure root PE is not a removed PE */         \
    my_vpe = my_lpe;                                                          /* Root PE always lpe 0 */                                                \
    numpes_log_floor = (int) (log(numpes)/log(2));                                                                                                      \
    p_prime = 1 << numpes_log_floor;                                                                                                                    \
    remainder = numpes - p_prime;                                                                                                                       \
    _type *accumulate = (_type*) xbrtime_malloc(sizeof(_type) * nelems);                                                                                \
    _type *temp = (_type*) xbrtime_malloc(sizeof(_type) * nelems);                                                                                      \
                                                                                                                                                        \
    /* Load reduction values into accumulate buffer and remove stride */                                                                                \
    for(i = 0; i < nelems; i++)                                                                                                                         \
    {                                                                                                                                                   \
        accumulate[i] = src[i*stride];                                                                                                                  \
    }                                                                                                                                                   \
                                                                                                                                                        \
    /* Divide buffers into p_prime partitions */                                                                                                        \
    counter = 0;                                                                                                                                        \
    int partition_sizes[p_prime], partition_disp[p_prime];                                                                                              \
    for(i = 0; i < p_prime; i++)                                                                                                                        \
    {                                                                                                                                                   \
        partition_sizes[i] = ( (i == p_prime-1) ?                                                                                                       \
                             (((int)(nelems/p_prime)) + (nelems%p_prime)) :                                                                             \
                             ((int)(nelems/p_prime)) );                                                                                                 \
        partition_disp[i] = counter;                                                                                                                    \
        counter += partition_sizes[i];                                                                                                                  \
    }                                                                                                                                                   \
                                                                                                                                                        \
    /* Ensure buffer is ready */                                                                                                                        \
    xbrtime_barrier();                                                                                                                                  \
                                                                                                                                                        \
    int num_exchange = p_prime/2;                                                                                                                       \
    int msg_size = 0;                                                                                                                                   \
                                                                                                                                                        \
    /* Stage 1 - ReduceScatter (only if NumPEs is not a power of two) */                                                                                \
    if(numpes_log_floor != (log(numpes)/log(2)))                                                                                                        \
    {                                                                                                                                                   \
        /* First 2r lpe ranks */                                                                                                                        \
        if(my_lpe < 2*remainder)                                                                                                                        \
        {                                                                                                                                               \
            /* Even ranks */                                                                                                                            \
            if(my_lpe % 2 == 0)                                                                                                                         \
            {                                                                                                                                           \
                /* Calculate and get first half of values from my_lpe + 1 */                                                                            \
                l_partner = my_lpe+1;                                                                                                                   \
                r_partner = ((l_partner+root) % numpes);                                                                                                \
                for(j = 0; j < num_exchange; j++)                                                                                                       \
                {                                                                                                                                       \
                    msg_size += partition_sizes[j];                                                                                                     \
                }                                                                                                                                       \
                xbrtime_##_typename##_get(temp, accumulate, msg_size, 1, r_partner);                                                                    \
                                                                                                                                                        \
                /* Perform reduction op */                                                                                                              \
                for(j = 0; j < msg_size; j++)                                                                                                           \
                {                                                                                                                                       \
                    accumulate[j] = accumulate[j] _op temp[j];                                                                                          \
                }                                                                                                                                       \
                                                                                                                                                        \
                /* Assign new vpe ranks */                                                                                                              \
                my_vpe = my_lpe/2;                                                                                                                      \
            }                                                                                                                                           \
            /* Odd ranks */                                                                                                                             \
            else                                                                                                                                        \
            {                                                                                                                                           \
                /* Calculate and get second half of values from my_lpe - 1 */                                                                           \
                l_partner = my_lpe-1;                                                                                                                   \
                r_partner = ((l_partner+root) % numpes);                                                                                                \
                for(j = num_exchange; j < p_prime; j++)                                                                                                 \
                {                                                                                                                                       \
                    msg_size += partition_sizes[j];                                                                                                     \
                }                                                                                                                                       \
                                                                                                                                                        \
                xbrtime_##_typename##_get(&(temp[(partition_disp[num_exchange])]), &(accumulate[(partition_disp[num_exchange])]),                       \
                                            msg_size, 1, r_partner);                                                                                    \
                                                                                                                                                        \
                /* Perform reduction op */                                                                                                              \
                for(j = 0; j < msg_size; j++)                                                                                                           \
                {                                                                                                                                       \
                    accumulate[(partition_disp[num_exchange])+j] = accumulate[(partition_disp[num_exchange])+j]                                         \
                                                                    _op temp[(partition_disp[num_exchange])+j];                                         \
                }                                                                                                                                       \
                                                                                                                                                        \
                /* Put calculated second half values back to even partner */                                                                            \
                xbrtime_##_typename##_put(&(accumulate[(partition_disp[num_exchange])]), &(accumulate[(partition_disp[num_exchange])]),                 \
                                            msg_size, 1, r_partner);                                                                                    \
                                                                                                                                                        \
                /* Assign new vpe ranks */                                                                                                              \
                my_vpe = -1;                                                                                                                            \
            }                                                                                                                                           \
        }                                                                                                                                               \
        else                                                                                                                                            \
        {                                                                                                                                               \
            /* Assign new vpe ranks */                                                                                                                  \
            my_vpe = my_lpe - remainder;                                                                                                                \
        }                                                                                                                                               \
        xbrtime_barrier();                                                                                                                              \
    }                                                                                                                                                   \
                                                                                                                                                        \
    /* Stage 2 - ReduceScatter Recursive Doubling/Halving */                                                                                            \
    int pe_stride = 1;                                                                                                                                  \
    int offset = 0;                                                                                                                                     \
    for(i = 0; i < numpes_log_floor; i++)                                                                                                               \
    {                                                                                                                                                   \
        msg_size = 0;                                                                                                                                   \
        if(my_vpe != -1)                                                                                                                                \
        {                                                                                                                                               \
            /* PEs perform get and reduction of first buffer half */                                                                                    \
            if((my_vpe & ( 1 << i)) == 0)                                                                                                               \
            {                                                                                                                                           \
                l_partner = ((my_vpe+pe_stride) < remainder ? (my_vpe+pe_stride)*2 : (my_vpe+pe_stride)+remainder);                                     \
                r_partner = ((l_partner+root) % numpes);                                                                                           	    \
                                                                                                                                                        \
                /* Calculate msg_size */                                                                                                                \
                for(j = 0; j < num_exchange; j++)                                                                                                       \
                {                                                                                                                                       \
                    msg_size += partition_sizes[offset+j];                                                                                              \
                }                                                                                                                                       \
                                                                                                                                                        \
                xbrtime_##_typename##_get(&(temp[(partition_disp[offset])]), &(accumulate[(partition_disp[offset])]), msg_size, 1, r_partner);          \
                                                                                                                                                        \
                /* Perform reduction op */                                                                                                              \
                for(j = 0; j < msg_size; j++)                                                                                                           \
                {                                                                                                                                       \
                    accumulate[(partition_disp[offset]+j)] = accumulate[(partition_disp[offset])+j] _op temp[(partition_disp[offset])+j];               \
                }                                                                                                                                       \
            }                                                                                                                                           \
            /* PEs perform get and reduction of second buffer half */                                                                                   \
            else                                                                                                                                        \
            {                                                                                                                                           \
                l_partner = (((my_vpe-pe_stride+p_prime)%p_prime) < remainder ? ((my_vpe-pe_stride+p_prime)%p_prime)*2 :                                \
                            ((my_vpe-pe_stride+p_prime)%p_prime)+remainder);                                                                            \
                r_partner = ((l_partner+root) % numpes);                                                                                                \
                                                                                                                                                        \
                /* Calculate msg_size */                                                                                                                \
                for(j = 0; j < num_exchange; j++)                                                                                                       \
                {                                                                                                                                       \
                    msg_size += partition_sizes[offset+num_exchange+j];                                                                                 \
                }                                                                                                                                       \
                                                                                                                                                        \
                xbrtime_##_typename##_get(&(temp[(partition_disp[offset+num_exchange])]), &(accumulate[(partition_disp[offset+num_exchange])]),         \
                                            msg_size, 1, r_partner);                                                                                    \
                                                                                                                                                        \
                /* Perform reduction op */                                                                                                              \
                for(j = 0; j < msg_size; j++)                                                                                                           \
                {                                                                                                                                       \
                    accumulate[(partition_disp[offset+num_exchange])+j] = accumulate[(partition_disp[offset+num_exchange])+j]                           \
                                                                            _op temp[(partition_disp[offset+num_exchange])+j];                          \
                }                                                                                                                                       \
                                                                                                                                                        \
                /* Increase offset for these PEs*/                                                                                                      \
                offset += num_exchange;                                                                                                                 \
            }                                                                                                                                           \
        }                                                                                                                                               \
        num_exchange >>= 1;                                                                                                                             \
        pe_stride <<= 1;                                                                                                                                \
        xbrtime_barrier();                                                                                                                              \
    }                                                                                                                                                   \
                                                                                                                                                        \
    /* Stage 3 - Gather to root PE */                                                                                                                   \
    pe_stride = (1 << (numpes_log_floor-1));                                                                                                            \
    num_exchange = 1;                                                                                                                                   \
    int active_pes = p_prime;                                                                                                                           \
    for(i = numpes_log_floor - 1; i >= 0; i--)                                                                                                          \
    {                                                                                                                                                   \
        msg_size = 0;                                                                                                                                   \
        if(my_vpe != -1)                                                                                                                                \
        {                                                                                                                                               \
            /* PEs perform put */                                                                                                                       \
            if(((my_vpe & ( 1 << i)) == (1 << i)) && (my_vpe < active_pes))                                                                             \
            {                                                                                                                                           \
                l_partner = (((my_vpe-pe_stride+p_prime)%p_prime) < remainder ? ((my_vpe-pe_stride+p_prime)%p_prime)*2 :                                \
                            ((my_vpe-pe_stride+p_prime)%p_prime)+remainder);                                                                            \
                r_partner = ((l_partner+root) % numpes);                                                                                                \
                                                                                                                                                        \
                /* Calculate msg_size */                                                                                                                \
                for(j = 0; j < num_exchange; j++)                                                                                                       \
                {                                                                                                                                       \
                    msg_size += partition_sizes[offset+j];                                                                                              \
                }                                                                                                                                       \
                xbrtime_##_typename##_put(&(accumulate[(partition_disp[offset])]), &(accumulate[(partition_disp[offset])]), msg_size, 1, r_partner);    \
            }                                                                                                                                           \
        }                                                                                                                                               \
        num_exchange <<= 1;                                                                                                                             \
        pe_stride >>= 1;                                                                                                                                \
        active_pes >>= 1;                                                                                                                               \
        xbrtime_barrier();                                                                                                                              \
    }                                                                                                                                                   \
                                                                                                                                                        \
    /* Copy from buffer to dest with stride on root */                                                                                                  \
    if(my_lpe == 0)                                                                                                                                     \
    {                                                                                                                                                   \
        for(i = 0; i < nelems; i++)                                                                                                                     \
        {                                                                                                                                               \
            dest[i*stride] = accumulate[i];                                                                                                             \
        }                                                                                                                                               \
    }                                                                                                                                                   \
                                                                                                                                                        \
    xbrtime_free(accumulate);                                                                                                                           \
    xbrtime_free(temp);                                                                                                                                 \
}                                                                                                                                                       \
                                                                                                                                                        \
/* Wrapper function - binomial tree for small messages, rabenseifner for large messages */                                                              \
void xbrtime_##_typename##_reduce_##_funcname(_type *dest, const _type *src, size_t nelems, int stride, int root)                                       \
{                                                                                                                                                       \
    if((sizeof(_type)*nelems) < LARGE_REDUCE)                                                                                                           \
    {                                                                                                                                                   \
        xbrtime_##_typename##_reduce_##_funcname##_tree(dest, src, nelems, stride, root);                                                               \
    }                                                                                                                                                   \
    else                                                                                                                                                \
    {                                                                                                                                                   \
        xbrtime_##_typename##_reduce_##_funcname##_rabenseifner(dest, src, nelems, stride, root);                                                       \
    }                                                                                                                                                   \
}

    /* Sum */
    XBGAS_REDUCE(float, float, sum, +)
    XBGAS_REDUCE(double, double, sum, +)
    XBGAS_REDUCE(char, char, sum, +)
    XBGAS_REDUCE(unsigned char, uchar, sum, +)
    XBGAS_REDUCE(signed char, schar, sum, +)
    XBGAS_REDUCE(unsigned short, ushort, sum, +)
    XBGAS_REDUCE(short, short, sum, +)
    XBGAS_REDUCE(unsigned int, uint, sum, +)
    XBGAS_REDUCE(int, int, sum, +)
    XBGAS_REDUCE(unsigned long, ulong, sum, +)
    XBGAS_REDUCE(long, long, sum, +)
    XBGAS_REDUCE(unsigned long long, ulonglong, sum, +)
    XBGAS_REDUCE(long long, longlong, sum, +)
    XBGAS_REDUCE(uint8_t, uint8, sum, +)
    XBGAS_REDUCE(int8_t, int8, sum, +)
    XBGAS_REDUCE(uint16_t, uint16, sum, +)
    XBGAS_REDUCE(int16_t, int16, sum, +)
    XBGAS_REDUCE(uint32_t, uint32, sum, +)
    XBGAS_REDUCE(int32_t, int32, sum, +)
    XBGAS_REDUCE(uint64_t, uint64, sum, +)
    XBGAS_REDUCE(int64_t, int64, sum, +)
    XBGAS_REDUCE(size_t, size, sum, +)
    XBGAS_REDUCE(ptrdiff_t, ptrdiff, sum, +)
    //  XBGAS_REDUCE(long double, longdouble, sum, +)

    /* Product */
    XBGAS_REDUCE(float, float, product, *)
    XBGAS_REDUCE(double, double, product, *)
    XBGAS_REDUCE(char, char, product, *)
    XBGAS_REDUCE(unsigned char, uchar, product, *)
    XBGAS_REDUCE(signed char, schar, product, *)
    XBGAS_REDUCE(unsigned short, ushort, product, *)
    XBGAS_REDUCE(short, short, product, *)
    XBGAS_REDUCE(unsigned int, uint, product, *)
    XBGAS_REDUCE(int, int, product, *)
    XBGAS_REDUCE(unsigned long, ulong, product, *)
    XBGAS_REDUCE(long, long, product, *)
    XBGAS_REDUCE(unsigned long long, ulonglong, product, *)
    XBGAS_REDUCE(long long, longlong, product, *)
    XBGAS_REDUCE(uint8_t, uint8, product, *)
    XBGAS_REDUCE(int8_t, int8, product, *)
    XBGAS_REDUCE(uint16_t, uint16, product, *)
    XBGAS_REDUCE(int16_t, int16, product, *)
    XBGAS_REDUCE(uint32_t, uint32, product, *)
    XBGAS_REDUCE(int32_t, int32, product, *)
    XBGAS_REDUCE(uint64_t, uint64, product, *)
    XBGAS_REDUCE(int64_t, int64, product, *)
    XBGAS_REDUCE(size_t, size, product, *)
    XBGAS_REDUCE(ptrdiff_t, ptrdiff, product, *)
    //  XBGAS_REDUCE(long double, longdouble, product, *)

    /* Binary AND */
    XBGAS_REDUCE(char, char, and, &)
    XBGAS_REDUCE(unsigned char, uchar, and, &)
    XBGAS_REDUCE(signed char, schar, and, &)
    XBGAS_REDUCE(unsigned short, ushort, and, &)
    XBGAS_REDUCE(short, short, and, &)
    XBGAS_REDUCE(unsigned int, uint, and, &)
    XBGAS_REDUCE(int, int, and, &)
    XBGAS_REDUCE(unsigned long, ulong, and, &)
    XBGAS_REDUCE(long, long, and, &)
    XBGAS_REDUCE(unsigned long long, ulonglong, and, &)
    XBGAS_REDUCE(long long, longlong, and, &)
    XBGAS_REDUCE(uint8_t, uint8, and, &)
    XBGAS_REDUCE(int8_t, int8, and, &)
    XBGAS_REDUCE(uint16_t, uint16, and, &)
    XBGAS_REDUCE(int16_t, int16, and, &)
    XBGAS_REDUCE(uint32_t, uint32, and, &)
    XBGAS_REDUCE(int32_t, int32, and, &)
    XBGAS_REDUCE(uint64_t, uint64, and, &)
    XBGAS_REDUCE(int64_t, int64, and, &)
    XBGAS_REDUCE(size_t, size, and, &)
    XBGAS_REDUCE(ptrdiff_t, ptrdiff, and, &)

    /* Binary OR */
    XBGAS_REDUCE(char, char, or, |)
    XBGAS_REDUCE(unsigned char, uchar, or, |)
    XBGAS_REDUCE(signed char, schar, or, |)
    XBGAS_REDUCE(unsigned short, ushort, or, |)
    XBGAS_REDUCE(short, short, or, |)
    XBGAS_REDUCE(unsigned int, uint, or, |)
    XBGAS_REDUCE(int, int, or, |)
    XBGAS_REDUCE(unsigned long, ulong, or, |)
    XBGAS_REDUCE(long, long, or, |)
    XBGAS_REDUCE(unsigned long long, ulonglong, or, |)
    XBGAS_REDUCE(long long, longlong, or, |)
    XBGAS_REDUCE(uint8_t, uint8, or, |)
    XBGAS_REDUCE(int8_t, int8, or, |)
    XBGAS_REDUCE(uint16_t, uint16, or, |)
    XBGAS_REDUCE(int16_t, int16, or, |)
    XBGAS_REDUCE(uint32_t, uint32, or, |)
    XBGAS_REDUCE(int32_t, int32, or, |)
    XBGAS_REDUCE(uint64_t, uint64, or, |)
    XBGAS_REDUCE(int64_t, int64, or, |)
    XBGAS_REDUCE(size_t, size, or, |)
    XBGAS_REDUCE(ptrdiff_t, ptrdiff, or, |)

    /* Binary XOR */
    XBGAS_REDUCE(char, char, xor, ^)
    XBGAS_REDUCE(unsigned char, uchar, xor, ^)
    XBGAS_REDUCE(signed char, schar, xor, ^)
    XBGAS_REDUCE(unsigned short, ushort, xor, ^)
    XBGAS_REDUCE(short, short, xor, ^)
    XBGAS_REDUCE(unsigned int, uint, xor, ^)
    XBGAS_REDUCE(int, int, xor, ^)
    XBGAS_REDUCE(unsigned long, ulong, xor, ^)
    XBGAS_REDUCE(long, long, xor, ^)
    XBGAS_REDUCE(unsigned long long, ulonglong, xor, ^)
    XBGAS_REDUCE(long long, longlong, xor, ^)
    XBGAS_REDUCE(uint8_t, uint8, xor, ^)
    XBGAS_REDUCE(int8_t, int8, xor, ^)
    XBGAS_REDUCE(uint16_t, uint16, xor, ^)
    XBGAS_REDUCE(int16_t, int16, xor, ^)
    XBGAS_REDUCE(uint32_t, uint32, xor, ^)
    XBGAS_REDUCE(int32_t, int32, xor, ^)
    XBGAS_REDUCE(uint64_t, uint64, xor, ^)
    XBGAS_REDUCE(int64_t, int64, xor, ^)
    XBGAS_REDUCE(size_t, size, xor, ^)
    XBGAS_REDUCE(ptrdiff_t, ptrdiff, xor, ^)

#undef XBGAS_REDUCE

#define XBGAS_REDUCE_MM(_type, _typename, _funcname, _op)                                                                                               \
void xbrtime_##_typename##_reduce_##_funcname##_tree(_type *dest, const _type *src, size_t nelems, int stride, int root)                                \
{                                                                                                                                                       \
    int i, j, numpes,my_rpe, my_vpe, numpes_log, mask, two_i, r_partner, v_partner;                                                                     \
    stride = ((stride == 0) ? 1 : stride);   /* Avoid memory allocation problem */                                                                      \
    _type *temp = (_type*) malloc(nelems * (sizeof(_type) * stride));                                                                                   \
    _type *accumulate = (_type*) xbrtime_malloc(nelems * (sizeof(_type) * stride));                                                                     \
    numpes = xbrtime_num_pes();                                                                                                                         \
    my_rpe = xbrtime_mype();                                                                                                                            \
    my_vpe = ((my_rpe >= root) ? (my_rpe - root) : (my_rpe + numpes - root));                                                                           \
    numpes_log = (int) ceil((log(numpes)/log(2)));   /* Number of commmuication stages */                                                               \
    mask = (int) (pow(2,numpes_log) - 1);                                                                                                               \
                                                                                                                                                        \
    /* Load accumulate buffer on each PE */                                                                                                             \
    for(i = 0; i < nelems; i++)                                                                                                                         \
    {                                                                                                                                                   \
        accumulate[i*stride] = src[i*stride];                                                                                                           \
    }                                                                                                                                                   \
                                                                                                                                                        \
    /* Ensure accumulate buffer is ready */                                                                                                             \
    xbrtime_barrier();                                                                                                                                  \
                                                                                                                                                        \
    /* Perform communication if PE active at stage i and has valid partner */                                                                           \
    for(i = 0; i < numpes_log; i++)                                                                                                                     \
    {                                                                                                                                                   \
        two_i = (int) pow(2,i);                                                                                                                         \
        mask = mask ^ two_i;                                                                                                                            \
        if(((my_vpe | mask) == mask) && ((my_vpe & two_i) == 0))                                                                                        \
        {                                                                                                                                               \
            v_partner = (my_vpe ^ two_i) % numpes;                                                                                                      \
            r_partner = (v_partner + root) % numpes;                                                                                                    \
            if(my_vpe < v_partner)                                                                                                                      \
            {                                                                                                                                           \
                xbrtime_##_typename##_get(temp, accumulate, nelems, stride, r_partner);                                                                 \
                for(j = 0; j < nelems; j++)                                                                                                             \
                {                                                                                                                                       \
                    accumulate[j*stride] = (_type) _op(accumulate[j*stride], temp[j*stride]);                                                           \
                }                                                                                                                                       \
            }                                                                                                                                           \
        }                                                                                                                                               \
        xbrtime_barrier();                                                                                                                              \
    }                                                                                                                                                   \
                                                                                                                                                        \
    /* Copy data to destination on root*/                                                                                                               \
    if(my_vpe == 0)                                                                                                                                     \
    {                                                                                                                                                   \
        for(i = 0; i < nelems; i++)                                                                                                                     \
        {                                                                                                                                               \
            dest[i*stride] = accumulate[i*stride];                                                                                                      \
        }                                                                                                                                               \
    }                                                                                                                                                   \
    xbrtime_free(accumulate);                                                                                                                           \
    free(temp);                                                                                                                                         \
}                                                                                                                                                       \
                                                                                                                                                        \
void xbrtime_##_typename##_reduce_##_funcname##_rabenseifner(_type *dest, const _type *src, size_t nelems, int stride, int root)                        \
{                                                                                                                                                       \
    int i, j, numpes, my_rpe, my_lpe, my_vpe, r_partner, l_partner, numpes_log_floor, p_prime, remainder, counter;                                      \
    numpes = xbrtime_num_pes();                                                                                                                         \
    my_rpe = xbrtime_mype();                                                                                                                            \
    my_lpe = ((my_rpe >= root) ? (my_rpe - root) : (my_rpe + numpes - root)); /* Logical PE abstraction - ensure root PE is not a removed PE */         \
    my_vpe = my_lpe;                                                          /* Root PE always lpe 0 */                                                \
    numpes_log_floor = (int) (log(numpes)/log(2));                                                                                                      \
    p_prime = 1 << numpes_log_floor;                                                                                                                    \
    remainder = numpes - p_prime;                                                                                                                       \
    _type *accumulate = (_type*) xbrtime_malloc(sizeof(_type) * nelems);                                                                                \
    _type *temp = (_type*) xbrtime_malloc(sizeof(_type) * nelems);                                                                                      \
                                                                                                                                                        \
    /* Load reduction values into accumulate buffer and remove stride */                                                                                \
    for(i = 0; i < nelems; i++)                                                                                                                         \
    {                                                                                                                                                   \
        accumulate[i] = src[i*stride];                                                                                                                  \
    }                                                                                                                                                   \
                                                                                                                                                        \
    /* Divide buffers into p_prime partitions */                                                                                                        \
    counter = 0;                                                                                                                                        \
    int partition_sizes[p_prime], partition_disp[p_prime];                                                                                              \
    for(i = 0; i < p_prime; i++)                                                                                                                        \
    {                                                                                                                                                   \
        partition_sizes[i] = ( (i == p_prime-1) ?                                                                                                       \
                             (((int)(nelems/p_prime)) + (nelems%p_prime)) :                                                                             \
                             ((int)(nelems/p_prime)) );                                                                                                 \
        partition_disp[i] = counter;                                                                                                                    \
        counter += partition_sizes[i];                                                                                                                  \
    }                                                                                                                                                   \
                                                                                                                                                        \
    /* Ensure buffer is ready */                                                                                                                        \
    xbrtime_barrier();                                                                                                                                  \
                                                                                                                                                        \
    int num_exchange = p_prime/2;                                                                                                                       \
    int msg_size = 0;                                                                                                                                   \
                                                                                                                                                        \
    /* Stage 1 - ReduceScatter (only if NumPEs is not a power of two) */                                                                                \
    if(numpes_log_floor != (log(numpes)/log(2)))                                                                                                        \
    {                                                                                                                                                   \
        /* First 2r lpe ranks */                                                                                                                        \
        if(my_lpe < 2*remainder)                                                                                                                        \
        {                                                                                                                                               \
            /* Even ranks */                                                                                                                            \
            if(my_lpe % 2 == 0)                                                                                                                         \
            {                                                                                                                                           \
                /* Calculate and get first half of values from my_lpe + 1 */                                                                            \
                l_partner = my_lpe+1;                                                                                                                   \
                r_partner = ((l_partner+root) % numpes);                                                                                                \
                for(j = 0; j < num_exchange; j++)                                                                                                       \
                {                                                                                                                                       \
                    msg_size += partition_sizes[j];                                                                                                     \
                }                                                                                                                                       \
                                                                                                                                                        \
                xbrtime_##_typename##_get(temp, accumulate, msg_size, 1, r_partner);                                                                    \
                                                                                                                                                        \
                /* Perform reduction op */                                                                                                              \
                for(j = 0; j < msg_size; j++)                                                                                                           \
                {                                                                                                                                       \
                    accumulate[j] = _op(accumulate[j], temp[j]);                                                                                        \
                }                                                                                                                                       \
                                                                                                                                                        \
                /* Assign new vpe ranks */                                                                                                              \
                my_vpe = my_lpe/2;                                                                                                                      \
            }                                                                                                                                           \
            /* Odd ranks */                                                                                                                             \
            else                                                                                                                                        \
            {                                                                                                                                           \
                /* Calculate and get second half of values from my_lpe - 1 */                                                                           \
                l_partner = my_lpe-1;                                                                                                                   \
                r_partner = ((l_partner+root) % numpes);                                                                                                \
                for(j = num_exchange; j < p_prime; j++)                                                                                                 \
                {                                                                                                                                       \
                    msg_size += partition_sizes[j];                                                                                                     \
                }                                                                                                                                       \
                                                                                                                                                        \
                xbrtime_##_typename##_get(&(temp[(partition_disp[num_exchange])]), &(accumulate[(partition_disp[num_exchange])]),                       \
                                            msg_size, 1, r_partner);                                                                                    \
                                                                                                                                                        \
                /* Perform reduction op */                                                                                                              \
                for(j = 0; j < msg_size; j++)                                                                                                           \
                {                                                                                                                                       \
                    accumulate[(partition_disp[num_exchange])+j] = _op(accumulate[(partition_disp[num_exchange])+j],                                    \
                                                                        temp[(partition_disp[num_exchange])+j]);                                        \
                }                                                                                                                                       \
                                                                                                                                                        \
                /* Put calculated second half values back to even partner */                                                                            \
                xbrtime_##_typename##_put(&(accumulate[(partition_disp[num_exchange])]), &(accumulate[(partition_disp[num_exchange])]),                 \
                                            msg_size, 1, r_partner);                                                                                    \
                                                                                                                                                        \
                /* Assign new vpe ranks */                                                                                                              \
                my_vpe = -1;                                                                                                                            \
            }                                                                                                                                           \
        }                                                                                                                                               \
        else                                                                                                                                            \
        {                                                                                                                                               \
            /* Assign new vpe ranks */                                                                                                                  \
            my_vpe = my_lpe - remainder;                                                                                                                \
        }                                                                                                                                               \
        xbrtime_barrier();                                                                                                                              \
    }                                                                                                                                                   \
                                                                                                                                                        \
    /* Stage 2 - ReduceScatter Recursive Doubling/Halving */                                                                                            \
    int pe_stride = 1;                                                                                                                                  \
    int offset = 0;                                                                                                                                     \
    for(i = 0; i < numpes_log_floor; i++)                                                                                                               \
    {                                                                                                                                                   \
        msg_size = 0;                                                                                                                                   \
        if(my_vpe != -1)                                                                                                                                \
        {                                                                                                                                               \
            /* PEs perform get and reduction of first buffer half */                                                                                    \
            if((my_vpe & ( 1 << i)) == 0)                                                                                                               \
            {                                                                                                                                           \
                l_partner = ((my_vpe+pe_stride) < remainder ? (my_vpe+pe_stride)*2 : (my_vpe+pe_stride)+remainder);                                     \
                r_partner = ((l_partner+root) % numpes);                                                                                                \
                                                                                                                                                        \
                /* Calculate msg_size */                                                                                                                \
                for(j = 0; j < num_exchange; j++)                                                                                                       \
                {                                                                                                                                       \
                    msg_size += partition_sizes[offset+j];                                                                                              \
                }                                                                                                                                       \
                                                                                                                                                        \
                xbrtime_##_typename##_get(&(temp[(partition_disp[offset])]), &(accumulate[(partition_disp[offset])]), msg_size, 1, r_partner);          \
                                                                                                                                                        \
                /* Perform reduction op */                                                                                                              \
                for(j = 0; j < msg_size; j++)                                                                                                           \
                {                                                                                                                                       \
                    accumulate[(partition_disp[offset]+j)] = _op(accumulate[(partition_disp[offset])+j], temp[(partition_disp[offset])+j]);             \
                }                                                                                                                                       \
            }                                                                                                                                           \
            /* PEs perform get and reduction of second buffer half */                                                                                   \
            else                                                                                                                                        \
            {                                                                                                                                           \
                l_partner = (((my_vpe-pe_stride+p_prime)%p_prime) < remainder ? ((my_vpe-pe_stride+p_prime)%p_prime)*2 :                                \
                            ((my_vpe-pe_stride+p_prime)%p_prime)+remainder);                                                                            \
                r_partner = ((l_partner+root) % numpes);                                                                                                \
                                                                                                                                                        \
                /* Calculate msg_size */                                                                                                                \
                for(j = 0; j < num_exchange; j++)                                                                                                       \
                {                                                                                                                                       \
                    msg_size += partition_sizes[offset+num_exchange+j];                                                                                 \
                }                                                                                                                                       \
                                                                                                                                                        \
                xbrtime_##_typename##_get(&(temp[(partition_disp[offset+num_exchange])]), &(accumulate[(partition_disp[offset+num_exchange])]),         \
                                            msg_size, 1, r_partner);                                                                                    \
                                                                                                                                                        \
                /* Perform reduction op */                                                                                                              \
                for(j = 0; j < msg_size; j++)                                                                                                           \
                {                                                                                                                                       \
                    accumulate[(partition_disp[offset+num_exchange])+j] = _op(accumulate[(partition_disp[offset+num_exchange])+j],                      \
                                                                       temp[(partition_disp[offset+num_exchange])+j]);                                  \
                }                                                                                                                                       \
                                                                                                                                                        \
                /* Increase offset for these PEs*/                                                                                                      \
                offset += num_exchange;                                                                                                                 \
            }                                                                                                                                           \
        }                                                                                                                                               \
        num_exchange >>= 1;                                                                                                                             \
        pe_stride <<= 1;                                                                                                                                \
        xbrtime_barrier();                                                                                                                              \
    }                                                                                                                                                   \
                                                                                                                                                        \
    /* Stage 3 - Gather to root PE */                                                                                                                   \
    pe_stride = (1 << (numpes_log_floor-1));                                                                                                            \
    num_exchange = 1;                                                                                                                                   \
    int active_pes = p_prime;                                                                                                                           \
    for(i = numpes_log_floor - 1; i >= 0; i--)                                                                                                          \
    {                                                                                                                                                   \
        msg_size = 0;                                                                                                                                   \
        if(my_vpe != -1)                                                                                                                                \
        {                                                                                                                                               \
            /* PEs perform put */                                                                                                                       \
            if(((my_vpe & ( 1 << i)) == (1 << i)) && (my_vpe < active_pes))                                                                             \
            {                                                                                                                                           \
                l_partner = (((my_vpe-pe_stride+p_prime)%p_prime) < remainder ? ((my_vpe-pe_stride+p_prime)%p_prime)*2 :                                \
                            ((my_vpe-pe_stride+p_prime)%p_prime)+remainder);                                                                            \
                r_partner = ((l_partner+root) % numpes);                                                                                                \
                                                                                                                                                        \
                /* Calculate msg_size */                                                                                                                \
                for(j = 0; j < num_exchange; j++)                                                                                                       \
                {                                                                                                                                       \
                    msg_size += partition_sizes[offset+j];                                                                                              \
                }                                                                                                                                       \
                                                                                                                                                        \
                xbrtime_##_typename##_put(&(accumulate[(partition_disp[offset])]), &(accumulate[(partition_disp[offset])]), msg_size, 1, r_partner);    \
            }                                                                                                                                           \
        }                                                                                                                                               \
        num_exchange <<= 1;                                                                                                                             \
        pe_stride >>= 1;                                                                                                                                \
        active_pes >>= 1;                                                                                                                               \
        xbrtime_barrier();                                                                                                                              \
    }                                                                                                                                                   \
                                                                                                                                                        \
    /* Copy from buffer to dest with stride on root rpe */                                                                                              \
    if(my_lpe == 0)                                                                                                                                     \
    {                                                                                                                                                   \
        for(i = 0; i < nelems; i++)                                                                                                                     \
        {                                                                                                                                               \
            dest[i*stride] = accumulate[i];                                                                                                             \
        }                                                                                                                                               \
    }                                                                                                                                                   \
                                                                                                                                                        \
    xbrtime_free(accumulate);                                                                                                                           \
    xbrtime_free(temp);                                                                                                                                 \
}                                                                                                                                                       \
                                                                                                                                                        \
/* Wrapper function - binomial tree for small messages, rabenseifner for large messages */                                                              \
void xbrtime_##_typename##_reduce_##_funcname(_type *dest, const _type *src, size_t nelems, int stride, int root)                                       \
{                                                                                                                                                       \
    if((sizeof(_type)*nelems) < LARGE_REDUCE)                                                                                                           \
    {                                                                                                                                                   \
        xbrtime_##_typename##_reduce_##_funcname##_tree(dest, src, nelems, stride, root);                                                               \
    }                                                                                                                                                   \
    else                                                                                                                                                \
    {                                                                                                                                                   \
        xbrtime_##_typename##_reduce_##_funcname##_rabenseifner(dest, src, nelems, stride, root);                                                       \
    }                                                                                                                                                   \
}

    /* Max */
    XBGAS_REDUCE_MM(float, float, max, MAX)
    XBGAS_REDUCE_MM(double, double, max, MAX)
    XBGAS_REDUCE_MM(char, char, max, MAX)
    XBGAS_REDUCE_MM(unsigned char, uchar, max, MAX)
    XBGAS_REDUCE_MM(signed char, schar, max, MAX)
    XBGAS_REDUCE_MM(unsigned short, ushort, max, MAX)
    XBGAS_REDUCE_MM(short, short, max, MAX)
    XBGAS_REDUCE_MM(unsigned int, uint, max, MAX)
    XBGAS_REDUCE_MM(int, int, max, MAX)
    XBGAS_REDUCE_MM(unsigned long, ulong, max, MAX)
    XBGAS_REDUCE_MM(long, long, max, MAX)
    XBGAS_REDUCE_MM(unsigned long long, ulonglong, max, MAX)
    XBGAS_REDUCE_MM(long long, longlong, max, MAX)
    XBGAS_REDUCE_MM(uint8_t, uint8, max, MAX)
    XBGAS_REDUCE_MM(int8_t, int8, max, MAX)
    XBGAS_REDUCE_MM(uint16_t, uint16, max, MAX)
    XBGAS_REDUCE_MM(int16_t, int16, max, MAX)
    XBGAS_REDUCE_MM(uint32_t, uint32, max, MAX)
    XBGAS_REDUCE_MM(int32_t, int32, max, MAX)
    XBGAS_REDUCE_MM(uint64_t, uint64, max, MAX)
    XBGAS_REDUCE_MM(int64_t, int64, max, MAX)
    XBGAS_REDUCE_MM(size_t, size, max, MAX)
    XBGAS_REDUCE_MM(ptrdiff_t, ptrdiff, max, MAX)
    //  XBGAS_REDUCE_MM(long double, longdouble, max, MAX)

    /* Min */
    XBGAS_REDUCE_MM(float, float, min, MIN)
    XBGAS_REDUCE_MM(double, double, min, MIN)
    XBGAS_REDUCE_MM(char, char, min, MIN)
    XBGAS_REDUCE_MM(unsigned char, uchar, min, MIN)
    XBGAS_REDUCE_MM(signed char, schar, min, MIN)
    XBGAS_REDUCE_MM(unsigned short, ushort, min, MIN)
    XBGAS_REDUCE_MM(short, short, min, MIN)
    XBGAS_REDUCE_MM(unsigned int, uint, min, MIN)
    XBGAS_REDUCE_MM(int, int, min, MIN)
    XBGAS_REDUCE_MM(unsigned long, ulong, min, MIN)
    XBGAS_REDUCE_MM(long, long, min, MIN)
    XBGAS_REDUCE_MM(unsigned long long, ulonglong, min, MIN)
    XBGAS_REDUCE_MM(long long, longlong, min, MIN)
    XBGAS_REDUCE_MM(uint8_t, uint8, min, MIN)
    XBGAS_REDUCE_MM(int8_t, int8, min, MIN)
    XBGAS_REDUCE_MM(uint16_t, uint16, min, MIN)
    XBGAS_REDUCE_MM(int16_t, int16, min, MIN)
    XBGAS_REDUCE_MM(uint32_t, uint32, min, MIN)
    XBGAS_REDUCE_MM(int32_t, int32, min, MIN)
    XBGAS_REDUCE_MM(uint64_t, uint64, min, MIN)
    XBGAS_REDUCE_MM(int64_t, int64, min, MIN)
    XBGAS_REDUCE_MM(size_t, size, min, MIN)
    XBGAS_REDUCE_MM(ptrdiff_t, ptrdiff, min, MIN)
    //  XBGAS_REDUCE_MM(long double, longdouble, min, MIN)

#undef XBGAS_REDUCE_MM

#undef MAX
#undef MIN
