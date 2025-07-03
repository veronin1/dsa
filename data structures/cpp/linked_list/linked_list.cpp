#include <memory>
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
};