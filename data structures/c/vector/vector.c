typedef struct {
  int *data;
  int currentSize;
  int capacity;
} Vector;

int empty(Vector v) {
  if (v.currentSize != 0) {
    return 1;
  }
  return 0;
}