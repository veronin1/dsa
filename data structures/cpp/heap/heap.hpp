#include <functional>
#include <stdexcept>
#include <utility>
#include <vector>

template <typename T>
class Heap {
 private:
  std::vector<T> data;
  std::function<bool(const T &, const T &)> comp;

  size_t parentIdx(size_t index);
  size_t leftNodeIdx(size_t index);
  size_t rightNodeIdx(size_t index);

 public:
  Heap(std::function<bool(const T &, const T &)> comp);
  Heap();
  Heap(const Heap &other);

  ~Heap();

  void push(const T &val);
  void heapifyUp(size_t index);
  void heapifyDownRecursive(size_t index);
  void heapifyDownIterative(size_t index);
  T pop();
  T peek();
  unsigned int size();
  bool empty();
  bool isMaxHeap();
  bool isMinHeap();
};

template <typename T>
size_t Heap<T>::parentIdx(size_t index) {
  return (index - 1) / 2;
}

template <typename T>
size_t Heap<T>::leftNodeIdx(size_t index) {
  return index * 2 + 1;
}

template <typename T>
size_t Heap<T>::rightNodeIdx(size_t index) {
  return index * 2 + 2;
}

template <typename T>
Heap<T>::Heap(std::function<bool(const T &, const T &)> comp) : comp(comp) {
}

template <typename T>
Heap<T>::Heap() : comp(std::less<T>()) {
}

template <typename T>
Heap<T>::Heap(const Heap &other) {
  data = other.data;
  comp = other.comp;
}

template <typename T>
Heap<T>::~Heap() {
}

template <typename T>
void Heap<T>::push(const T &val) {
  data.push_back(val);
  size_t index = data.size() - 1;
  heapifyUp(index);
}

template <typename T>
void Heap<T>::heapifyUp(size_t index) {
  if (index == 0) {
    return;
  }

  while (index > 0) {
    size_t parent = parentIdx(index);

    if (comp(data[index], data[parent])) {
      std::swap(data[index], data[parent]);
      index = parent;
    } else {
      break;
    }
  }

  return;
}

template <typename T>
void Heap<T>::heapifyDownRecursive(size_t index) {
  size_t left = leftNodeIdx(index);
  size_t right = rightNodeIdx(index);
  size_t smallest = index;

  if (left < data.size() && comp(data[left], data[smallest])) {
    smallest = left;
  }

  if (right < data.size() && comp(data[right], data[smallest])) {
    smallest = right;
  }

  if (smallest != index) {
    std::swap(data[index], data[smallest]);
    heapifyDownRecursive(smallest);
  }
}

template <typename T>
void Heap<T>::heapifyDownIterative(size_t index) {
  size_t length = data.size();

  while (true) {
    size_t left = leftNodeIdx(index);
    size_t right = rightNodeIdx(index);
    size_t smallest = index;

    if (left < length && comp(data[left], data[smallest])) {
      smallest = left;
    }

    if (right < length && comp(data[right], data[smallest])) {
      smallest = right;
    }

    if (smallest == index) {
      break;
    }

    std::swap(data[index], data[smallest]);
    index = smallest;
  }
}

template <typename T>
T Heap<T>::pop() {
  if (empty()) {
    throw std::out_of_range("Heap is empty");
  }

  T frontValue = data[0];
  std::swap(data[0], data.back());
  data.pop_back();
  heapifyDownRecursive(0);
  return frontValue;
}

template <typename T>
T Heap<T>::peek() {
  if (empty()) {
    throw std::out_of_range("Heap is empty");
  }

  return data[0];
}

template <typename T>
unsigned int Heap<T>::size() {
  return data.size();
}

template <typename T>
bool Heap<T>::empty() {
  return data.empty();
}

template <typename T>
bool Heap<T>::isMaxHeap() {
  for (size_t i = 0; i < data.size(); ++i) {
    size_t left = leftNodeIdx(i);
    size_t right = rightNodeIdx(i);

    if (left < data.size() && data[i] < data[left]) {
      return false;
    }
    if (right < data.size() && data[i] < data[right]) {
      return false;
    }
  }
  return true;
}

template <typename T>
bool Heap<T>::isMinHeap() {
  for (size_t i = 0; i < data.size(); ++i) {
    size_t left = leftNodeIdx(i);
    size_t right = rightNodeIdx(i);

    if (left < data.size() && data[left] < data[i]) {
      return false;
    }
    if (right < data.size() && data[right] < data[i]) {
      return false;
    }
  }
  return true;
}
