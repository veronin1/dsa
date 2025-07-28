#include <functional>
#include <vector>

template <typename T>
class Heap {
 private:
  std::vector<T> data;

  size_t parentIdx(size_t index);
  size_t leftNodeIdx(size_t index);
  size_t rightNodeIdx(size_t index);

 public:
  Heap(std::function<bool(T, T)> comp);
  Heap(const Heap &other);

  Heap();
  ~Heap();

  void push(const T &val);
  T pop();
  T peek();
  unsigned int size;
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
Heap<T>::Heap() {
  data = new std::vector<T>();
}

template <typename T>
Heap<T>::~Heap() {
  delete data;
}

template <typename T>
void Heap<T>::push(const T &val) {
  data.push_back(val);
  size_t index = data.size() - 1;
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

    if (left < data.size() && data[left] > data[i]) {
      return false;
    }
    if (right < data.size() && data[right] > data[i]) {
      return false;
    }
  }
  return true;
}
