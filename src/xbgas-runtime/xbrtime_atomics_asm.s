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
  #     - lor = logical OR
  #     - land = logical AND
  #     - lxor = logical XOR
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
    eamoadd.w t0, a1, a0
    ret
    .size __xbrtime_atomic_add_u4, .-__xbrtime_atomic_add_u4

    #---------------------------------------------------

    .global __xbrtime_atomic_add_s4
    .type __xbrtime_atomic_add_s4, @function
  __xbrtime_atomic_add_s4:
    eaddie e10, a2, 0
    eamoadd.w t0, a1, a0
    ret
    .size __xbrtime_atomic_add_s4, .-__xbrtime_atomic_add_s4

    #---------------------------------------------------

    .global __xbrtime_atomic_add_u8
    .type __xbrtime_atomic_add_u8, @function
  __xbrtime_atomic_add_u8:
    eaddie e10, a2, 0
    eamoadd.d t0, a1, a0
    ret
    .size __xbrtime_atomic_add_u8, .-__xbrtime_atomic_add_u8

    #---------------------------------------------------

    .global __xbrtime_atomic_add_s8
    .type __xbrtime_atomic_add_s8, @function
  __xbrtime_atomic_add_s8:
    eaddie e10, a2, 0
    eamoadd.d t0, a1, a0
    ret
    .size __xbrtime_atomic_add_s8, .-__xbrtime_atomic_add_s8

    #---------------------------------------------------

    .global __xbrtime_atomic_lor_u4
    .type __xbrtime_atomic_lor_u4, @function
  __xbrtime_atomic_lor_u4:
    eaddie e10, a2, 0
    eamoor.w t0, a1, a0
    ret
    .size __xbrtime_atomic_lor_u4, .-__xbrtime_atomic_lor_u4

    #---------------------------------------------------

    .global __xbrtime_atomic_lor_s4
    .type __xbrtime_atomic_lor_s4, @function
  __xbrtime_atomic_lor_s4:
    eaddie e10, a2, 0
    eamoor.w t0, a1, a0
    ret
    .size __xbrtime_atomic_lor_s4, .-__xbrtime_atomic_lor_s4

    #---------------------------------------------------

    .global __xbrtime_atomic_lor_u8
    .type __xbrtime_atomic_lor_u8, @function
  __xbrtime_atomic_lor_u8:
    eaddie e10, a2, 0
    eamoor.d t0, a1, a0
    ret
    .size __xbrtime_atomic_lor_u8, .-__xbrtime_atomic_lor_u8

    #---------------------------------------------------

    .global __xbrtime_atomic_lor_s8
    .type __xbrtime_atomic_lor_s8, @function
  __xbrtime_atomic_lor_s8:
    eaddie e10, a2, 0
    eamoor.d t0, a1, a0
    ret
    .size __xbrtime_atomic_lor_s8, .-__xbrtime_atomic_lor_s8

    #---------------------------------------------------

    .global __xbrtime_atomic_lxor_u4
    .type __xbrtime_atomic_lxor_u4, @function
  __xbrtime_atomic_lxor_u4:
    eaddie e10, a2, 0
    eamoxor.w t0, a1, a0
    ret
    .size __xbrtime_atomic_lxor_u4, .-__xbrtime_atomic_lxor_u4

    #---------------------------------------------------

    .global __xbrtime_atomic_lxor_s4
    .type __xbrtime_atomic_lxor_s4, @function
  __xbrtime_atomic_lxor_s4:
    eaddie e10, a2, 0
    eamoxor.w t0, a1, a0
    ret
    .size __xbrtime_atomic_lxor_s4, .-__xbrtime_atomic_lxor_s4

    #---------------------------------------------------

    .global __xbrtime_atomic_lxor_u8
    .type __xbrtime_atomic_lxor_u8, @function
  __xbrtime_atomic_lxor_u8:
    eaddie e10, a2, 0
    eamoxor.d t0, a1, a0
    ret
    .size __xbrtime_atomic_lxor_u8, .-__xbrtime_atomic_lxor_u8

    #---------------------------------------------------

    .global __xbrtime_atomic_lxor_s8
    .type __xbrtime_atomic_lxor_s8, @function
  __xbrtime_atomic_lxor_s8:
    eaddie e10, a2, 0
    eamoxor.d t0, a1, a0
    ret
    .size __xbrtime_atomic_lxor_s8, .-__xbrtime_atomic_lxor_s8

    #---------------------------------------------------

    .global __xbrtime_atomic_land_u4
    .type __xbrtime_atomic_land_u4, @function
  __xbrtime_atomic_land_u4:
    eaddie e10, a2, 0
    eamoand.w t0, a1, a0
    ret
    .size __xbrtime_atomic_land_u4, .-__xbrtime_atomic_land_u4

    #---------------------------------------------------

    .global __xbrtime_atomic_land_s4
    .type __xbrtime_atomic_land_s4, @function
  __xbrtime_atomic_land_s4:
    eaddie e10, a2, 0
    eamoand.w t0, a1, a0
    ret
    .size __xbrtime_atomic_land_s4, .-__xbrtime_atomic_land_s4

    #---------------------------------------------------

    .global __xbrtime_atomic_land_u8
    .type __xbrtime_atomic_land_u8, @function
  __xbrtime_atomic_land_u8:
    eaddie e10, a2, 0
    eamoand.d t0, a1, a0
    ret
    .size __xbrtime_atomic_land_u8, .-__xbrtime_atomic_land_u8

    #---------------------------------------------------

    .global __xbrtime_atomic_land_s8
    .type __xbrtime_atomic_land_s8, @function
  __xbrtime_atomic_land_s8:
    eaddie e10, a2, 0
    eamoand.d t0, a1, a0
    ret
    .size __xbrtime_atomic_land_s8, .-__xbrtime_atomic_land_s8

    #---------------------------------------------------

    .global __xbrtime_atomic_min_u4
    .type __xbrtime_atomic_min_u4, @function
  __xbrtime_atomic_min_u4:
    eaddie e10, a2, 0
    eamomin.w t0, a1, a0
    ret
    .size __xbrtime_atomic_min_u4, .-__xbrtime_atomic_min_u4

    #---------------------------------------------------

    #  .global __xbrtime_atomic_min_s4
    #  .type __xbrtime_atomic_min_s4, @function
    #  __xbrtime_atomic_min_s4:
    #  eaddie e10, 0, a2
    #  eamomin.w t0, a1, a0
    #  ret
    #  .size __xbrtime_atomic_min_s4, .-__xbrtime_atomic_min_s4

    #---------------------------------------------------

    .global __xbrtime_atomic_min_u8
    .type __xbrtime_atomic_min_u8, @function
  __xbrtime_atomic_min_u8:
    eaddie e10, a2, 0
    eamomin.d t0, a1, a0
    ret
    .size __xbrtime_atomic_min_u8, .-__xbrtime_atomic_min_u8

    #---------------------------------------------------

    #  .global __xbrtime_atomic_min_s8
    #  .type __xbrtime_atomic_min_s8, @function
    #  __xbrtime_atomic_min_s8:
    #  eaddie e10, 0, a2
    #  eamomin.d t0, a1, a0
    #  ret
    #  .size __xbrtime_atomic_min_s8, .-__xbrtime_atomic_min_s8

    #---------------------------------------------------

    .global __xbrtime_atomic_max_u4
    .type __xbrtime_atomic_max_u4, @function
  __xbrtime_atomic_max_u4:
    eaddie e10, a2, 0
    eamomax.w t0, a1, a0
    ret
    .size __xbrtime_atomic_max_u4, .-__xbrtime_atomic_max_u4

    #---------------------------------------------------

    #  .global __xbrtime_atomic_max_s4
    #  .type __xbrtime_atomic_max_s4, @function
    #  __xbrtime_atomic_max_s4:
    #  eaddie e10, 0, a2
    #  eamomax.w t0, a1, a0
    #  ret
    #  .size __xbrtime_atomic_max_s4, .-__xbrtime_atomic_max_s4

    #---------------------------------------------------

    .global __xbrtime_atomic_max_u8
    .type __xbrtime_atomic_max_u8, @function
    __xbrtime_atomic_max_u8:
    eaddie e10, a2, 0
    eamomax.d t0, a1, a0
    ret
    .size __xbrtime_atomic_max_u8, .-__xbrtime_atomic_max_u8

    #---------------------------------------------------

    #  .global __xbrtime_atomic_max_s8
    #  .type __xbrtime_atomic_max_s8, @function
    #  __xbrtime_atomic_max_s8:
    #  eaddie e10, 0, a2
    #  eamomax.d t0, a1, a0
    #  ret
    #  .size __xbrtime_atomic_max_s8, .-__xbrtime_atomic_max_s8

    #---------------------------------------------------

    .global __xbrtime_atomic_compare_swap_u4
    .type __xbrtime_atomic_compare_swap_u4, @function
  __xbrtime_atomic_compare_swap_u4:
    eaddie e10, a2, 0
    eamocas.w t0, a1, a0
    ret
    .size __xbrtime_atomic_compare_swap_u4, .-__xbrtime_atomic_compare_swap_u4

    #---------------------------------------------------

    .global __xbrtime_atomic_compare_swap_s4
    .type __xbrtime_atomic_compare_swap_s4, @function
  __xbrtime_atomic_compare_swap_s4:
    eaddie e10, a2, 0
    eamocas.w t0, a1, a0
    ret
    .size __xbrtime_atomic_compare_swap_s4, .-__xbrtime_atomic_compare_swap_s4

    #---------------------------------------------------

    .global __xbrtime_atomic_compare_swap_u8
    .type __xbrtime_atomic_compare_swap_u8, @function
  __xbrtime_atomic_compare_swap_u8:
    eaddie e10, a2, 0
    eamocas.d t0, a1, a0
    ret
    .size __xbrtime_atomic_compare_swap_u8, .-__xbrtime_atomic_compare_swap_u8

    #---------------------------------------------------

    .global __xbrtime_atomic_compare_swap_s8
    .type __xbrtime_atomic_compare_swap_s8, @function
  __xbrtime_atomic_compare_swap_s8:
    eaddie e10, a2, 0
    eamocas.d t0, a1, a0
    ret
    .size __xbrtime_atomic_compare_swap_s8, .-__xbrtime_atomic_compare_swap_s8

    #---------------------------------------------------
