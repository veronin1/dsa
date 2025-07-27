#include "heap.h"

#include <stddef.h>
#include <stdlib.h>

Heap *createHeap(size_t capacity, HeapType type, Comparator cmp) {
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
  heap->cmp = cmp;
  return heap;
}

Heap *createHeapArray(void *const *array, size_t size, HeapType type,
                      Comparator cmp) {
  Heap *heap = malloc(sizeof(Heap));
  if (!heap) {
    return NULL;
  }

  heap->data = malloc(sizeof(void *) * size);
  if (!heap->data) {
    free(heap);
    return NULL;
  }

  for (size_t i = 0; i < size; ++i) {
    heap->data[i] = array[i];
  }
  heap->size = size;
  heap->capacity = size;
  heap->type = type;
  heap->cmp = cmp;

  buildHeap(heap);
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

int resize(Heap *heap) {
  size_t newCapacity = heap->capacity * 2;
  void **newData = realloc(heap->data, sizeof(void *) * newCapacity);
  if (!newData) {
    return 0;
  }

  heap->data = newData;
  heap->capacity = newCapacity;
  return 1;
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
    if ((type == MAX_HEAP && cmpResult > 0) ||
        (type == MIN_HEAP && cmpResult < 0)) {
      void *tmp = heap->data[parent];
      heap->data[parent] = heap->data[index];
      heap->data[index] = tmp;
      index = parent;
    } else {
      break;
    }
  }
}

void heapifyDown(Heap *heap, size_t index) {
  HeapType type = heap->type;

  while (1) {
    size_t leftChild = index * 2 + 1;
    size_t rightChild = index * 2 + 2;
    size_t selected = index;

    // compare with left child
    if (leftChild < heap->size) {
      int cmpResult = heap->cmp(heap->data[leftChild], heap->data[selected]);

      if ((type == MAX_HEAP && cmpResult > 0) ||
          (type == MIN_HEAP && cmpResult < 0)) {
        selected = leftChild;
      }
    }

    // compare with right child
    if (rightChild < heap->size) {
      int cmpResult = heap->cmp(heap->data[rightChild], heap->data[selected]);

      if ((type == MAX_HEAP && cmpResult > 0) ||
          (type == MIN_HEAP && cmpResult < 0)) {
        selected = rightChild;
      }
    }

    if (selected == index) {
      break;
    }

    void *tmp = heap->data[selected];
    heap->data[selected] = heap->data[index];
    heap->data[index] = tmp;
    index = selected;
  }
}

// adds the element to top of the heap
void push(Heap *heap, const void *val) {
  if (heap->size == heap->capacity) {
    if (!resize(heap)) return;
  }

  heap->data[heap->size] = (void *) val;
  heapifyUp(heap, heap->size);
  heap->size++;
}

void *pop(Heap *heap) {
  if (heap->size == 0) {
    return NULL;
  }
  void *root = heap->data[0];
  heap->size--;
  heap->data[0] = heap->data[heap->size];
  heapifyDown(heap, 0);
  return root;
}

void *peek(const Heap *heap) {
  if (heap->size == 0) {
    return NULL;
  }

  return heap->data[0];
}

size_t size(const Heap *heap) {
  return heap->size;
}

// return 1 if true
int isEmpty(const Heap *heap) {
  return heap->size == 0;
}

// return 1 if true
int isMaxHeap(const Heap *heap) {
  // every node is >= the value of the parent
  if (isEmpty(heap)) {
    return 1;
  }

  size_t heapSize = heap->size;

  for (size_t i = 0; i <= (heapSize - 2) / 2; ++i) {
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < heapSize && heap->cmp(heap->data[left], heap->data[i]) > 0) {
      return 0;
    }

    if (right < heapSize && heap->cmp(heap->data[right], heap->data[i]) > 0) {
      return 0;
    }
  }
  return 1;
}

// return 1 if true
int isMinHeap(const Heap *heap) {
  // every node is <= the value of the parent

  if (isEmpty(heap)) {
    return 1;
  }

  size_t heapSize = heap->size;
  for (size_t i = 0; i <= (heapSize - 2) / 2; ++i) {
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < heapSize && heap->cmp(heap->data[left], heap->data[i]) < 0) {
      return 0;
    }
    if (right < heapSize && heap->cmp(heap->data[right], heap->data[i]) < 0) {
      return 0;
    }
  }
  return 1;
}

void buildHeap(Heap *heap) {
  if (heap == NULL || heap->size == 0) {
    return;
  }
  for (ssize_t i = (heap->size - 2) / 2; i >= 0; --i) {
    heapifyDown(heap, i);
  }
}
