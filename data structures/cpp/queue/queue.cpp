#include "queue.hpp"

#include <stdexcept>

#define DEFAULT_INIT_SIZE 1000

Queue::Queue(size_t cap) {
  capacity = cap;
  data = new int[capacity];
  head = 0;
  tail = capacity - 1; // point to last inserted elem
  currentSize = 0;
}

Queue::~Queue() {
  delete[] data;
}

void Queue::enqueue(int element) {
  if (currentSize == capacity) {
    expand();
  }
  tail = (tail + 1) % capacity;
  data[tail] = element;
  ++currentSize;
}

int Queue::dequeue() {
  if (isEmpty()) {
    throw std::out_of_range("Queue is empty");
  }
  auto front = data[head];
  head = (head + 1) % capacity;
  --currentSize;
  return front;
}

void Queue::expand() {
  size_t newCapacity = capacity * 2;
  int *newData = new int[newCapacity];

  for (int i = 0; i < currentSize; ++i) {
    newData[i] = data[(head + i) % capacity];
  }

  int *temp = data;
  data = newData;
  delete[] temp;
  capacity = newCapacity;
  tail = currentSize - 1;
}

int Queue::front() {
  if (isEmpty()) {
    throw std::out_of_range("Queue empty");
  }
  return data[head];
}

int Queue::back() {
  if (isEmpty()) {
    throw std::out_of_range("Queue empty");
  }

  return data[tail];
}

size_t Queue::size() {
  if (isEmpty()) {
    throw std::out_of_range("Queue empty");
  }

  return currentSize;
}

bool Queue::isEmpty() {
  return currentSize == 0;
}