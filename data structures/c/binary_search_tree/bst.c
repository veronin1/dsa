#include "bst.h"

#include <stdlib.h>

BinarySearchTree *createTree(void) {
  BinarySearchTree *tree = malloc(sizeof(BinarySearchTree));
  if (tree == NULL) {
    return NULL;
  }

  tree->root = NULL;
  tree->size = 0;
  return tree;
}

void destroyTree(BinarySearchTree *tree) {
  if (!tree) return;
  clear(tree);
  free(tree);
}

TreeNode *create_node(int value) {
  TreeNode *node = (TreeNode *) malloc(sizeof(TreeNode));
  if (!node) return NULL;

  node->data = value;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void insert(BinarySearchTree *tree, const int element) {
  if (tree == NULL) {
    return;
  }

  bool exists = contains(tree, element);
  tree->root = insert_node(tree->root, element);
  if (!exists) tree->size++;
}

TreeNode *insert_node(TreeNode *node, int value) {
  if (node == NULL) {
    return create_node(value);
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

  bool deleted = false;
  tree->root = delete_node(tree->root, value);
  if (deleted) tree->size--;
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
  if (!tree) return;

  tree->root = clear_bst(tree->root);
}

TreeNode *clear_bst(TreeNode *node) {
  if (!node) {
    return NULL;
  }
  node->left = clear_bst(node->left);
  node->right = clear_bst(node->right);
  free(node);

  return NULL;
}

int height(const BinarySearchTree *tree) {
  if (!tree) return -1;
  return height_helper(tree->root);
}

int height_helper(TreeNode *node) {
  if (!node) {
    return -1;
  }

  int leftHeight = height_helper(node->left);
  int rightHeight = height_helper(node->right);

  return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
}

bool isLeaf(const TreeNode *node) {
  if (node->left == NULL && node->right == NULL) {
    return true;
  }
  return false;
}

size_t size(const BinarySearchTree *tree) {
  return (tree ? tree->size : 0);
}

bool empty(const BinarySearchTree *tree) {
  return (!tree || tree->size == 0);
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
    free(*array);
    *array = NULL;
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
    free(*array);
    *array = NULL;
    return;
  }
  *array = temp;
  (*array)[*size] = node->data;
  (*size)++;

  pre_order_helper(node->left, array, size);
  pre_order_helper(node->right, array, size);
}

int *post_order_traversal(const BinarySearchTree *tree, size_t *out_size) {
  if (!tree || !tree->root) {
    return NULL;
  }

  int *array = NULL;
  size_t size = 0;

  post_order_helper(tree->root, &array, &size);

  *out_size = size;
  return array;
}

void post_order_helper(TreeNode *node, int **array, size_t *size) {
  if (!node) {
    return;
  }

  post_order_helper(node->left, array, size);
  post_order_helper(node->right, array, size);
  int *temp = realloc(*array, (*size + 1) * sizeof(int));
  if (!temp) {
    free(*array);
    *array = NULL;
    return;
  }

  *array = temp;
  (*array)[*size] = node->data;
  (*size)++;
}
