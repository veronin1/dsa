#include <iostream>

#include "linkedlist.hpp"

int main(void) {
  LinkedList list;

  // Push elements front and back
  list.pushFront(2);  // List: 2
  list.pushFront(99); // List: 99 -> 2
  list.pushBack(3);   // List: 99 -> 2 -> 3
  list.pushBack(5);   // List: 99 -> 2 -> 3 -> 5

  std::cout << "Initial list:" << std::endl;
  list.printList(); // Output: 99, 2, 3, 5

  // Access front and back elements
  // Use try-catch blocks for methods that might throw exceptions (like
  // front/back/pop on empty list)
  try {
    std::cout << "Front element: " << list.front() << std::endl; // Expected: 99
    std::cout << "Back element: " << list.back() << std::endl;   // Expected: 5
  } catch (const std::runtime_error& e) {
    std::cerr << "Error accessing elements: " << e.what() << std::endl;
  }

  // Pop elements from front and back
  try {
    std::cout << "Pop front: " << list.popFront() << std::endl; // Removes 99
    std::cout << "Pop back: " << list.popBack() << std::endl;   // Removes 5
  } catch (const std::runtime_error& e) {
    std::cerr << "Error popping elements: " << e.what() << std::endl;
  }

  std::cout << "List after popping front and back:" << std::endl;
  list.printList(); // Expected: 2, 3

  // Check size and emptiness
  std::cout << "Size: " << list.getSize() << std::endl; // Expected: 2
  std::cout << "Is empty? " << (list.empty() ? "True" : "False")
            << std::endl; // Expected: False

  // Add more elements
  list.pushBack(10);
  list.pushBack(20);
  list.pushBack(30);

  std::cout << "List before removing value 20:" << std::endl;
  list.printList(); // Expected: 2, 3, 10, 20, 30

  // Remove a value
  try {
    list.removeValue(20);
  } catch (const std::runtime_error& e) {
    std::cerr << "Error removing value: " << e.what() << std::endl;
  }

  std::cout << "List after removing value 20:" << std::endl;
  list.printList(); // Expected: 2, 3, 10, 30

  // Clear list
  list.clear();

  std::cout << "List after clear:" << std::endl;
  list.printList(); // Expected: (empty line)

  std::cout << "Is empty after clear? " << (list.empty() ? "True" : "False")
            << std::endl; // Expected: True

  // Demonstrate attempting to pop from an empty list
  try {
    std::cout << "Attempting to pop front from empty list: ";
    list.popFront(); // This will throw an exception
  } catch (const std::runtime_error& e) {
    std::cerr << "Caught exception: " << e.what() << std::endl;
  }

  return 0;
}