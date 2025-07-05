#include <stdlib.h>
typedef struct {
  int *data;
  int currentSize;
  int capacity;
} Vector;

int isEmpty(const Vector *v) {
  return v->currentSize == 0;
}

int size(const Vector *v) {
  return v->currentSize;
}

void clear(Vector *v) {
  v->currentSize = 0;
}