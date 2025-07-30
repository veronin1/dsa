#ifndef BST_H
#define BST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} TreeNode;

typedef struct {
  TreeNode *root;
  size_t size;
} BinarySearchTree;

BinarySearchTree *createTree(void);

void insert(BinarySearchTree *tree, int value);
void remove_node(BinarySearchTree *tree, int value);
bool contains(const BinarySearchTree *tree, int value);
void clear(BinarySearchTree *tree);
int height(const BinarySearchTree *tree);
size_t size(const BinarySearchTree *tree);
bool empty(const BinarySearchTree *tree);

int *in_order_traversal(const BinarySearchTree *tree, size_t *out_size);
int *pre_order_traversal(const BinarySearchTree *tree, size_t *out_size);
int *post_order_traversal(const BinarySearchTree *tree, size_t *out_size);

#endif
