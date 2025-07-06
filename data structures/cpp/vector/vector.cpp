#include <cstddef>
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

  // returns reference to first element in vect
  int &front() {
    if (empty()) {
      throw std::out_of_range("Vector is empty");
    }
    return data[0];
  }

  // return reference to last element in vect
  int &back() {
    if (empty()) {
      throw std::out_of_range("Vector is empty");
    }

    return data[currentSize - 1];
  }

  // append value to end of vect
  void pushBack(const int &value) {
    if (capacity == 0) {
      resize(1); // alloc space if none
    } else if (currentSize == capacity) {
      resize(capacity * 2); // double capac when full
    }

    data[currentSize] = value; // insert current pos
    ++currentSize;             // increment size
  }

  // removes the last element of the vect and returns it
  int popBack() {
    if (empty()) {
      throw std::out_of_range("Vector is empty");
    }

    --currentSize;
    return data[currentSize - 1];
  }

  void resize(size_t newSize) { return; }
};