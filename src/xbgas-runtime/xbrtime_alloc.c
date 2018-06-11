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

uint64_t __xbrtime_ltor(uint64_t remote, int pe){
  if( xbrtime_mype() == pe ){
    /* return the same address block */
    return remote;
#if 0
  }else{
    /* TODO: perform the address translation */
#endif
  }
  return remote;
}

uint64_t __xbrtime_find_base_addr( size_t nblocks ){
  uint64_t tmp        = 0x00ull;
  int success         = 0;
  XBRTIME_MEM_T *cur  = NULL;
  XBRTIME_MEM_T *wcur = NULL;

  /*
   * walk the allocated list
   * calculate each allocated blocks next block addr
   * if there exists no next block that encapsulates
   * that address, allocate it
   *
   */
  cur = __XBRTIME_CONFIG->_MMAP;
  while( cur != NULL ){

    /* calculate the next theoretical starting addr */
    tmp = cur->start_addr + ((cur->nblocks+1)*4096);

    /* search the list to see if there is a collision */
    wcur = __XBRTIME_CONFIG->_MMAP;
    while( wcur != NULL ){
      if( (tmp >= wcur->start_addr) &&
          (tmp < (wcur->start_addr + ((wcur->nblocks+1)*4096)) ) ){
        /* falls within memory range: failed */
        success = 1;
      }
      wcur = wcur->next;
    }

    /* if there is no collision, see if the total address space is in range */
    if( success == 0 ){
      return tmp;
    }

    cur = cur->next;
  }

  return 0x00ull;
}

void *__xbrtime_shared_malloc( size_t sz ){
  void *ptr = NULL;
  size_t nblocks = 0;
  uint64_t start = 0x00ull;
  XBRTIME_MEM_T *mem = NULL;
  XBRTIME_MEM_T *tmp = NULL;

  if( (sz%4096) > 0 ){
    nblocks = (sz/4096)+1;
  }else{
    nblocks = (sz/4096);
  }

  if( nblocks > __XBRTIME_CONFIG->_FREEBLOCKS ){
    return NULL;
  }

  if( __XBRTIME_CONFIG->_MMAP == NULL ){
    /* first allocation */
    mem = malloc( sizeof( XBRTIME_MEM_T ) );
    if( mem == NULL ){
      return NULL;
    }

    mem->nblocks = nblocks;
    mem->start_addr = __XBRTIME_CONFIG->_START_ADDR;
    mem->prev = NULL;
    mem->next = NULL;

    __XBRTIME_CONFIG->_FREEBLOCKS = __XBRTIME_CONFIG->_FREEBLOCKS-nblocks;
    __XBRTIME_CONFIG->_MMAP = mem;
    ptr = (void *)(mem->start_addr);
  }else{
    /* find an empty block */
    start = __xbrtime_find_base_addr(nblocks);
    if( start == 0x00ull ){
      return NULL;
    }

    mem = malloc( sizeof( XBRTIME_MEM_T ) );
    if( mem == NULL ){
      return NULL;
    }

    tmp = __XBRTIME_CONFIG->_MMAP;
    tmp->prev = mem;
    mem->nblocks = nblocks;
    mem->start_addr = start;
    mem->prev = NULL;
    mem->next = tmp;
    __XBRTIME_CONFIG->_FREEBLOCKS = __XBRTIME_CONFIG->_FREEBLOCKS-nblocks;
    ptr = (void *)(mem->start_addr);
  }

  return ptr;
}

void __xbrtime_shared_free(void *ptr){
  XBRTIME_MEM_T *mem = NULL;

  mem = __XBRTIME_CONFIG->_MMAP;
  while( mem != NULL ){
    if( mem->start_addr == (uint64_t)(ptr) ){
      /* found the correct block */
      __XBRTIME_CONFIG->_FREEBLOCKS += mem->nblocks;
      if( mem->prev != NULL ){
        mem->prev->next = mem->next;
      }else{
        /* removing the first block */
        if( mem->next == NULL ){
          /* last block */
          __XBRTIME_CONFIG->_MMAP = NULL;
        }else{
          __XBRTIME_CONFIG->_MMAP = mem->next;
        }
      }
      free( mem );
      return ;
    }
    mem = mem->next;
  }
}

extern void *xbrtime_malloc( size_t sz ){
  void *ptr = NULL;

  /* sanity check */
  if( sz == 0 ){
    return NULL;
  }else if( __XBRTIME_CONFIG == NULL ){
    return NULL;
  }else if( __XBRTIME_CONFIG->_FREEBLOCKS == 0 ){
    return NULL;
  }else if( sz > __XBRTIME_CONFIG->_MEMSIZE ){
    return NULL;
  }

  ptr = __xbrtime_shared_malloc( sz );

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
}
