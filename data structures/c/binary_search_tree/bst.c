#include <stddef.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;

typedef struct {
  Node *root;
  size_t size;
} BinarySearchTree;

BinarySearchTree *createTree(size_t size) {
  BinarySearchTree *tree = malloc(sizeof(BinarySearchTree));
  if (tree == NULL) {
    return NULL;
  }

  tree->root = NULL;
  tree->size = 0;
  return tree;
}

void insert(int element) {
  return;
}
