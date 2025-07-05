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
  s->top--;
  return s->data[s->top];
}