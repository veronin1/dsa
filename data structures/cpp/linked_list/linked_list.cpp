class Node {
 private:
  int data;
  Node* next;

  // Give LinkedList access to private members
  friend class LinkedList;

 public:
  Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
 private:
  Node* head;
  int size;

 public:
  LinkedList() : head(nullptr), size(0) {}
};