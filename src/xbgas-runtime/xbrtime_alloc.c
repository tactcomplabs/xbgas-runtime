/*
 * _XBRTIME_ALLOC_C_
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
_XBRTIME_XLEN_ __xbrtime_get_remote_alloc( _XBRTIME_XLEN_ slot, int pe );
uint32_t xbrtime_decode_pe( int pe );
void __xbrtime_asm_quiet_fence();

_XBRTIME_XLEN_ __xbrtime_ltor(uint64_t remote, int pe){
  int i                     = 0;
  _XBRTIME_XLEN_ base_slot  = 0x00;
  _XBRTIME_XLEN_ offset     = 0x00;
  _XBRTIME_XLEN_ new_addr   = 0x00;

  if( xbrtime_mype() == pe ){
    /* return the same address block */
    return remote;
  }else{
    /* perform the address translation */
#ifdef XBGAS_DEBUG
  #if __riscv_xlen == 64
    printf( "XBGAS_DEBUG : PE=%d; Translating local address at pe=%d from 0x%"PRIu64"\n",
            xbrtime_mype(), pe, remote );
  #else
    printf( "XBGAS_DEBUG : PE=%d; Translating local address at pe=%d from 0x%"PRIu32"\n",
            xbrtime_mype(), pe, remote );
  #endif
#endif
    for( i=0; i<_XBRTIME_MEM_SLOTS_; i++ ){
      if( (remote >= __XBRTIME_CONFIG->_MMAP[i].start_addr) &&
          (remote < (__XBRTIME_CONFIG->_MMAP[i].start_addr+
                     __XBRTIME_CONFIG->_MMAP[i].size)) ){
        /* found our slot */
        base_slot = (_XBRTIME_XLEN_)(&__XBRTIME_CONFIG->_MMAP[i].start_addr);

        /* calculate the local offset */
        offset = remote - __XBRTIME_CONFIG->_MMAP[i].start_addr;

        new_addr = (__xbrtime_get_remote_alloc(base_slot,xbrtime_decode_pe(pe))
                                    +offset);
#ifdef XBGAS_DEBUG
  #if __riscv_xlen == 64
        printf( "XBGAS_DEBUG : PE=%d; Remote address in slot=%d at pe=%d is 0x%"PRIu64"\n",
                i, xbrtime_mype(), pe, new_addr );
  #else
        printf( "XBGAS_DEBUG : PE=%d; Remote address in slot=%d at pe=%d is 0x%"PRIu32"\n",
                i, xbrtime_mype(), pe, new_addr );
  #endif
#endif
        return new_addr;
      }
    }
  }
  /*
   * if we reach this point, there is an error in translation
   * return 0x00ull will cause a user access violation on the
   * memory operation and raise a segmentation fault
   *
   */
  return 0x00;
}

void *__xbrtime_shared_malloc( size_t sz ){
  void *ptr = NULL;
  int slot  = -1;
  int i     = 0;
  int done  = 0;

  /* find an open slot */
  while( (slot == -1) && (done != 1) ){
    if( __XBRTIME_CONFIG->_MMAP[i].size == 0 ){
      slot = i;
      done = 1;
    }
    i++;
    if( i==_XBRTIME_MEM_SLOTS_ ){
      done = 1;
    }
  }

  /* no open slots */
  if( slot == -1 ){
    return NULL;
  }

  /* attempt to create an allocation */
  ptr = malloc( sz );
  if( ptr == NULL ){
    return NULL;
  }

  /* memory is good, register the block */
#ifdef XBGAS_DEBUG
  printf( "XBGAS_DEBUG : PE=%d; ALLOCATING MEMORY IN SLOT=%d\n",
          xbrtime_mype(), slot );
#endif
  __XBRTIME_CONFIG->_MMAP[slot].size = sz;
  __XBRTIME_CONFIG->_MMAP[slot].start_addr = (_XBRTIME_XLEN_)(ptr);
  return ptr;
}

void __xbrtime_shared_free(void *ptr){
  _XBRTIME_XLEN_ mem = (_XBRTIME_XLEN_)(ptr);
  int i = 0;

  /*
   * walk the allocated blocks and attempt to free
   * the allocation
   *
   */
  for( i=0; i<_XBRTIME_MEM_SLOTS_; i++ ){
    if( (mem >= __XBRTIME_CONFIG->_MMAP[i].start_addr) &&
        (mem < (__XBRTIME_CONFIG->_MMAP[i].start_addr+
                __XBRTIME_CONFIG->_MMAP[i].size)) ){
      /* found the allocation */
      free( ptr );
      __XBRTIME_CONFIG->_MMAP[i].start_addr = 0x00;
      __XBRTIME_CONFIG->_MMAP[i].size = 0;
      return ;
    }
  }
}

extern void *xbrtime_malloc( size_t sz ){
  void *ptr = NULL;

  /* sanity check */
  if( sz == 0 ){
    return NULL;
  }else if( __XBRTIME_CONFIG == NULL ){
    return NULL;
  }

  ptr = __xbrtime_shared_malloc( sz );
  __xbrtime_asm_quiet_fence();

  return ptr;
}

extern void xbrtime_free( void *ptr ){
  if( ptr == NULL ){
    return ;
  }else if( __XBRTIME_CONFIG == NULL ){
    return ;
  }else if( __XBRTIME_CONFIG->_MMAP == NULL ){
    return ;
  }

  __xbrtime_shared_free(ptr);
  __xbrtime_asm_quiet_fence();
}
