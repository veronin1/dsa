#include <stddef.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} TreeNode;

typedef struct {
  TreeNode *root;
  size_t size;
} BinarySearchTree;

BinarySearchTree *createTree(const size_t size) {
  BinarySearchTree *tree = malloc(sizeof(BinarySearchTree));
  if (tree == NULL) {
    return NULL;
  }

  tree->root = NULL;
  tree->size = 0;
  return tree;
}

void insert(BinarySearchTree *tree, const int element) {
  if (tree == NULL) {
    return;
  }

  TreeNode *temp = malloc(sizeof(TreeNode));
  if (!temp) {
    return;
  }
}

TreeNode *insert_node(TreeNode *node, int value) {
  if (value > node->data) {
    return node->right;
  }

  return node->left;
}
