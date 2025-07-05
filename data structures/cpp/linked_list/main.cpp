#include <iostream>
#include <ostream>
#include <string> // Required for std::string

#include "linkedlist.hpp" // Assuming this file contains the LinkedList template class definition

void testIntList() {
  std::cout << "--- Testing with int ---" << std::endl;
  LinkedList<int> list;

  // 22->15->30->12
  list.pushBack(30);
  list.pushBack(12);
  list.pushFront(15);
  list.pushFront(22);

  // Exp Out: 22, 15, 30, 12
  std::cout << "List: ";
  list.printList();

  // Exp Out: 12
  std::cout << "Last value: " << list.popBack() << std::endl;

  // Exp Out: 22, 15, 30
  std::cout << "Removal of ^ value: ";
  list.printList();

  // Exp Out: 22
  std::cout << "Front value: " << list.popFront() << std::endl;

  // Exp Out: 15, 30
  std::cout << "Removal of ^ value: ";
  list.printList();

  // Exp Out: 15
  std::cout << "New first value: " << list.front() << std::endl;

  // Exp Out: 15, 30
  std::cout << "List: ";
  list.printList();

  // Exp Out: 30
  std::cout << "New last value: " << list.back() << std::endl;

  // Exp Out: 15, 30
  std::cout << "List: ";
  list.printList();

  // Exp Out: false
  std::cout << "List empty: " << list.empty() << std::endl;

  // Exp Out: 2
  std::cout << "List size: " << list.getSize() << std::endl;

  // Remove '30'
  list.removeValue(30);

  // Exp Out: 15
  std::cout << "List after removing 30: ";
  list.printList();

  list.clear();

  std::cout << "List after clearing: ";
  list.printList();
  std::cout << "List empty after clearing: " << list.empty() << std::endl;
  std::cout << "List size after clearing: " << list.getSize() << std::endl;
  std::cout << std::endl;
}

int main() {
  testIntList();
  return 0;
}
