#ifndef BST_H_
#define BST_H_

#include <stdbool.h>
#include <stddef.h>

typedef struct bst_node {
  int data;
  struct bst_node *left;
  struct bst_node *right;
} bst_node;

typedef struct {
  bst_node *root;
  size_t size;
} bst_tree;

bst_tree *bst_create(void);
void bst_destroy(bst_tree *tree);
void bst_clear(bst_tree *tree);

bst_node *bst_node_create(int value);

void bst_insert(bst_tree *tree, int value);
bst_node *bst_insert_node(bst_node *node, int value);

void bst_remove(bst_tree *tree, int value);
bst_node *bst_delete_node(bst_node *node, int value);

bool bst_contains(const bst_tree *tree, int value);
bst_node *bst_find_node(bst_node *node, int value);

size_t bst_size(const bst_tree *tree);
bool bst_empty(const bst_tree *tree);
int bst_height(const bst_tree *tree);
int bst_height_node(bst_node *node);
bool bst_is_leaf(const bst_node *node);

bst_node *bst_find_min(bst_node *node);
bst_node *bst_clear_nodes(bst_node *node);

int *bst_in_order(const bst_tree *tree, size_t *out_size);
void bst_in_order_helper(bst_node *node, int **array, size_t *size);

int *bst_pre_order(const bst_tree *tree, size_t *out_size);
void bst_pre_order_helper(bst_node *node, int **array, size_t *size);

int *bst_post_order(const bst_tree *tree, size_t *out_size);
void bst_post_order_helper(bst_node *node, int **array, size_t *size);

#endif // BST_H_
