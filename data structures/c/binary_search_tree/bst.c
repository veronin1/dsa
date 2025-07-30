#include <stddef.h>

typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;

typedef struct {
  Node *root;
  size_t size;
} BinarySearchTree;
