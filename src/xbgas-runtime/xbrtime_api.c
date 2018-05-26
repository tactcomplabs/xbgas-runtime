/*
 * _XBRTIME_API_C_
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

#include "xbrtime.h"

/* ------------------------------------------------- FUNCTION PROTOTYPES */
void __xbrtime_asm_fence();
void __xbrtime_asm_quiet_fence();

void __xbrtime_get_u1_seq( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t nelems, uint32_t stride );
void __xbrtime_get_u1_unr( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t stride, uint32_t loop_iters,
                           uint32_t epilogue_iters);
void __xbrtime_get_u2_seq( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t nelems, uint32_t stride );
void __xbrtime_get_u2_unr( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t stride, uint32_t loop_iters,
                           uint32_t epilogue_iters);
void __xbrtime_get_u4_seq( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t nelems, uint32_t stride );
void __xbrtime_get_u4_unr( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t stride, uint32_t loop_iters,
                           uint32_t epilogue_iters);
void __xbrtime_get_u8_seq( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t nelems, uint32_t stride );
void __xbrtime_get_u8_unr( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t stride, uint32_t loop_iters,
                           uint32_t epilogue_iters);
void __xbrtime_get_s1_seq( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t nelems, uint32_t stride );
void __xbrtime_get_s1_unr( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t stride, uint32_t loop_iters,
                           uint32_t epilogue_iters);
void __xbrtime_get_s2_seq( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t nelems, uint32_t stride );
void __xbrtime_get_s2_unr( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t stride, uint32_t loop_iters,
                           uint32_t epilogue_iters);
void __xbrtime_get_s4_seq( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t nelems, uint32_t stride );
void __xbrtime_get_s4_unr( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t stride, uint32_t loop_iters,
                           uint32_t epilogue_iters);
void __xbrtime_get_s8_seq( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t nelems, uint32_t stride );
void __xbrtime_get_s8_unr( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t stride, uint32_t loop_iters,
                           uint32_t epilogue_iters);
void __xbrtime_put_u1_seq( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t nelems, uint32_t stride );
void __xbrtime_put_u1_unr( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t stride, uint32_t loop_iters,
                           uint32_t epilogue_iters);
void __xbrtime_put_u2_seq( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t nelems, uint32_t stride );
void __xbrtime_put_u2_unr( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t stride, uint32_t loop_iters,
                           uint32_t epilogue_iters);
void __xbrtime_put_u4_seq( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t nelems, uint32_t stride );
void __xbrtime_put_u4_unr( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t stride, uint32_t loop_iters,
                           uint32_t epilogue_iters);
void __xbrtime_put_u8_seq( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t nelems, uint32_t stride );
void __xbrtime_put_u8_unr( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t stride, uint32_t loop_iters,
                           uint32_t epilogue_iters);
void __xbrtime_put_s1_seq( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t nelems, uint32_t stride );
void __xbrtime_put_s1_unr( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t stride, uint32_t loop_iters,
                           uint32_t epilogue_iters);
void __xbrtime_put_s2_seq( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t nelems, uint32_t stride );
void __xbrtime_put_s2_unr( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t stride, uint32_t loop_iters,
                           uint32_t epilogue_iters);
void __xbrtime_put_s4_seq( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t nelems, uint32_t stride );
void __xbrtime_put_s4_unr( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t stride, uint32_t loop_iters,
                           uint32_t epilogue_iters);
void __xbrtime_put_s8_seq( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t nelems, uint32_t stride );
void __xbrtime_put_s8_unr( uint64_t base_src, uint64_t base_dest, uint32_t pe,
                           uint32_t stride, uint32_t loop_iters,
                           uint32_t epilogue_iters);



void xbgas_float_put(float *dest, const float *src,
                     size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_float_put_nb(float *dest, const float *src,
                        size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_double_put(double *dest, const double *src,
                      size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_double_put_nb(double *dest, const double *src,
                         size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_longdouble_put(long double *dest, const long double *src,
                          size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_longdouble_put_nb(long double *dest, const long double *src,
                             size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_schar_put(signed char *dest, const signed char *src,
                     size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_schar_put_nb(signed char *dest, const signed char *src,
                        size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_char_put(char *dest, const char *src,
                    size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_char_put_nb(char *dest, const char *src,
                       size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_short_put(short *dest, const short *src,
                     size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_short_put_nb(short *dest, const short *src,
                        size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_int_put(int *dest, const int *src,
                   size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_int_put_nb(int *dest, const int *src,
                      size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_long_put(long *dest, const long *src,
                    size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_long_put_nb(long *dest, const long *src,
                       size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_longlong_put(long long *dest, const long long *src,
                        size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_longlong_put_nb(long long *dest, const long long *src,
                           size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_uchar_put(unsigned char *dest, const unsigned char *src,
                     size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_uchar_put_nb(unsigned char *dest, const unsigned char *src,
                        size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_ushort_put(unsigned short *dest, const unsigned short *src,
                      size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_ushort_put_nb(unsigned short *dest, const unsigned short *src,
                         size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_uint_put(unsigned int *dest, const unsigned int *src,
                    size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_uint_put_nb(unsigned int *dest, const unsigned int *src,
                       size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_ulong_put(unsigned long *dest, const unsigned long *src,
                     size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_ulong_put_nb(unsigned long *dest, const unsigned long *src,
                        size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_ulonglong_put(unsigned long long *dest, const unsigned long long *src,
                         size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_ulonglong_put_nb(unsigned long long *dest, const unsigned long long *src,
                            size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_int8_put(int8_t *dest, const int8_t *src,
                    size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_int8_put_nb(int8_t *dest, const int8_t *src,
                       size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_int16_put(int16_t *dest, const int16_t *src,
                     size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_int16_put_nb(int16_t *dest, const int16_t *src,
                        size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_int32_put(int32_t *dest, const int32_t *src,
                     size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_int32_put_nb(int32_t *dest, const int32_t *src,
                        size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_int64_put(int64_t *dest, const int64_t *src,
                     size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_int64_put_nb(int64_t *dest, const int64_t *src,
                        size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_uint8_put(uint8_t *dest, const uint8_t *src,
                     size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_uint8_put_nb(uint8_t *dest, const uint8_t *src,
                        size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_uint16_put(uint16_t *dest, const uint16_t *src,
                      size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_uint16_put_nb(uint16_t *dest, const uint16_t *src,
                         size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_uint32_put(uint32_t *dest, const uint32_t *src,
                      size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_uint32_put_nb(uint32_t *dest, const uint32_t *src,
                         size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_uint64_put(uint64_t *dest, const uint64_t *src,
                      size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_uint64_put_nb(uint64_t *dest, const uint64_t *src,
                         size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_size_put(size_t *dest, const size_t *src,
                    size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_size_put_nb(size_t *dest, const size_t *src,
                       size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_ptrdiff_put(ptrdiff_t *dest, const ptrdiff_t *src,
                       size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_ptrdiff_put_nb(ptrdiff_t *dest, const ptrdiff_t *src,
                          size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_float_get(float *dest, const float *src,
                     size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_float_get_nb(float *dest, const float *src,
                        size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_double_get(double *dest, const double *src,
                      size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_double_get_nb(double *dest, const double *src,
                         size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_longdouble_get(long double *dest, const long double *src,
                          size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_longdouble_get_nb(long double *dest, const long double *src,
                             size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_schar_get(signed char *dest, const signed char *src,
                     size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_schar_get_nb(signed char *dest, const signed char *src,
                        size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_char_get(char *dest, const char *src,
                    size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_char_get_nb(char *dest, const char *src,
                       size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_short_get(short *dest, const short *src,
                     size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_short_get_nb(short *dest, const short *src,
                        size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_int_get(int *dest, const int *src,
                   size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_int_get_nb(int *dest, const int *src,
                      size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_long_get(long *dest, const long *src,
                    size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_long_get_nb(long *dest, const long *src,
                       size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_longlong_get(long long *dest, const long long *src,
                        size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_longlong_get_nb(long long *dest, const long long *src,
                           size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_uchar_get(unsigned char *dest, const unsigned char *src,
                     size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_uchar_get_nb(unsigned char *dest, const unsigned char *src,
                        size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_ushort_get(unsigned short *dest, const unsigned short *src,
                      size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_ushort_get_nb(unsigned short *dest, const unsigned short *src,
                         size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_uint_get(unsigned int *dest, const unsigned int *src,
                    size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_uint_get_nb(unsigned int *dest, const unsigned int *src,
                       size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_ulong_get(unsigned long *dest, const unsigned long *src,
                     size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_ulong_get_nb(unsigned long *dest, const unsigned long *src,
                        size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_ulonglong_get(unsigned long long *dest, const unsigned long long *src,
                         size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_ulonglong_get_nb(unsigned long long *dest, const unsigned long long *src,
                            size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_int8_get(int8_t *dest, const int8_t *src,
                    size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_int8_get_nb(int8_t *dest, const int8_t *src,
                       size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_int16_get(int16_t *dest, const int16_t *src,
                     size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_int16_get_nb(int16_t *dest, const int16_t *src,
                        size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_int32_get(int32_t *dest, const int32_t *src,
                     size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_int32_get_nb(int32_t *dest, const int32_t *src,
                        size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_int64_get(int64_t *dest, const int64_t *src,
                     size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_int64_get_nb(int64_t *dest, const int64_t *src,
                        size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_uint8_get(uint8_t *dest, const uint8_t *src,
                     size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_uint8_get_nb(uint8_t *dest, const uint8_t *src,
                        size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_uint16_get(uint16_t *dest, const uint16_t *src,
                      size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_uint16_get_nb(uint16_t *dest, const uint16_t *src,
                         size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_uint32_get(uint32_t *dest, const uint32_t *src,
                      size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_uint32_get_nb(uint32_t *dest, const uint32_t *src,
                         size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_uint64_get(uint64_t *dest, const uint64_t *src,
                      size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_uint64_get_nb(uint64_t *dest, const uint64_t *src,
                         size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_size_get(size_t *dest, const size_t *src,
                    size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_size_get_nb(size_t *dest, const size_t *src,
                       size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

void xbgas_ptrdiff_get(ptrdiff_t *dest, const ptrdiff_t *src,
                       size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
  __xbrtime_asm_fence();
}

void xbgas_ptrdiff_get_nb(ptrdiff_t *dest, const ptrdiff_t *src,
                          size_t nelems, int stride, int pe){
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
  }else{
    /* sequential execution */
  }
}

/* EOF */
