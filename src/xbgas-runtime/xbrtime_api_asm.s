#
# _XBRTIME_API_ASM_S_
#
# Copyright (C) 2017-2018 Tactical Computing Laboratories, LLC
# All Rights Reserved
# contact@tactcomplabs.com
#
# This file is a part of the XBGAS-RUNTIME package.  For license
# information, see the LICENSE file in the top level directory
# of the distribution.
#

  .file "xbrtime_api_asm.s"
  .text
  .align 1

  #---------------------------------------------------
  # xBGAS ASM API functions are formatted as follows:
  # __xbrtime_{get,put}_OPERAND_{seq,unr}
  #   where,
  #   - {get,put} correponds to receive and send
  #   - OPERAND is one of:
  #     - u1 = unsigned one byte
  #     - u2 = unsigned two byte
  #     - u4 = unsigned four byte
  #     - u8 = unsigned eight byte
  #     - s1 = signed one byte
  #     - s2 = signed two byte
  #     - s4 = signed four byte
  #     - s8 = signed eight byte
  #   - {seq,unr} corresponds to sequential transfers
  #             and unrolled (8-ways) transfers
  #---------------------------------------------------
  # Seq Calling Convention
  #   - a0 = base src address
  #   - a1 = base dest address
  #   - a2 = remote pe
  #   - a3 = nelems
  #   - a4 = stride (in bytes)
  #
  # Unrolled Calling Convention
  #   - a0 = base src address
  #   - a1 = base dest address
  #   - a2 = remote pe
  #   - a3 = stride (in bytes)
  #   - a4 = loop iters
  #   = a5 = epilogue iters
  #---------------------------------------------------

  .global __xbrtime_get_u1_seq
  .type __xbrtime_get_u1_seq, @function
__xbrtime_get_u1_seq:
  eaddie e10, 0, a2
  mv x31, zero
.get_u1_seq:
  elbu x30, 0(a0)
  add a0, a0, a4
  add x31,x31,1
  sb x30, 0(a1)
  add a1, a1, a4
  bne x31,a3,.get_u1_seq
  ret
  .size __xbrtime_get_u1_seq, .-__xbrtime_get_u1_seq

  #---------------------------------------------------

  .global __xbrtime_get_u1_unr
  .type __xbrtime_get_u1_unr, @function
__xbrtime_get_u1_unr:
  ret
  .size __xbrtime_get_u1_unr, .-__xbrtime_get_u1_unr

  #---------------------------------------------------

  .global __xbrtime_get_u2_seq
  .type __xbrtime_get_u2_seq, @function
__xbrtime_get_u2_seq:
  eaddie e10, 0, a2
  mv x31, zero
.get_u2_seq:
  elhu x30, 0(a0)
  add a0, a0, a4
  add x31,x31,1
  sh x30, 0(a1)
  add a1, a1, a4
  bne x31,a3,.get_u2_seq
  ret
  .size __xbrtime_get_u2_seq, .-__xbrtime_get_u2_seq

  #---------------------------------------------------

  .global __xbrtime_get_u2_unr
  .type __xbrtime_get_u2_unr, @function
__xbrtime_get_u2_unr:
  ret
  .size __xbrtime_get_u2_unr, .-__xbrtime_get_u2_unr

  #---------------------------------------------------

  .global __xbrtime_get_u4_seq
  .type __xbrtime_get_u4_seq, @function
__xbrtime_get_u4_seq:
  eaddie e10, 0, a2
  mv x31, zero
.get_u4_seq:
  elw x30, 0(a0)
  add a0, a0, a4
  add x31,x31,1
  sw x30, 0(a1)
  add a1, a1, a4
  bne x31,a3,.get_u4_seq
  ret
  .size __xbrtime_get_u4_seq, .-__xbrtime_get_u4_seq

  #---------------------------------------------------

  .global __xbrtime_get_u4_unr
  .type __xbrtime_get_u4_unr, @function
__xbrtime_get_u4_unr:
  ret
  .size __xbrtime_get_u4_unr, .-__xbrtime_get_u4_unr

  #---------------------------------------------------

  .global __xbrtime_get_u8_seq
  .type __xbrtime_get_u8_seq, @function
__xbrtime_get_u8_seq:
  eaddie e10, 0, a2
  mv x31, zero
.get_u8_seq:
  eld x30, 0(a0)
  add a0, a0, a4
  add x31,x31,1
  sd x30, 0(a1)
  add a1, a1, a4
  bne x31,a3,.get_u8_seq
  ret
  .size __xbrtime_get_u8_seq, .-__xbrtime_get_u8_seq

  #---------------------------------------------------

  .global __xbrtime_get_u8_unr
  .type __xbrtime_get_u8_unr, @function
__xbrtime_get_u8_unr:
  ret
  .size __xbrtime_get_u8_unr, .-__xbrtime_get_u8_unr

  #---------------------------------------------------

  .global __xbrtime_get_s1_seq
  .type __xbrtime_get_s1_seq, @function
__xbrtime_get_s1_seq:
  eaddie e10, 0, a2
  mv x31, zero
.get_s1_seq:
  elb x30, 0(a0)
  add a0, a0, a4
  add x31,x31,1
  sb x30, 0(a1)
  add a1, a1, a4
  bne x31,a3,.get_s1_seq
  ret
  .size __xbrtime_get_s1_seq, .-__xbrtime_get_s1_seq

  #---------------------------------------------------

  .global __xbrtime_get_s1_unr
  .type __xbrtime_get_s1_unr, @function
__xbrtime_get_s1_unr:
  ret
  .size __xbrtime_get_s1_unr, .-__xbrtime_get_s1_unr

  #---------------------------------------------------

  .global __xbrtime_get_s2_seq
  .type __xbrtime_get_s2_seq, @function
__xbrtime_get_s2_seq:
  eaddie e10, 0, a2
  mv x31, zero
.get_s2_seq:
  elh x30, 0(a0)
  add a0, a0, a4
  add x31,x31,1
  sh x30, 0(a1)
  add a1, a1, a4
  bne x31,a3,.get_s2_seq
  ret
  .size __xbrtime_get_s2_seq, .-__xbrtime_get_s2_seq

  #---------------------------------------------------

  .global __xbrtime_get_s2_unr
  .type __xbrtime_get_s2_unr, @function
__xbrtime_get_s2_unr:
  ret
  .size __xbrtime_get_s2_unr, .-__xbrtime_get_s2_unr

  #---------------------------------------------------

  .global __xbrtime_get_s4_seq
  .type __xbrtime_get_s4_seq, @function
__xbrtime_get_s4_seq:
  eaddie e10, 0, a2
  mv x31, zero
.get_s4_seq:
  elw x30, 0(a0)
  add a0, a0, a4
  add x31,x31,1
  sw x30, 0(a1)
  add a1, a1, a4
  bne x31,a3,.get_s4_seq
  ret
  .size __xbrtime_get_s4_seq, .-__xbrtime_get_s4_seq

  #---------------------------------------------------

  .global __xbrtime_get_s4_unr
  .type __xbrtime_get_s4_unr, @function
__xbrtime_get_s4_unr:
  ret
  .size __xbrtime_get_s4_unr, .-__xbrtime_get_s4_unr

  #---------------------------------------------------

  .global __xbrtime_get_s8_seq
  .type __xbrtime_get_s8_seq, @function
__xbrtime_get_s8_seq:
  eaddie e10, 0, a2
  mv x31, zero
.get_s8_seq:
  eld x30, 0(a0)
  add a0, a0, a4
  add x31,x31,1
  sd x30, 0(a1)
  add a1, a1, a4
  bne x31,a3,.get_s8_seq
  ret
  .size __xbrtime_get_s8_seq, .-__xbrtime_get_s8_seq

  #---------------------------------------------------

  .global __xbrtime_get_s8_unr
  .type __xbrtime_get_s8_unr, @function
__xbrtime_get_s8_unr:
  ret
  .size __xbrtime_get_s8_unr, .-__xbrtime_get_s8_unr

  #---------------------------------------------------

  .global __xbrtime_put_u1_seq
  .type __xbrtime_put_u1_seq, @function
__xbrtime_put_u1_seq:
  ret
  .size __xbrtime_put_u1_seq, .-__xbrtime_put_u1_seq

  #---------------------------------------------------

  .global __xbrtime_put_u1_unr
  .type __xbrtime_put_u1_unr, @function
__xbrtime_put_u1_unr:
  ret
  .size __xbrtime_put_u1_unr, .-__xbrtime_put_u1_unr

  #---------------------------------------------------

  .global __xbrtime_put_u2_seq
  .type __xbrtime_put_u2_seq, @function
__xbrtime_put_u2_seq:
  ret
  .size __xbrtime_put_u2_seq, .-__xbrtime_put_u2_seq

  #---------------------------------------------------

  .global __xbrtime_put_u2_unr
  .type __xbrtime_put_u2_unr, @function
__xbrtime_put_u2_unr:
  ret
  .size __xbrtime_put_u2_unr, .-__xbrtime_put_u2_unr

  #---------------------------------------------------

  .global __xbrtime_put_u4_seq
  .type __xbrtime_put_u4_seq, @function
__xbrtime_put_u4_seq:
  ret
  .size __xbrtime_put_u4_seq, .-__xbrtime_put_u4_seq

  #---------------------------------------------------

  .global __xbrtime_put_u4_unr
  .type __xbrtime_put_u4_unr, @function
__xbrtime_put_u4_unr:
  ret
  .size __xbrtime_put_u4_unr, .-__xbrtime_put_u4_unr

  #---------------------------------------------------

  .global __xbrtime_put_u8_seq
  .type __xbrtime_put_u8_seq, @function
__xbrtime_put_u8_seq:
  ret
  .size __xbrtime_put_u8_seq, .-__xbrtime_put_u8_seq

  #---------------------------------------------------

  .global __xbrtime_put_u8_unr
  .type __xbrtime_put_u8_unr, @function
__xbrtime_put_u8_unr:
  ret
  .size __xbrtime_put_u8_unr, .-__xbrtime_put_u8_unr

  #---------------------------------------------------

  .global __xbrtime_put_s1_seq
  .type __xbrtime_put_s1_seq, @function
__xbrtime_put_s1_seq:
  ret
  .size __xbrtime_put_s1_seq, .-__xbrtime_put_s1_seq

  #---------------------------------------------------

  .global __xbrtime_put_s1_unr
  .type __xbrtime_put_s1_unr, @function
__xbrtime_put_s1_unr:
  ret
  .size __xbrtime_put_s1_unr, .-__xbrtime_put_s1_unr

  #---------------------------------------------------

  .global __xbrtime_put_s2_seq
  .type __xbrtime_put_s2_seq, @function
__xbrtime_put_s2_seq:
  ret
  .size __xbrtime_put_s2_seq, .-__xbrtime_put_s2_seq

  #---------------------------------------------------

  .global __xbrtime_put_s2_unr
  .type __xbrtime_put_s2_unr, @function
__xbrtime_put_s2_unr:
  ret
  .size __xbrtime_put_s2_unr, .-__xbrtime_put_s2_unr

  #---------------------------------------------------

  .global __xbrtime_put_s4_seq
  .type __xbrtime_put_s4_seq, @function
__xbrtime_put_s4_seq:
  ret
  .size __xbrtime_put_s4_seq, .-__xbrtime_put_s4_seq

  #---------------------------------------------------

  .global __xbrtime_put_s4_unr
  .type __xbrtime_put_s4_unr, @function
__xbrtime_put_s4_unr:
  ret
  .size __xbrtime_put_s4_unr, .-__xbrtime_put_s4_unr

  #---------------------------------------------------

  .global __xbrtime_put_s8_seq
  .type __xbrtime_put_s8_seq, @function
__xbrtime_put_s8_seq:
  ret
  .size __xbrtime_put_s8_seq, .-__xbrtime_put_s8_seq

  #---------------------------------------------------

  .global __xbrtime_put_s8_unr
  .type __xbrtime_put_s8_unr, @function
__xbrtime_put_s8_unr:
  ret
  .size __xbrtime_put_s8_unr, .-__xbrtime_put_s8_unr

#-- EOF
