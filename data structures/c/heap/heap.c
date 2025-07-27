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
    resize(heap);
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

void *peek(Heap *heap) {
  if (heap->size == 0) {
    return NULL;
  }

  return heap->data[0];
}

size_t size(Heap *heap) {
  return heap->size;
}

// return 1 if true
int isEmpty(Heap *heap) {
  return heap->size == 0;
}

// return 1 if true
int isMaxHeap(Heap *heap) {
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
int isMinHeap(Heap *heap) {
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
