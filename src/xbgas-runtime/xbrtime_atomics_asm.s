#
# _XBRTIME_ATOMICS_ASM_S_
#
# Copyright (C) 2017-2019 Tactical Computing Laboratories, LLC
# All Rights Reserved
# contact@tactcomplabs.com
#
# This file is a part of the XBGAS-RUNTIME package.  For license
# information, see the LICENSE file in the top level directory
# of the distribution.
#

  .file "xbrtime_atomics_asm.s"
  .text
  .align 1

  #---------------------------------------------------
  # xBGAS ASM Atomic functions are formatted as follows:
  # __xbrtime_atomic_FUNC_OPERAND
  #   where,
  #   - FUNC is one of:
  #     - add = addition
  #     - bor = bitwise OR
  #     - band = bitwise AND
  #     - bxor = bitwise XOR
  #     - min = minimum
  #     - max = maximum
  #     - compare_swap = compare and swap
  #   - OPERAND is one of:
  #     - u4 = unsigned four bytes
  #     - s4 = signed four bytes
  #     - u8 = unsigned eight bytes
  #     - s8 = signed eight bytes
  #---------------------------------------------------
  # Atomic Function Calling Convention
  #   - a0 = base dest address
  #   - a1 = op value
  #   - a2 = remote pe
  #---------------------------------------------------

    .global __xbrtime_atomic_add_u4
    .type __xbrtime_atomic_add_u4, @function
  __xbrtime_atomic_add_u4:
    eaddie e10, a2, 0
    eamoadd.w a0, a0, a1
    ret
    .size __xbrtime_atomic_add_u4, .-__xbrtime_atomic_add_u4

    #---------------------------------------------------

    .global __xbrtime_atomic_add_s4
    .type __xbrtime_atomic_add_s4, @function
  __xbrtime_atomic_add_s4:
    eaddie e10, a2, 0
    eamoadd.w a0, a0, a1
    ret
    .size __xbrtime_atomic_add_s4, .-__xbrtime_atomic_add_s4

    #---------------------------------------------------

    .global __xbrtime_atomic_add_u8
    .type __xbrtime_atomic_add_u8, @function
  __xbrtime_atomic_add_u8:
    eaddie e10, a2, 0
    eamoadd.d a0, a0, a1
    ret
    .size __xbrtime_atomic_add_u8, .-__xbrtime_atomic_add_u8

    #---------------------------------------------------

    .global __xbrtime_atomic_add_s8
    .type __xbrtime_atomic_add_s8, @function
  __xbrtime_atomic_add_s8:
    eaddie e10, a2, 0
    eamoadd.d a0, a0, a1
    ret
    .size __xbrtime_atomic_add_s8, .-__xbrtime_atomic_add_s8

    #---------------------------------------------------

    .global __xbrtime_atomic_bor_u4
    .type __xbrtime_atomic_bor_u4, @function
  __xbrtime_atomic_bor_u4:
    eaddie e10, a2, 0
    eamoor.w a0, a0, a1
    ret
    .size __xbrtime_atomic_bor_u4, .-__xbrtime_atomic_bor_u4

    #---------------------------------------------------

    .global __xbrtime_atomic_bor_s4
    .type __xbrtime_atomic_bor_s4, @function
  __xbrtime_atomic_bor_s4:
    eaddie e10, a2, 0
    eamoor.w a0, a0, a1
    ret
    .size __xbrtime_atomic_bor_s4, .-__xbrtime_atomic_bor_s4

    #---------------------------------------------------

    .global __xbrtime_atomic_bor_u8
    .type __xbrtime_atomic_bor_u8, @function
  __xbrtime_atomic_bor_u8:
    eaddie e10, a2, 0
    eamoor.d a0, a0, a1
    ret
    .size __xbrtime_atomic_bor_u8, .-__xbrtime_atomic_bor_u8

    #---------------------------------------------------

    .global __xbrtime_atomic_bor_s8
    .type __xbrtime_atomic_bor_s8, @function
  __xbrtime_atomic_bor_s8:
    eaddie e10, a2, 0
    eamoor.d a0, a0, a1
    ret
    .size __xbrtime_atomic_bor_s8, .-__xbrtime_atomic_bor_s8

    #---------------------------------------------------

    .global __xbrtime_atomic_bxor_u4
    .type __xbrtime_atomic_bxor_u4, @function
  __xbrtime_atomic_bxor_u4:
    eaddie e10, a2, 0
    eamoxor.w a0, a0, a1
    ret
    .size __xbrtime_atomic_bxor_u4, .-__xbrtime_atomic_bxor_u4

    #---------------------------------------------------

    .global __xbrtime_atomic_bxor_s4
    .type __xbrtime_atomic_bxor_s4, @function
  __xbrtime_atomic_bxor_s4:
    eaddie e10, a2, 0
    eamoxor.w a0, a0, a1
    ret
    .size __xbrtime_atomic_bxor_s4, .-__xbrtime_atomic_bxor_s4

    #---------------------------------------------------

    .global __xbrtime_atomic_bxor_u8
    .type __xbrtime_atomic_bxor_u8, @function
  __xbrtime_atomic_bxor_u8:
    eaddie e10, a2, 0
    eamoxor.d a0, a0, a1
    ret
    .size __xbrtime_atomic_bxor_u8, .-__xbrtime_atomic_bxor_u8

    #---------------------------------------------------

    .global __xbrtime_atomic_bxor_s8
    .type __xbrtime_atomic_bxor_s8, @function
  __xbrtime_atomic_bxor_s8:
    eaddie e10, a2, 0
    eamoxor.d a0, a0, a1
    ret
    .size __xbrtime_atomic_bxor_s8, .-__xbrtime_atomic_bxor_s8

    #---------------------------------------------------

    .global __xbrtime_atomic_band_u4
    .type __xbrtime_atomic_band_u4, @function
  __xbrtime_atomic_band_u4:
    eaddie e10, a2, 0
    eamoand.w a0, a0, a1
    ret
    .size __xbrtime_atomic_band_u4, .-__xbrtime_atomic_band_u4

    #---------------------------------------------------

    .global __xbrtime_atomic_band_s4
    .type __xbrtime_atomic_band_s4, @function
  __xbrtime_atomic_band_s4:
    eaddie e10, a2, 0
    eamoand.w a0, a0, a1
    ret
    .size __xbrtime_atomic_band_s4, .-__xbrtime_atomic_band_s4

    #---------------------------------------------------

    .global __xbrtime_atomic_band_u8
    .type __xbrtime_atomic_band_u8, @function
  __xbrtime_atomic_band_u8:
    eaddie e10, a2, 0
    eamoand.d a0, a0, a1
    ret
    .size __xbrtime_atomic_band_u8, .-__xbrtime_atomic_band_u8

    #---------------------------------------------------

    .global __xbrtime_atomic_band_s8
    .type __xbrtime_atomic_band_s8, @function
  __xbrtime_atomic_band_s8:
    eaddie e10, a2, 0
    eamoand.d a0, a0, a1
    ret
    .size __xbrtime_atomic_band_s8, .-__xbrtime_atomic_band_s8

    #---------------------------------------------------

    .global __xbrtime_atomic_min_u4
    .type __xbrtime_atomic_min_u4, @function
  __xbrtime_atomic_min_u4:
    eaddie e10, a2, 0
    eamomin.w a0, a0, a1
    ret
    .size __xbrtime_atomic_min_u4, .-__xbrtime_atomic_min_u4

    #---------------------------------------------------

    #  .global __xbrtime_atomic_min_s4
    #  .type __xbrtime_atomic_min_s4, @function
    #  __xbrtime_atomic_min_s4:
    #  eaddie e10, 0, a2
    #  eamomin.w a0, a0, a1
    #  ret
    #  .size __xbrtime_atomic_min_s4, .-__xbrtime_atomic_min_s4

    #---------------------------------------------------

    .global __xbrtime_atomic_min_u8
    .type __xbrtime_atomic_min_u8, @function
  __xbrtime_atomic_min_u8:
    eaddie e10, a2, 0
    eamomin.d a0, a0, a1
    ret
    .size __xbrtime_atomic_min_u8, .-__xbrtime_atomic_min_u8

    #---------------------------------------------------

    #  .global __xbrtime_atomic_min_s8
    #  .type __xbrtime_atomic_min_s8, @function
    #  __xbrtime_atomic_min_s8:
    #  eaddie e10, 0, a2
    #  eamomin.d a0, a0, a1
    #  ret
    #  .size __xbrtime_atomic_min_s8, .-__xbrtime_atomic_min_s8

    #---------------------------------------------------

    .global __xbrtime_atomic_max_u4
    .type __xbrtime_atomic_max_u4, @function
  __xbrtime_atomic_max_u4:
    eaddie e10, a2, 0
    eamomax.w a0, a0, a1
    ret
    .size __xbrtime_atomic_max_u4, .-__xbrtime_atomic_max_u4

    #---------------------------------------------------

    #  .global __xbrtime_atomic_max_s4
    #  .type __xbrtime_atomic_max_s4, @function
    #  __xbrtime_atomic_max_s4:
    #  eaddie e10, 0, a2
    #  eamomax.w a0, a0, a1
    #  ret
    #  .size __xbrtime_atomic_max_s4, .-__xbrtime_atomic_max_s4

    #---------------------------------------------------

    .global __xbrtime_atomic_max_u8
    .type __xbrtime_atomic_max_u8, @function
    __xbrtime_atomic_max_u8:
    eaddie e10, a2, 0
    eamomax.d a0, a0, a1
    ret
    .size __xbrtime_atomic_max_u8, .-__xbrtime_atomic_max_u8

    #---------------------------------------------------

    #  .global __xbrtime_atomic_max_s8
    #  .type __xbrtime_atomic_max_s8, @function
    #  __xbrtime_atomic_max_s8:
    #  eaddie e10, 0, a2
    #  eamomax.d a0, a0, a1
    #  ret
    #  .size __xbrtime_atomic_max_s8, .-__xbrtime_atomic_max_s8

    #---------------------------------------------------

    .global __xbrtime_atomic_compare_swap_u4
    .type __xbrtime_atomic_compare_swap_u4, @function
  __xbrtime_atomic_compare_swap_u4:
    eaddie e10, a2, 0
    eamocas.w a0, a0, a1
    ret
    .size __xbrtime_atomic_compare_swap_u4, .-__xbrtime_atomic_compare_swap_u4

    #---------------------------------------------------

    .global __xbrtime_atomic_compare_swap_s4
    .type __xbrtime_atomic_compare_swap_s4, @function
  __xbrtime_atomic_compare_swap_s4:
    eaddie e10, a2, 0
    eamocas.w a0, a0, a1
    ret
    .size __xbrtime_atomic_compare_swap_s4, .-__xbrtime_atomic_compare_swap_s4

    #---------------------------------------------------

    .global __xbrtime_atomic_compare_swap_u8
    .type __xbrtime_atomic_compare_swap_u8, @function
  __xbrtime_atomic_compare_swap_u8:
    eaddie e10, a2, 0
    eamocas.d a0, a0, a1
    ret
    .size __xbrtime_atomic_compare_swap_u8, .-__xbrtime_atomic_compare_swap_u8

    #---------------------------------------------------

    .global __xbrtime_atomic_compare_swap_s8
    .type __xbrtime_atomic_compare_swap_s8, @function
  __xbrtime_atomic_compare_swap_s8:
    eaddie e10, a2, 0
    eamocas.d a0, a0, a1
    ret
    .size __xbrtime_atomic_compare_swap_s8, .-__xbrtime_atomic_compare_swap_s8

    #---------------------------------------------------
