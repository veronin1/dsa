#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef struct {
  size_t *data;
  size_t top;
  size_t maxSize;
} Stack;

// Create the stack in memory
Stack createStack(size_t maxSize);

// Removes and returns the last element in the stack
int pop(Stack *s);

// Adds an element to the end of the stack
void push(Stack *s, int value);

// Returns the last element in the stack
int top(Stack *s);

// Returns the size of the stack
int size(Stack *s);

// Returns 1 if stack empty, otherwise 0
int isEmpty(Stack *s);

#endif