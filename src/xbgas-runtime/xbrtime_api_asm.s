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
  eaddie e10, a2, 0
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
  eaddie e10, a2,0 #pe source 0
  eaddie e16, a2,0 #pe source 1
  eaddie e17, a2,0 #pe source 2
  eaddie e18, a2,0 #pe source 3
  add x16, x10, a3  #source addr 1
  add x17, x16, a3  #source addr 2
  add x18, x17, a3  #source addr 3
  add x19, x11, a3  #dest addr 1
  add x20, x19, a3  #dest addr 2
  add x21, x20, a3  #dest addr 3
  mv x31, zero
.get_u1_unr:
  elbu x22, 0(x10)  #load 0
  elbu x23, 0(x16)  #load 1
  elbu x24, 0(x17)  #load 2
  elbu x25, 0(x18)  #load 3
  add x10, x18, a3  #incr 0
  add x16, x10, a3  #incr 1
  add x17, x16, a3  #incr 2
  add x18, x17, a3  #incr 3
  add x31,x31,1     #incr loop trip
  sb x22, 0(x11)    #store 0
  add x11, x21, a3  #incr 0
  sb x23, 0(x19)    #store 1
  add x19, x11, a3  #incr 1
  sb x24, 0(x20)    #store 2
  add x20, x19, a3  #incr 2
  sb x25, 0(x21)    #store 3
  add x21, x20, a3  #incr 3
  bne x31,a4,.get_u1_unr

  beqz a5,.get_u1_unr_eject

  mv x31, zero
.get_u1_unr_epi:
  elbu x22, 0(x10)  #load 0
  add x31,x31,1     #incr loop trip
  add x10, x10, a3  #incr 0
  sb x22, 0(x11)    #store 0
  add x11, x11, a3  #incr 0
  bne x31,a5,.get_u1_unr_epi
.get_u1_unr_eject:
  ret
  .size __xbrtime_get_u1_unr, .-__xbrtime_get_u1_unr

  #---------------------------------------------------

  .global __xbrtime_get_u2_seq
  .type __xbrtime_get_u2_seq, @function
__xbrtime_get_u2_seq:
  eaddie e10, a2, 0
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
  eaddie e10, a2, 0 #pe source 0
  eaddie e16, a2, 0 #pe source 1
  eaddie e17, a2, 0 #pe source 2
  eaddie e18, a2, 0 #pe source 3
  add x16, x10, a3  #source addr 1
  add x17, x16, a3  #source addr 2
  add x18, x17, a3  #source addr 3
  add x19, x11, a3  #dest addr 1
  add x20, x19, a3  #dest addr 2
  add x21, x20, a3  #dest addr 3
  mv x31, zero
.get_u2_unr:
  elhu x22, 0(x10)  #load 0
  elhu x23, 0(x16)  #load 1
  elhu x24, 0(x17)  #load 2
  elhu x25, 0(x18)  #load 3
  add x10, x18, a3  #incr 0
  add x16, x10, a3  #incr 1
  add x17, x16, a3  #incr 2
  add x18, x17, a3  #incr 3
  add x31,x31,1     #incr loop trip
  sh x22, 0(x11)    #store 0
  add x11, x21, a3  #incr 0
  sh x23, 0(x19)    #store 1
  add x19, x11, a3  #incr 1
  sh x24, 0(x20)    #store 2
  add x20, x19, a3  #incr 2
  sh x25, 0(x21)    #store 3
  add x21, x20, a3  #incr 3
  bne x31,a4,.get_u2_unr

  beqz a5,.get_u2_unr_eject

  mv x31, zero
.get_u2_unr_epi:
  elhu x22, 0(x10)  #load 0
  add x31,x31,1     #incr loop trip
  add x10, x10, a3  #incr 0
  sh x22, 0(x11)    #store 0
  add x11, x11, a3  #incr 0
  bne x31,a5,.get_u2_unr_epi
.get_u2_unr_eject:
  ret
  .size __xbrtime_get_u2_unr, .-__xbrtime_get_u2_unr

  #---------------------------------------------------

  .global __xbrtime_get_u4_seq
  .type __xbrtime_get_u4_seq, @function
__xbrtime_get_u4_seq:
  eaddie e10, a2, 0
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
  eaddie e10, a2, 0 #pe source 0
  eaddie e16, a2, 0 #pe source 1
  eaddie e17, a2, 0 #pe source 2
  eaddie e18, a2, 0 #pe source 3
  add x16, x10, a3  #source addr 1
  add x17, x16, a3  #source addr 2
  add x18, x17, a3  #source addr 3
  add x19, x11, a3  #dest addr 1
  add x20, x19, a3  #dest addr 2
  add x21, x20, a3  #dest addr 3
  mv x31, zero
.get_u4_unr:
  elw x22, 0(x10)  #load 0
  elw x23, 0(x16)  #load 1
  elw x24, 0(x17)  #load 2
  elw x25, 0(x18)  #load 3
  add x10, x18, a3  #incr 0
  add x16, x10, a3  #incr 1
  add x17, x16, a3  #incr 2
  add x18, x17, a3  #incr 3
  add x31,x31,1     #incr loop trip
  sw x22, 0(x11)    #store 0
  add x11, x21, a3  #incr 0
  sw x23, 0(x19)    #store 1
  add x19, x11, a3  #incr 1
  sw x24, 0(x20)    #store 2
  add x20, x19, a3  #incr 2
  sw x25, 0(x21)    #store 3
  add x21, x20, a3  #incr 3
  bne x31,a4,.get_u4_unr

  beqz a5,.get_u4_unr_eject

  mv x31, zero
.get_u4_unr_epi:
  elw x22, 0(x10)  #load 0
  add x31,x31,1     #incr loop trip
  add x10, x10, a3  #incr 0
  sw x22, 0(x11)    #store 0
  add x11, x11, a3  #incr 0
  bne x31,a5,.get_u4_unr_epi
.get_u4_unr_eject:
  ret
  .size __xbrtime_get_u4_unr, .-__xbrtime_get_u4_unr

  #---------------------------------------------------

  .global __xbrtime_get_u8_seq
  .type __xbrtime_get_u8_seq, @function
__xbrtime_get_u8_seq:
  eaddie e10, a2, 0
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
  eaddie e10, a2, 0 #pe source 0
  eaddie e16, a2, 0 #pe source 1
  eaddie e17, a2, 0 #pe source 2
  eaddie e18, a2, 0 #pe source 3
  add x16, x10, a3  #source addr 1
  add x17, x16, a3  #source addr 2
  add x18, x17, a3  #source addr 3
  add x19, x11, a3  #dest addr 1
  add x20, x19, a3  #dest addr 2
  add x21, x20, a3  #dest addr 3
  mv x31, zero
.get_u8_unr:
  eld x22, 0(x10)  #load 0
  eld x23, 0(x16)  #load 1
  eld x24, 0(x17)  #load 2
  eld x25, 0(x18)  #load 3
  add x10, x18, a3  #incr 0
  add x16, x10, a3  #incr 1
  add x17, x16, a3  #incr 2
  add x18, x17, a3  #incr 3
  add x31,x31,1     #incr loop trip
  sd x22, 0(x11)    #store 0
  add x11, x21, a3  #incr 0
  sd x23, 0(x19)    #store 1
  add x19, x11, a3  #incr 1
  sd x24, 0(x20)    #store 2
  add x20, x19, a3  #incr 2
  sd x25, 0(x21)    #store 3
  add x21, x20, a3  #incr 3
  bne x31,a4,.get_u8_unr

  beqz a5,.get_u8_unr_eject

  mv x31, zero
.get_u8_unr_epi:
  eld x22, 0(x10)  #load 0
  add x31,x31,1     #incr loop trip
  add x10, x10, a3  #incr 0
  sd x22, 0(x11)    #store 0
  add x11, x11, a3  #incr 0
  bne x31,a5,.get_u8_unr_epi
.get_u8_unr_eject:
  ret
  .size __xbrtime_get_u8_unr, .-__xbrtime_get_u8_unr

  #---------------------------------------------------

  .global __xbrtime_get_s1_seq
  .type __xbrtime_get_s1_seq, @function
__xbrtime_get_s1_seq:
  eaddie e10, a2, 0
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
  eaddie e10, a2, 0 #pe source 0
  eaddie e16, a2, 0 #pe source 1
  eaddie e17, a2, 0 #pe source 2
  eaddie e18, a2, 0 #pe source 3
  add x16, x10, a3  #source addr 1
  add x17, x16, a3  #source addr 2
  add x18, x17, a3  #source addr 3
  add x19, x11, a3  #dest addr 1
  add x20, x19, a3  #dest addr 2
  add x21, x20, a3  #dest addr 3
  mv x31, zero
.get_s1_unr:
  elb x22, 0(x10)   #load 0
  elb x23, 0(x16)   #load 1
  elb x24, 0(x17)   #load 2
  elb x25, 0(x18)   #load 3
  add x10, x18, a3  #incr 0
  add x16, x10, a3  #incr 1
  add x17, x16, a3  #incr 2
  add x18, x17, a3  #incr 3
  add x31,x31,1     #incr loop trip
  sb x22, 0(x11)    #store 0
  add x11, x21, a3  #incr 0
  sb x23, 0(x19)    #store 1
  add x19, x11, a3  #incr 1
  sb x24, 0(x20)    #store 2
  add x20, x19, a3  #incr 2
  sb x25, 0(x21)    #store 3
  add x21, x20, a3  #incr 3
  bne x31,a4,.get_s1_unr

  beqz a5,.get_s1_unr_eject

  mv x31, zero
.get_s1_unr_epi:
  elb x22, 0(x10)   #load 0
  add x31,x31,1     #incr loop trip
  add x10, x10, a3  #incr 0
  sb x22, 0(x11)    #store 0
  add x11, x11, a3  #incr 0
  bne x31,a5,.get_s1_unr_epi
.get_s1_unr_eject:
  ret
  .size __xbrtime_get_s1_unr, .-__xbrtime_get_s1_unr

  #---------------------------------------------------

  .global __xbrtime_get_s2_seq
  .type __xbrtime_get_s2_seq, @function
__xbrtime_get_s2_seq:
  eaddie e10, a2, 0
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
  eaddie e10, a2, 0 #pe source 0
  eaddie e16, a2, 0 #pe source 1
  eaddie e17, a2, 0 #pe source 2
  eaddie e18, a2, 0 #pe source 3
  add x16, x10, a3  #source addr 1
  add x17, x16, a3  #source addr 2
  add x18, x17, a3  #source addr 3
  add x19, x11, a3  #dest addr 1
  add x20, x19, a3  #dest addr 2
  add x21, x20, a3  #dest addr 3
  mv x31, zero
.get_s2_unr:
  elh x22, 0(x10)   #load 0
  elh x23, 0(x16)   #load 1
  elh x24, 0(x17)   #load 2
  elh x25, 0(x18)   #load 3
  add x10, x18, a3  #incr 0
  add x16, x10, a3  #incr 1
  add x17, x16, a3  #incr 2
  add x18, x17, a3  #incr 3
  add x31,x31,1     #incr loop trip
  sh x22, 0(x11)    #store 0
  add x11, x21, a3  #incr 0
  sh x23, 0(x19)    #store 1
  add x19, x11, a3  #incr 1
  sh x24, 0(x20)    #store 2
  add x20, x19, a3  #incr 2
  sh x25, 0(x21)    #store 3
  add x21, x20, a3  #incr 3
  bne x31,a4,.get_s2_unr

  beqz a5,.get_s2_unr_eject

  mv x31, zero
.get_s2_unr_epi:
  elh x22, 0(x10)   #load 0
  add x31,x31,1     #incr loop trip
  add x10, x10, a3  #incr 0
  sh x22, 0(x11)    #store 0
  add x11, x11, a3  #incr 0
  bne x31,a5,.get_s2_unr_epi
.get_s2_unr_eject:
  ret
  .size __xbrtime_get_s2_unr, .-__xbrtime_get_s2_unr

  #---------------------------------------------------

  .global __xbrtime_get_s4_seq
  .type __xbrtime_get_s4_seq, @function
__xbrtime_get_s4_seq:
  eaddie e10, a2, 0
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
  eaddie e10, a2, 0 #pe source 0
  eaddie e16, a2, 0 #pe source 1
  eaddie e17, a2, 0 #pe source 2
  eaddie e18, a2, 0 #pe source 3
  add x16, x10, a3  #source addr 1
  add x17, x16, a3  #source addr 2
  add x18, x17, a3  #source addr 3
  add x19, x11, a3  #dest addr 1
  add x20, x19, a3  #dest addr 2
  add x21, x20, a3  #dest addr 3
  mv x31, zero
.get_s4_unr:
  elw x22, 0(x10)   #load 0
  elw x23, 0(x16)   #load 1
  elw x24, 0(x17)   #load 2
  elw x25, 0(x18)   #load 3
  add x10, x18, a3  #incr 0
  add x16, x10, a3  #incr 1
  add x17, x16, a3  #incr 2
  add x18, x17, a3  #incr 3
  add x31,x31,1     #incr loop trip
  sw x22, 0(x11)    #store 0
  add x11, x21, a3  #incr 0
  sw x23, 0(x19)    #store 1
  add x19, x11, a3  #incr 1
  sw x24, 0(x20)    #store 2
  add x20, x19, a3  #incr 2
  sw x25, 0(x21)    #store 3
  add x21, x20, a3  #incr 3
  bne x31,a4,.get_s4_unr

  beqz a5,.get_s4_unr_eject

  mv x31, zero
.get_s4_unr_epi:
  elw x22, 0(x10)   #load 0
  add x31,x31,1     #incr loop trip
  add x10, x10, a3  #incr 0
  sw x22, 0(x11)    #store 0
  add x11, x11, a3  #incr 0
  bne x31,a5,.get_s4_unr_epi
.get_s4_unr_eject:
  ret
  .size __xbrtime_get_s4_unr, .-__xbrtime_get_s4_unr

  #---------------------------------------------------

  .global __xbrtime_get_s8_seq
  .type __xbrtime_get_s8_seq, @function
__xbrtime_get_s8_seq:
  eaddie e10, a2, 0
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
  eaddie e10, a2, 0 #pe source 0
  eaddie e16, a2, 0 #pe source 1
  eaddie e17, a2, 0 #pe source 2
  eaddie e18, a2, 0 #pe source 3
  add x16, x10, a3  #source addr 1
  add x17, x16, a3  #source addr 2
  add x18, x17, a3  #source addr 3
  add x19, x11, a3  #dest addr 1
  add x20, x19, a3  #dest addr 2
  add x21, x20, a3  #dest addr 3
  mv x31, zero
.get_s8_unr:
  eld x22, 0(x10)   #load 0
  eld x23, 0(x16)   #load 1
  eld x24, 0(x17)   #load 2
  eld x25, 0(x18)   #load 3
  add x10, x18, a3  #incr 0
  add x16, x10, a3  #incr 1
  add x17, x16, a3  #incr 2
  add x18, x17, a3  #incr 3
  add x31,x31,1     #incr loop trip
  sd x22, 0(x11)    #store 0
  add x11, x21, a3  #incr 0
  sd x23, 0(x19)    #store 1
  add x19, x11, a3  #incr 1
  sd x24, 0(x20)    #store 2
  add x20, x19, a3  #incr 2
  sd x25, 0(x21)    #store 3
  add x21, x20, a3  #incr 3
  bne x31,a4,.get_s8_unr

  beqz a5,.get_s8_unr_eject

  mv x31, zero
.get_s8_unr_epi:
  eld x22, 0(x10)   #load 0
  add x31,x31,1     #incr loop trip
  add x10, x10, a3  #incr 0
  sd x22, 0(x11)    #store 0
  add x11, x11, a3  #incr 0
  bne x31,a5,.get_s1_unr_epi
.get_s8_unr_eject:
  ret
  .size __xbrtime_get_s8_unr, .-__xbrtime_get_s8_unr

  #---------------------------------------------------

  .global __xbrtime_put_u1_seq
  .type __xbrtime_put_u1_seq, @function
__xbrtime_put_u1_seq:
  eaddie e11, a2, 0
  mv x31, zero
.put_u1_seq:
  lbu x30, 0(a0)
  add a0, a0, a4
  add x31,x31,1
  esb x30, 0(a1)
  add a1,a1,a4
  bne x31,a3,.put_u1_seq
  ret
  .size __xbrtime_put_u1_seq, .-__xbrtime_put_u1_seq

  #---------------------------------------------------

  .global __xbrtime_put_u1_unr
  .type __xbrtime_put_u1_unr, @function
__xbrtime_put_u1_unr:
  eaddie e11, a2, 0   #pe dest 0
  eaddie e19, a2, 0   #pe dest 1
  eaddie e20, a2, 0   #pe dest 2
  eaddie e21, a2, 0   #pe dest 3
  add x16, x10, a3    #source addr 1
  add x17, x16, a3    #source addr 2
  add x18, x17, a3    #source addr 3
  add x19, x11, a3    #dest addr 1
  add x20, x19, a3    #dest addr 2
  add x21, x20, a3    #dest addr3
  mv x31, zero
.put_u1_unr:
  lbu x22, 0(x10)     #load 0
  lbu x23, 0(x16)     #load 1
  lbu x24, 0(x17)     #load 2
  lbu x25, 0(x18)     #load 3
  add x10, x18, a3    #incr 0
  add x16, x10, a3    #incr 1
  add x17, x16, a3    #incr 2
  add x18, x17, a3    #incr 3
  add x31, x31, 1     #incr loop trip
  esb x22, 0(x11)     #store 0
  add x11, x21, a3    #incr 0
  esb x23, 0(x19)     #store 1
  add x19, x11, a3    #incr 1
  esb x24, 0(x20)     #store 2
  add x20, x19, a3    #incr 2
  esb x25, 0(x21)     #store 3
  add x21, x20, a3    #incr 3
  bne x31,a4,.put_u1_unr

  beqz a5,.put_u1_unr_eject

  mv x31, zero
.put_u1_unr_epi:
  lbu x22, 0(x10)     #load 0
  add x31, x31, 1     #incr loop trip
  add x10, x10, a3    #incr 0
  esb x22, 0(x11)     #store 0
  add x11, x11, a3    #incr 0
  bne x31,a5,.put_u1_unr_epi
.put_u1_unr_eject:
  ret
  .size __xbrtime_put_u1_unr, .-__xbrtime_put_u1_unr

  #---------------------------------------------------

  .global __xbrtime_put_u2_seq
  .type __xbrtime_put_u2_seq, @function
__xbrtime_put_u2_seq:
  eaddie e11, a2, 0
  mv x31, zero
.put_u2_seq:
  lhu x30, 0(a0)
  add a0, a0, a4
  add x31,x31,1
  esh x30, 0(a1)
  add a1,a1,a4
  bne x31,a3,.put_u2_seq
  ret
  .size __xbrtime_put_u2_seq, .-__xbrtime_put_u2_seq

  #---------------------------------------------------

  .global __xbrtime_put_u2_unr
  .type __xbrtime_put_u2_unr, @function
__xbrtime_put_u2_unr:
  eaddie e11, a2, 0   #pe dest 0
  eaddie e19, a2, 0   #pe dest 1
  eaddie e20, a2, 0   #pe dest 2
  eaddie e21, a2, 0   #pe dest 3
  add x16, x10, a3    #source addr 1
  add x17, x16, a3    #source addr 2
  add x18, x17, a3    #source addr 3
  add x19, x11, a3    #dest addr 1
  add x20, x19, a3    #dest addr 2
  add x21, x20, a3    #dest addr3
  mv x31, zero
.put_u2_unr:
  lhu x22, 0(x10)     #load 0
  lhu x23, 0(x16)     #load 1
  lhu x24, 0(x17)     #load 2
  lhu x25, 0(x18)     #load 3
  add x10, x18, a3    #incr 0
  add x16, x10, a3    #incr 1
  add x17, x16, a3    #incr 2
  add x18, x17, a3    #incr 3
  add x31, x31, 1     #incr loop trip
  esh x22, 0(x11)     #store 0
  add x11, x21, a3    #incr 0
  esh x23, 0(x19)     #store 1
  add x19, x11, a3    #incr 1
  esh x24, 0(x20)     #store 2
  add x20, x19, a3    #incr 2
  esh x25, 0(x21)     #store 3
  add x21, x20, a3    #incr 3
  bne x31,a4,.put_u2_unr

  beqz a5,.put_u2_unr_eject

  mv x31, zero
.put_u2_unr_epi:
  lhu x22, 0(x10)     #load 0
  add x31, x31, 1     #incr loop trip
  add x10, x10, a3    #incr 0
  esh x22, 0(x11)     #store 0
  add x11, x11, a3    #incr 0
  bne x31,a5,.put_u2_unr_epi
.put_u2_unr_eject:
  ret
  .size __xbrtime_put_u2_unr, .-__xbrtime_put_u2_unr

  #---------------------------------------------------

  .global __xbrtime_put_u4_seq
  .type __xbrtime_put_u4_seq, @function
__xbrtime_put_u4_seq:
  eaddie e11, a2, 0
  mv x31, zero
.put_u4_seq:
  lwu x30, 0(a0)
  add a0, a0, a4
  add x31,x31,1
  esw x30, 0(a1)
  add a1,a1,a4
  bne x31,a3,.put_u4_seq
  ret
  .size __xbrtime_put_u4_seq, .-__xbrtime_put_u4_seq

  #---------------------------------------------------

  .global __xbrtime_put_u4_unr
  .type __xbrtime_put_u4_unr, @function
__xbrtime_put_u4_unr:
  eaddie e11, a2, 0   #pe dest 0
  eaddie e19, a2, 0   #pe dest 1
  eaddie e20, a2, 0   #pe dest 2
  eaddie e21, a2, 0   #pe dest 3
  add x16, x10, a3    #source addr 1
  add x17, x16, a3    #source addr 2
  add x18, x17, a3    #source addr 3
  add x19, x11, a3    #dest addr 1
  add x20, x19, a3    #dest addr 2
  add x21, x20, a3    #dest addr3
  mv x31, zero
.put_u4_unr:
  lwu x22, 0(x10)     #load 0
  lwu x23, 0(x16)     #load 1
  lwu x24, 0(x17)     #load 2
  lwu x25, 0(x18)     #load 3
  add x10, x18, a3    #incr 0
  add x16, x10, a3    #incr 1
  add x17, x16, a3    #incr 2
  add x18, x17, a3    #incr 3
  add x31, x31, 1     #incr loop trip
  esw x22, 0(x11)     #store 0
  add x11, x21, a3    #incr 0
  esw x23, 0(x19)     #store 1
  add x19, x11, a3    #incr 1
  esw x24, 0(x20)     #store 2
  add x20, x19, a3    #incr 2
  esw x25, 0(x21)     #store 3
  add x21, x20, a3    #incr 3
  bne x31,a4,.put_u4_unr

  beqz a5,.put_u4_unr_eject

  mv x31, zero
.put_u4_unr_epi:
  lwu x22, 0(x10)     #load 0
  add x31, x31, 1     #incr loop trip
  add x10, x10, a3    #incr 0
  esw x22, 0(x11)     #store 0
  add x11, x11, a3    #incr 0
  bne x31,a5,.put_u4_unr_epi
.put_u4_unr_eject:
  ret
  .size __xbrtime_put_u4_unr, .-__xbrtime_put_u4_unr

  #---------------------------------------------------

  .global __xbrtime_put_u8_seq
  .type __xbrtime_put_u8_seq, @function
__xbrtime_put_u8_seq:
  eaddie e11, a2, 0
  mv x31, zero
.put_u8_seq:
  ld x30, 0(a0)
  add a0, a0, a4
  add x31,x31,1
  esd x30, 0(a1)
  add a1,a1,a4
  bne x31,a3,.put_u8_seq
  ret
  .size __xbrtime_put_u8_seq, .-__xbrtime_put_u8_seq

  #---------------------------------------------------

  .global __xbrtime_put_u8_unr
  .type __xbrtime_put_u8_unr, @function
__xbrtime_put_u8_unr:
  eaddie e11, a2, 0   #pe dest 0
  eaddie e19, a2, 0   #pe dest 1
  eaddie e20, a2, 0   #pe dest 2
  eaddie e21, a2, 0   #pe dest 3
  add x16, x10, a3    #source addr 1
  add x17, x16, a3    #source addr 2
  add x18, x17, a3    #source addr 3
  add x19, x11, a3    #dest addr 1
  add x20, x19, a3    #dest addr 2
  add x21, x20, a3    #dest addr3
  mv x31, zero
.put_u8_unr:
  ld x22, 0(x10)      #load 0
  ld x23, 0(x16)      #load 1
  ld x24, 0(x17)      #load 2
  ld x25, 0(x18)      #load 3
  add x10, x18, a3    #incr 0
  add x16, x10, a3    #incr 1
  add x17, x16, a3    #incr 2
  add x18, x17, a3    #incr 3
  add x31, x31, 1     #incr loop trip
  esd x22, 0(x11)     #store 0
  add x11, x21, a3    #incr 0
  esd x23, 0(x19)     #store 1
  add x19, x11, a3    #incr 1
  esd x24, 0(x20)     #store 2
  add x20, x19, a3    #incr 2
  esd x25, 0(x21)     #store 3
  add x21, x20, a3    #incr 3
  bne x31,a4,.put_u8_unr

  beqz a5,.put_u8_unr_eject

  mv x31, zero
.put_u8_unr_epi:
  ld x22, 0(x10)      #load 0
  add x31, x31, 1     #incr loop trip
  add x10, x10, a3    #incr 0
  esd x22, 0(x11)     #store 0
  add x11, x11, a3    #incr 0
  bne x31,a5,.put_u8_unr_epi
.put_u8_unr_eject:
  ret
  .size __xbrtime_put_u8_unr, .-__xbrtime_put_u8_unr

  #---------------------------------------------------

  .global __xbrtime_put_s1_seq
  .type __xbrtime_put_s1_seq, @function
__xbrtime_put_s1_seq:
  eaddie e11, a2, 0
  mv x31, zero
.put_s1_seq:
  lb x30, 0(a0)
  add a0, a0, a4
  add x31,x31,1
  esb x30, 0(a1)
  add a1,a1,a4
  bne x31,a3,.put_s1_seq
  ret
  .size __xbrtime_put_s1_seq, .-__xbrtime_put_s1_seq

  #---------------------------------------------------

  .global __xbrtime_put_s1_unr
  .type __xbrtime_put_s1_unr, @function
__xbrtime_put_s1_unr:
  eaddie e11, a2, 0   #pe dest 0
  eaddie e19, a2, 0   #pe dest 1
  eaddie e20, a2, 0   #pe dest 2
  eaddie e21, a2, 0   #pe dest 3
  add x16, x10, a3    #source addr 1
  add x17, x16, a3    #source addr 2
  add x18, x17, a3    #source addr 3
  add x19, x11, a3    #dest addr 1
  add x20, x19, a3    #dest addr 2
  add x21, x20, a3    #dest addr3
  mv x31, zero
.put_s1_unr:
  lb x22, 0(x10)      #load 0
  lb x23, 0(x16)      #load 1
  lb x24, 0(x17)      #load 2
  lb x25, 0(x18)      #load 3
  add x10, x18, a3    #incr 0
  add x16, x10, a3    #incr 1
  add x17, x16, a3    #incr 2
  add x18, x17, a3    #incr 3
  add x31, x31, 1     #incr loop trip
  esb x22, 0(x11)     #store 0
  add x11, x21, a3    #incr 0
  esb x23, 0(x19)     #store 1
  add x19, x11, a3    #incr 1
  esb x24, 0(x20)     #store 2
  add x20, x19, a3    #incr 2
  esb x25, 0(x21)     #store 3
  add x21, x20, a3    #incr 3
  bne x31,a4,.put_s1_unr

  beqz a5,.put_s1_unr_eject

  mv x31, zero
.put_s1_unr_epi:
  lb x22, 0(x10)      #load 0
  add x31, x31, 1     #incr loop trip
  add x10, x10, a3    #incr 0
  esb x22, 0(x11)     #store 0
  add x11, x11, a3    #incr 0
  bne x31,a5,.put_s1_unr_epi
.put_s1_unr_eject:
  ret
  .size __xbrtime_put_s1_unr, .-__xbrtime_put_s1_unr

  #---------------------------------------------------

  .global __xbrtime_put_s2_seq
  .type __xbrtime_put_s2_seq, @function
__xbrtime_put_s2_seq:
  eaddie e11, a2, 0
  mv x31, zero
.put_s2_seq:
  lh x30, 0(a0)
  add a0, a0, a4
  add x31,x31,1
  esh x30, 0(a1)
  add a1,a1,a4
  bne x31,a3,.put_s2_seq
  ret
  .size __xbrtime_put_s2_seq, .-__xbrtime_put_s2_seq

  #---------------------------------------------------

  .global __xbrtime_put_s2_unr
  .type __xbrtime_put_s2_unr, @function
__xbrtime_put_s2_unr:
  eaddie e11, a2, 0   #pe dest 0
  eaddie e19, a2, 0   #pe dest 1
  eaddie e20, a2, 0   #pe dest 2
  eaddie e21, a2, 0   #pe dest 3
  add x16, x10, a3    #source addr 1
  add x17, x16, a3    #source addr 2
  add x18, x17, a3    #source addr 3
  add x19, x11, a3    #dest addr 1
  add x20, x19, a3    #dest addr 2
  add x21, x20, a3    #dest addr3
  mv x31, zero
.put_s2_unr:
  lh x22, 0(x10)      #load 0
  lh x23, 0(x16)      #load 1
  lh x24, 0(x17)      #load 2
  lh x25, 0(x18)      #load 3
  add x10, x18, a3    #incr 0
  add x16, x10, a3    #incr 1
  add x17, x16, a3    #incr 2
  add x18, x17, a3    #incr 3
  add x31, x31, 1     #incr loop trip
  esh x22, 0(x11)     #store 0
  add x11, x21, a3    #incr 0
  esh x23, 0(x19)     #store 1
  add x19, x11, a3    #incr 1
  esh x24, 0(x20)     #store 2
  add x20, x19, a3    #incr 2
  esh x25, 0(x21)     #store 3
  add x21, x20, a3    #incr 3
  bne x31,a4,.put_s2_unr

  beqz a5,.put_s2_unr_eject

  mv x31, zero
.put_s2_unr_epi:
  lh x22, 0(x10)      #load 0
  add x31, x31, 1     #incr loop trip
  add x10, x10, a3    #incr 0
  esh x22, 0(x11)     #store 0
  add x11, x11, a3    #incr 0
  bne x31,a5,.put_s2_unr_epi
.put_s2_unr_eject:
  ret
  .size __xbrtime_put_s2_unr, .-__xbrtime_put_s2_unr

  #---------------------------------------------------

  .global __xbrtime_put_s4_seq
  .type __xbrtime_put_s4_seq, @function
__xbrtime_put_s4_seq:
  eaddie e11, a2, 0
  mv x31, zero
.put_s4_seq:
  lw x30, 0(a0)
  add a0, a0, a4
  add x31,x31,1
  esw x30, 0(a1)
  add a1,a1,a4
  bne x31,a3,.put_s4_seq
  ret
  .size __xbrtime_put_s4_seq, .-__xbrtime_put_s4_seq

  #---------------------------------------------------

  .global __xbrtime_put_s4_unr
  .type __xbrtime_put_s4_unr, @function
__xbrtime_put_s4_unr:
  eaddie e11, a2, 0   #pe dest 0
  eaddie e19, a2, 0   #pe dest 1
  eaddie e20, a2, 0   #pe dest 2
  eaddie e21, a2, 0   #pe dest 3
  add x16, x10, a3    #source addr 1
  add x17, x16, a3    #source addr 2
  add x18, x17, a3    #source addr 3
  add x19, x11, a3    #dest addr 1
  add x20, x19, a3    #dest addr 2
  add x21, x20, a3    #dest addr3
  mv x31, zero
.put_s4_unr:
  lw x22, 0(x10)      #load 0
  lw x23, 0(x16)      #load 1
  lw x24, 0(x17)      #load 2
  lw x25, 0(x18)      #load 3
  add x10, x18, a3    #incr 0
  add x16, x10, a3    #incr 1
  add x17, x16, a3    #incr 2
  add x18, x17, a3    #incr 3
  add x31, x31, 1     #incr loop trip
  esw x22, 0(x11)     #store 0
  add x11, x21, a3    #incr 0
  esw x23, 0(x19)     #store 1
  add x19, x11, a3    #incr 1
  esw x24, 0(x20)     #store 2
  add x20, x19, a3    #incr 2
  esw x25, 0(x21)     #store 3
  add x21, x20, a3    #incr 3
  bne x31,a4,.put_s4_unr

  beqz a5,.put_s4_unr_eject

  mv x31, zero
.put_s4_unr_epi:
  lw x22, 0(x10)      #load 0
  add x31, x31, 1     #incr loop trip
  add x10, x10, a3    #incr 0
  esw x22, 0(x11)     #store 0
  add x11, x11, a3    #incr 0
  bne x31,a5,.put_s4_unr_epi
.put_s4_unr_eject:
  ret
  .size __xbrtime_put_s4_unr, .-__xbrtime_put_s4_unr

  #---------------------------------------------------

  .global __xbrtime_put_s8_seq
  .type __xbrtime_put_s8_seq, @function
__xbrtime_put_s8_seq:
  eaddie e11, a2, 0
  mv x31, zero
.put_s8_seq:
  ld x30, 0(a0)
  add a0, a0, a4
  add x31,x31,1
  esd x30, 0(a1)
  add a1,a1,a4
  bne x31,a3,.put_s8_seq
  ret
  .size __xbrtime_put_s8_seq, .-__xbrtime_put_s8_seq

  #---------------------------------------------------

  .global __xbrtime_put_s8_unr
  .type __xbrtime_put_s8_unr, @function
__xbrtime_put_s8_unr:
  eaddie e11, a2, 0   #pe dest 0
  eaddie e19, a2, 0   #pe dest 1
  eaddie e20, a2, 0   #pe dest 2
  eaddie e21, a2, 0   #pe dest 3
  add x16, x10, a3    #source addr 1
  add x17, x16, a3    #source addr 2
  add x18, x17, a3    #source addr 3
  add x19, x11, a3    #dest addr 1
  add x20, x19, a3    #dest addr 2
  add x21, x20, a3    #dest addr3
  mv x31, zero
.put_s8_unr:
  ld x22, 0(x10)      #load 0
  ld x23, 0(x16)      #load 1
  ld x24, 0(x17)      #load 2
  ld x25, 0(x18)      #load 3
  add x10, x18, a3    #incr 0
  add x16, x10, a3    #incr 1
  add x17, x16, a3    #incr 2
  add x18, x17, a3    #incr 3
  add x31, x31, 1     #incr loop trip
  esd x22, 0(x11)     #store 0
  add x11, x21, a3    #incr 0
  esd x23, 0(x19)     #store 1
  add x19, x11, a3    #incr 1
  esd x24, 0(x20)     #store 2
  add x20, x19, a3    #incr 2
  esd x25, 0(x21)     #store 3
  add x21, x20, a3    #incr 3
  bne x31,a4,.put_s8_unr

  beqz a5,.put_s8_unr_eject

  mv x31, zero
.put_s8_unr_epi:
  ld x22, 0(x10)      #load 0
  add x31, x31, 1     #incr loop trip
  add x10, x10, a3    #incr 0
  esd x22, 0(x11)     #store 0
  add x11, x11, a3    #incr 0
  bne x31,a5,.put_s8_unr_epi
.put_s8_unr_eject:
  ret
  .size __xbrtime_put_s8_unr, .-__xbrtime_put_s8_unr

#-- EOF
