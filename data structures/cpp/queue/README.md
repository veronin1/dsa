# Queue (C++)

A queue is a First-In-First-Out (FIFO) data structure. This implementation is a generic, circular queue using a dynamically allocated array. It supports automatic resizing and provides constant-time enqueue/dequeue operations.

## Interface

The queue is managed through the following methods:

- `void enqueue(const T &element)`: Adds element to the end of the queue.
- `T dequeue()`: Removes and returns the element at the front of the queue. Throws if the queue is empty.
- `T front() const`: Returns the element at the front without removing it. Throws if the queue is empty.
- `T back() const`: Returns the element at the end without removing it. Throws if the queue is empty.
- `size_t size() const`: Returns the current number of elements in the queue.
- `bool isEmpty() const`: Returns true if the queue is empty.
- `Queue &operator=(const Queue &other)`: Copies contents from another queue.
- `Queue(const Queue &other)`: Copy constructor.
- `~Queue()`: Destructor to free memory.

## Compiling

Compile:

```sh
g++ main.cpp -o queue -std=c++17
```

Run:

```sh
./queue
```

## Usage

```cpp
#include <iostream>
#include "Queue.hpp"

int main() {
  Queue<int> q;

  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);

  std::cout << "Front: " << q.front() << std::endl;  // Output: 10
  std::cout << "Back: "  << q.back()  << std::endl;  // Output: 30
  std::cout << "Size: "  << q.size()  << std::endl;  // Output: 3

  q.dequeue();
  std::cout << "Front after dequeue: " << q.front() << std::endl;  // Output: 20

  return 0;
}
```
