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

  TreeNode *temp = malloc(sizeof(TreeNode));
  if (!temp) {
    return;
  }

  while (1) {
    TreeNode *current = tree->root;
    temp = insert_node(current, element);

    if (temp == NULL) {
      temp->data = element;
      current = temp;
      free(temp);
      break;
    }
  }
}

TreeNode *insert_node(TreeNode *node, int value) {
  if (value > node->data) {
    return node->right;
  } else if (value < node->data) {
    return node->left;
  }
  return NULL;
}
