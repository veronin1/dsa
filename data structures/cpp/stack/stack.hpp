#include <cstddef>
#include <stdexcept>

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
  bool isFull();
};

template <typename T>
void Stack<T>::push(T element) {
  if (currentSize == capacity) {
    pop();
  }
  data[currentSize] = element;
  currentSize++;
}

// delete and return last element
template <typename T>
T Stack<T>::pop() {
  if (isEmpty()) {
    throw std::out_of_range("Stack is empty");
  }

  currentSize--;
  T lastElement = data[currentSize];
  return lastElement;
}

template <typename T>
size_t Stack<T>::size() {
  return currentSize;
}

template <typename T>
bool Stack<T>::isEmpty() {
  return currentSize == 0;
}

template <typename T>
bool Stack<T>::isFull() {
  return currentSize == capacity;
}
