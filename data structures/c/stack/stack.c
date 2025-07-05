#include <stdlib.h>

typedef struct {
  int *data;
  int top;
} Stack;

Stack createStack(void) {
  Stack s;
  s.data = NULL;
  s.top = 0;
  return s;
}

int pop(Stack *s) {
  // if stack empty
  if (!s || s->top == 0) {
    return -1;
  }
  int top = s->data[s->top];
  s->data[s->top] = 0;
  s->top--;
  return top;
}

void push(Stack *s, int element) {
  if (!s) {
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
  if (!s) {
    return 0;
  }
  return 1;
}