#include "heap.hpp"

#include <algorithm>

// Constructor with comparator
template <typename T>
Heap<T>::Heap(std::function<bool(T, T)> comp) : comp(comp) {
}

// Copy constructor
template <typename T>
Heap<T>::Heap(const Heap &other) {
  this->data = other.data;
  this->comp = other.comp;
}
