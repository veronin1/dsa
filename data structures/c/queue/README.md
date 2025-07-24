# Queue (C)

A **queue** is a linear data structure that follos the FIFO (First In, First Out) principle. This imeplementation uses a circular buffer backed by a dynamically resizing array. The queue automatically grows its capacity when needed.

## Interface

- `Queue createQueue(size_t capacity)`: Create a queue of n size in memory
- `bool isEmpty(void)` : Returns whether the queue is empty
- `int size(void)` : Returns the number of elements currently in the queue
- `void enqueue(int element)` : Adds an element to the back of the queue
- `int front(void)` : Returns the element at the front of the queue without removing it
- `int back(void)` : Returns the element at the back of the queue without removing it
- `int dequeue(void)` : Removes and returns the element at the front of the queue
- `void freeQueue(Queue *q)`: Frees allocated memory used by the queue

## Usage

```c
#include <stdio.h>
#include "queue.h"

int main() {
    Queue q = createQueue(3);

    enqueue(&q, 10);
    enqueue(&q, 20);

    printf("Front: %d\n", front(&q));  // 10
    printf("Back: %d\n", back(&q));    // 20

    printf("Dequeued: %d\n", dequeue(&q)); // 10
    printf("Empty? %d\n", isEmpty(&q));    // 0 (false)

    freeQueue(&q);
    return 0;
}
```
