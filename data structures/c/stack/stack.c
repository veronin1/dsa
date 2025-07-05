#include "stack.h"

#include <stdlib.h>

Stack createStack(size_t maxSize) {
  Stack s;
  if (maxSize == 0) {
    maxSize = 1000; // Default size
  }
  s.top = 0;

  s.maxSize = maxSize;
  s.data = malloc(sizeof(size_t) * s.maxSize);
  if (s.data == NULL) {
    s.maxSize = 0;
    return s;
  }
  return s;
}

int pop(Stack *s) {
  // if stack empty
  if (!s || s->top == 0) {
    return -1;
  }
  int top = s->data[s->top - 1];
  s->data[s->top - 1] = 0;
  s->top--;
  return top;
}

void push(Stack *s, int value) {
  if (!s) {
    return;
  }

  if (s->top == s->maxSize) {
    return;
  }

  s->data[s->top] = value;
  s->top++;
}

int top(Stack *s) {
  if (!s) {
    return -1;
  }

  return s->data[s->top - 1];
}

int size(Stack *s) {
  return s->top;
}

int isEmpty(Stack *s) {
  if (!s || !s->top) {
    return 1;
  }
  return 0;
}