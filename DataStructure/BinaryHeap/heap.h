#ifndef KBW_HEAP
#define KBW_HEAP

/** @{ */
/**
 * @file
 *
 * cp_heap is a generic heap implementation based on libheap and contributed 
 * to cprops by Kyle Wheeler. The original copyright notice follows.
 * 
 * This file (the header file for a generic C heap implementation) is licensed
 * under the BSD license, and is copyrighted to Kyle Wheeler, 2003. Feel free
 * to distribute and use as you see fit, as long as this copyright notice stays
 * with the code.
 * 
 */

#include "common.h"
#include <errno.h>

//#define __TRACE__
#define DEBUGMSG printf

typedef struct _heap
{
    void **heap;
    unsigned int heap_height;
    unsigned int heap_end;
    unsigned int heap_length;

    int mode;
    cp_compare_fn comp;
    cp_copy_fn copy;
    cp_destructor_fn dtr;

    cp_mutex *lock;
    cp_thread txowner;
} cp_heap;

void heap_info(cp_heap *h);

/* default create functions - creates a synchronized heap. 
 *
 * note that in contrast to he original libheap function, the compare functions
 * follows strcmp semantics - ie returns < 0 if the first parameter is smaller 
 * than the second, zero on equality and greater than zero if the second 
 * parameter is smaller. 
 */
cp_heap *cp_heap_create(cp_compare_fn comp);

cp_heap *cp_heap_create_by_option(int mode, 
                                  int initial_size,
                                  cp_compare_fn comp, 
                                  cp_copy_fn copy, 
                                  cp_destructor_fn dtr);

/* push an item */
int cp_heap_push(cp_heap *h, void *in);

/* get the item at the top of the heap */
void *cp_heap_peek(cp_heap *h);

/* remove the item at the top of the heap */
void *cp_heap_pop(cp_heap *h);

/* contract the heap to the minimal size to accomodate current item count */
int cp_heap_contract(cp_heap *h);

/* destroy the heap */
void cp_heap_destroy(cp_heap *h);

/* return the number of items stored on the heap */
unsigned int cp_heap_count(cp_heap *h);

/* return the maximal number of items that can be stored before another resize
 * is triggered 
 */
unsigned int cp_heap_size(cp_heap *h);

int cp_heap_verify(cp_heap *h);


/* run a callback on all stored elements */
void cp_heap_callback(cp_heap *h, cp_callback_fn cb, void *prm);

/* lock the heap for a transaction, ie performing a sequence of jointly 
 * synchronized operations
 */
int cp_heap_lock(cp_heap *h);

/* release a transaction lock */
int cp_heap_unlock(cp_heap *h);

/* internal - transaction aware locking */
int cp_heap_txlock(cp_heap *h);

/* internal - transaction aware unlock */
int cp_heap_txunlock(cp_heap *h);

/* retrieve the current mode setting */
int cp_heap_get_mode(cp_heap *h);

/* set the specified mode bits */
int cp_heap_set_mode(cp_heap *h, int mode);

/* unset the specified mode bits */
int cp_heap_unset_mode(cp_heap *h, int mode);


/** @} */

#endif
