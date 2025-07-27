#include <stdio.h>

#include "heap.h"

int cmpInt(const void *a, const void *b) {
  return (*(int *) a) - (*(int *) b);
}

int main() {
  int values[] = {20, 5, 15, 22, 9, 3};
  Heap *heap = createHeap(10, MIN_HEAP, cmpInt);

  if (!heap) return 1;

  for (int i = 0; i < 6; i++) push(heap, &values[i]);

  printf("Top: %d\n", *(int *) peek(heap));
  printf("Heap: ");
  while (!isEmpty(heap)) printf("%d ", *(int *) pop(heap));
  printf("\n");

  freeHeap(heap);
  return 0;
}
