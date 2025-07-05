#include <stdlib.h>

typedef struct {
  int *data;
  int currentSize;
  int capacity;
} Vector;

void resize(Vector *v, int newSize);

// Returns 1 if hte list is empty, otherwise 0
int isEmpty(const Vector *v) {
  return v->currentSize == 0;
}

// Return number of elements in the vector
int size(const Vector *v) {
  return v->currentSize;
}

// Remove all elements from vector
void clear(Vector *v) {
  v->currentSize = 0;
}

// Append a new element to the end of the vector
void pushBack(Vector *v, int value) {
  if (v->currentSize == v->capacity) {
    resize(v, v->capacity * 2);
  }

  v->data[v->currentSize] = value;
  v->currentSize++;
}

// Return a reference to the first element in vector
int front(Vector *v) {
  return v->data[0];
}

// Return a reference to the last element in vector
int back(Vector *v) {
  return v->data[v->currentSize - 1];
}

// Return a reference to the last element in vector
int popBack(Vector *v) {
  if (isEmpty(v)) {
    return -1;
  }

  v->currentSize--;
  return v->data[v->currentSize];
}

// Resize
void resize(Vector *v, int newSize) {
  int *new_arr = malloc(newSize * sizeof(int));
  if (new_arr == NULL) {
    return;
  }

  int limit = 0;
  if (newSize > v->currentSize) {
    limit = v->currentSize;
  } else {
    limit = newSize;
  }

  for (int i = 0; i < limit; i++) {
    new_arr[i] = v->data[i];
  }

  free(v->data);
  v->data = new_arr;
  v->currentSize = newSize;
}