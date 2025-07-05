typedef struct {
  int *data;
  int currentSize;
  int capacity;
} Vector;

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
void push_back(Vector *v, int value) {
  v->data[v->currentSize] = value;
  v->currentSize++;
}
