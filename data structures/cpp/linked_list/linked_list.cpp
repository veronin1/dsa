#include <cstddef>
#include <memory>

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
};