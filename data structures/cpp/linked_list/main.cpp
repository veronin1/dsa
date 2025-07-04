#include <iostream>
#include <stdexcept>

#include "linkedlist.hpp"

int main(void) {
  LinkedList list;

  list.pushFront(2);
  list.pushFront(99);
  list.pushBack(3);
  list.pushBack(5);

  std::cout << "Initial list:" << std::endl;
  list.printList();

  std::cout << "Front element: " << list.front() << std::endl;
  std::cout << "Back element: " << list.back() << std::endl;

  std::cout << "Pop front: " << list.popFront() << std::endl;
  std::cout << "Pop back: " << list.popBack() << std::endl;

  std::cout << "List after popping front and back:" << std::endl;
  list.printList();

  std::cout << "Size: " << list.getSize() << std::endl;
  std::cout << "Is empty? " << (list.empty() ? "True" : "False") << std::endl;

  list.pushBack(10);
  list.pushBack(20);
  list.pushBack(30);

  std::cout << "List before removing value 20:" << std::endl;
  list.printList();

  list.removeValue(20);

  std::cout << "List after removing value 20:" << std::endl;
  list.printList();

  list.clear();

  std::cout << "List after clear:" << std::endl;
  list.printList();

  std::cout << "Is empty after clear? " << (list.empty() ? "True" : "False")
            << std::endl;

  try {
    std::cout << "Attempting to pop front from empty list: ";
    list.popFront();
  } catch (const std::runtime_error& e) {
    std::cerr << "Caught exception: " << e.what() << std::endl;
  }

  return 0;
}