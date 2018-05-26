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
  #   - a0 = base address
  #   - a1 = remote pe
  #   - a2 = nelems
  #   - a3 = stride (in bytes)
  #
  # Unrolled Calling Convention
  #   - a0 = base address
  #   - a1 = remote pe
  #   - a2 = stride (in bytes)
  #   - a3 = loop iters
  #   = a4 = epilogue iters
  #---------------------------------------------------

  .global __xbrtime_get_u1_seq
  .type __xbrtime_get_u1_seq, @function
__xbrtime_get_u1_seq:
  ret
  .size __xbrtime_get_u1_seq, .-__xbrtime_get_u1_seq

  .global __xbrtime_get_u1_unr
  .type __xbrtime_get_u1_unr, @function
__xbrtime_get_u1_unr:
  ret
  .size __xbrtime_get_u1_unr, .-__xbrtime_get_u1_unr

  .global __xbrtime_get_u2_seq
  .type __xbrtime_get_u2_seq, @function
__xbrtime_get_u2_seq:
  ret
  .size __xbrtime_get_u2_seq, .-__xbrtime_get_u2_seq

  .global __xbrtime_get_u2_unr
  .type __xbrtime_get_u2_unr, @function
__xbrtime_get_u2_unr:
  ret
  .size __xbrtime_get_u2_unr, .-__xbrtime_get_u2_unr

  .global __xbrtime_get_u4_seq
  .type __xbrtime_get_u4_seq, @function
__xbrtime_get_u4_seq:
  ret
  .size __xbrtime_get_u4_seq, .-__xbrtime_get_u4_seq

  .global __xbrtime_get_u4_unr
  .type __xbrtime_get_u4_unr, @function
__xbrtime_get_u4_unr:
  ret
  .size __xbrtime_get_u4_unr, .-__xbrtime_get_u4_unr

  .global __xbrtime_get_u8_seq
  .type __xbrtime_get_u8_seq, @function
__xbrtime_get_u8_seq:
  ret
  .size __xbrtime_get_u8_seq, .-__xbrtime_get_u8_seq

  .global __xbrtime_get_u8_unr
  .type __xbrtime_get_u8_unr, @function
__xbrtime_get_u8_unr:
  ret
  .size __xbrtime_get_u8_unr, .-__xbrtime_get_u8_unr

  .global __xbrtime_get_s1_seq
  .type __xbrtime_get_s1_seq, @function
__xbrtime_get_s1_seq:
  ret
  .size __xbrtime_get_s1_seq, .-__xbrtime_get_s1_seq

  .global __xbrtime_get_s1_unr
  .type __xbrtime_get_s1_unr, @function
__xbrtime_get_s1_unr:
  ret
  .size __xbrtime_get_s1_unr, .-__xbrtime_get_s1_unr

  .global __xbrtime_get_s2_seq
  .type __xbrtime_get_s2_seq, @function
__xbrtime_get_s2_seq:
  ret
  .size __xbrtime_get_s2_seq, .-__xbrtime_get_s2_seq

  .global __xbrtime_get_s2_unr
  .type __xbrtime_get_s2_unr, @function
__xbrtime_get_s2_unr:
  ret
  .size __xbrtime_get_s2_unr, .-__xbrtime_get_s2_unr

  .global __xbrtime_get_s4_seq
  .type __xbrtime_get_s4_seq, @function
__xbrtime_get_s4_seq:
  ret
  .size __xbrtime_get_s4_seq, .-__xbrtime_get_s4_seq

  .global __xbrtime_get_s4_unr
  .type __xbrtime_get_s4_unr, @function
__xbrtime_get_s4_unr:
  ret
  .size __xbrtime_get_s4_unr, .-__xbrtime_get_s4_unr

  .global __xbrtime_get_s8_seq
  .type __xbrtime_get_s8_seq, @function
__xbrtime_get_s8_seq:
  ret
  .size __xbrtime_get_s8_seq, .-__xbrtime_get_s8_seq

  .global __xbrtime_get_s8_unr
  .type __xbrtime_get_s8_unr, @function
__xbrtime_get_s8_unr:
  ret
  .size __xbrtime_get_s8_unr, .-__xbrtime_get_s8_unr

  .global __xbrtime_put_u1_seq
  .type __xbrtime_put_u1_seq, @function
__xbrtime_put_u1_seq:
  ret
  .size __xbrtime_put_u1_seq, .-__xbrtime_put_u1_seq

  .global __xbrtime_put_u1_unr
  .type __xbrtime_put_u1_unr, @function
__xbrtime_put_u1_unr:
  ret
  .size __xbrtime_put_u1_unr, .-__xbrtime_put_u1_unr

  .global __xbrtime_put_u2_seq
  .type __xbrtime_put_u2_seq, @function
__xbrtime_put_u2_seq:
  ret
  .size __xbrtime_put_u2_seq, .-__xbrtime_put_u2_seq

  .global __xbrtime_put_u2_unr
  .type __xbrtime_put_u2_unr, @function
__xbrtime_put_u2_unr:
  ret
  .size __xbrtime_put_u2_unr, .-__xbrtime_put_u2_unr

  .global __xbrtime_put_u4_seq
  .type __xbrtime_put_u4_seq, @function
__xbrtime_put_u4_seq:
  ret
  .size __xbrtime_put_u4_seq, .-__xbrtime_put_u4_seq

  .global __xbrtime_put_u4_unr
  .type __xbrtime_put_u4_unr, @function
__xbrtime_put_u4_unr:
  ret
  .size __xbrtime_put_u4_unr, .-__xbrtime_put_u4_unr

  .global __xbrtime_put_u8_seq
  .type __xbrtime_put_u8_seq, @function
__xbrtime_put_u8_seq:
  ret
  .size __xbrtime_put_u8_seq, .-__xbrtime_put_u8_seq

  .global __xbrtime_put_u8_unr
  .type __xbrtime_put_u8_unr, @function
__xbrtime_put_u8_unr:
  ret
  .size __xbrtime_put_u8_unr, .-__xbrtime_put_u8_unr

  .global __xbrtime_put_s1_seq
  .type __xbrtime_put_s1_seq, @function
__xbrtime_put_s1_seq:
  ret
  .size __xbrtime_put_s1_seq, .-__xbrtime_put_s1_seq

  .global __xbrtime_put_s1_unr
  .type __xbrtime_put_s1_unr, @function
__xbrtime_put_s1_unr:
  ret
  .size __xbrtime_put_s1_unr, .-__xbrtime_put_s1_unr

  .global __xbrtime_put_s2_seq
  .type __xbrtime_put_s2_seq, @function
__xbrtime_put_s2_seq:
  ret
  .size __xbrtime_put_s2_seq, .-__xbrtime_put_s2_seq

  .global __xbrtime_put_s2_unr
  .type __xbrtime_put_s2_unr, @function
__xbrtime_put_s2_unr:
  ret
  .size __xbrtime_put_s2_unr, .-__xbrtime_put_s2_unr

  .global __xbrtime_put_s4_seq
  .type __xbrtime_put_s4_seq, @function
__xbrtime_put_s4_seq:
  ret
  .size __xbrtime_put_s4_seq, .-__xbrtime_put_s4_seq

  .global __xbrtime_put_s4_unr
  .type __xbrtime_put_s4_unr, @function
__xbrtime_put_s4_unr:
  ret
  .size __xbrtime_put_s4_unr, .-__xbrtime_put_s4_unr

  .global __xbrtime_put_s8_seq
  .type __xbrtime_put_s8_seq, @function
__xbrtime_put_s8_seq:
  ret
  .size __xbrtime_put_s8_seq, .-__xbrtime_put_s8_seq

  .global __xbrtime_put_s8_unr
  .type __xbrtime_put_s8_unr, @function
__xbrtime_put_s8_unr:
  ret
  .size __xbrtime_put_s8_unr, .-__xbrtime_put_s8_unr

#-- EOF
