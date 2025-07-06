#include <cstddef>

template <typename T>
class Vector {
 private:
  T *data;
  size_t size;
  size_t capacity;

 public:
  Vector() : data(nullptr), size(0), capacity(0) {};
  ~Vector() { delete[] data; }
};