void xbrtime_float_get(float *dest, const float *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_u4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(float)));
  }else{
    /* aggregate requests */
    __xbrtime_get_u4_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(float)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_float_get_nb(float *dest, const float *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_u4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(float)));
  }else{
    /* aggregate requests */
    __xbrtime_get_u4_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(float)));
  }
}

void xbrtime_double_get(double *dest, const double *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_u8_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(double)));
  }else{
    /* aggregate requests */
    __xbrtime_get_u8_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(double)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_double_get_nb(double *dest, const double *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_u8_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(double)));
  }else{
    /* aggregate requests */
    __xbrtime_get_u8_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(double)));
  }
}

void xbrtime_longdouble_get(long double *dest, const long double *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_u8_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(long double)));
  }else{
    /* aggregate requests */
    __xbrtime_get_u8_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(long double)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_longdouble_get_nb(long double *dest, const long double *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_u8_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(long double)));
  }else{
    /* aggregate requests */
    __xbrtime_get_u8_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(long double)));
  }
}

void xbrtime_schar_get(signed char *dest, const signed char *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_s1_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(signed char)));
  }else{
    /* aggregate requests */
    __xbrtime_get_s1_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(signed char)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_schar_get_nb(signed char *dest, const signed char *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_s1_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(signed char)));
  }else{
    /* aggregate requests */
    __xbrtime_get_s1_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(signed char)));
  }
}

void xbrtime_char_get(char *dest, const char *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_u1_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(char)));
  }else{
    /* aggregate requests */
    __xbrtime_get_u1_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(char)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_char_get_nb(char *dest, const char *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_u1_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(char)));
  }else{
    /* aggregate requests */
    __xbrtime_get_u1_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(char)));
  }
}

void xbrtime_short_get(short *dest, const short *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_s2_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(short)));
  }else{
    /* aggregate requests */
    __xbrtime_get_s2_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(short)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_short_get_nb(short *dest, const short *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_s2_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(short)));
  }else{
    /* aggregate requests */
    __xbrtime_get_s2_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(short)));
  }
}

void xbrtime_int_get(int *dest, const int *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_s4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int)));
  }else{
    /* aggregate requests */
    __xbrtime_get_s4_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_int_get_nb(int *dest, const int *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_s4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(short)));
  }else{
    /* aggregate requests */
    __xbrtime_get_s4_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(short)));
  }
}

void xbrtime_long_get(long *dest, const long *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_s4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(long)));
  }else{
    /* aggregate requests */
    __xbrtime_get_s4_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(long)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_long_get_nb(long *dest, const long *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_s4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(long)));
  }else{
    /* aggregate requests */
    __xbrtime_get_s4_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(long)));
  }
}

void xbrtime_longlong_get(long long *dest, const long long *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_s8_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(long long)));
  }else{
    /* aggregate requests */
    __xbrtime_get_s8_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(long long)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_longlong_get_nb(long long *dest, const long long *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_s8_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(long long)));
  }else{
    /* aggregate requests */
    __xbrtime_get_s8_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(long long)));
  }
}

void xbrtime_uchar_get(unsigned char *dest, const unsigned char *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_u1_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned char)));
  }else{
    /* aggregate requests */
    __xbrtime_get_u1_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned char)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_uchar_get_nb(unsigned char *dest, const unsigned char *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_u1_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned char)));
  }else{
    /* aggregate requests */
    __xbrtime_get_u1_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned char)));
  }
}

void xbrtime_ushort_get(unsigned short *dest, const unsigned short *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_u2_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned short)));
  }else{
    /* aggregate requests */
    __xbrtime_get_u2_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned short)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_ushort_get_nb(unsigned short *dest, const unsigned short *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_u2_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned short)));
  }else{
    /* aggregate requests */
    __xbrtime_get_u2_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned short)));
  }
}

void xbrtime_uint_get(unsigned int *dest, const unsigned int *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_u4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned int)));
  }else{
    /* aggregate requests */
    __xbrtime_get_u4_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned int)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_uint_get_nb(unsigned int *dest, const unsigned int *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_u4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned int)));
  }else{
    /* aggregate requests */
    __xbrtime_get_u4_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned int)));
  }
}

void xbrtime_ulong_get(unsigned long *dest, const unsigned long *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_u4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned long)));
  }else{
    /* aggregate requests */
    __xbrtime_get_u4_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned long)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_ulong_get_nb(unsigned long *dest, const unsigned long *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_u4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned long)));
  }else{
    /* aggregate requests */
    __xbrtime_get_u4_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned long)));
  }
}

void xbrtime_ulonglong_get(unsigned long long *dest, const unsigned long long *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_u8_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned long long)));
  }else{
    /* aggregate requests */
    __xbrtime_get_u8_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned long long)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_ulonglong_get_nb(unsigned long long *dest, const unsigned long long *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_u8_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned long long)));
  }else{
    /* aggregate requests */
    __xbrtime_get_u8_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(unsigned long long)));
  }
}

void xbrtime_int8_get(int8_t *dest, const int8_t *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_s1_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int8_t)));
  }else{
    /* aggregate requests */
    __xbrtime_get_s1_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int8_t)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_int8_get_nb(int8_t *dest, const int8_t *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_s1_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int8_t)));
  }else{
    /* aggregate requests */
    __xbrtime_get_s1_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int8_t)));
  }
}

void xbrtime_int16_get(int16_t *dest, const int16_t *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_s2_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int16_t)));
  }else{
    /* aggregate requests */
    __xbrtime_get_s2_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int16_t)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_int16_get_nb(int16_t *dest, const int16_t *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_s2_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int16_t)));
  }else{
    /* aggregate requests */
    __xbrtime_get_s2_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int16_t)));
  }
}

void xbrtime_int32_get(int32_t *dest, const int32_t *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_s4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int32_t)));
  }else{
    /* aggregate requests */
    __xbrtime_get_s4_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int32_t)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_int32_get_nb(int32_t *dest, const int32_t *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_s4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int32_t)));
  }else{
    /* aggregate requests */
    __xbrtime_get_s4_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int32_t)));
  }
}

void xbrtime_int64_get(int64_t *dest, const int64_t *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_s8_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int64_t)));
  }else{
    /* aggregate requests */
    __xbrtime_get_s8_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int64_t)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_int64_get_nb(int64_t *dest, const int64_t *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_s8_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int64_t)));
  }else{
    /* aggregate requests */
    __xbrtime_get_s8_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(int64_t)));
  }
}

void xbrtime_uint8_get(uint8_t *dest, const uint8_t *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_u1_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint8_t)));
  }else{
    /* aggregate requests */
    __xbrtime_get_u1_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint8_t)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_uint8_get_nb(uint8_t *dest, const uint8_t *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_u1_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint8_t)));
  }else{
    /* aggregate requests */
    __xbrtime_get_u1_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint8_t)));
  }
}

void xbrtime_uint16_get(uint16_t *dest, const uint16_t *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_u2_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint16_t)));
  }else{
    /* aggregate requests */
    __xbrtime_get_u2_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint16_t)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_uint16_get_nb(uint16_t *dest, const uint16_t *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_u2_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint16_t)));
  }else{
    /* aggregate requests */
    __xbrtime_get_u2_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint16_t)));
  }
}

void xbrtime_uint32_get(uint32_t *dest, const uint32_t *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_u4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint32_t)));
  }else{
    /* aggregate requests */
    __xbrtime_get_u4_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint32_t)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_uint32_get_nb(uint32_t *dest, const uint32_t *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_u4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint32_t)));
  }else{
    /* aggregate requests */
    __xbrtime_get_u4_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint32_t)));
  }
}

void xbrtime_uint64_get(uint64_t *dest, const uint64_t *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_u8_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint64_t)));
  }else{
    /* aggregate requests */
    __xbrtime_get_u8_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint64_t)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_uint64_get_nb(uint64_t *dest, const uint64_t *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_u8_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint64_t)));
  }else{
    /* aggregate requests */
    __xbrtime_get_u8_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(uint64_t)));
  }
}

void xbrtime_size_get(size_t *dest, const size_t *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_u4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(size_t)));
  }else{
    /* aggregate requests */
    __xbrtime_get_u4_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(size_t)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_size_get_nb(size_t *dest, const size_t *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_u4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(size_t)));
  }else{
    /* aggregate requests */
    __xbrtime_get_u4_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(size_t)));
  }
}

void xbrtime_ptrdiff_get(ptrdiff_t *dest, const ptrdiff_t *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_s4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(ptrdiff_t)));
  }else{
    /* aggregate requests */
    __xbrtime_get_s4_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(ptrdiff_t)));
  }
  __xbrtime_asm_fence();
}

void xbrtime_ptrdiff_get_nb(ptrdiff_t *dest, const ptrdiff_t *src,
                     size_t nelems, int stride, int pe){
  if( (stride != 1) || (nelems == 1)){
    /* sequential execution */
    __xbrtime_get_s4_seq(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(ptrdiff_t)));
  }else{
    /* aggregate requests */
    __xbrtime_get_s4_agg(__xbrtime_ltor((uint64_t)(src),pe),
                         (uint64_t)(dest,
                         xbrtime_decode_pe(pe),
                         (uint32_t)(nelems),
                         (uint32_t)(stride*sizeof(ptrdiff_t)));
  }
}
