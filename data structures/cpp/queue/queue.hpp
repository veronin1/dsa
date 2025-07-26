#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <cstddef>

class Queue {
 private:
  int *data;
  size_t head, tail, size, capacity;

 public:
  Queue(size_t cap);
  ~Queue();

  void enqueue(int element);
  int dequeue();
  void expand();
};

#endif