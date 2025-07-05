# Stack (C)

A stack is a linear data structure that stores items in a last-in, first-out (LIFO) order.

## Interface

- `Stack createStack(size_t maxSize)`: Creates a stack with the given maximum size.
- `int pop(Stack *s)`: Removes and returns the top element; returns -1 if stack is empty.
- `void push(Stack *s, int value)`: Pushes a value onto the top of the stack.
- `int top(Stack *s)`: Returns the top element without removing it; returns -1 if empty.
- `int size(Stack *s)`: Returns the current number of elements in the stack.
- `int isEmpty(Stack *s)`: Returns 1 if the stack is empty, 0 otherwise.

## Compiling

Compile:

```sh
gcc main.c linkedlist.c -o stack -std=c11
```

Run:

```sh
./stack
```

## Usage

```c
#include <stdio.h>
#include "stack.h"

int main() {
    Stack s = createStack(3);

    push(&s, 10);
    push(&s, 20);

    printf("Top: %d\n", top(&s));      // Output: Top: 20
    printf("Size: %d\n", size(&s));    // Output: Size: 2

    printf("Popped: %d\n", pop(&s));   // Output: Popped: 20
    printf("Empty? %d\n", isEmpty(&s)); // Output: Empty? 0

    pop(&s);
    printf("Empty now? %d\n", isEmpty(&s)); // Output: Empty now? 1

    return 0;
}
```
