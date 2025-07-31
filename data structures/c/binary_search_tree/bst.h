#ifndef BST_H
#define BST_H

#include <stdbool.h>
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

BinarySearchTree *createTree(void);
void destroyTree(BinarySearchTree *tree);

void insert(BinarySearchTree *tree, int value);
TreeNode *insert_node(TreeNode *node, int value);
void remove_node(BinarySearchTree *tree, int value);
TreeNode *find_min(TreeNode *node);
TreeNode *delete_node(TreeNode *root, int value);
bool contains(const BinarySearchTree *tree, int value);
TreeNode *contains_node(TreeNode *node, int value);
void clear(BinarySearchTree *tree);
TreeNode *clear_bst(TreeNode *node);
int height(const BinarySearchTree *tree);
int height_helper(TreeNode *node);
bool isLeaf(const TreeNode *node);
size_t size(const BinarySearchTree *tree);
bool empty(const BinarySearchTree *tree);

int *in_order_traversal(const BinarySearchTree *tree, size_t *out_size);
void in_order_helper(TreeNode *node, int **array, size_t *size);
int *pre_order_traversal(const BinarySearchTree *tree, size_t *out_size);
void pre_order_helper(TreeNode *node, int **array, size_t *size);
int *post_order_traversal(const BinarySearchTree *tree, size_t *out_size);
void post_order_helper(TreeNode *node, int **array, size_t *size);

#endif
