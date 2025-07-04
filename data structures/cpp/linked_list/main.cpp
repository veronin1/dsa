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

void testDoubleList() {
  std::cout << "--- Testing with double ---" << std::endl;
  LinkedList<double> list;

  // 22.5->15.1->30.9->12.0
  list.pushBack(30.9);
  list.pushBack(12.0);
  list.pushFront(15.1);
  list.pushFront(22.5);

  // Exp Out: 22.5, 15.1, 30.9, 12.0
  std::cout << "List: ";
  list.printList();

  // Exp Out: 12.0
  std::cout << "Last value: " << list.popBack() << std::endl;

  // Exp Out: 22.5, 15.1, 30.9
  std::cout << "Removal of ^ value: ";
  list.printList();

  // Exp Out: 22.5
  std::cout << "Front value: " << list.popFront() << std::endl;

  // Exp Out: 15.1, 30.9
  std::cout << "Removal of ^ value: ";
  list.printList();

  // Exp Out: 15.1
  std::cout << "New first value: " << list.front() << std::endl;

  // Exp Out: 15.1, 30.9
  std::cout << "List: ";
  list.printList();

  // Exp Out: 30.9
  std::cout << "New last value: " << list.back() << std::endl;

  // Exp Out: 15.1, 30.9
  std::cout << "List: ";
  list.printList();

  // Exp Out: false
  std::cout << "List empty: " << list.empty() << std::endl;

  // Exp Out: 2
  std::cout << "List size: " << list.getSize() << std::endl;

  // Remove '30.9'
  list.removeValue(30.9);

  // Exp Out: 15.1
  std::cout << "List after removing 30.9: ";
  list.printList();

  list.clear();

  std::cout << "List after clearing: ";
  list.printList();
  std::cout << "List empty after clearing: " << list.empty() << std::endl;
  std::cout << "List size after clearing: " << list.getSize() << std::endl;
  std::cout << std::endl;
}

void testCharList() {
  std::cout << "--- Testing with char ---" << std::endl;
  LinkedList<char> list;

  // 'D'->'B'->'E'->'C'
  list.pushBack('E');
  list.pushBack('C');
  list.pushFront('B');
  list.pushFront('D');

  // Exp Out: D, B, E, C
  std::cout << "List: ";
  list.printList();

  // Exp Out: C
  std::cout << "Last value: " << list.popBack() << std::endl;

  // Exp Out: D, B, E
  std::cout << "Removal of ^ value: ";
  list.printList();

  // Exp Out: D
  std::cout << "Front value: " << list.popFront() << std::endl;

  // Exp Out: B, E
  std::cout << "Removal of ^ value: ";
  list.printList();

  // Exp Out: B
  std::cout << "New first value: " << list.front() << std::endl;

  // Exp Out: B, E
  std::cout << "List: ";
  list.printList();

  // Exp Out: E
  std::cout << "New last value: " << list.back() << std::endl;

  // Exp Out: B, E
  std::cout << "List: ";
  list.printList();

  // Exp Out: false
  std::cout << "List empty: " << list.empty() << std::endl;

  // Exp Out: 2
  std::cout << "List size: " << list.getSize() << std::endl;

  // Remove 'E'
  list.removeValue('E');

  // Exp Out: B
  std::cout << "List after removing E: ";
  list.printList();

  list.clear();

  std::cout << "List after clearing: ";
  list.printList();
  std::cout << "List empty after clearing: " << list.empty() << std::endl;
  std::cout << "List size after clearing: " << list.getSize() << std::endl;
  std::cout << std::endl;
}

void testStringList() {
  std::cout << "--- Testing with std::string ---" << std::endl;
  LinkedList<std::string> list;

  // "apple"->"banana"->"cherry"->"date"
  list.pushBack("cherry");
  list.pushBack("date");
  list.pushFront("banana");
  list.pushFront("apple");

  // Exp Out: apple, banana, cherry, date
  std::cout << "List: ";
  list.printList();

  // Exp Out: date
  std::cout << "Last value: " << list.popBack() << std::endl;

  // Exp Out: apple, banana, cherry
  std::cout << "Removal of ^ value: ";
  list.printList();

  // Exp Out: apple
  std::cout << "Front value: " << list.popFront() << std::endl;

  // Exp Out: banana, cherry
  std::cout << "Removal of ^ value: ";
  list.printList();

  // Exp Out: banana
  std::cout << "New first value: " << list.front() << std::endl;

  // Exp Out: banana, cherry
  std::cout << "List: ";
  list.printList();

  // Exp Out: cherry
  std::cout << "New last value: " << list.back() << std::endl;

  // Exp Out: banana, cherry
  std::cout << "List: ";
  list.printList();

  // Exp Out: false
  std::cout << "List empty: " << list.empty() << std::endl;

  // Exp Out: 2
  std::cout << "List size: " << list.getSize() << std::endl;

  // Remove "cherry"
  list.removeValue("cherry");

  // Exp Out: banana
  std::cout << "List after removing cherry: ";
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
  testDoubleList();
  testCharList();
  testStringList();
  return 0;
}
