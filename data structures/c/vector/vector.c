#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

Vector createVector() {
  Vector v;
  v.data = NULL;
  v.currentSize = 0;
  v.capacity = 0;
  return v;
}

// Prints all elemenets in the vector
void printVector(const Vector *v) {
  for (int i = 0; i < v->currentSize; i++) {
    printf("%i", v->data[i]);
    if (i != v->currentSize - 1) {
      printf(", ");
    }
  }
  printf("\n");
}

// Returns 1 if the list is empty, otherwise 0
int isEmpty(const Vector *v) {
  return v->currentSize == 0;
}

// Return number of elements in the vector
int size(const Vector *v) {
  return v->currentSize;
}

// Remove all elements from vector
void clear(Vector *v) {
  for (int i = 0; i < v->capacity; i++) {
    v->data[i] = 0;
  }
  v->currentSize = 0;
}

// Change number of elements in vector ot newSize
void resize(Vector *v, int newSize) {
  int *new_arr = malloc(newSize * sizeof(int));
  if (new_arr == NULL) {
    return;
  }

  int limit = (newSize > v->currentSize) ? v->currentSize : newSize;

  v->currentSize = 0;
  for (int i = 0; i < limit; i++) {
    new_arr[i] = v->data[i];
    v->currentSize++;
  }

  if (newSize > v->currentSize) {
    for (int i = v->currentSize; i < newSize; i++) {
      new_arr[i] = 0;
    }
  }

  free(v->data);
  v->data = new_arr;
  v->capacity = newSize;
}

// Destroy the vector
void destroyVector(Vector *v) {
  free(v->data);
  v->data = NULL;
  v->currentSize = 0;
  v->capacity = 0;
}

// Append a new element to the end of the vector
void pushBack(Vector *v, int value) {
  if (v->capacity == 0) {
    resize(v, 1);
  }

  if (v->currentSize == v->capacity) {
    resize(v, v->capacity * 2);
  }

  v->data[v->currentSize] = value;
  v->currentSize++;
}

// Return a reference to the first element in vector
int front(const Vector *v) {
  return v->data[0];
}

// Return a reference to the last element in vector
int back(const Vector *v) {
  return v->data[v->currentSize - 1];
}

// Return and remove reference to the last element in vector
int popBack(Vector *v) {
  if (isEmpty(v)) {
    return -1;
  }

  v->currentSize--;
  return v->data[v->currentSize];
}