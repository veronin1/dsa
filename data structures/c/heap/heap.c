#include <stddef.h>
#include <stdlib.h>

typedef struct {
  void **data;
  size_t size;
  size_t capacity;
} Heap;

Heap *createHeap(size_t capacity) {
  Heap *heap = malloc(sizeof(Heap));
  if (!heap) {
    return NULL;
  }

  heap->data = malloc(capacity * sizeof(void *));
  if (!heap->data) {
    free(heap);
    return NULL;
  }

  heap->size = 0;
  heap->capacity = capacity;
  return heap;
}

void resize(Heap *heap) {
  size_t newCapacity = heap->capacity * 2;
  void **newHeap = malloc(sizeof(void *) * newCapacity);
  if (!newHeap) {
    return;
  }

  for (size_t i = 0; i < heap->size; ++i) {
    newHeap[i] = heap->data[i];
  }

  free(heap->data);
  heap->data = newHeap;
  heap->capacity = newCapacity;
}

void heapifyUp(Heap *heap, size_t size);

// adds the element to top of the heap
void push(Heap *heap, const void *val) {
  if (heap->size == heap->capacity) {
    resize(heap);
  }

  heap->data[heap->size] = (void *) val;
  heapifyUp(heap, heap->size);
  heap->size++;
}
