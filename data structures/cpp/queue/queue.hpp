#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <cstddef>
#include <stdexcept>

template <typename T>
class Queue {
 private:
  T *data;
  size_t head, tail, currentSize, capacity;
  void expand();
  void copy(const Queue &other);

 public:
  Queue();
  Queue(size_t cap);
  ~Queue();

  void enqueue(const T &element);
  T dequeue();
  T front() const;
  T back() const;
  size_t size() const;
  bool isEmpty() const;
  Queue &operator=(const Queue &other);
};

template <typename T>
void Queue<T>::copy(const Queue &other) {
  data = new T[other.capacity];
  for (size_t i = 0; i < other.currentSize; ++i) {
    data[i] = other.data[(other.head + i) % other.capacity];
  }

  head = 0;
  tail = other.currentSize - 1;
  currentSize = other.currentSize;
  capacity = other.capacity;
}

template <typename T>
Queue<T>::Queue()
    : head(0), tail(capacity - 1), currentSize(0), capacity(1000) {
  data = new T[capacity];
}

template <typename T>
Queue<T>::Queue(size_t cap)
    : head(0), tail(cap - 1), currentSize(0), capacity(cap) {
  data = new T[capacity];
}

template <typename T>
Queue<T>::~Queue() {
  delete[] data;
}

template <typename T>
void Queue<T>::enqueue(const T &element) {
  if (currentSize == capacity) {
    expand();
  }
  tail = (tail + 1) % capacity;
  data[tail] = element;
  ++currentSize;
}

template <typename T>
T Queue<T>::dequeue() {
  if (isEmpty()) {
    throw std::out_of_range("Queue is empty");
  }
  auto front = data[head];
  head = (head + 1) % capacity;
  --currentSize;
  return front;
}

template <typename T>
void Queue<T>::expand() {
  size_t newCapacity = capacity * 2;
  T *newData = new T[newCapacity];

  for (size_t i = 0; i < currentSize; ++i) {
    newData[i] = data[(head + i) % capacity];
  }

  delete[] data;
  data = newData;
  capacity = newCapacity;
  head = 0;
  tail = currentSize - 1;
}

template <typename T>
T Queue<T>::front() const {
  if (isEmpty()) {
    throw std::out_of_range("Queue empty");
  }
  return data[head];
}

template <typename T>
T Queue<T>::back() const {
  if (isEmpty()) {
    throw std::out_of_range("Queue empty");
  }
  return data[tail];
}

template <typename T>
size_t Queue<T>::size() const {
  return currentSize;
}

template <typename T>
bool Queue<T>::isEmpty() const {
  return currentSize == 0;
}

#endif