/*
 * _XBRTIME_ATOMICS_H_
 *
 * Copyright (C) 2017-2019 Tactical Computing Laboratories, LLC
 * All Rights Reserved
 * contact@tactcomplabs.com
 *
 * This file is a part of the XBGAS-RUNTIME package.  For license
 * information, see the LICENSE file in the top level directory
 * of the distribution.
 *
 */

#ifndef _XBRTIME_ATOMICS_H_
#define _XBRTIME_ATOMICS_H_

#ifdef __cplusplus
#define extern "C" {
#endif

/*!   \fn xbrtime_TYPENAME_atomic_OP( TYPE *dest, TYPE op_val, int pe )
      \brief Performs an atomic memory operation on a remote pe; OP is one of {add, lor, land, lxor, min, max}
      \param dest is a pointer to the base shared address on the target PE where the atomic operation is to be performed
      \param op_val is a provdied operand for the atomic operation
      \param pe is the id of the target remote pe
      \return void
*/
#define XBGAS_DECL_ATOMIC_OP(_type, _typename, _op)                                                     \
void xbrtime_##_typename##_atomic_##_op(_type *dest, _type op_val, int pe);

    /* Atomic add */
    XBGAS_DECL_ATOMIC_OP(unsigned int, uint, add)
    XBGAS_DECL_ATOMIC_OP(unsigned long, ulong, add)
    XBGAS_DECL_ATOMIC_OP(uint32_t, uint32, add)
    XBGAS_DECL_ATOMIC_OP(int, int, add)
    XBGAS_DECL_ATOMIC_OP(long, long, add)
    XBGAS_DECL_ATOMIC_OP(int32_t, int32, add)
    XBGAS_DECL_ATOMIC_OP(unsigned long long, ulonglong, add)
    XBGAS_DECL_ATOMIC_OP(uint64_t, uint64, add)
    XBGAS_DECL_ATOMIC_OP(long long, longlong, add)
    XBGAS_DECL_ATOMIC_OP(int64_t, int64, add)

    /* Atomic logical and */
    XBGAS_DECL_ATOMIC_OP(unsigned int, uint, land)
    XBGAS_DECL_ATOMIC_OP(unsigned long, ulong, land)
    XBGAS_DECL_ATOMIC_OP(uint32_t, uint32, land)
    XBGAS_DECL_ATOMIC_OP(int, int, land)
    XBGAS_DECL_ATOMIC_OP(long, long, land)
    XBGAS_DECL_ATOMIC_OP(int32_t, int32, land)
    XBGAS_DECL_ATOMIC_OP(unsigned long long, ulonglong, land)
    XBGAS_DECL_ATOMIC_OP(uint64_t, uint64, land)
    XBGAS_DECL_ATOMIC_OP(long long, longlong, land)
    XBGAS_DECL_ATOMIC_OP(int64_t, int64, land)

    /* Atomic logical or */
    XBGAS_DECL_ATOMIC_OP(unsigned int, uint, lor)
    XBGAS_DECL_ATOMIC_OP(unsigned long, ulong, lor)
    XBGAS_DECL_ATOMIC_OP(uint32_t, uint32, lor)
    XBGAS_DECL_ATOMIC_OP(int, int, lor)
    XBGAS_DECL_ATOMIC_OP(long, long, lor)
    XBGAS_DECL_ATOMIC_OP(int32_t, int32, lor)
    XBGAS_DECL_ATOMIC_OP(unsigned long long, ulonglong, lor)
    XBGAS_DECL_ATOMIC_OP(uint64_t, uint64, lor)
    XBGAS_DECL_ATOMIC_OP(long long, longlong, lor)
    XBGAS_DECL_ATOMIC_OP(int64_t, int64, lor)

    /* Atomic logical exclusive or */
    XBGAS_DECL_ATOMIC_OP(unsigned int, uint, lxor)
    XBGAS_DECL_ATOMIC_OP(unsigned long, ulong, lxor)
    XBGAS_DECL_ATOMIC_OP(uint32_t, uint32, lxor)
    XBGAS_DECL_ATOMIC_OP(int, int, lxor)
    XBGAS_DECL_ATOMIC_OP(long, long, lxor)
    XBGAS_DECL_ATOMIC_OP(int32_t, int32, lxor)
    XBGAS_DECL_ATOMIC_OP(unsigned long long, ulonglong, lxor)
    XBGAS_DECL_ATOMIC_OP(uint64_t, uint64, lxor)
    XBGAS_DECL_ATOMIC_OP(long long, longlong, lxor)
    XBGAS_DECL_ATOMIC_OP(int64_t, int64, lxor)

    /* Atomic min */
    XBGAS_DECL_ATOMIC_OP(unsigned int, uint, min)
    XBGAS_DECL_ATOMIC_OP(unsigned long, ulong, min)
    XBGAS_DECL_ATOMIC_OP(uint32_t, uint32, min)
    //XBGAS_DECL_ATOMIC_OP(int, int, min)
    //XBGAS_DECL_ATOMIC_OP(long, long, min)
    //XBGAS_DECL_ATOMIC_OP(int32_t, int32, min)
    XBGAS_DECL_ATOMIC_OP(unsigned long long, ulonglong, min)
    XBGAS_DECL_ATOMIC_OP(uint64_t, uint64, min)
    //XBGAS_DECL_ATOMIC_OP(long long, longlong, min)
    //XBGAS_DECL_ATOMIC_OP(int64_t, int64, min)

    /* Atomic max */
    XBGAS_DECL_ATOMIC_OP(unsigned int, uint, max)
    XBGAS_DECL_ATOMIC_OP(unsigned long, ulong, max)
    XBGAS_DECL_ATOMIC_OP(uint32_t, uint32, max)
    //XBGAS_DECL_ATOMIC_OP(int, int, max)
    //XBGAS_DECL_ATOMIC_OP(long, long, max)
    //XBGAS_DECL_ATOMIC_OP(int32_t, int32, max)
    XBGAS_DECL_ATOMIC_OP(unsigned long long, ulonglong, max)
    XBGAS_DECL_ATOMIC_OP(uint64_t, uint64, max)
    //XBGAS_DECL_ATOMIC_OP(long long, longlong, max)
    //XBGAS_DECL_ATOMIC_OP(int64_t, int64, max)

#undef XBGAS_DECL_ATOMIC_OP

/*!   \fn xbrtime_TYPENAME_atomic_compare_swap( TYPE *dest, TYPE comp_val, int pe )
      \brief Performs an atomic compare & swap operation on a remote pe
      \param dest is a pointer to the base shared address on the target PE where the compare & swap is to be performed
      \param comp_val is the provided value to compare against the value at DEST
      \param pe is the id of the target remote pe
      \return void
*/
#define XBGAS_DECL_ATOMIC_CAS(_type, _typename)                                                         \
void xbrtime_##_typename##_atomic_compare_swap(_type *dest, _type comp_val, int pe);

    /* Atomic compare and swap */
    XBGAS_DECL_ATOMIC_CAS(unsigned int, uint)
    XBGAS_DECL_ATOMIC_CAS(unsigned long, ulong)
    XBGAS_DECL_ATOMIC_CAS(uint32_t, uint32)
    XBGAS_DECL_ATOMIC_CAS(int, int)
    XBGAS_DECL_ATOMIC_CAS(long, long)
    XBGAS_DECL_ATOMIC_CAS(int32_t, int32)
    XBGAS_DECL_ATOMIC_CAS(unsigned long long, ulonglong)
    XBGAS_DECL_ATOMIC_CAS(uint64_t, uint64)
    XBGAS_DECL_ATOMIC_CAS(long long, longlong)
    XBGAS_DECL_ATOMIC_CAS(int64_t, int64)

#undef XBGAS_DECL_ATOMIC_CAS

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* _XBRTIME_ATOMICS_H_ */

/* EOF */
