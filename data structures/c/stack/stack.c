#include <stdlib.h>

typedef struct {
  size_t *data;
  size_t top;
  size_t maxSize;
} Stack;

Stack createStack(size_t maxSize) {
  Stack s;
  s.maxSize = maxSize;
  s.data = malloc(sizeof(size_t) * s.maxSize);
  s.top = 0;
  return s;
}

int pop(Stack *s) {
  // if stack empty
  if (!s || s->top == 0) {
    return -1;
  }
  int top = s->data[s->top - 1];
  s->data[s->top] = 0;
  s->top--;
  return top;
}

void push(Stack *s, int element) {
  if (!s) {
    return;
  }

  if (s->top == s->maxSize) {
    return;
  }

  s->data[s->top] = element;
  s->top++;
}

int top(Stack *s) {
  if (!s) {
    return -1;
  }

  return s->data[s->top];
}

int size(Stack *s) {
  return s->top;
}

int isEmpty(Stack *s) {
  if (!s || !s->top) {
    return 0;
  }
  return 1;
}