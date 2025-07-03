#include <algorithm>
#include <cstddef>
#include <iostream>
#include <memory>
#include <ostream>
#include <utility>

class Node {
 private:
  int data;
  std::unique_ptr<Node> next;

  // Give LinkedList access to private members
  friend class LinkedList;

 public:
  Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
 private:
  std::unique_ptr<Node> head;
  int size;

 public:
  LinkedList() : head(nullptr), size(0) {}

  void pushBack(int value) {
    // unique ptr
    auto newNode = std::make_unique<Node>(value);

    if (!head) {
      head = std::move(newNode);
    } else {
      Node* current = head.get();

      while (current != nullptr) {
        current = current->next.get();
      }

      current->next = std::move(newNode);
    }
    ++size;
  }

  void pushFront(int value) {
    auto newNode = std::make_unique<Node>(value);

    if (!head) {
      head = std::move(newNode);
    } else {
      newNode->next = std::move(this->head);
      this->head = std::move(newNode);
    }
    ++size;
  }

  void printList() {
    if (!head) {
      return;
    } else {
      Node* current = head.get();

      while (current != nullptr) {
        std::cout << current->data;
        if (current->next != nullptr) {
          std::cout << ", ";
        }
        current = current->next.get();
      }
      std::cout << std::endl;
    }
  }
};

int main(void) {
  LinkedList list;

  list.pushBack(30);
  list.pushFront(25);
  list.pushFront(50);
  list.printList();
}