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

TreeNode *insert_node(TreeNode *node, int value);

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

  tree->root = insert_node(tree->root, element);
  tree->size++;
}

TreeNode *insert_node(TreeNode *node, int value) {
  if (node == NULL) {
    TreeNode *new_node = malloc(sizeof(TreeNode));
    if (!new_node) return NULL;

    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
  }

  if (value > node->data) {
    node->right = insert_node(node->right, value);
  } else if (value < node->data) {
    node->left = insert_node(node->left, value);
  }
  return node;
}
