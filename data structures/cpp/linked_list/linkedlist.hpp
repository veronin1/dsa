#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <memory>
#include <ostream>
#include <stdexcept>
#include <utility>

template <typename T>
class LinkedList;

template <typename T>
class Node {
 private:
  T data;
  std::unique_ptr<Node<T>> next;

  // Give LinkedList access to private members
  friend class LinkedList<T>;

 public:
  Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {
 private:
  std::unique_ptr<Node<T>> head;
  int size;

 public:
  LinkedList() : head(nullptr), size(0) {}

  void pushBack(T value) {
    // unique ptr
    std::unique_ptr<Node<T>> newNode = std::make_unique<Node<T>>(value);

    if (!head) {
      head = std::move(newNode);
    } else {
      Node<T>* current = head.get();

      while (current->next != nullptr) {
        current = current->next.get();
      }

      current->next = std::move(newNode);
    }
    ++size;
  }

  void pushFront(T value) {
    std::unique_ptr<Node<T>> newNode = std::make_unique<Node<T>>(value);

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
      Node<T>* current = head.get();

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

  T popBack() {
    if (!head) {
      throw std::runtime_error("Cannot pop from an empty list");
    } else {
      Node<T>* current = head.get();

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

  T popFront() {
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

  T front() const {
    if (!head) {
      throw std::runtime_error("Empty list!");
    }
    return head->data;
  }

  T back() const {
    if (!head) {
      throw std::runtime_error("Empty list!");
    }
    const Node<T>* current = head.get();

    while (current->next != nullptr) {
      current = current->next.get();
    }
    return current->data;
  }

  bool empty() const { return !head; }

  void clear() {
    head.reset();
    size = 0;
  }

  int getSize() const { return size; }

  void removeValue(T value) {
    if (!head) {
      throw std::runtime_error("Empty list!");
    }

    if (head->data == value) {
      head = std::move(head->next);
      --size;
      return;
    }

    Node<T>* current = head.get();
    while (current->next && current->next->data != value) {
      current = current->next.get();
    }

    if (current->next && current->next->data == value) {
      current->next = std::move(current->next->next);
      --size;
    } else {
      throw std::runtime_error("Value not found");
    }
  }
};

#endif