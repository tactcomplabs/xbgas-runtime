#
# _XBRTIME_CTOR_ASM_S_
#
# Copyright (C) 2017-2018 Tactical Computing Laboratories, LLC
# All Rights Reserved
# contact@tactcomplabs.com
#
# This file is a part of the XBGAS-RUNTIME package.  For license
# information, see the LICENSE file in the top level directory
# of the distribution.
#

  .file "xbrtime_ctor_asm.s"
  .text
  .align 1

  .global __xbrtime_ctor_reg_reset
  .type __xbrtime_ctor_reg_reset, @function
__xbrtime_ctor_reg_reset:
  eaddie e14, 0, zero
  eaddie e15, 0, zero
  eaddie e16, 0, zero
  eaddie e17, 0, zero
  eaddie e18, 0, zero
  eaddie e19, 0, zero
  eaddie e20, 0, zero
  eaddie e21, 0, zero
  eaddie e22, 0, zero
  eaddie e23, 0, zero
  eaddie e24, 0, zero
  eaddie e25, 0, zero
  eaddie e26, 0, zero
  eaddie e27, 0, zero
  eaddie e28, 0, zero
  eaddie e29, 0, zero
  eaddie e30, 0, zero
  eaddie e31, 0, zero
  ret
  .size __xbrtime_ctor_reg_reset, .-__xbrtime_ctor_reg_reset

#-- EOF
