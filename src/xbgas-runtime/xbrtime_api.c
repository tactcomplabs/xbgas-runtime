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
#include <inttypes.h>

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
uint32_t xbrtime_decode_pe( int pe );
uint64_t __xbrtime_ltor(uint64_t remote,int pe);



void xbrtime_float_put(float *dest, const float *src,
                     size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_u4_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(float)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_u4_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(float)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_float_put_nb(float *dest, const float *src,
                        size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_u4_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(float)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_u4_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(float)));
  }
}

void xbrtime_double_put(double *dest, const double *src,
                      size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_u8_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(double)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_u8_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(double)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_double_put_nb(double *dest, const double *src,
                         size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_u8_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(double)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_u8_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(double)));
  }
}

void xbrtime_longdouble_put(long double *dest, const long double *src,
                          size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_u8_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(long double)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_u8_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(long double)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_longdouble_put_nb(long double *dest, const long double *src,
                             size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_u8_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(long double)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_u8_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(long double)));
  }
}

void xbrtime_schar_put(signed char *dest, const signed char *src,
                     size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_s1_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(signed char)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_s1_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(signed char)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_schar_put_nb(signed char *dest, const signed char *src,
                        size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_s1_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(signed char)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_s1_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(signed char)));
  }
}

void xbrtime_char_put(char *dest, const char *src,
                    size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_u1_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(char)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_u1_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(char)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_char_put_nb(char *dest, const char *src,
                       size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_u1_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(char)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_u1_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(char)));
  }
}

void xbrtime_short_put(short *dest, const short *src,
                     size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_s2_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(short)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_s2_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(short)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_short_put_nb(short *dest, const short *src,
                        size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_s2_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(short)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_s2_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(short)));
  }
}

void xbrtime_int_put(int *dest, const int *src,
                   size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_s4_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(int)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_s4_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_int_put_nb(int *dest, const int *src,
                      size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_s4_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(int)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_s4_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int)));
  }
}

void xbrtime_long_put(long *dest, const long *src,
                    size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_s4_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(long)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_s4_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(long)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_long_put_nb(long *dest, const long *src,
                       size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_s4_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(long)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_s4_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(long)));
  }
}

void xbrtime_longlong_put(long long *dest, const long long *src,
                        size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_s8_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(long long)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_s8_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(long long)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_longlong_put_nb(long long *dest, const long long *src,
                           size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_s8_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(long long)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_s8_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(long long)));
  }
}

void xbrtime_uchar_put(unsigned char *dest, const unsigned char *src,
                     size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_u1_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(unsigned char)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_u1_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned char)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_uchar_put_nb(unsigned char *dest, const unsigned char *src,
                        size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_u1_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(unsigned char)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_u1_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned char)));
  }
}

void xbrtime_ushort_put(unsigned short *dest, const unsigned short *src,
                      size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_u2_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(unsigned short)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_u2_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned short)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_ushort_put_nb(unsigned short *dest, const unsigned short *src,
                         size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_u2_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(unsigned short)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_u2_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned short)));
  }
}

void xbrtime_uint_put(unsigned int *dest, const unsigned int *src,
                    size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_u4_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(unsigned int)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_u4_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned int)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_uint_put_nb(unsigned int *dest, const unsigned int *src,
                       size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_u4_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(unsigned int)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_u4_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned int)));
  }
}

void xbrtime_ulong_put(unsigned long *dest, const unsigned long *src,
                     size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_u4_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(unsigned long)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_u4_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned long)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_ulong_put_nb(unsigned long *dest, const unsigned long *src,
                        size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_u4_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(unsigned long)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_u4_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned long)));
  }
}

void xbrtime_ulonglong_put(unsigned long long *dest, const unsigned long long *src,
                         size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_u8_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(unsigned long long)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_u8_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned long long)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_ulonglong_put_nb(unsigned long long *dest, const unsigned long long *src,
                            size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_u8_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(unsigned long long)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_u8_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned long long)));
  }
}

void xbrtime_int8_put(int8_t *dest, const int8_t *src,
                    size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_s1_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(int8_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_s1_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int8_t)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_int8_put_nb(int8_t *dest, const int8_t *src,
                       size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_s1_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(int8_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_s1_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int8_t)));
  }
}

void xbrtime_int16_put(int16_t *dest, const int16_t *src,
                     size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_s2_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(int16_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_s2_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int16_t)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_int16_put_nb(int16_t *dest, const int16_t *src,
                        size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_s2_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(int16_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_s2_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int16_t)));
  }
}

void xbrtime_int32_put(int32_t *dest, const int32_t *src,
                     size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_s4_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(int32_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_s4_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int32_t)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_int32_put_nb(int32_t *dest, const int32_t *src,
                        size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_s4_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(int32_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_s4_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int32_t)));
  }
}

void xbrtime_int64_put(int64_t *dest, const int64_t *src,
                     size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_s8_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(int64_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_s8_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int64_t)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_int64_put_nb(int64_t *dest, const int64_t *src,
                        size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_s8_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(int64_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_s8_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int64_t)));
  }
}

void xbrtime_uint8_put(uint8_t *dest, const uint8_t *src,
                     size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_u1_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(uint8_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_u1_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint8_t)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_uint8_put_nb(uint8_t *dest, const uint8_t *src,
                        size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_u1_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(uint8_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_u1_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint8_t)));
  }
}

void xbrtime_uint16_put(uint16_t *dest, const uint16_t *src,
                      size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_u2_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(uint16_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_u2_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint16_t)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_uint16_put_nb(uint16_t *dest, const uint16_t *src,
                         size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_u2_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(uint16_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_u2_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint16_t)));
  }
}

void xbrtime_uint32_put(uint32_t *dest, const uint32_t *src,
                      size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_u4_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(uint32_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_u4_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint32_t)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_uint32_put_nb(uint32_t *dest, const uint32_t *src,
                         size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_u4_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(uint32_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_u4_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint32_t)));
  }
}

void xbrtime_uint64_put(uint64_t *dest, const uint64_t *src,
                      size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_u8_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(uint64_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_u8_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint64_t)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_uint64_put_nb(uint64_t *dest, const uint64_t *src,
                         size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_u8_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(uint64_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_u8_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint64_t)));
  }
}

void xbrtime_size_put(size_t *dest, const size_t *src,
                    size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_u4_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(size_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_u4_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(size_t)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_size_put_nb(size_t *dest, const size_t *src,
                       size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_u4_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(size_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_u4_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(size_t)));
  }
}

void xbrtime_ptrdiff_put(ptrdiff_t *dest, const ptrdiff_t *src,
                       size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_s4_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(ptrdiff_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_s4_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(ptrdiff_t)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_ptrdiff_put_nb(ptrdiff_t *dest, const ptrdiff_t *src,
                          size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_put_s4_unr((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(ptrdiff_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_put_s4_seq((uint64_t)(src),
                         __xbrtime_ltor((uint64_t)(dest),pe),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(ptrdiff_t)));
  }
}

void xbrtime_float_get(float *dest, const float *src,
                     size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_u4_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(float)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_u4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(float)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_float_get_nb(float *dest, const float *src,
                        size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_u4_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(float)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_u4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(float)));
  }
}

void xbrtime_double_get(double *dest, const double *src,
                      size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_u8_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(double)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_u8_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(double)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_double_get_nb(double *dest, const double *src,
                         size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_u8_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(double)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_u8_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(double)));
  }
}

void xbrtime_longdouble_get(long double *dest, const long double *src,
                          size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_u8_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(long double)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_u8_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(long double)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_longdouble_get_nb(long double *dest, const long double *src,
                             size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_u8_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(long double)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_u8_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(long double)));
  }
}

void xbrtime_schar_get(signed char *dest, const signed char *src,
                     size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_s1_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(signed char)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_s1_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(signed char)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_schar_get_nb(signed char *dest, const signed char *src,
                        size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_s1_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(signed char)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_s1_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(signed char)));
  }
}

void xbrtime_char_get(char *dest, const char *src,
                    size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_u1_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(char)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_u1_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(char)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_char_get_nb(char *dest, const char *src,
                       size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_u1_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(char)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_u1_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(char)));
  }
}

void xbrtime_short_get(short *dest, const short *src,
                     size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_s2_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(short)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_s2_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(short)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_short_get_nb(short *dest, const short *src,
                        size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_s2_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(short)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_s2_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(short)));
  }
}

void xbrtime_int_get(int *dest, const int *src,
                   size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_s4_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(int)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_s4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_int_get_nb(int *dest, const int *src,
                      size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_s4_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(int)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_s4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int)));
  }
}

void xbrtime_long_get(long *dest, const long *src,
                    size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_s4_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(long)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_s4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(long)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_long_get_nb(long *dest, const long *src,
                       size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_s4_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(long)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_s4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(long)));
  }
}

void xbrtime_longlong_get(long long *dest, const long long *src,
                        size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_s8_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(long long)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_s8_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(long long)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_longlong_get_nb(long long *dest, const long long *src,
                           size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_s8_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(long long)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_s8_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(long long)));
  }
}

void xbrtime_uchar_get(unsigned char *dest, const unsigned char *src,
                     size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_u1_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(unsigned char)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_u1_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned char)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_uchar_get_nb(unsigned char *dest, const unsigned char *src,
                        size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_u1_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(unsigned char)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_u1_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned char)));
  }
}

void xbrtime_ushort_get(unsigned short *dest, const unsigned short *src,
                      size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_u2_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(unsigned short)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_u2_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned short)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_ushort_get_nb(unsigned short *dest, const unsigned short *src,
                         size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_u2_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(unsigned short)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_u2_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned short)));
  }
}

void xbrtime_uint_get(unsigned int *dest, const unsigned int *src,
                    size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_u4_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(unsigned int)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_u4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned int)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_uint_get_nb(unsigned int *dest, const unsigned int *src,
                       size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_u4_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(unsigned int)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_u4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned int)));
  }
}

void xbrtime_ulong_get(unsigned long *dest, const unsigned long *src,
                     size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_u4_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(unsigned long)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_u4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned long)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_ulong_get_nb(unsigned long *dest, const unsigned long *src,
                        size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_u4_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(unsigned long)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_u4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned long)));
  }
}

void xbrtime_ulonglong_get(unsigned long long *dest, const unsigned long long *src,
                         size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_u8_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(unsigned long long)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_u8_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned long long)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_ulonglong_get_nb(unsigned long long *dest, const unsigned long long *src,
                            size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_u8_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(unsigned long long)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_u8_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned long long)));
  }
}

void xbrtime_int8_get(int8_t *dest, const int8_t *src,
                    size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_s1_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(int8_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_s1_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int8_t)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_int8_get_nb(int8_t *dest, const int8_t *src,
                       size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_s1_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(int8_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_s1_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int8_t)));
  }
}

void xbrtime_int16_get(int16_t *dest, const int16_t *src,
                     size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_s2_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(int16_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_s2_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int16_t)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_int16_get_nb(int16_t *dest, const int16_t *src,
                        size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_s2_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(int16_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_s2_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int16_t)));
  }
}

void xbrtime_int32_get(int32_t *dest, const int32_t *src,
                     size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_s4_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(int32_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_s4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int32_t)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_int32_get_nb(int32_t *dest, const int32_t *src,
                        size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_s4_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(int32_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_s4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int32_t)));
  }
}

void xbrtime_int64_get(int64_t *dest, const int64_t *src,
                     size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_s8_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(int64_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_s8_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int64_t)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_int64_get_nb(int64_t *dest, const int64_t *src,
                        size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_s8_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(int64_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_s8_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int64_t)));
  }
}

void xbrtime_uint8_get(uint8_t *dest, const uint8_t *src,
                     size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_u1_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(uint8_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_u1_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint8_t)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_uint8_get_nb(uint8_t *dest, const uint8_t *src,
                        size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_u1_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(uint8_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_u1_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint8_t)));
  }
}

void xbrtime_uint16_get(uint16_t *dest, const uint16_t *src,
                      size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_u2_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(uint16_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_u2_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint16_t)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_uint16_get_nb(uint16_t *dest, const uint16_t *src,
                         size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_u2_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(uint16_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_u2_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint16_t)));
  }
}

void xbrtime_uint32_get(uint32_t *dest, const uint32_t *src,
                      size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_u4_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(uint32_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_u4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint32_t)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_uint32_get_nb(uint32_t *dest, const uint32_t *src,
                         size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_u4_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(uint32_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_u4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint32_t)));
  }
}

void xbrtime_uint64_get(uint64_t *dest, const uint64_t *src,
                      size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_u8_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(uint64_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_u8_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint64_t)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_uint64_get_nb(uint64_t *dest, const uint64_t *src,
                         size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_u8_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(uint64_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_u8_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint64_t)));
  }
}

void xbrtime_size_get(size_t *dest, const size_t *src,
                    size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_u4_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(size_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_u4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(size_t)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_size_get_nb(size_t *dest, const size_t *src,
                       size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_u4_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(size_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_u4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(size_t)));
  }
}

void xbrtime_ptrdiff_get(ptrdiff_t *dest, const ptrdiff_t *src,
                       size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_s4_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(ptrdiff_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_s4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(ptrdiff_t)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_ptrdiff_get_nb(ptrdiff_t *dest, const ptrdiff_t *src,
                          size_t nelems, int stride, int pe){
  uint32_t loop_iters     = 0;
  uint32_t epilogue_iters = 0;
  if( nelems >= _XBRTIME_MIN_UNR_THRESHOLD_ ){
    /* unrolled execution */
    loop_iters = nelems/(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    epilogue_iters = nelems%(uint32_t)(_XBRTIME_UNROLL_FACTOR_);
    __xbrtime_get_s4_unr(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(stride*sizeof(ptrdiff_t)),
                         loop_iters,
                         epilogue_iters);
  }else{
    /* sequential execution */
    __xbrtime_get_s4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest),
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(ptrdiff_t)));
  }
}

/* EOF */
