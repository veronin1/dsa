#include "bst.h"

#include <stdlib.h>

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

void remove_node(BinarySearchTree *tree, int value) {
  if (!tree) {
    return;
  }

  tree->root = delete_node(tree->root, value);
  tree->size--;
}

TreeNode *find_min(TreeNode *node) {
  if (!node) return NULL;
  while (node->left != NULL) {
    node = node->left;
  }
  return node;
}

TreeNode *delete_node(TreeNode *root, int value) {
  if (!root) return NULL;

  if (root->left == NULL && root->right == NULL) {
    free(root);
    root = NULL;
    return root;
  }

  if (root->left == NULL && root->right != NULL) {
    TreeNode *temp = root;
    root = root->right;
    free(temp);
    return root;
  } else if (root->left != NULL && root->right == NULL) {
    TreeNode *temp = root;
    root = root->left;
    free(temp);
    return root;
  }
}
