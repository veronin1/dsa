typedef struct {
  int *arr;
  int currentSize;
  int capacity;
} vector;

int empty(vector arr) {
  if (arr.currentSize != 0) {
    return 1;
  }
  return 0;
}