# Heap (C++)

A heap is a tree-like data structure that satisfies the heap property. There are two types of heaps (min and max). A minheap is one where every node is >= (greater than or equal to) the value of its respective parent. A maxheap is one where every node is <= (less than or equal to) the value of its respective parent.

This heap implementation in C++ uses a std::vector<T> as the underlying container and supports both min-heap and max-heap behaviours (and any custom order) via a comparator function.

## Interface

The heap has the following functions:

* `Heap(std::function<bool(const T&, const T&)> comp)`: Constructs a heap with a custom comparator to define the heap order (e.g., min-heap or max-heap).
* `Heap()`: Default constructor that creates a min-heap using `std::less<T>` as the comparator.
* `Heap(const Heap &other)`: Copy constructor that creates a new heap as a copy of an existing one.
* `~Heap()`: Destructor (default, no special cleanup needed).
* `void push(const T& val)`: Inserts a new element `val` into the heap and restores the heap property by moving the element up.
* `void heapifyUp(size_t index)`: Restores the heap property by moving the element at `index` up the tree until the correct position is found.
* `void heapifyDownRecursive(size_t index)`: Restores the heap property by moving the element at `index` down recursively.
* `void heapifyDownIterative(size_t index)`: Restores the heap property by moving the element at `index` down iteratively (loop-based).
* `T pop()`: Removes and returns the top element (root) of the heap, then restores the heap property.
* `T peek()`: Returns the top element (root) of the heap without removing it.
* `unsigned int size()`: Returns the current number of elements in the heap.
* `bool empty()`: Returns `true` if the heap contains no elements, otherwise `false`.
* `bool isMaxHeap()`: Checks if the heap satisfies the max-heap property assuming natural ordering (`data[i] >= data[left/right]`).
* `bool isMinHeap()`: Checks if the heap satisfies the min-heap property assuming natural ordering (`data[i] <= data[left/right]`).

## Compilation & Run

```sh
g++ -std=c++17 heap.cpp -o heap
./heap
```

## Usage

```cpp
#include "heap.hpp"
#include <iostream>

int main() {
  Heap<int> minHeap;  // Min-heap by default

  minHeap.push(5);
  minHeap.push(2);
  minHeap.push(8);

  std::cout << minHeap.pop() << "\n"; // Outputs: 2 (smallest)
  std::cout << minHeap.peek() << "\n"; // Outputs: 5 (next smallest)
}
```
