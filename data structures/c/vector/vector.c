#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *data;
  int currentSize;
  int capacity;
} Vector;

void resize(Vector *v, int newSize);

void printVector(const Vector *v) {
  for (int i = 0; i < v->currentSize; i++) {
    printf("%i", v->data[i]);
    if (i != v->currentSize - 1) {
      printf(", ");
    }
  }
  printf("\n");
}

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

// Change number of elements in vector ot newSize
void resize(Vector *v, int newSize) {
  int *new_arr = malloc(newSize * sizeof(int));
  if (new_arr == NULL) {
    return;
  }

  int limit = 0;
  if (newSize > v->currentSize) {
    limit = v->currentSize;

    for (int i = v->currentSize; i < newSize; i++) {
      new_arr[i] = 0;
    }
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

int main() {
  Vector v;

  // Initialize vector with size 5
  v.currentSize = 5;
  v.data = malloc(v.currentSize * sizeof(int));
  if (!v.data) {
    printf("Initial allocation failed!\n");
    return 1;
  }

  for (int i = 0; i < v.currentSize; i++) {
    v.data[i] = i + 1;
  }

  printf("Initial vector:\n");
  printVector(&v);

  // Resize larger
  resize(&v, 8);
  printf("After resizing to 8:\n");
  printVector(&v);

  // Fill new elements
  for (int i = 5; i < v.currentSize; i++) {
    v.data[i] = (i + 1) * 10;
  }

  printf("After filling new elements:\n");
  printVector(&v);

  // Resize smaller
  resize(&v, 3);
  printf("After resizing to 3:\n");
  printVector(&v);

  free(v.data);
  return 0;
}
