#include <memory>

class Vector {
 private:
  std::unique_ptr<int[]> data;
  int currentSize;
  int capacity;

 public:
  Vector() : currentSize(0), capacity(0) {}

  int size() const { return currentSize; }
};