#include "heap.hpp" // Assuming you put your class in Heap.h

#include <iostream>

int main() {
  // Create a min-heap (default uses std::less<T>, so it will be a min heap)
  Heap<int> minHeap;

  std::cout << "Pushing values: 10, 4, 15, 20, 0, 5\n";
  minHeap.push(10);
  minHeap.push(4);
  minHeap.push(15);
  minHeap.push(20);
  minHeap.push(0);
  minHeap.push(5);

  std::cout << "Heap size: " << minHeap.size() << "\n";
  std::cout << "Heap peek (min element): " << minHeap.peek() << "\n";

  std::cout << "Is minHeap a MinHeap? " << (minHeap.isMinHeap() ? "Yes" : "No")
            << "\n";
  std::cout << "Is minHeap a MaxHeap? " << (minHeap.isMaxHeap() ? "Yes" : "No")
            << "\n";

  std::cout << "Popping elements:\n";
  while (!minHeap.empty()) {
    std::cout << minHeap.pop() << " ";
  }
  std::cout << "\n";

  // Create a max-heap by passing a custom comparator
  Heap<int> maxHeap([](const int &a, const int &b) {
    return a > b; // max-heap comparator
  });

  std::cout << "\nPushing values to maxHeap: 10, 4, 15, 20, 0, 5\n";
  maxHeap.push(10);
  maxHeap.push(4);
  maxHeap.push(15);
  maxHeap.push(20);
  maxHeap.push(0);
  maxHeap.push(5);

  std::cout << "Heap size: " << maxHeap.size() << "\n";
  std::cout << "Heap peek (max element): " << maxHeap.peek() << "\n";

  std::cout << "Is maxHeap a MaxHeap? " << (maxHeap.isMaxHeap() ? "Yes" : "No")
            << "\n";
  std::cout << "Is maxHeap a MinHeap? " << (maxHeap.isMinHeap() ? "Yes" : "No")
            << "\n";

  std::cout << "Popping elements:\n";
  while (!maxHeap.empty()) {
    std::cout << maxHeap.pop() << " ";
  }
  std::cout << "\n";

  return 0;
}
