# Heap (C)

A heap is a complete binary tree based data structure that satisfies the heap property. The value of each node is greater than or ewqual to the values of its children (max-heap) or less than or equal to the value of its children (min-heap). Heaps are used to implement priority queues, where the element with the highest or lowest priority is always at the root of the tree.

This C Heap implementation uses a dynamically resizing array to store the elements and provides methods for manipulating the heap; as well as a generic comparator function to support heaps of varying data types.

## Interface

The heap class has the following methods:

- `Heap *createHeap(size_t capacity, HeapType type, Comparator cmp)`: Creates an empty heap with a given capacity, type (min or max), and comparator function.
- `Heap *createHeapArray(void **array, size_t size, HeapType type, Comparator cmp)`: Builds a heap from an existing array using the specified type and comparator.
- `void freeHeap(Heap *heap)`: Frees all memory used by the heap (but not the data inside it).
- `void push(Heap *heap, const void *val)`: Inserts a new element into the heap.
- `void *pop(Heap *heap)`: Removes and returns the root (min or max element depending on heap type).
- `void *peek(Heap *heap)`: Returns the root element without removing it.
- `size_t size(Heap *heap)`: Returns the current number of elements in the heap.
- `int isEmpty(Heap *heap)`: Returns `1` if the heap is empty, otherwise `0`.
- `int isMaxHeap(Heap *heap)`: Returns `1` if the heap satisfies the max-heap property, otherwise `0`.
- `int isMinHeap(Heap *heap)`: Returns `1` if the heap satisfies the min-heap property, otherwise `0`.

## Usage

```c
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

// Comparator for integers
int cmp(const void *a, const void *b) {
    int intA = *(const int *)a;
    int intB = *(const int *)b;
    return (intA > intB) - (intA < intB);
}

int main() {
    Heap *heap = createHeap(10, MAX_HEAP, cmp);

    if (!heap) {
        fprintf(stderr, "Heap creation failed!\n");
        return 1;
    }

    int values[] = {5, 10, 3, 8, 12};

    for (int i = 0; i < 5; i++) {
        push(heap, &values[i]);
    }

    printf("Popping all elements:\n");
    while (!isEmpty(heap)) {
        int *val = (int *)pop(heap);
        printf("%d ", *val);
    }
    printf("\n");

    freeHeap(heap);
    return 0;
}
```
