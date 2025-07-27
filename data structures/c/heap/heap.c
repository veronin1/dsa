#include <stddef.h>
#include <stdlib.h>

typedef enum { MIN_HEAP, MAX_HEAP } HeapType;

typedef struct {
  void **data;
  size_t size;
  size_t capacity;
  HeapType type;
} Heap;

Heap *createHeap(size_t capacity, HeapType type) {
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
  heap->type = type;
  return heap;
}

void freeHeap(Heap *heap) {
  if (heap == NULL) return;

  free(heap->data);
  free(heap);
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

// restore heap property after inserting a new element
void heapifyUp(Heap *heap, size_t index) {
  if (index == 0) {
    return;
  }

  while (index > 0) {
    int parent = (index - 1) / 2;
    if (heap->type == MAX_HEAP) {
      if (heap->data[index] > heap->data[parent]) {
        void *tmp;
        heap->data[parent] = tmp;
        heap->data[parent] = heap->data[index];
        heap->data[index] = tmp;
        index = parent;
      }
    } else if (heap->type == MIN_HEAP) {
      if (heap->data[index] < heap->data[parent]) {
        void *tmp;
        heap->data[parent] = tmp;
        heap->data[parent] = heap->data[index];
        heap->data[index] = tmp;
        index = parent;
      }
    }
  }
}
// adds the element to top of the heap
void push(Heap *heap, const void *val) {
  if (heap->size == heap->capacity) {
    resize(heap);
  }

  heap->data[heap->size] = (void *) val;
  heapifyUp(heap, heap->size);
  heap->size++;
}
