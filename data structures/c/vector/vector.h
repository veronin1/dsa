#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *data;
  int currentSize;
  int capacity;
} Vector;

// Create a new empty vector
Vector createVector(void);

// Print the elements of the vector
void printVector(const Vector *v);

// Returns 1 if the vector is empty, otherwise 0
int isEmpty(const Vector *v);

// Return the number of elements in the vector
int size(const Vector *v);

// Remove all elements from the vector
void clear(Vector *v);

// Resize the vector to newSize
void resize(Vector *v, int newSize);

// Free all resources used by the vector
void destroyVector(Vector *v);

// Append a new element to the end of the vector
void pushBack(Vector *v, int value);

// Return the first element of the vector
int front(const Vector *v);

// Return the last element of the vector
int back(const Vector *v);

// Remove and return the last element of the vector
int popBack(Vector *v);

#endif // VECTOR_H
