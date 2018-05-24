#
# _XBRTIME_UTIL_ASM_S_
#
# Copyright (C) 2017-2018 Tactical Computing Laboratories, LLC
# All Rights Reserved
# contact@tactcomplabs.com
#
# This file is a part of the XBGAS-RUNTIME package.  For license
# information, see the LICENSE file in the top level directory
# of the distribution.
#

  .file "xbrtime_util_asm.s"
  .text
  .align 1

  .global __xbrtime_asm_get_id
  .type __xbrtime_asm_get_id, @function
__xbrtime_asm_get_id:
  eaddi ra,0,e10
  ret
  .size __xbrtime_asm_get_id, .-__xbrtime_asm_get_id

  .global __xbrtime_asm_get_npes
  .type __xbrtime_asm_get_npes, @function
__xbrtime_asm_get_npes:
  eaddi ra,0,e11
  ret
  .size __xbrtime_asm_get_npes, .-__xbrtime_asm_get_npes

  .global __xbrtime_asm_get_memsize
  .type __xbrtime_asm_get_memsize, @function
__xbrtime_asm_get_memsize:
  eaddi ra,0,e12
  .size __xbrtime_asm_get_memsize, .-__xbrtime_asm_get_memsize

  .globl __xbrtime_asm_fence
  .type __xbrtime_asm_fence, @function
__xbrtime_asm_fence:
  fence.i
  .size __xbrtime_asm_fence, .-__xbrtime_asm_fence

  .globl __xbrtime_asm_quiet_fence
  .type __xbrtime_asm_quiet_fence, @function
__xbrtime_asm_quiet_fence:
  fence
  .size __xbrtime_asm_quiet_fence, .-__xbrtime_asm_quiet_fence

#-- EOF
