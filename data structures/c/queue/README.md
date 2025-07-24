# Queue (C)

A **queue** is a linear data structure that follos the FIFO (First In, First Out) principle. This imeplementation uses a circular buffer backed by a dynamically resizing array. The queue automatically grows its capacity when needed.

## Interface

- `bool isEmpty(void)` : Returns whether the queue is empty
- `int size(void)` : Returns the number of elements currently in the queue
- `void enqueue(int element)` : Adds an element to the back of the queue
- `int front(void)` : Returns the element at the front of the queue without removing it
- `int back(void)` : Returns the element at the back of the queue without removing it
- `int dequeue(void)` : Removes and returns the element at the front of the queue
