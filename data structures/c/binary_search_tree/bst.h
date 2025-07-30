#ifndef BST_H
#define BST_H

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

BinarySearchTree *createTree(const size_t size);
void insert(BinarySearchTree *tree, const int element);
TreeNode *insert_node(TreeNode *node, int value);

#endif
