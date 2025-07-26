#include <cstddef>

#define DEFAULT_INIT_SIZE 1000

class Queue {
 private:
  int *arr;
  size_t front;
  size_t rear;
  size_t size;
  size_t capacity;

 public:
  Queue(size_t cap) {
    capacity = cap;
    arr = new int[capacity];
    front = 0;
    rear = capacity - 1;
    size = 0;
  }

  ~Queue() { delete[] arr; }
};