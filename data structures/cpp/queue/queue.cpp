#include "queue.hpp"

#define DEFAULT_INIT_SIZE 1000

Queue::Queue(size_t cap) {
  capacity = cap;
  data = new int[capacity];
  head = 0;
  tail = capacity - 1;
  size = 0;
}

Queue::~Queue() {
  delete[] data;
}

void Queue::enqueue(int element) {
  if (size == capacity) {
    expand();
  }
  data[(++tail) % capacity] = element;
  ++size;
}

void Queue::expand() {
}