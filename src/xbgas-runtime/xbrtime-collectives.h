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
    XBGAS_DECL_REDUCE(double, double, sum)
    XBGAS_DECL_REDUCE(char, char, sum)
    XBGAS_DECL_REDUCE(unsigned char, uchar, sum)
    XBGAS_DECL_REDUCE(signed char, schar, sum)
    XBGAS_DECL_REDUCE(unsigned short, ushort, sum)
    XBGAS_DECL_REDUCE(short, short, sum)
    XBGAS_DECL_REDUCE(unsigned int, uint, sum)
    XBGAS_DECL_REDUCE(int, int, sum)
    XBGAS_DECL_REDUCE(unsigned long, ulong, sum)
    XBGAS_DECL_REDUCE(long, long, sum)
    XBGAS_DECL_REDUCE(unsigned long long, ulonglong, sum)
    XBGAS_DECL_REDUCE(long long, longlong, sum)
    XBGAS_DECL_REDUCE(uint8_t, uint8, sum)
    XBGAS_DECL_REDUCE(int8_t, int8, sum)
    XBGAS_DECL_REDUCE(uint16_t, uint16, sum)
    XBGAS_DECL_REDUCE(int16_t, int16, sum)
    XBGAS_DECL_REDUCE(uint32_t, uint32, sum)
    XBGAS_DECL_REDUCE(int32_t, int32, sum)
    XBGAS_DECL_REDUCE(uint64_t, uint64, sum)
    XBGAS_DECL_REDUCE(int64_t, int64, sum)
    XBGAS_DECL_REDUCE(size_t, size, sum)
    XBGAS_DECL_REDUCE(ptrdiff_t, ptrdiff, sum)
    //  XBGAS_DECL_REDUCE(long double, longdouble, sum)

    /* Product */
    XBGAS_DECL_REDUCE(float, float, product)
    XBGAS_DECL_REDUCE(double, double, product)
    XBGAS_DECL_REDUCE(char, char, product)
    XBGAS_DECL_REDUCE(unsigned char, uchar, product)
    XBGAS_DECL_REDUCE(signed char, schar, product)
    XBGAS_DECL_REDUCE(unsigned short, ushort, product)
    XBGAS_DECL_REDUCE(short, short, product)
    XBGAS_DECL_REDUCE(unsigned int, uint, product)
    XBGAS_DECL_REDUCE(int, int, product)
    XBGAS_DECL_REDUCE(unsigned long, ulong, product)
    XBGAS_DECL_REDUCE(long, long, product)
    XBGAS_DECL_REDUCE(unsigned long long, ulonglong, product)
    XBGAS_DECL_REDUCE(long long, longlong, product)
    XBGAS_DECL_REDUCE(uint8_t, uint8, product)
    XBGAS_DECL_REDUCE(int8_t, int8, product)
    XBGAS_DECL_REDUCE(uint16_t, uint16, product)
    XBGAS_DECL_REDUCE(int16_t, int16, product)
    XBGAS_DECL_REDUCE(uint32_t, uint32, product)
    XBGAS_DECL_REDUCE(int32_t, int32, product)
    XBGAS_DECL_REDUCE(uint64_t, uint64, product)
    XBGAS_DECL_REDUCE(int64_t, int64, product)
    XBGAS_DECL_REDUCE(size_t, size, product)
    XBGAS_DECL_REDUCE(ptrdiff_t, ptrdiff, product)
    //  XBGAS_DECL_REDUCE(long double, longdouble, product)

    /* Binary AND */
    XBGAS_DECL_REDUCE(char, char, and)
    XBGAS_DECL_REDUCE(unsigned char, uchar, and)
    XBGAS_DECL_REDUCE(signed char, schar, and)
    XBGAS_DECL_REDUCE(unsigned short, ushort, and)
    XBGAS_DECL_REDUCE(short, short, and)
    XBGAS_DECL_REDUCE(unsigned int, uint, and)
    XBGAS_DECL_REDUCE(int, int, and)
    XBGAS_DECL_REDUCE(unsigned long, ulong, and)
    XBGAS_DECL_REDUCE(long, long, and)
    XBGAS_DECL_REDUCE(unsigned long long, ulonglong, and)
    XBGAS_DECL_REDUCE(long long, longlong, and)
    XBGAS_DECL_REDUCE(uint8_t, uint8, and)
    XBGAS_DECL_REDUCE(int8_t, int8, and)
    XBGAS_DECL_REDUCE(uint16_t, uint16, and)
    XBGAS_DECL_REDUCE(int16_t, int16, and)
    XBGAS_DECL_REDUCE(uint32_t, uint32, and)
    XBGAS_DECL_REDUCE(int32_t, int32, and)
    XBGAS_DECL_REDUCE(uint64_t, uint64, and)
    XBGAS_DECL_REDUCE(int64_t, int64, and)
    XBGAS_DECL_REDUCE(size_t, size, and)
    XBGAS_DECL_REDUCE(ptrdiff_t, ptrdiff, and)

    /* Binary OR */
    XBGAS_DECL_REDUCE(char, char, or)
    XBGAS_DECL_REDUCE(unsigned char, uchar, or)
    XBGAS_DECL_REDUCE(signed char, schar, or)
    XBGAS_DECL_REDUCE(unsigned short, ushort, or)
    XBGAS_DECL_REDUCE(short, short, or)
    XBGAS_DECL_REDUCE(unsigned int, uint, or)
    XBGAS_DECL_REDUCE(int, int, or)
    XBGAS_DECL_REDUCE(unsigned long, ulong, or)
    XBGAS_DECL_REDUCE(long, long, or)
    XBGAS_DECL_REDUCE(unsigned long long, ulonglong, or)
    XBGAS_DECL_REDUCE(long long, longlong, or)
    XBGAS_DECL_REDUCE(uint8_t, uint8, or)
    XBGAS_DECL_REDUCE(int8_t, int8, or)
    XBGAS_DECL_REDUCE(uint16_t, uint16, or)
    XBGAS_DECL_REDUCE(int16_t, int16, or)
    XBGAS_DECL_REDUCE(uint32_t, uint32, or)
    XBGAS_DECL_REDUCE(int32_t, int32, or)
    XBGAS_DECL_REDUCE(uint64_t, uint64, or)
    XBGAS_DECL_REDUCE(int64_t, int64, or)
    XBGAS_DECL_REDUCE(size_t, size, or)
    XBGAS_DECL_REDUCE(ptrdiff_t, ptrdiff, or)

    /* Binary XOR */
    XBGAS_DECL_REDUCE(char, char, xor)
    XBGAS_DECL_REDUCE(unsigned char, uchar, xor)
    XBGAS_DECL_REDUCE(signed char, schar, xor)
    XBGAS_DECL_REDUCE(unsigned short, ushort, xor)
    XBGAS_DECL_REDUCE(short, short, xor)
    XBGAS_DECL_REDUCE(unsigned int, uint, xor)
    XBGAS_DECL_REDUCE(int, int, xor)
    XBGAS_DECL_REDUCE(unsigned long, ulong, xor)
    XBGAS_DECL_REDUCE(long, long, xor)
    XBGAS_DECL_REDUCE(unsigned long long, ulonglong, xor)
    XBGAS_DECL_REDUCE(long long, longlong, xor)
    XBGAS_DECL_REDUCE(uint8_t, uint8, xor)
    XBGAS_DECL_REDUCE(int8_t, int8, xor)
    XBGAS_DECL_REDUCE(uint16_t, uint16, xor)
    XBGAS_DECL_REDUCE(int16_t, int16, xor)
    XBGAS_DECL_REDUCE(uint32_t, uint32, xor)
    XBGAS_DECL_REDUCE(int32_t, int32, xor)
    XBGAS_DECL_REDUCE(uint64_t, uint64, xor)
    XBGAS_DECL_REDUCE(int64_t, int64, xor)
    XBGAS_DECL_REDUCE(size_t, size, xor)
    XBGAS_DECL_REDUCE(ptrdiff_t, ptrdiff, xor)

    /* Max */
    XBGAS_DECL_REDUCE(float, float, max)
    XBGAS_DECL_REDUCE(double, double, max)
    XBGAS_DECL_REDUCE(char, char, max)
    XBGAS_DECL_REDUCE(unsigned char, uchar, max)
    XBGAS_DECL_REDUCE(signed char, schar, max)
    XBGAS_DECL_REDUCE(unsigned short, ushort, max)
    XBGAS_DECL_REDUCE(short, short, max)
    XBGAS_DECL_REDUCE(unsigned int, uint, max)
    XBGAS_DECL_REDUCE(int, int, max)
    XBGAS_DECL_REDUCE(unsigned long, ulong, max)
    XBGAS_DECL_REDUCE(long, long, max)
    XBGAS_DECL_REDUCE(unsigned long long, ulonglong, max)
    XBGAS_DECL_REDUCE(long long, longlong, max)
    XBGAS_DECL_REDUCE(uint8_t, uint8, max)
    XBGAS_DECL_REDUCE(int8_t, int8, max)
    XBGAS_DECL_REDUCE(uint16_t, uint16, max)
    XBGAS_DECL_REDUCE(int16_t, int16, max)
    XBGAS_DECL_REDUCE(uint32_t, uint32, max)
    XBGAS_DECL_REDUCE(int32_t, int32, max)
    XBGAS_DECL_REDUCE(uint64_t, uint64, max)
    XBGAS_DECL_REDUCE(int64_t, int64, max)
    XBGAS_DECL_REDUCE(size_t, size, max)
    XBGAS_DECL_REDUCE(ptrdiff_t, ptrdiff, max)
    //  XBGAS_DECL_REDUCE(long double, longdouble, max)

    /* Min */
    XBGAS_DECL_REDUCE(float, float, min)
    XBGAS_DECL_REDUCE(double, double, min)
    XBGAS_DECL_REDUCE(char, char, min)
    XBGAS_DECL_REDUCE(unsigned char, uchar, min)
    XBGAS_DECL_REDUCE(signed char, schar, min)
    XBGAS_DECL_REDUCE(unsigned short, ushort, min)
    XBGAS_DECL_REDUCE(short, short, min)
    XBGAS_DECL_REDUCE(unsigned int, uint, min)
    XBGAS_DECL_REDUCE(int, int, min)
    XBGAS_DECL_REDUCE(unsigned long, ulong, min)
    XBGAS_DECL_REDUCE(long, long, min)
    XBGAS_DECL_REDUCE(unsigned long long, ulonglong, min)
    XBGAS_DECL_REDUCE(long long, longlong, min)
    XBGAS_DECL_REDUCE(uint8_t, uint8, min)
    XBGAS_DECL_REDUCE(int8_t, int8, min)
    XBGAS_DECL_REDUCE(uint16_t, uint16, min)
    XBGAS_DECL_REDUCE(int16_t, int16, min)
    XBGAS_DECL_REDUCE(uint32_t, uint32, min)
    XBGAS_DECL_REDUCE(int32_t, int32, min)
    XBGAS_DECL_REDUCE(uint64_t, uint64, min)
    XBGAS_DECL_REDUCE(int64_t, int64, min)
    XBGAS_DECL_REDUCE(size_t, size, min)
    XBGAS_DECL_REDUCE(ptrdiff_t, ptrdiff, min)
    //  XBGAS_DECL_REDUCE(long double, longdouble, min)

#undef XBGAS_DECL_REDUCE

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
