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

  class Iterator {
   private:
    int *data;

   public:
    Iterator() : data(nullptr) {}

    Iterator(int *ptr) : data(ptr) {}
  };

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
    return data[currentSize];
  }

  void resize(size_t newCapacity) {
    // new temp arr for copying
    std::unique_ptr<int[]> temp_arr(new int[newCapacity]);

    // set limit in for loop
    size_t limit = (newCapacity > currentSize) ? currentSize : newCapacity;

    // copy all data from data[] to temp_arr[] for elems that fit
    for (size_t i = 0; i < limit; i++) {
      temp_arr[i] = data[i];
    }

    // move ownership of pointer to the new arr
    data = std::move(temp_arr);

    capacity = newCapacity;

    // shrink size accordingly
    if (currentSize > capacity) {
      currentSize = capacity;
    }
  }

  // removes all elements from the vector
  void clear() {
    currentSize = 0;
    capacity = 0;
    data = nullptr;
  }
};