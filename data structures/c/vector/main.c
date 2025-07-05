#include <stdio.h>

#include "vector.h"

int main() {
  Vector v = createVector();

  // Push some elements
  pushBack(&v, 1);
  pushBack(&v, 2);
  pushBack(&v, 3);
  printf("Before resize: ");
  printVector(&v); // Should print 1, 2, 3
  printf("Size: %d, Capacity: %d\n", v.currentSize, v.capacity);

  // Resize down to 2 elements
  resize(&v, 2);
  printf("After resizing down to 2: ");
  printVector(&v); // Should print 1, 2
  printf("Size: %d, Capacity: %d\n", v.currentSize, v.capacity);

  // Resize up to 5 elements (new elements zero-initialized)
  resize(&v, 5);
  printf("After resizing up to 5: ");
  printVector(&v); // Should print 1, 2, 0, 0, 0
  printf("Size: %d, Capacity: %d\n", v.currentSize, v.capacity);

  destroyVector(&v);
  return 0;
}
