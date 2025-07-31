#include "bst.h"

#include <stdlib.h>

bst_tree *bst_create(void) {
  bst_tree *tree = malloc(sizeof(bst_tree));
  if (tree == NULL) {
    return NULL;
  }

  tree->root = NULL;
  tree->size = 0;
  return tree;
}

void bst_destroy(bst_tree *tree) {
  if (!tree) return;
  bst_clear(tree);
  free(tree);
}

bst_node *bst_node_create(int value) {
  bst_node *node = (bst_node *) malloc(sizeof(bst_node));
  if (!node) return NULL;

  node->data = value;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void bst_insert(bst_tree *tree, const int element) {
  if (tree == NULL) {
    return;
  }

  bool exists = bst_contains(tree, element);
  tree->root = bst_insert_node(tree->root, element);
  if (!exists) tree->size++;
}

bst_node *bst_insert_node(bst_node *node, int value) {
  if (node == NULL) {
    return bst_node_create(value);
  }

  if (value > node->data) {
    node->right = bst_insert_node(node->right, value);
  } else if (value < node->data) {
    node->left = bst_insert_node(node->left, value);
  }
  return node;
}

void bst_remove(bst_tree *tree, int value) {
  if (!tree) {
    return;
  }

  tree->root = bst_delete_node(tree->root, value);

  bool deleted = bst_contains(tree, value) ? true : false;
  if (deleted) {
    tree->size--;
  }
}

bst_node *bst_find_min(bst_node *node) {
  if (!node) return NULL;

  while (node->left != NULL) {
    node = node->left;
  }
  return node;
}

bst_node *bst_delete_node(bst_node *root, int value) {
  if (!root) return NULL;

  if (value < root->data) {
    root->left = bst_delete_node(root->left, value);
  } else if (value > root->data) {
    root->right = bst_delete_node(root->right, value);
  } else {
    if (root->left == NULL && root->right == NULL) {
      free(root);
      root = NULL;
      return root;
    }

    if (root->left == NULL && root->right != NULL) {
      bst_node *temp = root;
      root = root->right;
      free(temp);
      return root;
    } else if (root->left != NULL && root->right == NULL) {
      bst_node *temp = root;
      root = root->left;
      free(temp);
      return root;
    }

    bst_node *temp = bst_find_min(root->right);
    root->data = temp->data;
    root->right = bst_delete_node(root->right, temp->data);
  }
  return root;
}

bool bst_contains(const bst_tree *tree, int value) {
  if (!tree || !tree->root) return false;

  bst_node *tmp = bst_find_node(tree->root, value);
  return (tmp != NULL);
}

bst_node *bst_find_node(bst_node *node, int value) {
  if (!node) {
    return NULL;
  }

  if (node->data == value) {
    return node;
  }

  if (value < node->data) {
    return bst_find_node(node->left, value);
  } else if (value > node->data) {
    return bst_find_node(node->right, value);
  }

  return NULL;
}

void bst_clear(bst_tree *tree) {
  if (!tree) return;

  tree->root = bst_clear_nodes(tree->root);
}

bst_node *bst_clear_nodes(bst_node *node) {
  if (!node) {
    return NULL;
  }
  node->left = bst_clear_nodes(node->left);
  node->right = bst_clear_nodes(node->right);
  free(node);

  return NULL;
}

int bst_height(const bst_tree *tree) {
  if (!tree) return -1;
  return bst_height_node(tree->root);
}

int bst_height_node(bst_node *node) {
  if (!node) {
    return -1;
  }

  int left_height = bst_height_node(node->left);
  int right_height = bst_height_node(node->right);

  return 1 + ((left_height > right_height) ? left_height : right_height);
}

bool bst_is_leaf(const bst_node *node) {
  if (node->left == NULL && node->right == NULL) {
    return true;
  }
  return false;
}

size_t bst_size(const bst_tree *tree) {
  return (tree ? tree->size : 0);
}

bool bst_empty(const bst_tree *tree) {
  return (!tree || tree->size == 0);
}

int *bst_in_order(const bst_tree *tree, size_t *out_size) {
  if (!tree || !tree->root) {
    return NULL;
  }

  int *array = NULL;
  size_t size = 0;

  bst_in_order_helper(tree->root, &array, &size);

  *out_size = size;
  return array;
}

void bst_in_order_helper(bst_node *node, int **array, size_t *size) {
  if (!node) {
    return;
  }

  bst_in_order_helper(node->left, array, size);
  int *temp = realloc(*array, (*size + 1) * sizeof(int));
  if (!temp) {
    free(*array);
    *array = NULL;
    return;
  }
  *array = temp;
  (*array)[*size] = node->data;
  (*size)++;

  bst_in_order_helper(node->right, array, size);
}

int *bst_pre_order(const bst_tree *tree, size_t *out_size) {
  if (!tree || !tree->root) {
    return NULL;
  }

  int *array = NULL;
  size_t size = 0;

  bst_pre_order_helper(tree->root, &array, &size);

  *out_size = size;
  return array;
}

void bst_pre_order_helper(bst_node *node, int **array, size_t *size) {
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

  bst_pre_order_helper(node->left, array, size);
  bst_pre_order_helper(node->right, array, size);
}

int *bst_post_order(const bst_tree *tree, size_t *out_size) {
  if (!tree || !tree->root) {
    return NULL;
  }

  int *array = NULL;
  size_t size = 0;

  bst_post_order_helper(tree->root, &array, &size);

  *out_size = size;
  return array;
}

void bst_post_order_helper(bst_node *node, int **array, size_t *size) {
  if (!node) {
    return;
  }

  bst_post_order_helper(node->left, array, size);
  bst_post_order_helper(node->right, array, size);
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
