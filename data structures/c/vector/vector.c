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

void resize(Vector *v, int newSize) {
  return;
  return;
}