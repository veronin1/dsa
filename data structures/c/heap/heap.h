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
Heap *createHeapArray(void *const *array, size_t size, HeapType type,
                      Comparator cmp);
void freeHeap(Heap *heap);
void push(Heap *heap, const void *val);
void *pop(Heap *heap);
void *peek(const Heap *heap);
size_t size(const Heap *heap);
int isEmpty(const Heap *heap);
int isMaxHeap(const Heap *heap);
int isMinHeap(const Heap *heap);
int cmp(const void *a, const void *b);
void buildHeap(Heap *heap);

#endif
