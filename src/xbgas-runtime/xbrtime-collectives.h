/*
 * _XBRTIME_COLLECTIVES_H_
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

#ifndef _XBRTIME_COLLECTIVES_H_
#define _XBRTIME_COLLECTIVES_H_

#ifdef __cplusplus
#define extern "C" {
#endif

#define INIT_ADDR 0xBB00000000000000ull

void temp_barrier();

 /*!   \fn void xbrtime_TYPENAME_broadcast( TYPE *dest, const TYPE *src, size_t nelems, int stride, int root )
       \brief Broadcasts one or more values of type TYPE from the root to all PEs
       \param dest is a pointer to the base shared address where broadcasted values are placed on each PE
       \param src is a pointer to the base shared address on root where values to be broadcast are located
       \param nelems is the number of elements to be broadcast to each PE
       \param stride is the stride size between broadcast elements at src and dest
       \param root is the PE id of the root PE
       \return void
 */
#define XBGAS_DECL_BROADCAST(_type, _typename)                                                                    \
void xbrtime_##_typename##_broadcast(_type *dest, const _type *src, size_t nelems, int stride, int root);

    XBGAS_DECL_BROADCAST(float, float)
    XBGAS_DECL_BROADCAST(double, double)
    XBGAS_DECL_BROADCAST(char, char)
    XBGAS_DECL_BROADCAST(unsigned char, uchar)
    XBGAS_DECL_BROADCAST(signed char, schar)
    XBGAS_DECL_BROADCAST(unsigned short, ushort)
    XBGAS_DECL_BROADCAST(short, short)
    XBGAS_DECL_BROADCAST(unsigned int, uint)
    XBGAS_DECL_BROADCAST(int, int)
    XBGAS_DECL_BROADCAST(unsigned long, ulong)
    XBGAS_DECL_BROADCAST(long, long)
    XBGAS_DECL_BROADCAST(unsigned long long, ulonglong)
    XBGAS_DECL_BROADCAST(long long, longlong)
    XBGAS_DECL_BROADCAST(uint8_t, uint8)
    XBGAS_DECL_BROADCAST(int8_t, int8)
    XBGAS_DECL_BROADCAST(uint16_t, uint16)
    XBGAS_DECL_BROADCAST(int16_t, int16)
    XBGAS_DECL_BROADCAST(uint32_t, uint32)
    XBGAS_DECL_BROADCAST(int32_t, int32)
    XBGAS_DECL_BROADCAST(uint64_t, uint64)
    XBGAS_DECL_BROADCAST(int64_t, int64)
    XBGAS_DECL_BROADCAST(size_t, size)
    XBGAS_DECL_BROADCAST(ptrdiff_t, ptrdiff)
    //  XBGAS_DECL_BROADCAST(long double, longdouble)

#undef XBGAS_DECL_BROADCAST

/*!   \fn xbrtime_TYPENAME_reduce_FUNC( TYPE *dest, const TYPE *src, size_t nelems, int stride, int root )
      \brief Performs reduction operation FUNC (sum, product, min, max, and, or, xor) on one or more values of type TYPE and places the result on root
      \param dest is a pointer to the base shared address where final reduce values are placed on the root PE
      \param src is a pointer to the base shared address on each PE where values are located on which the reduction is to be performed
      \param nelems is the number of elements on each PE on which reduce op FUNC is to be performed
      \param stride is the stride size between reduce elements at src and dest
      \param root is the PE id of the root PE
      \return void
*/
#define XBGAS_DECL_REDUCE(_type, _typename, _funcname)                                                            \
void xbrtime_##_typename##_reduce_##_funcname(_type *dest, const _type *src, size_t nelems, int stride, int root);

    /* Sum */
    XBGAS_DECL_REDUCE(float, float, sum)
    XBAGS_DECL_REDUCE(double, double, sum)
    XBAGS_DECL_REDUCE(char, char, sum)
    XBAGS_DECL_REDUCE(unsigned char, uchar, sum)
    XBAGS_DECL_REDUCE(signed char, schar, sum)
    XBAGS_DECL_REDUCE(unsigned short, ushort, sum)
    XBAGS_DECL_REDUCE(short, short, sum)
    XBAGS_DECL_REDUCE(unsigned int, uint, sum)
    XBAGS_DECL_REDUCE(int, int, sum)
    XBAGS_DECL_REDUCE(unsigned long, ulong, sum)
    XBAGS_DECL_REDUCE(long, long, sum)
    XBAGS_DECL_REDUCE(unsigned long long, ulonglong, sum)
    XBAGS_DECL_REDUCE(long long, longlong, sum)
    XBAGS_DECL_REDUCE(uint8_t, uint8, sum)
    XBAGS_DECL_REDUCE(int8_t, int8, sum)
    XBAGS_DECL_REDUCE(uint16_t, uint16, sum)
    XBAGS_DECL_REDUCE(int16_t, int16, sum)
    XBAGS_DECL_REDUCE(uint32_t, uint32, sum)
    XBAGS_DECL_REDUCE(int32_t, int32, sum)
    XBAGS_DECL_REDUCE(uint64_t, uint64, sum)
    XBAGS_DECL_REDUCE(int64_t, int64, sum)
    XBAGS_DECL_REDUCE(size_t, size, sum)
    XBAGS_DECL_REDUCE(ptrdiff_t, ptrdiff, sum)
    //  XBAGS_DECL_REDUCE(long double, longdouble, sum)

    /* Product */
    XBAGS_DECL_REDUCE(float, float, product)
    XBAGS_DECL_REDUCE(double, double, product)
    XBAGS_DECL_REDUCE(char, char, product)
    XBAGS_DECL_REDUCE(unsigned char, uchar, product)
    XBAGS_DECL_REDUCE(signed char, schar, product)
    XBAGS_DECL_REDUCE(unsigned short, ushort, product)
    XBAGS_DECL_REDUCE(short, short, product)
    XBAGS_DECL_REDUCE(unsigned int, uint, product)
    XBAGS_DECL_REDUCE(int, int, product)
    XBAGS_DECL_REDUCE(unsigned long, ulong, product)
    XBAGS_DECL_REDUCE(long, long, product)
    XBAGS_DECL_REDUCE(unsigned long long, ulonglong, product)
    XBAGS_DECL_REDUCE(long long, longlong, product)
    XBAGS_DECL_REDUCE(uint8_t, uint8, product)
    XBAGS_DECL_REDUCE(int8_t, int8, product)
    XBAGS_DECL_REDUCE(uint16_t, uint16, product)
    XBAGS_DECL_REDUCE(int16_t, int16, product)
    XBAGS_DECL_REDUCE(uint32_t, uint32, product)
    XBAGS_DECL_REDUCE(int32_t, int32, product)
    XBAGS_DECL_REDUCE(uint64_t, uint64, product)
    XBAGS_DECL_REDUCE(int64_t, int64, product)
    XBAGS_DECL_REDUCE(size_t, size, product)
    XBAGS_DECL_REDUCE(ptrdiff_t, ptrdiff, product)
    //  XBAGS_DECL_REDUCE(long double, longdouble, product)

    /* Binary AND */
    XBAGS_DECL_REDUCE(char, char, and)
    XBAGS_DECL_REDUCE(unsigned char, uchar, and)
    XBAGS_DECL_REDUCE(signed char, schar, and)
    XBAGS_DECL_REDUCE(unsigned short, ushort, and)
    XBAGS_DECL_REDUCE(short, short, and)
    XBAGS_DECL_REDUCE(unsigned int, uint, and)
    XBAGS_DECL_REDUCE(int, int, and)
    XBAGS_DECL_REDUCE(unsigned long, ulong, and)
    XBAGS_DECL_REDUCE(long, long, and)
    XBAGS_DECL_REDUCE(unsigned long long, ulonglong, and)
    XBAGS_DECL_REDUCE(long long, longlong, and)
    XBAGS_DECL_REDUCE(uint8_t, uint8, and)
    XBAGS_DECL_REDUCE(int8_t, int8, and)
    XBAGS_DECL_REDUCE(uint16_t, uint16, and)
    XBAGS_DECL_REDUCE(int16_t, int16, and)
    XBAGS_DECL_REDUCE(uint32_t, uint32, and)
    XBAGS_DECL_REDUCE(int32_t, int32, and)
    XBAGS_DECL_REDUCE(uint64_t, uint64, and)
    XBAGS_DECL_REDUCE(int64_t, int64, and)
    XBAGS_DECL_REDUCE(size_t, size, and)
    XBAGS_DECL_REDUCE(ptrdiff_t, ptrdiff, and)

    /* Binary OR */
    XBAGS_DECL_REDUCE(char, char, or)
    XBAGS_DECL_REDUCE(unsigned char, uchar, or)
    XBAGS_DECL_REDUCE(signed char, schar, or)
    XBAGS_DECL_REDUCE(unsigned short, ushort, or)
    XBAGS_DECL_REDUCE(short, short, or)
    XBAGS_DECL_REDUCE(unsigned int, uint, or)
    XBAGS_DECL_REDUCE(int, int, or)
    XBAGS_DECL_REDUCE(unsigned long, ulong, or)
    XBAGS_DECL_REDUCE(long, long, or)
    XBAGS_DECL_REDUCE(unsigned long long, ulonglong, or)
    XBAGS_DECL_REDUCE(long long, longlong, or)
    XBAGS_DECL_REDUCE(uint8_t, uint8, or)
    XBAGS_DECL_REDUCE(int8_t, int8, or)
    XBAGS_DECL_REDUCE(uint16_t, uint16, or)
    XBAGS_DECL_REDUCE(int16_t, int16, or)
    XBAGS_DECL_REDUCE(uint32_t, uint32, or)
    XBAGS_DECL_REDUCE(int32_t, int32, or)
    XBAGS_DECL_REDUCE(uint64_t, uint64, or)
    XBAGS_DECL_REDUCE(int64_t, int64, or)
    XBAGS_DECL_REDUCE(size_t, size, or)
    XBAGS_DECL_REDUCE(ptrdiff_t, ptrdiff, or)

    /* Binary XOR */
    XBAGS_DECL_REDUCE(char, char, xor)
    XBAGS_DECL_REDUCE(unsigned char, uchar, xor)
    XBAGS_DECL_REDUCE(signed char, schar, xor)
    XBAGS_DECL_REDUCE(unsigned short, ushort, xor)
    XBAGS_DECL_REDUCE(short, short, xor)
    XBAGS_DECL_REDUCE(unsigned int, uint, xor)
    XBAGS_DECL_REDUCE(int, int, xor)
    XBAGS_DECL_REDUCE(unsigned long, ulong, xor)
    XBAGS_DECL_REDUCE(long, long, xor)
    XBAGS_DECL_REDUCE(unsigned long long, ulonglong, xor)
    XBAGS_DECL_REDUCE(long long, longlong, xor)
    XBAGS_DECL_REDUCE(uint8_t, uint8, xor)
    XBAGS_DECL_REDUCE(int8_t, int8, xor)
    XBAGS_DECL_REDUCE(uint16_t, uint16, xor)
    XBAGS_DECL_REDUCE(int16_t, int16, xor)
    XBAGS_DECL_REDUCE(uint32_t, uint32, xor)
    XBAGS_DECL_REDUCE(int32_t, int32, xor)
    XBAGS_DECL_REDUCE(uint64_t, uint64, xor)
    XBAGS_DECL_REDUCE(int64_t, int64, xor)
    XBAGS_DECL_REDUCE(size_t, size, xor)
    XBAGS_DECL_REDUCE(ptrdiff_t, ptrdiff, xor)

    /* Max */
    XBAGS_DECL_REDUCE(float, float, max)
    XBAGS_DECL_REDUCE(double, double, max)
    XBAGS_DECL_REDUCE(char, char, max)
    XBAGS_DECL_REDUCE(unsigned char, uchar, max)
    XBAGS_DECL_REDUCE(signed char, schar, max)
    XBAGS_DECL_REDUCE(unsigned short, ushort, max)
    XBAGS_DECL_REDUCE(short, short, max)
    XBAGS_DECL_REDUCE(unsigned int, uint, max)
    XBAGS_DECL_REDUCE(int, int, max)
    XBAGS_DECL_REDUCE(unsigned long, ulong, max)
    XBAGS_DECL_REDUCE(long, long, max)
    XBAGS_DECL_REDUCE(unsigned long long, ulonglong, max)
    XBAGS_DECL_REDUCE(long long, longlong, max)
    XBAGS_DECL_REDUCE(uint8_t, uint8, max)
    XBAGS_DECL_REDUCE(int8_t, int8, max)
    XBAGS_DECL_REDUCE(uint16_t, uint16, max)
    XBAGS_DECL_REDUCE(int16_t, int16, max)
    XBAGS_DECL_REDUCE(uint32_t, uint32, max)
    XBAGS_DECL_REDUCE(int32_t, int32, max)
    XBAGS_DECL_REDUCE(uint64_t, uint64, max)
    XBAGS_DECL_REDUCE(int64_t, int64, max)
    XBAGS_DECL_REDUCE(size_t, size, max)
    XBAGS_DECL_REDUCE(ptrdiff_t, ptrdiff, max)
    //  XBAGS_DECL_REDUCE(long double, longdouble, max)

    /* Min */
    XBAGS_DECL_REDUCE(float, float, min)
    XBAGS_DECL_REDUCE(double, double, min)
    XBAGS_DECL_REDUCE(char, char, min)
    XBAGS_DECL_REDUCE(unsigned char, uchar, min)
    XBAGS_DECL_REDUCE(signed char, schar, min)
    XBAGS_DECL_REDUCE(unsigned short, ushort, min)
    XBAGS_DECL_REDUCE(short, short, min)
    XBAGS_DECL_REDUCE(unsigned int, uint, min)
    XBAGS_DECL_REDUCE(int, int, min)
    XBAGS_DECL_REDUCE(unsigned long, ulong, min)
    XBAGS_DECL_REDUCE(long, long, min)
    XBAGS_DECL_REDUCE(unsigned long long, ulonglong, min)
    XBAGS_DECL_REDUCE(long long, longlong, min)
    XBAGS_DECL_REDUCE(uint8_t, uint8, min)
    XBAGS_DECL_REDUCE(int8_t, int8, min)
    XBAGS_DECL_REDUCE(uint16_t, uint16, min)
    XBAGS_DECL_REDUCE(int16_t, int16, min)
    XBAGS_DECL_REDUCE(uint32_t, uint32, min)
    XBAGS_DECL_REDUCE(int32_t, int32, min)
    XBAGS_DECL_REDUCE(uint64_t, uint64, min)
    XBAGS_DECL_REDUCE(int64_t, int64, min)
    XBAGS_DECL_REDUCE(size_t, size, min)
    XBAGS_DECL_REDUCE(ptrdiff_t, ptrdiff, min)
    //  XBAGS_DECL_REDUCE(long double, longdouble, min)

#undef XBAGS_DECL_REDUCE

/*!   \fn xbrtime_TYPENAME_scatter( TYPE *dest, TYPE *src, int *pe_msg_sz, int *pe_disp, size_t nelems, int root )
      \brief Independently distributes values of type TYPE located contiguously on root to each PE
      \param dest is a pointer to the base shared address on each PE where scattered values are to be stored
      \param src is a pointer to the base shared address on the root PE where values to be scattered are initially located
      \param pe_msg_sz is a pointer to an array containing the number of elements to be scattered to each PE (indexed by PE id)
      \param pe_disp is a pointer to an array containg index offsets (from src) at which each PE's messages are initially stored (indexed by PE id)
      \param nelems is the total number of elements to be scattered from the root PE
      \param root is the PE id of the root PE
      \return void
*/
#define XBGAS_DECL_SCATTER(_type, _typename)                                                                      \
void xbrtime_##_typename##_scatter(_type *dest, const _type *src, int *pe_msg_sz, int *pe_disp, size_t nelems, int root);

    XBGAS_DECL_SCATTER(float, float)
    XBGAS_DECL_SCATTER(double, double)
    XBGAS_DECL_SCATTER(char, char)
    XBGAS_DECL_SCATTER(unsigned char, uchar)
    XBGAS_DECL_SCATTER(signed char, schar)
    XBGAS_DECL_SCATTER(unsigned short, ushort)
    XBGAS_DECL_SCATTER(short, short)
    XBGAS_DECL_SCATTER(unsigned int, uint)
    XBGAS_DECL_SCATTER(int, int)
    XBGAS_DECL_SCATTER(unsigned long, ulong)
    XBGAS_DECL_SCATTER(long, long)
    XBGAS_DECL_SCATTER(unsigned long long, ulonglong)
    XBGAS_DECL_SCATTER(long long, longlong)
    XBGAS_DECL_SCATTER(uint8_t, uint8)
    XBGAS_DECL_SCATTER(int8_t, int8)
    XBGAS_DECL_SCATTER(uint16_t, uint16)
    XBGAS_DECL_SCATTER(int16_t, int16)
    XBGAS_DECL_SCATTER(uint32_t, uint32)
    XBGAS_DECL_SCATTER(int32_t, int32)
    XBGAS_DECL_SCATTER(uint64_t, uint64)
    XBGAS_DECL_SCATTER(int64_t, int64)
    XBGAS_DECL_SCATTER(size_t, size)
    XBGAS_DECL_SCATTER(ptrdiff_t, ptrdiff)
    //  XBGAS_DECL_SCATTER(long double, longdouble)

#undef XBGAS_DECL_SCATTER

/*!   \fn xbrtime_TYPENAME_gather( TYPE *dest, TYPE *src, int *pe_msg_sz, int *pe_disp, size_t nelems, int root )
      \brief Collects disparate values of type TYPE from each PE and stores contiguously on root
      \param dest is a pointer to the base shared address on root where gathered values are to be stored
      \param src is a pointer to the base shared address on each PE where values to be gathered are initially located
      \param pe_msg_sz is a pointer to an array containing the number of elements to be gathered from each PE (indexed by PE id)
      \param pe_disp is a pointer to an array containg index offsets (from dest) at which each PE's messages are to be stored on root (indexed by PE id)
      \param nelems is the total number of elements to be gathered to the root PE
      \param root is the PE id of the root PE
      \return void
*/
#define XBGAS_DECL_GATHER(_type, _typename)                                                                       \
void xbrtime_##_typename##_gather(_type *dest, const _type *src, int *pe_msg_sz, int *pe_disp, size_t nelems, int root);

    XBGAS_DECL_GATHER(float, float)
    XBGAS_DECL_GATHER(double, double)
    XBGAS_DECL_GATHER(char, char)
    XBGAS_DECL_GATHER(unsigned char, uchar)
    XBGAS_DECL_GATHER(signed char, schar)
    XBGAS_DECL_GATHER(unsigned short, ushort)
    XBGAS_DECL_GATHER(short, short)
    XBGAS_DECL_GATHER(unsigned int, uint)
    XBGAS_DECL_GATHER(int, int)
    XBGAS_DECL_GATHER(unsigned long, ulong)
    XBGAS_DECL_GATHER(long, long)
    XBGAS_DECL_GATHER(unsigned long long, ulonglong)
    XBGAS_DECL_GATHER(long long, longlong)
    XBGAS_DECL_GATHER(uint8_t, uint8)
    XBGAS_DECL_GATHER(int8_t, int8)
    XBGAS_DECL_GATHER(uint16_t, uint16)
    XBGAS_DECL_GATHER(int16_t, int16)
    XBGAS_DECL_GATHER(uint32_t, uint32)
    XBGAS_DECL_GATHER(int32_t, int32)
    XBGAS_DECL_GATHER(uint64_t, uint64)
    XBGAS_DECL_GATHER(int64_t, int64)
    XBGAS_DECL_GATHER(size_t, size)
    XBGAS_DECL_GATHER(ptrdiff_t, ptrdiff)
    //  XBGAS_DECL_GATHER(long double, longdouble)

#undef XBGAS_DECL_GATHER

/*!   \fn xbrtime_TYPENAME_alltoall( TYPE *dest, TYPE *src, ptrdiff_t src_stride, ptrdiff_t dest_stride, size_t nelems)
      \brief Performs a personalized all-to-all exchange of values of type TYPE between PEs
      \param dest is a pointer to the base shared address on each PE where exchanged values are to be stored (indexed by PE id)
      \param src is a pointer to the base shared address on each PE where values to be exchanged are initially located (indexed by PE id)
      \param src_stride is the stride size between elements at src
      \param dest_stride is the stride size between elements at dest
      \param nelems is the total number of elements to be exchanged by each PE
      \return void
*/
#define XBGAS_DECL_ALLTOALL(_type, _typename)                                                                       \
void xbrtime_##_typename##_alltoall(_type *dest, const _type *src, int src_stride, int dest_stride, size_t nelems);

    XBGAS_DECL_ALLTOALL(float, float)
    XBGAS_DECL_ALLTOALL(double, double)
    XBGAS_DECL_ALLTOALL(char, char)
    XBGAS_DECL_ALLTOALL(unsigned char, uchar)
    XBGAS_DECL_ALLTOALL(signed char, schar)
    XBGAS_DECL_ALLTOALL(unsigned short, ushort)
    XBGAS_DECL_ALLTOALL(short, short)
    XBGAS_DECL_ALLTOALL(unsigned int, uint)
    XBGAS_DECL_ALLTOALL(int, int)
    XBGAS_DECL_ALLTOALL(unsigned long, ulong)
    XBGAS_DECL_ALLTOALL(long, long)
    XBGAS_DECL_ALLTOALL(unsigned long long, ulonglong)
    XBGAS_DECL_ALLTOALL(long long, longlong)
    XBGAS_DECL_ALLTOALL(uint8_t, uint8)
    XBGAS_DECL_ALLTOALL(int8_t, int8)
    XBGAS_DECL_ALLTOALL(uint16_t, uint16)
    XBGAS_DECL_ALLTOALL(int16_t, int16)
    XBGAS_DECL_ALLTOALL(uint32_t, uint32)
    XBGAS_DECL_ALLTOALL(int32_t, int32)
    XBGAS_DECL_ALLTOALL(uint64_t, uint64)
    XBGAS_DECL_ALLTOALL(int64_t, int64)
    XBGAS_DECL_ALLTOALL(size_t, size)
    XBGAS_DECL_ALLTOALL(ptrdiff_t, ptrdiff)
    //  XBGAS_DECL_ALLTOALL(long double, longdouble)

#undef XBGAS_DECL_ALLTOALL

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif /* _XBRTIME_COLLECTIVES_H_ */

/* EOF */
