#include "queue.hpp"

#include <stdexcept>

#define DEFAULT_INIT_SIZE 1000

Queue::Queue(size_t cap) {
  capacity = cap;
  data = new int[capacity];
  head = 0;
  tail = capacity - 1;
  currentSize = 0;
}

Queue::~Queue() {
  delete[] data;
}

void Queue::enqueue(int element) {
  if (currentSize == capacity) {
    expand();
  }
  data[(++tail) % capacity] = element;
  ++currentSize;
}

int Queue::dequeue() {
  if (currentSize == 0) {
    throw std::out_of_range("Queue is empty");
  }
  auto front = data[head];

  if (head == tail) {
    head = -1;
    tail = -1;
  } else {
    head = (++head) & capacity;
  }

  --currentSize;
  return front;
}

void Queue::expand() {
  size_t newCapacity = capacity * 2;
  int *newData = new int[newCapacity];

  size_t lengthCounter = 0;
  for (int i = 0; i < capacity; ++i) {
    newData[i] = data[(head + i) % capacity];
    ++lengthCounter;
  }

  int *temp = data;
  data = newData;
  delete[] temp;
  capacity = newCapacity;
  currentSize = capacity;
}