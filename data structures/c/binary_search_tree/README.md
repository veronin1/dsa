# Binary Search Tree (C)

A binary search tree is a tree data structure that satisfies the binary search tree property. This is that every value to the left of a node is less than or equal to the nodes value. The opposite is applicable to the right side, where every node is greater than or equal to the nodes value. 

## Interface

The BST can be interfaced through the following methods:

- `BinarySearchTree *createTree(void)`: Creates and returns empty BST
- `void destroyTree(BinarySearchTree *tree)`: Frees all nodes and BST struct
- `void insert(BinarySearchTree *tree, const int element)`: Inserts value into BST and updates size
- `void remove_node(BinarySearchTree *tree, int value)`: Removes node with value and updates size
- `bool contains(const BinarySearchTree *tree, int value)`: Returns true if value exists in BST
- `void clear(BinarySearchTree *tree)`: Removes all nodes but keeps BST struct
- `int height(const BinarySearchTree *tree)`: Returns height of BST
- `bool empty(const BinarySearchTree *tree)`: Returns true if BST is empty
- `size_t size(const BinarySearchTree *tree)`: Returns number of nodes in BST
- `int *in_order_traversal(const BinarySearchTree *tree, size_t *out_size)`: Returns array of values in in-order
- `int *pre_order_traversal(const BinarySearchTree *tree, size_t *out_size)`: Returns array of values in pre-order
- `int *post_order_traversal(const BinarySearchTree *tree, size_t *out_size)`: Returns array of values in post-order

### Internal Methods for BST Logic

- `TreeNode *create_node(int value)`: Allocates and returns new node with value
- `TreeNode *insert_node(TreeNode *node, int value)`: Recursively inserts value in proper position
- `TreeNode *delete_node(TreeNode *root, int value)`: Recursive helper to delete node and restructure tree
- `TreeNode *find_min(TreeNode *node)`: Returns node with smallest value in subtree
- `TreeNode *contains_node(TreeNode *node, int value)`: Recursively checks if value exists in subtree
- `TreeNode *clear_bst(TreeNode *node)`: Recursively frees all nodes and returns NULL
- `int height_helper(TreeNode *node)`: Recursive helper to calculate height
- `bool isLeaf(const TreeNode *node)`: Returns true if node has no children
- `void in_order_helper(TreeNode *node, int **array, size_t *size)`: Recursive helper for in-order traversal
- `void pre_order_helper(TreeNode *node, int **array, size_t *size)`: Recursive helper for pre-order traversal
- `void post_order_helper(TreeNode *node, int **array, size_t *size)`: Recursive helper for post-order traversal

## Compilation & Run

```sh
gcc -std=c17 bst.c -o bst
./bst
```

## Usage

```c
#include <stdio.h>
#include "bst.h"

int main(void) {
    BinarySearchTree *tree = createTree();

    insert(tree, 5);
    insert(tree, 3);
    insert(tree, 7);

    if (contains(tree, 3)) {
        printf("Tree contains 3\n");
    }

    printf("Tree size: %zu\n", size(tree));

    int *inorder = in_order_traversal(tree, NULL);
    

    destroyTree(tree);
    return 0;
}
```
