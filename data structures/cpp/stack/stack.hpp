#include <cstddef>

template <typename T>
class Stack {
 private:
  T *data;
  size_t currentSize, capacity;

 public:
  T push(T element); // insert
  T pop();           // delete
  size_t size();
  bool isEmpty();
};
