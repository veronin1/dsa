#include <memory>
#include <stdexcept>

class Vector {
 private:
  std::unique_ptr<int[]> data;
  int currentSize;
  int capacity;

 public:
  Vector() : currentSize(0), capacity(0) {}

  // returns currentSize
  int size() const { return currentSize; }

  // return true if no elems
  bool empty() const { return currentSize == 0; }

  // return first element in vect
  int front() {
    if (currentSize == 0) {
      throw std::out_of_range("Vector is empty");
    }
    return data[0];
  }

 private:
};