# Vector (C)

A vector is a dynamic array data structure that allows for more efficient maneuverability. It grows and shrinks automatically as elements are added or removed.

## Interface

The vector is managed through the following methods in this order:

- `Vector createVector()`: Creates and returns a new, empty vector.
- `void printVector(const Vector *v)`: Print the entire vector.
- `int isEmpty(const Vector *v)`: Returns `1` if the list is empty, otherwise `0`.
- `int size(const Vector *v)`: Return number of elements in the vector.
- `void clear(Vector *v)`: Removes all elements from the vector.
- `void resize(Vector *v, int newSize)`: Changes the number of elements in the vector to `newSize`.
- `void destroyVector(Vector *v)`: Frees vector memory and resets its state.
- `void pushBack(Vector *v, int value)`: Appends a new element to the end of the vector.
- `int front(const Vector *v)`: Returns a reference to the first element in the vector.
- `int back(const Vector *v)`: Returns a reference to the last element in the vector.
- `int popBack(Vector *v)`: Removes and returns the last element of the vector.

## Compilation

Compile:

```sh
gcc main.c vector.c -o vector -std=c11
```

Run:

```sh
./vector
```

## Usage

```sh
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

  free(v.data);
  return 0;
}
```
