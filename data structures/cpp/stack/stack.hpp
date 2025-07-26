#include <cstddef>
#include <stdexcept>

#define DEFAULT_INIT_SIZE 1000

template <typename T>
class Stack {
 private:
  T *data;
  size_t currentSize, capacity;
  void copy(const Stack &other);

 public:
  Stack();
  Stack(const Stack &other);
  Stack &operator=(const Stack &other);
  void push(T element); // insert
  T pop();              // delete
  size_t size();
  bool isEmpty();
  bool isFull();
  ~Stack();
};

template <typename T>
void Stack<T>::copy(const Stack &other) {
  currentSize = other.currentSize;
  capacity = other.capacity;

  data = new T[capacity];

  for (size_t i = 0; i < currentSize; ++i) {
    data[i] = other.data[i];
  }
}

template <typename T>
Stack<T>::Stack()
    : data(new T[DEFAULT_INIT_SIZE]),
      currentSize(0),
      capacity(DEFAULT_INIT_SIZE) {
}

template <typename T>
Stack<T>::Stack(const Stack &other) {
  copy(other);
}

template <typename T>
Stack<T> &Stack<T>::operator=(const Stack &other) {
  if (this != &other) {
    delete[] data;
    copy(other);
  }
  return *this;
}

template <typename T>
void Stack<T>::push(T element) {
  if (isFull()) {
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

template <typename T>
Stack<T>::~Stack() {
  delete[] data; // free memory
}
