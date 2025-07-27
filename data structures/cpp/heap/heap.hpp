#include <vector>

template <typename T>
class Heap {
 private:
  std::vector<T> *data;
  size_t parentIdx(size_t index);
  size_t leftNodeIdx(size_t index);
  size_t rightNodeIdx(size_t index);
};

template <typename T>
size_t Heap<T>::parentIdx(size_t index) {
  return index / 2;
}

template <typename T>
size_t Heap<T>::leftNodeIdx(size_t index) {
  return index * 2 + 1;
}

template <typename T>
size_t Heap<T>::rightNodeIdx(size_t index) {
  return index * 2 + 2;
}
