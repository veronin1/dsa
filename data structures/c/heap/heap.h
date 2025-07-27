#ifndef HEAP_H
#define HEAP_H

#include <stddef.h>

typedef int (*Comparator)(const void *, const void *);

typedef enum { MIN_HEAP, MAX_HEAP } HeapType;

typedef struct {
  void **data;
  size_t size;
  size_t capacity;
  HeapType type;
  Comparator cmp;
} Heap;

Heap *createHeap(size_t capacity, HeapType type, Comparator cmp);
Heap *createHeapArray(void **array, size_t size, HeapType type, Comparator cmp);
void freeHeap(Heap *heap);
void push(Heap *heap, const void *val);
void *pop(Heap *heap);
void *peek(Heap *heap);
size_t size(Heap *heap);
int isEmpty(Heap *heap);
int isMaxHeap(Heap *heap);
int isMinHeap(Heap *heap);
int cmp(const void *a, const void *b);
void buildHeap(Heap *heap);

#endif
