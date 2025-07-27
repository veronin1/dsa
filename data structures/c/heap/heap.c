#include <stddef.h>
#include <stdlib.h>

typedef int (*Comparator)(const void *, const void *);

typedef enum { MIN_HEAP, MAX_HEAP } HeapType;

typedef struct {
  void **data;
  size_t size;
  size_t capacity;
  HeapType type;
  Comparator cmp;
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

int cmp(const void *a, const void *b) {
  int intA = *(const int *) a;
  int intB = *(const int *) b;
  if (intA < intB)
    return -1;
  else if (intA > intB)
    return 1;
  else
    return 0;
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

  HeapType type = heap->type;

  while (index > 0) {
    int parent = (index - 1) / 2;
    int cmpResult = heap->cmp(heap->data[index], heap->data[parent]);
    if ((type == MAX_HEAP && cmpResult > 0 ||
         (type == MIN_HEAP && cmpResult < 0))) {
      void *tmp = heap->data[parent];
      heap->data[parent] = heap->data[index];
      heap->data[index] = tmp;
      index = parent;
    } else {
      break;
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
