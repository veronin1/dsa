#include <stddef.h>

typedef struct {
  int *data;
  size_t size;
  size_t capacity;
} Heap;
