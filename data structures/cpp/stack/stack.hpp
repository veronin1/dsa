#include <cstddef>

template <typename T>
class Stack {
 private:
  T *data;
  size_t currentSize, capacity;

 public:
  void push(T element); // insert
  T pop();              // delete
  size_t size();
  bool isEmpty();
};

template <typename T>
void Stack<T>::push(T element) {
  if (currentSize == capacity) {
    pop();
  }
  data[currentSize] = element;
  currentSize++;
}
