#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <cstddef>

class Queue {
 private:
  int *data;
  size_t head, tail, currentSize, capacity;
  void expand();

 public:
  Queue(size_t cap);
  ~Queue();

  void enqueue(int element);
  int dequeue();
  int front();
  int back();
  size_t size();
  bool isEmpty();
};

#endif