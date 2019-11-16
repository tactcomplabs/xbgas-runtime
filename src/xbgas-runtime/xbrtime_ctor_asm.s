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
  eaddie e14, zero, 0
  eaddie e15, zero, 0
  eaddie e16, zero, 0
  eaddie e17, zero, 0
  eaddie e18, zero, 0
  eaddie e19, zero, 0
  eaddie e20, zero, 0
  eaddie e21, zero, 0
  eaddie e22, zero, 0
  eaddie e23, zero, 0
  eaddie e24, zero, 0
  eaddie e25, zero, 0
  eaddie e26, zero, 0
  eaddie e27, zero, 0
  eaddie e28, zero, 0
  eaddie e29, zero, 0
  eaddie e30, zero, 0
  eaddie e31, zero, 0
  ret
  .size __xbrtime_ctor_reg_reset, .-__xbrtime_ctor_reg_reset

#-- EOF
