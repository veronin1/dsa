# Binary Search Tree (C)

A binary search tree is a tree data structure that satisfies the binary search tree property. This is that every value to the left of a node is less than or equal to the nodes value. The opposite is applicable to the right side, where every node is greater than or equal to the nodes value. 

---

## Interface

The BST can be interfaced through the following methods:

* `bst_tree *bst_create(void)`: Creates and returns an empty BST.
* `void bst_destroy(bst_tree *tree)`: Frees all nodes and BST struct.
* `void bst_insert(bst_tree *tree, int value)`: Inserts a value into the BST and updates the size.
* `void bst_remove(bst_tree *tree, int value)`: Removes a node with the given value and updates the size.
* `bool bst_contains(const bst_tree *tree, int value)`: Returns `true` if the value exists in the BST.
* `void bst_clear(bst_tree *tree)`: Removes all nodes but keeps the BST struct.
* `int bst_height(const bst_tree *tree)`: Returns the height of the BST.
* `bool bst_empty(const bst_tree *tree)`: Returns `true` if the BST is empty.
* `size_t bst_size(const bst_tree *tree)`: Returns the number of nodes in the BST.
* `int *bst_in_order(const bst_tree *tree, size_t *out_size)`: Returns an array of values in in-order traversal.
* `int *bst_pre_order(const bst_tree *tree, size_t *out_size)`: Returns an array of values in pre-order traversal.
* `int *bst_post_order(const bst_tree *tree, size_t *out_size)`: Returns an array of values in post-order traversal.

### Internal Methods for BST Logic

* `bst_node *bst_node_create(int value)`: Allocates and returns a new node with the given value.
* `bst_node *bst_insert_node(bst_node *node, int value)`: Recursively inserts the value into the proper position starting from the given node.
* `bst_node *bst_delete_node(bst_node *node, int value)`: Recursive helper to delete a node and restructure the subtree.
* `bst_node *bst_find_min(bst_node *node)`: Returns the node with the smallest value in the subtree.
* `bst_node *bst_find_node(bst_node *node, int value)`: Recursively checks if the value exists in the subtree and returns the node if found.
* `bst_node *bst_clear_nodes(bst_node *node)`: Recursively frees all nodes in the subtree and returns `NULL`.
* `int bst_height_node(bst_node *node)`: Recursive helper to calculate height from a given node.
* `bool bst_is_leaf(const bst_node *node)`: Returns `true` if the node has no children.
* `void bst_in_order_helper(bst_node *node, int **array, size_t *size)`: Recursive helper for in-order traversal.
* `void bst_pre_order_helper(bst_node *node, int **array, size_t *size)`: Recursive helper for pre-order traversal.
* `void bst_post_order_helper(bst_node *node, int **array, size_t *size)`: Recursive helper for post-order traversal.

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
