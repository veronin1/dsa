#include <iostream>
#include <memory>
#include <ostream>
#include <stdexcept>
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

      while (current->next != nullptr) {
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

  void printList() const {
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

  int popBack() {
    if (!head) {
      throw std::runtime_error("Cannot pop from an empty list");
    } else {
      Node* current = head.get();

      auto prev = current;

      if (current->next == nullptr) {
        auto back = head->data;
        head = nullptr;
        --size;
        return back;
      }

      while (current->next != nullptr) {
        prev = current;
        current = current->next.get();
      }
      auto back = current->data;
      prev->next.reset();
      --size;
      return back;
    }
  }

  int popFront() {
    if (!head) {
      throw std::runtime_error("Cannot pop from an empty list");
    } else {
      if (head->next == nullptr) {
        auto front = head->data;
        head = nullptr;
        --size;
        return front;
      } else {
        auto front = head->data;
        head = std::move(head->next);
        --size;
        return front;
      }
    }
  }

  int front() const {
    if (!head) {
      throw std::runtime_error("Empty list!");
    }
    return head->data;
  }

  int back() const {
    if (!head) {
      throw std::runtime_error("Empty list!");
    }
    const Node* current = head.get();

    while (current->next != nullptr) {
      current = current->next.get();
    }
    return current->data;
  }

  bool empty() const { return !head; }
};

int main(void) {
  LinkedList list;

  list.pushFront(33);
  list.pushFront(50);
  list.pushFront(21);
  std::cout << "BACK: " << list.back() << std::endl;

  return 0;
}
