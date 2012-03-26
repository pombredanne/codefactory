#ifndef _CP_SPLAY_H
#define _CP_SPLAY_H

/** @{ */
/**
 * @file
 *
 * splay tree definitions
 *
 * splay trees move the node last accessed to the root of the tree as part of
 * every operation. This makes tree operations slower than in AVL or red-black 
 * trees. A natural application for splay trees would be in implementing a 
 * cache, where a small number of keys out of a large search space are expected
 * to be accessed at a significantly higher probability than average.
 *
 * The splay tree was introduced by Daniel D. Sleator and Robert E. Tarjan in
 * an article titled Self-Adjusting Binary Search Trees, 1985
 */

#include "common.h"
#include "vector.h"

struct _cp_splaytree;

typedef struct _cp_splaynode
{
	void *key;
	void *value;
	
	struct _cp_splaynode *left;
	struct _cp_splaynode *right;
} cp_splaynode;

/* (internal) allocate a new node */
cp_splaynode *cp_splaynode_create(void *key, void *value);
/* (internal) deallocate a node */
void cp_splaytree_destroy_node(struct _cp_splaytree *tree, cp_splaynode *node);
/* (internal) deallocate a node and its subnodes */
void cp_splaytree_destroy_node_deep(struct _cp_splaytree *owner, cp_splaynode *node);


/* tree wrapper object */
typedef struct _cp_splaytree
{
	cp_splaynode *root;          /* root node */
	
	int items;                   /* item count */

	int mode;					 /* mode flags */
	cp_compare_fn cmp;           /* key comparison function */
	cp_copy_fn key_copy;         /* key copy function */
	cp_destructor_fn key_dtr;    /* key destructor */
	cp_copy_fn value_copy;       /* value copy function */
	cp_destructor_fn value_dtr;  /* value destructor */
	cp_lock *lock;
	cp_thread txowner;           /* set if a transaction is in progress */
	int txtype;                  /* lock type */

} cp_splaytree;

/* 
 * default create function - equivalent to create_by_option with mode 
 * COLLECTION_MODE_NOSYNC
 */
cp_splaytree *cp_splaytree_create(cp_compare_fn cmp);

/*
 * complete parameter create function. Note that setting COLLECTION_MODE_COPY
 * without specifying a copy function for either keys or values will result in
 * keys or values respectively being inserted by value, with no copying 
 * performed. Similarly, setting COLLECTION_MODE_DEEP without specifying a 
 * destructor function for keys or values will result in no destructor call
 * for keys or values respectively. This allows using the copy/deep mechanisms
 * for keys only, values only or both.
 */
cp_splaytree *
	cp_splaytree_create_by_option(int mode, cp_compare_fn cmp, 
								cp_copy_fn key_copy, cp_destructor_fn key_dtr,
								cp_copy_fn val_copy, cp_destructor_fn val_dtr);

/* 
 * recursively destroy the tree structure 
 */
void cp_splaytree_destroy(cp_splaytree *tree);

/*
 * recursively destroy the tree structure with the given destructor functions
 */
void cp_splaytree_destroy_custom(cp_splaytree *tree, 
							   cp_destructor_fn key_dtr,
							   cp_destructor_fn val_dtr);

/* insertion function */
void *cp_splaytree_insert(cp_splaytree *tree, void *key, void *value);

/* retrieve the value mapped to the given key */
void *cp_splaytree_get(cp_splaytree *tree, void *key);

/* find the value of the closest key by operator */
void *cp_splaytree_find(cp_splaytree *tree, void *key, cp_op op);

/* return non-zero if a mapping for 'key' could be found */
int cp_splaytree_contains(cp_splaytree *tree, void *key);

/* delete a mapping */
void *cp_splaytree_delete(cp_splaytree *tree, void *key);

/* 
 * perform a pre-order iteration over the tree, calling 'callback' on each 
 * node
 */
int cp_splaytree_callback_preorder(cp_splaytree *tree, 
								 cp_callback_fn callback, 
								 void *prm);
/* 
 * perform an in-order iteration over the tree, calling 'callback' on each 
 * node
 */
int cp_splaytree_callback(cp_splaytree *tree, cp_callback_fn callback, void *prm);
/* 
 * perform a post-order iteration over the tree, calling 'callback' on each 
 * node
 */
int cp_splaytree_callback_postorder(cp_splaytree *tree, 
								  cp_callback_fn callback, 
								  void *prm);

/* return the number of mappings in the tree */
int cp_splaytree_count(cp_splaytree *tree);

/* 
 * lock tree for reading or writing as specified by type parameter. 
 */
int cp_splaytree_lock(cp_splaytree *tree, int type);
/* read lock */
#define cp_splaytree_rdlock(tree) \
	(cp_splaytree_lock((tree), COLLECTION_LOCK_READ))
/* write lock */
#define cp_splaytree_wrlock(tree) \
	(cp_splaytree_lock((tree), COLLECTION_LOCK_WRITE))
/* unlock */
int cp_splaytree_unlock(cp_splaytree *tree);


/* return the table mode indicator */
int cp_splaytree_get_mode(cp_splaytree *tree);
/* set mode bits on the tree mode indicator */
int cp_splaytree_set_mode(cp_splaytree *tree, int mode);
/* unset mode bits on the tree mode indicator. if unsetting 
 * COLLECTION_MODE_NOSYNC and the tree was not previously synchronized, the 
 * internal synchronization structure is initalized.
 */
int cp_splaytree_unset_mode(cp_splaytree *tree, int mode);

/* print tree to stdout */
void cp_splaytree_dump(cp_splaytree *tree);

/** @} */

#endif

