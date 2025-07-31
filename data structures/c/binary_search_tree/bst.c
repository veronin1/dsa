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

  if (value < root->data) {
    root->left = delete_node(root->left, value);
  } else if (value > root->data) {
    root->right = delete_node(root->right, value);
  } else {
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

    TreeNode *temp = find_min(root->right);
    root->data = temp->data;
    root->right = delete_node(root->right, temp->data);
  }
  return root;
}

bool contains(const BinarySearchTree *tree, int value) {
  if (!tree || !tree->root) return false;

  TreeNode *tmp = contains_node(tree->root, value);
  return (tmp != NULL);
}

TreeNode *contains_node(TreeNode *node, int value) {
  if (!node) {
    return NULL;
  }

  if (node->data == value) {
    return node;
  }

  if (value < node->data) {
    return contains_node(node->left, value);
  } else if (value > node->data) {
    return contains_node(node->right, value);
  }

  return NULL;
}

void clear(BinarySearchTree *tree) {
  return;
}

size_t size(const BinarySearchTree *tree) {
  return tree->size;
}

bool empty(const BinarySearchTree *tree) {
  return tree->size == 0;
}

int *in_order_traversal(const BinarySearchTree *tree, size_t *out_size) {
  if (!tree || !tree->root) {
    return NULL;
  }

  int *array = NULL;
  size_t size = 0;

  in_order_helper(tree->root, &array, &size);

  *out_size = size;
  return array;
}

void in_order_helper(TreeNode *node, int **array, size_t *size) {
  if (!node) {
    return;
  }

  in_order_helper(node->left, array, size);
  int *temp = realloc(*array, (*size + 1) * sizeof(int));
  if (!temp) {
    return;
  }
  *array = temp;
  (*array)[*size] = node->data;
  (*size)++;

  in_order_helper(node->right, array, size);
}

int *pre_order_traversal(const BinarySearchTree *tree, size_t *out_size) {
  if (!tree || !tree->root) {
    return NULL;
  }

  int *array = NULL;
  size_t size = 0;

  pre_order_helper(tree->root, &array, &size);

  *out_size = size;
  return array;
}

void pre_order_helper(TreeNode *node, int **array, size_t *size) {
  if (!node) {
    return;
  }

  int *temp = realloc(*array, (*size + 1) * sizeof(int));
  if (!temp) {
    return;
  }
  *array = temp;
  (*array)[*size] = node->data;
  (*size)++;

  pre_order_helper(node->left, array, size);
  pre_order_helper(node->right, array, size);
}
