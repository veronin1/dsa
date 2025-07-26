#include <cstddef>

#define DEFAULT_INIT_SIZE 1000

class Queue {
 private:
  int *data;
  size_t head;
  size_t tail;
  size_t size;
  size_t capacity;

 public:
  Queue(size_t cap) {
    capacity = cap;
    data = new int[capacity];
    head = 0;
    tail = capacity - 1;
    size = 0;
  }

  ~Queue() { delete[] data; }

  void enqueue(int element) {
    if (size == capacity) {
      expand();
    }
    data[(++tail) % capacity] = element;
    ++size;
  }

  void expand();
};