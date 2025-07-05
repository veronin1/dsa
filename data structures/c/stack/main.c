#include <stdio.h>

#include "stack.h"

int main() {
  Stack s = createStack(5);

  printf("Stack empty? %d\n", isEmpty(&s)); // Expect 1 (true)

  push(&s, 10);
  push(&s, 20);
  push(&s, 30);

  printf("Stack size: %d\n", size(&s)); // Expect 3
  printf("Top element: %d\n", top(&s)); // Expect 30

  int val = pop(&s);
  printf("Popped: %d\n", val);            // Expect 30
  printf("Top after pop: %d\n", top(&s)); // Expect 20

  while (!isEmpty(&s)) {
    printf("Popping: %d\n", pop(&s));
  }

  printf("Stack empty after popping all? %d\n", isEmpty(&s)); // Expect 1

  return 0;
}
